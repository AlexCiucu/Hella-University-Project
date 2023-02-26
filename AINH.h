/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace AINH with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   AINH_.h                                                            */
/*   Autor(s): YourName(s)                                                    */
/*   Description                                                              */
/*       File Containing the Public Data for the module AINH            */
/* ========================================================================== */

#ifndef AINH_H
#define AINH_H
/* ========================================================================== */
/*                  PUT YOUR CODE HERE                                        */
/* ========================================================================== */
#include "Std_Types.h"
#include "AINH_Types.h" 

extern void AINH_Init(void); /* Make here the appropiate changes */

extern void AinH_Cyclic();

extern Std_ReturnType AinH_GetChannelValue(AinH_ChannelIdType ChannelId, AinH_ValueType *Value);

#endif
