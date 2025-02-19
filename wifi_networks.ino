#include <WiFi.h>
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Setup done..!");  
}

void loop()
{
  Serial.println("Scan Start");
  int ENC_TYPE_NONE;
  int n = WiFi.scanNetworks();
  Serial.println("Scan done");
  if (n == 0)
  {
    Serial.println("No networks found");
  }
  else 
  {
    Serial.print(n);
    Serial.println("Network found");
    for(int i = 0; i < n; ++i)
    {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print("( ");
      Serial.print(WiFi.RSSI(1));
      Serial.print(") ");
      Serial.println((WiFi.encryptionType(i)==ENC_TYPE_NONE)? " ":"*");
      delay(10);    }
  }
  Serial.println("");
  delay(5000);
}