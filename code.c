#pragma config(Motor,  port1,           rightMotor,    tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port9,           arm,           tmotorServoStandard, openLoop)
#pragma config(Motor,  port10,          leftMotor,     tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*The Joystick's Vertical position is translated into values between -127 and +127
with 0 being the neutral center position, +127 bring the top and -127 at the bottom.
http://www.robotc.net/tutor/Cortex/cortex.php?platform=Cortex&unit=vexnetremotecontrol&lesson=1
*/

task main()
{
	int direction = 1; //1 = front (becomes forward direction), -1 = back (becomes forward direction)
	int ang = 0;
	//motor[port9] = -10;


	while(1) {

			if(vexRT[Btn7U]) {
				ang = -180;
				motor[port9] = ang;
			}
			if(vexRT[Btn7D]) {
				ang = 80;
				motor[port9] = ang;
			}

			while(vexRT[Btn5U]) {
				ang = ang - 2;
				if(ang < -180)
					ang = -180;
				motor[port9] = ang;
				wait10Msec(1);
			}

			while(vexRT[Btn5D]) {
				ang = ang + 2;
				if(ang > 180)
					ang = 180;
				motor[port9] = ang;
				wait10Msec(1);
			}

			//dump stuff
			if(vexRT[Btn6U]) {
				//motor[port1] = -100;
				//motor[port10] = -100; //full speed opposite direction
				//wait10Msec(20);
				ang = -180;
				direction = -1;
				motor[port9] = ang;

				motor[port1] = -1*vexRT[Ch3];1
				motor[port10] = -1*vexRT[Ch2];

				wait10Msec(25);
				//motor[port1] = 0;
				//motor[port10] = 0;
				for(int i=0; i<3; i++) {
					motor[port1] = -1*vexRT[Ch3];
					motor[port10] = -1*vexRT[Ch2];

					motor[port9] = -35;

					wait10Msec(25);
					motor[port9] = -180;

					motor[port1] = -1*vexRT[Ch3];
					motor[port10] = -1*vexRT[Ch2];

					wait10Msec(25);
				}

				/*
				if(ang < -10) {
					for(int i=ang; i<-10; i=i+2) {
						motor[port9] = i;
						wait10Msec(1);
					}
				}

				if(ang > -10) {
					for(int i=ang; i>-10; i=i-2) {
						motor[port9] = i;
						wait10Msec(1);
					}

				}

				ang=-10;
				for(int i=0; i<4; i++) {
					motor[port9] = 0;
				}


				motor[port9] = 0;
				motor[port1] = -100;
				motor[port10] = -100; //full speed opposite direction
				wait10Msec(12);
				motor[port9] = -20;
				motor[port1] = 100;
				motor[port10] = 100; //full speed opposite direction
				wait10Msec(12);
				motor[port9] = -10;
				motor[port1] = 0;
				motor[port10] = 0;
				wait10Msec(12);
				*/
			}

			if(vexRT[Btn8U]) //8 Up
				direction = 1;

			if(vexRT[Btn8D]) //8 Down
				direction = -1;

			//move  robot!
			if(direction == 1) {
				motor[port1] = vexRT[Ch2];
				motor[port10] = vexRT[Ch3];
			}
			else {
				motor[port1] = -1*vexRT[Ch3]; //switch which motor controls which
				motor[port10] = -1*vexRT[Ch2];
			}


		}
}
