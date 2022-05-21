#include "Bishop.h"
#include "common.h"
BISHOP::BISHOP(bool isWhite, int x, int y)
{
    this->isWhite = isWhite;
    this->name = Bishop;
    pos.x = x;
    pos.y = y;
    this->loadImage();
}

BISHOP::~BISHOP()
{

}
bool BISHOP::box_can_go(int boxPosX, int boxPosY)
{
    if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) != NULL) if(*Maps[MapStep::now].takeColor(boxPosX,boxPosY) == isWhite) return false;
    if(abs(boxPosX - pos.x) != abs(boxPosY - pos.y)) return false;
    while(true)
    {
        boxPosX = boxPosX - (boxPosX - pos.x)/abs(boxPosX - pos.x);
        boxPosY = boxPosY - (boxPosY - pos.y)/abs(boxPosY - pos.y);
        if(boxPosX == pos.x) break;
        if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) != NULL) return false;
    }
    return true;
}