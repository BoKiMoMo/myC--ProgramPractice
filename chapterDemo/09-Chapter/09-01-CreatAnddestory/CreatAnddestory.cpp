#include "CreatAnddestory.h"
#include <iostream>

using namespace std;

CreateAndDestroy::CreateAndDestroy(int ID, string messageString)
    : objectID(ID), message(messageString)
{
    cout << "Object " << objectID << "   constructor runs   "
        << message << endl;
}

CreateAndDestroy::~CreateAndDestroy()
{
    cout << (objectID == 1 || objectID == 6 ? "\n" : "");

    cout << "Object " << objectID << "   destructor runs    "
        << message << endl;
}