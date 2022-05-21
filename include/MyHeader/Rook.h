#pragma once
#include "chessman.h"
class ROOK: public chess_man{
    public:
    ROOK(bool isWhite, int x, int y);
    ~ROOK();
    bool box_can_go(int boxPosX, int boxPosY);
};
