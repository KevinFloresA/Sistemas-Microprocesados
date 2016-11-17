/*
 * Realizar la medición de velocidad (0-99) de un motor mediante la lectura de un converso análogo digital, recordar que deben realizar la 
 * conversión de 0-1023 a 0-99 para tener todas las referencias de voltaje.
 * 
 * Nombre: Kevin Flores
 * Fecha: 14-11-2016
 */
  int A=13;
  int B=12;
  int C=11;
  int D=10;
  int decenas=7;
  int unidades=8;
  int motor=9;
  int valor_decena;
  int valor_unidad;
  int valor_cad;
  
void setup() {
  pinMode (A,OUTPUT);
  pinMode (B,OUTPUT);
  pinMode (C,OUTPUT);
  pinMode (D,OUTPUT);
  pinMode (unidades,OUTPUT);
  pinMode (decenas,OUTPUT);
  pinMode (motor,OUTPUT);

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
  valor_cad=analogRead(0); //leer de 0-1023
  analogWrite(motor,valor_cad/4);  //% de ciclo util de la señal
  delay(100);
      valor_cad=map(valor_cad,0,1023,0,99);
      valor_decena=valor_cad/10;
      valor_unidad=valor_cad-(valor_decena*10);
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
      
}

