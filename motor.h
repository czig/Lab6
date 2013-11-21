/************************************
 * Author: C2C Caleb Ziegler
 * Date: 17 NOV 13
 * Description: Header file for interfacing with motor
 ***********************************/

#include <msp430.h>
#ifndef MOTOR_H_
#define MOTOR_H_

void moveLeftWheelForward(void);
void moveLeftWheelBack(void);
void moveRightWheelForward(void);
void moveRightWheelBack(void);
void stopLeftWheel(void);
void stopRightWheel(void);

#endif /* MOTOR_H_ */
