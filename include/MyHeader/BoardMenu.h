
#pragma once
#include <SDL.h>
#include "xulyhinhanh.h"

enum TypeBoardMenu{
    MAIN_MENU,
    MAIN_MENU_CHOOSES,
    SEETING_MENU,
    SEETING_MENU_BOARD,
    SEETING_MENU_CHOOSES,
    PAUSE_MENU_,
    PAUSE_MENU_CHOOSES,
    END_GAME_BOARD,
    END_GAME_CHOOSES,
    TOTAL_MENU
};


enum MenuMainChoice{
    MENU_MAIN_PLAY,
    MENU_MAIN_SETTING,
    MENU_MAIN_QUIT,
    MENU_MAIN_TOTAL,
};

enum MenuSettingChoice{
    MENU_SETTING_SAVE,
    MENU_SETTING_TIME_PLUS,
    MENU_SETTING_TIME_MINUS,
    MENU_SETTING_CHESS1,
    MENU_SETTING_CHESS2,
    MENU_SETTING_MUSIC,
    MENU_SETTING_SOUND,
    MENU_SETTING_BACK,
    MENU_SETTING_TOTAL
};

enum MenuPauseChoice{
    MENU_PAUSE_BACK,
    MENU_PAUSE_SAVE,
    MENU_PAUSE_MENU_MAIN,
    MENU_PAUSE_NEW_GAME,
    MENU_PAUSE_MUSIC,
    MENU_PAUSE_SOUND,
    MENU_PAUSE_KING_IS_ATTACKED,
    MENU_PAUSE_CAN_GO,
    MENU_PAUSE_CAN_EAT,
    MENU_PAUSE_CHESS1,
    MENU_PAUSE_CHESS2,
    MENU_PAUSE_TOTAL
};

class BoardMenu{
    protected:
    SDL_Point MousePos;
    int vien_board;
    bool TypeofChess;
    bool SaveOn;
    bool Music_On;
    bool SoundEffect_On;
    MyTexture* ImageMain;
    MyTexture* ImageChooses;
    public:
    BoardMenu();
};

class MainMenu: public BoardMenu{
    MenuMainChoice state_now;
    public:
    MainMenu();
    MenuMainChoice HandleMouseEvent();
    void Render_to_screen();
};

class SettingMenu: public BoardMenu{
    MenuSettingChoice state_now;
    MyTexture* BoardSetting;
    int GameTime;
    bool BackOn;
    public:
    int disappear;
    Uint8 appear;
    SettingMenu();
    MenuSettingChoice HandleMouseEvent();
    void Render_Board();
    void Render_to_screen();
    void SetToDefault();
};

class PauseMenu: public BoardMenu{
    MenuPauseChoice state_now;
    int GameTime;
    bool KingisAttacked, Caneat, Cango;
    public:
    Uint8 appear;
    Uint8 disappear;
    bool BackOn;
    PauseMenu();
    MenuPauseChoice HandleMouseEvent();
    void Render_to_screen();
    void SetToDefault();
};