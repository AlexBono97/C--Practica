#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <ostream>

using namespace sf;
using namespace std;

//I call restart once before the game loop and whenever the spacebar is pressed.
void restart(std::vector<RectangleShape>& player, Text& score, int& currentScore, RectangleShape* apple = NULL);
void drawPlayer(std::vector<RectangleShape>& player, RenderWindow& window);
void movePlayer(std::vector<RectangleShape>& player, int move, Vector2f& lastPosition);
bool checkLose(std::vector<RectangleShape>& player);
bool DoRectsCollide(RectangleShape& apple, std::vector<RectangleShape>& player);

 enum MOVING{UP, DOWN, LEFT, RIGHT};
const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;

//Used to prevent deaths when new segments are added to the player
Clock invinvibleTimer;


void iniciarjuego()
{
    srand(static_cast<unsigned int>(time(0)));

    RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake Game", Style::Close);
	bool isPlaying = false;

	//stores all the squares that make up the player.
	std::vector<RectangleShape> player;

	int move = UP;
	Clock moveClock;
	Clock inputClock;

	Font font;
    if (!font.loadFromFile("arial.ttf")){
		std::cout << "Can't find the font file" << std::endl;
		EXIT_FAILURE;
	}

	//Displayed before the game starts
    Text pauseMessage;
    pauseMessage.setFont(font);
	pauseMessage.setCharacterSize(12);
    pauseMessage.setPosition(SCREEN_WIDTH / 3, SCREEN_HEIGHT - 70);
    pauseMessage.setColor(Color::White);
    pauseMessage.setString("Press space to restart the game");

    //Game Over Text

    Text gameOverMessage;
    gameOverMessage.setFont(font);
	gameOverMessage.setCharacterSize(12);
    gameOverMessage.setPosition(SCREEN_WIDTH / 3, SCREEN_HEIGHT - 70);
    gameOverMessage.setColor(Color::White);
    gameOverMessage.setString("Game Over");

	//The score
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

	// apple
	RectangleShape apple(Vector2f(8, 8));
	apple.setPosition(-10, -10);
	apple.setFillColor(Color::Red);
	restart(player, score, currentScore);



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
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();

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
                isPlaying=false;
                restart(player, score, currentScore, &apple);

				//currentScore += 10;
				//std::string newScore = std::to_string(currentScore);
				//score.setString("Score: " + newScore);
			}
			if(checkLose(player))
				isPlaying = false;
				window.draw(pauseMessage);

		}
		else{
			window.draw(gameOverMessage);
		}

        window.display();
    }


}

//Resets player positions, puts the apple in a random spot, resets snake length
void restart(std::vector<RectangleShape>& player, Text& score, int& currentScore, RectangleShape* apple){

    //manejo de archivos
    string line;
    std::string newScore = std::to_string(currentScore);
    ofstream miarchivo2;
    miarchivo2.open("puntajes.txt", ofstream::app);
    if(miarchivo2.is_open())
        {
            miarchivo2 <<"Puntaje: "+ newScore << endl;
            miarchivo2.close();
        }
    //Termina manejo de archivos
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

void mostrarinstrucciones()
{
    sf::RenderWindow instrucciones(sf::VideoMode(800,600), "Instrucciones");
     sf::Texture g;
     sf::Sprite spG;
     g.loadFromFile("C:/C++Practica/ExamenFinalLabProgra3/instrucciones.png");
     spG.setTexture(g);

     while(instrucciones.isOpen())
     {
         instrucciones.clear(sf::Color(180, 200, 255));
         instrucciones.draw(spG);
         instrucciones.display();
         sf::Event evento;
         sf::Keyboard ev;

         while(instrucciones.pollEvent(evento))
         {
             if(evento.type == sf::Event::Closed)
             {
                 instrucciones.close();
             }
             else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
             {
                 instrucciones.close();
             }



}}}

void mostrarpuntajes()
{
     sf::RenderWindow puntajes(sf::VideoMode(800,600), "Puntajes");
     sf::Texture g;
     sf::Sprite spG;
     g.loadFromFile("C:/C++Practica/ExamenFinalLabProgra3/puntajes.png");
     spG.setTexture(g);

     RectangleShape scoreBox(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT - 480));
     scoreBox.setFillColor(Color::Black);
     scoreBox.setOutlineColor(Color::White);
     scoreBox.setOutlineThickness(-3.f);
     scoreBox.setPosition(0, 480);

     Font font;
     Text score;
     score.setFont(font);
     score.setCharacterSize(20);
     score.setPosition(20, 500);
     score.setColor(Color::White);




     while(puntajes.isOpen())
     {
         puntajes.clear(sf::Color(180, 200, 255));
         puntajes.draw(spG);
         puntajes.display();
         puntajes.draw(scoreBox);
         puntajes.draw(score);
         sf::Event evento;
         sf::Keyboard ev;

         string line;
         ifstream miarchivo2("Prueba.txt");

        if(miarchivo2.is_open())
        {
            while(getline(miarchivo2,line))
            {
                score.setString(line);
            }
                miarchivo2.close();
        }






         while(puntajes.pollEvent(evento))
         {
             if(evento.type == sf::Event::Closed)
             {
                 puntajes.close();
             }
             else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
             {
                 puntajes.close();
             }



}}
}
void menu()
{
    //loading main screen
     sf::RenderWindow menu(sf::VideoMode(800,600), "Menu");
     sf::Texture f;
     sf::Sprite spF;
     f.loadFromFile("C:/C++Practica/ExamenFinalLabProgra3/portada.png");
     spF.setTexture(f);

     //music
     sf::Music mu;
     mu.openFromFile("C:/C++Practica/ExamenFinalLabProgra3/ost.wav");
     mu.setVolume(33);
     mu.setLoop(true);
     mu.play();

     while(menu.isOpen())
     {
         menu.clear(sf::Color(180, 200, 255));
         menu.draw(spF);
         menu.display();
         sf::Event evento;
         sf::Keyboard ev;

         while(menu.pollEvent(evento))
         {
             if(evento.type == sf::Event::Closed)
             {
                 menu.close();
             }
             else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
             {
                 menu.close();
                 iniciarjuego();
             }
             else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
             {
                 mostrarinstrucciones();
             }
             else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
             {
                 menu.close();
             }
             else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
             {
                mostrarpuntajes();
             }

         }
     }
}
int main()
{
    menu();
	 //loop
}


