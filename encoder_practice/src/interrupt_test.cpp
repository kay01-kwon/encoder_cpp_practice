#include <wiringPi.h>
#include <iostream>

#define pinA 0  //Physical 11
#define pinB 2  //Physical 13

using std::cout;
using std::endl;

void PinAinterruptDetected();
void PinBinterruptDetected();

void PinA_risingEdgeDetected();
void PinA_fallingEdgeDetected();
void PinB_risingEdgeDetected();
void PinB_fallingEdgeDetected();


int EncoderPosition = 0;

int main()
{
    wiringPiSetup();
    pinMode(pinA,INPUT);
    pinMode(pinB,INPUT);


    wiringPiISR(pinA,INT_EDGE_BOTH,PinAinterruptDetected);
    wiringPiISR(pinB,INT_EDGE_BOTH,PinBinterruptDetected);
    //wiringPiISR(pinA,INT_EDGE_RISING,PinA_risingEdgeDetected);
    //wiringPiISR(pinA,INT_EDGE_FALLING,PinA_fallingEdgeDetected);
    //wiringPiISR(pinB,INT_EDGE_RISING,PinB_risingEdgeDetected);
    //wiringPiISR(pinB,INT_EDGE_FALLING,PinB_fallingEdgeDetected);
    

    for(;;)
    {
        std::cout<<EncoderPosition<<std::endl;
        //delayMicroseconds(5);
    }

}

void PinA_risingEdgeDetected()
{
    if(digitalRead(pinB) == LOW)
        EncoderPosition++;
    else
        EncoderPosition--;
}

void PinA_fallingEdgeDetected()
{
    if(digitalRead(pinB) == HIGH)
        EncoderPosition++;
    else
        EncoderPosition--;
}

void PinB_risingEdgeDetected()
{
    if(digitalRead(pinA) == HIGH)
        EncoderPosition++;
    else
        EncoderPosition--;
}

void PinB_fallingEdgeDetected()
{
    if(digitalRead(pinA) == LOW)
        EncoderPosition++;
    else
        EncoderPosition--;
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