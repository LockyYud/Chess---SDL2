#pragma once

#include "chessman.h"
class KING: public chess_man{
    public:
    KING(bool isWhite, int x, int y);
    ~KING();
    bool box_can_go(int boxPosX, int boxPosY);
};