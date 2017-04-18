

void red(bool on) {
  if(on) {
    digitalWrite(3, HIGH);   // sets the LED 
  } else {
    digitalWrite(3, LOW);   // sets the LED 
  }
}

void green(bool on) {
  if(on) {
    digitalWrite(5,HIGH);
  } else {
    digitalWrite(5,LOW);
  }
}

void blue(bool on) {
  if(on) {
    digitalWrite(6,HIGH);
  } else {
    digitalWrite(6,LOW);
  }
}

void all() {
  red(true);
  blue(true);
  green(true);
}

void off() {
  red(false);
  blue(false);
  green(false);
}


void redS(int i) {
  analogWrite(3, i);
  analogWrite(9, i);
}

void greenS(int i) {
  analogWrite(5,i);
   analogWrite(11,i);
 
}

void blueS(int i) {
  analogWrite(6,i);
   analogWrite(10,i);
 
}






int nextProg = -1;


void checkSerial() {

   if(Serial.available()) {
    switch (Serial.read()) {
      case 's':
      nextProg = 0; break;
      case 'a':
      nextProg = 1; break;
      case 'b':
      nextProg = 2; break;
      case 'c':
      nextProg = 3; break;
      case 'd':
      nextProg = 4; break;
      case 'e':
      nextProg = 5; break;
    }
   }
}

bool shouldStop() {
  checkSerial();
  return nextProg != -1;
}


void prog00() {
  Serial.println("START 00");
  off();
  delay(1000);
}

void prog01() {
  //ROUGE MONTANT DESCENDANT
  Serial.println("START PROGRAM 1");

   int s = 5;
   for(int i=0;i < 128;i=i+s) {
    if(shouldStop()) {return;}
    redS(i);
    delay(100);   
  }
  for(int i=128;i >0;i=i-s) {
    if(shouldStop()) {return;}
    redS(i);
    delay(10); 
  }  
}

void prog02() {
   //BLUE MONTANT DESCENDANT
   Serial.println("START PROGRAM 2");
   int s = 2;
   for(int i=0;i < 128;i=i+s) {
    if(shouldStop()) {return;}
    blueS(i);
    delay(100);   
  }
  for(int i=128;i >0;i=i-s) {
    if(shouldStop()) {return;}
    blueS(i);
    delay(10); 
  }  
  
}

void prog03() {
   //VERT MONTANT DESCENDANT
   Serial.println("START PROGRAM 3");
   int s = 3;
   for(int i=0;i < 128;i=i+s) {
    if(shouldStop()) {return;}
    greenS(i);
    delay(100);   
  }
  for(int i=128;i >0;i=i-s) {
    if(shouldStop()) {return;}
    greenS(i);
    delay(10); 
  }
}

void prog04() {

  //VIOLET MONTANT DESCENDANT
   Serial.println("START PROGRAM 3");
   int s = 2;
   for(int i=0;i < 255;i=i+s) {
    if(shouldStop()) {return;}
    blueS(i);
    redS(i);
    delay(100);   
  }
  for(int i=255;i >0;i=i-s) {
    if(shouldStop()) {return;}
    blueS(i);
    redS(i);
    delay(10); 
  } 
}

void prog05() {

  Serial.println("START PROGRAM 05");
  for(int i=0; i< 128; i=i+2) {
    if(shouldStop()) {return;}
    redS(i);
    delay(100);
  }
  for(int i=0; i < 128; i= i +1) {
    if(shouldStop()) {return;}
    blueS(i);
    delay(100);
  }
  for(int i=0; i < 128; i = i +1) {
     if(shouldStop()) {return;}
     redS(128 - i);
     blueS(128 - i);
     greenS(i);
     delay(100);
  }

  for(int i=0; i <128; i = i +1) {

    greenS(128 -i ) ;
    delay(10);
  }


  
}

void prod99() {

  Serial.println("Test all color");

  for(int c=3; c < 12; c ++) {
    if(c==4 || c==7 || c == 8) {
      
    } else {
      for(int i=0; i < 128; i++) {
        analogWrite(c,i);
        delay(1);
      }
     digitalWrite(c,LOW);

      
    }
  }
}

void setup() {

  Serial.begin(9600);
  pinMode(3, OUTPUT);   
  pinMode(5, OUTPUT);      // sets the digital pin as output
  pinMode(6, OUTPUT);      // sets the digital pin as output
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  prod99();

  
// sets the digital pin as output

}


void loop() {
  checkSerial();
  int nnextProg = nextProg;
  nextProg = -1;
  switch (nnextProg) {
    case 0 : prog00(); break;
    case 1 : prog01(); break;
    case 2 : prog02(); break;
    case 3 : prog03(); break;
    case 4 : prog04(); break;
    case 5 : prog05(); break;
  }
  /*
  nextProg = nnextProg - 1;
  if(nextProg < 0) nextProg=10;

  */
  
}

