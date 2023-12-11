byte getMode = 0;;
void goAndCollectBox(byte nextjpos/*position 0,1,2 */, int side/*left -1 or right +1 */, byte getFloor /*bot 1 or mid 2 or top 3*/) {

  advance(backDis);
  turnBack();
  while (!junctionDetected()) {
    followLine();
  }

  advance(advanceDis);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(hanoiPosition[0]);
  display.setCursor(40, 0);
  display.print(lastHanoiPosition[0]);
  display.setCursor(80, 0);
  display.print(nextjpos);
  display.display();

  if (hanoiPosition[0] > nextjpos) {
    if (hanoiPosition[1] == +1) {
      turnLeft();
      hanoiPosition[1] = 0;
      lastHanoiPosition[0] = hanoiPosition[0];
      hanoiPosition[0] = hanoiPosition[0] - 1;

    }
    else if (hanoiPosition[1] == -1) {
      turnRight();
      hanoiPosition[1] = 0;
      lastHanoiPosition[1] = 0;
      lastHanoiPosition[0] = hanoiPosition[0];
      hanoiPosition[0] = hanoiPosition[0] - 1;
    }
  }
  else if (hanoiPosition[0] < nextjpos) {
    if (hanoiPosition[1] == +1) {
      turnRight();
      hanoiPosition[1] = 0;
      lastHanoiPosition[0] = hanoiPosition[0];
      hanoiPosition[0] = hanoiPosition[0]  + 1;
    }
    else if (hanoiPosition[1] == -1) {
      turnLeft();
      hanoiPosition[1] = 0;
      lastHanoiPosition[0] = hanoiPosition[0];
      hanoiPosition[0] = hanoiPosition[0]  + 1;
    }
  }
  else if (hanoiPosition[0] == nextjpos) {

    hanoiPosition[0] = nextjpos;
    hanoiPosition[1] = side;
    lastHanoiPosition[0] = nextjpos;
    getBoxReady(getFloor);
    while (!squareDetected()) {
      followLineSlow();
    }
    stopBot();
    box = getBox();/*****************************************************************/


    return;
  }


  while (!junctionDetected()) {
    followLine();
  }
  advance(advanceDis);
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print(hanoiPosition[0]);
  display.setCursor(40, 20);
  display.print(lastHanoiPosition[0]);
  display.setCursor(80, 20);
  display.print(nextjpos);
  display.setCursor(110, 20);
  display.print("AA");
  display.display();

  if (hanoiPosition[0] == nextjpos) {
    if (lastHanoiPosition[0] < hanoiPosition[0]) {
      if (side == +1) {
        turnRight();
      }
      if (side == -1) {
        turnLeft();
      }
    }
    if (lastHanoiPosition[0] > hanoiPosition[0]) {
      if (side == +1) {
        turnLeft();
      }
      if (side == -1) {
        turnRight();
      }
    }


    hanoiPosition[0] = nextjpos;
    hanoiPosition[1] = side;
    lastHanoiPosition[0] = nextjpos;
    getBoxReady(getFloor);
    while (!junctionDetected()) {
      followLineSlow();
    }
    stopBot();

    box = getBox();/********************************************************/


    return;
  }

  display.setCursor(0, 40);
  display.print(hanoiPosition[0]);
  display.setCursor(40, 40);
  display.print(lastHanoiPosition[0]);
  display.setCursor(80, 40);
  display.print(nextjpos);
  display.setCursor(110, 40);
  display.print("BB");
  display.display();


  if (hanoiPosition[0] < nextjpos) {
    hanoiPosition[1] = 0;
    lastHanoiPosition[0] = hanoiPosition[0];
    hanoiPosition[0] = hanoiPosition[0]  + 1;
  }
  else if (hanoiPosition[0] > nextjpos) {
    hanoiPosition[1] = 0;
    lastHanoiPosition[0] = hanoiPosition[0];
    hanoiPosition[0] = hanoiPosition[0]  - 1;
  }

  while (!junctionDetected()) {
    followLine();
  }
  advance(advanceDis);

  display.setTextSize(1);
  display.setCursor(0, 60);
  display.print(hanoiPosition[0]);
  display.setCursor(40, 60);
  display.print(lastHanoiPosition[0]);
  display.setCursor(80, 60);
  display.print(nextjpos);
  display.setCursor(110, 20);
  display.print("CC");
  display.display();

  if (lastHanoiPosition[0] < hanoiPosition[0]) {
    if (side == +1) {
      turnRight();
    }
    if (side == -1) {
      turnLeft();
    }
  }
  if (lastHanoiPosition[0] > hanoiPosition[0]) {
    if (side == +1) {
      turnLeft();
    }
    if (side == -1) {
      turnRight();
    }
  }


  hanoiPosition[0] = nextjpos;
  hanoiPosition[1] = side;
  lastHanoiPosition[0] = nextjpos;
  getBoxReady(getFloor);
  while (!junctionDetected()) {
    followLineSlow();
  }
  stopBot();
  box = getBox();/***************************************************************************/


  return;


}
