# M5StickC Plus2 Lab & Pentesting 📡

Repository dedicata agli esperimenti con ESP32 basati su **M5StickC Plus2**.
L'obiettivo è esplorare firmware personalizzati (Bruce, Marauder) e sviluppare codice custom per automazione e radio frequenza.

## 🛠 Hardware
* **Core:** M5StickC Plus2 (ESP32-PICO-V3-02, Schermo LCD, Microfono, IMU, Batteria).
* **Radio Hat:** Modulo esterno con CC1101 (Sub-GHz) e NRF24L01 (2.4GHz).
* **Attuatori:** Modulo Relè Grove (con transistor/diodo integrati).
* **Connessioni:** Cavo Grove-to-Pin (per breadboard).

## 💾 Firmware & Software
1.  **Stock / UIFlow 2.0:** Firmware originale per test sensori e logica a blocchi/MicroPython.
2.  **Bruce:** Firmware "Multi-tool" per analisi RF, BLE, WiFi (supporta CC1101/NRF24).
3.  **M5Burner:** Tool ufficiale per flashare i firmware.
4.  **VS Code + PlatformIO / Arduino IDE:** Per lo sviluppo di codice custom (C++).

## ⚡ Pinout Importante (M5StickC Plus2)
* **Grove Port (Rosso):** G32 (SDA/IO), G33 (SCL/IO). *Usato per il Relè.*
* **LED Interno:** G19 (Attivo Basso).
* **Button A (M5):** G37.
* **Button B (Lato):** G39.
* **Button C (Power):** G35.
* **IR Transmitter:** G9.

## ⚠️ Disclaimer
Gli esperimenti con moduli radio (CC1101/NRF24) e firmware di pentesting devono essere eseguiti **SOLO** su dispositivi di propria proprietà o con esplicita autorizzazione.

## 💾 Firmware & Software Ecosystem

Per sfruttare al massimo l'hardware, utilizzeremo diversi ambienti:

### 1. Firmware "Swiss Army Knife" (Pentesting & Radio)
* **[Bruce](https://github.com/pr3y/Bruce):** Il firmware principale per questo lab. Supporta nativamente l'Hat con **CC1101** (Sub-GHz) e **NRF24L01**. Permette di analizzare telecomandi, segnali RF e reti.
* **[Nemo](https://github.com/n0xa/m5stick-nemo):** Un'alternativa a Bruce con interfaccia unica. Include tool divertenti come TV-B-Gone (spegnimento TV IR) e spam di pacchetti BLE.
* **[ESP32 Marauder](https://github.com/justcallmekoko/ESP32Marauder):** Il gold standard per l'analisi di sicurezza **WiFi** e **Bluetooth**. Ottimo per scansioni di rete, deauth detection e packet sniffing (PCAP).

### 2. Sviluppo & Prototipazione
* **M5Burner:** Il tool ufficiale (Windows/Mac/Linux) per flashare facilmente Bruce, Nemo, Marauder e i firmware stock senza compilare nulla.
* **UIFlow 2.0 / Stock:** Firmware originale basato su MicroPython/Blocchi. Utile per test rapidi dell'hardware (IMU, Mic, LCD).
* **PlatformIO (VS Code) / Arduino IDE:** Per scrivere codice C++ personalizzato, specialmente per la gestione dei moduli Grove (Relè) e integrazione con breadboard.

---

## 🗺️ Roadmap degli Esperimenti

### 🟢 Fase 1: Setup e "Hello World"
- [x] **1.1 Setup Ambiente:** Installazione driver USB (CH9102), M5Burner e VS Code.
- [x] **1.2 Hardware Check:** Flash del firmware "UserDemo" o "Factory Test" per verificare che schermo, microfono, giroscopio e tasti funzionino correttamente.

### 🔴 Fase 2: Into the Matrix (Radio Hacking con Bruce)
*Obiettivo: Prendere confidenza con il modulo Radio Hat esterno.*
- [ ] **2.1 Installazione Bruce:** Flashare l'ultima versione di Bruce tramite M5Burner.
- [ ] **2.2 Sub-GHz Sniffing (433 MHz):** Usare il modulo CC1101 per intercettare e visualizzare il segnale di un telecomando cancello o auto (proprio!).
- [ ] **2.3 Analisi Spettro:** Visualizzare il grafico a cascata (RSSI) per vedere le frequenze radio attive intorno a te.
- [ ] **2.4 Mousejacking (Teoria):** Testare il modulo NRF24L01 per scansionare periferiche wireless 2.4GHz vulnerabili.

### 🔵 Fase 3: Network & Wireless (WiFi/BLE)
- [ ] **3.1 Bluetooth Spam:** Generare pacchetti BLE di prova (es. "Apple TV", "Samsung Pair") per testare la ricezione sugli smartphone.
- [ ] **3.2 WiFi Scanner:** Mappare le reti circostanti, visualizzando canali, crittografia e client connessi.
- [ ] **3.3 Wardriving:** (Opzionale) Salvare i dati delle reti su SD Card (se disponibile) o memoria interna.

### 🟠 Fase 4: Physical Computing (Grove & Breadboard)
*Obiettivo: Unire la logica ESP32 con l'elettronica discreta su breadboard.*
- [ ] **4.1 Controllo Relè (Grove):** Collegare il modulo Relè alla porta Grove e scrivere un codice C++ per attivarlo alla pressione del tasto M5.
- [ ] **4.2 Hybrid Breadboarding:** Usare il cavo **Grove-to-Pin**.
    - Portare 3V3 e GND alla breadboard.
    - Collegare un LED esterno o un sensore sulla breadboard.
    - Controllare il componente esterno tramite i GPIO del connettore Grove.
- [ ] **4.3 Web Control:** Creare una mini pagina web ospitata sull'ESP32 per accendere/spegnere il Relè da smartphone via WiFi.
