/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Ring-0
* Project: CSC 615 Term Project
*
* File: MotorDriver.c
*
* Description: 
* 
**************************************************************/
#include "MotorDriver.h"
#include "Debug.h"

/**
 * Motor rotation.
 *
 * Example:
 * Motor_Init();
 */
void Motor_Init(void)
{
    PCA9685_Init(1, 0x40); // Bottom HAT
    PCA9685_Init(0, 0x50); // Top HAT
    PCA9685_SetPWMFreq(0, 100);
    PCA9685_SetPWMFreq(1, 100);
}

/**
 * Motor rotation.
 *
 * @param motor: Motor A and Motor B.
 * @param dir: forward and backward.
 * @param speed: Rotation speed.  //(0~100)
 *
 * Example:
 * @code
 * Motor_Run(MOTORA, FORWARD, 50);
 * Motor_Run(MOTORB, BACKWARD, 100);
 */
void Motor_Run(int hat, UBYTE motor, DIR dir, UWORD speed)
{
    if(speed > 100)
        speed = 100;

    if(motor == MOTORA) {
        DEBUG("Motor A Speed = %d\r\n", speed);
        PCA9685_SetPwmDutyCycle(hat, PWMA, speed);
        if(dir == FORWARD) {
            DEBUG("forward...\r\n");
            PCA9685_SetLevel(hat, AIN1, 0);
            PCA9685_SetLevel(hat, AIN2, 1);
        } else {
            DEBUG("backward...\r\n");
            PCA9685_SetLevel(hat, AIN1, 1);
            PCA9685_SetLevel(hat, AIN2, 0);
        }
    } else {
        DEBUG("Motor B Speed = %d\r\n", speed);
        PCA9685_SetPwmDutyCycle(hat, PWMB, speed);
        if(dir == FORWARD) {
            DEBUG("forward...\r\n");
            PCA9685_SetLevel(hat, BIN1, 0);
            PCA9685_SetLevel(hat, BIN2, 1);
        } else {
            DEBUG("backward...\r\n");
            PCA9685_SetLevel(hat, BIN1, 1);
            PCA9685_SetLevel(hat, BIN2, 0);
        }
    }
}

/**
 * Motor stop rotation.
 *
 * @param motor: Motor A and Motor B.
 *
 * Example:
 * @code
 * Motor_Stop(MOTORA);
 */
void Motor_Stop(int hat, UBYTE motor)
{
    if(motor == MOTORA) {
        PCA9685_SetPwmDutyCycle(hat, PWMA, 0);
    } else {
        PCA9685_SetPwmDutyCycle(hat, PWMB, 0);
    }
}