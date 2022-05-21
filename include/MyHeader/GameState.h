#pragma once
#include "GameLoop.h"
#include "GameMenu.h"
#include "PauseMenu.h"
enum state{
    IN_GAME,
    END_GAME,
    QUIT_GAME,
    MENU_GAME,
    SETTING_GAME,
    PAUSE_MENU,
    TOTAL_STATE
};
class GameState{
    private:
    GameLoop* Game_Loop;
    GameMenu* Game_Choice;
    PauseMenu* Pause_menu;
    state trang_thai;
    public:
    GameState();
    ~GameState();
    void HandleMouseEvent();
    void InGame();
    void InMenu();
    void InSetting();   
    void InPauseGame();
    state getState();
    void setState(state);
};