#ifndef SERVO_H
#define SERVO_H

#include <ESP32Servo.h>

#define servoPin  15

void servoSetup();
void servoOpen();
void servoClose();

#endif