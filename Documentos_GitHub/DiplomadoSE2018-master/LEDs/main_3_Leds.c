/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    ThreeLEDs.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "MK64F12.h"
#include "DataTypeDefinitions.h"

void delay(uint16 delay);
/*
 * @brief   Application entry point.
 */
int main(void) {
	/**Activating the GPIOB and GPIOE clock gating*/
	SIM->SCGC5 = 0x2400;
	/**Pin control configuration of GPIOB pin22 and pin21 as GPIO*/
	PORTB->PCR[21] = 0x00000100;
	PORTB->PCR[22] = 0x00000100;
	PORTE->PCR[26] = 0x00000100;
	/**Assigns a safe value to the output pin21 of the GPIOB*/
	GPIOB->PDOR = 0x00200000;
	/**Assigns a safe value to the output pin22 of the GPIOB*/
	GPIOB->PDOR |= 0x00400000;
	/**Assigns a safe value to the output pin26 of the GPIOE*/
	GPIOE->PDOR |= 0x04000000;

	/**Configures GPIOB pin21 as output*/
	GPIOB->PDDR = 0x00200000;
	/**Configures GPIOB pin22 as output*/
	GPIOB->PDDR |= 0x00400000;
	/**Configures GPIOE pin26 as output*/
	GPIOE->PDDR |= 0x04000000;


    while(1) {
    	GPIOB->PDOR |= 0x00200000;/**Blue led off*/
		delay(65000);
		GPIOB->PDOR |= 0x00400000;/**Read led off*/
		delay(65000);
		GPIOE->PDOR |= 0x4000000;/**Green led off*/
		delay(65000);
		GPIOB->PDOR &= ~(0x00200000);/**Blue led on*/
		delay(65000);
		GPIOB->PDOR &= ~(0x00400000);/**Read led on*/
		delay(65000);
		GPIOE->PDOR &= ~(0x4000000);/**Green led on*/
		delay(65000);
		GPIOB->PDOR |= 0x00200000;/**Blue led off*/
		delay(65000);
		GPIOB->PDOR |= 0x00400000;/**Read led off*/
		delay(65000);
		GPIOE->PDOR |= 0x4000000;/**Green led off*/
		delay(65000);
		/**---------------------------------------------------*/
		/**---------------------------------------------------*/
		__NOP();/** THIS a assembly macro*/
    }
    return 0 ;
}


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
void delay(uint16 delay)
{
	volatile uint16 counter;

	for(counter=delay; counter > 0; counter--)
	{
	}
}

