#ifndef _IMAGE.H
#define _IMAGE.H

SDL_Texture* play_bg(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("playbg.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image1(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(".jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image2(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(".jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image3(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(".jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image4(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(".jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image5(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(".jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image6(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(".jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}


#endif // _IMAGE
