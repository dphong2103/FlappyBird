#include <SFML/Graphics.hpp>

using namespace sf;

// all textures remain in here. Flappy has 3 textures, which will repeadetly draw, creating the illusion of flying.
struct Textures {
    Texture flappy[3];
    Texture pipe;
    Texture background;
    Texture gameover;
} textures;
