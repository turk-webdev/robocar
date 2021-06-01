/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Ring-0
* Project: CSC 615 Term Project
*
* File: DEV_Config.h
*
* Description: 
* Header file for the intermediary, contains some basic defs
**************************************************************/
#ifndef __DEV_CONFIG_H_
#define __DEV_CONFIG_H_

#include <wiringPi.h>
#include <stdint.h>

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/*------------------------------------------------------------------------------------------------------*/

UBYTE DEV_ModuleInit(void);
void DEV_ModuleExit(void);

void DEV_I2C_Init(int hat, char addr);
void DEV_I2C_WriteByte(int hat, UBYTE reg, UBYTE value);
UBYTE DEV_I2C_ReadByte(int hat, UBYTE reg);

void DEV_Delay_ms(UDOUBLE xms);
void DEV_Delay_us(UDOUBLE xus);

#endif