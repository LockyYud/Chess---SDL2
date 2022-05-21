#pragma once
#include "HandleEvent.h"
enum G_Choice{
    MENU,
    MENU_CHOICE,
    _SETTING,
    _SETTING_CHOICE,
    _SETTING_CHOOSES,
    TOTAL_CHOICE
};
enum MenuChoice{
    PLAY,
    SETTING,
    QUIT,
    NOTHING_MENU
};
enum SettingChoice{
    BACK,
    SAVE,
    TIME_PLUS,
    TIME_MINUS,
    MUSIC,
    SOUND,
    CHESS1,
    CHESS2,
    NOTHING_SETTING
};
class GameMenu{
    private:
    int do_mo = 0;
    int vienSetting;
    SDL_Point MousePos;
    SettingChoice PlayerSettingChoice;
    MenuChoice PlayerMenuChoice;
    bool TypeofChess;
    bool SaveOn;
    bool MusicInGame;
    bool SoundEffectInGame;
    int GameTime;
    public:
    int bat_dau;
    GameMenu();
    ~GameMenu();
    MenuChoice EventMouseMenu();
    SettingChoice EventMouseSetting();
    bool run();
    void renderMenuGame();
    void renderSetting();
    void renderSettingChooses();
    void renderMenuGameChooses();
};

