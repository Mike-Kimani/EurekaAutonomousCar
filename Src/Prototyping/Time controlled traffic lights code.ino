 int redCar = 2;
int yellowCar = 3;
int greenCar = 4;




void setup() {
  pinMode(redCar, OUTPUT);
pinMode(yellowCar, OUTPUT);
pinMode(greenCar, OUTPUT);

//turn on the red light

digitalWrite(redCar, HIGH);
digitalWrite(yellowCar, LOW);
digitalWrite(greenCar, LOW);


Serial.begin(9600);
  

}

void loop() {
  
digitalWrite(greenCar, HIGH);
delay(100);
digitalWrite(greenCar, LOW);
delay(100);
digitalWrite(greenCar, HIGH);
delay(100);
digitalWrite(greenCar, LOW);
delay(100);
digitalWrite(greenCar, HIGH);
delay(100);
digitalWrite(greenCar, LOW);
delay(100);
digitalWrite(greenCar, HIGH);
delay(100);
digitalWrite(greenCar, LOW);
delay(100);
digitalWrite(greenCar, HIGH);
delay(100);
digitalWrite(greenCar, LOW);
delay(100);
digitalWrite(greenCar, HIGH);
delay(100);
digitalWrite(greenCar, LOW);
delay(100);
digitalWrite(greenCar, HIGH);
delay(100);
digitalWrite(greenCar, LOW);
delay(100);
digitalWrite(greenCar, HIGH);
delay(100);  

digitalWrite(greenCar,LOW);
digitalWrite(yellowCar, LOW);
delay(5000);

digitalWrite(redCar, LOW);
digitalWrite(yellowCar, HIGH);
digitalWrite(greenCar, LOW);

delay(2000);
digitalWrite(greenCar, HIGH);
digitalWrite(yellowCar, LOW);
digitalWrite(redCar,LOW);

delay(7000);


 

}