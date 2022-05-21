#pragma once
#include "chessman.h"
class PAWN: public chess_man{
    public:
    PAWN(bool isWhite, int x, int y);
    ~PAWN();
    bool box_can_go(int boxPosX, int boxPosY);
};
