#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <iostream>
class MyTexture
{
    private:
    SDL_Texture* MTex;
    int wMTex;
    int hMTex;
    
    public:
    //first value - gia tri ban dau
    MyTexture();

    //destroy variable - pha huy bien
    ~MyTexture();

    //get height of texture - lay chieu cao cua texture
    int get_height();

    //get width of texture - lay chieu rong cua texture
    int get_width();

    //copy texture
    void copyTex(const MyTexture &tex);

    //load image from file with color key  - tai hinh anh tu 1 file co khoa mau
    void loadfromfile(std::string path, Uint8 red, Uint8 green, Uint8 blue);

    //load image from file  - tai hinh anh tu 1 file 
    void loadfromfile(std::string path);

    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    void setBlendMode( SDL_BlendMode blending );
    void setAlpha( Uint8 alpha );

    // render an image to window
    void renderText( std::string textureText, SDL_Color textColor );
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    void render();
    void render(const SDL_Rect &src,const SDL_Rect &dst);
    void render(const SDL_Rect &dst);
    void render(const SDL_Rect &src,const SDL_Rect &dst, double &degree, SDL_Point* center, SDL_RendererFlip flip);
    void free();
};


