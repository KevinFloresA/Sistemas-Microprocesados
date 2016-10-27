/* Realizar 2 juegos con 6 leds utilizando ciclos for anidados
 * Juego 1: Para este juego se utilizo ciclos for anidados y funcionará cuando el switch1=1 y switch2=0; los leds se encienden y apaguen en pares 
 * con un led apagado en medio de ellos,este juego se repetira las veces que el número randomico determine.
 * 
 * Juego 2: El juego funcionar[a cunado el switch1=0 y switch2=1; las luces se encienden una por una desde los extremos hacia el centro, luego 
 * vuelven hacia los extremos, este juego se repetira las veces que el número randomico determine. Para este juego se utilizo ciclos for anidados.
 * 
 * Flores Kevin
 * 2016-10-26
 */
 // Inicializamos variables de los pines
int led1=8;// mas sencillo cambiar la variable y no todo el codigo
int led2=9;
int led3=10;
int led4=11;
int led5=12;
int led6=13;
int sw1=7;
int sw2=6;
int vector_leds[6]={led1,led2,led3,led4,led5,led6};
////////////////
//variables de contadores
int i=0;
int j=0;
int k=0;
////////////////
void setup() {
  pinMode(led1,OUTPUT);//pin 13 como salida
  pinMode(led2,OUTPUT);//pin 12 como salida
  pinMode(led3,OUTPUT);//pin 11 como salida
  pinMode(led4,OUTPUT);//pin 10 como salida
  pinMode(led5,OUTPUT);//pin 9 como salida
  pinMode(led6,OUTPUT); //pin 8 como salida
  pinMode(sw1,INPUT);//pin 7 como entrada
  pinMode(sw2,INPUT);//pin 6 como entrada
}

void juego1(){
    k=random(1,5);
     for(;k<=5;k++){//for1, este ciclo permite que el segundo ciclo se repite las veces que determine el numero randomico
      for(i=0,j=2;i<4;i++,j++){//for2, este ciclo utiliza dos contadores y permite que los leds se enciendan y apaguen en pares con un led apagado en medio de ellos.
        digitalWrite(vector_leds[i],HIGH),digitalWrite(vector_leds[j],HIGH);
        delay(100);
        digitalWrite(vector_leds[i],LOW),digitalWrite(vector_leds[j],LOW);
        delay(100);
       }//for2
     }//for1
   }
void juego2(){
  k=random(1,5);
     for(;k<=5;k++){//for1, este ciclo permite que el segundo ciclo se repite las veces que determine el numero randomico 
      for(i=0,j=5;i<3;i++,j--){//para este ciclo utilizamos dos contadores ya que los leds se encenderan al mismo tiempo, empezando desde los extremos
        digitalWrite(vector_leds[i],HIGH),digitalWrite(vector_leds[j],HIGH);
        delay(100);}
      for(i=2,j=3;i>=0;i--,j++){//este ciclo cumple la funcion de apagar los leds en secuencia contraria al encendido, igualmente usamos dos contadores
        digitalWrite(vector_leds[i],LOW),digitalWrite(vector_leds[j],LOW);
        delay(100);}
     }//for1
  }

void loop() {
  if(digitalRead (sw1)==HIGH&&digitalRead(sw2)==LOW){
    juego1();//llamamos al metodo del juego 1
  }
  if(digitalRead (sw1)==LOW&&digitalRead(sw2)==HIGH){
    juego2();//llamamos al metodo del juego 2
   }
}
