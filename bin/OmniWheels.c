/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Ring-0
* Project: CSC 615 Term Project
*
* File: OmniWheels.c
*
* Description: 
* This file is (literally) the driver of the car. All of the 
* functions defined here allow the car to move in any direction
**************************************************************/
#include "OmniWheels.h"
#include <stdio.h>

int pwm = 60;

void set_pwm(int new_pwm) {
    pwm = new_pwm;
}

void get_pwm() {
    return pwm;
}

void run_omni_demo() {
    printf("Demo init motor...\n");
    init_omni(); 
    long run_start = micros(); 

    // 1) Drive forward for 2sec
    printf("PRANCE FORWARD...\n");
    
    motor_drive(FORWARD, pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);

    // 2) Drive backward for 2sec
    printf("BOOGIE DOWN...\n");
    run_start = micros();
    motor_drive(BACKWARD, pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);

    // 3) Rotate left for 2sec
    printf("Rotate CCW\n");
    run_start = micros();
    rotate_ccw(pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);
    
    // 4) Rotate right for 2sec
    printf("Rotate CW\n");
    run_start = micros();
    rotate_cw(pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);

    // 5) Strafe left for 2sec
    printf("SASHAY LEFT...\n");
    run_start = micros();
    strafe_left(pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);

    // 6) Strafe right for 2sec
    printf("SHIMMY RIGHT...\n");
    run_start = micros();
    strafe_right(pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);

    // 7) Left diagonal
    printf("Left Diag Fwd\n");
    run_start = micros();
    diag_left(FORWARD, pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);
    printf("Left Diag Bwd\n");
    run_start = micros();
    diag_left(BACKWARD, pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);

    // 8) Right diagonal
    printf("Right Diag Fwd\n");
    run_start = micros();
    diag_right(FORWARD, pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);
    printf("Right Diag Bwd\n");
    run_start = micros();
    diag_right(BACKWARD, pwm);
    interval(3e6);
    printf("STOP!\n");
    stop_motors();
    run_start = micros();
    interval(1.75e6);
}

void init_omni() {
    printf("OmniWheels init_omni()\n");
    Motor_Init();
}

void motor_test(DIR dir, int pwr, int fd, int motor) {
    if (motor == 1) {
        Motor_Run(fd, MOTORA, dir, pwr);
    } else {
        Motor_Run(fd, MOTORB, dir, pwr);
    }
}

/**
 * This function is the standard driving forward or backward
 * 
 * @param dir: FORWARD or BACKWARD
 * @param pwr: represents % of power for motors
 */
void motor_drive(DIR dir, int pwr) {
    Motor_Run(0, MOTORA, dir, pwr);
    Motor_Run(0, MOTORB, dir, pwr);
    Motor_Run(1, MOTORA, dir, pwr);
    Motor_Run(1, MOTORB, dir, pwr);
}

/**
 * This function stops all motors
 */
void stop_motors() {
    Motor_Stop(0, MOTORA);
    Motor_Stop(0, MOTORB);
    Motor_Stop(1, MOTORA);
    Motor_Stop(1, MOTORB);
}

/**
 * This function is to make the car move straight left
 * 
 * @param pwr: represents % of power for motors
 */
void strafe_left(int pwr) {
    Motor_Run(0, MOTORA, BACKWARD, pwr);
    Motor_Run(0, MOTORB, FORWARD, pwr);
    Motor_Run(1, MOTORA, FORWARD, pwr);
    Motor_Run(1, MOTORB, BACKWARD, pwr);
}

/**
 * This function is to make the car move straight right
 * 
 * @param pwr: represents % of power for motors
 */
void strafe_right(int pwr) {
    Motor_Run(0, MOTORA, FORWARD, pwr);
    Motor_Run(0, MOTORB, BACKWARD, pwr);
    Motor_Run(1, MOTORA, BACKWARD, pwr);
    Motor_Run(1, MOTORB, FORWARD, pwr);
}

/**
 * This function is to make the car move along the major diagonal
 * 
 * @param dir: FORWARD or BACKWARD
 * @param pwr: represents % of power for motors
 */
void diag_left(DIR dir, int pwr) {
    Motor_Run(0, MOTORB, dir, pwr);
    Motor_Run(1, MOTORA, dir, pwr);
    Motor_Stop(1, MOTORB);
    Motor_Stop(0, MOTORA);
}

/**
 * This function is to make the car move along the minor diagonal
 * 
 * @param dir: FORWARD or BACKWARD
 * @param pwr: represents % of power for motors
 */
void diag_right(DIR dir, int pwr) {
    Motor_Run(0, MOTORA, dir, pwr);
    Motor_Run(1, MOTORB, dir, pwr);
    Motor_Stop(1, MOTORA);
    Motor_Stop(0, MOTORB);
}

/**
 * This function is to make the car rotate counter-clockwise (turn left)
 * 
 * @param pwr: represents % of power for motors
 */
void rotate_ccw(int pwr) {
    Motor_Run(0, MOTORA, BACKWARD, pwr);
    Motor_Run(0, MOTORB, FORWARD, pwr);
    Motor_Run(1, MOTORA, BACKWARD, pwr);
    Motor_Run(1, MOTORB, FORWARD, pwr);
}

/**
 * This function is to make the car rotate clockwise (turn right)
 * 
 * @param pwr: represents % of power for motors
 */
void rotate_cw(int pwr) {
    Motor_Run(0, MOTORA, FORWARD, pwr);
    Motor_Run(0, MOTORB, BACKWARD, pwr);
    Motor_Run(1, MOTORA, FORWARD, pwr);
    Motor_Run(1, MOTORB, BACKWARD, pwr);
}

void interval(long delta) {
    long run_start = micros();
    while (micros() - run_start <= delta);
}