


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
    void setDirection(boolean newdir);
    void setPosition(int pos);
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

void MyStepper::setDirection(boolean newdir) {
  _dir = newdir;
}

void MyStepper::changeDirection() {
  _dir = !_dir;
}

void MyStepper::setPosition(int pos) {
    switch(pos){ //switch veut dire basculer vers : un switch permet d'avoir plusieurs codes à executer et n'en executer un seul à chaque fois qu'on passe par ici selon la valeur de la variable qui s'appelle _step, si la valeur de _step est different de toutes les valeurs qu'on a prevu en dessous alors on execute le code qui suit l'eatpe qui s'appelle "default:"
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
  
}




void MyStepper::nextStep() {
  
  setPosition(_step);
  
 
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

  Serial.begin(9600);
  Serial.println("new");
  light1.s();
  light2.s();
  
  
  stepper1.setPosition(8);
  stepper2.setPosition(8);
  
  //testlight2();
  //light1.s();
  //light2.s();
  //testlight();
  //testprg();
  
  
  //delay(4000);
  
} 



//fin d'initialisation

#define F0 10
#define B0 -10
#define F1 1
#define P 0
#define F2 2
#define F3 3
#define B1 -1
#define B2 -2
#define B3 -3
#define S 5
#define P1 6
#define P2 7
#define P3 8
#define R  9


#define A true
#define B false

boolean variationA = false;
boolean variationB = true; 
int variationC = 1;

void variation() {
  
  variationC = random(0, 4000);
  variationA = random(0,2) % 2 == 0;
  variationB = random(0,2) % 2 == 0;

}


void nextStep(boolean first) {
  if(first == A) {
    stepper1.nextStep();
  } else {
    stepper2.nextStep();
  }
}

void freeWheel(boolean aOrB) {
  if(aOrB == A) {
   stepper1.setPosition(8);
  } else {
   stepper2.setPosition(8); 
  }
}

void setDirection(boolean aOrB, boolean dir) {
  if(aOrB == A) {
    stepper1.setDirection(dir ^ variationA);
  } else {
    stepper2.setDirection(dir ^ variationB);
  }
}

void subcor(int m, int stepn, boolean aOrB) {
  
  switch(m) {
    case F0:
    case F1:
    case F2:
    case F3:
    setDirection(aOrB,true); break;
    case B0:
    case B1:
    case B2:
    case B3:
    setDirection(aOrB,false); break;
  }
  
  switch(m) {
    case B0:
    case F0:
    if (stepn % 8 > 0) break;
    case B1:
    case F1:
    if(stepn % 4 >0) break;
    case B2:
    case F2:
    if(stepn % 2 >0) break;
    case B3:
    case F3:
    nextStep(aOrB);
    
  }
  
}  

#define L1 1
#define L2 2

void subcorLight(int L1orL2, int m) {
  
  MyLight* light;
  if(L1orL2 == L1) {
    light = & light1;
  } else {
    light = & light2;
  }
  switch(m) {
    case S: light->s(); break;
    case P1: light->b(); break;
    case P2: light->c(); break;
    case P3: light->e(); break;
  }
  
}

void cor(int a, int b) {
 
 cor2(a,b,random(6,10),random(6,10), random(0,3) ==0); 
}

#define Clicp 4096
#define ClicpS 4000

void cor2(int a, int b, int l1, int l2, boolean fix) {
  
  for(int stepn=0; stepn < 4000 + variationC; stepn ++) {
    long start  = micros();
    if(stepn == 0) {
     subcorLight(L1,l1);
     subcorLight(L2,l2);
    }
    
    if(!fix && (stepn % Clicp == 0)) {
     subcorLight(L1,l1);
     subcorLight(L2,l2);
    }
    if(!fix && (stepn % Clicp == ClicpS)) {
      subcorLight(L1,S);
      subcorLight(L2,S);
    }
    
    if(!fix && (stepn + 1 == 4000 + variationC)) {
      subcorLight(L1,l1);
      subcorLight(L2,l2);
    }
    
    subcor(a,stepn,A);
    subcor(b,stepn,B);
    long len = max(micros() - start,0);
    delayMicroseconds(1200 - len);
  }
  
  
}



//loop veut dire boucle, ici c'est une boucle infinie, tant que la carte est sous tension la machine ne s'arretera pas grace à cette boucle
void loop() 
{ 
  //ce "switch ... case" permet de faire bouger le moteur et ne doit pas etre changé, il faut changer plus loin la vitesse et le sens de rotation en jouant sur les variables "dir" et step
 





boolean newCor = true;

if(newCor) {
  
  
   variation();

cor(B0,P);
cor(B1,P);
cor(B1,B0);
cor(B1,B1);
cor(B0,B0);
cor(P,P);
  
   variation();
 cor(B0,F0);
 cor(B0,F1);
 cor(F0,F1);
 cor(B0,F1);
 cor(F0,F1);
 cor(B0,F1);
 cor(F0,F1);
 cor(F0,F0);
 cor(F0,P);
 cor(P,P);
 
  
  
variation();
cor(F0,F1);
cor(F1,F2);
cor(F2,F3);
cor(F2,B3);
cor(B3,B2);
cor(B2,B1);
cor(B1,B0);
cor(B0,P);
cor(P,P);
  

     variation();
  
  cor(P,P);
  cor2(F0,P, P1, P1, true);
  cor2(F0,F0, S,S, true);
  cor2(P, F0, P1, P1, true);
  cor2(B0, F0, S, S, true);
  cor2(B0, P, P1, P1, true);
  cor2(B0, B0, S,S, true);
  cor2(P, B0, P1, P1, true);
  cor2(P,P,P1,P1,true);
  cor2(P,P,S,S,true);
  
  
  variation();
  cor2(B0,F0, S,S, true);
  cor2(F0,F0, P2, S, true);
  cor2(F0,B0, P3,P2, true);
  cor(F1,B1);
  cor2(P,B1, S,P1, true);
  cor2(F0,P, P1,S, true);
  cor(P,P);
  
  
  variation();
  cor(F1,F1);
  cor(F2,F2);
  cor(F3,F3);
  cor(F3,F3);
  cor(P,P);
  
  
  variation();
  cor(P,F1);
  cor(P,F2);
  cor(B1,F2);
  cor(B2,F1);
  cor(B2,P);
  cor(P,P);
  cor(P,P);
  
  
  variation();
  
  
  cor(P,F1);
  cor(P,F2);
  cor(F1,F2);
  cor(F2,F1);
  cor(F2,P);
  cor(P,P);
  cor(P,P);
  
  
  variation();
  
  cor(P,P);
  cor(F1,F1);
  cor(F1,F2);
  cor(F1,F3);
  cor(F1,F1);
  cor(F1,P);
  cor(F1,B1);
  cor(F1,B2);
  cor(F1,B3);
  cor(F1,B1);
  cor(F1,P);
  cor(P,P);
  
  
  variation();
  cor(P,P);
  cor(F1,F1);
  cor(F3,F3);
  cor(F2,B3);
  cor(P,F3);
  cor(P,P);
  cor(P,P);
  cor(F1,P);
  cor(F2,P);
  cor(F3,P);
  cor(F1,P);
  cor(P,P);
  
} 




}







