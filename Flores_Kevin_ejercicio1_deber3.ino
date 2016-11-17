/*
 * Realizar un contador de 0-999, observado en displays
 * 
 * 
 * Nombre: Kevin Flores
 * Fecha: 14-11-2016 
 */
  int A=13;
  int B=12;
  int C=11;
  int D=10;
  int centenas=9;
  int decenas=8;
  int unidades=7;
  int contador=0;
  int valor_decena;
  int valor_unidad;
  int valor_centena;
void setup() {
  pinMode (A,OUTPUT);
  pinMode (B,OUTPUT);
  pinMode (C,OUTPUT);
  pinMode (D,OUTPUT);
  pinMode (unidades,OUTPUT);
  pinMode (decenas,OUTPUT);
  pinMode (centenas,OUTPUT);
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
   for(;contador<999;contador++){
      valor_centena=contador/100;
      valor_decena=(contador-(valor_centena*100))/10;
      valor_unidad=contador-(valor_centena*100)-(valor_decena*10);
      digitalWrite(unidades,HIGH);
      digitalWrite(decenas,LOW);
      digitalWrite(centenas,LOW);
      //imprimir dato
      contador_display(valor_unidad);
      delay(80);
      digitalWrite(unidades,LOW);
      digitalWrite(decenas,HIGH);
      digitalWrite(centenas,LOW);
      //imprimir dato
      contador_display(valor_decena);
      delay(80);
      digitalWrite(unidades,LOW);
      digitalWrite(decenas,LOW);
      digitalWrite(centenas,HIGH);
      //imprimir dato
      contador_display(valor_centena);
      delay(80);
    }
    contador=0;

}
