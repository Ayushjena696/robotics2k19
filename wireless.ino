#include <Servo.h>
const byte numChars = 32;
char receivedChars[numChars]; // an array to store the received data
Servo arm1;
Servo arm2;

//MOTORS
int R1 = 8;
int R2 = 9;
int R3 = 10;
int R4 = 11;
int Sarm1 = 7;
int Sarm2 = 6;

boolean newData = false;

void setup() {
   pinMode(R1,OUTPUT);
   pinMode(R2,OUTPUT);
   pinMode(R3,OUTPUT);
   pinMode(R4,OUTPUT);
   arm1.attach(Sarm1);
   arm2.attach(Sarm2);
   //set the serial communication rate
   Serial.begin(9600);
   stopall_motors();
}

void loop() {
 recvWithEndMarker();
 showNewData();
}

void stopall_motors(){
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
}

void recvWithEndMarker() {
 static byte ndx = 0;
 char endMarker = '*';
 char rc;
 
 // if (Serial.available() > 0) {
           while (Serial.available() > 0 && newData == false) {
 rc = Serial.read();

 if (rc != endMarker) {
 receivedChars[ndx] = rc;
 ndx++;
 if (ndx >= numChars) {
 ndx = numChars - 1;
 }
 }
 else {
 receivedChars[ndx] = '\0'; // terminate the string
 ndx = 0;
 newData = true;
 }
 }
}

void showNewData() {
 if (newData == true) {
 Serial.print("This just in ... ");
 String s = receivedChars;
 int val = s.toInt();
if (val == 1)
  {
    //Auto Mode
    Serial.println("FORWARD");
    stopall_motors();    
    digitalWrite(R1,LOW);
    digitalWrite(R3,LOW);
  }
  else if(val == 2)
  {
    Serial.println("MANUAL FWD");
    stopall_motors();    
    digitalWrite(R1,LOW);
    digitalWrite(R3,LOW);
    delay(100);  
    stopall_motors();
  }
 
    /*********For Backward Motion*********/
  else if(val == 3)
  {
    Serial.println("BACK");
    stopall_motors();    
    digitalWrite(R2,LOW);
    digitalWrite(R4,LOW);   
  }
  else if(val == 4)
  {
    Serial.println("MANUAL BACK");
    stopall_motors();    
    digitalWrite(R2,LOW);
    digitalWrite(R4,LOW);
    delay(100);  
    stopall_motors();
  }
   /*********Right*********/
  else if(val == 5)
  {
    Serial.println("RIGHT");
    stopall_motors();       
    digitalWrite(R3,LOW);
  }
  else if(val == 6)
  {
    Serial.println("MANUAL RIGHT");
    stopall_motors();    
    digitalWrite(R3,LOW);   
    delay(100);  
    stopall_motors();
  }
   /*********Left*********/
  else if(val == 7)
  {
    Serial.println("LEFT");
    stopall_motors();       
    digitalWrite(R1,LOW);    
  }
   else if(val == 8)
  {
    Serial.println("MANUAL LEFT");
    stopall_motors();    
    digitalWrite(R1,LOW);   
    delay(100);  
    stopall_motors();
  }
  else if(val >= 100 && val <= 280){
    //first arm
    Serial.println("ARM1 :");
    Serial.println(val-100); 
    arm1.write(val);
  }
  else if(val >= 300 && val <= 480){
    //second arm
    Serial.println("ARM2 :");
    Serial.println(val-300); 
    arm2.write(val);
  }
  else
  {
    Serial.println("STOP");
    stopall_motors(); 
  }
 newData = false;
 }
}
