void mdrive(int mleft, int mright) {

  if (mleft > 0) {
    if (mleft > 255) {
      mleft = 255;
    }
    analogWrite(left_front, mleft);
    digitalWrite(left_back, LOW);

  } else if (mleft < 0) {
    if (mleft < -255) {
      mleft = -255;
    }
    digitalWrite(left_front, LOW);
    analogWrite(left_back, -1*mleft);
  } else {
    digitalWrite(left_front, LOW);
    digitalWrite(left_back, LOW);
  }



if (mright > 0) {
    if (mright > 255) {
      mright = 255;
    }
    analogWrite(right_front, mright);
    digitalWrite(right_back, LOW);

  } else if (mright < 0) {
    if (mright < -255) {
      mright = -255;
    }
    digitalWrite(right_front, LOW);
    analogWrite(right_back, -1*mright);
  } else {
    digitalWrite(right_front, LOW);
    digitalWrite(right_back, LOW);
  }


}
