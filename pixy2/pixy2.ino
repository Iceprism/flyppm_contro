#include <Pixy2.h>
Pixy2 pixy;
int L=6;
int R=7;
int U=4;
int D=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(L,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(U,OUTPUT);
  pinMode(D,OUTPUT);
  Serial.begin(115200);
  Serial.print("Starting...\n");
  
  pixy.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  int TX,TY;  int i;
  pixy.ccc.getBlocks();

  TX = pixy.ccc.blocks[0].m_x-158;
  TY = pixy.ccc.blocks[0].m_y-104;

  if(TX>15)
  {
    digitalWrite(R,HIGH);
    delay(10);
    digitalWrite(R,LOW);
  }
  if(TX>-15)
  {
    digitalWrite(L,HIGH);
    delay(10);
    digitalWrite(L,LOW);
  }
  if(TY<-15)
  {
    digitalWrite(U,HIGH);
    delay(10);
    digitalWrite(U,LOW);
  }
  if(TY>15)
  {
    digitalWrite(D,HIGH);
    delay(10);
    digitalWrite(D,LOW);
  } 
  pixy.ccc.blocks[i].print();
  Serial.println(TX);
  Serial.println(TY);
  
  
}
