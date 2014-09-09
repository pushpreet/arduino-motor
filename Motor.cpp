#include <Motor.h>

motor::motor()
{
	pinA = 255;
	pinB = 255;
	pinPWM = 255;
	speed = 0;
	maxSpeed = 255;
}

motor::motor(unsigned char _pinA, unsigned char _pinB, unsigned char _pinPWM, unsigned int _maxSpeed)
{
	pinA = _pinA;
	pinB = _pinB;
	pinPWM = _pinPWM;
	maxSpeed = _maxSpeed;
	speed = 0;
}

void motor::setPins(unsigned char _pinA, unsigned char _pinB, unsigned char _pinPWM)
{
	pinA = _pinA;
	pinB = _pinB;
	pinPWM = _pinPWM;
}

void motor::setMaxSpeed(unsigned int _maxSpeed)
{
	maxSpeed = _maxSpeed;
}

void motor::initialise()
{
	if ((pinA == 255) || (pinB == 255))
	{
		return;
	}
	
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	
	if (pinPWM != 255)
		pinMode(pinPWM, OUTPUT);
}

void motor::setSpeed(int _speed)
{
	if (_speed > maxSpeed)
	{
		_speed = maxSpeed;
	}
	else if (_speed < -maxSpeed)
	{
		_speed = -maxSpeed;
	}

	speed = _speed;
}

void motor::stop()
{
	digitalWrite(pinA, LOW);
	digitalWrite(pinB, LOW);
	analogWrite(pinPWM, LOW);
}

void motor::write(int _speed)
{
	if (_speed > maxSpeed)
	{
		_speed = maxSpeed;
	}
	else if (_speed < -maxSpeed)
	{
		_speed = -maxSpeed;
	}

	if (pinPWM == 255)
	{
		if (_speed >= 0)
		{
			analogWrite(pinA, _speed);
			digitalWrite(pinB, LOW);
		}

		else if (_speed < 0)
		{
			analogWrite(pinA, maxSpeed + _speed);
			digitalWrite(pinB, HIGH);
		}
	}
	
	else
	{
		if (_speed >= 0)
		{
			digitalWrite(pinA, HIGH);
			digitalWrite(pinB, LOW);

			analogWrite(pinPWM, _speed);
		}

		else if (_speed < 0)
		{
			digitalWrite(pinA, LOW);
			digitalWrite(pinB, HIGH);

			analogWrite(pinPWM, -_speed);
		}
	}
}

void motor::write()
{
	if (pinPWM == 255)
	{
		if (speed >= 0)
		{
			analogWrite(pinA, speed);
			digitalWrite(pinB, LOW);
		}

		else if (speed < 0)
		{
			analogWrite(pinA, maxSpeed + speed);
			digitalWrite(pinB, HIGH);
		}
	}

	else
	{
		if (speed >= 0)
		{
			digitalWrite(pinA, HIGH);
			digitalWrite(pinB, LOW);

			analogWrite(pinPWM, speed);
		}

		else if (speed < 0)
		{
			digitalWrite(pinA, LOW);
			digitalWrite(pinB, HIGH);

			analogWrite(pinPWM, -speed);
		}
	}
}
