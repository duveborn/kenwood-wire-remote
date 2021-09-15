# kenwood-wire-remote

Kenwood car stereo "steering wheel control" adapter using an ESP8266 Wemos/Lolin D1 Mini and PlatformIO.

So I need to control a Kenwood car stereo installed in my boat's cabin from the flybridge since I added outdoor speakers.

As it's not a marine system with
NMEA 2000 or multiple station support I figured I'd simnply hook up the "steering wheel control" wire to some DIY buttons
so I could change amplifier volume, play, pause and skip tracks from upstairs.

It turned out the easiest way to do this
was with a microcontroller to replicate the required NEC IR wire protocol as documented here: https://init6.pomorze.pl/projects/kenwood_ford/

Then I can simply add some buttons to the micro controller and run the "steering wheel control" wire to the stereo and get true amplifier volume control. Always make sure your gain staging is impeccable!

Future upgrades are REST API over WiFi and custom boat administrator site/app with everything from real-time engine data, tank levels and logs to stereo and 12V DC relay controls.

Another path would be to attempt creating an adapter to NMEA 2000 so the Kenwood stereo could be integrated like a true marine sound system, either via an IP Gateway or directly on the NMEA bus as a true test of DIY electronics.
