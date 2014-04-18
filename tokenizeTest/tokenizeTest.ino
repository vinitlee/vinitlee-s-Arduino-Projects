char str[] = "Hello. What a good day today!";
char *saveptr;
char *foo;
char *bar;

void setup() {
  Serial.begin(9600);
  delay(5000);
  Serial.println("Today's message is...");
  foo = strtok_r(str, " ", &saveptr); 
  while (foo) {
    Serial.println(foo);
    foo = strtok_r(NULL, " ", &saveptr);
  }
  Serial.println(foo);
  delay(500);
}
void loop() {
}
