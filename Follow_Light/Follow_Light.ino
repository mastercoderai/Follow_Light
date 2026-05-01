/*LED pins from Left to Right*/
const int led1 = 12;
const int led2 = 11;
const int led3 = 10;
const int led4 = 9;
const int led5 = 8;

/*Buzzer pin*/
const int buzzer = 7;

/*Button pins from Left to right*/
const int rec1 = A0;
const int rec2 = A1;
const int rec3 = A2;
const int rec4 = A4;
const int rec5 = A5;

int list[5] = {};
int copy[5] = {};

int j=0, re1=0,re2=0,re3=0,re4=0,re5=0;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);

  pinMode(buzzer,OUTPUT);

  pinMode(rec1,INPUT);
  pinMode(rec2,INPUT);
  pinMode(rec3,INPUT);
  pinMode(rec4,INPUT);
  pinMode(rec5,INPUT);

 }


void loop()
{
  for(int i=0;i<5;i++)
  {
     int randnum = random(1,6);
     list[i]=randnum;
     digitalWrite(buzzer , HIGH);
     delay(50);
     digitalWrite(buzzer , LOW);
    //  Serial.println(randnum);
    
    
    if(randnum == 1)
    {
      digitalWrite(led1,HIGH);
      delay(400);
      digitalWrite(led1,LOW);
      delay(100);
      
    }
    if(randnum ==2)
    {
       digitalWrite(led2,HIGH);
      delay(400);
      digitalWrite(led2,LOW);
      delay(100);
      
    }
    if(randnum == 3)
    {
       digitalWrite(led3,HIGH);
      delay(400);
      digitalWrite(led3,LOW);
      delay(100);
      
    }
    if(randnum == 4)
    {
       digitalWrite(led4,HIGH);
      delay(400);
      digitalWrite(led4,LOW);
      delay(100);
      
    }
    if(randnum == 5)
    {
       digitalWrite(led5,HIGH);
      delay(400);
      digitalWrite(led5,LOW);
      delay(100);
      
    }

  }
  
  for(j=0;j<5;j=j)
  {
    
  // Serial.println("Checking sensors...");

    if(int(analogRead(rec1))>1000)
    {
       re1 =1;
    }
    
    if(int(analogRead(rec2))>1000)
    {
       re2 = 1;
    }
    if(int(analogRead(rec3))>1000)
    {
       re3 = 1;
    }
    if(int(analogRead(rec4))>1000)
    {
       re4 = 1;
    }
    if(int(analogRead(rec5))>1010)
    {
       re5 = 1;
    }
     
    
    if( re1 == 1)
    {
      digitalWrite(led1,HIGH);
      tone(buzzer,1500,200);
      delay(30);
      digitalWrite(led1,LOW);
      tone(buzzer,1500,200);
      delay(30);

      copy[j]=1;
      j = j+1;
      re1 = 0;
    }
    if(re2 == 1)
    {
      digitalWrite(led2,HIGH);
      tone(buzzer,1500,200);
      delay(30);
      digitalWrite(led2,LOW);
      tone(buzzer,1500,200);
      delay(30);

      copy[j]=2;
      j = j+1;
      re2 = 0;
    }
    if(re3 == 1)
    {
      digitalWrite(led3,HIGH);
      tone(buzzer,1500,200);
      delay(30);
      digitalWrite(led3,LOW);
      tone(buzzer,1500,200);
      delay(30);

      copy[j]=3;
      j = j+1;
      re3 = 0;
    }
    if(re4 ==1)
    {
      digitalWrite(led4,HIGH);
      tone(buzzer,1500,200);
      delay(30);
      digitalWrite(led4,LOW);
      tone(buzzer,1500,200);
      delay(30);

      copy[j]=4;
      j =j+1;
      re4 = 0;
    }
    if(re5 == 1)
    {
      digitalWrite(led5,HIGH);
      tone(buzzer,1500,200);
      delay(30);
      digitalWrite(led5,LOW);
      tone(buzzer,1500,200);
      delay(30);

      copy[j]=5;
      j = j+1;
      re5 = 0;
    }

    /*This are the Serial outputs for testing your buttons connections and the LEDs connections*/

    // Serial.print("rec1: "); Serial.println(analogRead(rec1));
    // Serial.print("rec2: "); Serial.println(analogRead(rec2));
    // Serial.print("rec3: "); Serial.println(analogRead(rec3));
    // Serial.print("rec4: "); Serial.println(analogRead(rec4));
    // Serial.print("rec5: "); Serial.println(analogRead(rec5));

    delay(150);
  }
  
bool isCorrect = true;
for (int i = 0; i < 5; i++) {
    if (list[i] != copy[i]) {
        isCorrect = false;
        break;
    }
}

if (isCorrect) {
    playWinningTone();
    delay(3000);
} else {
    playLosingTone();
    delay(3000);
}

}
void playWinningTone() {
    tone(buzzer, 1000, 200);  
    delay(250);
    tone(buzzer, 1200, 200);  
    delay(250);
    tone(buzzer, 1500, 300);  
    delay(350);
    noTone(buzzer);  
}

void playLosingTone() {
    tone(buzzer, 400, 300); 
    delay(350);
    tone(buzzer, 300, 400);  
    delay(450);
    tone(buzzer, 200, 500);  
    delay(550);
    noTone(buzzer);  
}

//If you confuse with the winning/losing tones(of Buzzer), you can add a 4 pins LED and trigger the red light for wrong and green light for right!
// ALL THE BEST! KEEP BUILDING!
