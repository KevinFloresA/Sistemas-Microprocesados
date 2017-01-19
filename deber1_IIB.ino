/* Ingresar una palabra o palabras por comunicación serial, se genere una rotación o juego en la lcd.
 * 
 * Flores Kevin
 * 2017-01-12
 */
 
#include<LiquidCrystal.h>
LiquidCrystal lcd(9,8,7,6,5,4);//rs,e,d4,d5,d6,d7
String palabra;
int tam;
int estado;
volatile int state=LOW;

void int0(){
  estado=1-estado;
}

void setup() {
Serial.begin(9600);// abre el puerto serie,y le asigna la velocidad de 9600 bps
attachInterrupt(0, int0, LOW);
lcd.begin(16, 2);
}

void ingreso() {
  Serial.println("Ingresar palabra a visualizar en la LCD");
  espera();
  palabra=Serial.readString();
  tam=palabra.length();
  Serial.println("");
}
void condicion() {
  char respuest;
  Serial.println("Elejir juego (A, B o C): ");
  espera();
  respuest= Serial.read();
  if ((respuest == 'A') || (respuest == 'a')) {
    juego1();
  }
  else {
    if ((respuest == 'B') || (respuest == 'b')) {
      juego2();
    }
    else {
      if ((respuest == 'C') || (respuest == 'c')) {
        juego3();
      }
      else {
        Serial.println(" ");
        ingreso();
      }
    }
  }
}
void juego1() {
  int vel;
  for ( int a = 1; a < 30; a++) {
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 0);
    lcd.print(palabra);
    vel = 150 - (a * 5);
    delay(vel);//Tiempo de espera
    lcd.setCursor(0, 0);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print(palabra);
    vel = 150 - (a * 5);
    delay(vel);
  }

  lcd.clear();//Limpiamos la pantalla del LCD
}
void juego2() {
  lcd.setCursor(16, 0);
  lcd.print(palabra);
  int k = 0;
  for (; k < (17 + tam); k++) {
    lcd.setCursor(16, 0); 
    lcd.autoscroll();    
    lcd.print(" ");      
    delay(100);
  }
  lcd.noAutoscroll();
  lcd.clear();
}
void juego3() {
  int i = 0;
  int j = 0;
  char mensaje3[tam];
  palabra.toCharArray(mensaje3, tam + 1);
  for (; i < tam; i++) {
    j = 1 - j;
    lcd.setCursor(i, j);
    lcd.print(mensaje3[i]);
    delay(200);
    lcd.setCursor(i, j);
    lcd.print('*');
  }
  for (; i >= 0; i--) {
    j = 1 - j;
    lcd.setCursor(i, j);
    lcd.print(mensaje3[i]);
    delay(200);
    lcd.setCursor(i, j);
    lcd.print(" ");
  }
  lcd.clear();
}
void espera() {
  for (; Serial.available() == 0; ) {
  }
}


void loop() {
if (estado==1){
  if (Serial.available() > 0) {
      lcd.clear();
      ingreso();
      condicion();
      Serial.println("");
    }
}
else{
  lcd.clear();
  lcd.print("Sistema Apagado");
  Serial.println("Sistema Apagado");
  Serial.end();
}
}
