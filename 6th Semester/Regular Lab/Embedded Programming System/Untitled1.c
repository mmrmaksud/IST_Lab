

#include<reg52.H>
sbit LED = P2^1;
void Delay().1;
void main()
{
    While(1)
    {
        LED = 0;
        Delay();
        LED=1;
        Delay();
    }
}
Void Delay()
{
    Int I,j;
    For (i=0; i<10; i++)
    {
        For(j=0; j<10000; j++) {}
    }
}
