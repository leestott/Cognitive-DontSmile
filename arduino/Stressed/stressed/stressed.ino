#include <Servo.h>

//define the servo names

Servo cameraservo; //servo to control the camera
Servo gunservo; //servo to control elastic band gun movement
Servo triggerservo; //servo to fire the elastic band gun

String readString, n1, n2, n3;

//Attached Pin Number for each servo format is servo.attach(pin) wiring the servo Using some single strand hook up wire, connect the black wire to one of the Arduino 0V pins.
//Connect the red wire (center wire) to the Arduino 5V pin. And finally connect the orange/white wire to pin number.

void setup() {
  cameraservo.attach(2); //servo on digital pin 2
  gunservo.attach(3); //servo on digital pin 2
  triggerservo.attach(4); //servo on digital pin 4
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
   delay(10);  
   if (Serial.available() >0) {
     char c = Serial.read();
     readString += c;
   }
 }

 if (readString.length() > 0) {
     Serial.println(readString);
       
     n1 = readString.substring(0, 3);
     n2 = readString.substring(3, 6);
     n3 = readString.substring(6, 9);
     
     Serial.println(n1);
     Serial.println(n2);
     Serial.println(n3);
     
     int pos1; 
     int pos2;
     int pos3;
     
     char carray1[6];
     n1.toCharArray(carray1, sizeof(carray1));
     pos1 = atoi(carray1);
     
     char carray2[6];
     n2.toCharArray(carray2, sizeof(carray2));
     pos2 = atoi(carray2);

     char carray3[6];
     n3.toCharArray(carray3, sizeof(carray3));
     pos3 = atoi(carray3);
     
     //turning the servo to the positios 
     cameraservo.write(pos1);
     triggerservo.write(pos2);
     gunservo.write(pos3);
   readString="";
 } 
}

