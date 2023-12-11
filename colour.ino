byte getColour() {
  digitalWrite(26, HIGH);
  // tcs.setInterrupt(false);  // turn on LED
  delay(50);  // takes 50ms to read
  tcs.getRGB(&red, &green, &blue);
  digitalWrite(26, LOW);

  //  Serial.print(red);
  //  Serial.print("    ");
  //  Serial.print(green);
  //  Serial.print("    ");
  //  Serial.println(blue);
//
//  if (red < 260 && green < 155 && blue < 160) {
//    return 4;
//  } else {
    if (red > green && red > blue) {
      return 1;
    } else if (green > red && green > blue) {
      return 2;
    } else if (blue > green && blue > red) {
      return 3;
    }
  //}
}
