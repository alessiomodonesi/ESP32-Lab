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
  
  ELECHOUSE_cc1101.setSpiPin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN);
  ELECHOUSE_cc1101.setGDO(GDO0_PIN, GDO0_PIN);
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.setMHZ(433.92);
  ELECHOUSE_cc1101.setModulation(2);
  ELECHOUSE_cc1101.SetRx();
}

void loop() {
  float rssi = ELECHOUSE_cc1101.getRssi();

  // 1. STABILIZZATORE VERTICALE (Limiti finti)
  Serial.print("-100"); // Limite basso
  Serial.print(" ");
  Serial.print("10");   // Limite alto
  Serial.print(" ");
  
  // 2. DATO VERO
  Serial.println(rssi); 
  
  // 3. RALLENTATORE ORIZZONTALE
  // Prima era 20ms. Ora mettiamo 100ms o 200ms.
  // Più aumenti questo numero, più il grafico va lento.
  delay(150); 
  
  ELECHOUSE_cc1101.SetRx();
}