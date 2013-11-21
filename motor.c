#include <msp430.h>
#include "motor.h"

void initRobot(void)
{
	P1DIR |= BIT1|BIT2;
	P1SEL |= BIT1|BIT2;
	P2DIR |= BIT0|BIT1;
	P2SEL |= BIT0|BIT1;
	TA0CTL &= ~(MC1|MC0);
	TA0CTL |= TACLR;
	TA0CTL |= TASSEL1;
	TA1CTL |= TACLR;
	TA1CTL |= TASSEL1;
	TA0CCR0 = 100;
	TA0CCR1 = 50;
	TA1CCR0 = 100;
	TA1CCR1 = 50;
	TA0CTL |= MC0;
	TA1CTL |= MC0;  //not sure about these two, might be unnecessary
}

void moveLeftWheelForward(void)
{
	TA0CTL &= ~(MC1|MC0);
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5); //Clears bits in OUTMOD so no errors when writing a new mode(only modes 4 and 5 used for first pin)
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5); //Same thing but clears modes 7 and 5 because they are the only ones used on the second pin
	TA0CCTL0 |= OUTMOD_5;         //Reset mode for ground
	TA0CCTL1 |= OUTMOD_7;         //Reset/set mode
	TA0CTL |= MC0;                //Count up to TACCR0 mode
	__delay_cycles(100);

}

void moveLeftWheelBack(void)
{
	TA0CTL &= ~(MC1|MC0);
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA0CCTL0 |= OUTMOD_4;         //Toggle output on TACCR0
	TA0CCTL1 |= OUTMOD_5;
	TA0CTL |= MC0;
	__delay_cycles(100);
}

void moveRightWheelForward(void)
{
	TA1CTL &= ~(MC1|MC0);
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_7;
	TA1CTL |= MC0;
	__delay_cycles(100);
}

void moveRightWheelBack(void)
{
	TA1CTL &= ~(MC1|MC0);
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL0 |= OUTMOD_4;
	TA1CCTL1 |= OUTMOD_5;
	TA1CTL |= MC0;
	__delay_cycles(100);
}

void stopLeftWheel(void)
{
	TA0CTL &= ~(MC1|MC0);
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA0CCTL0 |= OUTMOD_5;         //Output as specified by Out (cleared in next line - output is zero)
	TA0CCTL1 |= OUTMOD_5;         //Reset mode
	TA0CTL |= MC0;
	__delay_cycles(100);
}

void stopRightWheel(void)
{
	TA1CTL &= ~(MC1|MC0);
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL0 |= OUTMOD_5;
	TA1CCTL1 |= OUTMOD_5;
	TA1CTL |= MC0;
	__delay_cycles(100);
}

void moveRobotForward(void)
{
	moveRightWheelForward();
	moveLeftWheelForward();
}

void moveRobotBackward(void)
{
    moveRightWheelBack();
    moveLeftWheelBack();
}

void turnRobotRight(void)
{
    moveRightWheelBack();
    moveLeftWheelForward();
    __delay_cycles(300000);
}

void turnRobotLeft(void)
{
    moveRightWheelForward();
    moveLeftWheelBack();
    __delay_cycles(900000);
}

void stopRobot(void)
{
    stopRightWheel();
    stopLeftWheel();
}
