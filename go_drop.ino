
void goAndDropBox(byte nextjpos/*position 0,1,2 */, int side/*left -1 or right +1 */, byte dropFloor /*bot 1 or mid 2 or top 3*/, bool backsw /*back on back off*/) {
  if (backsw == 1) {
    advance(backDis);
  }

  turnBack();
  while (!junctionDetected()) {
    followLine();
  }
  advance(advanceDis);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(hanoiPosition[0]);
  display.setCursor(20, 0);
  display.print(lastHanoiPosition[0]);
  display.setCursor(40, 0);
  display.print(nextjpos);
  display.setCursor(60, 0);
  display.print("one");
  display.display();


  if (hanoiPosition[0] == nextjpos) {

    hanoiPosition[0] = nextjpos;
    hanoiPosition[1] = side;
    lastHanoiPosition[0] = nextjpos;

    while (!squareDetected()) {
      followLineSlow();
    }
    stopBot();
    dropBox(dropFloor);/**************************************************************/
    if (backsw == 1) {
      advance(backDis);
    }
    return;
  }


  else if (hanoiPosition[0] > nextjpos) {
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




  while (!junctionDetected()) {
    followLine();
  }
  advance(advanceDis);
  display.setTextSize(1);
  display.setCursor(0, 15);
  display.print(hanoiPosition[0]);
  display.setCursor(20, 15);
  display.print(lastHanoiPosition[0]);
  display.setCursor(40, 15);
  display.print(nextjpos);
  display.setCursor(60, 15);
  display.print("two");
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
    while (!junctionDetected()) {
      followLineSlow();
    }
    stopBot();
    dropBox(dropFloor);/**********************************/
    if (backsw == 1) {
      advance(backDis);
    }
    return;
  }

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
  advance(advanceDis);

  hanoiPosition[0] = nextjpos;
  hanoiPosition[1] = side;
  lastHanoiPosition[0] = nextjpos;
  while (!junctionDetected()) {
    followLineSlow();
  }
  stopBot();
  dropBox(dropFloor);/*********************************************/
  if (backsw == 1) {
    advance(backDis);
  }

  return;

}
