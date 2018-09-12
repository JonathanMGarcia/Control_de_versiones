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
 * @file    LEDsAndBitfield.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "DataTypeDefinitions.h"
#include "MK64F12.h"

#define ALL_BIT_ON 0xFF

/**This is a prototype function to create a delay using a for-loop*/
void delay(uint16 delay);

int main(void) {
	/**Declaration of a bitfield*/
	typedef union
	{
		uint8 allBits;
		struct{
			uint8 bit0 :3;
			uint8 bit1 :1;
			uint8 bit2 :1;
			uint8 bit3 :1;
			uint8 bit4 :1;
			uint8 bit5 :1;
		}bitField;
	} myData;

	/**Variable declaration of myData type*/
	myData portDBits = {0};

	/**Activating the GPIOB and GPIOE clock gating*/
	SIM->SCGC5 = 0x1200;
	/**Pin control configuration of GPIOD pin0 and pin6 as GPIO by using a special macro contained in Kinetis studio in the MK64F12. h file*/
	PORTD->PCR[0] = PORT_PCR_MUX(1);
	PORTD->PCR[1] = PORT_PCR_MUX(1);
	PORTD->PCR[2] = PORT_PCR_MUX(1);
	PORTD->PCR[3] = PORT_PCR_MUX(1);
	PORTD->PCR[4] = PORT_PCR_MUX(1);
	PORTD->PCR[5] = PORT_PCR_MUX(1);
	/**GPIOA pin control configuration*/
	PORTA->PCR[1] = PORT_PCR_MUX(1)|0x03;

	/**Assigns a safe value to the output pin21 of the GPIOB*/
	GPIOD->PDOR =0x00;

	/**Configures GPIOD pin0-pin5 as output*/
	GPIOD->PDDR =0x3F;
	/**Configures GPIOA pin4 as output*/
	GPIOA->PDDR =0;

    while(1) {
    	/**Assigns all the bitfield*/
		portDBits.allBits = ALL_BIT_ON;
		GPIOD->PDOR = portDBits.allBits;
		delay(65000);
		/**Assigns only one bit in the bitfield*/
		portDBits.bitField.bit0 = 0;
		/**Assigns all the bitfield to the GPIOD output port*/
		GPIOD->PDOR = portDBits.allBits;
		delay(65000);
		portDBits.bitField.bit1 = BIT_OFF;
		GPIOD->PDOR = portDBits.allBits;
		delay(65000);
		portDBits.bitField.bit2 = BIT_OFF;
		GPIOD->PDOR = portDBits.allBits;
		delay(65000);
		portDBits.bitField.bit3 = BIT_OFF;
		GPIOD->PDOR = portDBits.allBits;
		delay(65000);
		portDBits.bitField.bit4 = BIT_OFF;
		GPIOD->PDOR = portDBits.allBits;
		delay(65000);
		portDBits.bitField.bit5 = BIT_OFF;

		GPIOD->PDOR = portDBits.allBits;
		delay(65000);
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

