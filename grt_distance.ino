float getDistFront() {
  durationFrontSensor   = frontSensor.ping();
  distanceFrontSensor   = (durationFrontSensor / 2) * 0.0343;
  return distanceFrontSensor;
}
float getDistBack() {
  durationBackSensor    = backSensor.ping();
  distanceBackSensor    = (durationBackSensor / 2) * 0.0343;
  delay(500);
  return distanceBackSensor;
}
float getDistLeft1() {
  durationLeft1Sensor   = left1Sensor.ping();
  distanceLeft1Sensor   = (durationLeft1Sensor / 2) * 0.0343;
  return distanceLeft1Sensor;
}
float getDistLeft2() {
  durationLeft2Sensor   = left2Sensor.ping();
  distanceLeft2Sensor   = (durationLeft2Sensor / 2) * 0.0343;
  return distanceLeft2Sensor;
}
float getDistRight1() {
  durationRight1Sensor  = right1Sensor.ping();
  distanceRight1Sensor  = (durationRight1Sensor / 2) * 0.0343;
  return distanceRight1Sensor;
}
float getDistRight2() {
  durationRight2Sensor  = right2Sensor.ping();
  distanceRight2Sensor  = (durationRight2Sensor / 2) * 0.0343;
  return distanceRight2Sensor;
}
