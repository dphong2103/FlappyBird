#include <iostream>
#include <stdlib.h>
#include "sound.cpp"
#include "texture.cpp"
#include "game.cpp"
#include "flappy.cpp"
#include "pipe.cpp"
#include "collide.cpp"
#include "score.cpp"

int main() {

	// create the window and set general settings
	RenderWindow window(VideoMode(1000, 600), "Flappy Bird");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	srand(time(0));

	loadSound();
    loadTexture();

	setupFlappy();

	loadGame();
	game.background[0].setTexture(textures.background);
	game.background[1].setTexture(textures.background);
	game.background[2].setTexture(textures.background);
	game.gameover.setTexture(textures.gameover);

	// main loop
	while (window.isOpen()) {
		updateScore();
		updateFlappy(fx,fy,fw,fh);

		flappyWing();

		// move flappy
		if (game.gameState == started) {
			flappy.sprite.move(0, flappy.v);
			flappy.v += 0.5;
		}

		moveFlappy();
		countScore();
		genPipes();

		// move pipes
		if (game.gameState == started) {
			for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
				(*itr).move(-3, 0);
			}
		}

		removePipe();

		collision();

		// handle events
		Event event;
		while (window.pollEvent(event)) {
            // close window
			if (event.type == Event::Closed) {
				window.close();
			}

			// bird flap
			else if (event.type == Event::KeyPressed &&
					   event.key.code == Keyboard::Space) {
				if (game.gameState == waiting) {
					game.gameState = started;
				}

				if (game.gameState == started) {
					flappy.v = -8;
					sounds.hop.play();
				}

			// replay
			} else if (event.type == Event::KeyPressed &&
					   event.key.code == Keyboard::C &&
					   game.gameState == gameover) {
				game.gameState = waiting;
				flappy.sprite.setPosition(250, 300);
				game.score = 0;
				pipes.clear();
			}
		}

		// clear
		window.clear();

		//draw window
        window.draw(game.background[0]);
		window.draw(game.background[1]);
		window.draw(game.background[2]);
		window.draw(flappy.sprite);

		// draw pipes
		for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
			window.draw(*itr);
		}

		// draw scores
		window.draw(game.scoreText);
		window.draw(game.highscoreText);

		//draw guide
		if (game.gameState == waiting) {
			window.draw(game.guide);
		}

		// draw game over
		if (game.gameState == gameover) {
			window.draw(game.gameover);

			if (game.frames % 60 < 30) {
				window.draw(game.pressC);
			}
		}

		//display
		window.display();

		//update total frames
		game.frames++;
	}

	return 0;
}
