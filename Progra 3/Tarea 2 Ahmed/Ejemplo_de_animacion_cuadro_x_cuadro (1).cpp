
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character,mi_rect,rect2,rect3,rect4,rect5;

vector<SDL_Texture*> textures;
vector<SDL_Texture*> pacman;
vector<SDL_Texture*> ghost;
vector<SDL_Texture*> pacman2;
vector<SDL_Texture*> ghost2;

bool estaColisionando(SDL_Rect r1, SDL_Rect r2)//maneja las colisiones
{
    if(rect2.x>rect4.x+rect4.w)
        return false;
    if(rect2.x + rect2.w < rect4.x)
        return false;
    if(rect2.y + rect2.h < rect4.y)
        return false;
    if(rect2.y > rect4.y + rect4.w)
        return false;

    return true;
}

int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0; rect_character.y = 100; rect_character.w = w; rect_character.h = h;


    //Pacman
    pacman.push_back(IMG_LoadTexture(renderer, "pac1.png"));
    pacman.push_back(IMG_LoadTexture(renderer, "pac2.png"));
    pacman.push_back(IMG_LoadTexture(renderer, "pac3.png"));
    rect2.x = 10;
    rect2.y = 10;
    rect2.w = 40;
    rect2.h = 56;

    //Ghost
    ghost.push_back(IMG_LoadTexture(renderer, "ghost1.png"));
    ghost.push_back(IMG_LoadTexture(renderer, "ghost2.png"));
    ghost.push_back(IMG_LoadTexture(renderer, "ghost3.png"));
    ghost.push_back(IMG_LoadTexture(renderer, "ghost4.png"));
    rect3.x = 100;
    rect3.y = 100;
    rect3.w = 40;
    rect3.h = 46;

    //Pacman 2 estatico
    pacman2.push_back(IMG_LoadTexture(renderer, "pac1.png"));
    pacman2.push_back(IMG_LoadTexture(renderer, "pac2.png"));
    pacman2.push_back(IMG_LoadTexture(renderer, "pac3.png"));
    pacman2.push_back(IMG_LoadTexture(renderer, "pac4.png"));
    pacman2.push_back(IMG_LoadTexture(renderer, "pac5.png"));
    pacman2.push_back(IMG_LoadTexture(renderer, "pac6.png"));
    pacman2.push_back(IMG_LoadTexture(renderer, "pac7.png"));
    pacman2.push_back(IMG_LoadTexture(renderer, "pac8.png"));
    pacman2.push_back(IMG_LoadTexture(renderer, "pac9.png"));
    rect4.x=150;
    rect4.y=150;
    rect4.h=40;
    rect4.w=40;

    //Ghost 2 Estatico
    ghost2.push_back(IMG_LoadTexture(renderer, "ghost1.png"));
    ghost2.push_back(IMG_LoadTexture(renderer, "ghost2.png"));
    ghost2.push_back(IMG_LoadTexture(renderer, "ghost3.png"));
    ghost2.push_back(IMG_LoadTexture(renderer, "ghost4.png"));
    rect5.x = 280;
    rect5.y =280;
    rect5.w = 40;
    rect5.h = 46;


    //Main Loop
    int frames = 0;
    int current_sprite = 0;
    int fantasma = 0;
    int pac=0;
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_a)
                {
                    rect2.x--;
                    rect3.x--;
                    rect_character.x--;
                }
                if(Event.key.keysym.sym == SDLK_w)
                {
                     rect2.y--;
                     rect3.y--;
                    rect_character.y--;
                }


                if(Event.key.keysym.sym == SDLK_d)
                {
                    rect2.x++;
                    rect3.x++;
                    rect_character.x++;
                }


                if(Event.key.keysym.sym == SDLK_s)
                {
                    rect2.y++;
                    rect3.y++;
                    rect_character.y++;
                }

            }

        }
        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );//colisiones que no se atraviesan
                if( currentKeyStates[ SDL_SCANCODE_UP ] )
                {
                    rect2.y--;
                    if(estaColisionando(rect2,rect4))
                        rect2.y++;
                }
                else if( currentKeyStates[ SDL_SCANCODE_DOWN ] )
                {
                    rect2.y++;
                    if(estaColisionando(rect2,rect4))
                        rect2.y--;
                }
                else if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
                {
                    rect2.x--;
                    if(estaColisionando(rect2,rect4))
                        rect2.x++;
                }
                else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
                {
                    rect2.x++;
                    if(estaColisionando(rect2,rect4))
                        rect2.x--;
                }

        if(frames%500==0)
        {
            current_sprite++;
            fantasma++;
            pac++;
        }




        if(fantasma>=ghost.size())
            fantasma=0;
        if(current_sprite>=pacman.size())
            current_sprite=0;
        if(current_sprite>=pacman2.size())
            pac=0;

        if(estaColisionando(rect2,rect4))
            cout<<"Colision!" <<endl;
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, pacman[current_sprite], NULL, &rect2);
        SDL_RenderCopy(renderer, ghost[fantasma], NULL, &rect3);
        SDL_RenderCopy(renderer, pacman2[fantasma], NULL, &rect4);
        SDL_RenderCopy(renderer, ghost2[fantasma], NULL, &rect5);

        SDL_RenderPresent(renderer);
        frames++;

        SDL_Delay(15);
    }

	return 0;
}
