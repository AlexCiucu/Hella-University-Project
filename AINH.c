/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace AINH with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   AINH_.c                                                            */
/*   Autor(s): YourName(s)                                                    */
/*   Description                                                              */
/*       File Containing the implementation of the module AINH          */
/* ========================================================================== */

#include "AINH.h"
#include "AINH_Private.h"
/* ========================================================================== */
/*                  PUT YOUR INCLUDES HERE                                    */
/* ========================================================================== */

#include "..\Drivers\ADC\ADC.h"

/* ========================================================================== */
/*                  PUT YOUR VARIABLE DECLARATIONS HERE                       */
/* ========================================================================== */

static boolean AINH_InitStatus = FALSE;

static AinH_BufferType buffer;

static AinH_ChannelIdType current_channel = 0;

/* ========================================================================== */
/*                  PUT YOUR API IMPLEMENTATIONS HERE                         */
/* ========================================================================== */

void AINH_Init(void)
{

for(int i = 0; i < AINH_NO_CHANNELS; i++){
    buffer[i] = 0;
}

ADC_Trigger(current_channel);

AINH_InitStatus = TRUE;
return;
}

void AinH_Cyclic(){
    ADC_GetChannelValue(current_channel, &buffer[current_channel]);

    if(current_channel < AINH_NO_CHANNELS - 1){
        current_channel++;
    }
    else{
        current_channel = 0;
    }

    ADC_Trigger(current_channel);

    if(AINH_InitStatus == FALSE){
        Det_Report();
    }
}

Std_ReturnType AinH_GetChannelValue(AinH_ChannelIdType ChannelId, AinH_ValueType *Value){
    Std_ReturnType status = E_NOT_OK;

    if(ChannelId >= AINH_NO_CHANNELS){
        Det_Report();
        status = E_NOT_OK;
    }
    else if(Value == NULL_PTR){
        Det_Report();
        status = E_NOT_OK;
    }
    else if(AINH_InitStatus == FALSE){
        Det_Report();
        status = E_NOT_OK;
    }
    else{
        *Value = buffer[ChannelId];
        status = E_OK;
    }

    return status;
}
