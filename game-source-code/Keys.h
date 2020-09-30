#ifndef KEYS_H
#define KEYS_H
#include <iostream>
#include <vector>
#include <tuple>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"

using x_and_y = std::tuple<float, float>;


class Keys : public MazeEntity <std::vector<x_and_y>>, public GeneralGameEntity <std::vector<x_and_y>>
{
    public:
        Keys();
        virtual void ReadEntityFromFile() override;
        virtual std::vector<x_and_y> ReturnEntityVec() const override;
        virtual std::vector<x_and_y> HitBox() const override;
        virtual void DestroyEntity() override;

        ~Keys();

    private:
        std::vector<x_and_y>KeyVec;
        float keyLength=21;
        float keyHeight=27;

};

#endif // KEYS_H
