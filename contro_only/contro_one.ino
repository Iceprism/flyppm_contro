//this programm will put out a PPM signal

//////////////////////CONFIGURATION///////////////////////////////
#define chanel_number 8  //set the number of chanels
//#define default_servo_value 0  //set the default servo value
#define PPM_FrLen 22500  //set the PPM frame length in microseconds (1ms = 1000µs)
#define PPM_PulseLen 300  //set the pulse length
#define onState 1  //set polarity of the pulses: 1 is positive, 0 is negative
#define sigPin 10  //set PPM signal output pin on the arduino
//////////////////////////////////////////////////////////////////

#define AIL1  6   //AIL fuyi
#define ELE2  7   //ELE shengjiang
#define THR3  8   //THR youmen
#define RUD4  9   //RUD fangxiang
unsigned long INAIL;
unsigned long INELE;
unsigned long INTHR;
unsigned long INRUD;
//////////////////==/////////////////

#define U 2
#define D 3
#define L 4
#define R 5



/*this array holds the servo values for the ppm signal
 change theese values in your code (usually servo values move between 1000 and 2000)*/
int ppm[chanel_number];

void setup(){  
  //initiallize default ppm values
  pinMode(AIL1,0);
  pinMode(ELE2,0);
  pinMode(THR3,0);
  pinMode(RUD4,0);
  
  pinMode(U,0);
  pinMode(D,0);
  pinMode(L,0);
  pinMode(R,0);//0 INPUT
  
////////
/*
  for(int i=0; i<chanel_number; i++){
    ppm[i]= default_servo_value;
  }
  */


  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, !onState);  //set the PPM signal pin to the default state (off)
  
  cli();
  TCCR1A = 0; // set entire TCCR1 register to 0
  TCCR1B = 0;
  
  OCR1A = 100;  // compare match register, change this
  TCCR1B |= (1 << WGM12);  // turn on CTC mode
  TCCR1B |= (1 << CS11);  // 8 prescaler: 0,5 microseconds at 16mhz
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  sei();
}

void loop(){
  //put main code here

  INAIL = pulseIn(AIL1, 1);
  INELE = pulseIn(ELE2, 1);
  INTHR = pulseIn(THR3, 1);
  INRUD = pulseIn(RUD4, 1);

    if (digitalRead(U)==HIGH)   
  {
    INELE = INELE + 222 ;
  }
  
    if (digitalRead(D)==HIGH)   
  {
    INELE = INELE - 222 ;
  }
  
  if (digitalRead(L)==HIGH) 
  {
    INAIL = INAIL - 222 ;
  }
  if (digitalRead(R)==HIGH) 
  {
    INAIL = INAIL + 222 ;
  }
  
  
  ppm[0] = INAIL;
  ppm[1] = INELE;
  ppm[2] = INTHR;
  ppm[3] = INRUD;
  
  
  
  /*
  ppm[4] = 1000;
  ppm[5] = 1000;
  ppm[6] = 1000;
  ppm[7] = 1000;
  delay(5);
  */
  /*
  static int val = 1;
  
  ppm[0] = ppm[0] + val;
  if(ppm[0] >= 2000){ val = -1; }
  if(ppm[0] <= 1000){ val = 1; }
  delay(10);
  */
}

ISR(TIMER1_COMPA_vect){  //leave this alone
  static boolean state = true;
  
  TCNT1 = 0;
  
  if(state) {  //start pulse
    digitalWrite(sigPin, onState);
    OCR1A = PPM_PulseLen * 2;
    state = false;
  }
  else{  //end pulse and calculate when to start the next pulse
    static byte cur_chan_numb;
    static unsigned int calc_rest;
  
    digitalWrite(sigPin, !onState);
    state = true;

    if(cur_chan_numb >= chanel_number){
      cur_chan_numb = 0;
      calc_rest = calc_rest + PPM_PulseLen;// 
      OCR1A = (PPM_FrLen - calc_rest) * 2;
      calc_rest = 0;
    }
    else{
      OCR1A = (ppm[cur_chan_numb] - PPM_PulseLen) * 2;
      calc_rest = calc_rest + ppm[cur_chan_numb];
      cur_chan_numb++;
    }     
  }
}



