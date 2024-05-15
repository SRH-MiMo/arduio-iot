#include <ESP8266WiFi.h>

// 와이파이명
const char* ssid = "MINJAERO";
const char* password = "Rlaalswo123!";



void setup() {
  Serial.begin(115200);
  delay(10);



  // 와이파이 스캔
  int n = WiFi.scanNetworks();
  Serial.println("Scan Done");
  if(n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println("networks found");

    for(int i = 0; i<n; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }



  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    Serial.print(n);
    Serial.println(WiFi.status());
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("connection Start");
}


void loop() {


}