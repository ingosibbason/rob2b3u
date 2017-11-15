#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    lineTracker,    sensorLineFollower)
#pragma config(Sensor, in2,    armEncoder,     sensorPotentiometer)
#pragma config(Sensor, dgtl1,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  Button,         sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port3,           rightMotor,    tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port6,           armMotor,      tmotorVex269, openLoop)
#pragma config(Motor,  port7,           clawMotor,     tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void detectObject()
{
	if(SensorValue(sonarSensor) < 30)
	{
		nMotorEncoder[rightMotor] = 0;
		nMotorEncoder[leftMotor] = 0;

		while(SensorValue(sonarSensor) > 2)
		{
		  motor[rightMotor] = -30;
			motor[leftMotor]	= -30;
		}
	}
	if(SensorValue(sonarSensor) > 2)
	{
		motor[rightMotor] = 0;
		motor[leftMotor] = 0;
	}
}

void driveTowardsObject()
{
		nMotorEncoder[rightMotor] = 0;
		nMotorEncoder[leftMotor] = 0;
		//nMotorEncoder[rightMotor] and nMotorEncoder[leftMotor] need to be calculated the correct length;
		while(nMotorEncoder[rightMotor] <= 2 && nMotorEncoder[leftMotor] <= 2)
		{
		  motor[rightMotor] = -20;
			motor[leftMotor]	= -20;
		}
}

void driveBack()
{
	  nMotorEncoder[rightMotor] = 0;
		nMotorEncoder[leftMotor] = 0;
		//nMotorEncoder[rightMotor] and nMotorEncoder[leftMotor] need to be calculated the correct length;
		while(nMotorEncoder[rightMotor] >= -2 && nMotorEncoder[leftMotor] >= -2)
		{
		  motor[rightMotor] = 20;
			motor[leftMotor]	= 20;
		}
}

void grabObject()
{
		while(SensorValue(armEncoder) > 2200)
		{
			motor[armMotor] = 63;
		}
		motor[armMotor] = 0;
}
bool correctItem = false;
void detectColor()
{
		if(SensorValue(lineTracker) > 400)
		{
			correctItem = false;
		{
		if(SensorValue(lineTracker) < 400 )
		{
			correctItem = true;
		}
}
}
}


task main()
{
	//Clear the encoders associated with the left and right motors
	nMotorEncoder[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;


	if(correctItem == false)
	{
		detectObject();
		driveTowardsObject();
		detectColor();
	}
	else
	{
	driveBack();
  }
}