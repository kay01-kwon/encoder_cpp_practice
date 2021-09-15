# encoder_cpp_practice

Prerequisite: wiringPi.h

First of all, find out which wPi is pin Number.
```
sudo gpio readall
```
Then, you can get information on wPi (Pin number).

<img src="/picture/gpio_readall.png">

In the interrupt_test.cpp, you can read the rotary encoder value.

Add executables by following procedure.

Make build directory.
```
mkdir build
```

Navigate to build directory.
```
cd build
```

Cmake.
```
cmake ..
```

Compile and build to convert the cpp code into executables.
```
make
```

Execute the code.
```
sudo ./interrupt_test
```
You can read encoder position data.
