void moveConveyorToBlender(){
  conveyorServo.write(CONVEYOR_MIX_POSITION);
}

void moveConveyorToWater(){
  conveyorServo.write(CONVEYOR_WATER_POSITION);
}

void moveConveyorToPowderTrigger(){
  conveyorServo.write(CONVEYOR_POWDER_TRIGGER_POSITION);
}

void moveConveyorToPowderFill(){
  conveyorServo.write(CONVEYOR_POWDER_FILL_POSITION);
}

void setupConveyorServo(){  
  conveyorServo.attach(conveyorPwmPin);
}



