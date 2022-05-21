#include <common.h>
SDL_Event e;
int main(int argc, char* args[])
{
	image* Image = new image;
	Image->init();
	Image->loadMedia();
	GameState* game = new GameState;
	while(game->getState() != state::QUIT_GAME)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				game->setState(state::QUIT_GAME);
			}
			game->HandleMouseEvent();
		}
		switch(game->getState())
		{
			case state::IN_GAME:
				game->InGame();
				break;
			case state::MENU_GAME:
				game->InMenu();
				break;
			case state::SETTING_GAME:
				game->InSetting();
				break;
			case state::PAUSE_MENU:
				game->InPauseGame();
			default:
				break;
		}
	}
	Image->close();
	return 0;
}