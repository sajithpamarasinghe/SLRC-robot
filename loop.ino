
byte jmode = 1;
void voidLoop() {

  //getTowerBox();

  //boxNumber=getTowerBox();

  if (jmode == 1) {
    followLine();
    if ( allBlack()) {
      lineEnd = 1;
      mdrive(0, 0);
      delay(2000);
      jmode = 2;
    }
    else if (junctionDetected()) {
      mpu. update();
      currentAngle = -1 * mpu.getAngleZ();
      junctionAngle = currentAngle;
      encorderCount = 0;
      attachInterrupt(digitalPinToInterrupt(encorderPin), countEncorderDist, CHANGE);
      while (encorderCount < 80) {
        qtr.readCalibrated(sensorValues);
        if (sensorValues[0] < 500) {
          leftLine = 1;
        }
        if (sensorValues[11] < 500) {
          rightLine = 1;
        }
        mdrive(leftBaseSpd, rightBaseSpd);
      }
      detachInterrupt(digitalPinToInterrupt(encorderPin));
      encorderCount = 0;
      if (frontLineDetected()) {
        frontLine = 1;
      }
      else if (colourPatch()) {
        leftLine = 0;
        rightLine = 0;
        patchcolour = getColour();
      }
      mdrive(0, 0);
      jmode = 2;
    }
  }

  /***********************************************************************************************************************************************/

  else if (jmode == 2) {

    junction = getJunction();

    mdrive(0, 0);
    mpu. update();
    currentAngle = -1 * mpu.getAngleZ();
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print(currentAngle);
    display.setCursor(70, 0);
    display.print(currentAngle);
    display.display();

    display.setTextSize(2);
    display.setCursor(0, 20);
    display.print(junction);
    display.display();


    delay(3000);

    lineEnd = 0;
    leftLine = 0;
    rightLine = 0;
    frontLine = 0;
    patchcolour = 0;
    jmode = 1;



  }


  else if (jmode == 3) {
    //currentAngle-90
    lineEnd = 0;
    leftLine = 0;
    rightLine = 0;
    frontLine = 0;
    patchcolour = 0;
    jmode = 1;
    //    while (intitialAngle >= (currentAngle - 90)) {
    //      mdrive(-leftBaseSpd, rightBaseSpd);
    //
    //      mpu. update();
    //      intitialAngle = -1 * mpu.getAngleZ();
    //
    //      display.clearDisplay();
    //      display.setTextSize(1);
    //      display.setCursor(0, 0);
    //      display.print(intitialAngle);
    //      display.setCursor(60, 0);
    //      display.print(currentAngle);
    //      display.display();
    //
    //    }
    //    mdrive(0, 0);
    delay(10000);


  }








  //  turnLeft();
  //  turnRight();
  //  passJunction();
  //  turn back();





  /*...............................................................................................................................*/
  //  if ((millis() - timer) > 5)
  //  {
  //    display.clearDisplay();
  //    display.setTextSize(1);
  //    display.setCursor(0, 0);
  //    display.print(error);
  //
  //    display.setCursor(85, 0);
  //    display.print(whiteIrCount);
  //
  //    display.setCursor(0, 20);
  //    display.print(intitialAngle);
  //    display.setCursor(60, 20);
  //    display.print(currentAngle);
  //
  //    display.setTextSize(1);
  //    display.setCursor(0, 35);
  //    display.print(leftBaseSpd + dif);
  //
  //    display.setCursor(60, 35);
  //    display.print(rightBaseSpd - dif);
  //
  //
  //
  //    display.display();
  //    timer = millis();
  //  }
}
