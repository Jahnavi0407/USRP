#include <SPI.h>
#include <LoRa.h>

int sequenceNumber = 0; 

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
  Serial.println("LoRa initialized with 250 kHz bandwidth, SF7, and CRC enabled.");
}

void loop() {
  sequenceNumber++; 
  String message = String(sequenceNumber) + ": THIS IS LORA PROJECT"; 
  Serial.println("Sending message: " + message);
  
  LoRa.beginPacket();  
  LoRa.print(message); 
  LoRa.endPacket();    
  
  delay(3000); 
}
