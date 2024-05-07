#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h>
#include <EEPROM.h>

const int mo= A0;
 
void writeString(char add,String data);
String read_String(char add);
 
void setup() 
{
Serial.begin(9600);

pinMode(A0, OUTPUT);

lcd.init();
lcd.backlight();
lcd.clear();
lcd.setCursor(0,0);
lcd.print("FISHERMAN LOCATION ");
lcd.setCursor(0, 1);
lcd.print("TRACKING SYSTEM");
delay(1000);
}

void loop() 
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("FISHERHMAN LOCATION ");
lcd.setCursor(0, 1);
lcd.print("TRACKING SYSTEM");
delay(1000);

while(Serial.available())
{
String key = Serial.readString();
Serial.println(key);
writeString(11, key);  
delay(10);
String recivedData;
recivedData = read_String(11);


lcd.clear();
lcd.setCursor(0,0);
lcd.print(key);
//lcd.print(recivedData[1]);
//lcd.print(recivedData[2]);
//lcd.print(recivedData[3]);
//lcd.print(recivedData[4]);
//lcd.print(recivedData[5]);
//lcd.print(recivedData[6]);
//lcd.print(recivedData[7]);
//lcd.print(recivedData[8]);
//lcd.print(recivedData[9]);
//lcd.print(recivedData[10]);
//lcd.print(recivedData[11]);
//lcd.print(recivedData[12]);
//lcd.print(recivedData[13]);
//lcd.print(recivedData[14]);
//lcd.print(recivedData[15]);
//lcd.print(recivedData[16]);

digitalWrite(A0, HIGH); 


delay(5000);  
digitalWrite(A0, LOW); 
lcd.setCursor(0, 1);
lcd.print("THANK YOU........");
delay(2000); 
  
  
}
}

void writeString(char add,String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size+1;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add+_size,'\0');   //Add termination null character for String Data
}
 
 
String read_String(char add)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(add);
  while(k != '\0' && len<=10)   //Read until null character
  {    
    k=EEPROM.read(add+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}
