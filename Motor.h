#include <Arduino.h>

#ifndef _MOTOR_H_
#define _MOTOR_H_

class motor
{
  private:
	unsigned char pinA, pinB, pinPWM;
	int speed;
	unsigned int maxSpeed;
	
  public:
	motor();
	motor(unsigned char _pinA, unsigned char _pinB, unsigned char _pinPWM = 255, unsigned int _maxSpeed = 255);

	void setPins( unsigned char _pinA, unsigned char _pinB, unsigned char _pinPWM );
	void setMaxSpeed(unsigned int _maxSpeed);
	void initialise( );
	void setSpeed( int _speed );
	void write( int _speed );
	void write( );
	void stop( );
};

#endif
