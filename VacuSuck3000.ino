/*Using LVGL with Arduino requires some extra steps:

 *Be sure to read the docs here: https://docs.lvgl.io/master/integration/framework/arduino.html  */

#include <lvgl.h>
#if LV_USE_TFT_ESPI
  #include <TFT_eSPI.h>
#endif

/*Setup Arduino Pins*/
  int Suck_pin = A0;
  int Q1pin = 2;
  int Q2pin = 3;
  int Q3pin = 4;
  int Q4pin = 5;
  int HVpin = 6;
  int DPDTpin = 7;

/*Setup Arduino Variables*/
  int SuckVal;

/*Set to your screen resolution and rotation*/
  #define TFT_HOR_RES   320
  #define TFT_VER_RES   240
  #define TFT_ROTATION  LV_DISPLAY_ROTATION_0


void setup()
{
  pinMode(Suck_pin, INPUT);  
  pinMode(Q1pin, OUTPUT);
  pinMode(Q2pin, OUTPUT);
  pinMode(Q3pin, OUTPUT);
  pinMode(Q4pin, OUTPUT);
  pinMode(HVpin, OUTPUT);
  pinMode(DPDTpin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  SuckVal = analogRead(Suck_pin);

  digitalWrite(Q1pin, LOW);
  digitalWrite(Q2pin, LOW);
  digitalWrite(Q3pin, LOW);
  digitalWrite(Q4pin, LOW);
  digitalWrite(HVpin, LOW);
  digitalWrite(DPDTpin, LOW);

  Serial.print("Transducer Reading: ");
  Serial.println(SuckVal);
  Serial.println("All Off");
  delay(1000);

  digitalWrite(Q1pin, HIGH);
  Serial.println("Q1");
  delay(1000);

  digitalWrite(Q1pin, LOW);
  digitalWrite(Q2pin, HIGH);
  Serial.println("Q2");
  delay(1000);

  digitalWrite(Q2pin, LOW);
  digitalWrite(Q3pin, HIGH);
  Serial.println("Q3");
  delay(1000);

  digitalWrite(Q3pin, LOW);
  digitalWrite(Q4pin, HIGH);
  Serial.println("Q4");
  delay(1000);

  digitalWrite(Q4pin, LOW);
  digitalWrite(HVpin, HIGH);
  Serial.println("HighVoltage");
  delay(1000);

  digitalWrite(HVpin, LOW);
  digitalWrite(DPDTpin, HIGH);
  Serial.println("Reverse");
  delay(1000);

}

