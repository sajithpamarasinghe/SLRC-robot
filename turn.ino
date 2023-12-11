int angleError;

void  turnLeft() {
  mpu. update();
  junctionAngle =  mpu.getAngleZ();
  do {
    mpu. update();
    currentAngle = mpu.getAngleZ();
    angleError = currentAngle - junctionAngle;
    mdrive(-leftBaseSpd, rightBaseSpd);
    //    display.clearDisplay();
    //    display.setTextSize(1);
    //    display.setCursor(0, 0);
    //    display.print(junctionAngle);
    //    display.setCursor(0, 15);
    //    display.print(currentAngle);
    //    display.setCursor(0, 45);
    //    display.print(angleError);
    //
    //    display.display();
  }
  while (angleError < 80);
  mdrive(leftBaseSpd, -rightBaseSpd);
  delay(100);
  mdrive(0, 0);

}

void  turnRight() {
  mpu. update();
  junctionAngle =  mpu.getAngleZ();
  do {
    mpu. update();
    currentAngle =  mpu.getAngleZ();
    angleError =   junctionAngle - currentAngle;
    mdrive(+leftBaseSpd, -rightBaseSpd);
    //    display.clearDisplay();
    //    display.setTextSize(1);
    //    display.setCursor(0, 0);
    //    display.print(junctionAngle);
    //    display.setCursor(0, 15);
    //    display.print(currentAngle);
    //    display.setCursor(0, 45);
    //    display.print(angleError);
    //
    //    display.display();
  }
  while (angleError < 75
        );
  mdrive(-leftBaseSpd, +rightBaseSpd);
  delay(turnBrake);
  mdrive(0, 0);

}

void  turnBack() {
  mpu. update();
  junctionAngle =  mpu.getAngleZ();
  do {
    mpu. update();
    currentAngle = mpu.getAngleZ();
    angleError = currentAngle - junctionAngle;
    mdrive(-leftBaseSpd, rightBaseSpd);
    //    display.clearDisplay();
    //    display.setTextSize(1);
    //    display.setCursor(0, 0);
    //    display.print(junctionAngle);
    //    display.setCursor(0, 15);
    //    display.print(currentAngle);
    //    display.setCursor(0, 45);
    //    display.print(angleError);
    //
    //    display.display();
  }
  while (angleError < 165);
  mdrive(leftBaseSpd, -rightBaseSpd);
  delay(turnBrake);
  mdrive(0, 0);

}

void stopBot() {


  mdrive(120, 105);
  delay(85);
  mdrive(-120, -105);
  delay(40);
  mdrive(0, 0);
}


void  turnRightOne() {

  mpu. update();
  junctionAngle =  mpu.getAngleZ();
  do {
    mpu. update();
    currentAngle =  mpu.getAngleZ();
    angleError =   junctionAngle - currentAngle;
    mdrive(+leftBaseSpd, 0);
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print(junctionAngle);
    display.setCursor(0, 15);
    display.print(currentAngle);
    display.setCursor(0, 45);
    display.print(angleError);

    display.display();
  }
  while (angleError < 60 );
  mdrive(-leftBaseSpd, 0);
  delay(turnBrake);
  mdrive(0, 0);

}
