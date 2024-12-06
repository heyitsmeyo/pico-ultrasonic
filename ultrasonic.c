
#include <stdio.h>
#include "pico/stdlib.h" 
#include "stdio_usb.h"


const int trigPin = 0;
const int echoPin = 15;
float duration, distance;


uint32_t measure_pulse_duration(uint gpio, bool state) {
    // Wait for the pin to go to the desired state
    while (gpio_get(gpio) != state);

    // Record the start time
    absolute_time_t start_time = get_absolute_time();

    // Wait for the pin to leave the desired state
    while (gpio_get(gpio) == state);

    // Record the end time
    absolute_time_t end_time = get_absolute_time();

    // Calculate the duration in microseconds
    return absolute_time_diff_us(start_time, end_time);
}

int main() {
	
stdio_init_all();

gpio_init(trigPin) ; 
gpio_init(echoPin) ; 
gpio_set_dir(trigPin , GPIO_OUT) ; 
gpio_set_dir(echoPin , GPIO_IN) ; 
while(true) { 
gpio_put(trigPin , 0) ; 
 sleep_us(2) ; 
gpio_put(trigPin , 1) ; 
sleep_us(10) ; 
gpio_put(trigPin , 0) ; 

  uint32_t duration = measure_pulse_duration(echoPin, true);
  distance = (duration*.0343)/2;
  sleep_ms(100);
  
 printf("Distance: %.2f cm\n", distance);
} 
} 
