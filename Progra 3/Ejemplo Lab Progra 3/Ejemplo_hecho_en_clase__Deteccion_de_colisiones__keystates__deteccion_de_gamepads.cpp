
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character,mi_rect;

vector<SDL_Texture*> textures;

SDL_Joystick* gGameController = NULL;


bool estaColisionando(SDL_Rect r1, SDL_Rect r2)
{
    if(r1.x > r2.x+r2.w)
        return false;

    if(r1.x + r1.w < r2.x)
        return false;

    if(r1.y+r1.h < r2.y)
        return false;

    if(r1.y > r2.y+r2.h)
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

    textures.push_back(IMG_LoadTexture(renderer, "1.png"));
    textures.push_back(IMG_LoadTexture(renderer, "2.png"));
    mi_rect.x = 50;
    mi_rect.y = 20;
    mi_rect.w = 40;
    mi_rect.h = 56;

    if( SDL_NumJoysticks() < 1 )
    {
        cout<< "No hay gamepads conectados" <<endl;
    }
    else
    {
        gGameController = SDL_JoystickOpen( 0 );
        if( gGameController == NULL )
        {
            cout<<"Error al abrir el gamepad"<<endl;
        }
    }

    //Main Loop
    int frames = 0;
    int current_sprite = 0;
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }

            if( Event.type == SDL_JOYBUTTONDOWN )
            {
                rect_character.x++;
            }
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if(currentKeyStates[SDL_SCANCODE_UP])
        {
            rect_character.y--;
            if(estaColisionando(rect_character,mi_rect))
                rect_character.y++;
        }
        if(currentKeyStates[SDL_SCANCODE_DOWN])
        {
            rect_character.y++;
            if(estaColisionando(rect_character,mi_rect))
                rect_character.y--;
        }
        if(currentKeyStates[SDL_SCANCODE_LEFT])
        {
            rect_character.x--;
            if(estaColisionando(rect_character,mi_rect))
                rect_character.x++;
        }
        if(currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            rect_character.x++;
            if(estaColisionando(rect_character,mi_rect))
                rect_character.x--;
        }

        if(frames%50==0)
            current_sprite++;
        if(current_sprite>=textures.size())
            current_sprite=0;

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, textures[current_sprite], NULL, &mi_rect);
        SDL_RenderPresent(renderer);
        frames++;

        SDL_Delay(15);
    }

	return 0;
}
