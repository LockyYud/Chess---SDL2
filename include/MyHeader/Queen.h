#pragma once
#include "chessman.h"
class QUEEN: public chess_man{
    public:
    QUEEN(bool isWhite, int x, int y);
    ~QUEEN();
    bool box_can_go(int boxPosX, int boxPosY);
};