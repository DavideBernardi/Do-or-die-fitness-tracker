class TimeBar {
  private:
    int x = 0;
    int y = 0;
    int w = 100;
    int h = 10;
    boolean changed;
    uint8_t val = 100;
    int oldval;

  public:
    TimeBar() {

    }

    void move() {
      //With this, we only draw the bar if there has been a change
      oldval = val;
      val = lifeleft;
      if (oldval != val) {
        changed = true;
      }
    }

    void draw() {
      if (changed) {
        M5.Lcd.fillRect(x + 1, y + 1, w, h, BACKGROUNDCOLOR);
        changed = false;
      }
      M5.Lcd.progressBar(x + 1, y + 1, w, h, val);
      M5.Lcd.drawRect(x, y, w + 2, h + 2, 0xFFFF); //White border around bae
    }
};
