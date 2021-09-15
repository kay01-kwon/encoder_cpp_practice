#include <wiringPi.h>
#include <iostream>

#define pinA 0
#define pinB 2

using std::cout;
using std::endl;

void PinAinterruptDetected();
void PinBinterruptDetected();

int EncoderPosition = 0;

int main()
{
    wiringPiSetup();
    pinMode(pinA,INPUT);
    pinMode(pinB,INPUT);

    wiringPiISR(pinA,INT_EDGE_BOTH,PinAinterruptDetected);
    wiringPiISR(pinB,INT_EDGE_BOTH,PinBinterruptDetected);
    for(;;)
    {

    }

}

void PinAinterruptDetected()
{
    //cout<<"Pin A Edge Change Detected"<<endl;

    if (digitalRead(pinA) == HIGH)
    {
        if (digitalRead(pinB) == LOW)
            EncoderPosition++;
        else
            EncoderPosition--;
    }
    else
    {
        if(digitalRead(pinB) == HIGH)
            EncoderPosition++;
        else
            EncoderPosition--;
    }
    cout<<EncoderPosition<<endl;
}

void PinBinterruptDetected()
{
    //cout<<"Pin B Edge Change Detected"<<endl;
    if (digitalRead(pinB) == HIGH)
    {
        if (digitalRead(pinA) == HIGH)
            EncoderPosition++;
        else
            EncoderPosition--;
    }
    else
    {
        if(digitalRead(pinA) == LOW)
            EncoderPosition++;
        else
            EncoderPosition--;
    }
}