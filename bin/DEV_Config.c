/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Ring-0
* Project: CSC 615 Term Project
*
* File: DEV_Config.c
*
* Description: 
* This file contains the intermediary code between WPi and the
* PCA9685 library to allow for the I2C communication to occur on-board.
**************************************************************/
#include "DEV_Config.h"
#include "Debug.h"  //DEBUG()

#include <wiringPi.h>
#include <wiringPiI2C.h>

// We are using 2 waveshare HATs, one for front and other for rear wheels
// The two have different I2C addresses
int front_hat_fd, back_hat_fd;

/**
 * Module Initialize, use WiringPi library.
 */
UBYTE DEV_ModuleInit(void) {
    if(wiringPiSetup() < 0) {
        DEBUG("set wiringPi lib failed	!!! \r\n");
        return 1;
    } else {
        DEBUG("set wiringPi lib success  !!! \r\n");
    }

    return 0;
}

/**
 * Module Exit, close BCM2835 library.
 *
 * Example:
 * DEV_ModuleExit();
 */
void DEV_ModuleExit(void)
{
    // bcm2835_i2c_end();
    // bcm2835_close();
}

/**
 * Module Initialize, use WiringPi library.
 *
 * @param addr: I2C Device address.
 */
void DEV_I2C_Init(int hat, char addr)
{
    if (hat == 0) { // Forward "axle"
        front_hat_fd = wiringPiI2CSetup(addr);
    } else {        // Rear "axle"
        back_hat_fd = wiringPiI2CSetup(addr);
    }
}

/**
 * I2C write byte.
 *
 * @param reg: register.
 * @param value: value.
 *
 * Example:
 * DEV_I2C_WriteByte(0x00, 0xff);
 */
void DEV_I2C_WriteByte(int hat, UBYTE reg, UBYTE value)
{
    int ref;
    if (hat == 0) {
        ref = wiringPiI2CWriteReg8(front_hat_fd, (int)reg, (int)value);
        while(ref != 0) {
            ref = wiringPiI2CWriteReg8 (front_hat_fd, (int)reg, (int)value);
            if(ref == 0)
                break;
        }
    } else {
        ref = wiringPiI2CWriteReg8(back_hat_fd, (int)reg, (int)value);
        while(ref != 0) {
            ref = wiringPiI2CWriteReg8 (back_hat_fd, (int)reg, (int)value);
            if(ref == 0)
                break;
        }
    }
    
}

/**
 * I2C read byte.
 *
 * @param reg: register.
 *
 * Example:
 * UBYTE buf = PCA9685_Read(0x00);
 */
UBYTE DEV_I2C_ReadByte(int hat, UBYTE reg)
{
    if (hat == 0) {
        return wiringPiI2CReadReg8(front_hat_fd, reg);
    }

    return wiringPiI2CReadReg8(back_hat_fd, reg);
}

/**
 * Millisecond delay.
 *
 * @param xms: time.
 *
 * Example:
 * DEV_Delay_ms(500);//delay 500ms
 */
void DEV_Delay_ms(uint32_t xms)
{
    delay(xms);
}

/**
 * Microsecond delay.
 *
 * @param xus: time.
 *
 * Example:
 * DEV_Delay_us(500);//delay 500us
 */
void DEV_Delay_us(uint32_t xus)
{
    int j;
    for(j=xus; j > 0; j--);
}
