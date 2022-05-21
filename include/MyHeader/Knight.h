#pragma once
#include "chessman.h"
#include "cmath"
class KNIGHT: public chess_man{
    public:
    KNIGHT(bool isWhite, int x, int y);
    ~KNIGHT();
    bool box_can_go(int boxPosX, int boxPosY);
};