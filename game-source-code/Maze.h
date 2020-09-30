#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <tuple>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"

struct mazeWall{
        float x_coord;
        float y_coord;
        float length;
        char Orientation;
        };


class Maze : public MazeEntity <std::vector<mazeWall>> , public GeneralGameEntity <std::vector<mazeWall>>
{
    public:
        Maze();
        virtual void ReadEntityFromFile() override;
        virtual std::vector<mazeWall> ReturnEntityVec() const override; //one between these two must go
        virtual std::vector<mazeWall> HitBox() const override;
        virtual void DestroyEntity() override;

        ~Maze();


    private:
        mazeWall currentWall;
        std::vector<mazeWall>LogicMaze;
        float WallThickness=10;
        //vector<vector<int>> vec( 565 , vector<int> (522, 0));



};

#endif // MAZE_H
