#include <reg51.h>
void Delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<100;j++)
		{
		}
	}
}
void main()
{
	while(1)
	{
		P2=0x09;
		Delay();
		P2=0x0C;
		Delay();
		P2=0x06;
		Delay();
		P2=0x03;
		Delay();
		
	}
}