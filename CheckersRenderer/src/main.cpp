#include <iostream>

#include <iostream>
#include "Board.h"

int main(int argc, char** argv) 
{
    Board b;
    bool isJump;
    std::cout << "Is valid move: " << b.IsValidMove(2, 2, 0, 0, isJump) << std::endl;
    
    return 0;
}