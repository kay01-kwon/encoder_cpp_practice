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
```
mkdir build
```

```
cd build
```

```
cmake ..
```

```
make
```

```
sudo ./interrupt_test
```
You can read encoder position data.
