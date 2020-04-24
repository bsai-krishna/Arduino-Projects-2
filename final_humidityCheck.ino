        
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

   
