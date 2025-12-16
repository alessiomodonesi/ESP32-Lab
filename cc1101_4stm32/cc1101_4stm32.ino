/*
  RX DEMO PER STM32 E CC1101
  Usa il Monitor Seriale a 115200 baud
*/
#include <Arduino.h>
#include <ELECHOUSE_CC1101_SRC_DRV.h>

// I tuoi pin confermati funzionanti
#define SCK_PIN   D13
#define MISO_PIN  D12
#define MOSI_PIN  D11
#define CSN_PIN   D10
#define GDO0_PIN  D2

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("--- PRONTO A RICEVERE (433.92 MHz) ---");

  // Configurazione
  ELECHOUSE_cc1101.setSpiPin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN);
  ELECHOUSE_cc1101.setGDO(GDO0_PIN, GDO0_PIN);
  ELECHOUSE_cc1101.Init();
  
  // Impostazioni standard per cancelli (433.92 MHz)
  ELECHOUSE_cc1101.setMHZ(433.92); 
  ELECHOUSE_cc1101.SetRx(); // Mette il modulo in ascolto
}

void loop() {
  // Se il modulo riceve qualcosa...
  if (ELECHOUSE_cc1101.CheckRxFifo(100)) {
    
    // Leggi i dati
    if (ELECHOUSE_cc1101.CheckCRC()) {
      Serial.print("RICEVUTO! RSSI: ");
      Serial.print(ELECHOUSE_cc1101.getRssi());
      Serial.print(" LQI: ");
      Serial.println(ELECHOUSE_cc1101.getLqi());
      
      // Qui potresti stampare i dati raw per clonarli
      // (La libreria ha funzioni avanzate per decodificare, 
      // ma questo conferma che il telecomando viene "sentito")
    }
    ELECHOUSE_cc1101.SetRx(); // Rimettiti in ascolto
  }
}