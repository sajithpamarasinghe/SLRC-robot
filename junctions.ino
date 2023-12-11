bool  allBlack() {
  qtr.readCalibrated(sensorValues);
  if (sensorValues[0] > 500 &&
      sensorValues[1] > 500 &&
      sensorValues[2] > 500 &&
      sensorValues[3] > 500 &&
      sensorValues[4] > 500 &&
      sensorValues[5] > 500 &&
      sensorValues[6] > 500 &&
      sensorValues[7] > 500 &&
      sensorValues[8] > 500 &&
      sensorValues[9] > 500 &&
      sensorValues[10] > 500 &&
      sensorValues[11] > 500 ) {
    return 1;
  } else {
    return 0;
  }
}

bool  allWhite() {
  qtr.readCalibrated(sensorValues);
  if (sensorValues[0] < 500 &&
      sensorValues[1] < 500 &&
      sensorValues[2] < 500 &&
      sensorValues[3] < 500 &&
      sensorValues[4] < 500 &&
      sensorValues[5] < 500 &&
      sensorValues[6] < 500 &&
      sensorValues[7] < 500 &&
      sensorValues[8] < 500 &&
      sensorValues[9] < 500 &&
      sensorValues[10] < 500 &&
      sensorValues[11] < 500 ) {
    return 1;
  } else {
    return 0;
  }
}

bool  squareDetected() {
  qtr.readCalibrated(sensorValues);
  if (
    sensorValues[2] < 500 &&
    sensorValues[3] < 500 &&
    sensorValues[4] < 500 &&
    sensorValues[5] < 500 &&
    sensorValues[6] < 500 &&
    sensorValues[7] < 500 &&
    sensorValues[8] < 500 &&
    sensorValues[9] < 500  ) {
    return 1;
  } else {
    return 0;
  }
}


bool  junctionDetected() {
  qtr.readCalibrated(sensorValues);
  if (((sensorValues[0] < 500 || sensorValues[11] < 500) &&
       (sensorValues[5] < 500 || sensorValues[6] < 500)) ) {
    return 1;
  } else {
    return 0;
  }
}


bool  frontLineDetected() {
  qtr.readCalibrated(sensorValues);
  if ((sensorValues[0] > 500 && sensorValues[11] >  500) &&
      (sensorValues[4] <  500 ||
       sensorValues[5] <  500 ||
       sensorValues[6] <  500 ||
       sensorValues[7] <  500 )) {
    return 1;
  } else {
    return 0;
  }
}
bool  inLine() {
  qtr.readCalibrated(sensorValues);
  if (sensorValues[0] > 500 && sensorValues[11] >  500) {
    return 1;
  } else {
    return 0;
  }
}

bool  colourPatch() {
  qtr.readCalibrated(sensorValues);
  if (sensorValues[0] < 500 || sensorValues[1] <  500 && sensorValues[10] < 500 || sensorValues[11] <  500) {
    return 1;
  } else {
    return 0;
  }
}



String getJunction() {

  if ( lineEnd     == 1 &&
       leftLine    == 0 &&
       rightLine   == 0 &&
       frontLine   == 0 &&
       patchcolour == 0) {
    return junctionArray[0];//END
  }
  if (lineEnd     == 0 &&
      leftLine    == 1 &&
      rightLine   == 0 &&
      frontLine   == 0 &&
      patchcolour == 0) {
    return junctionArray[1];//ENDLEFT
  }
  if (lineEnd     == 0 &&
      leftLine    == 0 &&
      rightLine   == 1 &&
      frontLine   == 0 &&
      patchcolour == 0) {
    return junctionArray[2];//ENDRIGHT
  }
  if (lineEnd     == 0 &&
      leftLine    == 1 &&
      rightLine   == 1 &&
      frontLine   == 1 &&
      patchcolour == 0) {
    return junctionArray[3];//CROSS
  }
  if (lineEnd     == 0 &&
      leftLine    == 1 &&
      rightLine   == 1 &&
      frontLine   == 0 &&
      patchcolour == 0) {
    return junctionArray[4];//ENDT
  }
  if (lineEnd     == 0 &&
      leftLine    == 1 &&
      rightLine   == 0 &&
      frontLine   == 1 &&
      patchcolour == 0) {
    return junctionArray[5];//CONTLEFT
  }
  if (lineEnd     == 0 &&
      leftLine    == 0 &&
      rightLine   == 1 &&
      frontLine   == 1 &&
      patchcolour == 0) {
    return junctionArray[6];//CONTRIGHT
  }
  if (lineEnd     == 0 &&
      leftLine    == 0 &&
      rightLine   == 0 &&
      frontLine   == 0 &&
      patchcolour == 1) {
    return junctionArray[7];//RED
  }
  if (lineEnd     == 0 &&
      leftLine    == 0 &&
      rightLine   == 0 &&
      frontLine   == 0 &&
      patchcolour == 2) {
    return junctionArray[8];//GREEN
  }
  if (lineEnd     == 0 &&
      leftLine    == 0 &&
      rightLine   == 0 &&
      frontLine   == 0 &&
      patchcolour == 3) {
    return junctionArray[9];//BLUE
  }
}
