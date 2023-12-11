#include <NewPing.h>
#include <Servo.h>
#include <Wire.h>
#include <QTRSensors.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050_light.h>
#include "Adafruit_TCS34725.h"

#define left_front 3
#define left_back 4
#define right_front 5
#define right_back 6

#define grabServoPin 9
#define liftServoPin 10
#define armSwitch 53
#define startButton 8
#define encorderPin 19                  //interupt



#define frontEcho 32
#define frontTrig 30

#define backEcho 46
#define backTrig 48

#define left1Echo 52
#define left1Trig 50

#define left2Echo 44
#define left2Trig 42

#define right1Echo 34
#define right1Trig 36

#define right2Echo 38
#define right2Trig 40




#define leftBaseSpd 255
#define rightBaseSpd 248

Adafruit_SSD1306 display(128, 64, &Wire);
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
MPU6050 mpu(Wire);
QTRSensors qtr;


NewPing frontSensor(frontTrig, frontEcho, 50);
NewPing backSensor(backTrig, backEcho, 50);
NewPing left1Sensor(left1Trig, left1Echo, 50);
NewPing left2Sensor(left2Trig, left2Echo, 50);
NewPing right1Sensor(right1Trig, right1Echo, 50);
NewPing right2Sensor(right2Trig, right2Echo, 50);

float durationFrontSensor, distanceFrontSensor;
float durationBackSensor, distanceBackSensor;
float durationLeft1Sensor, distanceLeft1Sensor;
float durationLeft2Sensor, distanceLeft2Sensor;
float durationRight1Sensor, distanceRight1Sensor;
float durationRight2Sensor, distanceRight2Sensor;


Servo grabServo;
Servo liftServo;
int pos;
#define boxTightness 0  //.................................................................................increse value to increase grip
int armMode = 0;
bool armSwitchState;
int boxNumber = 0;



float kp = 0.08;//0.1
float kd = 0.04;//0.07
#define advanceDis 75
#define backDis -19
#define turnBrake 36



float lastErr;
float dif;

byte whiteIrCount = 0;
const uint8_t SensorCount = 12;
uint16_t sensorValues[SensorCount];
byte gammatable[256];
unsigned long timer = 0;
float red, green, blue;
//int ir [12] = {A15, A14, A13, A12, A11, A10, A9, A8, A7, A6, A5, A4};

int error = 0;




bool lineEnd = 0;
bool leftLine = 0;
bool rightLine = 0;
bool frontLine = 0;
byte patchcolour = 0;

String junctionArray[] = {"END", "ENDLEFT", "ENDRIGHT",  "CROSS", "ENDT", "CONTLEFT", "CONTRIGHT",  "RED", "GREEN", "BLUE"};
String junction;



//int angle = 0;

int currentAngle;
int junctionAngle;



unsigned int encorderCount = 0;
int buttonPushCounter = 0;
bool encorderState = 0;
bool lastEncorderState = 0;

bool displayOn = 1;


void setup() {

  grabServo.attach(grabServoPin);
  liftServo.attach(liftServoPin);
  liftServo.write(35);
  delay(500);
  grabServo.write(145);
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]) {
    A15, A14, A13, A12, A11, A10, A9, A8, A7, A6, A5, A4
  }, SensorCount);


  pinMode(26, OUTPUT);//colour sensor led

  pinMode(left_front, OUTPUT);
  pinMode(left_back, OUTPUT);
  pinMode(right_front, OUTPUT);
  pinMode(right_back, OUTPUT);

  pinMode(armSwitch, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);
  pinMode(encorderPin, INPUT);

  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(SSD1306_WHITE);
  tcs.begin();
  digitalWrite(26, LOW);//colour sensor led


  display.setTextSize(2);
  display.setCursor(0, 5);
  display.clearDisplay();


  display.println(F("gyro calibrating"));
  display.display();
  mpu.calcGyroOffsets();                          // This does the calibration
  delay(500);

  display.clearDisplay();                        //print ir calibrating
  display.setCursor(0, 5);
  display.println("ir calibrating");
  display.display();

  for (uint16_t i = 0; i < 200; i++)             // ir calibrating
  {
    qtr.calibrate();
  }



  display.clearDisplay();                        //print press start button
  display.setCursor(0, 5);
  display.println("press start button");
  display.display();


}



int hanoiPosition[2] = {0, 0};
int lastHanoiPosition[2] = {0, 0};
byte box = 0;




String junctionType = "null";
bool startBox = 1;
int mode = 0;







void loop() {

  if (mode == 0) {

    if (digitalRead(startButton) == 0) {
      mode = 200;

    }
  }

  if (mode == 200) {

    advance(100);
    encorderCount = 0;
    mode = 1;

  }

  if (mode == 1) {
    followLine();
    if (whiteIrCount >= 8 ) {
      advance(40);//37
      mdrive(0, 0);
      turnRightOne();
      delay(500);
      mode = 2;
    }
  }
  if (mode == 2) {


    hanoiArea();
  }

  //voidLoop();

}
