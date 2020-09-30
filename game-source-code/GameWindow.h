#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Maze.h"
#include "Mazedoors.h"
#include "Food.h"
#include "Keys.h"
#include "Pellets.h"
#include "GameMaze.h"
#include "Player.h"


class GameWindow
{
    public:

        GameWindow(sf::RenderWindow& window,GameMaze& Maze);
        void drawMaze();
        void drawDoors();
        void drawFoods();
        void drawKeys();
        void drawPellets();
        void drawEveryObject();
        ~GameWindow();


    private:
       sf::RenderWindow& window_;
       GameMaze WholeMaze;
       sf::Texture texture;
};

#endif // GAMEWINDOW_H
