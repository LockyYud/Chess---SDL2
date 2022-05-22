#include "common.h"
#include "GameState.h"
bool MusicOn = true, SoundEffectOn = true;
GameState::GameState()
{
    Game_Loop = new GameLoop;
	Game_Choice = new GameMenu;
	Pause_menu = new PauseMenu;
    trang_thai = state::MENU_GAME; 
}

GameState::~GameState()
{
    
}

state GameState::getState()
{
	return trang_thai;
}

void GameState::setState(state a)
{
	trang_thai = a;
}

void GameState::HandleMouseEvent()
{
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_KEYDOWN)
	{
		switch (trang_thai)
		{
		case state::IN_GAME:
			Game_Loop->EventMouse();
			if(Game_Loop->End_Game.second)
				switch(Game_Loop->End_Game.first)
				{
					case Game_Result::BACK_TO_MENU:
						trang_thai = state::MENU_GAME;
						break;
					case Game_Result::PLAY_AGAIN:
						delete Game_Loop;
						Game_Loop = new GameLoop;
						Game_Loop->SetTypeChess();
						Game_Loop->SetTime();
						Game_Loop->StartTime = SDL_GetTicks();
						break;
					default:
						break;
				}
			else
			{
				if(Game_Loop->OptiongChoice == Option::OPTION)
				{
					trang_thai = state::PAUSE_MENU;
					Pause_menu->setPauseMenu();
				}
			}
			break;
		case state::MENU_GAME:
			switch(Game_Choice->EventMouseMenu())
			{
				case MenuChoice::PLAY:
					trang_thai = state::IN_GAME;
					delete Game_Loop;
					Game_Loop = new GameLoop;
					Game_Loop->SetTypeChess();
					Game_Loop->SetTime();
					Game_Loop->StartTime = SDL_GetTicks();
					break;
				case MenuChoice::SETTING:
					trang_thai = state::SETTING_GAME;
					Game_Choice->bat_dau = 400;
					break;
				case MenuChoice::QUIT:
					trang_thai = state::QUIT_GAME;
				default:
					break;
			}
			break;
		case state::PAUSE_MENU:
			switch(Pause_menu->HandleEventMouse())
			{
				case PauseGameChoice::PAUSE_BACK:
					trang_thai = state::IN_GAME;
					Game_Loop->SetTypeChess();
					break;
				case PauseGameChoice::PAUSE_MENU_MAIN:
					trang_thai = state::MENU_GAME;
					break;
				case PauseGameChoice::PAUSE_NEW_GAME:
					trang_thai = state::IN_GAME;
					delete Game_Loop;
					Game_Loop = new GameLoop;
					Game_Loop->SetTypeChess();
					Game_Loop->SetTime();
					Game_Loop->StartTime = SDL_GetTicks();
					break;
				default:
					break;
			}
			break;
		case state::SETTING_GAME:
			switch(Game_Choice->EventMouseSetting())
			{
				case SettingChoice::BACK:
					trang_thai = state::MENU_GAME;
					break;
				case SettingChoice::SAVE:
					if(MusicOn)
					{
						if( Mix_PlayingMusic() == 0 )
						{
							//Play the music
							Mix_PlayMusic( Music, -1 );
						}
					}
					else{
						if( Mix_PlayingMusic() != 0 )
						{
							//Stop the music
							Mix_HaltMusic();
						}
					}
					break;
				case SettingChoice::MUSIC:
					break;
				case SettingChoice::SOUND:
					SoundEffectOn = !SoundEffectOn;
					break;
				default:
					break;
			}
			break;
		default:
			break;
		}
	}
}

void GameState::InGame()
{
 	// Game_Loop->checkObject();
	SDL_SetRenderDrawColor(gameRenderer, 108, 108, 108, 0);
	SDL_RenderClear(gameRenderer);
	Game_Loop->CheckGameSpecial();
	Game_Loop->LoadGameBoardtoScreen();
	Game_Loop->LoadOptionToScreen();
	Game_Loop->LoadPiecesToScreen();
	Game_Loop->PlayerTime();
	if(Game_Loop->getGameResult() != Game_Result::TRONG) Game_Loop->renderResult();
	SDL_RenderPresent(gameRenderer);
	if(!Game_Loop->GameRunning()) trang_thai = state::QUIT_GAME;
}

void GameState::InMenu()
{
	SDL_SetRenderDrawColor(gameRenderer, 108, 108, 108, 0);
	SDL_RenderClear(gameRenderer);
	Game_Choice->renderMenuGame();
	Game_Choice->renderMenuGameChooses();
	SDL_RenderPresent(gameRenderer);
}

void GameState::InSetting()
{
	SDL_SetRenderDrawColor(gameRenderer, 108, 108, 108, 0);
	SDL_RenderClear(gameRenderer);
	Game_Choice->renderSetting();
	if(Game_Choice->bat_dau == 70) Game_Choice->renderSettingChooses();
	SDL_RenderPresent(gameRenderer);
}

void GameState::InPauseGame()
{
	SDL_SetRenderDrawColor(gameRenderer, 108, 108, 108, 0);
	SDL_RenderClear(gameRenderer);
	Game_Loop->LoadGameBoardtoScreen();
	Game_Loop->LoadOptionToScreen();
	Game_Loop->LoadPiecesToScreen();
	Game_Loop->PlayerTime();
	if(Pause_menu->hiendan + 15 > 255) Pause_menu->renderPauseMenu();
	else Pause_menu->renderImagePauseMenu();
	SDL_RenderPresent(gameRenderer);
}