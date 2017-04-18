


#include <SoftwareSerial.h>







class MyLight
{
  public:
    MyLight(SoftwareSerial* ss);
    void exec(char program);
    void e();
    void b();
    void c();
    void s();
    void write(char cmd);
    
  private:
    SoftwareSerial* _ss;
    char prev;
};


MyLight::MyLight(SoftwareSerial* ss) {
  ss->begin(9200);
  _ss = ss;
}

void MyLight::exec(char cmd) {
  this->write(cmd);
}

void MyLight::e() {
  this->write('e');
}

void MyLight::b() {
  this->write('b');
}

void MyLight::c() {
  this->write('c');
}

void MyLight::s() {
  this->write('s');
}

void MyLight::write(char cmd) {
  if(cmd != prev) {
    prev = cmd;
    _ss->write(cmd);
  }
  
}




class MyStepper
{
  public:
    MyStepper(int pin0, int pin1, int pin2, int pin3);
    void nextStep();
    void nextStep2();
    void changeDirection();
   private:
     int _pin0;
     int _pin1;
     int _pin2;
     int _pin3;
     boolean _dir = false;
     int _step = 0;
};


MyStepper::MyStepper(int pin0, int pin1, int pin2, int pin3)
{
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  _pin0 = pin0;
  _pin1 = pin1;
  _pin2 = pin2;
  _pin3 = pin3;
}

void MyStepper::changeDirection() {
  _dir = !_dir;
}


void MyStepper::nextStep() {
   switch(_step){ //switch veut dire basculer vers : un switch permet d'avoir plusieurs codes à executer et n'en executer un seul à chaque fois qu'on passe par ici selon la valeur de la variable qui s'appelle _step, si la valeur de _step est different de toutes les valeurs qu'on a prevu en dessous alors on execute le code qui suit l'eatpe qui s'appelle "default:"
  case 0: 
    digitalWrite(_pin0, LOW);  
    digitalWrite(_pin1, LOW); 
    digitalWrite(_pin2, LOW); 
    digitalWrite(_pin3, HIGH); 
    break;  
  case 1: 
    digitalWrite(_pin0, LOW);  
    digitalWrite(_pin1, LOW); 
    digitalWrite(_pin2, HIGH); 
    digitalWrite(_pin3, HIGH); 
    break;  
  case 2: 
    digitalWrite(_pin0, LOW);  
    digitalWrite(_pin1, LOW); 
    digitalWrite(_pin2, HIGH); 
    digitalWrite(_pin3, LOW); 
    break;  
  case 3: 
    digitalWrite(_pin0, LOW);  
    digitalWrite(_pin1, HIGH); 
    digitalWrite(_pin2, HIGH); 
    digitalWrite(_pin3, LOW); 
    break;  
  case 4: 
    digitalWrite(_pin0, LOW);  
    digitalWrite(_pin1, HIGH); 
    digitalWrite(_pin2, LOW); 
    digitalWrite(_pin3, LOW); 
    break;  
  case 5: 
    digitalWrite(_pin0, HIGH);  
    digitalWrite(_pin1, HIGH); 
    digitalWrite(_pin2, LOW); 
    digitalWrite(_pin3, LOW); 
    break;  
  case 6: 
    digitalWrite(_pin0, HIGH);  
    digitalWrite(_pin1, LOW); 
    digitalWrite(_pin2, LOW); 
    digitalWrite(_pin3, LOW); 
    break;  
  case 7: 
    digitalWrite(_pin0, HIGH);  
    digitalWrite(_pin1, LOW); 
    digitalWrite(_pin2, LOW); 
    digitalWrite(_pin3, HIGH); 
    break;  
  default: 
    digitalWrite(_pin0, LOW);  
    digitalWrite(_pin1, LOW); 
    digitalWrite(_pin2, LOW); 
    digitalWrite(_pin3, LOW); 
    break;  
  } 
  
  
 
  if(_dir){ 
    _step++; 
  }
  else{ 
    _step--; 
  } 
  
  if(_step>7){ 
    _step=0; 
  } 
  if(_step<0){ 
    _step=7; 
  } 
}


SoftwareSerial mySerial1(3, 9); // RX, TX
SoftwareSerial mySerial2(3, 8); //RX, TX

MyStepper stepper1(10,11,12,13);
MyStepper stepper2(7,6,5,4);

MyLight light1(&mySerial1);
MyLight light2(&mySerial2);



int ce_que_on_fait=0;
int counter = 0;
int automate=0;



void off() {
  //mySerial.write('s');
}


void red(int discard) {
  light1.e();
  light2.e();
  
}

void green(int discard) {
   
  light1.b();
  light2.b();
}

void blue(int discard) {
  light1.c();
  light2.c();
}



void testprg() {
  
  
  Serial.println("start test");
  light1.s();
  light2.s();
  delay(4000);
  
  
  
  for(int i=10;i<10000;i++) {
   stepper1.nextStep();
   stepper2.nextStep();
   
  
   delayMicroseconds(4000000/i);
//   delayMicroseconds(700); 
  }
  
  delay(1000);
  stepper1.changeDirection();
  stepper2.changeDirection();
  for(int i=10;i<10000;i++) {
   stepper1.nextStep();
   stepper2.nextStep();
   delayMicroseconds(4000000/i);

  
  }
  
  delay(2000);
  
  Serial.println("end test");
  
  
}


void testlight() {
  
  light1.s();
  delay(2000);
  light1.b();
  delay(2000);
  light1.c();
  delay(2000);
  light1.e();
  delay(2000);
  
}

void testlight2() {
  
  
   light2.s();
  delay(2000);
  light2.b();
  delay(2000);
  light2.c();
  delay(2000);
  light2.e();
  delay(2000);
  
} 

void setup() 
{ 

  Serial.begin(9200);
  
  light1.s();
  light2.s();
  testlight2();
   light1.s();
  light2.s();
  testlight();
  testprg();
  
  
  
  


} 



//fin d'initialisation



//loop veut dire boucle, ici c'est une boucle infinie, tant que la carte est sous tension la machine ne s'arretera pas grace à cette boucle
void loop() 
{ 
  //ce "switch ... case" permet de faire bouger le moteur et ne doit pas etre changé, il faut changer plus loin la vitesse et le sens de rotation en jouant sur les variables "dir" et step
 

stepper1.nextStep();
stepper2.nextStep();


 //si on vient de finir les mouvements gauche droite accélerés
if ((automate == 10) && ce_que_on_fait==0) 
{
       ce_que_on_fait=1;
       automate = 0;
       counter = 0;
       delay(8000);
  }
  else if ((automate == 2) && ce_que_on_fait==1){ 
           delay(8000);

       ce_que_on_fait=2;
       automate = 3;
       counter = 0;
  }
  else if ((automate == 10) && ce_que_on_fait==2) {   
           delay(8000);

         ce_que_on_fait=0;
       automate = 0;
   }   
 
  else {   
         /*ce_que_on_fait=0;
       automate = 0;
       counter = 0;*/
   }    
   
switch(ce_que_on_fait)
{
       case 0:
                        off();
                        counter++;
                        switch(automate)
                        {
                      
                        case 0:
                                                  red(1);

                          delay(10);
                          if((counter % 500) == 0) automate=1;
                          break;
                        case 1:
                                                  red(1);


                          delay(5);
                          if((counter % 500) == 0) automate=2;
                          break;
                        case 2:
                        
                                                                          green(1);


                          delay(1);
                          if((counter % 500) == 0) automate=3;
                          break;
                      
                      
                        case 3:
                        blue(1)
;
                          if((counter % 500) == 0) 
                          {
                                                    //off();

                            delay(8000);
                            automate=4;
                            
                            stepper1.changeDirection();
            
                          }     
                          break;  
                        case 4:
                          delay(5);
                          if((counter % 500) == 0) automate=5;
                          break; 
                        case 5:
                          delay(10);
                          if((counter % 500) == 0) automate=10;
                          break; 
                      
                        case 10:
                          if((counter % 500) == 0) automate=0;
                          break; 
                        default:
                          if((counter % 500) == 0) automate=0;
                          break; 
                        }  
                      
                        if((counter % 500) == 0) counter=0;
  
    break; 

       case 1:
       
                        red(counter/50);
                        counter++;
                        switch(automate)
                        {
                      
                        case 0:
                          delay(1);
                          if((counter % 500) == 0) automate=1;
                          break;
                        case 1:
                          delay(5);
                          if((counter % 500) == 0) automate=2;
                          break;
                        case 2:
                          delay(1);
                          if((counter % 500) == 0) automate=0;
                          break;
                      
                        default:
                          if((counter % 500) == 0) automate=0;
                          break; 
                        }  
                      
                        if((counter % 500) == 0) counter=0;
  
    break;     

       case 2:
                        counter++;
                          off();
                        green(100);
                        switch(automate)
                        {
                          case 3:
                          delay(1);
                          if((counter % 500) == 0) 
                          {
                            automate=4;
                            stepper1.changeDirection();
                          }     
                          break;  
                        case 4:
                          delay(5);
                          if((counter % 500) == 0) automate=5;
                          break; 
                        case 5:
                          delay(10);
                          if((counter % 500) == 0) automate=10;
                          break; 
                      
                        case 10:
                          if((counter % 500) == 0) automate=0;
                          break; 
                        default:
                          if((counter % 500) == 0) automate=3;
                          break; 
                        }  
                      
                        if((counter % 500) == 0) counter=0;
  
    break;     
 }   

}
















