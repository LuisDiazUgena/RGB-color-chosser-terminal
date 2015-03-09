
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
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(pinB,OUTPUT);
  
  Serial.begin(9600);
  
  // fade (pin, delay_led) (pin number or variable,delay time in ms)
  fade(pinR,20);
  fade(pinG,20);
  fade(pinB,20);
      
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    
  }
}

void fade(int pin,int delay_led){
  // delay_led in ms
  
  for (int i=0;i<255;i++){
    analogWrite(pin,i);
    delay(delay_led);
  }
  
  for (int i = 255;i>0;i--){
    analogWrite(pin,i);
    delay(delay_led);
  }
  
}

int ascii2chr(int data) {
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
