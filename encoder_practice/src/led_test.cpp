#include <iostream>
#include <wiringPi.h>

using std::cout;

int main()
{
    wiringPiSetup () ;
    pinMode (0, OUTPUT) ;
  for (;;)
  {
    digitalWrite (0, HIGH) ; delay (500) ;
    digitalWrite (0,  LOW) ; delay (500) ;
  }
  return 0 ;
  digitalWrite8(0, LOW);
}