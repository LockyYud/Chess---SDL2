#pragma once
#include "chessman.h"
#include "ChessObject.h"
enum Option{
    khongcogi,
    OPTION,
    OPTION_CHOICE,
    RETURN,
    TOTAL_OPTION
};
enum Game_Result{
    WHITE_WIN,
    BLACK_WIN,
    DRAW,
    PLAY_AGAIN,
    BACK_TO_MENU,
    TRONG
};
class HandleMouse{
    private:
    SDL_Point MousePos;
    bool da_chon = false;
    bool* luot_choi;
    public:
    HandleMouse(bool &luotchoi);
    HandleMouse();
    bool OnBoard();
    void UpdateMousePos();
    Option handle_event_option();
    Game_Result handle_event_game_result();
    bool handle_event_peices(chess_man** peices_peices);
};