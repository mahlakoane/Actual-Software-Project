#ifndef MAZEDOORS_H
#define MAZEDOORS_H
#include <iostream>
#include <vector>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"

//using x_and_y = std::tuple<float, float>;
struct MazeDoorComponents{
float x_coord=0;
float y_coord=0;
char orientation=' ';
};

class Mazedoors : public MazeEntity <std::vector<MazeDoorComponents>> , public GeneralGameEntity <std::vector<MazeDoorComponents>>
{
    public:
        Mazedoors();
        virtual void ReadEntityFromFile() override;
        virtual std::vector<MazeDoorComponents> ReturnEntityVec() const override;
        virtual std::vector<MazeDoorComponents> HitBox() const override;
        virtual void DestroyEntity() override;
        ~Mazedoors();

    private:
        MazeDoorComponents currentDoor;
        std::vector<MazeDoorComponents>mazedoors;
        float doorLength=37;
        float doorThickness=5;

};



#endif // MAZEDOORS_H
