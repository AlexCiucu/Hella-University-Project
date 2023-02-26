/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   PORT_Types.h                                                       */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian */
/*   Description                                                              */
/*       File Containing the Type definitions of the module PORT        */
/* ========================================================================== */
#include "..\Std_Files\Std_Types.h"
#ifndef PORT_TYPES_H
#define PORT_TYPES_H
/* ========================================================================== */
/*                  PUT YOUR CODE HERE                                        */
/* ========================================================================== */

typedef enum  
{
PORT_PIN_OUTPUT = 0,
PORT_PIN_INPUT
}PORT_PinDirectionType; /* Make here the appropiate changes */
typedef enum
{
DIGITAL = 0,
ANALOG,
PWN
}PORT_PinModeType;
typedef uint8 PORT_PinType;

struct pin{
    PORT_PinDirectionType direction;
    PORT_PinModeType type;
    PORT_PinType id;
};


#endif
