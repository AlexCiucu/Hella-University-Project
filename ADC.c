/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   ADC_.c                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian */
/*   Description                                                              */
/*       File Containing the implementation of the module ADC          */
/* ========================================================================== */

#include "ADC.h"
#include "ADC_Private.h"
/* ========================================================================== */
/*                  PUT YOUR INCLUDES HERE                                    */
/* ========================================================================== */

#include "..\PORT\PORT.h"

/* ========================================================================== */
/*                  PUT YOUR VARIABLE DECLARATIONS HERE                       */
/* ========================================================================== */

static boolean ADC_InitStatus = FALSE;

//static ADC_ConvertorStatusType driver_status = ADC_STATUS_OK;

static const uint8 ADC_Ports[ADC_NO_PORTS] = {103, 104, 105, 106};

/* ========================================================================== */
/*                  PUT YOUR API IMPLEMENTATIONS HERE                         */
/* ========================================================================== */

void ADC_Init(void)
{
/* Put here the code */

    // setting  virtual channel 0
    ADCA0SGVCSP1 &=~(1<<0);
    ADCA0SGVCSP1 &=~(1<<1);
    ADCA0SGVCSP1 &=~(1<<2);
    ADCA0SGVCSP1 &=~(1<<3);
    ADCA0SGVCSP1 &=~(1<<4);
    ADCA0SGVCSP1 &=~(1<<5);

    ADCA0SGVCEP1 &=~(1<<0);
    ADCA0SGVCEP1 &=~(1<<1);
    ADCA0SGVCEP1 &=~(1<<2); 
    ADCA0SGVCEP1 &=~(1<<3);
    ADCA0SGVCEP1 &=~(1<<4);
    ADCA0SGVCEP1 &=~(1<<5);
    

    ADCA0THSMPSTCR &=~(1<<0); // disable the track and hold circuit

    // scan group ??

    ADCA0VCR0 &=~(1<<15); // disable the use of external multiplexer

    ADCA0VCR0 &=~(1<<7);
    ADCA0VCR0 &=~(1<<6); // disable the check for upper/lower limit

    ADCA0ADCR &=~(1<<7); // disable the self-diagnostic voltage level

    ADCA0ADCR &=~(1<<5); // set the alignment control as right-aligned

    ADCA0ADCR &=~(1<<4); // set the resolution of the ADC unit to 12 bits

    ADCA0SGTSEL0 &=~(1<<0); // disable the hardware trigger

    ADCA0VCR0 &=~(1<<8); // disable the A/D conversion end interrupt



    ADC_InitStatus = TRUE;
    return;
}

Std_ReturnType ADC_Trigger(ADC_ChannelIdType ADC_Channel){
    Std_ReturnType status = E_NOT_OK;

    if(ADC_InitStatus == FALSE){
        Det_Report();
        status = E_NOT_OK;
    }

    // functie
    PORT_PinModeType mode;
    PORT_PinDirectionType direction;
    PORT_GetPinMode(ADC_Ports[ADC_Channel], &mode, &direction);

    if(ADC_Channel >= ADC_NO_PORTS){
        Det_Report();
        status = E_NOT_OK;
    }

    // alta functie
    ADC_ConvertorStatusType ADC_status;

    ADC_GetStatus(&ADC_status);

    if(ADC_status == ADC_STATUS_IN_PROGRESS){
        status = E_NOT_OK;
    }   

    else if(ADC_status == ADC_STATUS_OK){
        ADCA0SGSTCR1 |= (1<<0); // start A/D conversion
        status = E_OK;
        ADCA0VCR00[0] = ADC_Channel;
    }
    
    

    return status;
}

Std_ReturnType ADC_GetStatus (ADC_ConvertorStatusType* ADC_Status){
    Std_ReturnType status = E_NOT_OK;

    if(ADC_Status == NULL_PTR){
        Det_Report();
        status = E_NOT_OK;
    }

    if(ADC_InitStatus == FALSE){
        Det_Report();
        status = E_NOT_OK;
    }
    
    uint8 bitStatus = (ADCA0SGSTR >> 9) & 1; 

    if(bitStatus == 0){
        *ADC_Status = ADC_STATUS_OK;
        status = E_OK;
    }
    else if(bitStatus == 1){
        *ADC_Status = ADC_STATUS_IN_PROGRESS;
        status = E_OK;
    }

    return status;
}

Std_ReturnType ADC_GetChannelValue
(ADC_ChannelIdType ADC_ChannelId, ADC_ValueType* ADC_Value){
    Std_ReturnType status = E_NOT_OK;

    if(ADC_ChannelId >= ADC_NO_PORTS){
        Det_Report();
        status = E_NOT_OK;
    }

    else if(ADC_Value == NULL_PTR){
        Det_Report();
        status = E_NOT_OK;
    }

    else if(ADC_InitStatus == FALSE){
        Det_Report();
        status = E_NOT_OK;
    } 

    else{
        *ADC_Value = (ADCA0DR00 >> 0) & ~(~0 << (12)); // read first 12 bits from the register
        status = E_OK;
    }
    
    return status;         
}