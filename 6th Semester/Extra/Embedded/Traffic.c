/*#include <reg51.h>
// First traffic light (P2.0 - P2.2)
sbit red1 = P2^0;
sbit yellow1 = P2^1;
sbit green1 = P2^2;
// Second traffic light (P2.3 - P2.5)
sbit red2 = P2^3;
sbit yellow2 = P2^4;
sbit green2 = P2^5;
// Third traffic light (P3.0 - P3.2)
sbit red3 = P3^0;
sbit yellow3 = P3^1;
sbit green3 = P3^2;
// Delay function
void Delay(int time)
{
    int i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 1000; j++)
        {
        }
    }
}
// Function to turn off all lights
void allOff()
{
    red1 = yellow1 = green1 = 0;
    red2 = yellow2 = green2 = 0;
    red3 = yellow3 = green3 = 0;
}
void main()
{
    while (1)
    {
        // First Traffic Light Green
        allOff();
        green1 = 1;
        red2 = 1;
        red3 = 1;
        Delay(200);
        // Yellow transition for First
        green1 = 0;
        yellow1 = 1;
        Delay(200);
        yellow1 = 0;
        // Second Traffic Light Green
        allOff();
        red1 = 1;
        green2 = 1;
        red3 = 1;
        Delay(200);
        // Yellow transition for Second
        green2 = 0;
        yellow2 = 1;
        Delay(200);
        yellow2 = 0;
        // Third Traffic Light Green
        allOff();
        red1 = 1;
        red2 = 1;
        green3 = 1;
        Delay(200);
        // Yellow transition for Third
        green3 = 0;
        yellow3 = 1;
        Delay(200);
        yellow3 = 0;
    }
}
*/

#include <reg51.h>

// First traffic light (P2.0 - P2.2)
sbit red1 = P2^0;
sbit yellow1 = P2^1;
sbit green1 = P2^2;

// Second traffic light (P2.3 - P2.5)
sbit red2 = P2^3;
sbit yellow2 = P2^4;
sbit green2 = P2^5;

// Third traffic light (P3.0 - P3.2)
sbit red3 = P3^0;
sbit yellow3 = P3^1;
sbit green3 = P3^2;

// Delay function
void Delay(int time)
{
    int i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 1000; j++)
        {
        }
    }
}

// Function to turn off all lights
void allOff()
{
    red1 = yellow1 = green1 = 0;
    red2 = yellow2 = green2 = 0;
    red3 = yellow3 = green3 = 0;
}

void main()
{
    while (1)
    {
        // Cycle 1: First road red, Second road yellow-green, Third road green-yellow
        allOff();
        red1 = 1;     // First road red
        green2 = 1;   // Second road green
        red3 = 1;     // Third road red
        Delay(200);
        
        allOff();
        yellow2 = 1;  // Second road yellow
        red1 = 1;      // First road red
        green3 = 1;    // Third road green
        Delay(200);
        
        allOff();
        red2 = 1;      // Second road red
        green1 = 1;    // First road green
        yellow3 = 1;   // Third road yellow
        Delay(200);
        
        // Cycle 2: Second road red, First road yellow-green, Third road green-yellow
        allOff();
        red2 = 1;     // Second road red
        green1 = 1;   // First road green
        red3 = 1;     // Third road red
        Delay(200);
        
        allOff();
        yellow1 = 1;  // First road yellow
        red2 = 1;     // Second road red
        green3 = 1;   // Third road green
        Delay(200);
        
        allOff();
        red1 = 1;     // First road red
        green2 = 1;   // Second road green
        yellow3 = 1;  // Third road yellow
        Delay(200);
        
        // Cycle 3: Third road red, First road yellow-green, Second road green-yellow
        allOff();
        red3 = 1;     // Third road red
        green1 = 1;   // First road green
        red2 = 1;     // Second road red
        Delay(200);
        
        allOff();
        yellow1 = 1;  // First road yellow
        red3 = 1;     // Third road red
        green2 = 1;   // Second road green
        Delay(200);
        
        allOff();
        red1 = 1;     // First road red
        yellow2 = 1;  // Second road yellow
        green3 = 1;   // Third road green
        Delay(200);
    }
}
