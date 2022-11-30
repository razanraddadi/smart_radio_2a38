#include <LiquidCrystal_I2C.h>
#include <Wire.h>


char data;
int Li=16;
int Lii=0;
int i=0;

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows


void setup() 
{
 
lcd.begin(16, 2);

Serial.begin(9600);//permet d’initialiser la liaison Série à 9600 bauds

  lcd.init(); // initialize the lcd
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("BIENVENUE");
  lcd.setCursor(1,1);
  lcd.print("CHEZ Beyond FM");
}

void loop() 
{
if(Serial.available())
  {
        
data = Serial.read();




if(data=='1')

  {

    ///lcd/// 
    
    lcd.clear();
    String msg="A L'HEURE";

    for(int i=0;i<16;i++)
    {
        data=Serial.read();
        
         lcd.setCursor(3,0);
         lcd.print(msg);
         lcd.setCursor(0,1);
         lcd.print(Scroll_LCD_Left("Employe cin:14514839")); 
         delay(350);
   
    }

  }

else if(data=='2')

{     
        lcd.clear();
    String msg="En RETARD";

    for(int i=0;i<16;i++)
    {
        data=Serial.read();
       
         lcd.setCursor(3,0);
         lcd.print(msg);
         lcd.setCursor(0,1);
         lcd.print(Scroll_LCD_Left("Employe cin:14514839")); 
         delay(350);
  
}
 
}
  }
}
String Scroll_LCD_Left(String StrDisplay){
  String result;
  String StrProcess="  " + StrDisplay + "   ";
  result=StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if(Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
    }

  void Clear_Scroll_LCD_Left(){
    Li=16;
    Lii=0;
  }
