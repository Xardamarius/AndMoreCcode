#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT 0x0501
#include <windows.h>

#define sqr(x) (x)*(x)

#define worldW 600
#define worldH 300
#define width 80
#define height 24
#define c_sand (char)176
#define c_water (char)219
#define c_wall '#'
#define c_space ' '
#define c_soil (char)178

typedef char Tworld[worldH][worldW];
Tworld world;

typedef char Tmap[height][width];
Tmap map;
POINT CamPos = {-3, -3};
POINT mousePos;
POINT sellSize;
enum {s_sand = 0, s_water, s_wall, s_last} substance = s_sand;
char subChar[] = {c_sand, c_water, c_wall};
char *subName[] = {"sand","water","wall"};

typedef struct { int x,y, w,h, speed, ay; } TPlayer;
TPlayer player = { worldW/2,90, 2,3, 2,0};
POINT dirInc[] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

typedef enum {b_solid, b_liquid, b_gas} TBlockType;
char solidBlocks[] = {c_sand, c_wall, c_soil, 0};
char liquidBlocks[] = {c_water, 0};

void FocusToPlayer(TPlayer plr)
{
    static const int dx = width / 2;
    static const int dy = height / 2;
    CamPos.x = plr.x - dx;
    CamPos.y = plr.y - dy;
}

char IfPointInWorld(int x, int y)
{
    return !((x < 0) || (y < 0) || (x >= worldW) || (y >= worldH));
}

char IsCrossBlocks(RECT r, char blocks[])
{
    int k;
    for (int i = r.left; i <= r.right; i++)
        for (int j = r.top; j <= r.bottom; j++)
            if (k = 0, IfPointInWorld(i,j))
                while (blocks[k] != '\0')
                    if (world[j][i] == blocks[k++])
                        return 1;
    return 0;
}

RECT GetPlayerRect(TPlayer pl)
{
    return (RECT){pl.x, pl.y, pl.x + pl.w -1, pl.y + pl.h -1};
}

TBlockType TryMovePlayer(TPlayer *plr, int dx, int dy)
{
    TPlayer old = *plr;
    plr->x += dx;
    plr->y += dy;

    RECT rct = GetPlayerRect(*plr);
    if (IsCrossBlocks(rct, solidBlocks))
        return (*plr = old, b_solid);
    if (IsCrossBlocks(rct, liquidBlocks))
        return b_liquid;
    return b_gas;
}

int GetOne(int a)
{
    return (a > 0 ? 1 : (a < 0 ? -1 : 0));
}

void ApplyPlayerGravity(TPlayer *plr)
{
    plr->ay++;
    TBlockType res;
    for (int k = 0; k < abs(plr->ay); k++)
    {
        res = TryMovePlayer(plr, 0, GetOne(plr->ay) );
        if (res == b_solid) plr->ay = 0;
        if (res == b_liquid) plr->ay -= GetOne(plr->ay);
    }
}

void PlayerMove(TPlayer *plr, char w, char s, char a, char d)
{
    ApplyPlayerGravity(plr);
    char wasd[4] = {w,s,a,d};
    for (int k = 0; k < plr->speed; k++)
        for (int i = 0; i < 4; i++)
            if (GetKeyState(wasd[i]) < 0)
            {
                if (i == 0)
                {
                    RECT foot = {plr->x, plr->y + plr->h,
                             plr->x + plr->w - 1, plr->y + plr->h};
                    if (IsCrossBlocks(foot, solidBlocks))
                    plr->ay = -4;
                    if (!IsCrossBlocks(GetPlayerRect(*plr), liquidBlocks))
                    continue;
                }
                TryMovePlayer(plr, dirInc[i].x, dirInc[i].y);
            }
}

void PlayerShow(Tmap map, TPlayer plr)
{
    int x = plr.x - CamPos.x;
    int y = plr.y - CamPos.y;
    for (int i = x; i < x + plr.w; i++)
        for (int j = y; j < y + plr.h; j++)
            map[j][i] = '@';
}

void PutCircle(int x, int y, int rad, char c)
{
    for (int i = x-rad; i < x+rad; i++)
        for (int j = y-rad; j < y+rad; j++)
            if ( IfPointInWorld(i, j) &&
                (sqr(x-i) + sqr(y-j) <= sqr(rad)) )
                world[j][i] = c;
}

void GenerateWorld(int speed)
{
    srand(speed);
    memset(world, c_soil, sizeof(world));
    for (int i = 0; i < 100; i++)
        memset(world[i], c_space, sizeof(world[i]));
    for (int i = 0; i < worldW; i++)
        PutCircle(rand() % worldW, 110 + rand() % 20, rand() % 20, c_soil);
    for (int i = 0; i < worldW; i++)
    {
        int x = rand() % worldW;
        int y = 110 + rand() % (worldH-100);
        int rad = 2 + rand() % 10;
        PutCircle(x, y, rad, c_space);
        if (rand() % 10 == 0)
            PutCircle(x, y, rad, c_water);
        else if (rand() % 10 == 0)
            PutCircle(x, y, rad, c_sand);
    }
}

void WorldToMapFrom(int x, int y)
{
    memset(map, '.', sizeof(map));
    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            if (IfPointInWorld(x+i, y+j))
                map[j][i] = world[y+j][x+i];
}

POINT GetMousePos(HWND hwnd, POINT sellSz)
{
    static POINT pt;
    GetCursorPos(&pt);
    ScreenToClient(hwnd, &pt);
    pt.x /= sellSz.x;
    pt.y /= sellSz.y;
    return pt;
}

POINT GetSellSize(HWND hwnd)
{
    RECT rct;
    GetClientRect(hwnd, &rct);
    POINT sellSz;
    sellSz.x = (rct.right - rct.left) / width;
    sellSz.y = (rct.bottom - rct.top) / height;
    return sellSz;
}

void SetCurPos(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ShowMap(Tmap map)
{
    SetCurPos(0,0);
    map[height-1][width-1] = '\0';
    printf("%s", map[0]);
}

void ShowInfo()
{
    SetCurPos(0, height);
    printf("   ");
    for (int i = 0; i < s_last; i++)
        printf("%d-%s   ", i+1, subName[i]);
    printf("LMB-put %s   RMB-clear   ", subName[substance]);
}

void SelectSubstance()
{
    for (int i = 0; i < s_last; i++)
        if (GetKeyState('1' + i) < 0) substance = i;
}

void PutLine(POINT a, POINT b, char sub)
{
    float dx = (b.x - a.x) / (float)width;
    float dy = (b.y - a.y) / (float)width;
    int x,y;
    for (int i = 0; i < width; i++)
        {
            x = (a.x + dx * i);
            y = (a.y + dy * i);
            if (IfPointInWorld(x,y))
                world[y][x] = sub;
        }
}

void PutSubstance(POINT pt)
{
    static POINT old;
    pt.x += CamPos.x;
    pt.y += CamPos.y;
    if (GetKeyState(VK_LBUTTON) < 0)
        PutLine(old, pt, subChar[substance]);
    else if (GetKeyState(VK_RBUTTON) < 0)
        PutLine(old, pt, c_space);
    old = pt;
}

char IfPointInMap(int x, int y)
{
    return !((x < 0) || (y < 0) || (x >= width) || (y >= height));
}

void MoveSand(int x, int y)
{
    for(int i = 0; i <= 1; i += (i == 0 ? -1 : 2))
        if (IfPointInWorld(x+i, y+1))
            if ((world[y+1][x+i] == c_space)  ||
                (world[y+1][x+i] == c_water))
            {
                world[y][x] = world[y+1][x+i];
                world[y+1][x+i] = c_sand;
                break;
            }
}

Tworld worldTmp;
char waterLevel;
POINT foundPoint;

void FindWaterPath(int x, int y)
{
    if (!IfPointInWorld(x,y)) return;

    if ((y >= waterLevel) && (y > foundPoint.y))
        if (worldTmp[y][x] == c_space)
        {
            foundPoint.x = x;
            foundPoint.y = y;
        }
    if (worldTmp[y][x] == c_water)
    {
        worldTmp[y][x] = '#';
        FindWaterPath(x, y-1);
        FindWaterPath(x, y+1);
        FindWaterPath(x-1, y);
        FindWaterPath(x+1, y);
    }
}

void MoveWater(int x, int y)
{
    if (!IfPointInWorld(x, y+1)) return;
    if (world[y+1][x] == c_space)
    {
        world[y][x] = c_space;
        world[y+1][x] = c_water;
    }
    else if (world[y+1][x] == c_water)
    {
        if (IfPointInWorld(x, y-1)&& (world[y-1][x] == c_water))
            return;
        waterLevel = y+1;
        foundPoint.y = -1;
        memcpy(worldTmp, world, sizeof(world));
        FindWaterPath(x,y+1);
        if (foundPoint.y >= 0)
        {
            world[foundPoint.y][foundPoint.x] = c_water;
            world[y][x] = c_space;
        }
    }
}

void MoveSubstance()
{
    for (int j = worldH-1; j >= 0; j--)
        for (int i = 0; i < worldW; i++)
        {
            if (world[j][i] == c_sand) MoveSand(i, j);
            if (world[j][i] == c_water) MoveWater(i, j);
        }
}

int main()
{
    HWND hwnd = GetConsoleWindow();
    sellSize = GetSellSize(hwnd);
    GenerateWorld(0);
    do
    {
        mousePos = GetMousePos(hwnd, sellSize);
        SelectSubstance();
        PutSubstance(mousePos);
        PlayerMove(&player, 'W','S','A','D');
        FocusToPlayer(player);

        MoveSubstance();

        WorldToMapFrom(CamPos.x, CamPos.y);
        PlayerShow(map, player);
        PlayerShow(map, player);
        ShowMap(map);
        ShowInfo();
        Sleep(50);
    }
    while(GetKeyState(VK_ESCAPE) >= 0);
    return 0;
}

