#include <SPI.h>

void setup() {
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV64);
}

void loop() {
	for (int i=0; i<4; i++) {
		SPI.transfer(0x00);
		delayMicroseconds(10);
	}
	for (int i=0; i<5; i++) {
		SPI.transfer(0x8DDD);
		delayMicroseconds(10);
	}
	for (int i=0; i<20; i++) {
		SPI.transfer(0xFF);
		delayMicroseconds(10);
	}

}