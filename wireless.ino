
/*
---------------------
AOT ROBO CLUB
V1.2
---------------------
GodFatherXVII
*********************
For help,
post in FB AOT Robo Club
Or contact mentors
********************
*/

char data = 0;            //Variable for storing received data

//Relay Pins
int R1 = 8; // IN1
int R2 = 9; // IN2
int R3 = 10; //IN3
int R4 = 11; //IN4

void stopall_motors(){
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
}

void setup()
{
   Serial.begin(9600);   //Sets the baud for serial data transmission                               
   //Initialize the pins as Output
   pinMode(R1,OUTPUT);
   pinMode(R2,OUTPUT);
   pinMode(R3,OUTPUT);
   pinMode(R4,OUTPUT);  
  //by default put the relay in HIGH State aka switch off all motors.
   stopall_motors();
}
void loop()
{
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
     
     /* Debug :
      See what you are getting as input in console
      
      Serial.print(data);          //Print Value inside data in Serial monitor
      */
           
      if(data == 'F'){
        //Forward
        digitalWrite(R1,LOW);
        digitalWrite(R2,HIGH);
        digitalWrite(R3,LOW); 
        digitalWrite(R4,HIGH);
      }else if(data == 'B'){ 
        //Backward
        digitalWrite(R1,HIGH);
        digitalWrite(R2,LOW);
        digitalWrite(R3,HIGH);
        digitalWrite(R4,LOW);                  
      }else if(data == 'R'){
        //Right
        digitalWrite(R1,LOW);
        digitalWrite(R2,HIGH);
        digitalWrite(R3,HIGH);
        digitalWrite(R4,HIGH);
      }else if(data == 'L'){
        //Left
        digitalWrite(R1,HIGH);
        digitalWrite(R2,HIGH);
        digitalWrite(R3,LOW);
        digitalWrite(R4,HIGH);
      }else{
        //Default stop.
        stopall_motors();      
      }
   }
}
