// ============================================================
// HW-484 VIBRATION SENSOR TEST - DO (Digital Output) Method
// ============================================================
// This code:
// 1. Reads vibration from HW-484 DO pin
// 2. Blue LED blinks when vibration is detected
// 3. Blue LED OFF when no vibration
// 4. Shows status on Serial Monitor
// ============================================================

#include <Arduino.h>

// ============================================================
// PIN DEFINITIONS
// ============================================================

#define LED_PIN         2    // Built-in LED (GPIO 2)
#define VIBRATION_DO    4    // HW-484 Digital Output (GPIO 4)

// ============================================================
// SETUP - Runs once when ESP32 powers on
// ============================================================

void setup() {
    // --- Initialize Serial Monitor ---
    Serial.begin(115200);
    delay(1000);
    
    // --- Initialize LED ---
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);  // Start with LED OFF
    
    // --- Initialize Vibration Sensor (DO pin) ---
    pinMode(VIBRATION_DO, INPUT);
    
    // --- Print startup message ---
    Serial.println("========================================");
    Serial.println("  HW-484 VIBRATION SENSOR TEST");
    Serial.println("  (Digital Output - DO Method)");
    Serial.println("========================================");
    Serial.println();
    Serial.println("📌 HOW IT WORKS:");
    Serial.println("  - Shake sensor  → Blue LED BLINKS");
    Serial.println("  - Sensor still  → Blue LED OFF");
    Serial.println();
    Serial.println("📌 Sensitivity Adjustment:");
    Serial.println("  - Turn screw counter-clockwise = MORE sensitive");
    Serial.println("  - Turn screw clockwise = LESS sensitive");
    Serial.println();
    Serial.println("Waiting for vibration...");
    Serial.println("========================================");
    Serial.println();
}

// ============================================================
// LOOP - Runs forever
// ============================================================

void loop() {
    // --- Read vibration from DO pin ---
    // HIGH (1) = Vibration detected
    // LOW (0)  = No vibration
    int vibrationState = digitalRead(VIBRATION_DO);
    
    // --- Check if vibration is detected ---
    if (vibrationState == HIGH) {
        // ✅ VIBRATION DETECTED!
        
        // Print to Serial Monitor
        Serial.println("💥💥💥 VIBRATION DETECTED! 💥💥💥");
        
        // Blink Blue LED rapidly (3 times)
        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
        digitalWrite(LED_PIN, HIGH);
        delay(100);
        digitalWrite(LED_PIN, LOW);
        delay(100);
        
    } else {
        // ❌ NO VIBRATION
        
        // Print to Serial Monitor (only once every 2 seconds to avoid spam)
        static unsigned long lastPrint = 0;
        if (millis() - lastPrint > 2000) {
            lastPrint = millis();
            Serial.println("⏳ No vibration... (Blue LED OFF)");
        }
        
        // Keep Blue LED OFF
        digitalWrite(LED_PIN, LOW);
        delay(100);
    }
}