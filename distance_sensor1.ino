
#include <Servo.h>

int pos = 0;
Servo servo_9;
const int trig_Pin = 6;  //Initialize I/O pins
const int echo_Pin = 5;
long duration;  //Since PulseIn return an unsigned Long 
int distance;  //To save the distance

void setup()
{
  servo_9.attach(9);
  pinMode(echo_Pin, INPUT);      //Echo pin as Input
  pinMode(trig_Pin, OUTPUT);   //Trigger pin as Output
  Serial.begin(9600);   //Initialize Serial communication
}

void loop(){
 
  digitalWrite(trig_Pin, LOW); //Make Trigger pin Low at start
  delayMicroseconds(2);
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10);  //Make Trigger pin High for 10 uS to start sending the pulse
  digitalWrite(trig_Pin, LOW);
  duration = pulseIn(echo_Pin, HIGH);  //Save the time it took ultrasonic wave to come back
  distance = duration*0.034/2; 
     Serial.print("Distance: ");
     Serial.println(distance);
  
   if (distance<50)
{
   Serial.println("Rotate Forwards");
    // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 90; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
    Serial.println("Rotate Backwards"); 
  for (pos = 90; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
 }
   } else {
   Serial.print("distance: ");
   for (pos = 0; pos <= 0; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
   }
}
}
