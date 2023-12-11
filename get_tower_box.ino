//getTowerBox()


byte checkBox1stPosition() {
  for (pos = 145; pos > 90; pos--) {
    grabServo.write(pos);
    delay(10);
    armSwitchState = digitalRead(armSwitch);
    if (armSwitchState == 0) {
      grabServo.write(pos - boxTightness);
      delay(100);
      if (pos <= 96) {
        return 3;
      } else if (pos >= 97 && pos <= 102) {
        return 2;
      } else if (pos >= 103) {
        return 1;
      }
    }
  }
}


void dropBox(byte dropf) {
  if (dropf == 1) {
    liftServo.write(36);
    delay(1000);
    grabServo.write(145);
    delay(300);
    liftServo.write(180);
    delay(400);

  }
  if (dropf == 2) {

    liftServo.write(102);
    delay(800);
    grabServo.write(145);
    delay(500);
    liftServo.write(180);
    delay(300);

  }
  if (dropf == 3) {
    liftServo.write(168);
    delay(400);
    grabServo.write(145);
    delay(500);
    liftServo.write(180);
    delay(200);
  }
}
void getBoxReady(byte getf) {
  if (getf == 1) {
    grabServo.write(145);
    delay(500);
    liftServo.write(34);
    delay(400);
  }
  if (getf == 2) {
    grabServo.write(145);
    delay(500);
    liftServo.write(100);
    delay(400);
  }
  if (getf == 3) {
    grabServo.write(145);
    delay(500);
    liftServo.write(166);
    delay(400);
  }
}

byte getBox() {
  for (pos = 145; pos > 90; pos--) {
    grabServo.write(pos);
    delay(10);
    armSwitchState = digitalRead(armSwitch);
    if (armSwitchState == 0) {
      grabServo.write(pos - boxTightness);
      delay(100);
      liftServo.write(180);

      if (pos <= 96) {
        return 3;
      } else if (pos >= 97 && pos <= 102) {
        return 2;
      } else if (pos >= 103) {
        return 1;
      }
    }
  }
}


void releaseBox() {

  liftServo.write(35);
  delay(600);
  grabServo.write(145);
  delay(300);
  liftServo.write(100);
  delay(1000);

}
