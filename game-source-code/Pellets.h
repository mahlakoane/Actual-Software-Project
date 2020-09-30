#ifndef PELLETS_H
#define PELLETS_H
#include "Maze.h"
#include <vector>
#include "MazeEntity.h"
#include "GeneralGameEntity.h"

struct PelletProperties{
float x_coord=0;
float y_coord=0;
char PelletType=0;
};


class Pellets : public MazeEntity <std::vector<PelletProperties>>, public GeneralGameEntity <std::vector<PelletProperties>>
{
    public:
        Pellets();
        virtual void ReadEntityFromFile() override;
        virtual std::vector<PelletProperties> ReturnEntityVec() const override;
        virtual std::vector<PelletProperties> HitBox() const override;
        virtual void DestroyEntity() override;
        virtual ~Pellets();

    private:
        PelletProperties CurrentPellet;
        std::vector<PelletProperties>pelletVec;
        float normalPelletLength =28;
        float normalPelletHeight=29;
        float superPelletLength =24;
        float superPelletHeight=21;


};

#endif // PELLETS_H
