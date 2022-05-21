#include <Keyboard.h>

void setup() {
  pinMode(13, INPUT);
  Serial.begin(9600);
}

void loop() {

  Keyboard.begin();
  if(digitalRead(13) == 0) {
    Keyboard.write('A');
    delay(200);
  }
  Keyboard.end()
}
