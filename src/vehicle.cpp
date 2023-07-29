#include "vehicle.h"
#include <Arduino.h>

void moveFwd()
{
    digitalWrite(IN1 , LOW);
    digitalWrite(IN2 , HIGH);
    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , HIGH);
}

void moveBwd()
{
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , LOW);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , LOW);
}

void moveLeft()
{
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , LOW);
    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , HIGH);
}

void moveRight()
{
    digitalWrite(IN1 , LOW);
    digitalWrite(IN2 , HIGH);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , LOW);
}

void moveStop()
{
    digitalWrite(IN1 , LOW);
    digitalWrite(IN2 , LOW);
    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , LOW);
}

void motorSetup()
{
    pinMode(IN1 , OUTPUT);
    pinMode(IN2 , OUTPUT);
    pinMode(IN3 , OUTPUT);
    pinMode(IN4 , OUTPUT);

    moveStop();
}

// void moveFwd()
// {
//     digitalWrite(IN1led , LOW);
//     digitalWrite(IN2led , HIGH);
//     digitalWrite(IN3led , LOW);
//     digitalWrite(IN4led , HIGH);
// }

// void moveBwd()
// {
//     digitalWrite(IN1led , HIGH);
//     digitalWrite(IN2led , LOW);
//     digitalWrite(IN3led , HIGH);
//     digitalWrite(IN4led , LOW);
// }

// void moveLeft()
// {
//     digitalWrite(IN1led , HIGH);
//     digitalWrite(IN2led , LOW);
//     digitalWrite(IN3led , LOW);
//     digitalWrite(IN4led, HIGH);
// }

// void moveRight()
// {
//     digitalWrite(IN1led , LOW);
//     digitalWrite(IN2led , HIGH);
//     digitalWrite(IN3led , HIGH);
//     digitalWrite(IN4led , LOW);
// }

// void moveStop()
// {
//     digitalWrite(IN1led , LOW);
//     digitalWrite(IN2led , LOW);
//     digitalWrite(IN3led , LOW);
//     digitalWrite(IN4led , LOW);
// }

// void motorSetup()
// {
//     pinMode(IN1led , OUTPUT);
//     pinMode(IN2led , OUTPUT);
//     pinMode(IN3led , OUTPUT);
//     pinMode(IN4led , OUTPUT);

//     moveStop();
// }


