#include "Knight.h"
#include "common.h"
KNIGHT::KNIGHT(bool isWhite, int x, int y)
{
    this->isWhite = isWhite;
    this->name = Knight;
    pos.x = x;
    pos.y = y;
    this->loadImage();
}

KNIGHT::~KNIGHT()
{

}

bool KNIGHT::box_can_go(int boxPosX, int boxPosY)
{
    if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) == NULL or *Maps[MapStep::now].takeColor(boxPosX,boxPosY) != isWhite)
    {
        for(int i = 0; i < 4; i++)
        {
            if(boxPosX == pos.x + 2 * pow(-1,i) and boxPosY == pos.y + (i - 1.5)/abs( i - 1.5)) return true;
            if(boxPosX == pos.x + 1 * pow(-1,i) and boxPosY == pos.y + 2 * (i - 1.5)/abs( i - 1.5)) return true;
        }
    }
    return false;
}