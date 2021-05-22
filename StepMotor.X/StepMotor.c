/*
 * File:   StepMotor.c
 * Author:  Grupo 4 (G4)
 *          -Davi Melo;
 *          -Gabriel Ruanes;
 *          -Marco Antonio. 
 *
 * Created on 20 de Maio de 2021, 15:56
 */


#include <xc.h>
#include "delay.h"

#define     A_mais          PORTBbits.RB3
#define     B_mais          PORTBbits.RB2
#define     A_menos         PORTBbits.RB1
#define     B_menos         PORTBbits.RB0

#define     Horario         PORTDbits.RD0
#define     Anti_Horario    PORTDbits.RD1

void StepMotor_init ( void )
{
    ANSELH = 0;
    TRISB = 0x00;        
}

char botao_S1 ( void )
{
    return(Horario);
}

char botao_S2 ( void )
{
    return(Anti_Horario);
}

void StepMotor ( void )
{
    char estado = 0;
    
    while( 1 )  
    {
        switch( estado )
        {
            case 0:
                    if( botao_S1() == 1 )
                        estado = 1;
                    else if( botao_S2() == 1 )
                            estado = 6;
                    break;
                    
            case 1:                        
                    A_mais = 1;
                    delay(1000);
                    A_mais = 0;
                    estado = 2;
                    break;
                    
            case 2:
                    B_menos = 1;
                    delay(1000);
                    B_menos = 0;
                    estado = 3;
                    break;
                    
            case 3:
                    A_menos = 1;
                    delay(1000);
                    A_menos = 0;
                    estado = 4;
                    break;
                    
            case 4:
                    B_mais = 1;
                    delay(1000);
                    B_mais = 0;
                    estado = 5;
                    break; 
                    
            case 5:
                    A_mais = 1;
                    delay(1000);
                    A_mais = 0;
                    estado = 0;                
                break;

            case 6:
                    A_mais = 1;
                    delay(1000);
                    A_mais = 0;
                    estado = 7;                
                break;
                
            case 7:
                    B_mais = 1;
                    delay(1000);
                    B_mais = 0;
                    estado = 8;
                    break; 

            case 8:
                    A_menos = 1;
                    delay(1000);
                    A_menos = 0;
                    estado = 9;
                    break;

            case 9:
                    B_menos = 1;
                    delay(1000);
                    B_menos = 0;
                    estado = 10;
                    break;

            case 10:                        
                    A_mais = 1;
                    delay(1000);
                    A_mais = 0;
                    estado = 0;
                    break;
                    
        }
    }
}    

