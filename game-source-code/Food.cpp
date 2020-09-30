#include "Food.h"
#include "Constants.h"
#include <fstream>

Food::Food()
{
   ReadEntityFromFile();

}
void Food::ReadEntityFromFile()
{
    float x;
    float y;


    std::ifstream inputFile;
    inputFile.open("Resources/foods.txt");
    if (!inputFile) {
    std::cerr << "File could not be opened";}

    while(inputFile>>x>>y)
    {
        auto CurrentCoordinates=std::make_tuple(x+Constants::MAZE_X_OFFSET,y+Constants::MAZE_Y_OFFSET);
        Foods.push_back(CurrentCoordinates);
    }
inputFile.close();
}


std::vector<x_and_y> Food::ReturnEntityVec() const
{
    return Foods;
}


std::vector<x_and_y> Food::HitBox() const
{
  return Foods;
}

void Food::DestroyEntity()
{

}

Food::~Food()
{
    //dtor
}
