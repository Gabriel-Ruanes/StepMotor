/*
 * File:   main.c
 * Author: 21192694
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
    giro();
}
