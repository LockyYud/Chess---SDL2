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
		game->RenderImage();
	}
	Image->close();
	return 0;
}