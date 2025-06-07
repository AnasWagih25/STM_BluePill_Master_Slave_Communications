#define SLAVE_LED PC13

void setup() {
  pinMode(SLAVE_LED, OUTPUT);
  digitalWrite(SLAVE_LED, HIGH);  // OFF (PC13 is active LOW)
  Serial3.begin(9600);  // RX from Master (PB11)
}

void loop() {
  if (Serial3.available()) {
    char c = Serial3.read();
    if (c == 'B') {
      digitalWrite(SLAVE_LED, LOW);  // ON
      delay(500);
      digitalWrite(SLAVE_LED, HIGH); // OFF
    }
  }
}
