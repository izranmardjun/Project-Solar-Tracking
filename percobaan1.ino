#include <Servo.h> 
Servo servo1;
Servo servo2;
int pos1 = 0;
int pos2 = 0;
int right = 0;
int left = 0;
int centre = 0;
int up = 0;
int down = 0;

int ldr1 = 0;
int ldr2 = 1;
int ldr3 = 2;
int ldr4 = 3;
int ldr5 = 4;
 
void setup() 
{ 
servo1.attach(10);
servo1.write(90);

servo2.attach(9);
servo2.write(90);
 pinMode(ldr1, INPUT);
 pinMode(ldr2, INPUT);
 pinMode(ldr3, INPUT);
 pinMode(ldr4, INPUT);
 pinMode(ldr5, INPUT);
 Serial.begin(9600);
 
}

void loop ()
{
  pos1 = servo1.read();
  pos2 = servo2.read();
  int right = analogRead(ldr2);
  int centre = analogRead(ldr3);
  int left = analogRead(ldr1);
  int up = analogRead(ldr5);
  int down = analogRead(ldr4);

	 
if (pos2 < 90) {
  if(right > centre && left < centre)
  {
    servo1.write(pos1 +1);
    delay(10);
  }
  else if (left > centre && right < centre)
  {
    servo1.write(pos1 -1);
    delay(10);
  }
  else
  {
    servo1.write(pos1);
  }
}

if (pos2 > 90 ) {
  if(right > centre && left < centre)
  {
    servo1.write(pos1 -1);
    delay(10);
  }
  else if (left > centre && right < centre)
  {
    servo1.write(pos1 +1);
    delay(10);
  }
  else
  {
    servo1.write(pos1);
  }
}

if(up > centre && down < centre)
  {
    servo2.write(pos2 +1);
    delay(10);
  }
else if (down > centre && up < centre)
  {
  servo2.write(pos2 -1);
  delay(10);
  }
else
{
  servo2.write(pos2);
}


//# debug posisi untuk mengetahui nilai tiap sensor
Serial.print("sensor KANAN = ");
Serial.println(right);
Serial.print("sensor KIRI = ");
Serial.println(left);

Serial.print("sensor TENGAH = ");
Serial.println(centre);

Serial.print("sensor ATAS = ");
Serial.println(up);
Serial.print("sensor BAWAH = ");
Serial.println(down);

Serial.println("");

Serial.print("Nilai servo BAWAH  -->> ");
Serial.print(pos1);

Serial.print(" ||    Nilai servo ATAS  ->> ");
Serial.print(pos2);
Serial.println("");
delay(5);
}
