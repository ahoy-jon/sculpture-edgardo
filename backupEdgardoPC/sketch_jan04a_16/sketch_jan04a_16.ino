



// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
AF_Stepper motorM3(48, 2);      // to motor port #2 (M3 and M4)

void setup(){ 
}

void loop(){
      motorM3.setSpeed(5);      // aqui el 5 = 10 rpm 
      motorM3.step(400, BACKWARD, INTERLEAVE);  // 400 
      segundos(10);         // tiempo de espera 10 segundos

      motorM3.setSpeed(5);      // aqui el 5 = 10 rpm 
      motorM3.step(600, FORWARD, INTERLEAVE);  // 600 
      segundos(15);         // tiempo de espera 15 segundos
} 

void segundos(int seg){
  for(int x=0; x < seg; x++) delay(1000); 
}
