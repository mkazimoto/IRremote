#include <IRremote.h>

IRrecv irrecv1(4);
IRrecv irrecv2(5);

decode_results results1;
decode_results results2;

void setup() {
    Serial.begin(115200);
    irrecv1.enableIRIn();
    irrecv2.enableIRIn();
}

void loop() {

    if (irrecv1.decode(&results1)) {
        Serial.print("Receiver 1:");
        Serial.println(results1.value, HEX);
        irrecv1.resume(); 
    }    
    delay(100);

    if (irrecv2.decode(&results2)) {
        Serial.print("Receiver 2:");
        Serial.println(results2.value, HEX);
        irrecv2.resume(); 
    }    
    delay(100);
}
