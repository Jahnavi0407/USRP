#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!LoRa.begin(868E6)) {
    Serial.println("LoRa initialization failed. Check your wiring.");
    while (1);
  }

  LoRa.setSignalBandwidth(250E3);
  LoRa.setSpreadingFactor(7);
  LoRa.setPreambleLength(12);
  LoRa.enableCrc();

  Serial.println("LoRa Receiver initialized with 250 kHz bandwidth, SF7, and CRC enabled.");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  
  if (packetSize) {
    Serial.print("Received packet: ");
    
    while (LoRa.available()) {
      char receivedChar = (char)LoRa.read();
      Serial.print(receivedChar);
    }

    Serial.print(" | RSSI: ");
    Serial.print(LoRa.packetRssi());
    Serial.print(" | SNR: ");
    Serial.println(LoRa.packetSnr());
  }
}