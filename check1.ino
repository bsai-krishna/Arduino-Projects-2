#include <LiquidCrystal.h>
  
#define sensor A0
  
bool LCDControl = 0, LowUmid = 0, HighUmid = 0;
byte UmidityPercent = 0, moisture = 0, PreviousValue = 0;
int ValUmidade = 0, AnalogValue = 0;
  
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

