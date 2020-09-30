#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <vector>
#include <tuple>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"


using x_and_y = std::tuple<float, float>;


class Food : public MazeEntity <std::vector<x_and_y>>,public GeneralGameEntity <std::vector<x_and_y>>
{
public:
    Food();
    virtual void ReadEntityFromFile() override;
    virtual std::vector<x_and_y> ReturnEntityVec() const override;
    virtual std::vector<x_and_y> HitBox() const override;
    virtual void DestroyEntity() override;
    ~Food();

private:
    std::vector<x_and_y>Foods;
    float foodLength=25;
    float foodHeight=27;

};

#endif // FOOD_H
