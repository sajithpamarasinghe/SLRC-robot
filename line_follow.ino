

void followLine() {
  uint16_t position = qtr.readLineWhite(sensorValues);
  error = position - 5500;
  qtr.readCalibrated(sensorValues);
  whiteIrCount = 0;
  for (int c = 0; c < 12; c++) {
    if (sensorValues[c] < 500) {
      whiteIrCount++;
    } else {
      whiteIrCount = whiteIrCount;
    }
  }
  dif = error * kp + (error - lastErr) * kd;
  lastErr = error;
  mdrive(leftBaseSpd + dif, rightBaseSpd - dif);
 
}

void followLineSlow() {
  uint16_t position = qtr.readLineWhite(sensorValues);
  error = position - 5500;
  qtr.readCalibrated(sensorValues);
  whiteIrCount = 0;
  for (int c = 0; c < 12; c++) {
    if (sensorValues[c] < 500) {
      whiteIrCount++;
    } else {
      whiteIrCount = whiteIrCount;
    }
  }
  dif = error * kp + (error - lastErr) * kd;
  lastErr = error;
  mdrive(leftBaseSpd-50 + dif, rightBaseSpd-50 - dif);
 
}
