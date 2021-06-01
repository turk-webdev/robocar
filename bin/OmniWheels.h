/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Ring-0
* Project: CSC 615 Term Project
*
* File: OmniWheels.h
*
* Description: 
* Header file for the (literal) driver class
**************************************************************/

#ifndef OMNIWHEELS_H
#define OMNIWHEELS_H

#include "DEV_Config.h"
#include "PCA9685.h"
#include "MotorDriver.h"

void run_omni_demo();
void init_omni();
void motor_test(DIR dir, int pwr, int fd, int motor);
void motor_drive(DIR dir, int pwr);
void stop_motors();
void strafe_left(int pwr);
void strafe_right(int pwr);
void diag_left(DIR dir, int pwr);
void diag_right(DIR dir, int pwr);
void rotate_ccw(int pwr);
void rotate_cw(int pwr);
void interval(long delta);
void set_pwm(int new_pwm);
void get_pwm();

#endif