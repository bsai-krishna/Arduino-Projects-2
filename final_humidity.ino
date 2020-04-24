#include <LiquidCrystal.h>

#define sensor A0

bool LCDControl = 0, LowUmid = 0, HighUmid = 0;

byte UmidityPercent = 0, moisture = 0, PreviousValue = 0;
 
int ValUmidade = 0, AnalogValue = 0;

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(sensor, INPUT);

  PreviousValue = analogRead(sensor);
}
 
void loop()
{
  //Le o valor do pino A0 do sensor
  AnalogValue = analogRead(sensor);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Analog Port: ");
  Serial.println(AnalogValue);

  UmidityPercent = map(AnalogValue, 0, 1023, 0, 100);
  moisture = 100 - UmidityPercent;

  if( (moisture > (PreviousValue)+1) || (moisture < (PreviousValue)- 1))
  {
    lcd.setCursor(1,0);
    lcd.print("Moisture: ");
    lcd.print("      ");
    lcd.setCursor(11,0);
    lcd.print(moisture);
    lcd.print("%");
    
    if(moisture < 60 && LowUmid == 0)
    {
        lcd.setCursor(1,1);
        lcd.print("                ");
        lcd.setCursor(1,1);
        lcd.print("Low Moisture");
        LowUmid = 1;
        HighUmid = 0;
    }
    
    if(moisture >= 60 && HighUmid == 0)
    {
        lcd.setCursor(2,1);
        lcd.print("                ");
        lcd.setCursor(1,1);
        lcd.print("High Moisture");
        HighUmid = 1;
        LowUmid = 0;
    }  
    
    PreviousValue = moisture;
  }
  
}
