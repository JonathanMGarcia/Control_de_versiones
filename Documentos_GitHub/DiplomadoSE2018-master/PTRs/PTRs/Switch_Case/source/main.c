
#include <LEDs_and_SWs.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"


int main(void) {

	Colors_t color_selector = RED;

	BOARD_InitBootPins();


    while(1) {

    	color_selector = Color_get_next_color();

    	switch (color_selector) {
			case RED:
				Color_Red();
				break;
			case BLUE:
				Color_Blue();
				break;
			case GREEN:
				Color_Green();
				break;
			case YELLOW:
				Color_yellow();
				break;
			case WHITE:
				Color_white();
				break;
			default:
				Color_OFF();
				break;
		}


    }
    return 0 ;
}
