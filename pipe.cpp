#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

// resizable array of sprites representing pipes
vector<Sprite> pipes;

void genPipes()
{
    if (game.gameState == started && game.frames % 150 == 0) {
        int r = rand() % 275 + 75;
        int gap = 150;

        // lower pipe
        Sprite pipeL;
        pipeL.setTexture(textures.pipe);
        pipeL.setPosition(1000, r + gap);
        pipeL.setScale(2, 2);

        // upper pipe
        Sprite pipeU;
        pipeU.setTexture(textures.pipe);
        pipeU.setPosition(1000, r);
        pipeU.setScale(2, -2);

        // push to the array
        pipes.push_back(pipeL);
        pipes.push_back(pipeU);
    }
}

void removePipe()
{
    // remove pipes if offscreen
    if (game.frames % 100 == 0) {
        vector<Sprite>::iterator startitr = pipes.begin();
        vector<Sprite>::iterator enditr = pipes.begin();

        for (; enditr != pipes.end(); enditr++) {
            if ((*enditr).getPosition().x > -104) {
                break;
            }
        }

        pipes.erase(startitr, enditr);
    }
}
