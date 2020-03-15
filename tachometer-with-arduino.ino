//EE_wave
//RPM_meter

#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
float value=0;
float rev=0;
int rpm;
int oldtime=0;
int time;

void isr()                      //interrupt service routine, only in pin number 2 or pin number 3
{
rev++;
}

void setup()
{
lcd.begin(16,2);                //initialize LCD
attachInterrupt(0,isr,RISING);  //attaching the interrupt
}

void loop()
{
delay(1000);
detachInterrupt(0);         
time=millis()-oldtime;        //finding total time for one rev 
rpm=(rev/time)*60000;         //calculating the rpm
oldtime=millis();             
rev=0;
lcd.clear();                  
lcd.setCursor(0,0);
lcd.print("  RPM TESTER  ");    //printing on LCD
lcd.setCursor(0,1);             //sets the position where to print
lcd.print(     rpm);
lcd.print(" RPM");
lcd.print("   ");                //final result
attachInterrupt(0,isr,RISING);

} 
