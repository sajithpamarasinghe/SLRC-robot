void advance(int dis) {
  attachInterrupt(digitalPinToInterrupt(encorderPin), countEncorderDist, CHANGE);
  if (dis > 0) {
    while (encorderCount < dis) {
      mdrive(leftBaseSpd, rightBaseSpd);
    }
  }
  else {
    while (encorderCount < (dis * -1)) {
      mdrive(-leftBaseSpd, -rightBaseSpd);
    }
  }

  detachInterrupt(digitalPinToInterrupt(encorderPin));
  encorderCount = 0;
  mdrive(0, 0);
}
