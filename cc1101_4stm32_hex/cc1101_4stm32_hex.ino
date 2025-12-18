#include <Arduino.h>
#include <ELECHOUSE_CC1101_SRC_DRV.h>

// PIN DEFINITIONS (Nucleo F446RE)
#define SCK_PIN   D13 // G0
#define MISO_PIN  D12 // yellow groove
#define MOSI_PIN  D11 // white groove
#define CSN_PIN   D10 // G26
#define GDO0_PIN  D2 // G36
// collegare anche 3V3 e GND

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("=== DECODIFICA SEGNALE 433MHz ===");

  ELECHOUSE_cc1101.setSpiPin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN);
  ELECHOUSE_cc1101.setGDO(GDO0_PIN, GDO0_PIN);
  ELECHOUSE_cc1101.Init();
  
  ELECHOUSE_cc1101.setMHZ(433.92);
  ELECHOUSE_cc1101.setModulation(2); // ASK/OOK
  ELECHOUSE_cc1101.SetRx();
  
  Serial.println("Premi il telecomando per vedere il codice HEX...");
}

void loop() {
  // Se riceve dati validi
  if (ELECHOUSE_cc1101.CheckRxFifo(100)) {
    
    // Verifica CRC (Rimuove il rumore)
    if (ELECHOUSE_cc1101.CheckCRC()) {
      Serial.print("RICEVUTO! [RSSI: ");
      Serial.print(ELECHOUSE_cc1101.getRssi());
      Serial.print("] Dati: ");
      
      // Legge il buffer
      byte buffer[100];
      int len = ELECHOUSE_cc1101.ReceiveData(buffer);
      
      // Stampa in esadecimale
      for (int i = 0; i < len; i++) {
        Serial.print(buffer[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
    }
    ELECHOUSE_cc1101.SetRx(); // Torna in ascolto
  }
}