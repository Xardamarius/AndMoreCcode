#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define width 80
#define height 25

struct{
    char map[height][width+1];
    POINT sz;
} loc;

void loc_LoadFromFile(char *fileName)
{
    memset(&loc.map, ' ', sizeof(loc));
    for (int i = 0; i < height; i++)
        loc.map[i][width] = '\0';

    FILE *f = fopen(fileName, "r");
    char c[80];
    int line = 0;
    loc.sz.x = 0;
    loc.sz.y = 0;
    while (!feof(f))
    {
        fgets(c, width, f);
        int cnt = strlen(c);
        if (c[cnt-1] == '\n') cnt--;
        strncpy(loc.map[line], c, cnt);
        line++;
        if (cnt > loc.sz.x) loc.sz.x =cnt;
    }
    loc.sz.y = line;
    fclose(f);

    loc.map[height-1][width-1] = '\0';
}

void SetCurPos()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), coord );
}

char map[height][width+1];

void map_Show()
{
    SetCurPos();
    for (int i = 0; i < height; i++)
        printf("%s", map[i]);
}

void loc_PutOnMap()
{
    memcpy(map, loc.map, sizeof(map) );
}

typedef struct {
    char name[20];
} TItem;

struct {
    char name[20];
    POINT pos;
    POINT locPos;
    TItem items[20];
} player;

typedef struct {
    char name[20];
    char oType;
    POINT pos;
    char item_Message[200];
    TItem item_Need;
    int item_Cnt;
    TItem item_Given;
} TObj;

TObj *obj = NULL;
int  objCnt = 0;

TObj *obj_Add()
{
    objCnt++;
    obj = realloc( obj, sizeof(*obj) * objCnt);
    return obj + objCnt - 1;
}

void obj_LoadFormFile(char *name)
{
    objCnt = 0;
    obj = realloc( obj, 0);

    TObj *tmp;

    FILE *f = fopen(name, "rt");
    if (f)
        while (!feof(f))
        {
            tmp = obj_Add();
            fgets(tmp->name, 1000, f);
            fscanf(f, "%c", &tmp->oType);
            fscanf(f, "%d", &tmp->pos.x);
            fscanf(f, "%d\n", &tmp->pos.y);

            fgets(tmp->item_Message, 1000, f);
            fgets(tmp->item_Need.name, 1000, f);
            fscanf(f, "%d\n", &tmp->item_Cnt);

            fgets(tmp->item_Given.name, 1000, f);
            int len = strlen(tmp->item_Given.name);
            if(tmp->item_Given.name[len-1] == '\n') tmp->item_Given.name[len-1] == '\0';
        }
    fclose(f);
}

void obj_PutOnMap()
{
    for (int i = 0; i < objCnt; i++)
        map[obj[i].pos.y][obj[i].pos.x] = obj[i].oType;
}

TObj *obj_GetByXY(int x, int y)
{
    for (int i = 0; i < objCnt; i++)
        if ((obj[i].pos.x == x) && (obj[i].pos.y == y))
            return obj + i;
    return NULL;
}

int player_GetItemCnt(TItem item)
{
    int cnt = 0;
    int len = strlen(item.name);
    if (item.name[len-1] == '\n') len--;
    for (int i = 0; i < 20; i++)
        if ( strncmp(item.name, player.items[i].name, len) == 0)
            cnt++;
    return cnt;
}

void player_AddItem(TItem item)
{
    for (int i = 0 ; i < 20; i++)
        if (player.items[i].name[0] == 0)
        {
            sprintf( player.items[i].name, item.name);
            return;
        }
}

int player_deleteItem(TItem item, int delCnt)
{
    int cnt = player_GetItemCnt(item);
    if (delCnt > cnt) return 0;

    int len = strlen(item.name);
    if (item.name[len-1] == '\n') len--;
    for (int i = 0; i < 20; i++)
        if ( strncmp(item.name, player.items[i].name, len) == 0 )
        {
            memset(player.items[i].name, 0, sizeof(player.items[i].name) );
            delCnt--;
            if (delCnt < 1) return 1;
        }
    return -1;
}

void obj_StartDialog(TObj *obj)
{
    if (obj == NULL) return;
    char ans;
    do
    {
        system("cls");
        printf("%s\n", obj->name);


        if (obj->oType == '/')
        {
                if (player_GetItemCnt(obj->item_Need) < obj->item_Cnt)
                {
                    printf("\n%s\n", obj->item_Message);
                    printf("\n0 - Exit");
                    ans = getch();
                }
                else
                {
                    printf("\nEnter the door?");
                    printf("\n1 - Yes");
                    printf("\n0 - No");
                    ans = getch();
                    if (ans == '1');
                        {
                        player.pos.x += (obj->pos.x - player.pos.x) *2;
                        player.pos.y += (obj->pos.y - player.pos.y) *2;
                        ans = '0';
                        }
                }
        }
        if (obj->oType == "N")
        {
            if (player_GetItemCnt(obj->item_Need) < obj->item_Cnt)
                {
                    printf("\n%s\n", obj->item_Message);
                    printf("\n0 - Exit");
                    ans = getch();
                }
                else
                {
                    printf("\nNeed a %s?", obj->item_Given.name);
                    printf("\n1 - Yes");
                    printf("\n0 - No");
                    ans = getch();
                    if (ans == '1');
                    {
                        TItem item;
                        sprintf(item.name, obj->item_Given.name);
                        if (    (player_GetItemCnt(item) == 0)
                                && (player_deleteItem(obj->item_Need, obj->item_Cnt) > 0) )
                                player_AddItem(item);
                        ans = '0';
                    }

                }

        }
        else
            ans = '0';
    }
    while (ans != '0');

}

void player_Init(int xLoc, int yLoc, int x, int y, char *name)
{
    player.pos.x = x;
    player.pos.y = y;
    sprintf(player.name, name);
    player.locPos.x = xLoc;
    player.locPos.y = yLoc;
    memset(player.items, 0, sizeof(player.items) );
}

void player_PutOnMap()
{
    map[player.pos.y][player.pos.x] = 'A';

    static int dx = 55;
    for (int k = 0; k < 20; k++)
    {
        for (int i = 0; i < 20; i++)
            if ((player.items[k].name[i] != 0) && (player.items[k].name[i] != '\n'))
                map[k][dx + i] = player.items[k].name[i];
    }
}

void player_Control()
{
    POINT old = player.pos;
    if (GetKeyState('W') < 0) player.pos.y--;
    if (GetKeyState('S') < 0) player.pos.y++;
    if (GetKeyState('A') < 0) player.pos.x--;
    if (GetKeyState('D') < 0) player.pos.x++;
    if (map[player.pos.y][player.pos.x] != ' ')
    {
        if (map[player.pos.y][player.pos.x] == 'a')
        {
            TItem item;
            sprintf(item.name, "Apple");
            player_AddItem(item);
            sleep(1);
        }

        TObj *obj = obj_GetByXY(player.pos.x, player.pos.y);
        player.pos = old;
        obj_StartDialog(obj);
    }


    if (player.pos.x > loc.sz.x - 2)
    {
        player.locPos.x++;
        player_LoadLocation();
        player.pos.x = 1;
    }

    if (player.pos.x < 1)
    {
        player.locPos.x--;
        player_LoadLocation();
        player.pos.x = loc.sz.x - 2;
    }

    if (player.pos.y > loc.sz.y - 2)
    {
        player.locPos.y++;
        player_LoadLocation();
        player.pos.y = 1;
    }

    if (player.pos.y < 1)
    {
        player.locPos.y--;
        player_LoadLocation();
        player.pos.y = loc.sz.y - 2;
    }
}

void player_Save()
{
    FILE *f = fopen(player.name, "wb");
        fwrite(&player, 1, sizeof(player), f);
    fclose(f);
}

void player_Load(char *name)
{
    FILE *f = fopen(name, "rb");
    if (f == NULL)
        player_Init(0,0, 5,5, name);
    else
        fread(&player, 1, sizeof(player), f);
    fclose(f);
}

void player_LoadLocation()
{
    char c[100];
    sprintf(c, "map_%d_%d.txt", player.locPos.x, player.locPos.y);
    loc_LoadFromFile(c);
    /*sprintf(c, "obj_%d_%d.txt", player.locPos.x, player.locPos.y);
    loc_LoadFromFile(c);*/
}

int main()
{
    player_Load("Xardamarius");
    player_LoadLocation();
    do
    {
        player_Control();
        loc_PutOnMap();
        obj_PutOnMap();
        player_PutOnMap();
        map_Show();
        Sleep(1);
    }
    while (GetKeyState(VK_ESCAPE) >= 0);

    player_Save();

    return 0;
}
