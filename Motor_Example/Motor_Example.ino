#include <Motor.h>

int MAX_SPEED = 2048;

motor motorLeft, motorRight;

void setup( )
{
  motorLeft.setPins(6, 5, 4);
  motorRight.setPins(8, 9, 10);
 
  motorLeft.setMaxSpeed(MAX_SPEED);
  motorRight.setMaxSpeed(MAX_SPEED);
  
  motorLeft.initialise();
  motorRight.initialise();
  
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
}

void loop( )
{
  // Go Forward
  motorLeft.write(MAX_SPEED);
  motorRight.write(MAX_SPEED);
  
  delay(500);
  
  // Stop
  motorLeft.stop();
  motorRight.stop();
  
  delay(1000);
  
  // Go Backward
  motorLeft.write(-MAX_SPEED);
  motorRight.write(-MAX_SPEED);
  
  delay(500);
  
  // Stop
  motorLeft.stop();
  motorRight.stop();
  
  delay(1000);
  
  // Turn Left
  motorLeft.write( - MAX_SPEED / 3);
  motorRight.write(MAX_SPEED / 3);
  
  delay(200);
  
  // Stop
  motorLeft.stop();
  motorRight.stop();
  
  delay(1000);
  
  // Turn Right
  motorLeft.write(MAX_SPEED / 3);
  motorRight.write( - MAX_SPEED / 3);
  
  delay(200);
  
  // Stop
  motorLeft.stop();
  motorRight.stop();
  
  delay(1000);
  
  while(1);
}