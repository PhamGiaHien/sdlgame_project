#ifndef IMAGE.H
#define IMAGE.H

SDL_Texture* init_picture(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/startbg.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* play_bg(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/playbg.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image1(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/card1.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image2(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/card2.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image3(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/card3.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image4(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/card4.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image5(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/card5.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_image6(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/card6.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* card_imageback(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("image/back.jpg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

#endif // IMAGE

