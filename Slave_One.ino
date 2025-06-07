// Button on PB4
#define BUTTON_PIN PB4


uint8_t digits[] = {
  0x40,  // 0
  0x79,  // 1
  0x24,  // 2
  0x30,  // 3
  0x19,  // 4
  0x12,  // 5
  0x02,  // 6
  0x78,  // 7
  0x00,  // 8
  0x10   // 9
};

const int segPins[] = {PB8, PB9, PB10, PB11, PB12, PB13, PB14};

int pressCount = 0;
unsigned long lastPressTime = 0;
const unsigned long pressGap = 400;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], HIGH);  // All off
  }

  Serial2.begin(9600); // PA2 (TX to Master)
}

void displayDigit(uint8_t value) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], (value >> i) & 0x01);
  }
}

void clearDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], HIGH);
  }
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (millis() - lastPressTime > pressGap) {
      pressCount++;
      lastPressTime = millis();
    }
  }

  if (pressCount == 1 && millis() - lastPressTime > 500) {
    Serial2.write('1');              // Signal to Master
    displayDigit(digits[1]);         // Show "1"
    delay(1500);
    clearDisplay();
    pressCount = 0;
  }
  else if (pressCount == 2 && millis() - lastPressTime > 500) {
    Serial2.write('2');              // Signal to Master
    displayDigit(digits[2]);         // Show "2"
    delay(1500);
    clearDisplay();
    pressCount = 0;
  }
}
