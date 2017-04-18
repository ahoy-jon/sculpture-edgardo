
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
boolean pause=false;
int nombreToursAvantReset=4250;

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
  
  
  
 if(pause == false)
 
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

 } 
 
if ((automate == 10) && ce_que_on_fait==0) //si on vient de finir les mouvements gauche droite accélerés
{
       ce_que_on_fait=0;
       automate = 0;
       counter = 0;
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
                      
                        case 0://1 fois 360 degres dans le premier sens
                          delay(1);
                          nombreToursAvantReset=4250;
                          if((counter % 4250) == 0) automate=1;
                          break;
                        case 1://1 fois 360 degres dans le premier sens
                          delay(1);
                          
                          nombreToursAvantReset=4250;
                         if(((counter % 4250) == 0) && (pause==false)  ) 
                           {
                          
                             // changement de direction
                            if(dir == true) dir=false;
                            else dir = true; 
                            
                        pause=true;//demande de pasue
                         
                         
                         automate=2;
                          
                           } 
                           
                           
                           
                          
                          break;
                          
                          
                          
                        case 2://1 fois 360 degres dans le sens opposé(2nd sens)
                          delay(1);
 
                           
                          nombreToursAvantReset=4250;
                          if(((counter % 4250) == 0) && (pause==true)  ) 
                           {
                          
                             
                            
                        pause=false;
                         
                          //counter=0;
                          automate=3;
                          
                           } 
                          break;
                        case 3:
                          delay(1);
                          
                          nombreToursAvantReset=4250;
                          if((counter % 4250) == 0) 
                          
                              {
                          
                             
                            if(dir == true) dir=false;
                            else dir = true; 
                            
                          
                          automate=4;
                          
                          
                           } 
                          break;
                          
                          
                          
                        case 4:
                          delay(1);
                          
                          nombreToursAvantReset=4250/4;
                          if((counter % 4250/4) == 0) 
                          
                              {
                          /*
                             
                            if(dir == true) dir=false;
                            else dir = true; */
                            
                          
                          automate=5;
                          
                          
                           } 
                          break;
                          
                          
                        case 5:
                          delay(1);
                          
                          nombreToursAvantReset=4250;
                          if((counter % 4250) == 0) 
                          
                              {
                          
                             
                            if(dir == true) dir=false;
                            else dir = true; 
                            
                          
                          automate=0;
                          
                          
                           } 
                          break;
                      
                      
                          
                         
                          
                        default:
                          if((counter % 4250) == 0) automate=0;
                          break; 
                        }  
                      
                      
                      if((counter % nombreToursAvantReset) == 0) counter=0;
                     
  
    break; 

      
   
    
 }   

}
















