int U=8;
int ppm[16];

void setup() 
{
  // put your setup code here, to run once:
  pinMode(U,INPUT);

  Serial.begin(115200);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //static int count;
  
  for(int i=0;i<5;i++)
  {
    ppm[i]=1000;
  }
  int n =digitalRead(U);
  if(n==HIGH)
  {
    ppm[0] = ppm[0] +  300;
  }
  
  for(int c=0;c<16;c++){  //print out the servo values
    Serial.print(ppm[c]);
    Serial.print("  ");
    //count++;
  }
  //count = 0;
  Serial.println("");
  delay(100);  //you can even use delays!!!
}
