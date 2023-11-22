const int micIn = 34;
const int bits = 12;

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(bits);
}

void loop() {
  // read the analog
  int analogValue = analogRead(micIn);
  
  // print out the values you read:
  Serial.println(String(analogValue));
}
