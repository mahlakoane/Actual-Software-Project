#ifndef PLAYER_H
#define PLAYER_H
#include "Orientation.h"
#include <tuple>
#include "MovableEntity.h"
#include "GeneralGameEntity.h"




using x_and_y = std::tuple<float, float>;

class Player : public MovableEntity <Orientation>, public GeneralGameEntity <BoundingBox>
{
    public:
        Player(Orientation playerOrientation);
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
        Orientation playerMoveDirection_;
        Orientation playerOrientation_;
        BoundingBox CurrentBox;
        float playerWidth_;
        float playerHeight_;
        float x_playerPosition_;
        float y_playerPosition_;
        float movementStep_;


};

#endif // PLAYER_H
