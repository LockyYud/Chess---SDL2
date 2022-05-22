// So thu tu cac quan co:
// 8 : ROOK
// 9 : KNIGHT
// 10 : BISHOP
// 11 : QUEEN
// 12 : KING
// 13 : BISHOP
// 14 : KNIGHT
// 15 : ROOK
#include "GameLoop.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "common.h"
bool dung = true;
bool sai = false;
int TimeofGame = 30;
Map Maps[MapStep::total_step];
GameLoop::GameLoop()
{
    luot_choi = true;

    for (int i = 0; i < 8; i++)
    {
        white_chessman[i] = new PAWN(true, i + 1, 7);
        black_chessman[i] = new PAWN(false, i + 1, 2);
    }

    white_chessman[8] = new ROOK(true, 1, 8);
    white_chessman[9] = new KNIGHT(true, 2, 8);
    white_chessman[10] = new BISHOP(true, 3, 8);
    white_chessman[11] = new QUEEN(true, 4, 8);
    white_chessman[12] = new KING(true, 5, 8);
    white_chessman[13] = new BISHOP(true, 6, 8);
    white_chessman[14] = new KNIGHT(true, 7, 8);
    white_chessman[15] = new ROOK(true, 8, 8);

    black_chessman[8] = new ROOK(false, 1, 1);
    black_chessman[9] = new KNIGHT(false, 2, 1);
    black_chessman[10] = new BISHOP(false, 3, 1);
    black_chessman[11] = new QUEEN(false, 4, 1);
    black_chessman[12] = new KING(false, 5, 1);
    black_chessman[13] = new BISHOP(false, 6, 1);
    black_chessman[14] = new KNIGHT(false, 7, 1);
    black_chessman[15] = new ROOK(false, 8, 1);

    Mouse = new HandleMouse(luot_choi);

    Selected = new ChessObject(chess_object::PEICE_SELECTED);

    Kingisattacked = new ChessObject(chess_object::KING_IS_ATTACKED);

    running = true;

    result = Game_Result::TRONG;

    timetoPlay = 60 * 60000;
    WhiteTime = 30 * 60000;
    BlackTime = 30 * 60000;
    TimeEndGame = 0;
    
    OptiongChoice = Option::khongcogi;
}

GameLoop::~GameLoop()
{
    for(int i = 0; i < 16; i++)
    {
        delete white_chessman[i];
        delete black_chessman[i];
    }
    delete Mouse;
    delete Selected;
    delete Kingisattacked;
    for(int i = MapStep::five_step; i != MapStep::total_step; i++)
    {
        Maps[i].lammoiMap();
    }
}

void GameLoop::SetTime()
{
    timetoPlay = TimeofGame * 60000 * 2;
    WhiteTime = TimeofGame * 60000;
    BlackTime = TimeofGame * 60000;
}

void GameLoop::LoadPiecesToScreen()
{
    for (int i = 0; i < 16; i++)
    {
        if (black_chessman[i]->isLive)
            black_chessman[i]->renderchess();
        if (white_chessman[i]->isLive)
        {
            white_chessman[i]->renderchess();
        }
    }
}

void GameLoop::LoadGameBoardtoScreen()
{
    SDL_Rect dst;
    dst.x = (window_width - 540) / 2;
    dst.y = (window_height - 540) / 2;
    dst.h = dst.w = 540;
    chessboard.render(dst);
    if (Selected->on)
    {
        Selected->render();
        if(CanGoOn)
            for (int i = 0; i < cango.size(); i++)
            {
                cango[i]->render();
            }
        if(CanEatOn)
            for (int i = 0; i < caneat.size(); i++)
            {
                caneat[i]->render_nhapnhay();
            }
    }
    
    if(KingIsAttackedOn)
        for(int i = 0; i < 16; i++)
        {
            // if(luot_choi)
            // {
                if(black_chessman[i]->box_can_go(white_chessman[12]->getPosX(), white_chessman[12]->getPosY()) and black_chessman[i]->isLive)
                {
                    Kingisattacked->setpos(white_chessman[12]->getPosX(), white_chessman[12]->getPosY());
                    Kingisattacked->render_nhapnhay();
                }
            // }
            // else
            // {
                if(white_chessman[i]->box_can_go(black_chessman[12]->getPosX(), black_chessman[12]->getPosY()) and white_chessman[i]->isLive)
                {
                    Kingisattacked->setpos(black_chessman[12]->getPosX(), black_chessman[12]->getPosY());
                    Kingisattacked->render_nhapnhay();
                }
            // }
        }
}

void GameLoop::PlayerTime()
{
    Uint32 timenow = SDL_GetTicks();
    if (result == Game_Result::TRONG)
    {
        if (luot_choi)
        {
            WhiteTime = (timetoPlay - BlackTime - (timenow - StartTime));
        }
        else
        {
            BlackTime = (timetoPlay - WhiteTime - (timenow - StartTime));
        }
    }
    std::stringstream timeWhite, timeBlack;
    timeWhite.str("");
    if (WhiteTime / 60000 < 10)
    {
        timeWhite << "0" << WhiteTime / 60000 << ":";
    }
    else
        timeWhite << WhiteTime / 60000 << ":";
    if ((WhiteTime / 1000) % 60 < 10)
    {
        timeWhite << "0" << (WhiteTime / 1000) % 60;
    }
    else
        timeWhite << (WhiteTime / 1000) % 60;
    timeBlack.str("");
    if (BlackTime / 60000 < 10)
    {
        timeBlack << "0" << BlackTime / 60000 << ":";
    }
    else
        timeBlack << BlackTime / 60000 << ":";
    if ((BlackTime / 1000) % 60 < 10)
    {
        timeBlack << "0" << (BlackTime / 1000) % 60;
    }
    else
        timeBlack << (BlackTime / 1000) % 60;
    SDL_Color textColor;
    if (!luot_choi)
        textColor = {255, 255, 255, 255};
    else
        textColor = {128, 128, 128, 255};
    GameFont.renderText(timeBlack.str().c_str(), textColor);
    GameFont.render((window_height - GameFont.get_width()) / 2, 40 - GameFont.get_height());
    if (luot_choi)
        textColor = {255, 255, 255, 255};
    else
        textColor = {128, 128, 128, 255};
    GameFont.renderText(timeWhite.str().c_str(), textColor);
    GameFont.render((window_height - GameFont.get_width()) / 2, window_height - 40);
}

void GameLoop::LoadOptionToScreen()
{
    option[int(Option::OPTION)].render(5, 5);
    option[int(Option::RETURN)].render(window_height - 40 - 5, 5);
}

void GameLoop::EventMouse()
{
    Mouse->UpdateMousePos();
    OptiongChoice = Mouse->handle_event_option(); 
    if(result == Game_Result::TRONG)
    {
        if (OptiongChoice == Option::RETURN)
        {
            Maps[MapStep::one_step].SetChessPos(white_chessman, black_chessman);

            if (Maps[MapStep::one_step] != Maps[MapStep::now])
                luot_choi = !luot_choi;

            for (int i = MapStep::now; i != MapStep::five_step; i--)
            {
                Maps[i] = Maps[i - 1];
            }
        }
        if (Mouse->OnBoard())
        {
            if (luot_choi)
            {
                if(Mouse->handle_event_peices(white_chessman))
                {
                    this->checkObject();
                }
            }
            else
            {
                if(Mouse->handle_event_peices(black_chessman))
                {
                    this->checkObject();
                }
            }
            Maps[MapStep::now].SetChessPos(white_chessman, black_chessman);
        }
    }
    else{
        if(End_Game.second == false)
            switch(Mouse->handle_event_game_result())
            {
                case Game_Result::PLAY_AGAIN:
                    End_Game.first = Game_Result::PLAY_AGAIN;
                    if(e.type == SDL_MOUSEBUTTONDOWN) End_Game.second = true;
                    break;
                case Game_Result::BACK_TO_MENU:
                    End_Game.first = Game_Result::BACK_TO_MENU;
                    if(e.type == SDL_MOUSEBUTTONDOWN) End_Game.second = true;
                    break;
                default:
                    End_Game.first = Game_Result::TRONG;
                    break;
            }
    }
}

bool GameLoop::GameRunning()
{
    if(result == Game_Result::TRONG)
    {
        if (!white_chessman[12]->isLive)
        {
            result = Game_Result::BLACK_WIN;
            TimeEndGame = SDL_GetTicks();
        }
        if (!black_chessman[12]->isLive)
        {
            result = Game_Result::WHITE_WIN;
            TimeEndGame = SDL_GetTicks();
        }
    }
    return running;
}

void GameLoop::checkObject()
{
    Selected->on = false;
    cango.clear();
    caneat.clear();
    for (int i = 0; i < 16; i++)
    {
        if (black_chessman[i]->isMoving and black_chessman[i]->isLive)
        {
            Selected->setpos(black_chessman[i]->getPosX(), black_chessman[i]->getPosY());
            Selected->on = true;
            for (int k = 1; k <= 8; k++)
            {
                for (int j = 1; j <= 8; j++)
                {
                    if (black_chessman[i]->box_can_go(k, j))
                    {
                        if(Maps[MapStep::now].takeColor(k, j) != NULL)
                        {
                            if (black_chessman[i]->getcolor() != *Maps[MapStep::now].takeColor(k, j))
                            {
                                ChessObject *can_eat = new ChessObject(chess_object::PEICE_CAN_EAT);
                                can_eat->setpos(k, j);
                                caneat.push_back(can_eat);
                            }
                        }
                        else
                        {
                            ChessObject *can_go = new ChessObject(chess_object::PEICE_CAN_GO);
                            can_go->setpos(k, j);
                            cango.push_back(can_go);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 16; i++)
    {
        if (white_chessman[i]->isMoving and white_chessman[i]->isLive)
        {
            Selected->setpos(white_chessman[i]->getPosX(), white_chessman[i]->getPosY());
            Selected->on = true;
            for (int k = 1; k <= 8; k++)
            {
                for (int j = 1; j <= 8; j++)
                {
                    if (white_chessman[i]->box_can_go(k, j))
                    {
                        if(Maps[MapStep::now].takeColor(k, j) != NULL)
                        {
                            if (white_chessman[i]->getcolor() != *Maps[MapStep::now].takeColor(k, j))
                            {
                                ChessObject *can_eat = new ChessObject(chess_object::PEICE_CAN_EAT);
                                can_eat->setpos(k, j);
                                caneat.push_back(can_eat);
                            }
                        }
                        else
                        {
                            ChessObject *can_go = new ChessObject(chess_object::PEICE_CAN_GO);
                            can_go->setpos(k, j);
                            cango.push_back(can_go);
                        }
                    }
                }
            }
        }
    }
}

Game_Result GameLoop::getGameResult()
{
    return result;
}

void GameLoop::renderResult()
{
    BackGround.setAlpha(155);
    BackGround.render();
    if (result == Game_Result::BLACK_WIN)
    {
        ingame[int(Game_Result::BLACK_WIN)].render();
    }
    if (result == Game_Result::WHITE_WIN)
    {
        ingame[int(Game_Result::WHITE_WIN)].render();
    }
    if (result == Game_Result::DRAW)
        ingame[int(Game_Result::DRAW)].render();
  
    SDL_Rect src;
    SDL_Rect dst;
    Uint32 timenow = SDL_GetTicks();
    if(timenow - TimeEndGame > 1000)
    {
        EndGame[1].setAlpha(255);
        switch(End_Game.first)
        {
            case Game_Result::PLAY_AGAIN:
                src = {0 , 0 , 250 , 500};
                dst = {0 ,0 , window_height/2 , window_height};
                EndGame[0].render(src, dst);
                src = {250 , 0 , 250 , 500};
                dst = {window_height/2 ,0 , window_height/2 , window_height};
                EndGame[1].render(src, dst);
                break;
            case Game_Result::BACK_TO_MENU:
                src = {250 , 0 , 250 , 500};
                dst = {window_height/2 ,0 , window_height/2 , window_height};
                EndGame[0].render(src, dst);
                src = {0 , 0 , 250 , 500};
                dst = {0 ,0 , window_height/2 , window_height};
                EndGame[1].render(src, dst);
                break;
            default:
                EndGame[1].render();
                break;
        }
    }
    else{
        EndGame[1].setAlpha((timenow - TimeEndGame) * 255 / 5000);
        EndGame[1].render();
    }
}

void GameLoop::SetTypeChess()
{
    for (int i = 0; i < 16; i++)
    {
        white_chessman[i]->loadImage();
        black_chessman[i]->loadImage();
    }
}

void GameLoop::CheckGameSpecial()
{
    //todo phong hau
    for (int i = 0; i < 8; i++)
    {
        if(white_chessman[i]->getName() == name_chess::Pawn)
        {
            if (white_chessman[i]->getPosY() == 1)
            {
                int x = white_chessman[i]->getPosX();
                int y = white_chessman[i]->getPosY();
                white_chessman[i] = new QUEEN(true, x, y);
            }
            if (white_chessman[i]->getPosY() == 8)
            {
                int x = white_chessman[i]->getPosX();
                int y = white_chessman[i]->getPosY();
                white_chessman[i] = new QUEEN(false, x, y);
            }
        }
    }

    //todo dieu kien nhap thanh
    if(luot_choi)
        if(can_castleW_L == true or can_castleW_R == true)
            for(int i = 0; i < 16; i++)
            {
                for(int j = 2; j <= 7; j++)
                {
                    if(black_chessman[i]->isLive and black_chessman[i]->box_can_go(j ,white_chessman[12]->getPosY()))
                    {
                        if(j == white_chessman[12]->getPosX()) can_castleW_L = can_castleW_R = false;
                        if(j > white_chessman[12]->getPosX()) can_castleW_R = false;
                        if(j < white_chessman[12]->getPosX()) can_castleW_L = false;
                        return;
                    }
                }
            }
    else
        if(can_castleB_L == true or can_castleB_R == true)
            for(int i = 0; i < 16; i++)
            {
                for(int j = 2; j <= 7; j++)
                {
                    if(white_chessman[i]->isLive and white_chessman[i]->box_can_go(j ,black_chessman[12]->getPosY()))
                    {
                        if(j == black_chessman[12]->getPosX()) can_castleB_L = can_castleB_R = false;
                        if(j > black_chessman[12]->getPosX()) can_castleB_R = false;
                        if(j < black_chessman[12]->getPosX()) can_castleB_L = false;
                        return;
                    }
                }
            }
    if(luot_choi) can_castleW_L = can_castleW_R = true;
    else can_castleB_L = can_castleB_R = true;
}
