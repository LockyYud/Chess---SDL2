#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>
#include <sstream>

#include <hinhanh.h>
#include <chessman.h>
#include <xulyhinhanh.h>
#include <HandleEvent.h>
#include <GameState.h>
#include "GameLoop.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "ChessObject.h"
#include "GameMenu.h"
extern SDL_Window* gameWindow;
extern SDL_Renderer* gameRenderer;
extern TTF_Font* gFont;
extern Mix_Chunk* PeiceIn;
extern Mix_Chunk* PeiceOut;
extern Mix_Music* Music;

extern MyTexture chessboard;
extern MyTexture MenuGame;
extern MyTexture SettingGame;
extern MyTexture white_chess[7];
extern MyTexture black_chess[7];
extern MyTexture white_chess3d[7];
extern MyTexture black_chess3d[7];
extern SDL_Event e;
extern MyTexture Object[int(chess_object::TOTAL_OBJECT)];
extern MyTexture Choices[int(G_Choice::TOTAL_CHOICE)];
extern MyTexture ingame[3];
extern MyTexture option[int(Option::TOTAL_OPTION)];
extern MyTexture BackGround;
extern MyTexture GameFont;
extern MyTexture EndGame[2];
extern MyTexture PauseGame[2];
extern bool dung;
extern bool sai;
extern Map Maps[MapStep::total_step];
extern bool Type_Chess;
extern int TimeofGame;
extern bool can_castleW_L;
extern bool can_castleW_R;
extern bool can_castleB_L;
extern bool can_castleB_R;
extern std::pair<bool,bool> Castle;
extern bool MusicOn;
extern bool SoundEffectOn;
extern bool CanEatOn;
extern bool CanGoOn;
extern bool KingIsAttackedOn;