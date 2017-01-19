/* Realizar juegos que se vizualicen en la LCD
 * 
 * Flores Kevin
 * 18/01/2017
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
int i = 0;
int j = 1;
int tamano;
String dato;
void setup() {
lcd.begin(16, 2);
Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    tamano=dato.length();
    char vector [tamano+1];
    dato.toCharArray(vector, tamano+1);
    
   for (; i < tamano; i++) {
    j = 1 - j;
    lcd.setCursor(i, j);
    lcd.print(vector[i]);
    delay(200);
  }
  j = 0;
  for (; i > 0; i--) {
    j = 1 - j;
    lcd.setCursor(i, j);
    lcd.print(' ');
    delay(200);
  }
  }
}
