#include <reg51.h>
// Traffic Light 1 (P2.0 - P2.2)
sbit RED_1    = P2^0;
sbit YELLOW_1 = P2^1;
sbit GREEN_1  = P2^2;
// Traffic Light 2 (P2.3 - P2.5)
sbit RED_2    = P2^3;
sbit YELLOW_2 = P2^4;
sbit GREEN_2  = P2^5;
// Traffic Light 3 (P3.0 - P3.2)
sbit RED_3    = P3^0;
sbit YELLOW_3 = P3^1;
sbit GREEN_3  = P3^2;
void delay(unsigned int t) {
    unsigned int i, j;
    for(i = 0; i < t; i++)
        for(j = 0; j < 1275; j++);
}
// Phase 1: 1 - RED, 2 - YELLOW, 3 - GREEN
void signal_phase1() {
    RED_1 = 1; YELLOW_1 = 0; GREEN_1 = 0;
    RED_2 = 0; YELLOW_2 = 1; GREEN_2 = 0;
    RED_3 = 0; YELLOW_3 = 0; GREEN_3 = 1;
    delay(200);
}
// Phase 2: 1 - GREEN, 2 - RED, 3 - YELLOW
void signal_phase2() {
    RED_1 = 0; YELLOW_1 = 0; GREEN_1 = 1;
    RED_2 = 1; YELLOW_2 = 0; GREEN_2 = 0;
    RED_3 = 0; YELLOW_3 = 1; GREEN_3 = 0;
    delay(200);
}
// Phase 3: 1 - YELLOW, 2 - GREEN, 3 - RED
void signal_phase3() {
    RED_1 = 0; YELLOW_1 = 1; GREEN_1 = 0;
    RED_2 = 0; YELLOW_2 = 0; GREEN_2 = 1;
    RED_3 = 1; YELLOW_3 = 0; GREEN_3 = 0;
    delay(200);
}
// Sequence control
void traffic_light_sequence() {
    signal_phase1();
    signal_phase2();
    signal_phase3();
}
void main() {
    P1 = 0x00;
    P2 = 0x00;
    P3 = 0x00;
    while(1) {
        traffic_light_sequence();
    }
}
