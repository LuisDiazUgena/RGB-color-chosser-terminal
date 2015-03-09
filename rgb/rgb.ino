
/*

Luis Diaz - diwo.bq.com
Proyecto switch + lectura terminal + analog Write RGB

Simple led ON/OFF & fade from Serial Monitor.
Use single digits pins (i.e: 1,2,{...},9);

*/

// Use pwm pins to drive LEDS (3,5,6,9)
int pinR = 6, pinG = 5, pinB = 3, pinButton = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);

  Serial.begin(9600);

  //test(); // Uncomment this to test the led. Serial.println("Bienvenido! Listo para ejecutar el programa.");
  Serial.println("Listo para recibir datos");
}

void loop() {
  if (Serial.available() > 0) {

    int incomming = Serial.read();

    //Debug
    //Serial.print("incomming");
    //Serial.println(incomming);

    manageChar(incomming);

  }
}

void test() {
  // fade_ALL (pin, delay_led) (pin number or variable,delay time in ms)
  fade_ALL(pinR, 20);
  fade_ALL(pinG, 20);
  fade_ALL(pinB, 20);

}
void fade_ALL(int pin, int delay_led) {
  // delay_led in ms

  for (int i = 0; i < 255; i++) {
    analogWrite(pin, i);
    delay(delay_led);
  }

  for (int i = 255; i > 0; i--) {
    analogWrite(pin, i);
    delay(delay_led);
  }

}

void manageChar(int data) {

  if (data == 82 || data == 114) {
    //R
    Serial.println("El caracter introducido es R o r");
    ledChosser(pinR);
    } else if (data == 71 || data == 103) {
    //G
    Serial.println("El caracter introducido es G o g");
    } else if (data == 66 || data == 98) {
    //B
    Serial.println("El caracter introducido es B o b");
    } else {
      Serial.println("Caracteres no validos. Los caracteres validos son:\n\tR o r.\n\tG o g.\n\tB o b. ");

    }
  }

  int waitForInput() {

    int fadeValue=0, acum=0;

    Serial.print("Introduce el valor del color (0-255)");

  //Esperamos mientras no entre ningún dato por el puerto serie
  while (Serial.available() == 0) {
    delay(500); // Esperamos durante 500 ms y volvemos a comprobar.
  }

  //Al llegar aquí sabemos que han entrado caracteres.

  //Almacena el número de caracteres que están entrando para
  //poder parsear el mensaje entrante en un número entero

  int buf_lenght = Serial.available();
  
  //Debug
  Serial.print("buf_lenght available = ");
  Serial.println(buf_lenght);

  while (Serial.available() > 0) {

    for ( int i = 0; i < buf_lenght; i++) {
      int aux;
      int incomming = Serial.read();

      if (buf_lenght == 1) { // Solo hay un caracter entrando por el puerto serie.
        return ascii2int(incomming);
      }

      if (buf_lenght == 2){ // Hay dos caracteres entrando por el puerto serie.

        if (i == 0 ){

          aux = ascii2int(incomming) * 10;
          acum += aux;

           //Debug
           /*
           Serial.print("i= ");
           Serial.print(i);
           Serial.print("\taux=");
           Serial.print(aux);
           Serial.print("\tacum=");
           Serial.println(acum);
           */
         }
         if (i == 1){
          aux = ascii2int(incomming);
          acum +=aux;

           //Debug
           /*
           Serial.print("i= ");
           Serial.print(i);
           Serial.print("\taux=");
           Serial.print(aux);
           Serial.print("\tacum=");
           Serial.println(acum);
           */
         } 
      }// fin buf_lenght = 2

      if (buf_lenght == 3 ){ // Hay dos caracteres entrando por el puerto serie.
        Serial.println("Dentro de buf_lenght = 3");
        if (i==0){
          aux = ascii2int(incomming) * 100;
          acum += aux;
            //Debug
            Serial.print("i= ");
            Serial.print(i);
            Serial.print("\taux=");
            Serial.print(aux);
            Serial.print("\tacum=");
            Serial.println(acum); 
          }
          if(i==1){
            aux = ascii2int(incomming) * 10;
            acum += aux;
            //Debug
            Serial.print("i= ");
            Serial.print(i);
            Serial.print("\taux=");
            Serial.print(aux);
            Serial.print("\tacum=");
            Serial.println(acum);
          }        
          if(i==2){
            aux = ascii2int (incomming);
            acum += aux;
            //Debug
            Serial.print("i= ");
            Serial.print(i);
            Serial.print("\taux=");
            Serial.print(aux);
            Serial.print("\tacum=");
            Serial.println(acum);            
          }
          

        }
      }


    /*
     for (int i=0;i<buf_lenght;i++){

      int incomming = Serial.read();

      if (buf_lenght==3){
        if (i==0){
        acum = ascii2int(incomming) * 100;
        }else if (i==1){
          acum = ascii2int(incomming) * 10;
        }else {
          acum = ascii2int(incomming);
        }
      }

      if (buf_lenght == 2){
        if (i==0){
          acum = ascii2int (incomming) * 10;
        }else{
          acum = ascii2int (incomming);
        }
      }

      if (buf_lenght == 1){
        acum = ascii2int (incomming);
      }
      fadeValue += acum;
    }
    */
  }

  return fadeValue;
  // when arrived here, Serial is empty and we have received something
  // that is what we wanted!
}
void ledChosser(int pin) {

  int fade = waitForInput();
  Serial.print("fade = ");
  Serial.println(fade);

}


int ascii2int(int data) {
  Serial.print("pre ascci char= ");
  Serial.println(data);
  switch (data) {
    case 48:
    return 0;
    case 49:
    return 1;
    case 50:
    return 2;
    case 51:
    return 3;
    case 52:
    return 4;
    case 53:
    return 5;
    case 54:
    return 6;
    case 55:
    return 7;
    case 56:
    return 8;
    case 57:
    return 9;

  }
}
