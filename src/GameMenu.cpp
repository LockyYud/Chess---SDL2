#include "GameMenu.h"
#include "common.h"
GameMenu::GameMenu()
{
    vienSetting = (window_height - Choices[int(G_Choice::_SETTING)].get_height())/2;
    GameTime = 30;
    TypeofChess = true;
    SaveOn = false;
    MusicInGame = true;
    SoundEffectInGame = true;
    Mix_PlayMusic( Music, -1 );
}
GameMenu::~GameMenu()
{

}


MenuChoice GameMenu::EventMouseMenu()
{
    SDL_GetMouseState(&MousePos.x, &MousePos.y);
    float ti_le = float(window_height) / Choices[int(G_Choice::MENU_CHOICE)].get_height();
    // pos play: 75 - 174 : 95x350
    PlayerMenuChoice = MenuChoice::NOTHING_MENU;
    if(MousePos.x >= float(75*ti_le) and MousePos.x <= float((75 + 350)*ti_le) and MousePos.y >= float(174*ti_le) and MousePos.y <= float((174 + 95)*ti_le))
    {
        PlayerMenuChoice = MenuChoice::PLAY;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return MenuChoice::PLAY;
        }
    }
    // pos setting: 75 - 267 : 95x350
    if(MousePos.x >= float(75*ti_le) and MousePos.x <= float((75 + 350)*ti_le) and MousePos.y >= float(267*ti_le) and MousePos.y <= float((267 + 95)*ti_le))
    {
        PlayerMenuChoice = MenuChoice::SETTING;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return MenuChoice::SETTING;
        }
    }
    // pos quit: 75 - 363 : 95x350
    if(MousePos.x >= float(75*ti_le) and MousePos.x <= float((75 + 350)*ti_le) and MousePos.y >= float(363*ti_le) and MousePos.y <= float((363 + 95)*ti_le))
    {
        PlayerMenuChoice = MenuChoice::QUIT;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return MenuChoice::QUIT;
        }
    }
    return MenuChoice::NOTHING_MENU;
}

SettingChoice GameMenu::EventMouseSetting()
{
    SDL_GetMouseState(&MousePos.x, &MousePos.y);
    //back
    PlayerSettingChoice = SettingChoice::NOTHING_SETTING;
    if(MousePos.x >= 60 + vienSetting and MousePos.x <= 235 + vienSetting and MousePos.y >= 400 + vienSetting and MousePos.y <= 500 - 63 + vienSetting)
    {
        PlayerSettingChoice = SettingChoice::BACK;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(SaveOn)
            {
                SaveOn = false;
                TypeofChess = Type_Chess;
                GameTime = TimeofGame;
                MusicInGame = MusicOn;
                SoundEffectInGame = SoundEffectOn;
            }
            return SettingChoice::BACK;
        }
    }
    //save
    if(MousePos.x >= 280 + vienSetting and MousePos.x <= 425 + vienSetting and MousePos.y >= 400 + vienSetting and MousePos.y <= 500 - 63 + vienSetting)
    {
        PlayerSettingChoice = SettingChoice::SAVE;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(SaveOn)
            {
                SaveOn = false;
                Type_Chess = TypeofChess;
                TimeofGame = GameTime;
                MusicOn = MusicInGame;
                SoundEffectOn = SoundEffectInGame;
            }
            return SettingChoice::SAVE;
        }
    }
    //image chess
    // src.h = dst.h = 70;
    // src.w = dst.w = 30;
    if(MousePos.x >= 278 + vienSetting and MousePos.x <= 278 + 30 + vienSetting and MousePos.y >= 201 + vienSetting and MousePos.y <= 250 + vienSetting)
    {
        PlayerSettingChoice = SettingChoice::CHESS1;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            TypeofChess = true;
            SaveOn = true;
            return SettingChoice::CHESS1;
        }
    }
    if(MousePos.x >= 339 + vienSetting and MousePos.x <= 339 + 30 + vienSetting and MousePos.y >= 201 + vienSetting and MousePos.y <= 250 + vienSetting)
    {
        PlayerSettingChoice = SettingChoice::CHESS2;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            TypeofChess =  false;
            SaveOn = true;
            return SettingChoice::CHESS2;
        }
    }
    //time
    // src.h = dst.h = 26;
    // src.w = dst.w = 40;
    if(MousePos.x >= 365 + vienSetting and MousePos.x <= 365 + 32 + vienSetting and MousePos.y >= 100 + vienSetting and MousePos.y <= 100 + 26 + vienSetting)
    {
        PlayerSettingChoice = SettingChoice::TIME_PLUS;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            GameTime += 5;
            SaveOn = true;
            return SettingChoice::TIME_PLUS;
        }
    }
    if(MousePos.x >= 365 + vienSetting and MousePos.x <= 365 + 32 + vienSetting and MousePos.y >= 134 + vienSetting and MousePos.y <= 134 + 26 + vienSetting)
    {
        PlayerSettingChoice = SettingChoice::TIME_MINUS;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            GameTime -= 5;
            SaveOn = true;
            return SettingChoice::TIME_MINUS;
        }
    }

    if(MousePos.x >= 143 + vienSetting and MousePos.x <= 203 + vienSetting and MousePos.y >= 317 + vienSetting and MousePos.y <= 377 + vienSetting)
    {
        PlayerSettingChoice = SettingChoice::MUSIC;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            MusicInGame = !MusicInGame;
            return SettingChoice::MUSIC;
        }
    }

    if(MousePos.x >= 289 + vienSetting and MousePos.x <= 349 + vienSetting and MousePos.y >= 317 + vienSetting and MousePos.y <= 377 + vienSetting)
    {
        PlayerSettingChoice = SettingChoice::SOUND;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            SoundEffectInGame = !SoundEffectInGame;
            return SettingChoice::SOUND;
        }
    }
    return SettingChoice::NOTHING_SETTING;
}

void GameMenu::renderMenuGame()
{
    SDL_Rect dst;
    dst.x = dst.y = 0;
    dst.w = dst.h = window_height;
    Choices[int(G_Choice::MENU)].setAlpha(255);
    Choices[int(G_Choice::MENU)].render(dst);
}

void GameMenu::renderMenuGameChooses()
{
    SDL_Rect src, dst;
    src.x = 75;
    src.h = 95, src.w = 350;
    dst.x = (75*window_width)/500, dst.h = (95*window_height)/500, dst.w = (350*window_height)/500;
    int y_play = (174*window_height)/500, y_quit = (363*window_height)/500, y_setting = (267*window_height)/500;
    switch (PlayerMenuChoice)
    {
        case MenuChoice::PLAY:
            src.y = 174;
            dst.y = y_play;
            Choices[int(G_Choice::MENU_CHOICE)].render(src,dst);
            break;
        case MenuChoice::SETTING:
            src.y = 267;
            dst.y = y_setting;
            Choices[int(G_Choice::MENU_CHOICE)].render(src,dst);
            break;
        case MenuChoice::QUIT:
            src.y = 363;
            dst.y = y_quit;
            Choices[int(G_Choice::MENU_CHOICE)].render(src,dst);
            break;
        default:
            break;
    }
}

void GameMenu::renderSetting()
{
    Choices[int(G_Choice::MENU)].setAlpha(100);
    SDL_Rect dst;
    dst.x = dst.y = 0;
    dst.w = dst.h = window_height;
    Choices[int(G_Choice::MENU)].render(dst);
    bat_dau = bat_dau - 20;
    do_mo = do_mo + 10*255/(Choices[int(G_Choice::_SETTING)].get_width()/2);
    if(do_mo > 255) do_mo = 255;
    if(bat_dau < (window_width - Choices[int(G_Choice::_SETTING)].get_width())/2)  bat_dau = (window_width - Choices[int(G_Choice::_SETTING)].get_width())/2;
    int y = Choices[int(G_Choice::_SETTING)].get_width();
    Choices[int(G_Choice::_SETTING)].setAlpha(do_mo);
    Choices[int(G_Choice::_SETTING)].render( (window_width - y)/2,bat_dau);
    if(bat_dau == (window_width - Choices[int(G_Choice::_SETTING)].get_width())/2) Choices[int(G_Choice::_SETTING_CHOICE)].render( (window_width - y)/2,bat_dau);
    std::stringstream Time;
    Time << GameTime;
    SDL_Color color = {255,255,255,255};
    GameFont.renderText(Time.str().c_str(),color);
    if(bat_dau == (window_width - Choices[int(G_Choice::_SETTING)].get_width())/2)
    {
        GameFont.render( 310 + vienSetting - GameFont.get_width()/2, 130 + vienSetting - GameFont.get_height()/2);
        if(TypeofChess)
        {
            SDL_Rect src, dst;
            src.x = 278;
            src.y = 201;
            dst.x = 278 + vienSetting;
            dst.y = 201 + vienSetting;
            src.h = dst.h = 70;
            src.w = dst.w = 30;
            Choices[int(G_Choice::_SETTING_CHOOSES)].render(src,dst);
        }
        else
        {
            SDL_Rect src, dst;
            src.x = 339;
            src.y = 201;
            dst.x = 339 + vienSetting;
            dst.y = 201 + vienSetting;
            src.h = dst.h = 70;
            src.w = dst.w = 30;
            Choices[int(G_Choice::_SETTING_CHOOSES)].render(src,dst);
        }
    }
}

void GameMenu::renderSettingChooses()
{
    //60 - 400 -> 235 - 500 - 63
    //336 - 400 -> 508 - 500 - 63
    SDL_Rect src, dst;
    switch(PlayerSettingChoice)
    {
        case SettingChoice::BACK:
            src.h = dst.h = 37;
            src.x = 60;
            src.y = 400;
            dst.x = 60 + vienSetting;
            dst.y = 400 + vienSetting;
            src.w = dst.w = 175;
            break;
        case SettingChoice::SAVE:
            src.h = dst.h = 37;
            src.x = 280;
            src.y = 400;
            dst.x = 280 + vienSetting;
            dst.y = 400 + vienSetting;
            src.w = dst.w = 145;
            break;
        case SettingChoice::CHESS1:
            src.x = 278;
            src.y = 201;
            dst.x = 278 + vienSetting;
            dst.y = 201 + vienSetting;
            src.h = dst.h = 70;
            src.w = dst.w = 30;
            break;
        case SettingChoice::CHESS2:
            src.x = 339;
            src.y = 201;
            dst.x = 339 + vienSetting;
            dst.y = 201 + vienSetting;
            src.h = dst.h = 70;
            src.w = dst.w = 30;
            break;
        case SettingChoice::TIME_PLUS:
            src.h = dst.h = 26;
            src.w = dst.w = 40;
            src.x = 365;
            src.y = 100;
            dst.x = 365 + vienSetting;
            dst.y = 100 + vienSetting;
            break;
        case SettingChoice::TIME_MINUS:
            src.h = dst.h = 26;
            src.w = dst.w = 40;
            src.x = 365;
            src.y = 134;
            dst.x = 365 + vienSetting;
            dst.y = 134 + vienSetting;
            break;
        case SettingChoice::MUSIC:
            src.h = dst.h = 60;
            src.w = dst.w = 60;
            src.x = 143;
            src.y = 317;
            dst.x = 143 + vienSetting;
            dst.y = 317 + vienSetting;
            break;
        case SettingChoice::SOUND:
            src.h = dst.h = 60;
            src.w = dst.w = 60;
            src.x = 289;
            src.y = 317;
            dst.x = 289 + vienSetting;
            dst.y = 317 + vienSetting;
            break;
    }

    if(!(PlayerSettingChoice == SettingChoice::NOTHING_SETTING or (PlayerSettingChoice == SettingChoice::SAVE and SaveOn == false))) Choices[int(G_Choice::_SETTING_CHOOSES)].render(src,dst);

    if(!MusicInGame)
    {
        src.h = dst.h = 60;
        src.w = dst.w = 60;
        src.x = 143;
        src.y = 317;
        dst.x = 143 + vienSetting;
        dst.y = 317 + vienSetting;
        Choices[int(G_Choice::_SETTING_CHOOSES)].render(src,dst);
    }
    if(!SoundEffectInGame)
    {
        src.h = dst.h = 60;
        src.w = dst.w = 60;
        src.x = 289;
        src.y = 317;
        dst.x = 289 + vienSetting;
        dst.y = 317 + vienSetting;
        Choices[int(G_Choice::_SETTING_CHOOSES)].render(src,dst);
    }
}