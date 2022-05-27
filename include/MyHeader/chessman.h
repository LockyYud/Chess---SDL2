#pragma once
#include "xulyhinhanh.h"
enum name_chess{
    Empty = 0,
    King = 1,
    Queen = 2,
    Bishop = 3,
    Knight = 4,
    Rook = 5,
    Pawn = 6
};

class chess_man{
    protected:
    SDL_Point pos;
    name_chess name;
    bool isWhite;
    int vien;
    public:
    MyTexture* chessTex;
    bool isLive = true;
    bool isMoving = false;
    chess_man();
    ~chess_man(){};
    void Setposition(const int &x, const int &y);
    void renderchess();
    bool getcolor();
    void loadImage();
    int getPosX();
    int getPosY();
    name_chess getName();
    virtual bool box_can_go(int boxPosX, int boxPosY);
    bool inside(int, int);
};