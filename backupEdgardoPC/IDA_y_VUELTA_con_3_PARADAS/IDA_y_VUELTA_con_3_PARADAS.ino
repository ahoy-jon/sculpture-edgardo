

int Pin0 = 10; 
int Pin1 = 11; 
int Pin2 = 12; 
int Pin3 = 13; 
int _step = 0; 
int counter = 0;
int automate=0;
boolean dir = true;// gre
void setup() 
{ 
  pinMode(Pin0, OUTPUT);  
  pinMode(Pin1, OUTPUT);  
  pinMode(Pin2, OUTPUT);  
  pinMode(Pin3, OUTPUT);  
} 
void loop() 
{ 
  switch(_step){ 
  case 0: 
    digitalWrite(Pin0, HIGH);  
    digitalWrite(Pin1, HIGH); 
    digitalWrite(Pin2, HIGH); 
    digitalWrite(Pin3, HIGH); 
    break;  
  case 1: 
    digitalWrite(Pin0, HIGH);  
    digitalWrite(Pin1, LOW); 
    digitalWrite(Pin2, LOW); 
    digitalWrite(Pin3, HIGH); 
    break;  
  case 2: 
    digitalWrite(Pin0, LOW);  
    digitalWrite(Pin1, LOW); 
    digitalWrite(Pin2, HIGH); 
    digitalWrite(Pin3, LOW); 
    break;  
  case 3: 
    digitalWrite(Pin0, LOW);  
    digitalWrite(Pin1, HIGH); 
    digitalWrite(Pin2, HIGH); 
    digitalWrite(Pin3, LOW); 
    break;  
  case 4: 
    digitalWrite(Pin0, LOW);  
    digitalWrite(Pin1, HIGH); 
    digitalWrite(Pin2, LOW); 
    digitalWrite(Pin3, LOW); 
    break;  
  case 5: 
    digitalWrite(Pin0, HIGH);  
    digitalWrite(Pin1, HIGH); 
    digitalWrite(Pin2, LOW); 
    digitalWrite(Pin3, LOW); 
    break;  
  case 6: 
    digitalWrite(Pin0, HIGH);  
    digitalWrite(Pin1, LOW); 
    digitalWrite(Pin2, LOW); 
    digitalWrite(Pin3, LOW); 
    break;  
  case 7: 
    digitalWrite(Pin0, HIGH);  
    digitalWrite(Pin1, LOW); 
    digitalWrite(Pin2, LOW); 
    digitalWrite(Pin3, HIGH); 
    break;  
  default: 
    digitalWrite(Pin0, LOW);  
    digitalWrite(Pin1, LOW); 
    digitalWrite(Pin2, LOW); 
    digitalWrite(Pin3, LOW); 
    break;  
  } 
  if(dir){ 
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



  counter++;
  switch(automate)
  {

  case 0:
    delay(1);
    if((counter % 500) == 0) automate=1;
    break;
  case 1:
    delay(1);
    if((counter % 500) == 0) automate=2;
    break;
  case 2:
    delay(1);
    if((counter % 500) == 0) automate=3;
    break;
  case 3:
    delay(10);
    if((counter % 500) == 0) 
    {
      automate=4;
      if(dir == true) dir=false;
      else dir = true; 
    }     
    break;  
  case 4:
    delay(1);
    if((counter % 500) == 0) automate=5;
    break; 
  case 5:
    delay(1);
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

}















