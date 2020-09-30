#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Orientation.h"
#include "ScreenModes.h"
#include "GameWindow.h"
#include "GameMaze.h"
#include "Ghost.h"
#include "PlayerCollisions.h"

using namespace sf;
using width_and_height = std::tuple<float, float>;

width_and_height setUpGhostSprite(Texture ghostTexture)
{
    auto [x_ghostTextureSize, y_ghostTextureSize] = ghostTexture.getSize();

    float Ghost_Width = x_ghostTextureSize /=Constants::GHOST_SPRITESHEET_COLS;
    float Ghost_Height = y_ghostTextureSize /=Constants::GHOST_SPRITESHEET_ROWS;

    return {Ghost_Width, Ghost_Height};
}

width_and_height setUpPacmanSprite(Texture pacmanTexture)
{
    //get the size of pacman texture
    auto [x_pacManTextureSize,y_pacManTextureSize]= pacmanTexture.getSize();

    //get the width and height of each Pac-Man figure to have
    //size of one Pac-Man figure
    float PacMan_Width = x_pacManTextureSize /= Constants::PACMMAN_SPRITESHEET_COLS;
    float PacMan_Height = y_pacManTextureSize /= Constants::PACMAN_SPRITESHEET_ROWS;

    return {PacMan_Width, PacMan_Height};
}

//This function rotates the sprite with respect to its current orientation
void setOrientation(Sprite& pacman, Orientation& orientation)
{
    switch(orientation)
    {

    case Orientation::FACE_LEFT:
        pacman.setRotation(180);
        break;
    case Orientation::FACE_RIGHT:
        pacman.setRotation(0);
        break;
    case Orientation::FACE_UP:
        pacman.setRotation(270);
        break;
    case Orientation::FACE_DOWN:
        pacman.setRotation(90);
        break;
    default:
        break;
    }
}

void updatePacmanSprite (Orientation orientation, Player& player, Sprite& pacman,PlayerCollisions& coll)
{
    player.setEntityMoveDirection(orientation);
    setOrientation(pacman, orientation);

    if(!coll.playerAndPellets(player)){ /// Returns true if they collide
     player.moveEntity();}

    player.isEntityInsideTheMaze();

    auto newPlayerPos = player.getEntityPosition();

    auto x_newPlayerPos = std::get<0>(newPlayerPos);
    auto y_newPlayerPos = std::get<1>(newPlayerPos);

    pacman.setPosition(x_newPlayerPos, y_newPlayerPos);
}

//This function moves the pacman around the screen
void pacmanMovement(Player& player, Sprite& pacman,PlayerCollisions& coll)
{
    if(Keyboard::isKeyPressed(Keyboard::Key::Up))
    {
        auto pacmanOrientation = Orientation::FACE_UP;
        updatePacmanSprite(pacmanOrientation, player, pacman,coll);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Key::Down))
    {
        auto pacmanOrientation = Orientation::FACE_DOWN;
        updatePacmanSprite(pacmanOrientation, player, pacman,coll);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Key::Right))
    {
        auto pacmanOrientation = Orientation::FACE_RIGHT;
        updatePacmanSprite(pacmanOrientation, player, pacman,coll);
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Left))
    {
        auto pacmanOrientation = Orientation::FACE_LEFT;
        updatePacmanSprite(pacmanOrientation, player, pacman,coll);

    }
}

int main()
{
    auto screenWidth = Constants::SCREEN_WIDTH;
    auto screenHeight = Constants::SCREEN_HEIGHT;

    auto screenMode = ScreenModes::SPLASH_SCREEN;


    //declaration of ghost objects
    auto Inky = Ghost{Constants::INKY_START_XPOS, Constants::INKY_START_YPOS};

    RenderWindow window(VideoMode(screenWidth, screenHeight), "Super Pac-Man");
    //window.setFramerateLimit(120);
    auto EntireMaze=GameMaze{};
    auto CurrentGame = GameWindow{window,EntireMaze};

    //declaration of the pacman object
    auto player = Player{Orientation::FACE_RIGHT};
    auto collisions = PlayerCollisions{};

    RectangleShape splashScreen(Vector2f(screenWidth, screenHeight));
    RectangleShape gameScreen(Vector2f(screenWidth, screenHeight));

    Texture splashScreenTexture;
    if(!splashScreenTexture.loadFromFile("Resources/SplashScreen.png")) {}
    splashScreen.setTexture(&splashScreenTexture);

    Texture pacmanTexture;
    if(!pacmanTexture.loadFromFile("Resources/pacman-spritesheet.png")) {}

    Texture ghostTexture;
    if(!ghostTexture.loadFromFile("Resources/Ghost-SpriteSheet.png")) {}

    auto [PacMan_Width, PacMan_Height] = setUpPacmanSprite(pacmanTexture);

    //get the uv co-ordinates of the texture
    //IntRect has x and y offset, also the pacman width and height (index start from 0)
    //we choose where we want to access our sprite sheet using uv co-ordinates
    IntRect rectPlayerSprite(PacMan_Width * 3, PacMan_Height * 0, PacMan_Width, PacMan_Height);
    Sprite pacman(pacmanTexture, rectPlayerSprite);

    pacman.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    pacman.setPosition(Constants::PLAYER_START_XPOS, Constants::PLAYER_START_YPOS);

    auto [ghost_Width, ghost_Height] = setUpGhostSprite(ghostTexture);

    //setting up the ghosts sprites
    IntRect rectInkySprite(ghost_Width * 1, ghost_Height * 1, ghost_Width, ghost_Height); //accessing Inky sprite
    Sprite inkySprite(ghostTexture, rectInkySprite);

    IntRect rectBlinkySprite(ghost_Width * 0, ghost_Height * 0, ghost_Width, ghost_Height); //accessing Blinky sprite
    Sprite blinkySprite(ghostTexture, rectBlinkySprite);

    IntRect rectPinkySprite(ghost_Width * 1, ghost_Height * 0, ghost_Width, ghost_Height); //accessing Pinky sprite
    Sprite pinkySprite(ghostTexture, rectPinkySprite);

    IntRect rectClydeSprite(ghost_Width * 0, ghost_Height * 1, ghost_Width, ghost_Height); //accessing Clyde sprite
    Sprite clydeSprite(ghostTexture, rectClydeSprite);

    //setting up the initial positions of the ghosts
    inkySprite.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    inkySprite.setPosition(Constants::INKY_START_XPOS, Constants::INKY_START_YPOS);

    blinkySprite.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    blinkySprite.setPosition(Constants::BLINKY_START_XPOS, Constants::BLINKY_START_YPOS);

    pinkySprite.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    pinkySprite.setPosition(Constants::PINKY_START_XPOS, Constants::PINKY_START_YPOS);

    clydeSprite.setOrigin(Constants::MOVING_OBJECT_X_ORIGIN, Constants::MOVING_OBJECT_Y_ORIGIN);
    clydeSprite.setPosition(Constants::CLYDE_START_XPOS, Constants::CLYDE_START_YPOS);

    Clock clock; //for animation

    while(window.isOpen())
    {
        Event evnt;
        window.clear();

        while(window.pollEvent(evnt))
        {
            if(evnt.type == evnt.Closed)
                window.close();
            else if(evnt.type == Event::KeyPressed)
            {
                if(screenMode == ScreenModes::SPLASH_SCREEN && Keyboard::isKeyPressed(Keyboard::Enter))
                    screenMode = ScreenModes::PLAY_SCREEN;
            }
        }

        if (screenMode == ScreenModes::SPLASH_SCREEN)
        {
            window.clear(Color::Black);
            window.draw(splashScreen);
        }
        else if (screenMode == ScreenModes::PLAY_SCREEN)
        {
            window.clear(Color::Black);
            CurrentGame.drawEveryObject();

            //animation
            if(clock.getElapsedTime().asSeconds() > Constants::REFRESH_FRAME_RATE)
            {
                if(rectPlayerSprite.left == (PacMan_Width * 4))
                    rectPlayerSprite.left = (PacMan_Width * 3);
                else
                    rectPlayerSprite.left += PacMan_Width;

                pacman.setTextureRect(rectPlayerSprite);
                clock.restart();
            }

            window.draw(pacman);
            window.draw(inkySprite);
            window.draw(pinkySprite);
            window.draw(blinkySprite);
            window.draw(clydeSprite);
            pacmanMovement(player, pacman,collisions);


        }

        window.display(); //displaying the pacman to the screen
    }

    return 0;
}

