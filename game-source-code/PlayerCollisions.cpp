#include "PlayerCollisions.h"


PlayerCollisions::PlayerCollisions()
{

}
bool PlayerCollisions::DoPlayerAndWallsCollide(Player& currentPlayer)
{
    auto mazeWalls=AllObjects_.mazeWalls();
    auto WallVec=mazeWalls.HitBox();
    float wall=10;
    BoundingBox MazeWallBox;
    auto CurrentBox = currentPlayer.HitBox();

    for(auto WallBox : WallVec)
    {

        MazeWallBox.xTopLeft=WallBox.x_coord;
        MazeWallBox.yTopLeft=WallBox.y_coord;

        if(WallBox.Orientation=='h')
        {
            MazeWallBox.BoxLength=WallBox.length;
            MazeWallBox.BoxHeight=wall;
            bool result=Intersects(CurrentBox,MazeWallBox);
            std::cout<<MazeWallBox.xTopLeft<<" "<<MazeWallBox.yTopLeft<<"\n";
            std::cout<<CurrentBox.xTopLeft<<" "<<CurrentBox.yTopLeft<<"\n";
            if(result)
            {
                return result;
            }

        }
        if(WallBox.Orientation=='v')
        {

            MazeWallBox.BoxLength=wall;
            MazeWallBox.BoxHeight=WallBox.length;
            bool result=Intersects(CurrentBox,MazeWallBox);
            if(result)
            {
                return result;
            }

        }


    }
    return false; // all else has failed
}

bool PlayerCollisions::playerAndDoors(Player& currentPlayer)
{
    auto mazeDoors=AllObjects_.mazeDoors();
    auto DoorVec= mazeDoors.HitBox();
    auto CurrentBox = currentPlayer.HitBox();
    float height=5;
    float width=37;
    BoundingBox doorBox;

    for(auto door : DoorVec)
    {
        doorBox.xTopLeft=door.x_coord;
        doorBox.yTopLeft=door.y_coord;

        if(door.orientation=='h')
        {
            doorBox.BoxLength=width;
            doorBox.BoxHeight=height;
            bool result=Intersects(CurrentBox,doorBox);
            std::cout<<doorBox.xTopLeft<<" "<<doorBox.yTopLeft<<"\n";
            std::cout<<CurrentBox.xTopLeft<<" "<<CurrentBox.yTopLeft<<"\n";
            if(result)
            {
                return result;
            }

        }
        if(door.orientation=='v')
        {

            doorBox.BoxLength=height;
            doorBox.BoxHeight=width;
            bool result=Intersects(CurrentBox,doorBox);
            std::cout<<doorBox.xTopLeft<<" "<<doorBox.yTopLeft<<"\n";
            std::cout<<CurrentBox.xTopLeft<<" "<<CurrentBox.yTopLeft<<"\n";
            if(result)
            {
                return result;
            }
        }
    }
    return false; // all else has failed

}

bool PlayerCollisions::playerVsFood(Player& currentPlayer)
{
    auto mazeFoods=AllObjects_.MazeFoods();
    auto FoodBoxes= mazeFoods.HitBox();
    auto CurrentBox = currentPlayer.HitBox();
    float height=27;
    float width=25;

    BoundingBox FoodBox;
    FoodBox.BoxLength=width;
    FoodBox.BoxHeight=height;

    for(auto food : FoodBoxes)
    {
        FoodBox.xTopLeft=std::get<0>(food);
        FoodBox.yTopLeft=std::get<1>(food);

        bool result=Intersects(CurrentBox,FoodBox);
        std::cout<<FoodBox.xTopLeft<<" "<<FoodBox.yTopLeft<<"\n";
        std::cout<<CurrentBox.xTopLeft<<" "<<CurrentBox.yTopLeft<<"\n";
        if(result)
        {
            return result;
        }
    }

    return false; // all else has failed
}

bool PlayerCollisions::playerAndKeys(Player& currentPlayer)
{
    auto mazeKeys=AllObjects_.MazeKeys();
    auto KeyVec= mazeKeys.HitBox();
    auto CurrentBox = currentPlayer.HitBox();
    float height=27;
    float width=21;
    BoundingBox keyBox;

    for(auto key : KeyVec)
    {

        keyBox.xTopLeft=std::get<0>(key);
        keyBox.yTopLeft=std::get<1>(key);


            keyBox.BoxLength=width;
            keyBox.BoxHeight=height;
            bool result=Intersects(CurrentBox,keyBox);
            std::cout<<keyBox.xTopLeft<<" "<<keyBox.yTopLeft<<"\n";
            std::cout<<CurrentBox.xTopLeft<<" "<<CurrentBox.yTopLeft<<"\n";
            if(result)
            {
                return result;
            }

    }
    return false; // all else has failed
}


bool PlayerCollisions::playerAndPellets(Player& currentPlayer)
{
    auto mazePellet=AllObjects_.MazePellets();
    auto pelletVec= mazePellet.HitBox();
    auto CurrentBox = currentPlayer.HitBox();
    float  superPelletLength=28;
    float superPelletHeight=29;
    float  normalPelletLength=24;
    float normalPelletHeight=21;
    BoundingBox pelletBox;

    for(auto pellet : pelletVec)
    {


        if(pellet.PelletType=='n')
        {
            pelletBox.xTopLeft=pellet.x_coord;
            pelletBox.yTopLeft=pellet.y_coord;
            pelletBox.BoxLength=normalPelletLength;
            pelletBox.BoxHeight=normalPelletHeight;

            bool result=Intersects(CurrentBox,pelletBox);
            //std::cout<<pelletBox.xTopLeft<<" "<<pelletBox.yTopLeft<<"\n";
            std::cout<<CurrentBox.xTopLeft<<" "<<CurrentBox.yTopLeft<<"\n";
            if(result)
            {
                return result;
            }

        }
        if(pellet.PelletType=='s')
        {

            pelletBox.xTopLeft=pellet.x_coord;
            pelletBox.yTopLeft=pellet.y_coord;
            pelletBox.BoxLength=superPelletLength;
            pelletBox.BoxHeight=superPelletHeight;
            bool result=Intersects(CurrentBox,pelletBox);
            //std::cout<<pelletBox.xTopLeft<<" "<<pelletBox.yTopLeft<<"\n";
            std::cout<<CurrentBox.xTopLeft<<" "<<CurrentBox.yTopLeft<<"\n";
            if(result)
            {
                return result;
            }
        }
    }
    return false;

}

bool PlayerCollisions::Intersects(BoundingBox& Box1,BoundingBox& Box2) ///collision between bounding boxes, works fine
{
    if((Box1.xTopLeft<=(Box2.xTopLeft+Box2.BoxLength)) && ((Box1.xTopLeft+Box1.BoxLength)>=Box2.xTopLeft) &&
            (Box1.yTopLeft<=(Box2.yTopLeft+Box2.BoxHeight)) && ((Box1.yTopLeft+Box1.BoxHeight)>=Box2.yTopLeft))
    {
        std::cout<<"Inside";
        return true;
    }
    return false;
}
PlayerCollisions::~PlayerCollisions()
{
    //dtor
}
