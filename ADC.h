/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   ADC_.h                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian */
/*   Description                                                              */
/*       File Containing the Public Data for the module ADC            */
/* ========================================================================== */

#ifndef ADC_H
#define ADC_H
/* ========================================================================== */
/*                  PUT YOUR CODE HERE                                        */
/* ========================================================================== */
#include "..\Std_Files\Std_Types.h"
#include "ADC_Types.h" 
#include "..\Std_Files\DET.h"
extern void ADC_Init(void); /* Make here the appropiate changes */

extern Std_ReturnType ADC_Trigger(ADC_ChannelIdType ADC_Channel);

extern Std_ReturnType ADC_GetStatus (ADC_ConvertorStatusType* ADC_Status);

extern Std_ReturnType ADC_GetChannelValue
(ADC_ChannelIdType ADC_ChannelId, ADC_ValueType* ADC_Value);

#endif
