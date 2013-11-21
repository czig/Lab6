#include <msp430.h>
#include "motor.h"

void moveLeftWheelForward(void)
{
	P1DIR |= BIT1|BIT2;
	P1SEL |= BIT1|BIT2;
	TA0CTL &= ~(MC1|MC0);
	TA0CTL |= TACLR;
	TA0CTL |= TASSEL1;
	TA0CCR0 = 100;
	TA0CCR1 = 50;
	TA0CCTL0 |= OUTMOD_5;         //Reset mode
	//TA0CCTL0 &= ~OUT;
	TA0CCTL1 |= OUTMOD_7;         //reset/set mode
	TA0CTL |= MC0;                //Count up to TACCR0 mode
	__delay_cycles(1000);

}

void moveLeftWheelBack(void)
{
	//P1DIR |= BIT1|BIT2;
	//P1SEL |= BIT1|BIT2;
	TA0CTL &= ~(MC1|MC0);
	//TA0CTL |= TACLR;
	//TA0CTL |= TASSEL1;
	//TA0CCR0 = 100;
	//TA0CCR1 = 50;
	TA0CCTL0 |= OUTMOD_4;         //Toggle output on TACCR0
	TA0CCTL1 |= OUTMOD_5;
	//TA0CCTL1 &= ~OUT;
	TA0CTL |= MC0;
	__delay_cycles(1000);
}

void moveRightWheelForward(void)
{
	P2DIR |= BIT0|BIT1;
	P2SEL |= BIT0|BIT1;
	TA1CTL &= ~(MC1|MC0);
	TA1CTL |= TACLR;
	TA1CTL |= TASSEL1;
	TA1CCR0 = 100;
	TA1CCR1 = 50;
	TA1CCTL0 |= OUTMOD_5;
	//TA1CCTL0 &= ~OUT;
	TA1CCTL1 |= OUTMOD_7;
	TA1CTL |= MC0;
	__delay_cycles(1000);
}

void moveRightWheelBack(void)
{
	//P2DIR |= BIT0|BIT1;
	//P2SEL |= BIT0|BIT1;
	TA1CTL &= ~(MC1|MC0);
	//TA1CTL |= TACLR;
	//TA1CTL |= TASSEL1;
	//TA1CCR0 = 100;
	//TA1CCR1 = 50;
	TA1CCTL0 |= OUTMOD_4;
	TA1CCTL1 |= OUTMOD_5;
	//TA1CCTL1 &= ~OUT;
	TA1CTL |= MC0;
	__delay_cycles(1000);
}
