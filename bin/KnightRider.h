/**************************************************************
* Class: CSC-615-01 Spring 2020
* Name: Ring-0
* Project: CSC 615 Term Project
*
* File: KnightRider.h
*
* Description: 
* Knight Rider - A shadowy flight into the dangerous world of a man
* who does not exist. Michael Knight, a young loner on a crusade to 
* champion the cause of the innocent, the helpless, the powerless, in
* a world of criminals who operate above the law.
**************************************************************/
#ifndef MAIN_H
#define MAIN_H

#include <wiringPi.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


// These are all wPi numbers
#define L1 8    // Physical: 3
#define L2 9    // Physical: 5
#define L3 15   // Physical: 8
#define L4 7    // Physical: 7
#define L5 16   // Physical: 10
#define L6 0    // Physical: 11
#define L7 2    // Physical: 13
#define L8 1    // Physical: 12

#define NUM_LIGHTS 8

void turn_on_single(int pin_idx);
void turn_off_all();
void turn_on_all();
void kit_init();
void kit_run();

enum lights{a1=L1, a2=L2, a3=L3, a4=L4, a5=L5, a6=L6, a7=L7, a8=L8};
static const enum lights lights_vect[] = { a1, a2, a3, a4, a5, a6, a7, a8 };



#endif