const int triggerPin = 11;
const int echoPin = 10;
const int flamePin = 7; 

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(flamePin, INPUT);
}

void loop() {
  // Send a trigger pulse
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
 
  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the speed of sound
  // Distance = (Duration / 2) * Speed of Sound (in cm/us)
  float distance = (duration * 0.034) / 2;

  // Print the distance to the serial monitor
  if(distance <10 && distance >5){
    Serial.println("Half Filled");
  }else if(distance < 5 && distance > 1){
    Serial.println("Over Filled");
  }else if(distance>10){
    Serial.println("Empty");
  }


// Read the digital value from the flame sensor
  int flameValue = digitalRead(flamePin);
   if (flameValue == LOW) {
    // Flame detected
    Serial.println("Flame detected!");
  } else {
    // No flame detected
    Serial.println("No flame detected.");
  }

  delay(1000);  // Wait for a second before taking the next measurement
}
