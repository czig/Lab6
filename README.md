Lab6
====

PWM - "Robot Motion"

This repository includes the files main.c, motor.h, and motor.c, which allow the MSP430 to interface with the motor on the robot to move the robot. Motor.h provides the functions required to operate the motors, while motor.c contains the implementations of those functions. 

##Grading

 - Prelab....................... 15
 - Required Functionality....... 35
 - B-Functionality.............. 10

##Operation: 

 - Required Functionality - The robot moves forward, backward, makes a small (less than 45 degrees) turn left and right, and finally makes a large (greater than 45 degrees) turn left and right. The operation of this can be seen in main.c where the delays represent the amount of time that the robot spends performing the previous function. 

##Functions: 

All functions pertaining to the operation of the motor and movement of the robot are shown below.

```
void initRobot(void);
```
 - Initializes the pins to be used (P1.1,P1.2,P2.0,P2.1), sets up the timer, and sets up a 50% duty cycle in the PWM (does not define the output modes yet).

```
void moveLeftWheelForward(void);
```
 - Makes left motor operate in "forward" direction. Sets OUTMOD in the Timer A Capture/Compare Control Register to allow P1.2 to carry the PWM signal at 50% duty cycle while P1.1 carries ground (P1.1 is connected to the black
terminal and P1.2 is connected to the red terminal).

```
void moveLeftWheelBack(void);
```
 - Reverses direction of left motor. Sets OUTMOD in the Timer A Capture/Compare Control Register to allow P1.1 to carry the PWM signal at 50% duty cycle while P1.2 carries ground (P1.1 is connected to the black terminal and P1.2 is connected to the red terminal).

```
void moveRightWheelForward(void);
```
 - Makes right motor move in "forward direction". Sets OUTMOD in the Timer A capture/compare control register so that P2.1 carries the PWM signal at 50% duty cycle while P2.0 carries ground (P2.1 connected to red terminal and P2.0 connected to black terminal).

```
void moveRightWheelBack(void);
```
 - Reverses direction of left motor. Sets OUTMOD in the Timer A capture/compare control register so that P2.0 carries the PWM signal at 50% duty cycle while P2.1 carries ground (P2.1 connected to red terminal and P2.0 connected to black terminal).

```
void stopLeftWheel(void);
```
 - Stops the left motor by setting both pins (P1.1 and P1.2) to ground. Sets OUTMOD in the Timer A Capture/Compare Control register to make this happen.

```
void stopRightWheel(void);
```
 - Stops the right motor by setting both pins (P2.0 and P2.1) to ground. Sets OUTMOD in the Timer A Capture/Compare Control register to make this happen.

```
void moveRobotForward(void);
```
 - Uses moveLeftWheelForward and moveRightWheelForward to make the robot move forward.

```
void moveRobotBackward(void);
```
 - Uses moveLeftWheelBack and moveRightWheelBack to make the robot move in reverse.

```
void turnRobotRight(void);
```
 - Uses moveRightWheelBack and moveLeftWheelForward to make the robot turn right.

```
void turnRobotLeft(void);
```
 - Uses moveLeftWheelBack and moveRightWheelForward to make the robot turn left.

```
void stopRobot(void);
```
 - Uses stopLeftWheel and stopRightWheel to make the robot come to a stop.

##Documentation
 
 - C2C Jason Mossing helped me troubleshoot hardware problems with my motor driver chip and fuses. 

 - C2C Colin Busho explained to me how the OUTMOD bits needed to be cleared before setting new OUTMOD bits to establish a new output mode for the PWM. Before he explained this to my, my motors could only move in one direction, and this occured because I was continually setting bits for OUTMOD so 

 - Captain Branchflower helped me troubleshoot hardware problems with my motor driver chip and fuses. Also, he explained to me how to make the PWM work by changing the output modes (OUTMOD) to be reset/set for the positive terminal and reset for the negative terminal. Additionally, he explained to me that if I want the motor to go in reverse, the positive terminal output mode (OUTMOD) must be set to reset to become ground and the negative terminal output mode must be changed to toggle in order to send the PWM signal to the negative terminal.

##Licensing

 - Anyone is free to use and modify this code for any reason as long as it is documented. 