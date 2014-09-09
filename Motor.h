#include <Arduino.h>

#ifndef _MOTOR_H_
#define _MOTOR_H_

class motor
{
	// private class members
private:
	// digital and PWM pin definitions
	// if using a simple H-bridge driver only two pins are used,
	// if that is the case, for controlling motor speed pinA whould be PWM capable
	// for motor drivers with a separate pin for PWM use the third pin,
	// in this case pinA and pinB are digital and pinPWM should be PWM enabled
	unsigned char pinA, pinB, pinPWM;

	// speed stores the speed which was last written to the motors
	int speed;

	// maxSpeed stores the upper limit of the speed which will be given to the motors
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
