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
    
   pinMode(R1,OUTPUT);
   pinMode(R2,OUTPUT);
   pinMode(R3,OUTPUT);
   pinMode(R4,OUTPUT);  

   stopall_motors();
}
void loop()
{
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      //Serial.print(data);          //Print Value inside data in Serial monitor

           
      if(data == 'F'){        
        digitalWrite(R1,LOW);
        digitalWrite(R2,HIGH);
        digitalWrite(R3,LOW); 
        digitalWrite(R4,HIGH);
      }else if(data == 'B'){ 
        digitalWrite(R1,HIGH);
        digitalWrite(R2,LOW);
        digitalWrite(R3,HIGH);
        digitalWrite(R4,LOW);                  
      }else if(data == 'R'){
        digitalWrite(R1,HIGH);
        digitalWrite(R2,HIGH);
        digitalWrite(R3,LOW);
        digitalWrite(R4,HIGH);
      }else if(data == 'L'){
        digitalWrite(R1,LOW);
        digitalWrite(R2,HIGH);
        digitalWrite(R3,HIGH);
        digitalWrite(R4,HIGH);
      }else{
        stopall_motors();      
      }
   }
}
