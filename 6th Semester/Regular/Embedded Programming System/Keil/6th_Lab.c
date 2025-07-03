#include <reg51.h>
void Delay(int timer)
{
    int i, j;
    for (i = 0; i < timer; i++)
	{
        for (j = 0; j < 1000; j++)
		{}
  }
}
void main()
{
    P2 = 0x00;
    while (1)
    {
        P2++;
        Delay(200);
    }
}