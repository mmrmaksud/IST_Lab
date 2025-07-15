#include <reg51.h>
// Traffic Light 1 (P2.0 - P2.2)
sbit tl1r = P2^0;  // Red
sbit tl1o = P2^1;  // Orange
sbit tl1g = P2^2;  // Green
// Traffic Light 2 (P2.3 - P2.5)
sbit tl2r = P2^3;  // Red
sbit tl2o = P2^4;  // Orange
sbit tl2g = P2^5;  // Green
// Traffic Light 3 (P3.0 - P3.2)
sbit tl3r = P3^0;  // Red
sbit tl3o = P3^1;  // Orange
sbit tl3g = P3^2;  // Green
void delay(unsigned int t) {
    unsigned int i, j;
    for(i = 0; i < t; i++)
        for(j = 0; j < 1275; j++);
}
// Phase 1: TL1 - RED, TL2 - ORANGE, TL3 - GREEN
void signal_phase1() {
    tl1r = 1; tl1o = 0; tl1g = 0;
    tl2r = 0; tl2o = 1; tl2g = 0;
    tl3r = 0; tl3o = 0; tl3g = 1;
    delay(200);
}
// Phase 2: TL1 - GREEN, TL2 - RED, TL3 - ORANGE
void signal_phase2() {
    tl1r = 0; tl1o = 0; tl1g = 1;
    tl2r = 1; tl2o = 0; tl2g = 0;
    tl3r = 0; tl3o = 1; tl3g = 0;
    delay(200);
}
// Phase 3: TL1 - ORANGE, TL2 - GREEN, TL3 - RED
void signal_phase3() {
    tl1r = 0; tl1o = 1; tl1g = 0;
    tl2r = 0; tl2o = 0; tl2g = 1;
    tl3r = 1; tl3o = 0; tl3g = 0;
    delay(200);
}
// Traffic light control sequence
void trafficlight() {
    signal_phase1();
    signal_phase2();
    signal_phase3();
}
void main() {
    P1 = 0x00;
    P2 = 0x00;
    P3 = 0x00;
    while(1) {
        trafficlight();
    }
}
