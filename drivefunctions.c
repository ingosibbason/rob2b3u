
void resetencoder(){
	nMotorEncoder[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;
}

void drive(bool bf){
	int i = 1;
	if(!bf){
		i = -1;
	}
	if(abs(nMotorEncoder[rightMotor]) == abs(nMotorEncoder[leftMotor])) // If rightEncoder has counted the same amount as leftEncoder:
	{
		// Move Forward
		motor[rightMotor] = 40*i;		    // Right Motor is run at power level 80
		motor[leftMotor]  = 40*i;		    // Left Motor is run at power level 80
	}
	else if(abs(nMotorEncoder[rightMotor]) > abs(nMotorEncoder[leftMotor]))	// If rightEncoder has counted more encoder counts
	{
		// Turn slightly right
		motor[rightMotor] = 30*i;		    // Right Motor is run at power level 60
		motor[leftMotor]  = 40*i;		    // Left Motor is run at power level 80
	}
	else	// Only runs if leftEncoder has counted more encoder counts
	{
		// Turn slightly left
		motor[rightMotor] = 40*i;		    // Right Motor is run at power level 80
		motor[leftMotor]  = 30*i;		    // Left Motor is run at power level 60
	}
}
