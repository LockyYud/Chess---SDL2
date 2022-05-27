#include "HandleEvent.h"
#include "common.h"
#include "chessman.h"
bool can_castleW_L = true;
bool can_castleW_R = true;
bool can_castleB_L = true;
bool can_castleB_R = true;
std::pair<bool,bool> Castle = {true, true};
HandleMouse::HandleMouse(bool &luotchoi)
{
    MousePos.x = 0;
    MousePos.y = 0;
    luot_choi = &luotchoi;
    vien = ( window_height - 8 * size_img_chess) / 2;
}

HandleMouse::HandleMouse()
{
    MousePos.x = 0;
    MousePos.y = 0;
}

void HandleMouse::UpdateMousePos()
{
    SDL_GetMouseState(&MousePos.x, &MousePos.y);
}

bool HandleMouse::OnBoard()
{
    SDL_GetMouseState(&MousePos.x, &MousePos.y);
    if (MousePos.x >= vien and MousePos.y >= vien and MousePos.x <= window_width - vien and MousePos.y <= window_height - vien)
    {
        return true;
    }
    else
        return false;
}

Option HandleMouse::handle_event_option()
{
    if (MousePos.x >= 5 and MousePos.y >= 5 and MousePos.x <= 40 + 5 and MousePos.y <= 40 + 5)
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
            return Option::OPTION;
    }
    if (MousePos.x >= window_height - 40 - 5 and MousePos.y >= 5 and MousePos.x <= window_height - 5 and MousePos.y <= 40 + 5)
    {
        if (e.type == SDL_MOUSEBUTTONDOWN)
            return Option::RETURN;
    }
    return Option::khongcogi;
}

bool HandleMouse::handle_event_peices(chess_man **peice_chess)
{
    int Posx, Posy;
    Posx = (MousePos.x - vien) / size_img_chess + 1;
    Posy = (MousePos.y - vien) / size_img_chess + 1;
    if (e.type == SDL_MOUSEMOTION or e.type == SDL_MOUSEBUTTONDOWN)
    {
        for (int i = 0; i < 16; i++)
        {
            if (!peice_chess[i]->isLive)
                continue;
            if (peice_chess[i]->inside(Posx, Posy) and e.type == SDL_MOUSEBUTTONDOWN and !peice_chess[i]->isMoving and !da_chon)
            {
                peice_chess[i]->isMoving = true;
                da_chon = true;
                if(SoundEffectOn) Mix_PlayChannel(-1,PeiceOut,0);
                return true;
            }
            else if (peice_chess[i]->inside(Posx, Posy) and e.type == SDL_MOUSEBUTTONDOWN and peice_chess[i]->isMoving and da_chon)
            {
                peice_chess[i]->isMoving = false;
                da_chon = false;
                if(SoundEffectOn) Mix_PlayChannel(-1,PeiceIn,0);
                return true;
            }
            if (peice_chess[i]->isMoving and e.type == SDL_MOUSEBUTTONDOWN and peice_chess[i]->box_can_go(Posx, Posy) and da_chon)
            {
                for (int i = MapStep::five_step; i != MapStep::now; i++)
                {
                    Maps[i] = Maps[i + 1];
                }
                // todo: an tot qua duong
                if (peice_chess[i]->getName() == name_chess::Pawn)
                {
                    if (Posx - peice_chess[i]->getPosX() != 0 and Maps[MapStep::now].getNumber(Posx, Posy) == 16)
                    {
                        int buoc;
                        if (peice_chess[i]->getcolor())
                            buoc = 1;
                        else
                            buoc = -1;
                        Maps[MapStep::now].MoveChess(Posx, Posy, Posx, Posy + buoc);
                    }
                }

                // todo nhap thanh
                if(peice_chess[i]->getName() == name_chess::King)
                {
                    if(peice_chess[i]->getPosX() + 2 == Posx)
                    {
                        Maps[MapStep::now].MoveChess(peice_chess[i]->getPosX() + 3, peice_chess[i]->getPosY(), peice_chess[i]->getPosX() + 1, peice_chess[i]->getPosY());
                    }
                    if(peice_chess[i]->getPosX() - 2 == Posx)
                    {
                        Maps[MapStep::now].MoveChess(peice_chess[i]->getPosX() - 4, peice_chess[i]->getPosY(), peice_chess[i]->getPosX() - 1, peice_chess[i]->getPosY());
                    }
                }

                // dieu kien nhap thanh
                if (peice_chess[i]->getName() == name_chess::King or peice_chess[i]->getName() == name_chess::Rook)
                {
                    if (peice_chess[i]->getcolor())
                        Castle.first = false;
                    else
                        Castle.second = false;
                }

                Maps[MapStep::now].MoveChess(peice_chess[i]->getPosX(), peice_chess[i]->getPosY(), Posx, Posy);
                peice_chess[i]->isMoving = false;
                da_chon = false;
                *luot_choi = !*luot_choi;
                if(SoundEffectOn) Mix_PlayChannel(-1,PeiceIn,0);  
                return true;
            }
        }
    }
    return false;
}

Game_Result HandleMouse::handle_event_game_result()
{
    float ti_le = float(window_height) / EndGame[0].get_height();
    
    if(MousePos.x > 111*ti_le and MousePos.x < 211*ti_le and MousePos.y > 318*ti_le and MousePos.y < 366*ti_le)
    {
        return Game_Result::PLAY_AGAIN;
    }
    if(MousePos.x > 275*ti_le and MousePos.x < 423*ti_le and MousePos.y > 318*ti_le and MousePos.y < 366*ti_le)
    {
        return Game_Result::BACK_TO_MENU;
    }
    return Game_Result::TRONG;
}