#include <LiquidCrystal.h>   //arduino lcd library

LiquidCrystal lcd(8,9,4,5,6,7);   //defining lcd pins

int value=0;            //initializing variables
float volts=0.0;      
float temp=0.0;      
float tempF=0.0;

void setup()
{
  pinMode(3,INPUT);      //setting arduino pin3 as input
  Serial.begin(9600);   // opens serial port, sets data rate to 9600 bps
  lcd.begin(16,2);      // set up the LCD's number of columns and rows
 
  
}

void loop()
{
  value=analogRead(A0);          //read from A0
  volts=(value/1024.0)*5.0;      //conversion to volts
  temp= volts*100.0;             //conversion to temp Celsius
  tempF=temp*9/5+32;             //conversion to temp Fahrenheit

//display temp no lcd

  Serial.print("temperature= "); 
  lcd.println(temp);
  lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  Serial.println(tempF);
  lcd.print(" F");
  
  
  delay(500);
}
