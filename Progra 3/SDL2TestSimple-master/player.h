#ifndef PLAYER_H
#define PLAYER_H
#include <vector>




class Player : public Entity
{

    public:
        Player();
        virtual ~Player();
        void draw();
        void logic();

    protected:

    private:
        SDL_Renderer * renderer;
        SDL_Rect rect;
        vector<SDL_Texture*> textures;
        int current_texture;

};

#endif // PLAYER_H
