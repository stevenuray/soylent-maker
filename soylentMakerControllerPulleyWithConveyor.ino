#include <Servo.h>

const int blenderPwmPin = 9;
const int blenderRelayInputPin = 6;
const int conveyorPwmPin = 2;
const int MIN_SERVO_RANGE = 600;
const int MAX_SERVO_RANGE = 2400;

/* In order to keep the motor in sync with the target angle, there is a delay at the end of each cycle 
 * to allow the motor to catch up with the target angle.
 */
int directionSwitchDelayInMilliseconds = 3000;

const unsigned long blenderCycleInMilliseconds = 213000;

Servo conveyorServo;
const int MIN_CONVEYOR_POSITION = 600;
const int MAX_CONVEYOR_POSITION = 2400;
const int CONVEYOR_POWDER_FILL_POSITION = 1140;
const int CONVEYOR_POWDER_TRIGGER_POSITION = 980;
const int CONVEYOR_MIX_POSITION = 2130;
const int CONVEYOR_WATER_POSITION = 2100;

//Maximum time it takes for the conveyor to move from one end to another with a full load.
const int MAX_CONVEYOR_MOVE_IN_MILLISECONDS = 9000;
const unsigned long POWDER_FILL_TIME = 71000;

//general configuration
const unsigned int MIX_AND_FILL_CYCLES = 11;
const unsigned int MIX_SEQUENCES_PER_MIX_STAGE = 3;
const unsigned int MIX_SEQUENCES_PER_PLACEMENT_SEQUENCE = 3;
const unsigned long DRIP_TIME_IN_MILLISECONDS = 25000;

void setup() {
  Serial.begin(9600);  
  setupBlenderServo();
  moveBlenderToInitialPosition();
  setupConveyorServo();
  setupBlenderRelay();
  checkMixerPlacementSequence(MIX_SEQUENCES_PER_PLACEMENT_SEQUENCE);
  generalMixAndFillSequence(MIX_AND_FILL_CYCLES, MIX_SEQUENCES_PER_MIX_STAGE);
  mixSequences(20);
}

void loop() {
  
}

void hardShutdown(){
  
}



