#include<reg52.H>
sbit LED = P2^1;
void Delay();
void main()
{
    while(1)
    {
        LED = 0;
        Delay();
        LED=1;
        Delay();
    }
}
void Delay()
{
    int i,j;
    for (i=0; i<10; i++)
    {
        for(j=0; j<10000; j++) {}
    }
}