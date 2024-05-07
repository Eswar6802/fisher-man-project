#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
const char *ssid = "SMART-G";  
const char *password = "10112019"; 
const char *host = "https://myprojectfinal.in";   


void setup() {
  delay(1000);
  Serial.begin(9600);
  WiFi.mode(WIFI_OFF);        
  delay(1000);
  WiFi.mode(WIFI_STA);  
  WiFi.begin(ssid, password);     
  Serial.println(""); 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print("*");
  } 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
  delay(1000);
 
  
}
void loop() 
{

 while(Serial.available())
{
HTTPClient http;  
String postData;  
String key = Serial.readString();
Serial.print(key);
postData = "g="+String(key);  
http.begin("http://patient.fantasysolution.in/fishh.php?");            
http.addHeader("Content-Type", "application/x-www-form-urlencoded");
int httpCode = http.POST(postData);   
String payload = http.getString();
Serial.println(payload); 
http.end();    
delay(1000); 
}
}
