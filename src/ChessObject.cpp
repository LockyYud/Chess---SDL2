#include "common.h"
#include "ChessObject.h"
///ChessObject function
ChessObject::ChessObject(chess_object OJ)
{
    pos.x = 1;
    pos.y = 1;
    chessOJ = OJ;
    ObjectTex = &Object[int(chessOJ)];
    on = false;
    do_mo = 255;
    su_thay_doi_do_mo = 15;
    vien = ( window_height - 8 * size_img_chess) / 2;
}
ChessObject::~ChessObject()
{
}
void ChessObject::setpos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void ChessObject::render()
{
    SDL_Rect dst;
    dst.h = dst.w = size_img_chess;
    dst.x = (pos.x - 1) * size_img_chess + vien;
    dst.y = (pos.y - 1) * size_img_chess + vien;
    ObjectTex->render(dst);
}
void ChessObject::render_nhapnhay()
{
    ObjectTex->setAlpha(do_mo);
    if(do_mo - su_thay_doi_do_mo < 0 or do_mo - su_thay_doi_do_mo > 255) su_thay_doi_do_mo =- su_thay_doi_do_mo;
    do_mo = do_mo - su_thay_doi_do_mo;
    SDL_Rect dst;
    dst.h = dst.w = size_img_chess;
    dst.x = (pos.x - 1) * size_img_chess + vien;
    dst.y = (pos.y - 1) * size_img_chess + vien;
    ObjectTex->render(dst);
}

///MapS function
Map::Map()
{
    std::vector<std::pair<int, bool*>> temp(9);
    for(int i = 0; i < 9; i++)
    {
        temp[i].first = 16;
        temp[i].second = NULL;
    }
    for(int i = 0; i < 9; i++)
    {
        mapp.push_back(temp);
    }
    for(int i = 0; i < 8; i++)
    {
        mapp[i+1][2].first = i;
        mapp[i+1][2].second = &sai;
        mapp[i+1][7].first = i;
        mapp[i+1][7].second = &dung;
    }
    for(int i = 1; i <= 8; i++)
    {
        mapp[i][8].first = i + 7;
        mapp[i][8].second = &dung;
        mapp[i][1].first = i + 7;
        mapp[i][1].second = &sai;
    }
}

Map::~Map()
{
}
void Map::SetChessPos(chess_man** white, chess_man** black)
{
    for(int i = 0; i < 16; i++)
    {
        white[i]->isLive = false;
        black[i]->isLive = false;
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(mapp[i][j].first < 16)
            {
                if(*mapp[i][j].second)
                {
                    white[mapp[i][j].first]->Setposition(i,j);
                    white[mapp[i][j].first]->isLive = true;
                }
                else
                {
                    black[mapp[i][j].first]->Setposition(i,j);
                    black[mapp[i][j].first]->isLive = true;
                }
            }
        }
    }
}

bool* Map::takeColor(int x, int y)
{
    return mapp[x][y].second;
}

bool Map::operator!=(const Map& okeoke)
{
    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            if(this->mapp[i][j].first != okeoke.mapp[i][j].first) return true;
        }
    }
    return false;
}

int Map::getNumber(int x, int y)
{
    return mapp[x][y].first;
}

void Map::MoveChess(int x1, int y1, int x2, int y2)
{
    mapp[x2][y2].first = mapp[x1][y1].first ;
    mapp[x2][y2].second = mapp[x1][y1].second;
    mapp[x1][y1].first = 16;
    mapp[x1][y1].second = NULL;
}

void Map::lammoiMap()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            mapp[i][j].first = 16;
            mapp[i][j].second = NULL;
        }
    }
    for(int i = 0; i < 8; i++)
    {
        mapp[i+1][2].first = i;
        mapp[i+1][2].second = &sai;
        mapp[i+1][7].first = i;
        mapp[i+1][7].second = &dung;
    }
    for(int i = 1; i <= 8; i++)
    {
        mapp[i][8].first = i + 7;
        mapp[i][8].second = &dung;
        mapp[i][1].first = i + 7;
        mapp[i][1].second = &sai;
    }
}