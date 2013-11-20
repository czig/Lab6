void moveLeftWheelForward(void)
{
	P1DIR |= BIT1|BIT2;
	P1SEL |= BIT1|BIT2;
	TACTL &= ~(MC1|MCO);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACCR0 = 100;
	TACCR1 = 50;                 //Changed from 40 to 50 to keep a constant 50% duty cycle for every wheel movement
	TACCTL0 |= OUTMOD_0;         //Output as specified by Out (cleared in next line - output is zero)
	TACCTL0 &= ~OUT;
	TACCTL1 |= OUTMOD_3;         //Set/Reset mode
	TACTL |= MCO;                //Count up to TACCR0 mode

	//Do something about making a pin ground, and repeat all of this in opposite ways for other functions
}

void moveLeftWheelBack(void)
{
	P1DIR |= BIT1|BIT2;
	P1SEL |= BIT1|BIT2;
	TACTL &= ~(MC1|MCO);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACCR0 = 100;
	TACCR1 = 50;
	TACCTL0 |= OUTMOD_4;         //Toggle output on TACCR0
	TACCTL1 |= OUTMOD_0;
	TACCTL1 &= ~OUT;
	TACTL |= MCO;
}

void moveRightWheelForward(void)
{
	P2DIR |= BIT0|BIT1;
	P2SEL |= BIT0|BIT1;
	TACTL &= ~(MC1|MCO);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACCR0 = 100;
	TACCR1 = 50;
	TACCTL0 |= OUTMOD_0;
	TACCTL0 &= ~OUT;
	TACCTL1 |= OUTMOD_3;
	TACTL |= MCO;
}

void moveRightWheelBack(void)
{
	P2DIR |= BIT0|BIT1;
	P2SEL |= BIT0|BIT1;
	TACTL &= ~(MC1|MCO);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACCR0 = 100;
	TACCR1 = 50;
	TACCTL0 |= OUTMOD_4;
	TACCTL1 |= OUTMOD_0;
	TACCTL1 &= ~OUT;
	TACTL |= MCO;
}

void stopLeftWheel(void)
{
	P1DIR |= BIT1|BIT2;
	P1SEL |= BIT1|BIT2;
	TACTL &= ~(MC1|MCO);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACCR0 = 100;
	TACCR1 = 50;                 //Changed from 40 to 50 to keep a constant 50% duty cycle for every wheel movement
	TACCTL0 |= OUTMOD_0;         //Output as specified by Out (cleared in next line - output is zero)
	TACCTL0 &= ~OUT;
	TACCTL1 |= OUTMOD_0;         //Set/Reset mode
	TACCTL1 &= ~OUT;
	TACTL |= MCO;
}

void stopRightWheel(void)
{
	P2DIR |= BIT0|BIT1;
	P2SEL |= BIT0|BIT1;
	TACTL &= ~(MC1|MCO);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACCR0 = 100;
	TACCR1 = 50;
	TACCTL0 |= OUTMOD_0;
	TACCTL0 &= ~OUT;
	TACCTL1 |= OUTMOD_0;
	TACCTL1 &= ~OUT;
	TACTL |= MCO;
}
