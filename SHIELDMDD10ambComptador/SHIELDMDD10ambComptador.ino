#include "CytronMotorDriver.h"


CytronMD motorD(PWM_DIR, 9,8); //PWM = 9, DIR = 8 (PER DEFECTE)
CytronMD motorE(PWM_DIR, 11, 13);//PWM=11, DIR=13 (PER DEFECTE)



void obrir_dues(){
  motorD.setSpeed(255);
  delay(4000);
  motorE.setSpeed(255);
  delay(10750);
  motorE.setSpeed(0);
  delay(100);
}

void tancar_dues(){
  //motorrD.setSpeed(255);
  //delay(4000);
  motorE.setSpeed(-255);
  delay(10750);
  motorD.setSpeed(-255);
  delay(100);
}

void obrir_dreta(){
  motorD.setSpeed(255);
  delay(300);
}

void tancar_dreta(){
  motorD.setSpeed(-255);
  delay(300);
}

void obrir_tancar_dreta(){
  motorD.setSpeed(255);
  delay(40000);
  motorD.setSpeed(-255);
  delay(100);
}

void parar(){
  motorD.setSpeed(0);
  motorE.setSpeed(0);
  delay(100);
}

void parar_esquerra(){
  motorE.setSpeed(0);
  delay(100);
}

int comptador = 0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (Serial.available()>0){
    int estat = Serial.read();

    switch(estat){
      break;
      case '1':
      parar();
      break;
      case '3':
      obrir_dreta();
      break;
      case '4':
      tancar_dreta();
      break;
   }    
  if (estat == '0' && comptador == 0){
     obrir_dues();
     comptador++;
     delay(300);
    }

  if (estat == '2'){
    tancar_dues();
    comptador = 0;
    delay(300);
  }
 }
  
  if (digitalRead(5) == HIGH){
    obrir_dreta();
    delay(300);
  }

  if (digitalRead(6) == HIGH){
    tancar_dreta();
    delay(300);
  }

  if (digitalRead(7) == HIGH){
    obrir_tancar_dreta();
    delay(300);
  }
  

}
