/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   PORT_.h                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian */
/*   Description                                                              */
/*       File Containing the Public Data for the module PORT            */
/* ========================================================================== */

#ifndef PORT_H
#define PORT_H
/* ========================================================================== */
/*                  PUT YOUR CODE HERE                                        */
/* ========================================================================== */
#include "..\Std_Files\Std_Types.h"
#include "PORT_Types.h" 
#include "..\Std_Files\DET.h"

extern void PORT_Init(void); /* Make here the appropiate changes */

extern Std_ReturnType PORT_GetPinMode
(PORT_PinType PinId, PORT_PinModeType *mode, PORT_PinDirectionType *direction);




#endif
