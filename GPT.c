/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   GPT_.c                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian */
/*   Description                                                              */
/*       File Containing the implementation of the module GPT          */
/* ========================================================================== */

#include "GPT.h"
#include "GPT_Private.h"
/* ========================================================================== */
/*                  PUT YOUR INCLUDES HERE                                    */
/* ========================================================================== */

/* ========================================================================== */
/*                  PUT YOUR VARIABLE DECLARATIONS HERE                       */
/* ========================================================================== */

static boolean GPT_InitStatus = FALSE;

static Gpt_ValueType counter = 0;

/* ========================================================================== */
/*                  PUT YOUR API IMPLEMENTATIONS HERE                         */
/* ========================================================================== */

void GPT_Init(void)
{
    /* Put here the code */

    TAUJ0TPS = 0xFFF3; // set the frequency of the TAUJ clock as 5MHz

    IMR2 &= ~(1 << 16); // enable the interrupt for the TAUJ0 channel 0

    TAUJ0CMOR = 0x0000; // set the TAUJ0 channel 0 to run as “Interval Timer Mode”

    TAUJ0CDR0 = 0x7A120; // set interrupt to 100 seconds

    TAUJ0TS = 0x01; // start TAUJ channel 0

    // disable input

    GPT_InitStatus = TRUE;
    return;
}

void GPT_TimerISR(void)
{
    counter += 100;
}

Std_ReturnType GPT_GetTime(Gpt_ValueType *Gpt_Time)
{
    Std_ReturnType status = E_NOT_OK;

    if (GPT_InitStatus == FALSE)
    {
        Det_Report();
        status = E_NOT_OK;
    }
    else if (GPT_InitStatus == TRUE)
    {
        if (Gpt_Time == NULL_PTR)
        {
            Det_Report();
            status = E_NOT_OK;
        }
        else
        {
            *Gpt_Time = counter;
            status = E_OK;
        }
    }
    return status;
}