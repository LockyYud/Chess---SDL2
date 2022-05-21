#pragma once
#include <vector>
#include "chessman.h"
#include "HandleEvent.h"
#include "ChessObject.h"


class GameLoop{
    private:
    bool running;
    bool luot_choi = true;
    Uint32 WhiteTime;
    Uint32 BlackTime;
    HandleMouse* Mouse;
    Game_Result result;
    std::vector<ChessObject*> cango;
    std::vector<ChessObject*> caneat;
    ChessObject* Kingisattacked;
    public:
    std::pair<Game_Result, bool> End_Game;
    Option OptiongChoice;
    Uint32 timetoPlay;
    Uint32 StartTime;
    Uint32 TimeEndGame;

    GameLoop();
    ~GameLoop();
    chess_man* white_chessman[16];
    chess_man* black_chessman[16];
    ChessObject* Selected;
    void EventMouse();
    void LoadPiecesToScreen();
    void LoadGameBoardtoScreen();
    void LoadOptionToScreen();
    void PlayerTime();
    void SetTime();
    bool GameRunning();
    void checkObject();
    void renderResult();
    Game_Result getGameResult();
    void SetTypeChess();
    void CheckGameSpecial();
};