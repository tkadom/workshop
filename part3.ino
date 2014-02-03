
#include <IRremote.h>
#include <AFMotor.h>
#include <Servo.h> 
#include <stdarg.h>

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo1;
int pos = 90;


void setup()
{
  servo1.attach(10);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  int val = 0;
  
  if (irrecv.decode(&results)) {
    switch(results.value)
    {
      case 0xCA31DA45:
          Serial.println("left");
          pos = 30;
          servo1.write(pos);
          
          delay(10);
          break;
       case 0x17112D07:
          Serial.println("right");
          pos = 150;
          servo1.write(pos);
          delay(10);
          break;
    }
    irrecv.resume(); // Receive the next value
  }
}
