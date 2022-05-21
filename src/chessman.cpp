#include "chessman.h"
#include "common.h"

bool Type_Chess = true;
chess_man::chess_man()
{
    name = Empty;
    chessTex = new MyTexture;
    pos.x = 0;
    pos.y = 0;
}
void chess_man::Setposition(const int &x, const int &y)
{
    pos.x = x;
    pos.y = y;
}

void chess_man::renderchess()
{
    SDL_Rect dst;
    dst.x = vien + (pos.x - 1) * size_img_chess;
    dst.y = vien + (pos.y - 1) * size_img_chess;
    dst.h = dst.w = size_img_chess;
    chessTex->render(dst);
}

void chess_man::loadImage()
{
    if(!Type_Chess)
    {
        if(!isWhite) chessTex = &white_chess[int(name)];
        else chessTex = &black_chess[int(name)];
    }
    else
    {
        if(!isWhite) chessTex = &white_chess3d[int(name)];
        else chessTex = &black_chess3d[int(name)];
    }
}

name_chess chess_man::getName()
{
    return name;
}

int chess_man::getPosX()
{
    return pos.x;
}

int chess_man::getPosY()
{
    return pos.y;
}

bool chess_man::box_can_go(int boxPosX, int boxPosY)
{
    return true;
}

bool chess_man::inside(int x, int y)
{
    if(x == pos.x and y == pos.y)
    {
        return true;
    }
    return false;
}

bool chess_man::getcolor()
{
    return isWhite;
}