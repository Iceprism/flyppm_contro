#define PWMnum 75 //1.5v 
int NOWPWM = 110 ;//2.2v
int D0 = 5 ;
int D1 = 6 ;
int D2 = 7 ;
int D3 = 8 ;//遥控器接收端 定义io
int VT = 9 ;
// 前轮驱动
int IN1 = 19 ;// + OUT1
int IN2 = 18 ;// - OUT2
//后轮驱动
int IN3 = 14 ;// + OUT3
int IN4 = 15 ;// - OUT4
//使能端
int ENA = 13 ;//前轮使能
int ENB = 12 ;//后轮使能 PWM！

void setup() {
    //输入端
	pinMode(D0,INPUT);
	pinMode(D1,INPUT);
	pinMode(D2,INPUT);
	pinMode(D3,INPUT);
	pinMode(VT,INPUT);
	//输出端 驱动
	pinMode(IN1,OUTPUT);
	pinMode(IN2,OUTPUT);
	pinMode(IN3,OUTPUT);
	pinMode(IN4,OUTPUT);	
	//使能端 因为PWM的ENB不需要定义、
	pinMode(ENA,OUTPUT);
	pinMode(ENB,OUTPUT);
	//ENB
	
}

void loop() {
	
	//if(digitalRead(VT) == HIGH) //无信号即停机
	//{
		if((digitalRead(D1) == HIGH)||(digitalRead(D2) == HIGH))
		{
			digitalWrite(IN3,LOW);
			digitalWrite(IN4,LOW);
			digitalWrite(ENB,HIGH);
			/*for(;NOWPWM>PWMnum;NOWPWM -= 5)
			{
				analogWrite(ENB,NOWPWM);
			}*/
			if(digitalRead(D2) == HIGH)// 前进
			{
				digitalWrite(IN3,LOW);
				digitalWrite(IN4,HIGH);
				
				
				if(digitalRead(D3) == HIGH)// 左转
				{
					digitalWrite(ENA,HIGH);//启动使能端
					digitalWrite(IN1,HIGH);
					digitalWrite(IN2,LOW);
				}
				if(digitalRead(D0) == HIGH)// 右转
				{
					digitalWrite(ENA,HIGH);//启动使能端
					digitalWrite(IN1,LOW);
					digitalWrite(IN2,HIGH);
				}
			}
			if(digitalRead(D1) == HIGH)//后退
			{
				digitalWrite(IN3,HIGH);
				digitalWrite(IN4,LOW);
								
				if(digitalRead(D3) == HIGH)// 左转
				{
					digitalWrite(ENA,HIGH);//启动使能端
					digitalWrite(IN1,HIGH);
					digitalWrite(IN2,LOW);
				}
				if(digitalRead(D0) == HIGH)// 右转
				{
					digitalWrite(ENA,HIGH);//启动使能端
					digitalWrite(IN1,LOW);
					digitalWrite(IN2,HIGH);
				}
			}
			/*else //归零 不知道有什么用
			{
				digitalWrite(IN3,LOW);
				digitalWrite(IN4,LOW);
			}*/
			//左右判断
			if((digitalRead(D3) == HIGH)||(digitalRead(D0) == HIGH))
			{
				digitalWrite(ENA,HIGH);//启动使能端
				if(digitalRead(D3) == HIGH)// 左转
				{
					digitalWrite(IN1,HIGH);
					digitalWrite(IN2,LOW);
				}
				if(digitalRead(D0) == HIGH)// 右转
				{
					digitalWrite(IN1,LOW);
					digitalWrite(IN2,HIGH);
				}
				/*else
				{
					digitalWrite(IN1,LOW);
					digitalWrite(IN2,LOW);
				}*/
			}
			/*else 
			{
				digitalWrite(ENA,LOW);
			}*/
			
		}
		/*else
		{
			digitalWrite(ENB,LOW);
		}*/
	//}
	/*
	else
	{
		digitalWrite(IN1,LOW);
		digitalWrite(IN2,LOW);
		digitalWrite(IN3,LOW);
		digitalWrite(IN4,LOW);
		
		digitalWrite(ENA,LOW);
		digitalWrite(ENB,LOW);
	}
	*/
	if(digitalRead(VT) == LOW)
	{
		digitalWrite(IN1,LOW);
		digitalWrite(IN2,LOW);
		digitalWrite(IN3,LOW);
		digitalWrite(IN4,LOW);
	}
	

  
  

}