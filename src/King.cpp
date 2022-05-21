#include "King.h"
#include "common.h"
KING::KING(bool isWhite, int x, int y)
{
    this->isWhite = isWhite;
    this->name = King;
    this->pos.x = x;
    this->pos.y = y;
    this->loadImage();
}
KING::~KING()
{

}
bool KING::box_can_go(int boxPosX, int boxPosY)
{
    bool mauT = (isWhite)? can_castleW_L : can_castleB_L;
    bool mauP = (isWhite)? can_castleW_R : can_castleB_R;
    bool mau = (isWhite)? Castle.first : Castle.second;
    if(mau)
    {
        if(boxPosX == pos.x - 2 and boxPosY == pos.y)
        {
            if(Maps[MapStep::now].takeColor(pos.x - 2, pos.y) == NULL and Maps[MapStep::now].takeColor(pos.x - 3, pos.y) == NULL and Maps[MapStep::now].takeColor(pos.x - 1, pos.y) == NULL and Maps[MapStep::now].getNumber(pos.x - 4, pos.y) == 8 and mauT) return true;
        }
        if(boxPosX == pos.x + 2 and boxPosY == pos.y)
        {
            if(Maps[MapStep::now].takeColor(pos.x + 2, pos.y) == NULL and Maps[MapStep::now].takeColor(pos.x + 1, pos.y) == NULL and Maps[MapStep::now].getNumber(pos.x + 3, pos.y) == 15 and mauP) return true;
        }
    }
    if(pos.x - boxPosX < -1 or pos.x - boxPosX > 1 or pos.y - boxPosY < -1 or pos.y - boxPosY > 1) return false;
    if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) == NULL or *Maps[MapStep::now].takeColor(boxPosX,boxPosY) != isWhite) return true;
    return false;
}