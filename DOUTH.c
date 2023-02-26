/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace DOUTH with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   DOUTH_.c                                                            */
/*   Autor(s): YourName(s)                                                    */
/*   Description                                                              */
/*       File Containing the implementation of the module DOUTH          */
/* ========================================================================== */

#include "DOUTH.h"
#include "DOUTH_Private.h"
/* ========================================================================== */
/*                  PUT YOUR INCLUDES HERE                                    */
/* ========================================================================== */

/* ========================================================================== */
/*                  PUT YOUR VARIABLE DECLARATIONS HERE                       */
/* ========================================================================== */

static boolean DOUTH_InitStatus = FALSE;

static DoutH_BufferType buffer;

static uint8 output_pins[DO_NO_PINS] = {8, 9, 10, 11}; // digital output

/* ========================================================================== */
/*                  PUT YOUR API IMPLEMENTATIONS HERE                         */
/* ========================================================================== */

void DOUTH_Init(void)
{
    for (int i = 0; i < DOUTH_NO_CHANNELS; i++)
    {
        buffer[i] = DOUTH_LOW;
    }

    DOUTH_InitStatus = TRUE;
    return;
}

void DoutH_Cyclic()
{

    if (DOUTH_InitStatus == FALSE)
    {
        Det_Report();
    }
    else
    {
        for (int i = 0; i < DOUTH_NO_CHANNELS; i++)
        {
            DIO_PinWrite(output_pins[i], buffer[i]);
        }
    }
}

Std_ReturnType DoutH_SetChannelValue(DoutH_ChannelIdType ChannelId, DoutH_ValueType Value){
    Std_ReturnType status = E_NOT_OK;

    if(ChannelId >= DOUTH_NO_CHANNELS){
        Det_Report();
        status = E_NOT_OK;
    }
    else if(Value != DOUTH_LOW || Value != DOUTH_HIGH){
        Det_Report();
        status = E_NOT_OK;
    }
    else if(DOUTH_InitStatus == FALSE){
        Det_Report();
        status = E_NOT_OK;
    }
    else{
        buffer[ChannelId] = Value;
        status = E_OK;
    }
    
    return status;
}