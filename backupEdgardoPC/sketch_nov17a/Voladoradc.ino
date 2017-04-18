
#include <MotorShield.h>

boolean dir = true;
int speed=10;
int roundx=0;

MS_DCMotor motor_a(MOTOR_A);
MS_DCMotor motor_b(MOTOR_B);

void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.println("Comienzo");
  motor_b.setSpeed(30);
  motor_a.setSpeed(90);
  motor_a.run(BACKWARD|RELEASE);  
  motor_b.run(BACKWARD|RELEASE);  
  delay(5000);              //5
  motor_a.run(BRAKE);
  delay(10000);             //15
  for(int x=90; x>45; x--){
    if(x>90-5*5 && x<90-5) motor_b.run(BRAKE);
    else motor_b.run(FORWARD|RELEASE);
    motor_a.setSpeed(x);
    motor_a.run(BACKWARD|RELEASE);  
    delay(333);  
  }
  delay(5000);
  motor_a.run(BRAKE);
  delay(5000);             //30

  for(int x=45; x<135; x++){
    if(x>45+25 && x<135-25) motor_b.run(BRAKE);
    else motor_b.run(RELEASE);
    motor_a.setSpeed(x);
    motor_a.run(FORWARD|RELEASE);  
    delay(277);  
  }
  delay(5000);
  motor_a.run(BRAKE);  
  delay(5000);
  motor_a.setSpeed(90);
  motor_a.run(BACKWARD|RELEASE);  
  delay(15000);
  motor_b.run(BRAKE);  
  delay(10000);
  Serial.println("Fin");
} 


