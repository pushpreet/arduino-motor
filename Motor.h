#include<Arduino.h>

#ifndef _MOTOR_H_
#define _MOTOR_H_

class motor
{
  private:
    unsigned int pinA, pinB;
    int speed;
    
  public:
    motor( )
    {
      pinA = 0;
      pinB = 0;
      speed = 0;
    }
    
    motor( unsigned int _pinA, unsigned int _pinB, int _speed )
    {
      pinA = _pinA;
      pinB = _pinB;
      speed = _speed;
    }
    
   void setPins( unsigned int _pinA, unsigned int _pinB );
   void initialise( );
   void setSpeed( int _speed );
   void write( int _speed );
   void write( );
   void stop( );
};

void motor :: setPins( unsigned int _pinA, unsigned int _pinB )
{
  pinA = _pinA;
  pinB = _pinB;
}
    
void motor :: initialise( )
{
  pinMode( pinA, OUTPUT);
  pinMode( pinB, OUTPUT);
}

void motor :: setSpeed( int _speed )
{
  speed = _speed;
}

void motor :: stop( )
{
  digitalWrite( pinA, LOW);
  digitalWrite( pinB, LOW);
}

void motor :: write( int _speed )
{
  if( _speed >= 0 )
  {
    analogWrite( pinA, _speed);
    digitalWrite( pinB, LOW);
  }
  
  else if( _speed < 0 )
  {
    digitalWrite( pinA, LOW);
    analogWrite( pinB, -_speed);
  }
}

void motor :: write( )
{
  if( speed >= 0 )
  {
    analogWrite( pinA, speed);
    digitalWrite( pinB, LOW);
  }
  
  else if( speed < 0 )
  {
    digitalWrite( pinA, LOW);
    analogWrite( pinB, -speed);
  }
}

#endif
