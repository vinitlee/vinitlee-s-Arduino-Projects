#define PWR 23
#define ch_R 22
#define ch_G 21
#define ch_B 20

int hue = 0;

void setup() {
  
  pinMode(PWR,OUTPUT);
  pinMode(ch_R,OUTPUT);
  pinMode(ch_G,OUTPUT);
  pinMode(ch_B,OUTPUT);
  analogWrite(PWR,255);
  analogWrite(ch_R,255);
  analogWrite(ch_G,255);
  analogWrite(ch_B,255);
}
void loop() {
  hue = (hue + 1)%360;
  setHSV(hue,1,1);
  delay(10);
}

void setHSV(float hue,float sat,float val) {
  float c = val * sat;
  float hp = hue/60.0;
  float x = c*(1 - abs((hp-floor(hp/2)*2) - 1));
  float rgb1[3] = {0,0,0};
  if (hp < 1)      {rgb1[1] = x;rgb1[0] = c;}
  else if (hp < 2) {rgb1[0] = x;rgb1[1] = c;}
  else if (hp < 3) {rgb1[2] = x;rgb1[1] = c;}
  else if (hp < 4) {rgb1[1] = x;rgb1[2] = c;}
  else if (hp < 5) {rgb1[0] = x;rgb1[2] = c;}
  else if (hp < 6) {rgb1[2] = x;rgb1[0] = c;}

  float m = val - c;
  
  float rgb[] = {(rgb1[0]+m),(rgb1[1]+m),(rgb1[2]+m)};
  // return rgb;

  analogWrite(ch_R,(-rgb[0]+1)*255);
  analogWrite(ch_G,(-rgb[1]+1)*255);
  analogWrite(ch_B,(-rgb[2]+1)*255);
}
