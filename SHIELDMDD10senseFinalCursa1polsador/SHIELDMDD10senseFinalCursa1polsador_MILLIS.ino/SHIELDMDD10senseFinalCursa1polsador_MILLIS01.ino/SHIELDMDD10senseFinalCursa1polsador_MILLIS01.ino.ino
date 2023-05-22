#include <CytronMotorDriver.h>      // https://github.com/CytronTechnologies/CytronMotorDriver

CytronMD motorD(PWM_DIR, 9,8);      // PWM = 9, DIR = 8 (PER DEFECTE)
CytronMD motorE(PWM_DIR, 11, 13);   // PWM=11, DIR=13 (PER DEFECTE)

#include <Bounce2.h>                // https://github.com/thomasfredericks/Bounce2

Bounce debouncer = Bounce();

#define BUTTON_PIN  7
unsigned long RetardoAbrirDerecha       = 0;
unsigned long RetardoAbrirIzquierda     = 0;
unsigned long RetardoPararDerecha       = 0;
unsigned long RetardoPararIzquierda     = 0;
unsigned long RetardoIzquierda          = 0;
unsigned long MaximTempsAbrirIzquierda  = 0;
unsigned long MaximTempsAbrirDerecha    = 0;
unsigned long actual_millis             = 0;
byte estat;

void setup(){
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(50); // interval in ms
}

void abrir_dues(){
  RetardoAbrirDerecha       = millis();
  RetardoAbrirIzquierda     = RetardoAbrirDerecha + 4000;
  RetardoPararDerecha       = RetardoAbrirDerecha + 30000;
  RetardoPararIzquierda     = RetardoPararDerecha + 4000;
  MaximTempsAbrirIzquierda  = RetardoPararIzquierda + 99000;
  MaximTempsAbrirDerecha    = MaximTempsAbrirIzquierda + 17000;
}

void cerrar_dues(){
  RetardoPararIzquierda   = millis();
  RetardoAbrirDerecha     = RetardoPararIzquierda;
  RetardoPararDerecha     = RetardoAbrirDerecha + 15000;
}

void abrir_derecha(){
  RetardoAbrirDerecha     = millis();
}

void cerrar_derecha(){
  RetardoPararDerecha     = millis();
}

void abrir_cerrar_derecha(){
  RetardoAbrirDerecha     = millis();
  RetardoPararDerecha     = RetardoAbrirDerecha + 40000;
}

void parar(){
  motorD.setSpeed(0);
  motorE.setSpeed(0);
  RetardoAbrirDerecha       = 0;
  RetardoAbrirIzquierda     = 0;
  RetardoPararDerecha       = 0;
  RetardoIzquierda          = 0;
  MaximTempsAbrirIzquierda  = 0;
  MaximTempsAbrirDerecha    = 0;
  RetardoPararDerecha       = 0;
  RetardoPararIzquierda     = 0;

}
void parar_izquierda(){
  motorE.setSpeed(0);
  RetardoAbrirIzquierda     = 0;
  RetardoIzquierda          = 0;
  MaximTempsAbrirIzquierda  = 0;
  RetardoPararIzquierda     = 0;
}

void loop() {
  actual_millis = millis();

  if (RetardoAbrirDerecha != 0 && RetardoAbrirDerecha < actual_millis) {
      RetardoAbrirDerecha = 0;
      motorD.setSpeed(255);
  }

  if (RetardoAbrirIzquierda != 0 && RetardoAbrirIzquierda < actual_millis) {
    RetardoAbrirIzquierda = 0;
    motorE.setSpeed(255);
  }

  if (RetardoPararDerecha != 0 && RetardoPararDerecha < actual_millis) {
    RetardoPararDerecha = 0;
    motorD.setSpeed(-255);
  }

  if (RetardoIzquierda != 0 && RetardoIzquierda < actual_millis) {
    RetardoIzquierda = 0;
    motorE.setSpeed(255);
  }

  if (MaximTempsAbrirIzquierda != 0 && MaximTempsAbrirIzquierda < actual_millis) {
    MaximTempsAbrirIzquierda=0,
    motorE.setSpeed(-255);
  }

  if (MaximTempsAbrirDerecha != 0 &&MaximTempsAbrirDerecha < actual_millis) {
    MaximTempsAbrirDerecha = 0;
    motorD.setSpeed(-255);
  }

  if (RetardoPararDerecha != 0 && RetardoPararDerecha < actual_millis) {
    RetardoPararDerecha = 0;
    motorD.setSpeed(0);
  }
  if (RetardoPararIzquierda != 0  && RetardoPararIzquierda < actual_millis) {
    RetardoPararIzquierda = 0;
    motorE.setSpeed(0);
  }

  estat = 99;

  if (Serial.available()>0){
      int estat = Serial.read();

      switch(estat){
        case '0': abrir_dues();
                  break;
        case '1': parar();
                  break;
        case '2': cerrar_dues();
                  break;
        case '3': abrir_derecha();
                  break;
        case '4': cerrar_derecha();
                  break;
      }   
  }
  // Actualiza la instancia Bounce
  debouncer.update();

  // 50 mseg de antirebotes
  bool value = debouncer.read();

  if (value == HIGH){
      abrir_cerrar_derecha();
  }
}


================================
================================

"""Per 2 finals de cursa"""
Bounce debouncer2 = Bounce();
Bounce debouncer3 = Bounce();


#define FINAL_IZQUIERDA   8
#define FINAL_DERECHA     9

// en el setup
    pinMode(FINAL_IZQUIERDA, INPUT);
    pinMode(FINAL_DERECHA, INPUT);
    debouncer2.attach(FINAL_IZQUIERDA);
    debouncer2.interval(100); // interval in ms
    debouncer3.attach(FINAL_DERECHA);
    debouncer3.interval(100); // interval in ms

// en el loop 

 // Actualiza la instancia Bounce
  debouncer2.update();
  debouncer3.update();

  // 100 mseg de antirebotes
  bool value2 = debouncer2.read();          // FINAL CARRERA IZQUIERDA
  bool value3 = debouncer3.read();          // FINAL CARRERA DERECHA
