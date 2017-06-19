#include "player.h"

Player::Player(SDL_Renderer * renderer)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::draw()
{
    SDL_RenderCopy(renderer, background, NULL, &rect_background);
}

void Player::logic()
{

}
