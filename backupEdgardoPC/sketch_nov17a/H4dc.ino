
#include <MotorShield.h>

boolean dir = true;
int speed=10;
int roundx=0;

MS_DCMotor motor_a(MOTOR_A);
MS_DCMotor motor_b(MOTOR_B);

void setup() {
  motor_a.setSpeed(600);  
  motor_b.setSpeed(500);  
}

void loop(){
        for(int i=2; i<200; i++){
          speed = i;
          motor_a.setSpeed(speed);
          motor_a.run(FORWARD|RELEASE);
          motor_b.setSpeed(500);
          motor_b.run(FORWARD|RELEASE);
        }
        for(int i=2; i<200; i++){
          motor_b.setSpeed(500);
          motor_b.run(FORWARD|RELEASE);
        }
        
        delay(5000);
        for(int i=2; i<200; i++){
          speed = i;
          motor_a.setSpeed(speed);
          motor_a.run(FORWARD|RELEASE);
          motor_b.setSpeed(500);
          motor_b.run(BACKWARD|RELEASE);
        }
        for(int i=2; i<200; i++){
          speed = i;
          motor_a.setSpeed(speed);
          motor_a.run(FORWARD|RELEASE);
        }
        delay(5000);
} 


