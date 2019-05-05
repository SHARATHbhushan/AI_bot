// duration for output
int time = 50;
// initial command
int command = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  Serial.begin(115200);
}

void loop() {
  //receive command
  if (Serial.available() > 0){
    command = Serial.read();
  }
  else{
    reset();
  }
   send_command(command,time);
}

void left(int time){
  analogWrite(3, 255);//LEFT MOTOR 1 1EN_A 
  analogWrite(5,255);//LEFT MOTOR 2  1EN_B
  analogWrite(6, 255);//RIGHT MOTOR 1 2EN_A 
  analogWrite(9, 255);//RIGHT MOTOR 2  2EN_B
  digitalWrite(2, HIGH);//left motors FORWARD
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8,LOW);
  digitalWrite(10, LOW);//right motors REVERSE
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(time);
}

void right(int time){
  analogWrite(3, 255);//LEFT MOTOR 1 1EN_A 
  analogWrite(5,255);//LEFT MOTOR 2  1EN_B
  analogWrite(6, 255);//RIGHT MOTOR 1 2EN_A 
  analogWrite(9, 255);//RIGHT MOTOR 2  2EN_B
  digitalWrite(2, LOW);//left motors REVERSE
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8,HIGH);
  digitalWrite(10, HIGH);//right motors FORWARD
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(time);
}

void forward(int time){
  analogWrite(3, 255);//LEFT MOTOR 1 1EN_A 
  analogWrite(5,255);//LEFT MOTOR 2  1EN_B
  analogWrite(6, 255);//RIGHT MOTOR 1 2EN_A 
  analogWrite(9, 255);//RIGHT MOTOR 2  2EN_B
  digitalWrite(2, HIGH);//left motors FORWARD
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8,LOW);
  digitalWrite(10, HIGH);//right motors FORWARD
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(time);
}

void reverse(int time){
  analogWrite(3, 255);//LEFT MOTOR 1 1EN_A 
  analogWrite(5,255);//LEFT MOTOR 2  1EN_B
  analogWrite(6, 255);//RIGHT MOTOR 1 2EN_A 
  analogWrite(9, 255);//RIGHT MOTOR 2  2EN_B
  digitalWrite(2, LOW);//left motors REVERSE
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8,HIGH);
  digitalWrite(10, LOW);//right motors REVERSE
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(time);
}

void forward_right(int time){
  analogWrite(3, 180);//LEFT MOTOR 1 1EN_A 
  analogWrite(5,180);//LEFT MOTOR 2  1EN_B
  analogWrite(6, 255);//RIGHT MOTOR 1 2EN_A 
  analogWrite(9, 255);//RIGHT MOTOR 2  2EN_B
  digitalWrite(2, HIGH);//left motors FORWARD
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8,LOW);
  digitalWrite(10, HIGH);//right motors FORWARD
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(time);
}

void reverse_right(int time){
  analogWrite(3, 180);//LEFT MOTOR 1 1EN_A 
  analogWrite(5,180);//LEFT MOTOR 2  1EN_B
  analogWrite(6, 255);//RIGHT MOTOR 1 2EN_A 
  analogWrite(9, 255);//RIGHT MOTOR 2  2EN_B
  digitalWrite(2, LOW);//left motors REVERSE
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8,HIGH);
  digitalWrite(10, LOW);//right motors REVERSE
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(time);
}

void forward_left(int time){
  analogWrite(3, 255);//LEFT MOTOR 1 1EN_A 
  analogWrite(5,255);//LEFT MOTOR 2  1EN_B
  analogWrite(6, 180);//RIGHT MOTOR 1 2EN_A 
  analogWrite(9, 180);//RIGHT MOTOR 2  2EN_B
  digitalWrite(2, HIGH);//left motors FORWARD
  digitalWrite(4, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8,LOW);
  digitalWrite(10, HIGH);//right motors FORWARD
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(time);
}

void reverse_left(int time){
   analogWrite(3, 255);//LEFT MOTOR 1 1EN_A 
  analogWrite(5,255);//LEFT MOTOR 2  1EN_B
  analogWrite(6, 180);//RIGHT MOTOR 1 2EN_A 
  analogWrite(9, 180);//RIGHT MOTOR 2  2EN_B
  digitalWrite(2, LOW);//left motors REVERSE
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8,HIGH);
  digitalWrite(10, LOW);//right motors REVERSE
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(time);
}

void reset(){
  digitalWrite(2, LOW);//left motors HALT
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8,LOW);
  digitalWrite(10, LOW);//right motors HALT
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 1: forward(time); break;
     case 2: reverse(time); break;
     case 3: right(time); break;
     case 4: left(time); break;

     //combination command
     case 6: forward_right(time); break;
     case 7: forward_left(time); break;
     case 8: reverse_right(time); break;
     case 9: reverse_left(time); break;

     default: Serial.print("InValid Command\n");
    }
}
