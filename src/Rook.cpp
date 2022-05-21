#include "Rook.h"
#include "common.h"
ROOK::ROOK(bool isWhite, int x, int y)
{
    this->isWhite = isWhite;
    name = name_chess::Rook;
    pos.x = x;
    pos.y = y;
    this->loadImage();
}

bool ROOK::box_can_go(int boxPosX, int boxPosY)
{
    if(boxPosX == pos.x and boxPosY == pos.y) return false;
    if(boxPosX != pos.x and boxPosY != pos.y) return false;
    if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) != NULL) if(isWhite == *Maps[MapStep::now].takeColor(boxPosX,boxPosY)) return false;
    if(boxPosY == pos.y)
    {
        int buoc;
        if(boxPosX > pos.x) buoc = 1; else buoc = -1;
        for(int i = pos.x + buoc; i != boxPosX; i = i + buoc)
        {
            if(Maps[MapStep::now].takeColor(i,pos.y) != NULL) return false;
        }
        return true;
    }
    if(boxPosX == pos.x)
    {
        int buoc;
        if(boxPosY > pos.y) buoc = 1; else buoc = -1;
        for(int i = pos.y + buoc; i != boxPosY; i = i + buoc)
        {
            if(Maps[MapStep::now].takeColor(pos.x,i) != NULL) return false;
        }
        return true;
    }
    return true;
}

ROOK::~ROOK()
{
    
}