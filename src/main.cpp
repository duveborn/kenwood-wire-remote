#include <Arduino.h>

// https://init6.pomorze.pl/projects/kenwood_ford/
// TODO
// If the key on the remote controller is kept depressed, a repeat code will be issued, typically around 40ms after the pulse burst that signified the end of the message. A repeat code will continue to be sent out at 108ms intervals, until the key is finally released. The repeat code consists of the following, in order:

// a 9ms leading pulse burst
// a 2.25ms space
// a 562.5µs pulse burst to mark the end of the space (and hence end of the transmitted repeat code).

const float KENWOOD_BASE_MICROSECONDS = 562.5;

const byte ADDRESS_KENWOOD = 0xb9;
const byte COMMAND_PLAY_PAUSE = 0x0e;
const byte COMMAND_VOLUME_UP = 0x14;
const byte COMMAND_VOLUME_DOWN = 0x15;
const byte COMMAND_PREVIOUS_TRACK = 0x0b;
const byte COMMAND_NEXT_TRACK = 0x03;
const byte COMMAND_MUTE = 0x16;

void zero()
{
  digitalWrite(D1, HIGH);
  delayMicroseconds(KENWOOD_BASE_MICROSECONDS);
  digitalWrite(D1, LOW);
  delayMicroseconds(KENWOOD_BASE_MICROSECONDS);
}

void one()
{
  digitalWrite(D1, HIGH);
  delayMicroseconds(KENWOOD_BASE_MICROSECONDS);
  digitalWrite(D1, LOW);
  delayMicroseconds(KENWOOD_BASE_MICROSECONDS * 3.0);
}

void writeByte(byte byte)
{
  for (int i = 0; i < 8; i++)
  {
    if (byte & 0x01)
    {
      one();
    }
    else
    {
      zero();
    }

    byte = byte >> 1;
  }
}

void writeCommand(byte command)
{
  // Start
  digitalWrite(D1, HIGH);
  delay(9);
  digitalWrite(D1, LOW);
  delay(4.5);
  // Data
  writeByte(ADDRESS_KENWOOD);
  writeByte(~ADDRESS_KENWOOD);
  writeByte(command);
  writeByte(~command);
  // Finish
  digitalWrite(D1, HIGH);
  delayMicroseconds(562.5);
  digitalWrite(D1, LOW);
}

void setup()
{
  // Set up D1 for remote control output
  pinMode(D1, OUTPUT);
  digitalWrite(D1, LOW);
}

int test = 0;

void loop()
{
  if (test == 0)
  {
    writeCommand(COMMAND_PLAY_PAUSE);
    test = 1;
  }
}