#include<SPI.h>
#include<RF24.h>
RF24 radio(9, 10);
const byte address[6] = "00001";
float ans = 0;
void setup()
{
    Serial.begin(19200);
    radio.begin();
    radio.setChannel(115);
    radio.setPALevel(RF24_PA_MAX);
    radio.setDataRate(RF24_250KBPS);
    radio.openWritingPipe(address);
    radio.stopListening();
}

void loop()
{
    ans = random(1, 10);
    Serial.println(ans); //Random number generator
    radio.write(&ans, sizeof(ans));
    delay(1000);
}
