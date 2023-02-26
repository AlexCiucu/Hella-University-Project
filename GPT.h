/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   GPT_.h                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian  */
/*   Description                                                              */
/*       File Containing the Public Data for the module GPT            */
/* ========================================================================== */

#ifndef GPT_H
#define GPT_H
/* ========================================================================== */
/*                  PUT YOUR CODE HERE                                        */
/* ========================================================================== */
#include "..\Std_Files\Std_Types.h"
#include "GPT_Types.h" 
#include "..\Std_Files\DET.h"

extern void GPT_Init(void); /* Make here the appropiate changes */

extern void GPT_TimerISR(void);

extern Std_ReturnType GPT_GetTime(Gpt_ValueType* Gpt_Time);


#endif
