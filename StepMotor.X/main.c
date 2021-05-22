/*
 * File:   main.c
 * Author:  Grupo 4 (G4)
 *          -Davi Melo;
 *          -Gabriel Ruanes;
 *          -Marco Antonio. 
 *
 * Created on 20 de Maio de 2021, 14:15
 */

#include"config.h"
#include <xc.h>
#include"delay.h"
#include "StepMotor.h"



void main(void) 
{
    StepMotor_init();
    StepMotor();
}
