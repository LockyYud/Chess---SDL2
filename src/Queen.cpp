#include "Queen.h"
#include "common.h"
QUEEN::QUEEN(bool isWhite, int x, int y)
{
    this->isWhite = isWhite;
    this->name = Queen;
    pos.x = x;
    pos.y = y;
    this->loadImage();
}
QUEEN::~QUEEN()
{

}
bool QUEEN::box_can_go(int boxPosX, int boxPosY)
{
    if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) != NULL) if(*Maps[MapStep::now].takeColor(boxPosX,boxPosY) == isWhite) return false;
    if(abs(boxPosX - pos.x) == abs(boxPosY - pos.y))
    {
        while(true)
        {
            boxPosX = boxPosX - (boxPosX - pos.x)/abs(boxPosX - pos.x);
            boxPosY = boxPosY - (boxPosY - pos.y)/abs(boxPosY - pos.y);
            if(boxPosX == pos.x) break;
            if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) != NULL) return false;
        }
        return true;
    }
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
    return false;
}