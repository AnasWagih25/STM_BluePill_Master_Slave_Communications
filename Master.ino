#define LED_PIN PB2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial2.begin(9600); // RX from Slave 1 (PA3), TX to Slave 2 (PB10)
  Serial3.begin(9600); // TX: PB10, RX: PB11
}

void loop() {
  if (Serial2.available()) {
    char command = Serial2.read();
    if (command == '1') {
      digitalWrite(LED_PIN, HIGH);
      delay(500);
      digitalWrite(LED_PIN, LOW);
    }
    else if (command == '2') {
      Serial3.write('B');  // Send trigger to Slave 2
    }
  }
}
