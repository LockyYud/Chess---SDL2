#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <xulyhinhanh.h>
#include <chessman.h>

const int window_height = 640;
const int window_width = 640;
const int size_img_chess = 60;
class image{
    public:
    image() {};
    ~image() {};
    void init();
    void loadMedia();
    void close();
};
#include <common.h>