
//debut d'initialisation
int Pin0 = 10; 
int Pin1 = 11; 
int Pin2 = 12; 
int Pin3 = 13; 
int _step = 0; 
int ce_que_on_fait=0;
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
//fin d'initialisation

//loop veut dire boucle, ici c'est une boucle infinie, tant que la carte est sous tension la machine ne s'arretera pas grace à cette boucle
void loop() 
{ 
  //ce "switch ... case" permet de faire bouger le moteur et ne doit pas etre changé, il faut changer plus loin la vitesse et le sens de rotation en jouant sur les variables "dir" et step
  switch(_step){ //switch veut dire basculer vers : un switch permet d'avoir plusieurs codes à executer et n'en executer un seul à chaque fois qu'on passe par ici selon la valeur de la variable qui s'appelle _step, si la valeur de _step est different de toutes les valeurs qu'on a prevu en dessous alors on execute le code qui suit l'eatpe qui s'appelle "default:"
  case 0: 
    digitalWrite(Pin0, LOW);  
    digitalWrite(Pin1, LOW); 
    digitalWrite(Pin2, LOW); 
    digitalWrite(Pin3, HIGH); 
    break;  
  case 1: 
    digitalWrite(Pin0, LOW);  
    digitalWrite(Pin1, LOW); 
    digitalWrite(Pin2, HIGH); 
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


 
if ((automate == 10) && ce_que_on_fait==0) //si on vient de finir les mouvements gauche droite accélerés
{
       ce_que_on_fait=1;
       automate = 0;
       counter = 0;
  }
  else if ((automate == 2) && ce_que_on_fait==1){ 
       ce_que_on_fait=2;
       automate = 3;
       counter = 0;
  }
  else if ((automate == 10) && ce_que_on_fait==2) {   
         ce_que_on_fait=3;
       automate = 3;
   }   
 
  else if ((automate == 10) && ce_que_on_fait==3) {   
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
       case 0://
                        counter++;
                        switch(automate)
                        {
                      
                        case 0:
                          delay(10);
                          if((counter % 500) == 0) automate=1;
                          break;
                        case 1:
                          delay(5);
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
                          delay(5);
                          if((counter % 200) == 0) automate=5;
                          break; 
                        case 5:
                          delay(10);
                          if((counter % 200) == 0) automate=10;
                          break; 
                      
                        case 10:
                          if((counter % 200) == 0) automate=0;
                          break; 
                        default:
                          if((counter % 200) == 0) automate=0;
                          break; 
                        }  
                      
                        if((counter % 200) == 0) counter=0;
  
    break; 

       case 1:
                        counter++;
                        switch(automate)
                        {
                      
                        case 0:
                          delay(1);
                          if((counter % 2500) == 0) automate=2;
                          break;
                        /*case 1:
                          delay(1);
                          if((counter % 500) == 0) automate=2;
                          break;*/
                        case 2:
                          delay(1);
                          if((counter % 2500) == 0) automate=0;
                          break;
                      
                        default:
                          if((counter % 2500) == 0) automate=0;
                          break; 
                        }  
                      
                        if((counter % 2500) == 0) counter=0;
  
    break;     

       case 2:
                        counter++;
                        switch(automate)
                        {
                          case 3:
                          delay(10);
                          if((counter % 2500) == 0) 
                          {
                            automate=10;
                            if(dir == true) dir=false;
                            else dir = true; 
                          }     
                          break;  
                        /*case 4:
                          delay(1);
                          if((counter % 5000) == 0) automate=5;
                          break; 
                        case 5:
                          delay(1);
                          if((counter % 1000) == 0) automate=10;
                          break; */
                      
                        case 10:
                          if((counter % 2500) == 0) automate=0;
                          break; 
                        default:
                          if((counter % 2500) == 0) automate=3;
                          break; 
                        }  
                      
                        if((counter % 2500) == 0) counter=0;
  
    break;    
   
   
 
       case 3:
                        counter++;
                        switch(automate)
                        {
                          case 3:
                          delay(10);
                          if((counter % 1000) == 0) 
                          {
                            automate=10;
                            if(dir == true) dir=false;
                            else dir = true; 
                          }     
                          break;  
                        /*case 4:
                          delay(1);
                          if((counter % 1000) == 0) automate=5;
                          break; 
                        case 5:
                          delay(1);
                          if((counter % 2000) == 0) automate=10;
                          break; */
                      
                        case 10:
                          if((counter % 2000) == 0) automate=0;
                          break; 
                        default:
                          if((counter % 2000) == 0) automate=3;
                          break; 
                        }  
                      
                        if((counter % 2000) == 0) counter=0;
  
    break;      
   
    
 }   

}















