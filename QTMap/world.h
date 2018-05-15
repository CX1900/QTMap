#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"
//#include "monster.h"

class World
{
public:
    World(){}
    ~World(){}
    void initWorld(char *mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void handlePlayerMove(int direction, int steps);
        //假定只有一个玩家
    void setplayer(char *line);
    void setobject(char *line);
    //void setMonster(char *line);
    void setxsety(char *line, char *ox, char *oy, int i);
    
    //void Monstermove(int direction, int steps);
    bool Gameover();
    void savedata();

    int movejustify(int direction, int steps, int px, int py, int role);

private:
    vector<RPGObj> _objs;
    Player _player;
   // Monster _monster;
};

#endif // WORLD_H
