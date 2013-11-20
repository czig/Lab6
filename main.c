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
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
	return 0;
}
