#include "servo.h"

Servo servo;

void servoSetup()
{
    Serial.begin(115200);
    servo.setPeriodHertz(50);
    servo.attach(servoPin,500,2400);

    if(servo.attached())
    {
      Serial.println("servo attached");
    }
    servo.write(0);

}

void servoOpen()
{
   servo.write(180);
}

void servoClose()
{
  servo.write(0);
}