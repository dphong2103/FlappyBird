#include "flappy.h"

float fx,fy,fw,fh;

void setupFlappy()
{
    // initial position, scale
	flappy.sprite.setPosition(250, 300);
	flappy.sprite.setScale(2, 2);
}

void flappyWing()
{
    // flap the wings if playing
    if (game.gameState == waiting || game.gameState == started) {

        // change the texture once in 6 frames
        if (game.frames % 6 == 0) {
            flappy.frame += 1;
        }
        if (flappy.frame == 3) {
            flappy.frame = 0;
        }
		}

    flappy.sprite.setTexture(textures.flappy[flappy.frame]);
}

void updateFlappy(float &fx, float &fy,float &fw,float &fh)
{
    //update position
    fx = flappy.sprite.getPosition().x;
    fy = flappy.sprite.getPosition().y;
    fw = 34 * flappy.sprite.getScale().x;
    fh = 24 * flappy.sprite.getScale().y;
}

void moveFlappy()
{
    // if hits ceiling, stop ascending
    // if out of screen, game over
    if (game.gameState == started) {
        if (fy < 0) {
            flappy.sprite.setPosition(250, 0);
            flappy.v = 0;
        } else if (fy > 600) {
            flappy.v = 0;
            game.gameState = gameover;
            sounds.crash.play();
        }
    }
}
