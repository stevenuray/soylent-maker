void generalMixAndFillSequence(unsigned int cycleCount, unsigned int mixSequencesPerMixStep){
  for(int i = 0; i < cycleCount; i++){
    powderFillSequence();
    mixSequences(mixSequencesPerMixStep);
  }
}

void checkMixerPlacementSequence(unsigned int mixSequencesPerPlacementSequence){
  printStepTimestamp("Check Mixer Placement Start");
  printStepTimestamp("Moving Conveyor To Port Start");
  moveConveyorToBlender();
  delay(MAX_CONVEYOR_MOVE_IN_MILLISECONDS);
  printStepTimestamp("Moving Conveyor To Port End");
  printStepTimestamp("Waiting for mixer placement adjustments start");
  for(int i = 0; i < mixSequencesPerPlacementSequence; i++){
    mixSequence();
  }
  printStepTimestamp("Waiting for mixer placement adjustments start");
  printStepTimestamp("Check Mixer Placement End");
}

void powderFillSequence() {
  printStepTimestamp("Powder fill sequence start");
  switchPulleyDirectionToUp();
  delay(10000);
  printStepTimestamp("Moving conveyor to powder start");
  moveConveyorToPowderTrigger();
  delay(MAX_CONVEYOR_MOVE_IN_MILLISECONDS);
  moveConveyorToPowderFill();
  printStepTimestamp("Moving conveyor to powder end");
  waitForPowderFill();
  printStepTimestamp("Moving conveyor to blender start");
  moveConveyorToBlender();  
  delay(MAX_CONVEYOR_MOVE_IN_MILLISECONDS);
  printStepTimestamp("Moving conveyor to blender end");
  printStepTimestamp("Powder fill sequence end");  
}

void waitForPowderFill() {
  printStepTimestamp("Waiting for powder fill start");
  delay(POWDER_FILL_TIME);  
  printStepTimestamp("Waiting for powder fill end");
}

void mixSequence() {
  printStepTimestamp("Mix sequence start");
  switchPulleyDirectionToHighBlendPosition();  
  delay(5000);
  switchPulleyDirectionToLowBlendPosition();
  delay(5000);
  printStepTimestamp("Mix sequence end"); 
}

void mixSequences(unsigned int sequenceCount) {
  turnOnBlender();
  for(int i = 0; i < sequenceCount; i++){
    printStepTimestamp("Mix sequence count is: " + (String) (i + 1));
    mixSequence();
  }
  turnOffBlender();
  switchPulleyDirectionToUp();
  delay(5000);
  delay(DRIP_TIME_IN_MILLISECONDS);
}

void gracefulShutdown(){
  printStepTimestamp("Graceful shutdown start");
  switchPulleyDirectionToUp();
  delay(10000);
  delay(MAX_CONVEYOR_MOVE_IN_MILLISECONDS);
  switchPulleyDirectionToBottom();
  printStepTimestamp("Graceful shutdown end");
}
