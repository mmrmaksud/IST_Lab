#include<reg51.h>

//signal 1
sbit tl1r = P2^0;      // red
sbit tl1o = P2^1;      // orange
sbit tl1g = P2^2;      // green

//signal 2
sbit tl2r = P2^3;    // red
sbit tl2o = P2^4;     // orange
sbit tl2g = P2^5;    // green

//signal 3
sbit tl3r = P3^0;    // red
sbit tl3o = P3^1;    // orange
sbit tl3g = P3^2;    // green


void delay(int t);          
void trafficlight(void);


void main()                  // main program
{
	P1=0x00;                     
	P2=0x00;
	P3=0x00;
	
  while(1)
  {
	trafficlight();	
  }

}


void delay(unsigned long int t)              // delay routine
{
	while(t>0)
	{
	unsigned long int i;
	for(i=1;i<10*1275;i++);
		t--;
	}

}


void trafficlight(void)         // traffic light system program

{
	
P2= 0x11;  // traffic signal control
P3= 0x04;
	
	
tl1r=1;    // signal 1
tl1o=0;	
tl1g=0;

tl2r=0;   // signal 2
tl2o=1;
tl2g=0;

tl3r=0;   // signal 3
tl3o=0;
tl3g=1;
	
	
delay(100);   // delay 

P2= 0x0c;    // traffic signal control
P3= 0x02;

	
tl1r=0;     // signal 1
tl1o=0;	
tl1g=1;
	
tl2r=1;    // signal 2
tl2o=0; 
tl2g=0;

tl3r=0;    // signal 3
tl3o=1;
tl3g=0;	


delay(100);  // delay

P2= 0x22;  // traffic signal control
P3= 0x01;

	 
tl1r=0;   // signal 1
tl1o=1;	
tl1g=0;

tl2r=0;   // signal 2
tl2o=0;
tl2g=1;

tl3r=1;   // signal 3
tl3o=0;
tl3g=0;	


delay(100);  // delay
	
}
