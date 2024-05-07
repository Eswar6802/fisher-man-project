#include <Wire.h>;
//#include <SimpleDHT.h>
#include <LiquidCrystal.h>
#include <TinyGPS++.h>                                                                                                                                                                                                         //library for gps module
#include <SoftwareSerial.h>               
#define button A2
int GPSBaud = 9600;
SoftwareSerial gps_serial(2,3);   //RX, TX
TinyGPSPlus gps;                     //create object for gps device
double Lat;       //variable for lattitude
double Lot;       //variable for longitude
double Alt;       //variable for altitude
unsigned long pmillis = 0; 
unsigned long plmillis = 0;
unsigned const bdelay = 100;
int count = 0;


int i=0;
int j=0;
int k=0;
void setup()   
{ 
gps_serial.begin(9600); //assign gps buadrate
Serial.begin(9600);  
pinMode(LED_BUILTIN, OUTPUT); 
  delay(1000);
}

void loop() 
{
  
Locationdata();
  
i=analogRead(A0);
  
if(analogRead(A0)>=1000)  
{
//String msg = "i am in trouble!: http://www.google.com/maps/place/" + String(Lat) + "," + String(Lot);
//
 Serial.print(Lat);
 Serial.print(",");
 Serial.println(Lot);
delay(2000);
}

delay(100);
   

}












void Locationdata(){
  while (gps_serial.available() > 0){                   //check if serial data  is available
    if (gps.encode(gps_serial.read())){                 //encode Serial data
      if(gps.location.isValid()){                       //if data is valid get location
        Lat = gps.location.lat();                       //update lattitude
        Lot = gps.location.lng();                       //update longiitude
        Alt = gps.altitude.meters();                    //update altitude
     // Serial.println(Lat);
      //Serial.println(Lot);
 digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500); 
      
      }
      else{                                             //if data is not available
       // Serial.println("Please connect gps");
       // lcd.begin(16, 2);
 // lcd.print("plz connect gps");

  delay(1000);
      }
    }
  }
}
