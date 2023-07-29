#ifndef VEHICLE_H
#define VEHICLE_H

#define IN1 27
#define IN2 26
#define IN3 25
#define IN4 33

// #define IN1led 2                                 // Assign output variables to GPIO pins
// #define IN2led 23
// #define IN3led 22
// #define IN4led 1

void motorSetup();
void moveFwd();
void moveBwd();
void moveLeft();
void moveRight();
void moveStop();
#endif