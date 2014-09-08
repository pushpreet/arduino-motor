#include <Arduino.h>

#ifndef _MOTOR_H_
#define _MOTOR_H_

class motor
{
  private:
	unsigned char pinA, pinB, pinPWM;
	int speed;
	
  public:
	motor();
	
	motor(unsigned int _pinA, unsigned int _pinB, int _speed);

	void setPins( unsigned int _pinA, unsigned int _pinB );
	void initialise( );
	void setSpeed( int _speed );
	void write( int _speed );
	void write( );
	void stop( );
};

#endif
