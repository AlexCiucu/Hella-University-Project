/* ========================================================================== */
/*                                                                            */
/*                                                                            */
/*  !!!!!!!!!!!!!! Replace ModuleName with the name of your module!!!!!!!!!!  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   PORT_.c                                                            */
/*   Autor(s): Ciucu Alexandru-Mihai, Lupu Nicolae, Popescu Andrei-Florin, Preda Stefan-Marian  */
/*   Description                                                              */
/*       File Containing the implementation of the module PORT          */
/* ========================================================================== */

#include "PORT.h"
#include "PORT_Private.h"
/* ========================================================================== */
/*                  PUT YOUR INCLUDES HERE                                    */
/* ========================================================================== */

/* ========================================================================== */
/*                  PUT YOUR VARIABLE DECLARATIONS HERE                       */
/* ========================================================================== */

static boolean PORT_InitStatus = FALSE;
static struct pin pins[PORT_NO_PINS];

/* ========================================================================== */
/*                  PUT YOUR API IMPLEMENTATIONS HERE                         */
/* ========================================================================== */

void PORT_Init(void)
{
/* Put here the code */

for(int i = 0; i < PORT_NO_PINS; i++){

    pins[i].id = i;

    // setting the digital outputs
    if(i == 7 || i == 153 || i == 165 || i == 166){
        pins[i].direction = PORT_PIN_OUTPUT;
        pins[i].type = DIGITAL;
    }

    // setting the analog inputs
    else if(i == 106 || i == 105 || i == 104 || i == 103){
        pins[i].direction = PORT_PIN_INPUT;
        pins[i].type = ANALOG;
    }

    // setting the pwm outputs
    else if(i == 15 || i == 154 || i == 161 || i == 167 || i == 16 || i == 155 || i == 162 || i == 8 || i == 17 || i == 156 || i == 163 || i == 9){
        pins[i].direction = PORT_PIN_OUTPUT;
        pins[i].type = PWN;
    }  
    // setting all other pins as digital inputs
    else{
        pins[i].direction = PORT_PIN_INPUT;
        pins[i].type = DIGITAL;
    }   
}

//Initialize all pins as digital inputs
    PM0   = 0xFFFF;
    PMC0  = 0x0000;
    PM1   = 0xFFFF;
    PMC1  = 0x0000;
    PM2   = 0xFFFF;
    PMC2  = 0x0000;
    PM8   = 0xFFFF;
    PMC8  = 0x0000;
    PM9   = 0xFFFF;
    PMC9  = 0x0000;
    PM10  = 0xFFFF;
    PMC10 = 0x0000;
    PM11  = 0xFFFF;
    PMC11 = 0x0000;
    PM12  = 0xFFFF;
    PMC12 = 0x0000;
    PM18  = 0xFFFF;
    PMC18 = 0x0000;
    PM20  = 0xFFFF;         
    PMC20 = 0x0000;


    //Configuram Port 11 pin 0 ca Digital Outputs
    PM11 &=~(1<<0); // face 0 pentru ca e output mode
    PMC11 &=~ (1<<0); // face 0 pt ca e digital

    //Configuram Port 10 pin 7 ca Digital Outputs
    PM10 &=~(1<<7); // face 0 pentru ca e output mode
    PMC10 &=~ (1<<7); // face 0 pt ca e digital

    //Configuram Port 11 pin 5 ca Digital Outputs
    PM11 &=~(1<<5); // face 0 pentru ca e output mode
    PMC11 &=~ (1<<5); // face 0 pt ca e digital

    //Configuram Port 11 pin 6 ca Digital Outputs
    PM11 &=~(1<<6); // face 0 pentru ca e output mode
    PMC11 &=~ (1<<6); // face 0 pt ca e digital



    //Configuram Port 0 pin 0 ca Analog Inputs
    APM0 |= (1<<0); // face 1 pentru input mode
    PMC0 &=~ (1<<0);
    //Configuram Port 0 pin 1 ca Analog Inputs
    APM0 |= (1<<1); // face 1 pentru input mode
    PMC0 &=~ (1<<1);
    //Configuram Port 0 pin 2 ca Analog Inputs
    APM0 |= (1<<2); // face 1 pentru input mode
    PMC0 &=~ (1<<2);
    //Configuram Port 0 pin 3 ca Analog Inputs
    APM0 |= (1<<3); // face 1 pentru input mode
    PMC0 &=~ (1<<3);

    //Configuram Port 12 pin 3 ca PWM Output
    PIPC12 &=~(1<<3); // face 0
    PM12 &=~(1<<3); // face 0
    PFCAE12 &=~(1<<3); // face 0
    PFCE12 &=~(1<<3); // face 0
    PFC12 |= (1<<3); // face 1


    //Configuram Port 10 pin 8 ca PWM Output
    PIPC10  &=~(1<<8);
    PM10 &=~(1<<8);
    PFCAE10 &=~(1<<8);
    PFCE10 |= 1<<8;
    PFC10 &=~(1<<8);


    //Configuram Port 11 pin 1 ca PWM Output
    PIPC11  &=~(1<<1);
    PM11 &=~(1<<1);
    PFCAE11 &=~(1<<1);
    PFCE11 |= 1<<1;
    PFC11 &=~(1<<1);


    //Configuram Port 11 pin 7 ca PWM Output
    PIPC11 &=~(1<<7);
    PM11 &=~(1<<7);
    PFCAE11 &=~(1<<7);
    PFCE11 &=~(1<<7);
    PFC11 |= (1<<7);


    //Configuram Port 12 pin 4 ca PWM Output
    PIPC12 &=~(1<<4);
    PM12 &=~(1<<4);
    PFCAE12 &=~(1<<4);
    PFCE12 &=~(1<<4);
    PFC12 |= (1<<4);


    //Configuram Port 10 pin 9 ca PWM Output
    PIPC10  &=~(1<<9);
    PM10 &=~(1<<9);
    PFCAE10 &=~(1<<9);
    PFCE10 |= 1<<9;
    PFC10 &=~(1<<9);


    //Configuram Port 11 pin 2 ca PWM Output
    PIPC11  &=~(1<<2);
    PM11 &=~(1<<2);
    PFCAE11 &=~(1<<2);
    PFCE11 |= 1<<2;
    PFC11 &=~(1<<2);


    //Configuram Port 11 pin 8 ca PWM Output *
    PIPC11  &=~(1<<8);
    PM11 &=~(1<<8);
    PFCAE11 &=~(1<<8);
    PFCE11 &= 1<<8;
    PFC11 |=~(1<<8);


    //Configuram Port 12 pin 5 ca PWM Output
    PIPC12  &=~(1<<5);
    PM12 &=~(1<<5);
    PFCAE12 &=~(1<<5);
    PFCE12 &=~(1<<5);
    PFC12 &=~(1<<5);


    //Configuram Port 10 pin 10 ca PWM Output
    PIPC10  &=~(1<<10);
    PM10 &=~(1<<10);
    PFCAE10 &=~(1<<10);
    PFCE10 |= 1<<10;
    PFC10 &=~(1<<10);


    //Configuram Port 11 pin 3 ca PWM Output *
    PIPC11  &=~(1<<3);
    PM11 &=~(1<<3);
    PFCAE11 &=~(1<<3);
    PFCE11 &=~(1<<3);
    PFC11 |= (1<<3);


    //Configuram Port 11 pin 9 ca PWM Output
    PIPC11  &=~(1<<9);
    PM11 &=~(1<<9);
    PFCAE11 &=~(1<<9);
    PFCE11 &=~(1<<9);
    PFC11 |= (1<<9);



PORT_InitStatus = TRUE;
return;
}

Std_ReturnType PORT_GetPinMode(PORT_PinType PinId, PORT_PinModeType *mode, PORT_PinDirectionType *direction)
{
    Std_ReturnType status = E_OK;

    if(PinId < 0 || PinId > PORT_NO_PINS - 1){
        Det_Report();
        status = E_NOT_OK;
    }

    if(mode == NULL_PTR || direction == NULL_PTR){
        Det_Report();
        status = E_NOT_OK;
    }

    if(PORT_InitStatus == FALSE){
        Det_Report();
        status = E_NOT_OK;
    }
    

    *mode = pins[PinId].type;
    *direction = pins[PinId].direction;


    return status;
}
