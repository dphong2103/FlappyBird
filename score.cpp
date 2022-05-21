void countScore()
{
    for (vector<Sprite>::iterator itr = pipes.begin(); itr != pipes.end(); itr++) {
			if (game.gameState == started && (*itr).getPosition().x == 250) {
				game.score++;
				sounds.ching.play();

				if (game.score > game.highscore) {
					game.highscore = game.score;
				}

				break;
			}
		}

}

void updateScore()
{
    flappy.sprite.setTexture(textures.flappy[1]);
    game.scoreText.setString("Score: " + to_string(game.score));
    game.highscoreText.setString("HIGH SCORE: " + to_string(game.highscore));
}
