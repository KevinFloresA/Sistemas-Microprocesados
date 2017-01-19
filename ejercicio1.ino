#include <Keypad.h>
#include <LiquidCrystal.h>
#include <TimerOne.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int numero;
char letra;
int posicion;
int contp=0;
int cont=0;
int cont1=0;
int cont2=0;
int cont3=0;
int cont4=0;
int cont5=0;
int cont6=0;
int cont7=0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
lcd.begin(16, 2);
Timer1.initialize(150000);
Timer1.attachInterrupt(espera);
}
void loop() {
 char customKey = customKeypad.getKey();
  
  if (customKey){
    if (customKey == '2') {
      cont++;
      letra= tecla(cont);
         lcd.setCursor(posicion,0);
         lcd.print(letra);
        if(cont==3){
          cont = 0; 
        }
        contp=0;
      }
    if (customKey == '3') {
      cont1++;
      letra= tecla1(cont1);
         lcd.setCursor(posicion,0);
         lcd.print(letra);
        if(cont1==3){
          cont1 = 0; 
        }
        contp = 0;
      }
    if (customKey == '4') {
      cont2++;
      letra= tecla2(cont2);
         lcd.setCursor(posicion,0);
         lcd.print(letra);
        if(cont2==3){
          cont2 = 0; 
        }
        contp = 0;
      }
    if (customKey == '5') {
      cont3++;
      letra= tecla3(cont3);
         lcd.setCursor(posicion,0);
         lcd.print(letra);
        if(cont3==3){
          cont3 = 0; 
        }
        contp = 0;
      }
    if (customKey == '6') {
      cont4++;
      letra= tecla4(cont4);
         lcd.setCursor(posicion,0);
         lcd.print(letra);
        if(cont4==3){
          cont4 = 0; 
        }
        contp = 0;
      }
    if (customKey == '7') {
      cont5++;
      letra= tecla5(cont5);
         lcd.setCursor(posicion,0);
         lcd.print(letra);
        if(cont5==4){
          cont5 = 0; 
        }
        contp = 0;
      }
    if (customKey == '8') {
      cont6++;
      letra= tecla6(cont6);
         lcd.setCursor(posicion,0);
         lcd.print(letra);
        if(cont6==3){
          cont6 = 0; 
        }
        contp = 0;
      }
    if (customKey == '9') {
      cont7++;
      letra= tecla7(cont7);
         lcd.setCursor(posicion,0);
         lcd.print(letra);
        if(cont7==4){
          cont7 = 0; 
        }
        contp = 0;
      }    
    }
  }
char tecla (int pulsos){
  char letra;
  switch (pulsos) {
    case 1:
      letra= 'a';
      break;
    case 2:
      letra= 'b';
      break;
    case 3:
      letra='c';
      break;
  }
  return letra;
}
char tecla1 (int pulsos){
  char letra;
  switch (pulsos) {
    case 1:
      letra= 'd';
      break;
    case 2:
      letra= 'e';
      break;
    case 3:
      letra='f';
      break;
  }
  return letra;
}
char tecla2 (int pulsos){
  char letra;
  switch (pulsos) {
    case 1:
      letra= 'g';
      break;
    case 2:
      letra= 'h';
      break;
    case 3:
      letra='i';
      break;
  }
  return letra;
}
char tecla3 (int pulsos){
  char letra;
  switch (pulsos) {
    case 1:
      letra= 'j';
      break;
    case 2:
      letra= 'k';
      break;
    case 3:
      letra='l';
      break;
  }
  return letra;
}
char tecla4 (int pulsos){
  char letra;
  switch (pulsos) {
    case 1:
      letra= 'm';
      break;
    case 2:
      letra= 'n';
      break;
    case 3:
      letra='o';
      break;
  }
  return letra;
}
char tecla5 (int pulsos){
  char letra;
  switch (pulsos) {
    case 1:
      letra= 'p';
      break;
    case 2:
      letra= 'q';
      break;
    case 3:
      letra='r';
      break;
    case 4:
      letra='s';
      break;
  }
  return letra;
}
char tecla6 (int pulsos){
  char letra;
  switch (pulsos) {
    case 1:
      letra= 't';
      break;
    case 2:
      letra= 'u';
      break;
    case 3:
      letra='v';
      break;
  }
  return letra;
}
char tecla7 (int pulsos){
  char letra;
  switch (pulsos) {
    case 1:
      letra= 'w';
      break;
    case 2:
      letra= 'x';
      break;
    case 3:
      letra='y';
      break;
    case 4:
      letra='z';
      break;
  }
  return letra;
}
void espera() {
  contp++;
  if (contp == 6) {
    posicion++;
    cont= 0;
    cont1= 0;
    cont2=0;
    cont3=0;
    cont4=0;
    cont5=0;
    cont6=0;
    cont7=0;
  }
}

