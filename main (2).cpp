#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace sf;

//I call restart once before the game loop and whenever the spacebar is pressed.
void restart(std::vector<RectangleShape>& player, Text& score, int& currentScore, RectangleShape* apple = NULL);
void drawPlayer(std::vector<RectangleShape>& player, RenderWindow& window);
void movePlayer(std::vector<RectangleShape>& player, int move, Vector2f& lastPosition);
bool checkLose(std::vector<RectangleShape>& player);
bool DoRectsCollide(RectangleShape& apple, std::vector<RectangleShape>& player);

const enum MOVING{UP, DOWN, LEFT, RIGHT};
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

//Used to prevent deaths when new segments are added to the player
Clock invinvibleTimer;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

    RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake", Style::Close);
	bool isPlaying = false;

	//stores all the squares that make up the player.
	std::vector<RectangleShape> player;

	int move = UP;
	Clock moveClock;
	Clock inputClock;

	Font font;
    if (!font.loadFromFile("arial.ttf")){
		std::cout << "Can't find the font file" << std::endl;
		return EXIT_FAILURE;
	}

	//Displayed before the game starts and whenever the player dies
    Text pauseMessage;
    pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(20);
    pauseMessage.setPosition(SCREEN_WIDTH / 3, SCREEN_HEIGHT - 70);
    pauseMessage.setColor(Color::White);
    pauseMessage.setString("Press space to start the game"); 

	//The score :D
	Text score;
	score.setFont(font);
	score.setCharacterSize(20);
	score.setPosition(20, 500);
	score.setColor(Color::White);
	int currentScore = 0;

	//Acts as the bottom boundary for the player and contains any text displayed
	RectangleShape scoreBox(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT - 480));
	scoreBox.setFillColor(Color::Black);
	scoreBox.setOutlineColor(Color::White);
	scoreBox.setOutlineThickness(-3.f);
	scoreBox.setPosition(0, 480);

	//An apple :D
	RectangleShape apple(Vector2f(8, 8));
	apple.setPosition(-10, -10);
	apple.setFillColor(Color::Red);
	restart(player, score, currentScore);

	//Used in the Konami code (just an experiment)
	int Konami = 0;

	 //////////////////////////
	//SNAKE//Enter Game Loop//
   //////////////////////////
    while (window.isOpen())
    {
		//gets the position of the player before it moves; used in player movement
		Vector2f lastPosition(player.at(0).getPosition().x, player.at(0).getPosition().y);

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

			if(event.type == event.KeyPressed){
				//Restarts the game
				if(event.key.code == Keyboard::Space){
					if(!isPlaying)
						isPlaying = true;
					restart(player, score, currentScore, &apple);
					move = UP;
					moveClock.restart();
				}

				//Gets player input every .07 seconds to prevent moving back into yourself, causing death.
				if(inputClock.getElapsedTime().asSeconds() >= 0.07){
					if(event.key.code == Keyboard::Up && move != DOWN)
						move = UP; inputClock.restart();
					if(event.key.code == Keyboard::Down && move != UP)
						move = DOWN; inputClock.restart();
					if(event.key.code == Keyboard::Left && move != RIGHT)
						move = LEFT; inputClock.restart();
					if(event.key.code == Keyboard::Right && move != LEFT)
						move = RIGHT; inputClock.restart();
				}

				//Konami Code :D When entered correctly, adds 10000 to score
				if(isPlaying){
					if(event.key.code == Keyboard::Up && Konami == 0)
						Konami = 1;
					else if(event.key.code == Keyboard::Up && Konami == 1)
						Konami = 2;
					else if(event.key.code == Keyboard::Down && Konami == 2)
						Konami = 3;
					else if(event.key.code == Keyboard::Down && Konami == 3)
						Konami = 4;
					else if(event.key.code == Keyboard::Left && Konami == 4)
						Konami = 5;
					else if(event.key.code == Keyboard::Right && Konami == 5)
						Konami = 6;
					else if(event.key.code == Keyboard::Left && Konami == 6)
						Konami = 7;
					else if(event.key.code == Keyboard::Right && Konami == 7)
						Konami = 8;
					else if(event.key.code == Keyboard::B && Konami == 8)
						Konami = 9;
					else if(event.key.code == Keyboard::A && Konami == 9){
						std::cout << "Konami Test\n";
						currentScore += 10000;
						std::string newScore = std::to_string(currentScore);
						score.setString("Score: " + newScore);
						Konami = 0;
					}
					else Konami = 0;
				}
			}
        }

		window.clear();
		drawPlayer(player, window);
		window.draw(scoreBox);
		window.draw(score);
		window.draw(apple);

		//Runs functions for playing the game if the player hasn't lost yet
		if(isPlaying){
			//moves the player about every .09 seconds (limits speed)
			if(moveClock.getElapsedTime().asSeconds() >= .09){
				movePlayer(player, move, lastPosition);
				moveClock.restart();
			}
			//Adds 10 to the score if the snake eats the apple
			if(DoRectsCollide(apple, player)){
				currentScore += 10;
				std::string newScore = std::to_string(currentScore);
				score.setString("Score: " + newScore);
			}
			if(checkLose(player))
				isPlaying = false;
		}
		else{
			window.draw(pauseMessage);
		}

        window.display();
    }

    return 0;
}

//Resets player positions, puts the apple in a random spot, resets snake length
void restart(std::vector<RectangleShape>& player, Text& score, int& currentScore, RectangleShape* apple){
	player.clear();
	player.push_back(RectangleShape(Vector2f(8, 8)));
	player.at(0).setPosition(SCREEN_WIDTH / 2, 400);
	score.setString("Score: 0");
	currentScore = 0;

	int x, y;
	x = rand() % SCREEN_WIDTH;
	y = rand() % 470;
		if(apple != NULL){
			do{
				if(x % 10 != 0)
					x = rand() % SCREEN_WIDTH;
				if(y % 10 != 0)
					y = rand() % 470;
			}while(x % 10 != 0 || y % 10 != 0);
			apple->setPosition(x, y);
		}
}

//Loops through the player vector to display each piece of the snake
void drawPlayer(std::vector<RectangleShape>& player, RenderWindow& window){
	std::vector<RectangleShape>::iterator iter;
	for(iter = player.begin(); iter < player.end(); iter++){
		window.draw(*iter);
	}
}

void movePlayer(std::vector<RectangleShape>& player, int move, Vector2f& lastPosition){
	std::vector<RectangleShape>::iterator iter, beforeIter;	//Irony?

	//I was originally going to use this to stop player movement when the game is lost
	//I decided to just stop calling the function, instead
	/*int speed = 10;
	
	if(checkLose(player) && move == UP){
		speed = 0;
	}
	else speed = 10;*/
	
	//moves the 'head' of the snake by ten pixels
	switch (move)
	{
	case UP: player.at(0).move(0, -10); break;
	case DOWN: player.at(0).move(0, 10); break;
	case LEFT: player.at(0).move(-10, 0); break;
	case RIGHT: player.at(0).move(10, 0); break;
	default: break;
	}

	//moves the 'tail' of the snake based on the position of the square in front of it
	Vector2f newPosition(lastPosition);
	for(iter = player.begin() + 1; iter < player.end(); iter++){
		if(player.begin() + 1 != player.end()){
			lastPosition = iter->getPosition();
			iter->setPosition(newPosition);
			newPosition = lastPosition;
		}
	}
	
}


bool DoRectsCollide(RectangleShape& apple, std::vector<RectangleShape>& player){
	int x, y;

	if(apple.getPosition() == player.at(0).getPosition()){
		x = rand() % SCREEN_WIDTH;
		y = rand() % 470;

		//Checks to see if the apple is at coordinates divisible by ten
		//because the snake moves at 10 pixels at a time
		do{
			if(x % 10 != 0)
				x = rand() % SCREEN_WIDTH;
			if(y % 10 != 0)
				y = rand() % 470;
		}while(x % 10 != 0 || y % 10 != 0);
		apple.setPosition(x, y);

		for(int i = 0; i < 5; i++){
			player.push_back(RectangleShape(Vector2f(8, 8)));
			player.back().setPosition(player.begin()->getPosition().x, player.begin()->getPosition().y);
		}
		//restarts the invincible timer so checkLose doesn't kill the
		//player when new parts of the snake are addded
		invinvibleTimer.restart();
		return true;
	}
	else
		return false;
}

bool checkLose(std::vector<RectangleShape>& player){
	std::vector<RectangleShape>::iterator iter;

	//Checks if player is out of bounds
	if(player.at(0).getPosition().x < 0 || player.at(0).getPosition().x > SCREEN_WIDTH - 10 ||
	   player.at(0).getPosition().y < 0 || player.at(0).getPosition().y > 470){
			return true;
	}
	//checks if the snake's head is inside its body
	//if the player just ate an apple, it waits .09 seconds for the
	//player to move and .03 seconds more just in case .09 isn't enough
	if(invinvibleTimer.getElapsedTime().asSeconds() >= .12){
		for(iter = player.begin() + 1; iter < player.end(); iter++){
			if(player.at(0).getPosition() == iter->getPosition())
				return true;
		}
	}
	return false;
}