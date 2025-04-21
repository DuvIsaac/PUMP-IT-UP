#include <Keyboard.h>
// char keys[20] = "**zqsec"; // 1P
char keys[20] = "**tyuio"; // 2P

int key_pushed[20] = {0};

void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  for (int pin = 2; pin <= 6; pin++) {
    pinMode(pin, INPUT);
  } 
}

int val;

void loop() {
  for (int pin = 2; pin <= 6; pin++) {
    val = digitalRead(pin);
    Serial.println(val);
    if (val == HIGH) {
      Keyboard.press(keys[pin]);
      key_pushed[pin] = 1;
    }
    else if (val == LOW) {
      if (key_pushed[pin] == 1) {
        Keyboard.release(keys[pin]);
        key_pushed[pin] = 0;
      }
    }
  }
}
