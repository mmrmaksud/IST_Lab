#include<reg51.h>
void delay();

void main()
{
	while(1)
	{
		P1 = 0xCC; // Pattern to turn on alternate LEDs - 10101010
		delay();
		P1 = 0x33; // Reverse the pattern
		delay();
	}
}

void delay()
{
	unsigned int i, j;
	for(i = 0; i < 23; i++)
	{
		for(j = 0; j < 1000; j++)
		{
		}
	}
}