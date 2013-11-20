void moveLeftWheelForward(void)
{
	P1DIR |= BIT0|BIT2;
	P1SEL |= BIT0|BIT2;
	TACTL &= ~(MC1|MCO);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACCRO = 100;
	TACCR1 = 40;
	TACCTL0 |= OUTMOD_0;
	TACCTL0 &= ~OUT
	TACCTL1 |= OUTMOD_3;
	TACTL |= MCO;

	//Do something about making a pin ground, and repeat all of this in opposite ways for other functions
}

void moveLeftWheelBack(void)
{
	P1DIR |= BIT0|BIT2;
	P1SEL |= BIT0|BIT2;
	TACTL &= ~(MC1|MCO);
	TACTL |= TACLR;
	TACTL |= TASSEL1;
	TACCRO = 100;
	TACCR1 = 40;
	TACCTL0 |= OUTMOD_0;
	TACCTL0 &= ~OUT
	TACCTL1 |= OUTMOD_3;
	TACTL |= MCO;
}

void moveRightWheelForward(void)
{

}

void moveRightWheelBack(void)
{

}
