#pragma once
#include <SDL.h>
#include <xulyhinhanh.h>
#include <chessman.h>
#include <vector>
enum chess_object
{
    PEICE_SELECTED,
    CHESS_BOARD,
    PEICE_CAN_GO,
    PEICE_CAN_EAT,
    KING_IS_ATTACKED,
    TOTAL_OBJECT
};

enum MapStep
{
    five_step,
    four_step,
    three_step,
    two_step,
    one_step,
    now,
    total_step
};

class Map
{
    std::vector<std::vector<std::pair<int, bool *>>> mapp;

    public:
    Map();
    ~Map();
    void SetChessPos(chess_man **, chess_man **);
    bool *takeColor(int x, int y);
    int getNumber(int x, int y);
    bool operator!=(const Map &abc);
    void MoveChess(int Pos_befor_x, int Pos_befor_y, int Pos_after_x, int Pos_after_y);
    void lammoiMap();
};

class ChessObject
{
private:
    Uint8 do_mo;
    int su_thay_doi_do_mo;
    SDL_Point pos;
    chess_object chessOJ;
    MyTexture* ObjectTex;
    int vien;
public:
    bool on;
    ChessObject(chess_object);
    ~ChessObject();
    void setpos(int, int);
    void render();
    void render_nhapnhay();
};
