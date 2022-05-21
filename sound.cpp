#include "sound.h"

void loadSound()
{
    // load sounds
	sounds.chingBuffer.loadFromFile("./audio/score.wav");
	sounds.hopBuffer.loadFromFile("./audio/flap.wav");
	sounds.crashBuffer.loadFromFile("./audio/crash.wav");
	sounds.ching.setBuffer(sounds.chingBuffer);
	sounds.hop.setBuffer(sounds.hopBuffer);
	sounds.crash.setBuffer(sounds.crashBuffer);
}
