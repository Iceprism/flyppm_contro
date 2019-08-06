#include <Pixy2.h>
Pixy2 pixy;
int L=4;
int R=5;
int U=6;
int D=7;
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
	int TX,TY;
	pixy.ccc.getBlocks();
	
	TX=pixy.blocks[i].x-158;
	TY=pixy.blocks[i].y-104;
	
	if(TX>10)
	{
		digitalWrite(R,HIGH);
		delay(100);
		digitalWrite(R,LOW);
	}
	if(TX>-10)
	{
		digitalWrite(L,HIGH);
		delay(100);
		digitalWrite(L,LOW);
	}
	if(TY<-10)
	{
		digitalWrite(U,HIGH);
		delay(100);
		digitalWrite(U,LOW);
	}
	if(TY>10)
	{
		digitalWrite(D,HIGH);
		delay(100);
		digitalWrite(D,LOW);
	}	
	
	
	
	
}