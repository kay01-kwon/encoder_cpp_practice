cmake_minimum_required(VERSION 2.8.11)
project(encoder_practice)

find_library(WIRINGPI_LIBRARIES NAMES wiringPi)

# Executables for practice
add_executable(led_test src/led_test.cpp)
target_link_libraries(led_test ${WIRINGPI_LIBRARIES})

add_executable(digitalpin_read src/digitalpin_read.cpp)
target_link_libraries(digitalpin_read ${WIRINGPI_LIBRARIES})

add_executable(interrupt_test src/interrupt_test.cpp)
target_link_libraries(interrupt_test ${WIRINGPI_LIBRARIES})

add_executable(pwm_test src/pwm_test.cpp)
target_link_libraries(pwm_test ${WIRINGPI_LIBRARIES})

add_executable(encoder_practice src/encoder_practice.cpp)
target_link_libraries(encoder_practice ${WIRINGPI_LIBRARIES})
