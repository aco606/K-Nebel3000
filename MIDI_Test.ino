#include <MIDI.h>
 // Created and binds the MIDI interface to the default hardware Serial port
 MIDI_CREATE_DEFAULT_INSTANCE();

 void setup()
 {
     MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages
 }

 void loop()
 {
     MIDI.read();
    // delay(500);
     MIDI.sendNoteOn(30, 127, 1);
    // delay(500);
     MIDI.sendNoteOff(30, 127, 1);
    // delay(500);
   MIDI.sendNoteOn(40, 127, 1);
    // delay(500);
     MIDI.sendNoteOff(40, 127, 1);
    // delay(500);
   MIDI.sendNoteOn(50, 127, 1);
    // delay(500);
     MIDI.sendNoteOff(50, 127, 1);
    // delay(500);
 }
