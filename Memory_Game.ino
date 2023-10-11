const int ledPin1 = 8;
const int ledPin2 = 9;
const int ledPin3 = 10;
const int ledPin4 = 11;
const int correctLed = 12;
const int wrongLed = 13;
const int buzzer = 7;
const int btn1 = 6;
const int btn2 = 5;
const int btn3 = 4;
const int btn4 = 3;

int arr[50];
int lightCount = 3;
float lightDuration = 1000;
int pressCount = 0;
int correctAnswer = 0;

unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

void setup() {
   for(int i = 8 ; i <= 13 ; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(7,OUTPUT);
  pinMode(A0,INPUT);
  for(int i = 6 ; i >= 3 ; i--){
    pinMode(i,INPUT);
  }
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  delay(300);
  Serial.println(" ");
  playSequence();
  pressCount = 0;
  correctAnswer = 0;
  while(pressCount < lightCount){
    currentMillis  = millis() - previousMillis;
    int btnPressed = listen();
    if(btnPressed != 0 && currentMillis > 500){
      if(btnPressed != arr[pressCount]){
        lightCount = 3;
        lightDuration = 1000;
        wrongSequenceAlarm();
        break;
      }
      else{
        correctSequenceAlarm();
        Serial.println("correct");
        if(pressCount == lightCount - 1){
          levelPassed();
          lightCount += 2;
          lightDuration -= 200;
          break;
        }
      }
      previousMillis = millis();
      pressCount++;
    } 
  }
  
} 

int listen(){ 
  if(digitalRead(btn1) == 1){
    return 8;
  }
  else if(digitalRead(btn2) == 1){
    return 9;
  }
  else if(digitalRead(btn3) == 1){
    return 10;
  }
  else if(digitalRead(btn4) == 1){
    return 11;
  }
  else {
    return 0;
  }
}

void playSequence(){
  int containerCount = 0;
   for(int i = 1 ; i <= lightCount ; i++){
    int toLitUp = random(8,12);
    Serial.println(containerCount);
    arr[containerCount] = toLitUp;
    containerCount++;
    digitalWrite(toLitUp,HIGH);
    Serial.println("Sequence " + String(i) + ":" + String(toLitUp));
    tone(buzzer,262);
    delay(lightDuration);
    digitalWrite(toLitUp,LOW);
    noTone(buzzer);
    delay(lightDuration);
  }
}

void wrongSequenceAlarm(){
  for(int i = 0 ; i <= 3 ; i++){
    digitalWrite(wrongLed,HIGH);
    tone(buzzer,31,100);
    delay(200);
    digitalWrite(wrongLed,LOW);
    noTone(buzzer);
  }
}

void correctSequenceAlarm(){
   for(int i = 0; i <= 3 ; i++){
    digitalWrite(correctLed,HIGH);
    tone(buzzer,2794,100);
    delay(50);
    digitalWrite(correctLed,LOW);
    noTone(buzzer);
  }
}

void levelPassed(){
  for(int i = 0; i <= 5 ; i++){
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin3,HIGH);
    digitalWrite(ledPin4,HIGH);
    tone(buzzer,2794,100);
    delay(100);
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    digitalWrite(ledPin4,LOW);
    noTone(buzzer);
    delay(100);
  }
}
