
#include <IRremote.h>

int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
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
          break;
       case 0x17112D07:
       Serial.println("right");
          break;
       default:
          Serial.println(results.value, HEX);
          break;
    }
    irrecv.resume(); // Receive the next value
  }
}
