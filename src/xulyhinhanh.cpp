#include <xulyhinhanh.h>
#include <assert.h>
#include <common.h>

SDL_Window* gameWindow;
SDL_Renderer* gameRenderer;
TTF_Font* gFont;
MyTexture::MyTexture()
{
    MTex = NULL;
    wMTex = 0;
    hMTex = 0;
}
MyTexture::~MyTexture()
{
    free();
}
int MyTexture::get_height()
{
    return hMTex;
}
int MyTexture::get_width()
{
    return wMTex;
}

void MyTexture::free()
{
    if(MTex != NULL)
    {
        SDL_DestroyTexture(MTex);
        wMTex = 0;
        hMTex = 0;
    }
}

void MyTexture::loadfromfile(std::string path, Uint8 red, Uint8 green, Uint8 blue)
{
    free();
    SDL_Surface* sur;
    sur = IMG_Load( path.c_str() );
    if(sur == NULL)
    {
        std::cout << "Tai hinh anh sur that bai! SDL_Error: " << SDL_GetError() << std::endl;
    }
    SDL_SetColorKey(sur,SDL_TRUE,SDL_MapRGB(sur->format,red,green,blue));
    MTex = SDL_CreateTextureFromSurface(gameRenderer,sur);
    if(MTex == NULL)
    {
        std::cout << "Tai hinh anh tex that bai! SDL_Error: " << SDL_GetError() << std::endl;
    }
    hMTex = sur->h;
    wMTex = sur->w;
    SDL_FreeSurface(sur);
} 

void MyTexture::loadfromfile(std::string path)
{
    free();
    SDL_Surface* sur;
    sur = IMG_Load( path.c_str() );
    if(sur == NULL)
    {
        std::cout << "Tai hinh anh sur that bai! SDL_Error: " << SDL_GetError() << std::endl;
    }
    MTex = SDL_CreateTextureFromSurface(gameRenderer,sur);
    if(MTex == NULL)
    {
        std::cout << "Tai hinh anh tex that bai! SDL_Error: " << SDL_GetError() << std::endl;
    }
    hMTex = sur->h;
    wMTex = sur->w;
    SDL_FreeSurface(sur);
} 

void MyTexture::renderText( std::string textureText, SDL_Color textColor )
{
    //Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        MTex = SDL_CreateTextureFromSurface( gameRenderer, textSurface );
		if( MTex == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			wMTex = textSurface->w;
			hMTex = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
}

void MyTexture::render()
{
    SDL_Rect dst;
    dst.x = dst.y = 0, dst.w = dst.h = window_height;
    SDL_RenderCopy(gameRenderer, MTex, NULL, &dst);
}

void MyTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, wMTex, hMTex };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gameRenderer, MTex, clip, &renderQuad, angle, center, flip );
}

void MyTexture::render(const SDL_Rect &src,const SDL_Rect &dst)
{

    SDL_RenderCopy(gameRenderer ,MTex ,&src ,&dst);

}

void MyTexture::render(const SDL_Rect &dst)
{
    SDL_RenderCopy(gameRenderer, MTex, NULL, &dst);
}

void MyTexture::render(const SDL_Rect &src,const SDL_Rect &dst, double &degree, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_RenderClear(gameRenderer);
    SDL_RenderCopyEx(gameRenderer, MTex, &src, &dst, degree, center, flip);
    SDL_RenderPresent(gameRenderer);
}

void MyTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod(MTex, red, green, blue );
}

void MyTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( MTex, blending );
}
		
void MyTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
    SDL_SetTextureAlphaMod( MTex, alpha );
	// assert((SDL_SetTextureAlphaMod( MTex, alpha )==0));
}

void MyTexture::copyTex(const MyTexture &tex)
{
    MTex = tex.MTex;
    hMTex = tex.hMTex;
    wMTex = tex.wMTex;
}
