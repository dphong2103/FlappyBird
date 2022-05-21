#include <SFML/Audio.hpp>

using namespace sf;

// all sounds and their buffers will rest in this struct
struct Sounds {
    SoundBuffer chingBuffer;
    SoundBuffer hopBuffer;
    SoundBuffer crashBuffer;
    Sound ching;
    Sound hop;
    Sound crash;
} sounds;
