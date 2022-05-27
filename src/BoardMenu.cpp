#include "common.h"
#include "BoardMenu.h"
bool CanGoOn = true;
bool CanEatOn = true;
bool KingIsAttackedOn = true;
//fuction Board
BoardMenu::BoardMenu()
{
    TypeofChess = Type_Chess;
    SaveOn = false;
    Music_On = MusicOn;
    SoundEffect_On = SoundEffect_On;
}

//fuction MainMenu
MainMenu::MainMenu()
{
    ImageMain = &ImageMenu[TypeBoardMenu::MAIN_MENU];
    ImageChooses = &ImageMenu[TypeBoardMenu::MAIN_MENU_CHOOSES];
    vien_board = 0;
    state_now = MenuMainChoice::MENU_MAIN_TOTAL;
}

MenuMainChoice MainMenu::HandleMouseEvent()
{
    SDL_GetMouseState(&MousePos.x, &MousePos.y);
    float ti_le = float(window_height) / ImageMain->get_height();
    // pos play: 75 - 174 : 95x350
    state_now = MenuMainChoice::MENU_MAIN_TOTAL;
    if(MousePos.x >= float(75*ti_le) and MousePos.x <= float((75 + 350)*ti_le) and MousePos.y >= float(174*ti_le) and MousePos.y <= float((174 + 95)*ti_le))
    {
        state_now = MenuMainChoice::MENU_MAIN_PLAY;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return MenuMainChoice::MENU_MAIN_PLAY;
        }
    }
    // pos setting: 75 - 267 : 95x350
    if(MousePos.x >= float(75*ti_le) and MousePos.x <= float((75 + 350)*ti_le) and MousePos.y >= float(267*ti_le) and MousePos.y <= float((267 + 95)*ti_le))
    {
        state_now = MenuMainChoice::MENU_MAIN_SETTING;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return MenuMainChoice::MENU_MAIN_SETTING;
        }
    }
    // pos quit: 75 - 363 : 95x350
    if(MousePos.x >= float(75*ti_le) and MousePos.x <= float((75 + 350)*ti_le) and MousePos.y >= float(363*ti_le) and MousePos.y <= float((363 + 95)*ti_le))
    {
        state_now = MenuMainChoice::MENU_MAIN_QUIT;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return MenuMainChoice::MENU_MAIN_QUIT;
        }
    }
    return MenuMainChoice::MENU_MAIN_TOTAL;
}

void MainMenu::Render_to_screen()
{
    ImageMain->setAlpha(255);
    ImageMain->render();
    SDL_Rect src, dst;
    src.x = 75;
    src.h = 95, src.w = 350;
    dst.x = (75*window_width)/500, dst.h = (95*window_height)/500, dst.w = (350*window_height)/500;
    int y_play = (174*window_height)/500, y_quit = (363*window_height)/500, y_setting = (267*window_height)/500;
    switch (state_now)
    {
        case MenuMainChoice::MENU_MAIN_PLAY:
            src.y = 174;
            dst.y = y_play;
            break;
        case MenuMainChoice::MENU_MAIN_SETTING:
            src.y = 267;
            dst.y = y_setting;
            break;
        case MenuMainChoice::MENU_MAIN_QUIT:
            src.y = 363;
            dst.y = y_quit;
            break;
        default:
            break;
    }
    ImageChooses->render(src,dst);
}

//fuction setting menu
SettingMenu::SettingMenu()
{
    ImageMain = &ImageMenu[TypeBoardMenu::SEETING_MENU];
    BoardSetting = &ImageMenu[TypeBoardMenu::SEETING_MENU_BOARD];
    ImageChooses = &ImageMenu[TypeBoardMenu::SEETING_MENU_CHOOSES];
    vien_board = (window_height - ImageMain->get_height())/2;
    state_now = MenuSettingChoice::MENU_SETTING_TOTAL;
    GameTime = TimeofGame;
    BackOn = false;
}

MenuSettingChoice SettingMenu::HandleMouseEvent()
{
    if(BackOn and disappear == 0) return MenuSettingChoice::MENU_SETTING_BACK;
    if(BackOn) return MenuSettingChoice::MENU_SETTING_TOTAL;
    SDL_GetMouseState(&MousePos.x, &MousePos.y);
    //back
    state_now = MenuSettingChoice::MENU_SETTING_TOTAL;
    if(MousePos.x >= 60 + vien_board and MousePos.x <= 235 + vien_board and MousePos.y >= 400 + vien_board and MousePos.y <= 500 - 63 + vien_board)
    {
        state_now = MenuSettingChoice::MENU_SETTING_BACK;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            BackOn = true;
        }
    }
    //save
    if(MousePos.x >= 280 + vien_board and MousePos.x <= 425 + vien_board and MousePos.y >= 400 + vien_board and MousePos.y <= 500 - 63 + vien_board)
    {
        state_now = MenuSettingChoice::MENU_SETTING_SAVE;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(SaveOn)
            {
                SaveOn = false;
                Type_Chess = TypeofChess;
                TimeofGame = GameTime;
                MusicOn = Music_On;
                SoundEffectOn = SoundEffect_On;
            }
            return MenuSettingChoice::MENU_SETTING_SAVE;
        }
    }
    //image chess
    // src.h = dst.h = 70;
    // src.w = dst.w = 30;
    if(MousePos.x >= 278 + vien_board and MousePos.x <= 278 + 30 + vien_board and MousePos.y >= 201 + vien_board and MousePos.y <= 250 + vien_board)
    {
        state_now = MenuSettingChoice::MENU_SETTING_CHESS1;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            TypeofChess = true;
            SaveOn = true;
            return MenuSettingChoice::MENU_SETTING_CHESS1;
        }
    }
    if(MousePos.x >= 339 + vien_board and MousePos.x <= 339 + 30 + vien_board and MousePos.y >= 201 + vien_board and MousePos.y <= 250 + vien_board)
    {
        state_now = MenuSettingChoice::MENU_SETTING_CHESS2;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            TypeofChess =  false;
            SaveOn = true;
            return MenuSettingChoice::MENU_SETTING_CHESS2;
        }
    }
    //time
    // src.h = dst.h = 26;
    // src.w = dst.w = 40;
    if(MousePos.x >= 365 + vien_board and MousePos.x <= 365 + 32 + vien_board and MousePos.y >= 100 + vien_board and MousePos.y <= 100 + 26 + vien_board)
    {
        state_now = MenuSettingChoice::MENU_SETTING_TIME_PLUS;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            GameTime += 5;
            SaveOn = true;
            return MenuSettingChoice::MENU_SETTING_TIME_PLUS;
        }
    }
    if(MousePos.x >= 365 + vien_board and MousePos.x <= 365 + 32 + vien_board and MousePos.y >= 134 + vien_board and MousePos.y <= 134 + 26 + vien_board)
    {
        state_now = MenuSettingChoice::MENU_SETTING_TIME_MINUS;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            GameTime -= 5;
            SaveOn = true;
            return MenuSettingChoice::MENU_SETTING_TIME_MINUS;
        }
    }

    if(MousePos.x >= 143 + vien_board and MousePos.x <= 203 + vien_board and MousePos.y >= 317 + vien_board and MousePos.y <= 377 + vien_board)
    {
        state_now = MenuSettingChoice::MENU_SETTING_MUSIC;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            Music_On = !Music_On;
            return MenuSettingChoice::MENU_SETTING_MUSIC;
        }
    }

    if(MousePos.x >= 289 + vien_board and MousePos.x <= 349 + vien_board and MousePos.y >= 317 + vien_board and MousePos.y <= 377 + vien_board)
    {
        state_now = MenuSettingChoice::MENU_SETTING_SOUND;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            SoundEffect_On = !SoundEffect_On;
            return MenuSettingChoice::MENU_SETTING_SOUND;
        }
    }
    return MenuSettingChoice::MENU_SETTING_TOTAL;
}

void SettingMenu::Render_Board()
{
    ImageMenu[TypeBoardMenu::MAIN_MENU].setAlpha(100);
    ImageMenu[TypeBoardMenu::MAIN_MENU].render();
    if(appear >= 255 - 10) appear = 255; else appear += 10;
    BoardSetting->setAlpha(appear);
    ImageMain->setAlpha(appear);
    if(BackOn)
    {
        ImageMain->setAlpha(disappear);
        ImageChooses->setAlpha(disappear);
        BoardSetting->setAlpha(disappear);
        GameFont.setAlpha(disappear);
        if(disappear < 15) disappear = 0; else disappear = disappear - 15; 
    }
    else
    {
        BoardSetting->setAlpha(appear);
        ImageMain->setAlpha(appear);
    }
    BoardSetting->render(vien_board,vien_board + 255 - appear);
    ImageMain->render(vien_board,vien_board + 255 - appear);
    //hien thi thoi gian
}

void SettingMenu::Render_to_screen()
{
    if(!BackOn)
    {
        GameFont.setAlpha(255);
        ImageChooses->setAlpha(255);
    }
    std::stringstream Time;
    Time << GameTime;
    SDL_Color color = {255,255,255,255};
    GameFont.renderText(Time.str().c_str(),color);
    GameFont.render( 310 + vien_board - GameFont.get_width()/2, 130 + vien_board - GameFont.get_height()/2);
    //60 - 400 -> 235 - 500 - 63
    //336 - 400 -> 508 - 500 - 63
    SDL_Rect src, dst;
    switch(state_now)
    {
        case MenuSettingChoice::MENU_SETTING_BACK:
            src.h = dst.h = 37;
            src.x = 60;
            src.y = 400;
            dst.x = 60 + vien_board;
            dst.y = 400 + vien_board;
            src.w = dst.w = 175;
            break;
        case MenuSettingChoice::MENU_SETTING_SAVE:
            src.h = dst.h = 37;
            src.x = 280;
            src.y = 400;
            dst.x = 280 + vien_board;
            dst.y = 400 + vien_board;
            src.w = dst.w = 145;
            break;
        case MenuSettingChoice::MENU_SETTING_CHESS1:
            src.x = 278;
            src.y = 201;
            dst.x = 278 + vien_board;
            dst.y = 201 + vien_board;
            src.h = dst.h = 70;
            src.w = dst.w = 30;
            break;
        case MenuSettingChoice::MENU_SETTING_CHESS2:
            src.x = 339;
            src.y = 201;
            dst.x = 339 + vien_board;
            dst.y = 201 + vien_board;
            src.h = dst.h = 70;
            src.w = dst.w = 30;
            break;
        case MenuSettingChoice::MENU_SETTING_TIME_PLUS:
            src.h = dst.h = 26;
            src.w = dst.w = 40;
            src.x = 365;
            src.y = 100;
            dst.x = 365 + vien_board;
            dst.y = 100 + vien_board;
            break;
        case MenuSettingChoice::MENU_SETTING_TIME_MINUS:
            src.h = dst.h = 26;
            src.w = dst.w = 40;
            src.x = 365;
            src.y = 134;
            dst.x = 365 + vien_board;
            dst.y = 134 + vien_board;
            break;
        case MenuSettingChoice::MENU_SETTING_MUSIC:
            src.h = dst.h = 60;
            src.w = dst.w = 60;
            src.x = 143;
            src.y = 317;
            dst.x = 143 + vien_board;
            dst.y = 317 + vien_board;
            break;
        case MenuSettingChoice::MENU_SETTING_SOUND:
            src.h = dst.h = 60;
            src.w = dst.w = 60;
            src.x = 289;
            src.y = 317;
            dst.x = 289 + vien_board;
            dst.y = 317 + vien_board;
            break;
    }

    if(!(state_now == MenuSettingChoice::MENU_SETTING_TOTAL or (state_now == MenuSettingChoice::MENU_SETTING_SAVE and SaveOn == false))) ImageChooses->render(src,dst);

    if(!Music_On)
    {
        src.h = dst.h = 60;
        src.w = dst.w = 60;
        src.x = 143;
        src.y = 317;
        dst.x = 143 + vien_board;
        dst.y = 317 + vien_board;
        ImageChooses->render(src,dst);
    }
    if(!SoundEffect_On)
    {
        src.h = dst.h = 60;
        src.w = dst.w = 60;
        src.x = 289;
        src.y = 317;
        dst.x = 289 + vien_board;
        dst.y = 317 + vien_board;
        ImageChooses->render(src,dst);
    }
    GameFont.render( 310 + vien_board - GameFont.get_width()/2, 130 + vien_board - GameFont.get_height()/2);
        if(TypeofChess)
        {
            SDL_Rect src, dst;
            src.x = 278;
            src.y = 201;
            dst.x = 278 + vien_board;
            dst.y = 201 + vien_board;
            src.h = dst.h = 70;
            src.w = dst.w = 30;
            ImageChooses->render(src,dst);
        }
        else
        {
            SDL_Rect src, dst;
            src.x = 339;
            src.y = 201;
            dst.x = 339 + vien_board;
            dst.y = 201 + vien_board;
            src.h = dst.h = 70;
            src.w = dst.w = 30;
            ImageChooses->render(src,dst);
        }
}

void SettingMenu::SetToDefault()
{
    SaveOn = false;
    TypeofChess = Type_Chess;
    GameTime = TimeofGame;
    Music_On = MusicOn;
    SoundEffect_On = SoundEffectOn;
    GameTime = TimeofGame;
    appear = 0;
    disappear = 255;
    BackOn = false;
}

//fuction pause menu
PauseMenu::PauseMenu()
{
    ImageMain = &ImageMenu[TypeBoardMenu::PAUSE_MENU_];
    ImageChooses = &ImageMenu[TypeBoardMenu::PAUSE_MENU_CHOOSES];
    vien_board = (window_height - ImageMain->get_height())/2;
    state_now = MenuPauseChoice::MENU_PAUSE_TOTAL;
    GameTime = TimeofGame;
    appear = 0;
    disappear = 255;
    BackOn = false;
}

MenuPauseChoice PauseMenu::HandleMouseEvent()
{
    if(BackOn and disappear == 0) return MenuPauseChoice::MENU_PAUSE_BACK;
    if(BackOn) return MenuPauseChoice::MENU_PAUSE_TOTAL;
    SDL_GetMouseState(&MousePos.x, &MousePos.y);
    //back (12,90) -> (160,140)
    state_now = MenuPauseChoice::MENU_PAUSE_TOTAL;

    if(MousePos.x >= vien_board + 12 and MousePos.x <= vien_board + 160 and MousePos.y >= vien_board + 90 and MousePos.y <= vien_board + 140)
    {
        state_now = MenuPauseChoice::MENU_PAUSE_BACK;
        
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            BackOn = true;
        }
    }
    //save (175,90) -> (324,140)
    if(MousePos.x >= vien_board + 175 and MousePos.x <= vien_board + 324 and MousePos.y >= vien_board + 90 and MousePos.y <= vien_board + 140)
    {
        state_now = MenuPauseChoice::MENU_PAUSE_SAVE;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            KingIsAttackedOn = KingisAttacked;
            CanEatOn = Caneat;
            CanGoOn = Cango;
            SaveOn = false;
            Type_Chess = TypeofChess;
            MusicOn = Music_On;
            SoundEffectOn = SoundEffect_On;
            return MenuPauseChoice::MENU_PAUSE_SAVE;
        }
    }
    //menu (339,90) -> (490,140)
    if(MousePos.x >= vien_board + 339 and MousePos.x <= vien_board + 490 and MousePos.y >= vien_board + 90 and MousePos.y <= vien_board + 140)
    {
        state_now = MenuPauseChoice::MENU_PAUSE_MENU_MAIN;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return MenuPauseChoice::MENU_PAUSE_MENU_MAIN;
        }
    }
    //cac nut y >= 220 and y <= 236
    if(MousePos.x >= vien_board + 66 and MousePos.x <= vien_board + 110 and MousePos.y >= vien_board + 220 and MousePos.y <= vien_board + 236)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            KingisAttacked = !KingisAttacked;
            state_now = MenuPauseChoice::MENU_PAUSE_KING_IS_ATTACKED;
            SaveOn = true;
            return MenuPauseChoice::MENU_PAUSE_KING_IS_ATTACKED;
        }
    }

    if(MousePos.x >= vien_board + 228 and MousePos.x <= vien_board + 272 and MousePos.y >= vien_board + 220 and MousePos.y <= vien_board + 236)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            Cango = !Cango;
            state_now = MenuPauseChoice::MENU_PAUSE_CAN_GO;
            SaveOn = true;
            return MenuPauseChoice::MENU_PAUSE_CAN_GO;
        }
    }

    if(MousePos.x >= vien_board + 387 and MousePos.x <= vien_board + 431 and MousePos.y >= vien_board + 220 and MousePos.y <= vien_board + 236)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            Caneat = !Caneat;
            state_now = MenuPauseChoice::MENU_PAUSE_CAN_EAT;
            SaveOn = true;
            return MenuPauseChoice::MENU_PAUSE_CAN_EAT;
        }
    }

    //chess image
    if(MousePos.x >= vien_board + 280 and MousePos.x <= vien_board + 314 and MousePos.y >= vien_board + 250 and MousePos.y <= vien_board + 296)
    {
        state_now = MenuPauseChoice::MENU_PAUSE_CHESS1;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            TypeofChess = true;
            return MenuPauseChoice::MENU_PAUSE_CHESS1;
        }
    }

    if(MousePos.x >= vien_board + 337 and MousePos.x <= vien_board + 373 and MousePos.y >= vien_board + 250 and MousePos.y <= vien_board + 296)
    {
        state_now = MenuPauseChoice::MENU_PAUSE_CHESS2;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            TypeofChess = false;
            return MenuPauseChoice::MENU_PAUSE_CHESS2;
        }
    }

    //music(145,320) -> (202,378)
    if(MousePos.x >= vien_board + 145 and MousePos.x <= vien_board + 202 and MousePos.y >= vien_board + 320 and MousePos.y <= vien_board + 378)
    {
        state_now = MenuPauseChoice::MENU_PAUSE_MUSIC;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            Music_On = !Music_On;
            return MenuPauseChoice::MENU_PAUSE_MUSIC;
        }
    }

    //sound(290,320) -> (351,378)
    if(MousePos.x >= vien_board + 290 and MousePos.x <= vien_board + 351 and MousePos.y >= vien_board + 320 and MousePos.y <= vien_board + 378)
    {
        state_now = MenuPauseChoice::MENU_PAUSE_SOUND;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            SoundEffect_On = !SoundEffect_On;
            return MenuPauseChoice::MENU_PAUSE_SOUND;
        }
    }

    //New game(100,380) -> (400,480)
    if(MousePos.x >= vien_board + 100 and MousePos.x <= vien_board + 400 and MousePos.y >= vien_board + 380 and MousePos.y <= vien_board + 480)
    {
        state_now = MenuPauseChoice::MENU_PAUSE_NEW_GAME;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            return MenuPauseChoice::MENU_PAUSE_NEW_GAME;
        }
    }
    return MenuPauseChoice::MENU_PAUSE_TOTAL;
}

void PauseMenu::SetToDefault()
{
    KingisAttacked = KingIsAttackedOn, Caneat = CanEatOn, Cango = CanGoOn;
    SaveOn = false;
    TypeofChess = Type_Chess;
    Music_On = MusicOn;
    SoundEffect_On = SoundEffectOn;
    appear = 0;
    disappear = 255;
    BackOn = false;
}

void PauseMenu::Render_to_screen()
{
    if(appear >= 255 - 10) appear = 255; else appear += 10;
    ImageMain->setAlpha(appear);
    ImageChooses->setAlpha(appear);
    if(BackOn)
    {
        ImageMain->setAlpha(disappear);
        ImageChooses->setAlpha(disappear);
        if(disappear < 15) disappear = 0; else disappear = disappear - 15; 
    }

    ImageMain->render(vien_board, vien_board);
    SDL_Rect src, dst;
    switch(state_now)
    {
        case MenuPauseChoice::MENU_PAUSE_BACK:
            src = {12,90,148,50};
            dst = {12 + vien_board,90 + vien_board,148,50};
            break;
        case MenuPauseChoice::MENU_PAUSE_MENU_MAIN:
            src = {339,90,148,50};
            dst = {339 + vien_board,90 + vien_board,148,50};
            break;
        case MenuPauseChoice::MENU_PAUSE_SAVE:
            src = {175,90,148,50};
            dst = {175 + vien_board,90 + vien_board,148,50};
            break;
        case MenuPauseChoice::MENU_PAUSE_KING_IS_ATTACKED:
            src = {66,220,44,16};
            dst = {66 + vien_board,220 + vien_board,44,16};
            break;
        case MenuPauseChoice::MENU_PAUSE_CAN_GO:
            src = {228,220,44,16};
            dst = {228 + vien_board,220 + vien_board,44,16};
            break;
        case MenuPauseChoice::MENU_PAUSE_CAN_EAT:
            src = {387,220,44,16};
            dst = {387 + vien_board,220 + vien_board,44,16};
            break;
        case MenuPauseChoice::MENU_PAUSE_CHESS1:
            src = {280,250,44,60};
            dst = {280 + vien_board,250 + vien_board,44,60};
            break;
        case MenuPauseChoice::MENU_PAUSE_CHESS2:
            src = {337,250,44,60};
            dst = {337 + vien_board,250 + vien_board,44,60};
            break;
        case MenuPauseChoice::MENU_PAUSE_MUSIC:
            src = {145,320,60,60};
            dst = {145 + vien_board,320 + vien_board,60,60};
            break;
        case MenuPauseChoice::MENU_PAUSE_SOUND:
            src = {290,320,60,60};
            dst = {290 + vien_board,320 + vien_board,60,60};
            break;
        case MenuPauseChoice::MENU_PAUSE_NEW_GAME:
            src = {100,380,300,100};
            dst = {100 + vien_board,380 + vien_board,300,100};
            break;
        default:
            break;
    }
    if(appear == 255)
    {
        if(state_now == MenuPauseChoice::MENU_PAUSE_SAVE)
        {
            if(SaveOn)
            {
                ImageChooses->render(src, dst);
            }
        }
        else ImageChooses->render(src,dst);
    }
    if(!KingisAttacked)
    {
        src = {66,220,44,16};
        dst = {66 + vien_board,220 + vien_board,44,16};
        ImageChooses->render(src, dst);
    }

    if(!Caneat)
    {
        src = {387,220,44,16};
        dst = {387 + vien_board,220 + vien_board,44,16};
        ImageChooses->render(src, dst);
    }

    if(!Cango)
    {
        src = {228,220,44,16};
        dst = {228 + vien_board,220 + vien_board,44,16};
        ImageChooses->render(src, dst);
    }

    if(TypeofChess)
    {
        src = {280,250,44,60};
        dst = {280 + vien_board,250 + vien_board,44,60};
        ImageChooses->render(src,dst);
    }
    else{
        src = {337,250,44,60};
        dst = {337 + vien_board,250 + vien_board,44,60};
        ImageChooses->render(src,dst);
    }

    if(!SoundEffect_On)
    {
        src = {290,320,60,60};
        dst = {290 + vien_board,320 + vien_board,60,60};
        ImageChooses->render(src,dst);
    }

    if(!Music_On)
    {
        src = {145,320,60,60};
        dst = {145 + vien_board,320 + vien_board,60,60};
        ImageChooses->render(src,dst);
    }

}