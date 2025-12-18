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
  Serial.println("=== TEST POTENZA SEGNALE (RSSI) FIX ===");

  // 1. Configurazione Pin
  ELECHOUSE_cc1101.setSpiPin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN);
  ELECHOUSE_cc1101.setGDO(GDO0_PIN, GDO0_PIN);
  
  // 2. Inizializzazione (CORRETTA PER LA TUA LIBRERIA)
  ELECHOUSE_cc1101.Init(); // Senza 'if'

  // 3. Verifica se il modulo c'è
  if (ELECHOUSE_cc1101.getCC1101()) {
    Serial.println("✅ Modulo Rilevato! Inizio scansione segnale...");
  } else {
    Serial.println("❌ Errore Hardware.");
    while(1);
  }

  // IMPOSTAZIONI RADIO
  ELECHOUSE_cc1101.setMHZ(433.92);    // Frequenza
  ELECHOUSE_cc1101.setModulation(2);  // ASK/OOK (per cancelli)
  ELECHOUSE_cc1101.setRxBW(812.50);   // Banda larga
  
  ELECHOUSE_cc1101.SetRx(); // In ascolto
}

void loop() {
  // Leggiamo la potenza del segnale
  float rssi = ELECHOUSE_cc1101.getRssi();
  
  // Se il segnale è più forte del rumore di fondo (es. > -80dBm)
  // Nota: Più il numero è vicino a 0, più è forte (-50 è più forte di -90)
  if (rssi > -80) { 
    Serial.print("📡 SEGNALE RILEVATO! Potenza: ");
    Serial.print(rssi);
    Serial.println(" dBm");
  }
  
  delay(50); // Scansiona velocemente
  ELECHOUSE_cc1101.SetRx(); // Ricarica RX
}