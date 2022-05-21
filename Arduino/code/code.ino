#include <ESP8266WiFi.h>

const char ssid = "REA-SW Gast";
const char password = "reagroningen";

const char url = "10.0.1.30/update.php";

const char windowID = "1";
const int pinIn = 12;

windowOpen = "0";

void setup() {
  Serial.begin(115200);
  pinMode(pinIn, INPUT);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("connecting to: ");
  Serial.print(ssid);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP Adress: ");
  Serial.print(WiFi.localIP());
}

void loop() {
  HTTPClient http;

  if(digitalRead(12) == HIGH) {
    windowOpen = 0;
  } else {
    windowOpen = 1;
  }
  String windowOpenStr = String(windowOpen);

  String postData = "window="+ windowID +"&open="+ windowOpenStr;

  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(postData);
  String payload = http.getString();

  Serial.println(httpCode);
  Serial.println(payload);

  http.end;

  delay(10000);
}
