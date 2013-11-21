/************************************
 * Author: C2C Caleb Ziegler
 * Date: 17 NOV 13
 * Description: Header file for interfacing with motor
 ***********************************/

#include <msp430.h>
#ifndef MOTOR_H_
#define MOTOR_H_

void initRobot(void);

void moveLeftWheelForward(void);

void moveLeftWheelBack(void);

void moveRightWheelForward(void);

void moveRightWheelBack(void);

void stopLeftWheel(void);

void stopRightWheel(void);

void moveRobotForward(void);

void moveRobotBackward(void);

void turnRobotRight(void);

void turnRobotLeft(void);

void stopRobot(void);

#endif /* MOTOR_H_ */
