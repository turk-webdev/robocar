/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Ring-0
* Project: CSC 615 Term Project
*
* File: MotorDriver.h
*
* Description: 
* Header file for the motor driver. Important to remember that
* the two separate HATs dictate the front & rear motor "axles".
* Motor A/B dictates the left/right motor respectively for each HAT.
**************************************************************/
#ifndef __TB6612FNG_
#define __TB6612FNG_

#include "DEV_Config.h"
#include "PCA9685.h"

//GPIO config
#define PWMA        PCA_CHANNEL_0 // Left
#define AIN1        PCA_CHANNEL_1 // Red
#define AIN2        PCA_CHANNEL_2 // Black
#define PWMB        PCA_CHANNEL_5 // Right
#define BIN1        PCA_CHANNEL_3 // Red
#define BIN2        PCA_CHANNEL_4 // Black

#define MOTORA       0      // Left Motor
#define MOTORB       1      // Right Motor

typedef enum {
    FORWARD  = 1,
    BACKWARD  ,
} DIR;

void Motor_Init(void);
void Motor_Run(int hat, UBYTE motor, DIR dir, UWORD speed);
void Motor_Stop(int hat, UBYTE motor);

#endif