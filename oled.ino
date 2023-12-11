//showOled(0,0,2,"ir calibrating");



void showOled(unsigned int px, unsigned int py, unsigned int textSize, char wordPhrase) {
  display.setTextSize(textSize);
     display.setTextColor(SSD1306_WHITE);
   display.setCursor(px, py);
  display.clearDisplay();
  display.println(wordPhrase);
  display.display();
}
