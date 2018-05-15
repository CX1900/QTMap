#include "world.h"
#include "icon.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "monster.h"

using namespace std;

void World::initWorld(char *mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5

    ifstream mapdata(mapFile);
    char line[300];

    mapdata.getline(line, 100);
    setplayer(line);

    mapdata.getline(line, 100);
    //setMonster(line);

    mapdata.getline(line, 300);
    while(!mapdata.eof())
    {
        setobject(line);
        mapdata.getline(line, 300);
    }

    mapdata.close();
}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if((*it).getObjType()=="peristele")
        {
            break;
        }
        (*it).show(painter);
    }
    this->_player.show(painter);
    //this->_monster.show(painter);
    for(it;it!=this->_objs.end();it++)
        (*it).show(painter);
}

void World::handlePlayerMove(int direction, int steps){
    if(movejustify(direction, steps, this->_player.getPosX(), this->_player.getPosY() + 1, 1))
        this->_player.move(direction, steps);
}

/*bool World::Gameover(){
    if(this->_player.getPosX() == this->_monster.getPosX() && this->_player.getPosY()  == this->_monster.getPosY())
    {
        _objs.clear();
        return true;
    }
    return false;
}*/

void World::setxsety(char *line, char *ox, char *oy, int i){
    int j = 0;
    while(line[i] != '-')
    {
        ox[j] = line[i];
        j++;
        i++;
    }
    ox[j] = '\0';
    i++;
    j = 0;
    while(line[i] != ','){
        oy[j] = line[i];
        j++;
        i++;
    }
    oy[j] = '\0';
}

void World::setplayer(char *line){
    char ox[3], oy[3];
    setxsety(line, ox, oy, 7);

    this->_player.initObj("player");
    this->_player.setPosX(atoi(ox));
    this->_player.setPosY(atoi(oy));
}

void World::setobject(char *line){
    int i = 0;
    char object[10], ox[3], oy[3];
    while(line[i] != ',')
    {
        object[i] = line[i];
        i++;
    }
    object[i] = '\0';
    i++;
    while(line[i] != '\0'){
        int j = 0;
        RPGObj obj;
        obj.initObj(object);
        while(line[i+j] != '-')
        {
            ox[j] = line[i+j];
            j++;
        }
        ox[j] = '\0';
        i = j + i + 1;
        j = 0;

        while(line[i+j] != ',')
        {
            oy[j] = line[i+j];
            j++;
        }
        oy[j] = '\0';
        obj.setPosX(atoi(ox));
        obj.setPosY(atoi(oy));
        this->_objs.push_back(obj);
        i = i + j + 1;
    }
}

int World::movejustify(int direction, int steps,int px, int py ,int role){
    vector<RPGObj>::iterator it;

    switch (direction){
        case 1:
            py -= steps;
            break;
        case 2:
            py += steps;
            break;
        case 3:
            px -= steps;
            break;
        case 4:
            px += steps;
            break;
    }
    if(px<0)
        return 0;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if(!(*it).canEat())
        {
            if((*it).getObjType()=="well"){
                int ax = (px>=(*it).getPosX() && px<=(*it).getPosX()+1);
                int ay = (py>=(*it).getPosY()+1 && py<=(*it).getPosY()+2);
                if(ax && ay)
                    return 0;
            }
            else if((*it).getObjType()=="tree"){
                int ax = (px>=(*it).getPosX() && px<=(*it).getPosX()+1);
                int ay = (py==(*it).getPosY()+1);
                if(ax && ay)
                    return 0;
            }
            else if((*it).getObjType()=="light"){
                int ax = (px==(*it).getPosX());
                int ay = (py==(*it).getPosY()+2);
                if(ax && ay)
                    return 0;
            }
            else if((*it).getObjType()=="peristele"){
                int ax = (px==(*it).getPosX());
                int ay = (py==(*it).getPosY()+1);
                if(ax && ay)
                    return 0;
            }
            else if(!(*it).canCover()){
                int ax = (px>=(*it).getPosX() && px<(*it).getPosX()+(*it).getWidth());
                int ay = (py>=(*it).getPosY() && py<(*it).getPosY()+(*it).getHeight());
                if(ax && ay){
                    return 0;
                }

            }
        }
        else
        {
            if(role == 1 && (*it).getPosX() == px && (*it).getPosY() == py)
            {
                _objs.erase(it);
                return 1;
            }
            else if (role == 0 && (*it).getPosX() == px && (*it).getPosY() == py)
                return 0;
        }
    }
    return 1;
}

void World::savedata(){
    ofstream savefile("E:\\QTMap\\QTMap\\savedata.txt");
    savefile << "player," << this->_player.getPosX() << '-' << this->_player.getPosY() << ",\n";

    vector<RPGObj>::iterator it;
    it = this->_objs.begin();
    string name = (*it).getObjType();
    savefile << name << ',' << (*it).getPosX() << '-' << (*it).getPosY() << ',';

    for(it=this->_objs.begin()+1;it!=this->_objs.end();it++){
        if(name!=(*it).getObjType())
        {
            savefile << '\n';
            name = (*it).getObjType();
            savefile << name << ',' << (*it).getPosX() << '-' << (*it).getPosY() << ',';
        }
        else{
            savefile << (*it).getPosX() << '-' << (*it).getPosY() << ',';
        }
    }
    savefile << '\n';
}
