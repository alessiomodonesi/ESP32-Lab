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
    delay(3000); 
    Serial.println("=== TEST NUCLEO per URPIZY CC1101 ===");

    // 1. Configurazione Manuale SPI
    // Diciamo alla libreria esattamente quali pin usare
    ELECHOUSE_cc1101.setSpiPin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN);

    // 2. Configurazione Interrupt
    ELECHOUSE_cc1101.setGDO(GDO0_PIN, GDO0_PIN);

    // 3. Avvio
    ELECHOUSE_cc1101.Init();

    // 4. VERIFICA
    bool isConnected = ELECHOUSE_cc1101.getCC1101();

    if (isConnected) {
        Serial.println("✅ SUCCESSO TOTALE!");
        Serial.println("Il modulo CC1101 funziona. Il problema è l'M5Stick.");
        
        // Lettura info extra
        byte part = ELECHOUSE_cc1101.SpiReadStatus(0x30);
        byte ver = ELECHOUSE_cc1101.SpiReadStatus(0x31);
        Serial.print("Part: 0x"); Serial.println(part, HEX);
        Serial.print("Ver:  0x"); Serial.println(ver, HEX);
    } else {
        Serial.println("❌ FALLITO.");
        Serial.println("Controlla che i cavi Bianco e Giallo siano su D11 e D12.");
        Serial.println("Assicurati che l'interruttore sia su CC1101.");
    }
}

void loop() {
    // Led lampeggiante di vittoria (LD2 sulla Nucleo è di solito su D13 o PA5)
    // Nota: Su D13 abbiamo anche SCK, quindi il led lampeggerà velocissimo 
    // durante la comunicazione, che è normale.
}