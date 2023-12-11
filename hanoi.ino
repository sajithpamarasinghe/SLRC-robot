void hanoiArea() {
  followLine();
  if (junctionDetected()) {

    advance(advanceDis);
    turnLeft();

    while (!squareDetected()) {
      followLine();
    }

    // advance(-1*backDis);
    stopBot();

    box = checkBox1stPosition();
    if (box == 1) {
      liftServo.write(50);
      delay(100);
    } else {
      grabServo.write(145);
      delay(300);
      liftServo.write(100);
      delay(500);
      advance(backDis);
    }

    hanoiPosition[0] = 1;
    hanoiPosition[1] = -1;

    buildTower();
    /******************************************************************************************************/
    for (pos = 145; pos > 90; pos--) {
      grabServo.write(pos);
      delay(5);
      armSwitchState = digitalRead(armSwitch);
      if (armSwitchState == 0) {
        grabServo.write(pos - boxTightness);
        delay(50);

      }
    }
    liftServo.write(180);
    transferTower();






    display.clearDisplay();
    display.setTextSize(4);
    display.setCursor(0, 0);
    display.print("OK");
    display.display();
    mdrive(0, 0);
    delay(1000000);

  }

}


void buildTower() {
  if (box == 1) {

    goAndDropBox(3/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
    goAndCollectBox(2/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
    if (box == 2) {
      goAndDropBox(3/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/, 1);
      goAndCollectBox(3/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 3/*bottom or middle or top*/, 0);
      return;
    } else {
      releaseBox();
      goAndCollectBox(3/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/, 1);
      goAndCollectBox(2/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 3/*bottom or middle or top*/, 0);
      return;

    }
  }
  else if (box == 2) {

    goAndCollectBox(2/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
    if (box == 1) {
      goAndDropBox(3/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
      goAndCollectBox(1/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/, 1);
      goAndCollectBox(3/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 3/*bottom or middle or top*/, 0);
      return;
    }
    else if (box == 3) {
      releaseBox();
      goAndCollectBox(3/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
      goAndCollectBox(1/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/, 1);
      goAndCollectBox(2/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 3/*bottom or middle or top*/, 0);
      return;
    }


  }
  else if (box == 3) {
    goAndCollectBox(2/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
    if (box == 1) {
      goAndDropBox(3/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
      goAndCollectBox(3/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/, 1);
      goAndCollectBox(1/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 3/*bottom or middle or top*/, 0);
      return;
    }
    if (box == 2) {
      releaseBox();
      goAndCollectBox(3/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
      goAndCollectBox(2/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/, 1);
      goAndCollectBox(1/*position*/, -1/*left or right*/, 1/*bottom or middle or top*/);
      goAndDropBox(3/*position*/, +1/*left or right*/, 3/*bottom or middle or top*/, 0);
      return;
    }

  }

}

void transferTower() {
  goAndDropBox(2/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
  goAndCollectBox(3/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/);
  goAndDropBox(1/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
  goAndCollectBox(2/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/);
  goAndDropBox(1/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/, 1);
  goAndCollectBox(3/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/);
  goAndDropBox(2/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
  goAndCollectBox(1/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/);
  goAndDropBox(3/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/, 1);
  goAndCollectBox(1/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/);
  goAndDropBox(2/*position*/, +1/*left or right*/, 2/*bottom or middle or top*/, 1);
  goAndCollectBox(3/*position*/, +1/*left or right*/, 1/*bottom or middle or top*/);
  goAndDropBox(2/*position*/, +1/*left or right*/, 3/*bottom or middle or top*/, 1);


}
