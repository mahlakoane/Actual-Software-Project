#ifndef GHOST_H
#define GHOST_H
#include "Orientation.h"
#include <tuple>
#include "MovableEntity.h"
#include "GeneralGameEntity.h"

using x_and_y = std::tuple<float, float>;

class Ghost : public MovableEntity <Orientation>,public GeneralGameEntity <BoundingBox>
{
public:
    Ghost(float xStartPos, float yStartPos);
    virtual x_and_y getEntityPosition() const override;
    virtual x_and_y getSizeOfEntity() const override;
    virtual void setEntityMoveDirection(Orientation orientation) override;
    virtual Orientation getEntityMoveDirection() const override;
    virtual void moveEntity() override;
    virtual void isEntityInsideTheMaze() override;
    virtual void setEntityPosition(float x, float y) override;
    virtual BoundingBox HitBox() const override;
    virtual void DestroyEntity() override;

private:
    Orientation ghostMoveDirection_;
    float ghostWidth_;
    float ghostHeight_;
    float x_ghostPosition_;
    float y_ghostPosition_;
    float movementStep_;
};

#endif // GHOST_H
