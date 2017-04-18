// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>



int _step = 0; 
int ce_que_on_fait=0;
int counter = 0;
int automate=0;
boolean dir = true;// gre
int speed=10;
int roundx=0;
// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(48, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor.setSpeed(60);  // 10 rpm   
}

void loop() {
  Serial.println("Single coil steps");
  //motor.step(100, FORWARD, SINGLE); 
  //motor.step(100, BACKWARD, SINGLE); 
  if(roundx == 0)
{   
speed=30;  
motor.setSpeed(speed);
switch(dir)
{ 
    case 0:
    { 
    motor.step(200, FORWARD, SINGLE);
    dir=1;
    
    }break;
    case 1:
    { 
    motor.step(200, BACKWARD, SINGLE);
    dir=0;
    roundx=1;
     dir=0;
    }break;
    default:
    { 
    dir=0;
    }break;
};
//speed=speed+20;
//vitesse maximum=180
//vitesse minimum=0
//if(speed > 180) speed=speed-20;
//if(speed < 0) speed=0;


  
}
else
{ 
 
speed=150;  
motor.setSpeed(speed);
switch(dir)
{ 
    case 0:
    { 
    motor.step(200, FORWARD, SINGLE);
    dir=1;
    
    }break;
    case 1:
    { 
    motor.step(200, BACKWARD, SINGLE);
    dir=0;
    roundx=0;
     dir=0;
    }break;
    default:
    { 
    dir=0;
    }break;
}; 

}



}

