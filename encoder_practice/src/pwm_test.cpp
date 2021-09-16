#include <wiringPi.h>
#include <iostream>

#define pin_pwmA 1

using std::cout;
using std::cin;
using std::endl;

int main()
{
    wiringPiSetup();
    pinMode(pin_pwmA,PWM_OUTPUT);

    int value;

//    while (1)
//    {
//        for(int i = 0; i < 1024; i++){
        cout<<"Input Value (Range 0 ~ 1024): "<<endl;
        cin>>value;
//        value = i;
        cout<<"\n";
        pwmWrite(pin_pwmA,value);
//        delay(1);
//        }
//    }

    return 0;

}