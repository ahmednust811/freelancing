#include "Wire.h"
#define GPIO_LED LED_BUILTIN
#define time_fast 100
#define time_slow 1000 //
#define i2c_slave_addr 0x44 // i2c slave address 
bool high_func_flag = 0;
bool blink_slow_flag = 0;
bool blink_fast_flag = 0;
bool low_func_flag = 0;

void recieve_handler(int n){
  Serial.println("recieved");
  char x;
  while(Wire.available()){
    x = Wire.read();
    Serial.println(x);
    }
    switch(x){
      
      case 'a':
       digitalWrite(GPIO_LED,HIGH);
  
        high_func_flag = 1;
        blink_slow_flag = 0;
        blink_fast_flag = 0;
        low_func_flag = 0;
        break;
      case 'b':
     
        high_func_flag = 0;
        blink_slow_flag = 1;
        blink_fast_flag = 0;
        low_func_flag = 0;
       
        break;
      case 'c':
        
        high_func_flag = 0;
        blink_slow_flag = 0;
        blink_fast_flag = 1;
        low_func_flag = 0;
      
        break;
      case 'd':
      digitalWrite(GPIO_LED,LOW);
        high_func_flag = 0;
        blink_slow_flag = 0;
        blink_fast_flag = 0;
        low_func_flag = 1;
        break;
      default:
        high_func_flag = 0;
        blink_slow_flag = 0;
        blink_fast_flag = 0;
        low_func_flag = 0;
      }
  }

void setup() {
  // put your setup code here, to run once:
Wire.begin(i2c_slave_addr);

delay(10);
Wire.onReceive(recieve_handler);

Serial.begin(9600);
pinMode(GPIO_LED,OUTPUT);
delay(10);
}

void loop() {
  if(blink_fast_flag){
    blinky_fast();
    }
    if(blink_slow_flag){
    blinky_slow();
    }
    delay(10);
}


void blinky_slow(){
  Serial.println("blink slow called");
   while( blink_slow_flag){
    digitalWrite(GPIO_LED,!(digitalRead(GPIO_LED)));
    delay(time_slow);
    }
  }

 void blinky_fast(){
  Serial.println("blink fast called");
  while(blink_fast_flag){
    digitalWrite(GPIO_LED,!(digitalRead(GPIO_LED)));
    delay(time_fast);
    
    }
  
  }
