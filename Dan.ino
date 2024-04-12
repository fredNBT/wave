
#include "pins.h"
#include "Params.h"
const int STEP = 6; // toggle to rotate the motor
const int rampMuli = 1;
bool direction = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_MTR_EN, OUTPUT); // Set the BG96 PowerPin as an output
  pinMode(PIN_MTR_PULS, OUTPUT); // Set the BG96 PowerPin as an output
  pinMode(PIN_MTR_DIR,OUTPUT);
  pinMode(PIN_BTN_ES1,INPUT);
  pinMode(PIN_BTN_RMT,INPUT);
  pinMode(PIN_BTN_SRV,INPUT);
  pinMode(PIN_BTN_LID,INPUT);
  digitalWrite(PIN_MTR_EN, LOW); //Pull the pin high 
  digitalWrite(PIN_MTR_DIR, HIGH);
  resetDevice();
  
}
void loop() {
  Serial.println(digitalRead(PIN_BTN_LID));
  
  if (digitalRead(PIN_BTN_SRV) == LOW || digitalRead(PIN_BTN_RMT) == LOW || digitalRead(PIN_BTN_LID) == LOW){
    startWaves();
  }
  delay(100);
}

void startWaves(){
  for (int i = 0; i < numberOfWaves; i++) {
    Serial.println(i);
    beginWave();
    if(digitalRead(PIN_BTN_LID) == LOW){return;}
    Serial.println("waveDone");
    if (direction == true){
      direction = false;
      digitalWrite(PIN_MTR_DIR, HIGH);
    }
    else{
      direction = true;
      digitalWrite(PIN_MTR_DIR, LOW);
      delay(waveDelay);
    }
    
  }
  resetDevice();
}

void beginWave(){
  Serial.println("in wave");
  int RampUpTime = RampUpDistance;
for (int i = 0; i < waveLength; i++) {
    if (RampUpTime > 0){RampUpTime-- ;}
    if (i > (waveLength - RampUpDistance)){RampUpTime++; RampUpTime++;}
    digitalWrite(STEP, HIGH);
    delayMicroseconds(Speed + RampUpTime);
    digitalWrite(STEP, LOW);
    delayMicroseconds(Speed + RampUpTime);
     if (digitalRead(PIN_BTN_ES2) == LOW || digitalRead(PIN_BTN_ES1) == LOW){
       resetDevice(); // this should never happen
      }
  }
}

void resetDevice(){
  Serial.println("restting");
  digitalWrite(PIN_MTR_DIR, HIGH);
  while(true){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(returnSpeen);
    digitalWrite(STEP, LOW);
    delayMicroseconds(returnSpeen);
        if (digitalRead(PIN_BTN_ES1) == LOW) //hit end stop 1 
        {
        Serial.println("EndStop1 Hit");
        digitalWrite(PIN_MTR_DIR, LOW);
        for (int i = 0; i < BackoffDistance; i++) {
            digitalWrite(STEP, HIGH);
            delayMicroseconds(returnSpeen);
            digitalWrite(STEP, LOW);
            delayMicroseconds(returnSpeen);
          }
          //loop();
        return;
        }
  }

}
