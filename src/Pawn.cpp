#include "Pawn.h"
#include "common.h"

PAWN::PAWN(bool isWhite, int x, int y)
{
    this->isWhite = isWhite;
    name = name_chess::Pawn;
    pos.x = x;
    pos.y = y;
    this->loadImage();
}
PAWN::~PAWN()
{
}

bool PAWN::box_can_go(int boxPosX, int boxPosY)
{
    int buoc = 0;
    if(boxPosX == pos.x and boxPosY == pos.y) return false;
    if(isWhite) buoc = -1; else buoc = 1;
    if((boxPosX - pos.x == 1 or boxPosX - pos.x == -1) and boxPosY - pos.y == buoc)
    {
        if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) != NULL)
        {
            if(isWhite != *Maps[MapStep::now].takeColor(boxPosX,boxPosY)) return true;
        }         
    }
    if(boxPosX == pos.x and boxPosY - pos.y == buoc)
    {
        if(Maps[MapStep::now].takeColor(boxPosX,boxPosY) == NULL) 
        {
            return true;
        }
    }
    if(boxPosX == pos.x)
    {
        if(pos.y == 7 and isWhite and boxPosY - pos.y == 2*buoc and Maps[MapStep::now].takeColor(boxPosX,boxPosY) == NULL and Maps[MapStep::now].takeColor(boxPosX,boxPosY - buoc) == NULL)
        {
            return true;
        }
        if(pos.y == 2 and !isWhite and boxPosY - pos.y == 2*buoc and Maps[MapStep::now].takeColor(boxPosX,boxPosY) == NULL and Maps[MapStep::now].takeColor(boxPosX,boxPosY - buoc) == NULL)
        {
            return true;
        }
    }
    if((boxPosX == pos.x + 1) and boxPosY == pos.y + buoc)
    {
        if(Maps[MapStep::one_step].getNumber(boxPosX, pos.y + 2*buoc) < 8 and Maps[MapStep::one_step].takeColor(boxPosX, pos.y + 2*buoc) != NULL)
        {
            if(*Maps[MapStep::one_step].takeColor(boxPosX, pos.y + 2*buoc) != isWhite)
            {
                if(Maps[MapStep::now].getNumber(boxPosX, pos.y) == Maps[MapStep::one_step].getNumber(boxPosX, pos.y + 2*buoc))
                {
                    if(*Maps[MapStep::now].takeColor(boxPosX, pos.y) != isWhite)
                    {
                        return true;
                    }
                }
            }
        }
    }
    if((boxPosX == pos.x - 1) and boxPosY == pos.y + buoc)
    {
        if(Maps[MapStep::one_step].getNumber(boxPosX, pos.y + 2*buoc) < 8 and Maps[MapStep::one_step].takeColor(boxPosX, pos.y + 2*buoc) != NULL)
        {
            if(*Maps[MapStep::one_step].takeColor(boxPosX, pos.y + 2*buoc) != isWhite)
            {
                if(Maps[MapStep::now].getNumber(boxPosX, pos.y) == Maps[MapStep::one_step].getNumber(boxPosX, pos.y + 2*buoc))
                {
                    if(*Maps[MapStep::now].takeColor(boxPosX, pos.y) != isWhite)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}