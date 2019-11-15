/*
 * Test Harness for the ILI9225 LCD driver.
 * 
 * File:   main.c
 * Author: tommy
 *
 * Created on 2 July 2019, 7:32 PM
 */


#include "ILI9225.h"

#define PWR_LED     LATC7

/*
 * Initialise SPI port for the LCD
 */
void initSPI() {

}

void main(void) {

    //Begin SPI
    initSPI();
    
    //Initialise the LCD
    lcd_init();
    //Clear the screen
    fill_rectangle(0, 0, WIDTH, HEIGHT, COLOR_BLACK);
    
    //Power LED to show that we have finished boot
    PWR_LED = 1;
    
    //Test pattern
    while(1) {
        fill_rectangle(0, 0, WIDTH, HEIGHT, COLOR_LIGHTBLUE);
        draw_string(64, 64, COLOR_BLACK, 1, "Hello World\0");
        delay_ms(1000);
        fill_rectangle(0, 0, WIDTH, HEIGHT, COLOR_RED);
        draw_string(64, 64, COLOR_BLACK, 2, "Hello World\0");
        delay_ms(1000);
        fill_rectangle(0, 0, WIDTH, HEIGHT, COLOR_GREEN);
        draw_string(64, 64, COLOR_BLACK, 3, "Hello World\0");
        delay_ms(1000);
    }
    return;
}
