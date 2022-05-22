#include "PauseMenu.h"
#include "common.h"
bool CanEatOn = true;
bool CanGoOn = true;
bool KingIsAttackedOn = true;
PauseMenu::PauseMenu()
{
    ImageMenu = &PauseGame[0];
    ChoiceMenu = &PauseGame[1];
    viensetting = (window_height - ChoiceMenu->get_height())/2;
    KingisAttacked = true, Caneat = true, Cango = true;
    SaveOn = false;
    TypeChess = Type_Chess;
    Music_On = MusicOn;
    state = PauseGameChoice::TOTAL_PAUSE;
    hiendan = 0;
}

void PauseMenu::setPauseMenu()
{
    KingisAttacked = KingIsAttackedOn, Caneat = CanEatOn, Cango = CanGoOn;
    SaveOn = false;
    TypeChess = Type_Chess;
    Music_On = MusicOn;
    SoundEffect_On = SoundEffectOn;
    hiendan = 0;
}

PauseGameChoice PauseMenu::HandleEventMouse()
{
    SDL_GetMouseState(&MousePos.x, &MousePos.y);
    //back (12,90) -> (160,140)
    state = PauseGameChoice::TOTAL_PAUSE;

    if(MousePos.x >= viensetting + 12 and MousePos.x <= viensetting + 160 and MousePos.y >= viensetting + 90 and MousePos.y <= viensetting + 140)
    {
        state = PauseGameChoice::PAUSE_BACK;
        
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return PauseGameChoice::PAUSE_BACK;
        }
    }
    //save (175,90) -> (324,140)
    if(MousePos.x >= viensetting + 175 and MousePos.x <= viensetting + 324 and MousePos.y >= viensetting + 90 and MousePos.y <= viensetting + 140)
    {
        state = PauseGameChoice::PAUSE_SAVE;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            KingIsAttackedOn = KingisAttacked;
            CanEatOn = Caneat;
            CanGoOn = Cango;
            SaveOn = false;
            Type_Chess = TypeChess;
            MusicOn = Music_On;
            SoundEffectOn = SoundEffect_On;
            return PauseGameChoice::PAUSE_SAVE;
        }
    }
    //menu (339,90) -> (490,140)
    if(MousePos.x >= viensetting + 339 and MousePos.x <= viensetting + 490 and MousePos.y >= viensetting + 90 and MousePos.y <= viensetting + 140)
    {
        state = PauseGameChoice::PAUSE_MENU_MAIN;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            return PauseGameChoice::PAUSE_MENU_MAIN;
        }
    }
    //cac nut y >= 220 and y <= 236
    if(MousePos.x >= viensetting + 66 and MousePos.x <= viensetting + 110 and MousePos.y >= viensetting + 220 and MousePos.y <= viensetting + 236)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            KingisAttacked = !KingisAttacked;
            state = PauseGameChoice::PAUSE_KING_IS_ATTACKED;
            SaveOn = true;
            return PauseGameChoice::PAUSE_KING_IS_ATTACKED;
        }
    }

    if(MousePos.x >= viensetting + 228 and MousePos.x <= viensetting + 272 and MousePos.y >= viensetting + 220 and MousePos.y <= viensetting + 236)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            Cango = !Cango;
            state = PauseGameChoice::PAUSE_CAN_GO;
            SaveOn = true;
            return PauseGameChoice::PAUSE_CAN_GO;
        }
    }

    if(MousePos.x >= viensetting + 387 and MousePos.x <= viensetting + 431 and MousePos.y >= viensetting + 220 and MousePos.y <= viensetting + 236)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            Caneat = !Caneat;
            state = PauseGameChoice::PAUSE_CAN_EAT;
            SaveOn = true;
            return PauseGameChoice::PAUSE_CAN_EAT;
        }
    }

    //chess image
    if(MousePos.x >= viensetting + 280 and MousePos.x <= viensetting + 314 and MousePos.y >= viensetting + 250 and MousePos.y <= viensetting + 296)
    {
        state = PauseGameChoice::PAUSE_CHESS1;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            TypeChess = true;
            return PauseGameChoice::PAUSE_CHESS1;
        }
    }

    if(MousePos.x >= viensetting + 337 and MousePos.x <= viensetting + 373 and MousePos.y >= viensetting + 250 and MousePos.y <= viensetting + 296)
    {
        state = PauseGameChoice::PAUSE_CHESS2;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            TypeChess = false;
            return PauseGameChoice::PAUSE_CHESS2;
        }
    }

    //music(145,320) -> (202,378)
    if(MousePos.x >= viensetting + 145 and MousePos.x <= viensetting + 202 and MousePos.y >= viensetting + 320 and MousePos.y <= viensetting + 378)
    {
        state = PauseGameChoice::PAUSE_MUSIC;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            Music_On = !Music_On;
            return PauseGameChoice::PAUSE_MUSIC;
        }
    }

    //sound(290,320) -> (351,378)
    if(MousePos.x >= viensetting + 290 and MousePos.x <= viensetting + 351 and MousePos.y >= viensetting + 320 and MousePos.y <= viensetting + 378)
    {
        state = PauseGameChoice::PAUSE_SOUND;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            SoundEffect_On = !SoundEffect_On;
            return PauseGameChoice::PAUSE_SOUND;
        }
    }

    //New game(100,380) -> (400,480)
    if(MousePos.x >= viensetting + 100 and MousePos.x <= viensetting + 400 and MousePos.y >= viensetting + 380 and MousePos.y <= viensetting + 480)
    {
        state = PauseGameChoice::PAUSE_NEW_GAME;
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            SaveOn = true;
            return PauseGameChoice::PAUSE_NEW_GAME;
        }
    }

    return PauseGameChoice::TOTAL_PAUSE;
}

void PauseMenu::renderPauseMenu()
{
    ImageMenu->setAlpha(255);
    ImageMenu->render(viensetting, viensetting);
    SDL_Rect src, dst;
    switch(state)
    {
        case PauseGameChoice::PAUSE_BACK:
            src = {12,90,148,50};
            dst = {12 + viensetting,90 + viensetting,148,50};
            break;
        case PauseGameChoice::PAUSE_MENU_MAIN:
            src = {339,90,148,50};
            dst = {339 + viensetting,90 + viensetting,148,50};
            break;
        case PauseGameChoice::PAUSE_SAVE:
            src = {175,90,148,50};
            dst = {175 + viensetting,90 + viensetting,148,50};
            break;
        case PauseGameChoice::PAUSE_KING_IS_ATTACKED:
            src = {66,220,44,16};
            dst = {66 + viensetting,220 + viensetting,44,16};
            break;
        case PauseGameChoice::PAUSE_CAN_GO:
            src = {228,220,44,16};
            dst = {228 + viensetting,220 + viensetting,44,16};
            break;
        case PauseGameChoice::PAUSE_CAN_EAT:
            src = {387,220,44,16};
            dst = {387 + viensetting,220 + viensetting,44,16};
            break;
        case PauseGameChoice::PAUSE_CHESS1:
            src = {280,250,44,60};
            dst = {280 + viensetting,250 + viensetting,44,60};
            break;
        case PauseGameChoice::PAUSE_CHESS2:
            src = {337,250,44,60};
            dst = {337 + viensetting,250 + viensetting,44,60};
            break;
        case PauseGameChoice::PAUSE_MUSIC:
            src = {145,320,60,60};
            dst = {145 + viensetting,320 + viensetting,60,60};
            break;
        case PauseGameChoice::PAUSE_SOUND:
            src = {290,320,60,60};
            dst = {290 + viensetting,320 + viensetting,60,60};
            break;
        case PauseGameChoice::PAUSE_NEW_GAME:
            src = {100,380,300,100};
            dst = {100 + viensetting,380 + viensetting,300,100};
            break;
        default:
            break;
    }
    if(state == PauseGameChoice::PAUSE_SAVE)
    {
        if(SaveOn)
        {
            ChoiceMenu->render(src, dst);
        }
    }
    else ChoiceMenu->render(src,dst);

    if(!KingisAttacked)
    {
        src = {66,220,44,16};
        dst = {66 + viensetting,220 + viensetting,44,16};
        ChoiceMenu->render(src, dst);
    }

    if(!Caneat)
    {
        src = {387,220,44,16};
        dst = {387 + viensetting,220 + viensetting,44,16};
        ChoiceMenu->render(src, dst);
    }

    if(!Cango)
    {
        src = {228,220,44,16};
        dst = {228 + viensetting,220 + viensetting,44,16};
        ChoiceMenu->render(src, dst);
    }

    if(TypeChess)
    {
        src = {280,250,44,60};
        dst = {280 + viensetting,250 + viensetting,44,60};
        ChoiceMenu->render(src,dst);
    }
    else{
        src = {337,250,44,60};
        dst = {337 + viensetting,250 + viensetting,44,60};
        ChoiceMenu->render(src,dst);
    }

    if(!SoundEffect_On)
    {
        src = {290,320,60,60};
        dst = {290 + viensetting,320 + viensetting,60,60};
        ChoiceMenu->render(src,dst);
    }

    if(!Music_On)
    {
        src = {145,320,60,60};
        dst = {145 + viensetting,320 + viensetting,60,60};
        ChoiceMenu->render(src,dst);
    }
}

void PauseMenu::renderImagePauseMenu()
{
    hiendan = hiendan + 15;
    ImageMenu->setAlpha(hiendan);
    ImageMenu->render(viensetting, viensetting);
}