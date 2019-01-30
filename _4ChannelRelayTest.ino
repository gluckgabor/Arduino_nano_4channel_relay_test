//IDE settings: Tools/Board: arduino nano, Processor:atmega168, Programmer: arduinoISP

const int IN1 = 7; 
const int IN2 = 6;
const int IN3 = 5; 
const int IN4 = 4;

#define ON   0
#define OFF  1

void setup() {
 Serial.begin(9600); 
 
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  relay_init();//initialize the relay
}
 
void loop() {
  relay_SetStatus(ON, OFF, OFF, OFF);//turn on RELAY_1 
  delay(2000);//delay 2s
  relay_SetStatus(OFF, ON, OFF, OFF);//turn on RELAY_2
  delay(2000);//delay 2s
  relay_SetStatus(OFF, OFF, ON, OFF);//turn on RELAY_3
  delay(2000);//delay 2s
  relay_SetStatus(OFF, OFF, OFF, ON);//turn on RELAY_4
  delay(2000);//delay 2s
}

void relay_init(void)//initialize the relay
{  
  //set all the relays OUTPUT
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  relay_SetStatus(OFF,OFF,OFF,OFF);//turn off all the relay
}
//set the status of relays
void relay_SetStatus( unsigned char status_1,  unsigned char status_2, unsigned char status_3,unsigned char status_4)
{
  digitalWrite(IN1, status_1);
  digitalWrite(IN2, status_2);
  digitalWrite(IN3, status_3);
  digitalWrite(IN4, status_4);

}
