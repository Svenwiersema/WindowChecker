#include <LowPower.h>

#define CPINOUT 13
#define CPININ 12

void setup() {
  Serial.begin(9600);
  pinMode(CPINOUT, OUTPUT);
  pinMode(CPININ, INPUT);

  digitalWrite(CPINOUT, HIGH);
}

void loop() {
  int state = digitalRead(CPININ);
  if(state) {
    Serial.println("window closed");
  } else {
    Serial.println("window open");
  }

  delay(1000);

  Serial.println("Going to sleep");
  delay(1000);
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, SPI_OFF, USART0_OFF, TWI_OFF);
  Serial.println("Goodmorning");
  Serial.println("");
  delay(1000);
}
