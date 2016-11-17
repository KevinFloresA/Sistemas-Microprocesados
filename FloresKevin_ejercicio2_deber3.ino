/*
 * Realizar un contador mediante un pulsador de 0-99, se observa en displays.
 * Nombre: Kevin Flores
 * Fecha: 14-11-2016
 */
  int A=13;
  int B=12;
  int C=11;
  int D=10;
  int decenas=9;
  int unidades=8;
  int pulsador=7;
  int contador=0;
  int valor_decena;
  int valor_unidad;
void setup() {
  pinMode (A,OUTPUT);
  pinMode (B,OUTPUT);
  pinMode (C,OUTPUT);
  pinMode (D,OUTPUT);
  pinMode (unidades,OUTPUT);
  pinMode (decenas,OUTPUT);
  pinMode(pulsador,INPUT);
}
void contador_display(int numero){
  switch(numero){
   case 0: 
    //0
    digitalWrite (A,LOW);
    digitalWrite (B,LOW);
    digitalWrite (C,LOW);
    digitalWrite (D,LOW);
   break;
   case 1:
    //1
    digitalWrite (A,HIGH);
    digitalWrite (B,LOW);
    digitalWrite (C,LOW);
    digitalWrite (D,LOW);
   break;
   case 2: 
    //2
    digitalWrite (A,LOW);
    digitalWrite (B,HIGH);
    digitalWrite (C,LOW);
    digitalWrite (D,LOW);
   break;
   case 3: 
    //3
    digitalWrite (A,HIGH);
    digitalWrite (B,HIGH);
    digitalWrite (C,LOW);
    digitalWrite (D,LOW);
   break;
   case 4: 
    //4
    digitalWrite (A,LOW);
    digitalWrite (B,LOW);
    digitalWrite (C,HIGH);
    digitalWrite (D,LOW);
   break;
   case 5:
    //5
    digitalWrite (A,HIGH);
    digitalWrite (B,LOW);
    digitalWrite (C,HIGH);
    digitalWrite (D,LOW);
   break;
   case 6:
    //6
    digitalWrite (A,LOW);
    digitalWrite (B,HIGH);
    digitalWrite (C,HIGH);
    digitalWrite (D,LOW);
   break;
   case 7:
    //7
    digitalWrite (A,HIGH);
    digitalWrite (B,HIGH);
    digitalWrite (C,HIGH);
    digitalWrite (D,LOW);
   break;
   case 8: 
    //8
    digitalWrite (A,LOW);
    digitalWrite (B,LOW);
    digitalWrite (C,LOW);
    digitalWrite (D,HIGH);
   break;
   case 9: 
    //9
    digitalWrite (A,HIGH);
    digitalWrite (B,LOW);
    digitalWrite (C,LOW);
    digitalWrite (D,HIGH);
   break;  
  }
}
void loop() {
  
    for(;contador<99;contador++){
      
      if(digitalRead(pulsador)==HIGH){
      delay(200);
      valor_decena=contador/10;
      valor_unidad=contador-(valor_decena*10);
      digitalWrite(unidades,HIGH);
      digitalWrite(decenas,LOW);
      //imprimir dato
      contador_display(valor_unidad);
      delay(100);
      digitalWrite(unidades,LOW);
      digitalWrite(decenas,HIGH);
      //imprimir dato
      contador_display(valor_decena);
      delay(100);
      
      }delay(300);
   }contador=0;
}
