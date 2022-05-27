#pragma once
#include "GameLoop.h"
#include "BoardMenu.h"
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
    PauseMenu* Pause;
    SettingMenu* Setting;
    MainMenu* Main;
    state trang_thai;
    public:
    GameState();
    ~GameState();
    void HandleMouseEvent();
    void RenderImage();
    void InGame();
    void InMenu();
    void InSetting();   
    void InPauseGame();
    state getState();
    void setState(state);
};