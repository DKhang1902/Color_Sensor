int S0 = 4;
int S1 = 5;
int S2 = 6;
int S3 = 7;
int sensorOut = 8;
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;

void setup(){
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

//Setting frequency scaling to 20%
digitalWrite(S0, HIGH);
digitalWrite(S1, LOW);

Serial.begin(9600);
}

void loop(){
  //Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  //Reading the output frequency
  redfrequency = pulseIn(sensorOut, LOW);

  //Print the value on serial monitor
  Serial.print("R= ");
  Serial.print(redfrequency);//printing red LED frequency
  Serial.print(" ");
  delay(100);

//Setting Green filtered photodiodes to be read
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);

//Reading the output frequency
greenfrequency = pulseIn(sensorOut, LOW);

//Printing the value on the serial monitor
Serial.print("G= ");
Serial.print(greenfrequency);
Serial.print(" ");
delay(100);

//Setting blue filtered photodiodes to read
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);

//Reading the output frequency
bluefrequency = pulseIn(sensorOut, LOW);

//Printing the value on the serial monitor
Serial.print("B= ");
Serial.print(bluefrequency);
Serial.println(" ");
delay(100);

//Find the color
if (redfrequency > 10 && redfrequency < 30){
  Serial.println("IT's RED");
}
else if (bluefrequency > 20 && bluefrequency <40){
  Serial.println("IT's BLUE");
}
else if (greenfrequency >20 && greenfrequency <40){
  Serial.println("It's GREEN");
}
else{
  Serial.println("NO COLOR DETECTED");
}
delay(500);
}
