#pragma once
#include <SDL.h>
#include "xulyhinhanh.h"
enum PauseGameChoice{
    PAUSE_BACK,
    PAUSE_SAVE,
    PAUSE_MENU_MAIN,
    PAUSE_NEW_GAME,
    PAUSE_MUSIC,
    PAUSE_SOUND,
    PAUSE_KING_IS_ATTACKED,
    PAUSE_CAN_GO,
    PAUSE_CAN_EAT,
    PAUSE_CHESS1,
    PAUSE_CHESS2,
    TOTAL_PAUSE
};

class PauseMenu{
    // SDL_Point 
    int viensetting;
    SDL_Point MousePos;
    MyTexture* ImageMenu;
    MyTexture* ChoiceMenu;
    PauseGameChoice state;
    bool SaveOn;
    bool KingisAttacked, Caneat, Cango;
    bool TypeChess;
    bool Music_On, SoundEffect_On;
    public:
    PauseMenu();
    PauseGameChoice HandleEventMouse();
    void setPauseMenu();
    void renderPauseMenu();
};