#include "memory_functions_NNNN.h"

using namespace std;

// initMemory initializes the memory; at the outset of the game the grid of
// shots taken is empty, we've not hit any ships, and our player can only apply
// a general, somewhat random firing strategy until we get a hit on some ship
void initMemoryNNNN(ComputerMemory &memory) {
   memory.mode        =  RANDOM;
   memory.hitRow      = -1;
   memory.hitCol      = -1;
   memory.hitShip     =  NONE;
   memory.fireDir     =  NONE;
   memory.fireDist    =  1;
   memory.lastResult  =  NONE;

   for (int i = 0; i < BOARDSIZE; i++) {
      for (int j = 0; j < BOARDSIZE; j++) {
         memory.grid[i][j] = EMPTY_MARKER;
      }
   }
}

// complete this function so it produces a "smart" move based on the information
// which appears in the computer's memory
string smartMoveNNNN(const ComputerMemory &memory) {
   string move;

   return move;
}

// complete this function so it updates the computer's memory based on the
// result of the last shot at location (row, col)
void updateMemoryNNNN(int row, int col, int result, ComputerMemory &memory) {

}

