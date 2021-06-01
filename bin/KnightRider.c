/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Ring-0
* Project: CSC 615 Term Project
*
* File: KnightRider.h
*
* Description: 
* We wanted to have a set of LED lights on the front that bounce
* back and forth like Kit from Knight Rider. Why? Because it's
* awesome and I have a hunch that Prof. Bierman would appreciate
* a callback to an 80s TV series featuring David Hasselhoff.
* Also it was something to do while waiting on other commits.
**************************************************************/
#include "KnightRider.h"

void turn_on_single(int pin_idx) {
    for (int i=0; i<NUM_LIGHTS; i++) {
        if (i == pin_idx) {
            digitalWrite(lights_vect[i], 1);
        } else {
            digitalWrite(lights_vect[i], 0);
        }
    }
}

void turn_off_all() {
    for (int i=0; i<NUM_LIGHTS; i++) {
        digitalWrite(lights_vect[i], 0);
    }
}

void turn_on_all() {
    for (int i=0; i<NUM_LIGHTS; i++) {
        digitalWrite(lights_vect[i], 1);
    }
}

void interrupt_handler(int signo) {
    printf("Interrupt command...\n");
    turn_off_all();
    exit(0);
}

void kit_init() {
    for (int i=0; i<NUM_LIGHTS; i++) {
        pinMode(lights_vect[i], OUTPUT);
        digitalWrite(lights_vect[i], 0);
    }
}

void kit_run() {  
    while(1) {
        int i=0;
        for (i; i<NUM_LIGHTS; i++) {
            turn_on_single(i);
            usleep(1e5);
        }

        for (i=NUM_LIGHTS-1; i>=0; i--) {
            turn_on_single(i);
            usleep(1e5);
        }
    }
}