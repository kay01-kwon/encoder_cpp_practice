#include <iostream>
#include <wiringPi.h>

#define pinA 0  // GPIO 11
#define pinB 2  // GPIO 13

int main()
{
    wiringPiSetup();
    pinMode(pinA,INPUT);
    for(;;){
        int A_signal = digitalRead(pinA);
        int B_singal = digitalRead(pinB);
        std::cout<<"A signal : "<<A_signal<<"\t B signal : "<<B_singal<<std::endl;
    }

}