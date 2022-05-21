#include <hinhanh.h>
#include <common.h>
#include <SDL_ttf.h>
MyTexture chessboard;
MyTexture MenuGame;
MyTexture SettingGame;
MyTexture white_chess[7];
MyTexture black_chess[7];
MyTexture white_chess3d[7];
MyTexture black_chess3d[7];
MyTexture Object[int(chess_object::TOTAL_OBJECT)];
MyTexture Choices[int(G_Choice::TOTAL_CHOICE)];
MyTexture ingame[3];
MyTexture option[int(Option::TOTAL_OPTION)];
MyTexture BackGround;
MyTexture GameFont;
MyTexture EndGame[2];
MyTexture PauseGame[2];
Mix_Chunk* PeiceIn = NULL;
Mix_Chunk* PeiceOut = NULL;
Mix_Music* Music;
void image::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "khoi tao sdl loi! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else{
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            std::cout << "loi sdl" << std::endl;
        }
        gameWindow = SDL_CreateWindow("Chess",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width,window_height,SDL_WINDOW_SHOWN);
        gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            std::cout << "Khoi tao IMG that bai! SDL_Error: " << SDL_GetError() << std::endl; 
        }
        if( TTF_Init() == -1 )
        {
            std::cout << "Khoi tao TTF that bai! SDL_Error: " << SDL_GetError() << std::endl; 
        }
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
    }   
}

void image::loadMedia()
{
    chessboard.loadfromfile("D:/MyGame/Chess/images/chessboard1.png");

    black_chess[int(name_chess::Rook)].loadfromfile("D:/MyGame/Chess/images/RookW.png");
    black_chess[int(name_chess::Pawn)].loadfromfile("D:/MyGame/Chess/images/PawnW.png");
    black_chess[int(name_chess::Queen)].loadfromfile("D:/MyGame/Chess/images/QueenW.png");
    black_chess[int(name_chess::King)].loadfromfile("D:/MyGame/Chess/images/KingW.png");
    black_chess[int(name_chess::Knight)].loadfromfile("D:/MyGame/Chess/images/KnightW.png");
    black_chess[int(name_chess::Bishop)].loadfromfile("D:/MyGame/Chess/images/BishopW.png");

    white_chess[int(name_chess::Rook)].loadfromfile("D:/MyGame/Chess/images/RookB.png");
    white_chess[int(name_chess::Pawn)].loadfromfile("D:/MyGame/Chess/images/PawnB.png");
    white_chess[int(name_chess::Queen)].loadfromfile("D:/MyGame/Chess/images/QueenB.png");
    white_chess[int(name_chess::King)].loadfromfile("D:/MyGame/Chess/images/KingB.png");
    white_chess[int(name_chess::Knight)].loadfromfile("D:/MyGame/Chess/images/KnightB.png");
    white_chess[int(name_chess::Bishop)].loadfromfile("D:/MyGame/Chess/images/BishopB.png");

    black_chess3d[int(name_chess::Rook)].loadfromfile("D:/MyGame/Chess/images/RookW1.png");
    black_chess3d[int(name_chess::Pawn)].loadfromfile("D:/MyGame/Chess/images/PawnW1.png");
    black_chess3d[int(name_chess::Queen)].loadfromfile("D:/MyGame/Chess/images/QueenW1.png");
    black_chess3d[int(name_chess::King)].loadfromfile("D:/MyGame/Chess/images/KingW1.png");
    black_chess3d[int(name_chess::Knight)].loadfromfile("D:/MyGame/Chess/images/KnightW1.png");
    black_chess3d[int(name_chess::Bishop)].loadfromfile("D:/MyGame/Chess/images/BishopW1.png");

    white_chess3d[int(name_chess::Rook)].loadfromfile("D:/MyGame/Chess/images/RookB1.png");
    white_chess3d[int(name_chess::Pawn)].loadfromfile("D:/MyGame/Chess/images/PawnB1.png");
    white_chess3d[int(name_chess::Queen)].loadfromfile("D:/MyGame/Chess/images/QueenB1.png");
    white_chess3d[int(name_chess::King)].loadfromfile("D:/MyGame/Chess/images/KingB1.png");
    white_chess3d[int(name_chess::Knight)].loadfromfile("D:/MyGame/Chess/images/KnightB1.png");
    white_chess3d[int(name_chess::Bishop)].loadfromfile("D:/MyGame/Chess/images/BishopB1.png");


    Object[int(chess_object::CHESS_BOARD)].loadfromfile("D:/MyGame/Chess/images/chessboard.png");
    Object[int(chess_object::PEICE_SELECTED)].loadfromfile("D:/MyGame/Chess/images/Selected.png");
    Object[int(chess_object::PEICE_CAN_GO)].loadfromfile("D:/MyGame/Chess/images/Can_go.png");
    Object[int(chess_object::PEICE_CAN_EAT)].loadfromfile("D:/MyGame/Chess/images/Can_eat.png");
    Object[int(chess_object::KING_IS_ATTACKED)].loadfromfile("D:/MyGame/Chess/images/Vua.png");

    Choices[int(G_Choice::MENU)].loadfromfile("D:/MyGame/Chess/images/Menu.png");
    Choices[int(G_Choice::MENU_CHOICE)].loadfromfile("D:/MyGame/Chess/images/Menu_choice.png");
    Choices[int(G_Choice::_SETTING)].loadfromfile("D:/MyGame/Chess/images/Setting.png");
    Choices[int(G_Choice::_SETTING_CHOICE)].loadfromfile("D:/MyGame/Chess/images/Setting_choice.png");
    Choices[int(G_Choice::_SETTING_CHOOSES)].loadfromfile("D:/MyGame/Chess/images/Setting_chooses.png");

    ingame[int(Game_Result::BLACK_WIN)].loadfromfile("D:/MyGame/Chess/images/Bwin.png");
    ingame[int(Game_Result::WHITE_WIN)].loadfromfile("D:/MyGame/Chess/images/Wwin.png");
    ingame[int(Game_Result::DRAW)].loadfromfile("D:/MyGame/Chess/images/Draw.png");

    option[int(Option::OPTION)].loadfromfile("D:/MyGame/Chess/images/Option.png");
    option[int(Option::RETURN)].loadfromfile("D:/MyGame/Chess/images/Return.png");
    
    BackGround.loadfromfile("D:/MyGame/Chess/images/Background.png");

    gFont = TTF_OpenFont("D:/MyGame/Chess/images/Font.ttf",32);
    EndGame[0].loadfromfile("D:/MyGame/Chess/images/EndGameChoice.png");
    EndGame[1].loadfromfile("D:/MyGame/Chess/images/chess.png");

    PeiceIn = Mix_LoadWAV("D:/MyGame/Chess/images/PeiceIn.wav");
    PeiceOut = Mix_LoadWAV("D:/MyGame/Chess/images/PeiceOut.wav"); 
    Music = Mix_LoadMUS("D:/MyGame/Chess/images/NhacNen.wav");

    PauseGame[0].loadfromfile("D:/MyGame/Chess/images/MenuInGame.png");
    PauseGame[1].loadfromfile("D:/MyGame/Chess/images/MenuInGameChooses.png");
}

void image::close()
{
    chessboard.free();
    for(int i = 1; i < 7; i++)
    {
        black_chess[i].free();
        white_chess[i].free();
    }

    SDL_DestroyWindow(gameWindow);
    SDL_DestroyRenderer(gameRenderer);

    gameRenderer = NULL;
    gameWindow = NULL;

    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}