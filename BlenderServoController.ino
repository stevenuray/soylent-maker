/* The motor has to do more work to move the mixer up the beam, 
give it more time to get there or the target angle will increase,
faster than the motor can keep up.
*/
const int upDirectionCycleTimeInMilliseconds = 11000;
const int downDirectionCycleTimeInMilliseconds = 6000;

//Variables that determine the state of the app and motor.
String currentBlenderDirection = "UP";

Servo pulleyServo;
const int MIN_PULLEY_POSITION = 975;
const int MAX_PULLEY_POSITION = 2000;
const int LOW_BLEND_POSITION = 1250;
const int HIGH_BLEND_POSITION = 1650;
unsigned long pulleyDirectionSwitchTime = 0;
unsigned long blenderCycleEndTime = 0;
String pulleyDirection = "UP";

void setupBlenderServo(){  
  pulleyServo.attach(blenderPwmPin);  
}

void moveBlenderToInitialPosition(){
  printStepTimestamp("Initial Blender Position Start");
  switchPulleyDirectionToUp();
  delay(upDirectionCycleTimeInMilliseconds);
  printStepTimestamp("Initial Blender Position End");
}

void shutdownBlender(){
  pulleyServo.write(MAX_PULLEY_POSITION);
  delay(12500);
  pulleyServo.write(MIN_PULLEY_POSITION);
}

void switchPulleyDirectionIfNecessary(){
  if(millis() > pulleyDirectionSwitchTime){
    if(pulleyDirection == "LOW BLEND"){
      switchPulleyDirectionToHighBlendPosition();
      Serial.println("Switch Time!");
      Serial.println("Pulley Direction: " + (String) pulleyDirection);
      Serial.println("Next switch time is: " + (String) pulleyDirectionSwitchTime);
      return;
    }

    if(pulleyDirection == "HIGH BLEND"){
      switchPulleyDirectionToLowBlendPosition();
      Serial.println("Switch Time!");
      Serial.println("Pulley Direction: " + (String) pulleyDirection);
      Serial.println("Next switch time is: " + (String) pulleyDirectionSwitchTime);
    }    
  }
}

void switchPulleyDirectionToUp(){
  pulleyDirection = "UP";
  pulleyDirectionSwitchTime = millis() + upDirectionCycleTimeInMilliseconds;
  pulleyServo.write(MAX_PULLEY_POSITION);
  delay(10);
}

void switchPulleyDirectionToBottom(){
  pulleyDirection = "DOWN";
  pulleyDirectionSwitchTime = millis() + downDirectionCycleTimeInMilliseconds;
  pulleyServo.write(MIN_PULLEY_POSITION);
  delay(10);
}

void switchPulleyDirectionToLowBlendPosition(){
  pulleyDirection = "LOW BLEND";
  pulleyDirectionSwitchTime = millis() + downDirectionCycleTimeInMilliseconds;
  pulleyServo.write(LOW_BLEND_POSITION);
  delay(10);
}

void switchPulleyDirectionToHighBlendPosition(){
  pulleyDirection = "HIGH BLEND";
  pulleyDirectionSwitchTime = millis() + upDirectionCycleTimeInMilliseconds;
  pulleyServo.write(HIGH_BLEND_POSITION);
  delay(10);
}

