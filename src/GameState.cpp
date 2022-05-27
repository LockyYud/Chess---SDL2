#include "common.h"
#include "GameState.h"
bool MusicOn = true, SoundEffectOn = true;
GameState::GameState()
{
    Game_Loop = new GameLoop;
	Setting = new SettingMenu;
	Pause = new PauseMenu;
	Main = new MainMenu;
    trang_thai = state::MENU_GAME; 
    Mix_PlayMusic( Music, -1 );
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
					Pause->SetToDefault();
				}
			}
			break;
		case state::MENU_GAME:
			switch(Main->HandleMouseEvent())
			{
				case MenuMainChoice::MENU_MAIN_PLAY:
					trang_thai = state::IN_GAME;
					delete Game_Loop;
					Game_Loop = new GameLoop;
					Game_Loop->SetTypeChess();
					Game_Loop->SetTime();
					Game_Loop->StartTime = SDL_GetTicks();
					break;
				case MenuMainChoice::MENU_MAIN_SETTING:
					trang_thai = state::SETTING_GAME;
					Setting->SetToDefault();
					break;
				case MenuMainChoice::MENU_MAIN_QUIT:
					trang_thai = state::QUIT_GAME;
				default:
					break;
			}
			break;
		case state::PAUSE_MENU:
			switch(Pause->HandleMouseEvent())
			{
				case MenuPauseChoice::MENU_PAUSE_BACK:
					trang_thai = state::IN_GAME;
					Game_Loop->SetTypeChess();
					break;
				case MenuPauseChoice::MENU_PAUSE_MENU_MAIN:
					trang_thai = state::MENU_GAME;
					break;
				case MenuPauseChoice::MENU_PAUSE_NEW_GAME:
					trang_thai = state::IN_GAME;
					delete Game_Loop;
					Game_Loop = new GameLoop;
					Game_Loop->SetTypeChess();
					Game_Loop->SetTime();
					Game_Loop->StartTime = SDL_GetTicks();
					break;
				case MenuPauseChoice::MENU_PAUSE_SAVE:
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
				default:
					break;
			}
			break;
		case state::SETTING_GAME:
			switch(Setting->HandleMouseEvent())
			{
				case MenuSettingChoice::MENU_SETTING_BACK:
					trang_thai = state::MENU_GAME;
					break;
				case MenuSettingChoice::MENU_SETTING_SAVE:
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
				case MenuSettingChoice::MENU_SETTING_MUSIC:
					break;
				case MenuSettingChoice::MENU_SETTING_SOUND:
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
	Main->Render_to_screen();
	SDL_RenderPresent(gameRenderer);
}

void GameState::InSetting()
{
	SDL_SetRenderDrawColor(gameRenderer, 108, 108, 108, 0);
	SDL_RenderClear(gameRenderer);
	Setting->Render_Board();
	if(Setting->appear == 255) Setting->Render_to_screen();
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
	Pause->Render_to_screen();
	SDL_RenderPresent(gameRenderer);
}

void GameState::RenderImage()
{
	switch(this->getState())
		{
			case state::IN_GAME:
				this->InGame();
				break;
			case state::MENU_GAME:
				this->InMenu();
				break;
			case state::SETTING_GAME:
				this->InSetting();
				break;
			case state::PAUSE_MENU:
				this->InPauseGame();
			default:
				break;
		}
}