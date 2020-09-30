#include "Ghost.h"

Ghost::Ghost(float x_startPos, float y_startPos)
{
    this->x_ghostPosition_ = x_startPos;
    this->y_ghostPosition_ = y_startPos;

    this->ghostWidth_ = Constants::MOVING_OBJECT_WIDTH;
    this->ghostHeight_ = Constants::MOVING_OBJECT_HEIGHT;
}

x_and_y Ghost::getEntityPosition() const
{
    return {x_ghostPosition_, y_ghostPosition_};
}

x_and_y Ghost::getSizeOfEntity() const
{
    return {ghostWidth_, ghostHeight_};
}

void Ghost::setEntityPosition(float x, float y)
{
    x_ghostPosition_ = x;
    y_ghostPosition_ = y;
}

void Ghost::setEntityMoveDirection(Orientation orientation)
{

}

void Ghost::moveEntity()
{

}

BoundingBox Ghost::HitBox() const
{

}

void Ghost::DestroyEntity()
{

}

Orientation Ghost::getEntityMoveDirection() const
{

}

void Ghost::isEntityInsideTheMaze()
{
    auto [x_ghostPosition, y_ghostPosition] = getEntityPosition();

    auto leftEdge = Constants::LEFT_EDGE;
    auto rightEdge = Constants::RIGHT_EDGE;
    auto topEdge = Constants::TOP_EDGE;
    auto bottomEdge = Constants::BOTTOM_EDGE;

    if(y_ghostPosition > bottomEdge)
        setEntityPosition(x_ghostPosition, bottomEdge);
    else if(y_ghostPosition < topEdge)
        setEntityPosition(x_ghostPosition, topEdge);
    else if (x_ghostPosition < leftEdge)
        setEntityPosition(leftEdge, y_ghostPosition);
    else if(x_ghostPosition > rightEdge)
        setEntityPosition(rightEdge, y_ghostPosition);
}
