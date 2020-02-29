#include "engine.h"

// stdlib
#include <fstream>
#include <iostream>
#include <random>
// local
#include "Object.h"
#include "GUI.h"

int
loadBlockData (
    const std::string& p_gameFile,
    Object p_objects[],
    const GUI& p_gui
) {
    std::ifstream inFile;
    inFile.open("p_gameFile");
    int x{ NULL };
    while (inFile >> x && !inFile.eof()) {
        if (!inFile) {
            std::cerr << "Unable to open file at " << p_gameFile;
            exit(1);
        }
        for (int i{ 0 }; i <= 21; i++) {
            for (int j{ 0 }; j <= 13; j++) {
                p_objects[x].position = { i, j };
                switch (x) {
                case 0:
                    p_objects[x].type = Type::none;
                    break;
                case 1:
                    p_objects[x].type = Type::block;
                    break;
                case 2:
                    p_objects[x].type = Type::belowBlock;
                    break;
                case 3:
                    p_objects[x].type = Type::belowBlock2;
                    break;
                case 4:
                    p_objects[x].type = Type::wall1;
                    break;
                case 5:
                    p_objects[x].type = Type::wall2;
                    break;
                case 6:
                    p_objects[x].type = Type::waterSurface;
                    break;
                case 7:
                    p_objects[x].type = Type::water;
                    break;
                case 8:
                    p_objects[x].type = Type::player;
                    break;
                case 9:
                    p_objects[x].type = Type::numTypes;
                    break;
                }
            }
        }
    }
    inFile.close();
    return x;
    /*
        -- loadBlockData   --
        Parameters:
            p_gameFile : A string representing the location of the game data file
            p_objects  : An array of default-constructed objects, each element
                         needs to be updated to with the correct information from
                         the data file
            p_gui      : A reference to the GUI Object if you need it

        Return: the number of objects read from the data file

        loadBlockData will read the p_gameFile and update the objects in
        p_objects with the appropriate data.
    */
}

void
randomPlayerData (
    const int p_numObjects,
    Object p_objects[],
    const GUI & p_gui
) {
    std::random_device rdev;
    std::default_random_engine e(rdev());
    std::uniform_int_distribution<int> d(0, 21);
    p_objects[8].spriteID = d(e);
    p_objects[8].position.x = d(e);
    /*
        -- randomPlayerData   --
        Parameters:
            p_numObjects : The total number of objects in p_objects
            p_objects    : An array of almost all fully-constructed objects
            p_gui      : A reference to the GUI Object if you need it

        This function needs to modify the player object and assign them random values.
        Player
            xPosition needs to be random
            spriteID needs to be random
            yPosition needs to be physically correct
                The player cannot be in the air for instance
                The player cannot be underground
    */
}

int
getMaxYOfBlock (
    const Object& player,
    const Object objects[],
    int numObjects
) {
    /*
        -- getMaxYOfBlock --
        Parameters
            player  - A read-only reference to the player object
            objects - A list of read-only objects
            numObjects - The number of objects

        Return: The height that the player needs to be at to be physically accurate
    */

    return 0; // placeholder
}
