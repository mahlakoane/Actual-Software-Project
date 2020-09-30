#ifndef PLAYERCOLLISIONS_H
#define PLAYERCOLLISIONS_H
#include "GameMaze.h"
#include "Player.h"


class PlayerCollisions
{
    public:
        PlayerCollisions();
        bool DoPlayerAndWallsCollide(Player& currentPlayer); ///Player is not a fixed property, it changes
        bool playerAndDoors(Player& currentPlayer);
        bool playerVsFood(Player& currentPlayer);
        bool playerAndKeys(Player& currentPlayer);
        bool playerAndPellets(Player& currentPlayer);
        ~PlayerCollisions();

    private:
        GameMaze AllObjects_;
        bool Intersects(BoundingBox& Box1,BoundingBox& Box2);


};

#endif // PLAYERCOLLISIONS_H
