#include "CytronMotorDriver.h"

void setup(){

CytronMD motorD(PWM_DIR, 9,8); //PWM = 9, DIR = 8 (PER DEFECTE)
CytronMD motorE(PWM_DIR, 11, 13);//PWM=11, DIR=13 (PER DEFECTE)

  pinMode(7, INPUT);
  Serial.begin(9600);

global unsigned long RetardObrirDreta = 0;
global unsigned long RetardObrirEsquerra = 0;
global unsigned long RetardTancarDreta = 0;
global unsigned long RetardEsquerra = 0;
global unsigned long MaximTempsObertEsquerra = 0;
global unsigned long MaximTempsObertDreta = 0;
global unsigned long RetardPararDreta = 0;
global unsigned long RetardPararEsquerra = 0;
global unsigned long ara = 0;
}

void obrir_dues(){
RetardObrirDreta = millis();
RetardObrirEsquerra = RetardObrirDreta + 4000;
RetardPararDret = RetardObrirDreta + 30000;
RetardPararEsquerra =  RetardPararDret + 4000;
MaximTempsObertEsquerra = RetardPararEsquerra + 99000;
MaximTempsObertDreta = maximTempsObertEsquerra + 17000;
//  motorD.setSpeed(255);
//  delay(4000);
//  motorE.setSpeed(255);
//  delay(16000);
//  motorD.setSpeed(0);
//  delay(10000);
//  motorE.setSpeed(0);
//  delay(99000);
//  motorE.setSpeed(-255);
//  delay(17000);
//  motorD.setSpeed(-255);
//  delay(100);
}

void tancar_dues(){
RetardTancarEsquerra = millis();
RetardObrirDreta = RetardTancarEsquerra;
RetardTancarDreta = RetardObrirdreta + 15000;
  //motorD.setSpeed(255);
  //delay(4000);
//  motorE.setSpeed(-255);
//  motorD.setSpeed(255);
//  delay(15000);
//  motorD.setSpeed(-255);
//  delay(100);
}

void obrir_dreta(){
RetardObrirDreta = millis();
//  motorD.setSpeed(255);
//  delay(300);
}

void tancar_dreta(){
RetardTancarDreta = millis();
//  motorD.setSpeed(-255);
//  delay(300);
}

void obrir_tancar_dreta(){
  RetardObrirDreta=milis();
  RetardTancarDreta = RetardObrirDreta + 40000;
//motorD.setSpeed(255);
//  delay(40000);
//  motorD.setSpeed(-255);
 // delay(100);
}

void parar(){
  motorD.setSpeed(0);
  motorE.setSpeed(0);
 RetardObrirDreta = 0;
 RetardObrirEsquerra = 0;
 RetardTancarDreta = 0;
 RetardEsquerra = 0;
 MaximTempsObertEsquerra = 0;
 MaximTempsObertDreta = 0;
 RetardPararDreta = 0;
 RetardPararEsquerra = 0;
//  delay(100);
}
void parar_esquerra(){
  motorE.setSpeed(0);
 RetardObrirEsquerra = 0;
 RetardEsquerra = 0;
 MaximTempsObertEsquerra = 0;
 RetardPararEsquerra = 0;
//  delay(100);
}

void loop() {

ara = millis();

if RetardObrirDreta != 0 && RetardObrirDreta < ara{
RetardObrirDreta = 0;
motorD.setSpeed(255);
}

if RetardObrirEsquerra != 0 && RetardObrirEsquerra < ara{
RetardObrirEsquerra = 0;
motorE.setspeed(255);
}

if RetardTancarDreta != 0 && RetardTancarDreta < ara{
RetardTancarDreta = 0;
motorD.setSpeed(-255);
}

if RetardEsquerra != 0 && RetardEsquerra < ara {
RetardEsquerra = 0;
motorE.setSpeed(255);
}

if MaximTempsObertEsquerra != 0 && MaximTempsObertEsquerra < ara{
MaximTempsObertEsquerra=0,
motorE.setSpeed(-255);
}

if MaximTempsObertDreta != 0 &&MaximTempsObertDreta < ara{
MaximTempsObertDreta = 0;
MotorD.setSpeed(-255);
}

if RetardPararDreta != 0 && RetardPararDreta < ara{
RetarPararDreta = 0;
MotorD.setSpeed(0);
}
if RetardPararEsquerra != 0  && RetardPararEsquerra < ara{
RetardPararEsquerra = 0;
MotorE.setSpeed(0);
}
  
estat = 99;

  if (Serial.available()>0){
    int estat = Serial.read();

    switch(estat){
      case '0':
      obrir_dues();
      break;
      case '1':
      parar();
      break;
      case '2':
      tancar_dues();
      break;
      case '3':
      obrir_dreta();
      break;
      case '4':
      tancar_dreta();
      break;
   }    
  }
  
//   Aquí abajo, al leer un interruptor  te haria falta un debouncer() ;

if (digitalRead(7) == HIGH){
    obrir_tancar_dreta();
//    delay(300);
  }
  

}8
