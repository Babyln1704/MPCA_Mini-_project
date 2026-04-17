#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define UV_RELAY_PIN    8   
#define LIMIT_SWITCH    3  
#define IR_SENSOR       2  
#define DHTPIN          5   
#define DHTTYPE         DHT11

// --- MATCHING YOUR SERIAL MONITOR VALUES ---
bool LID_CLOSED_STATE = HIGH;   
bool RELAY_ON_STATE = LOW;      
bool PHONE_DETECTED_STATE = LOW; 

LiquidCrystal_I2C lcd(0x27, 16, 2); 
DHT dht(DHTPIN, DHTTYPE);

int timerCount = 30;
unsigned long prevMillis = 0;
bool isFinished = false;

void setup() {
  Serial.begin(9600);
  pinMode(UV_RELAY_PIN, OUTPUT);
  // Initial state: Force relay pin HIGH (which is OFF for active-low)
  digitalWrite(UV_RELAY_PIN, HIGH); 

  pinMode(LIMIT_SWITCH, INPUT_PULLUP); 
  pinMode(IR_SENSOR, INPUT);
  
  lcd.init();
  lcd.backlight();
  dht.begin();
  Serial.println("Logic Synchronized...");
}

void loop() {
  int rawSwitch = digitalRead(LIMIT_SWITCH);
  int rawIR = digitalRead(IR_SENSOR);
  
  bool isClosed = (rawSwitch == LID_CLOSED_STATE);
  bool isPresent = (rawIR == PHONE_DETECTED_STATE);
  float temp = dht.readTemperature();

  // SERIAL DEBUGGING
  Serial.print("Lid: "); Serial.print(rawSwitch);
  Serial.print(" | IR: "); Serial.print(rawIR);
  Serial.print(" | Status: ");

  if (!isClosed) {
    digitalWrite(UV_RELAY_PIN, HIGH); // Ensure Relay is OFF
    timerCount = 30;
    isFinished = false;
    updateLCD("LID OPEN!", "UV: PROTECT OFF");
    Serial.println("DOOR IS OPEN");
  } 
  else if (!isPresent) {
    digitalWrite(UV_RELAY_PIN, HIGH); // Ensure Relay is OFF
    timerCount = 30;
    isFinished = false;
    updateLCD("WAITING...", "INSERT PHONE");
    Serial.println("PHONE MISSING");
  } 
  else if (!isFinished) {
    digitalWrite(UV_RELAY_PIN, LOW); // TRIGGER RELAY (Tick sound should happen here!)
    Serial.println("STERILIZING ON");
    
    if (millis() - prevMillis >= 1000) {
      timerCount--;
      prevMillis = millis();
    }
    
    lcd.setCursor(0, 0);
    lcd.print("STERILIZING...  ");
    lcd.setCursor(0, 1);
    lcd.print("TIME: "); lcd.print(timerCount); 
    lcd.print("s  T:"); lcd.print((int)temp); lcd.print("C");

    if (timerCount <= 0) {
      digitalWrite(UV_RELAY_PIN, HIGH); // TURN OFF
      isFinished = true;
    }
  }
  else {
    digitalWrite(UV_RELAY_PIN, HIGH); // ENSURE OFF
    updateLCD("STERILIZE DONE!", "REMOVE PHONE");
    Serial.println("FINISHED");
  }
  delay(100);
}

void updateLCD(String l1, String l2) {
  lcd.setCursor(0, 0);
  lcd.print(l1 + "                ");
  lcd.setCursor(0, 1);
  lcd.print(l2 + "                ");
}