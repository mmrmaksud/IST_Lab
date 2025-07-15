#include <reg51.h>
void Delay();
void main()
{
	while (1)
	{
		P1 = 0xAA;
		Delay();
		P1 = 0x55;
		Delay();
	}
}
void Delay()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10000; j++)
		{
		}
	}
}