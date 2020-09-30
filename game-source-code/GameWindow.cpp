#include "GameWindow.h"

using namespace std;
GameWindow::GameWindow(sf::RenderWindow& window,GameMaze& Maze):window_(window),WholeMaze(Maze)
{

}

void GameWindow::drawMaze()
{
    auto maze=WholeMaze.mazeWalls();
    auto currMaze = maze.ReturnEntityVec();  /// this returns the Logic maze vector;
    for(auto wall : currMaze) ///deal with maze walls
    {
        if(wall.Orientation=='v')
        {
            sf::RectangleShape rect(sf::Vector2f(10.f,wall.length));
            rect.setPosition(sf::Vector2f(wall.x_coord,wall.y_coord));
            window_.draw(rect);

        }
        else if(wall.Orientation=='h')
        {
            sf::RectangleShape rect(sf::Vector2f(wall.length,10.f));
            rect.setPosition(sf::Vector2f(wall.x_coord,wall.y_coord));
            window_.draw(rect);

        }

    }

}


void GameWindow::drawDoors()
{
///deal with doors
    auto doors=WholeMaze.mazeDoors();
    auto doorVec=doors.ReturnEntityVec();
    for(auto door : doorVec)
    {
        if(door.orientation=='v')
        {
            sf::RectangleShape currentDoor(sf::Vector2f(5.f,37.f));
            currentDoor.setPosition(sf::Vector2f(door.x_coord,door.y_coord));
            currentDoor.setFillColor(sf::Color(100, 250, 50));
            window_.draw(currentDoor);

        }
        else if(door.orientation=='h')
        {
            sf::RectangleShape currentDoor(sf::Vector2f(37.f,5.f));
            currentDoor.setPosition(sf::Vector2f(door.x_coord,door.y_coord));
            currentDoor.setFillColor(sf::Color(100, 250, 50));
            window_.draw(currentDoor);

        }

    }
}

void GameWindow::drawFoods()
{
    auto foods=WholeMaze.MazeFoods();
    auto FoodVector=foods.ReturnEntityVec();
    for(auto foodItem : FoodVector)
    {

        if(!texture.loadFromFile("Resources/food.png")) {}
        sf::RectangleShape normalPellet(sf::Vector2f(25.f,27.f));
        normalPellet.setTexture(&texture);
        normalPellet.setPosition(sf::Vector2f(get<0>(foodItem),get<1>(foodItem)));
        window_.draw(normalPellet);


    }

}

void GameWindow::drawKeys()
{
    auto key=WholeMaze.MazeKeys();
    auto consumables=key.ReturnEntityVec();
    for(auto cons : consumables)
    {
        if(!texture.loadFromFile("Resources/key.png"))
        {
            break;
        }
        sf::RectangleShape Key(sf::Vector2f(21.f,27.f));
        Key.setTexture(&texture);
        Key.setPosition(sf::Vector2f(get<0>(cons),get<1>(cons)));
        window_.draw(Key);
    }


}

void GameWindow::drawPellets()
{
    auto pellet=WholeMaze.MazePellets();
    auto consumables=pellet.ReturnEntityVec();
    for(auto cons : consumables) ///deal with maze walls
    {
        switch(cons.PelletType)
        {


        case 's':
        {
            if(!texture.loadFromFile("Resources/SuperPellet.png"))
            {
                break;
            }
            sf::RectangleShape SuperPellet(sf::Vector2f(28.f,29.f));
            SuperPellet.setTexture(&texture);
            SuperPellet.setPosition(sf::Vector2f(cons.x_coord,cons.y_coord));
            window_.draw(SuperPellet);
            break;
        }

        case 'n':
        {
            if(!texture.loadFromFile("Resources/normalPellet.png"))
            {
                break;
            }
            sf::RectangleShape Food(sf::Vector2f(24.f,21.f));
            Food.setTexture(&texture);
            Food.setPosition(sf::Vector2f(cons.x_coord,cons.y_coord));
            window_.draw(Food);
            break;
        }

        default:
        {

            break;
        }


        }
    }
}

void GameWindow::drawEveryObject()
{
    drawMaze();
    drawDoors();
    drawPellets();
    drawFoods();
    drawKeys();
}

GameWindow::~GameWindow()
{

}
