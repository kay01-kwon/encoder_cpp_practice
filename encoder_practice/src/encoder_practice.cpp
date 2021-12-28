#include <iostream>
#include <wiringPi.h>

#define pinA 0  //Physical 11
#define pinB 2  //Physical 13

#define pinC 15 //Physical 8
#define pinD 16 //Physical 10

using std::cout;
using std::endl;

int encoderPosition = 0;

void check_edge();
void encoder_function();


int LastA, LastB;
int CurrA, CurrB;

int main()
{
    wiringPiSetup();
    pinMode(pinA,INPUT);
    pinMode(pinB,INPUT);

    CurrA = digitalRead(pinA);
    CurrB = digitalRead(pinB);

    LastA = CurrA;
    LastB = CurrB;

    for(;;){

        CurrA = digitalRead(pinA);
        CurrB = digitalRead(pinB);

        if(LastA != CurrA && LastB == CurrB){
            if(LastA == LOW && CurrA == HIGH){
                if(CurrB == LOW)
                    encoderPosition++;
                else
                    encoderPosition--;
            }
            else
                if(CurrB == HIGH)
                    encoderPosition++;
                else
                    encoderPosition--;
        }

        if(LastA == CurrA && LastB != CurrB){
            if(LastB == LOW && CurrB == HIGH){
                if(CurrA == HIGH)
                    encoderPosition++;
                else
                    encoderPosition--;
            }
            else
                if(CurrA == LOW)
                    encoderPosition++;
                else
                    encoderPosition--;
        }

        LastA = CurrA;
        LastB = CurrB;

        std::cout<<encoderPosition<<std::endl;
    }

}