#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>

SDL_Texture* init_picture(SDL_Renderer* renderer);
SDL_Texture* play_bg(SDL_Renderer* renderer);
SDL_Texture* card_image1(SDL_Renderer* renderer);
SDL_Texture* card_image2(SDL_Renderer* renderer);
SDL_Texture* card_image3(SDL_Renderer* renderer);
SDL_Texture* card_image4(SDL_Renderer* renderer);
SDL_Texture* card_image5(SDL_Renderer* renderer);
SDL_Texture* card_image6(SDL_Renderer* renderer);
SDL_Texture* card_imageback(SDL_Renderer* renderer);
SDL_Texture* win_bg(SDL_Renderer* renderer);
SDL_Texture* gameover_bg(SDL_Renderer* renderer);


#endif
