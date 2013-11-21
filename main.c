/************************************
 * Author: C2C Caleb Ziegler
 * Date: 17 NOV 13
 * Description: Moves robot forward,
 * backward, right (by an angle less
 * than 45 degrees), and left (by an
 * angle greater than 45 degrees.
 ***********************************/

#include <msp430.h> 
#include "motor.h"

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    initRobot();
    __delay_cycles(10000000);
    moveRightWheelForward();
    moveLeftWheelForward();
    __delay_cycles(1000000);
    stopRightWheel();
    stopLeftWheel();
    __delay_cycles(1000000);
    moveRightWheelBack();
    moveLeftWheelBack();
    __delay_cycles(1000000);
    stopRightWheel();
    stopLeftWheel();
    __delay_cycles(1000000);
    moveRightWheelForward();
    moveLeftWheelBack();
    __delay_cycles(300000);
    stopRightWheel();
    stopLeftWheel();
    __delay_cycles(1000000);
    moveRightWheelBack();
    moveLeftWheelForward();
    __delay_cycles(900000);
    stopRightWheel();
    stopLeftWheel();

    //More modular way to run this code
    //initRobot();
    //__delay_cycles(5000000);
    //moveRobotForward();
    //__delay_cycles(1000000);
    //stopRobot();
    //__delay_cycles(1000000);
    //moveRobotBackward();
    //__delay_cycles(1000000);
    //stopRobot();
    //__delay_cycles(1000000);
    //turnRobotLeft();
    //stopRobot();
    //__delay_cycles(1000000);
    //turnRobotRight();
    //stopRobot();



    while(1)
    {

    }

}
