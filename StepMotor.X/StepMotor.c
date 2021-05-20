/*
 * File:   StepMotor.c
 * Author: 21192694
 *
 * Created on 20 de Maio de 2021, 15:56
 */


#include <xc.h>
#include "delay.h"

#define A  PORTDbits.RD7
#define B  PORTDbits.RD6
#define C  PORTDbits.RD5
#define D  PORTDbits.RD4

void StepMotor_init ( void )
{
    TRISD = 0;
    PORTD = 0;    
}
void giro (void)
{
    char estado = 0;
    while(1)
    {
        switch(estado)
        {
                case 0:
                estado = 1;
                    break;
                case 1:                        
                A = 1;
                delay(3000);
                A = 0;
                estado = 2;
                    break;
                case 2:
                    if (A == 0)
                    D = 1;
                    delay(3000);
                    D = 0;
                    estado = 3;
                    break;
                case 3:
                    C = 1;
                    delay(3000);
                    C = 0;
                    estado = 4;
                    break;
                case 4:
                    B = 1;
                    delay(3000);
                    B = 0;
                    estado = 0;
                    break;                  
        }
    }
}    

