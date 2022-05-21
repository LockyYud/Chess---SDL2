#pragma once

#include "chessman.h"
class BISHOP: public chess_man
{
    public:
    BISHOP(bool isWhite, int x, int y);
    ~BISHOP();
    bool box_can_go(int boxPosX, int boxPosY);
};