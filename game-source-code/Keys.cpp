#include "Keys.h"
#include <fstream>
#include "Constants.h"

Keys::Keys()
{
  ReadEntityFromFile();
}
void Keys::ReadEntityFromFile()
{
    float x;
    float y;


    std::ifstream inputFile;
    inputFile.open("Resources/keys.txt");
    if (!inputFile) {
    std::cerr << "File could not be opened";}

    while(inputFile>>x>>y)
    {
       auto CurrentKeyPosition= std::make_tuple(x+Constants::MAZE_X_OFFSET,y+Constants::MAZE_Y_OFFSET);
        KeyVec.push_back(CurrentKeyPosition);
    }
inputFile.close();
}

std::vector<x_and_y> Keys::ReturnEntityVec()const
{
    return KeyVec;
}


std::vector<x_and_y> Keys::HitBox() const
{
  return KeyVec;
}

void Keys::DestroyEntity()
{

}

Keys::~Keys()
{

}
