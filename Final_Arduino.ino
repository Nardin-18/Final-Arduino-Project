int btn = 2;
int value=0; // this is the value of the first LDR
int value2=0; // this is the value of the second LDR
int buzzer=10;
int p=0; 
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;
int sys_state = 0;
 
void setup() {
  pinMode(btn,INPUT);
  Serial.begin(9600);
  pinMode(10,OUTPUT);
}
 
void loop() {
  // here's the loop to connect the working of the system with the push of the button.
  // if the button is pressed the system starts with the value 1 or any other odd value appearing on the screen.
  // if the button is pressed again to stop the system an even number will appear.
  buttonState = digitalRead(btn);
  if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH)
    {
      buttonPushCounter++;
      Serial.println(buttonPushCounter);
    }
    delay(50);
  }
 
 lastButtonState = buttonState;
 
 if (buttonPushCounter %2 != 0)
 {
   sys_state = 1;
 }
 else
 {
  sys_state = 0;
 }
 
 if (sys_state == 1){ 
 value=analogRead(A0);
 value2=analogRead(A1);
 value=map(value,0,1023,0,255);
 value2=map(value2,0,1023,0,255);
 // the variable p is a counter to count the number of people in the room.
 
  if (value<50){ // first LDR to detect if a person entered the room
  p+=1;
  delay(1000);
  Serial.println("A person entered the room");
  Serial.print("Number of persons in the room: ");
  Serial.println(p);
  Serial.print("LDR reading: ");
  Serial.println(value);
  value2=0;
  if (p>=6){ 
      digitalWrite(10,HIGH);
      delay(1000);
      digitalWrite(10,LOW);
      delay(1000);}
      }
  else if (value2<50){ //second LDR to detect if a person left the room
  p-=1;
  delay(1000);
  Serial.println("A person left the room");
  Serial.print("Number of persons in the room: ");
  Serial.println(p);
  Serial.print("LDR reading: ");
  Serial.println(value2);
  value=0;
  if (p>=6){ 
      digitalWrite(10,HIGH);
      delay(1000);
      digitalWrite(10,LOW);
      delay(1000);}
  }
  value=0;
  value2=0;
  delay(20);
  }
  else{
    digitalWrite(10,LOW);
    value2=0;
    value=0;
    }
}
