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
      Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}
