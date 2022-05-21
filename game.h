#include <SFML/Graphics.hpp>

enum GameState {waiting, // waiting = game not started yet
                started, // started = playing
                gameover }; // gameover = game is over

// game settings in singleton game struct
// frames counts total frames passed since the beginning of time
struct Game {
    int score = 0;
    int highscore = 0;
    int frames = 0;
    GameState gameState = waiting;
    Sprite background[3];
    Sprite gameover;
    Text pressC;
    Text scoreText;
    Text highscoreText;
    Font font;
} game;
