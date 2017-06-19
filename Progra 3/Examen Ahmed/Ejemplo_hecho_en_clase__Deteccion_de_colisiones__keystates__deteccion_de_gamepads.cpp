
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>
#include <fstream>

using namespace std;

int check=0;
int check2=0;
int gano=0;
int perdio=0;
SDL_Window* window;
SDL_Renderer* renderer, *renderer2;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character1,rect_character2,rect_libroverde,rect_libronegro,rect_evaluar1,rect_evaluar2,rect_timemachine,rect_bomba, rect_bomba2,rect_enemy1,rect_enemy2,rect_enemy3,rect_enemy4,rect_enemy5,rect_enemy6;

vector<SDL_Texture*> character1;
vector<SDL_Texture*> character2;
vector<SDL_Texture*> bomba;
vector<SDL_Texture*> bomba2;
vector<SDL_Texture*> enemy1;
vector<SDL_Texture*> enemy2;
vector<SDL_Texture*> enemy3;
vector<SDL_Texture*> enemy4;
vector<SDL_Texture*> enemy5;
vector<SDL_Texture*> enemy6;
vector<SDL_Texture*> libroverde;
vector<SDL_Texture*> libronegro;
vector<SDL_Texture*> timemachine;
vector<SDL_Texture*> evaluarjuego1;
vector<SDL_Texture*> evaluarjuego2;


SDL_Joystick* gGameController = NULL;


bool estaColisionando1(SDL_Rect rect_character1, SDL_Rect rect_bomba)
{
    if(rect_character1.x > rect_bomba.x+rect_bomba.w)
        return false;

    if(rect_character1.x + rect_character1.w < rect_bomba.x)
        return false;

    if(rect_character1.y+rect_character1.h < rect_bomba.y)
        return false;

    if(rect_character1.y > rect_bomba.y+rect_bomba.h)
        return false;

    return true;
}

bool estaColisionando2(SDL_Rect rect_character1, SDL_Rect rect_timemachine)
{
    if(rect_character1.x > rect_timemachine.x+rect_timemachine.w)
        return false;

    if(rect_character1.x + rect_character1.w < rect_timemachine.x)
        return false;

    if(rect_character1.y+rect_character1.h < rect_timemachine.y)
        return false;

    if(rect_character1.y > rect_timemachine.y+rect_timemachine.h)
        return false;

    return true;
}

bool estaColisionando3(SDL_Rect rect_character1, SDL_Rect rect_bomba2)
{
    if(rect_character1.x > rect_bomba2.x+rect_bomba2.w)
        return false;

    if(rect_character1.x + rect_character1.w < rect_bomba2.x)
        return false;

    if(rect_character1.y+rect_character1.h < rect_bomba2.y)
        return false;

    if(rect_character1.y > rect_bomba2.y+rect_bomba2.h)
        return false;

    return true;
}

bool estaColisionando4(SDL_Rect rect_character1, SDL_Rect rect_libroverde)
{
    if(rect_character1.x > rect_libroverde.x+rect_libroverde.w)
        return false;

    if(rect_character1.x + rect_character1.w < rect_libroverde.x)
        return false;

    if(rect_character1.y+rect_character1.h < rect_libroverde.y)
        return false;

    if(rect_character1.y > rect_libroverde.y+rect_libroverde.h)
        return false;

    return true;
}

bool estaColisionando5(SDL_Rect rect_character1, SDL_Rect rect_enemy1)
{
    if(rect_character1.x > rect_enemy1.x+rect_enemy1.w)
        return false;

    if(rect_character1.x + rect_character1.w < rect_enemy1.x)
        return false;

    if(rect_character1.y+rect_character1.h < rect_enemy1.y)
        return false;

    if(rect_character1.y > rect_enemy1.y+rect_enemy1.h)
        return false;

    return true;
}

bool estaColisionando6(SDL_Rect rect_character1, SDL_Rect rect_enemy2)
{
    if(rect_character1.x > rect_enemy2.x+rect_enemy2.w)
        return false;

    if(rect_character1.x + rect_character1.w < rect_enemy2.x)
        return false;

    if(rect_character1.y+rect_character1.h < rect_enemy2.y)
        return false;

    if(rect_character1.y > rect_enemy2.y+rect_enemy2.h)
        return false;

    return true;
}

bool estaColisionando7(SDL_Rect rect_character1, SDL_Rect rect_enemy3)
{
    if(rect_character1.x > rect_enemy3.x+rect_enemy3.w)
        return false;

    if(rect_character1.x + rect_character1.w < rect_enemy3.x)
        return false;

    if(rect_character1.y+rect_character1.h < rect_enemy3.y)
        return false;

    if(rect_character1.y > rect_enemy3.y+rect_enemy3.h)
        return false;

    return true;
}

int main( int argc, char* args[] )
{

    //Init SDL
    string nombre;
    string name;
    int edad;
    cout<< "Ingrese su nombre: " << endl;
    cin>>nombre;
    cout<<"Ingrese su edad: " <<endl;
    cin>>edad;
    ofstream miarchivo("Datos.txt", std::ios_base::app);

    miarchivo << nombre << " " << edad;


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 0, 25, 1367/*WIDTH*/, 760/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
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
    background = IMG_LoadTexture(renderer,"fondo.jpg");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    //Carga los dinosaurios
    character1.push_back(IMG_LoadTexture(renderer,"trex.png"));
    character2.push_back(IMG_LoadTexture(renderer, "dimorphodon.png"));
    rect_character1.x = 0;
    rect_character1.y = 100;
    rect_character1.w = 120;
    rect_character1.h =120;



    /*Notas sobre el tamaño:
    *T-rex: W=120, h=120
    *Dimorphodon: W=120, h=120
    *Bombas: w=30, h=30
    *cuadernos: w=30, h=30
    *time machine: w=120, h=120
    *Gameover & youwin: w=360, h=360
    */
    //carga las bombas
    bomba.push_back(IMG_LoadTexture(renderer, "bomba.png"));
    bomba2.push_back(IMG_LoadTexture(renderer, "bomba2.png"));
    rect_bomba.x = 370;
    rect_bomba.y = 260;
    rect_bomba.w= 30;
    rect_bomba.h= 30;
    rect_bomba2.x = 490;
    rect_bomba2.y = 380;
    rect_bomba2.w= 30;
    rect_bomba2.h= 30;
    //carga la meta
    timemachine.push_back(IMG_LoadTexture(renderer, "time.png"));
    rect_timemachine.x=1250;
    rect_timemachine.y=250;
    rect_timemachine.h=120;
    rect_timemachine.w=120;

    //Ganar
    evaluarjuego1.push_back(IMG_LoadTexture(renderer, "youwin.jpg"));
    rect_evaluar1.x=500;
    rect_evaluar1.y=200;
    rect_evaluar1.h=360;
    rect_evaluar1.w=360;

    //Perdio
    evaluarjuego2.push_back(IMG_LoadTexture(renderer, "gameover.jpg"));
    rect_evaluar2.x=500;
    rect_evaluar2.y=200;
    rect_evaluar2.h=360;
    rect_evaluar2.w=360;

    //Cuaderno Verde
    libroverde.push_back(IMG_LoadTexture(renderer, "cuadernoverde.png"));
    rect_libroverde.x=200;
    rect_libroverde.y=200;
    rect_libroverde.h=30;
    rect_libroverde.w=30;

    //Enemy1
    enemy1.push_back((IMG_LoadTexture(renderer, "enemy1.png")));
    rect_enemy1.x=500;
    rect_enemy1.y=300;
    rect_enemy1.h=100;
    rect_enemy1.w=100;

    //Enemy2
    enemy2.push_back(IMG_LoadTexture(renderer, "enemy2.png"));
    rect_enemy2.x=900;
    rect_enemy2.y=400;
    rect_enemy2.h=100;
    rect_enemy2.w=100;

    //Enemy3
    enemy3.push_back(IMG_LoadTexture(renderer, "enemy3.png"));
    rect_enemy3.x=1100;
    rect_enemy3.y=300;
    rect_enemy3.h=100;
    rect_enemy3.w=100;



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
                rect_character1.x++;
            }
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        if(currentKeyStates[SDL_SCANCODE_UP])
        {
            rect_character1.y--;
            rect_enemy3.y++;
            rect_enemy1.y--;

            rect_enemy2.y--;
            rect_enemy2.x--;
            if(estaColisionando1(rect_character1,rect_bomba))
            {
                rect_character1.y++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;

               /* SDL_RenderCopy(renderer,character2[0], NULL, &rect_character1);
                character1.pop_back();
                SDL_RenderPresent(renderer);
                check++;
                */
            }
            if(estaColisionando2(rect_character1, rect_timemachine))
            {
                rect_character1.y++;
                SDL_RenderCopy(renderer,evaluarjuego1[0], NULL, &rect_evaluar1);
                SDL_RenderPresent(renderer);
                gano++;
            }
             if(estaColisionando3(rect_character1,rect_bomba2))
            {
                rect_character1.y++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
             if(estaColisionando4(rect_character1,rect_libroverde))
            {
                rect_character1.y++;
                SDL_RenderCopy(renderer, character2[0], NULL, &rect_character1);
                //character1.pop_back();
                SDL_RenderPresent(renderer);
                check2++;
            }
             if(estaColisionando5(rect_character1,rect_enemy1))
            {
                rect_character1.y++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando6(rect_character1,rect_enemy2))
            {
                rect_character1.y++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando7(rect_character1,rect_enemy3))
            {
                rect_character1.y++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }

        }
        if(currentKeyStates[SDL_SCANCODE_DOWN])
        {
            rect_character1.y++;
            rect_enemy3.y--;
            rect_enemy1.y++;
            rect_enemy1.x--;
            rect_enemy2.y++;
            rect_enemy2.x--;

            if(estaColisionando1(rect_character1,rect_bomba))
            {
                rect_character1.y--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
               /* SDL_RenderCopy(renderer,character2[0], NULL, &rect_character1);
                character1.pop_back();
                SDL_RenderPresent(renderer);
                check++;*/
            }
            if(estaColisionando2(rect_character1, rect_timemachine))
            {
                rect_character1.y--;
                SDL_RenderCopy(renderer,evaluarjuego1[0], NULL, &rect_evaluar1);
                SDL_RenderPresent(renderer);
                gano++;
            }
            if(estaColisionando3(rect_character1,rect_bomba2))
            {
                rect_character1.y--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando4(rect_character1,rect_libroverde))
            {
                rect_character1.y--;
                SDL_RenderCopy(renderer,character2[0], NULL, &rect_character1);
                character1.pop_back();
                SDL_RenderPresent(renderer);
                check2++;
            }
             if(estaColisionando5(rect_character1,rect_enemy1))
            {
                rect_character1.y--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando6(rect_character1,rect_enemy2))
            {
                rect_character1.y--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando7(rect_character1,rect_enemy3))
            {
                rect_character1.y--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }

        }
        if(currentKeyStates[SDL_SCANCODE_LEFT])
        {
            rect_character1.x--;
            rect_enemy3.x++;
            rect_enemy1.y--;
            rect_enemy1.x++;
            rect_enemy2.y--;
            rect_enemy2.x++;
            if(estaColisionando1(rect_character1,rect_bomba))
            {
                rect_character1.x++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
                /*SDL_RenderCopy(renderer,character2[0], NULL, &rect_character1);
                character1.pop_back();
                SDL_RenderPresent(renderer);
                check++;*/
            }
            if(estaColisionando2(rect_character1, rect_timemachine))
            {
                rect_character1.x++;
                SDL_RenderCopy(renderer,evaluarjuego1[0], NULL, &rect_evaluar1);
                SDL_RenderPresent(renderer);
                gano++;
            }
            if(estaColisionando3(rect_character1,rect_bomba2))
            {
                rect_character1.x++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando4(rect_character1,rect_libroverde))
            {
                rect_character1.x++;
                SDL_RenderCopy(renderer,character2[0], NULL, &rect_character1);
                character1.pop_back();
                SDL_RenderPresent(renderer);
                check2++;
            }
             if(estaColisionando5(rect_character1,rect_enemy1))
            {
                rect_character1.x++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando6(rect_character1,rect_enemy2))
            {
                rect_character1.x++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando7(rect_character1,rect_enemy3))
            {
                rect_character1.x++;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }

        }
        if(currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            rect_character1.x++;
            rect_enemy3.x--;
            rect_enemy1.x--;
            rect_enemy1.y--;
            rect_enemy2.x--;
            rect_enemy2.y--;
            if(estaColisionando1(rect_character1,rect_bomba))
            {
                rect_character1.x--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
                /*SDL_RenderCopy(renderer,character2[0], NULL, &rect_character1);
                character1.pop_back();
                SDL_RenderPresent(renderer);
                check++;*/
            }
            if(estaColisionando2(rect_character1, rect_timemachine))
            {
                rect_character1.x--;
                SDL_RenderCopy(renderer,evaluarjuego1[0], NULL, &rect_evaluar1);
                SDL_RenderPresent(renderer);
                gano++;
            }
            if(estaColisionando3(rect_character1,rect_bomba2))
            {
                rect_character1.x--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando4(rect_character1,rect_libroverde))
            {
                rect_character1.x--;
                SDL_RenderCopy(renderer, character2[0], NULL, &rect_character2);
                character1.pop_back();
                SDL_RenderPresent(renderer);
                check2++;
            }
             if(estaColisionando5(rect_character1,rect_enemy1))
            {
                rect_character1.x--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando6(rect_character1,rect_enemy2))
            {
                rect_character1.x--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }
            if(estaColisionando7(rect_character1,rect_enemy3))
            {
                rect_character1.x--;
                SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar2);
                SDL_RenderPresent(renderer);
                perdio++;
            }


        }
       /*rect.x-=1;
        if(rect.x==-100);
            rect.x=500;*/

        if(frames%50==0)
            current_sprite++;
        if(current_sprite>=bomba.size())
            current_sprite=0;

        int evaluador=0;
        if(check==0 && perdio==0 && gano==0 & check2==0)
        {
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character1[0], NULL, &rect_character1);
        SDL_RenderCopy(renderer, bomba[0], NULL, &rect_bomba);
        SDL_RenderCopy(renderer,enemy1[0], NULL, &rect_enemy1);
        SDL_RenderCopy(renderer,enemy2[0], NULL, &rect_enemy2);
        SDL_RenderCopy(renderer,enemy3[0], NULL, &rect_enemy3);
        rect_bomba2.x-=1;
        rect_bomba.x-=1;
        if(rect_bomba.x==-100)
        {
            rect_bomba.x=1200;
        }
        if(rect_bomba2.x==-100)
        {
            rect_bomba2.x=1200;
        }
        if(rect_enemy3.y==0 || rect_enemy3.y==600)
        {
            rect_enemy3.y=300;
        }
        if(rect_enemy3.x==666 || rect_enemy3.x==1300)
        {
            rect_enemy3.x=1100;
        }
        if(rect_enemy1.y==0 || rect_enemy1.y==600)
        {
            rect_enemy1.y=300;
        }
        if(rect_enemy1.x==0 || rect_enemy1.x==1300)
        {
            rect_enemy1.x=400;
        }
        if(rect_enemy2.y==0 || rect_enemy2.y==600)
        {
            rect_enemy2.y=300;
        }
        if(rect_enemy2.x==0 || rect_enemy2.x==1300)
        {
            rect_enemy2.x=600;
        }

        SDL_RenderCopy(renderer, bomba2[0], NULL, &rect_bomba2);
        SDL_RenderCopy(renderer, libroverde[0], NULL, &rect_libroverde);
        SDL_RenderCopy(renderer, timemachine[0], NULL, &rect_timemachine);
        SDL_RenderPresent(renderer);
        }
        else if(check==0 && gano==1 && perdio==0)
        {
            if(evaluador==0)
          {
               miarchivo << " Gano" <<endl;
               evaluador++;
          }
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character1[0], NULL, &rect_character1);
        SDL_RenderCopy(renderer, bomba[0], NULL, &rect_bomba);
        SDL_RenderCopy(renderer, bomba2[0], NULL, &rect_bomba2);
        SDL_RenderCopy(renderer,enemy1[0], NULL, &rect_enemy1);
        SDL_RenderCopy(renderer,enemy2[0], NULL, &rect_enemy2);
        SDL_RenderCopy(renderer,enemy3[0], NULL, &rect_enemy3);
        SDL_RenderCopy(renderer, libroverde[0], NULL, &rect_libroverde);
        SDL_RenderCopy(renderer, timemachine[0], NULL, &rect_timemachine);
        SDL_RenderCopy(renderer, evaluarjuego1[0], NULL, &rect_evaluar1);
        SDL_RenderPresent(renderer);

        }
        else if(check==0 && gano==0 && perdio==0 && check2!=1)
        {
            cout << "3" << endl;
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character2[0], NULL, &rect_character1);
        SDL_RenderCopy(renderer, bomba[0], NULL, &rect_bomba);
        SDL_RenderCopy(renderer, bomba2[0], NULL, &rect_bomba2);
        SDL_RenderCopy(renderer,enemy1[0], NULL, &rect_enemy1);
        SDL_RenderCopy(renderer,enemy2[0], NULL, &rect_enemy2);
        SDL_RenderCopy(renderer,enemy3[0], NULL, &rect_enemy3);
        rect_bomba2.x-=1;
        rect_bomba.x-=1;
        if(rect_bomba.x==-100)
        {
            rect_bomba.x=1200;
        }
        if(rect_bomba2.x==-100)
        {
            rect_bomba2.x=1200;
        }
        if(rect_enemy1.y==0 || rect_enemy1.y==600)
        {
            rect_enemy1.y=300;
        }
        if(rect_enemy1.x==0 || rect_enemy1.x==1300)
        {
            rect_enemy1.x=400;
        }
        if(rect_enemy2.y==0 || rect_enemy2.y==600)
        {
            rect_enemy2.y=300;
        }
        if(rect_enemy2.x==0 || rect_enemy2.x==1300)
        {
            rect_enemy2.x=600;
        }
        if(rect_enemy3.y==0 || rect_enemy3.y==600)
        {
            rect_enemy3.y=300;
        }
        if(rect_enemy3.x==666 || rect_enemy3.x==1300)
        {
            rect_enemy3.x=1100;
        }
        SDL_RenderCopy(renderer, libroverde[0], NULL, &rect_libroverde);
        SDL_RenderCopy(renderer, timemachine[0], NULL, &rect_timemachine);
        SDL_RenderPresent(renderer);
        }
        else if(perdio==1 && check==0 && gano==0)
        {
            cout << "4" << endl;
          if(evaluador==0)
          {
               miarchivo << " Perdio" <<endl;
               evaluador++;
          }
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character1[0], NULL, &rect_character1);
        SDL_RenderCopy(renderer, bomba[0], NULL, &rect_bomba);
        SDL_RenderCopy(renderer, bomba2[0], NULL, &rect_bomba2);
        SDL_RenderCopy(renderer,enemy1[0], NULL, &rect_enemy1);
        SDL_RenderCopy(renderer,enemy2[0], NULL, &rect_enemy2);
        SDL_RenderCopy(renderer,enemy3[0], NULL, &rect_enemy3);
        rect_bomba2.x-=1;
        rect_bomba.x-=1;
        SDL_RenderCopy(renderer, libroverde[0], NULL, &rect_libroverde);
        SDL_RenderCopy(renderer, timemachine[0], NULL, &rect_timemachine);
        SDL_RenderCopy(renderer, evaluarjuego2[0], NULL, &rect_evaluar1);
        SDL_RenderPresent(renderer);
        }
        frames++;

        SDL_Delay(7);
    }

	return 0;
}
