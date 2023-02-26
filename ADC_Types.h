/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   ADC_Types.h                                                       */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian */
/*   Description                                                              */
/*       File Containing the Type definitions of the module ADC        */
/* ========================================================================== */
#include "..\Std_Files\Std_Types.h"
#ifndef ADC_TYPES_H
#define ADC_TYPES_H
/* ========================================================================== */
/*                  PUT YOUR CODE HERE                                        */
/* ========================================================================== */

typedef uint8 ADC_ChannelIdType; /* Make here the appropiate changes */
typedef enum
{
    ADC_STATUS_OK,
    ADC_STATUS_IN_PROGRESS
}ADC_ConvertorStatusType;

typedef uint16 ADC_ValueType;


#endif
