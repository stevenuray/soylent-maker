void turnOnBlender(){
  digitalWrite(blenderRelayInputPin, HIGH);
  Serial.println("Blender ON");
}

void turnOffBlender() {
  digitalWrite(blenderRelayInputPin, LOW);
  Serial.println("Blender OFF");  
}

void setupBlenderRelay() {
  pinMode(blenderRelayInputPin, OUTPUT);
  digitalWrite(blenderRelayInputPin, LOW);
}

