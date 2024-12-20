// Author:  Keith Shomper
// Date:    24 Oct 03
// Purpose: Programming Assignment #10 - Smart Battleship assignment

#include "battleship.h"
#include "memory.h"                     
#include "memory_functions_chitwoo.h"

int main() {
   Board          dumbComputerBoard, smartComputerBoard;
   ComputerMemory smartComputerMemory;  

   bool           done = false;
   string         message;
   string         dumbComputerMove, smartComputerMove;
   int            numDumbComputerShipsSunk = 0;
   int            numSmartComputerShipsSunk = 0;
   int            dumbComputerRow,  dumbComputerColumn;
   int            smartComputerRow, smartComputerColumn;
   int            checkValue, dumbComputerResult, smartComputerResult;

   // Welcome the player to the game
   welcome(false);

   // Initialize the game boards
   initializeBoard(dumbComputerBoard);
   initializeBoard(smartComputerBoard);
   initMemoryChitwoo (smartComputerMemory);

   // Play the game until one player has sunk the other's ships
   while (!done) {

      // blank the screen to show the game situation
      clearTheScreen();

      // Display game situation (use HUMAN so we can see where the ships are)
      displayBoard(1,  5, HUMAN, dumbComputerBoard);
      displayBoard(1, 40, HUMAN, smartComputerBoard);

      // get the dumb computer's move -- it's always a random move
      dumbComputerMove  = randomMove();
      checkValue = checkMove(dumbComputerMove, smartComputerBoard, 
	                     dumbComputerRow,  dumbComputerColumn);

		// validate the move
      while (checkValue != VALID_MOVE) {
         if (checkValue == ILLEGAL_FORMAT) {
            ; // this case will not occur with a random move
         } else if (checkValue == REUSED_MOVE) {
            ; // this case may occur, if it does, just get another move
         } 

	 // if necessary, get another move
         dumbComputerMove  = randomMove();
         checkValue = checkMove(dumbComputerMove, smartComputerBoard, 
                                dumbComputerRow,  dumbComputerColumn);
      }

      // get the smartComputer's move
      smartComputerMove = smartMoveChitwoo(smartComputerMemory);       

      while (checkMove(smartComputerMove, dumbComputerBoard, 
                       smartComputerRow,  smartComputerColumn) != VALID_MOVE) {

         // if smartMove() returns an invalid move, take a random move instead
         smartComputerMove = randomMove();
      }

      // execute the moves on the respective boards
      dumbComputerResult  = playMove(dumbComputerRow,  dumbComputerColumn,
                                     smartComputerBoard);
      smartComputerResult = playMove(smartComputerRow, smartComputerColumn,
                                     dumbComputerBoard);
      updateMemoryChitwoo(smartComputerRow,    smartComputerColumn,  
                       smartComputerResult, smartComputerMemory); 

      // blank the screen to show the new game situation
      clearTheScreen();

      // Display the game situation
      displayBoard(1,  5, HUMAN, dumbComputerBoard);
      displayBoard(1, 40, HUMAN, smartComputerBoard);

      // Display the move choices
      writeMessage(15, 0, "The dumb  computer chooses:  " + dumbComputerMove);
      writeMessage(16, 0, "The smart computer chooses:  " + smartComputerMove);

      // Show the results of the moves
      writeResult(18, 0, dumbComputerResult,  COMPUTER);
      writeResult(19, 0, smartComputerResult, HUMAN);

      // record any sunken ships
      if (isASunk(dumbComputerResult))  { numDumbComputerShipsSunk++; }
      if (isASunk(smartComputerResult)) { numSmartComputerShipsSunk++; }

      // determine if we have a winner
      if (numDumbComputerShipsSunk == 5 || numSmartComputerShipsSunk == 5) {
         done = true;
      } else {
         // pause to let the user assess the situation
         pauseForEnter();
      }
   }

   // Display the game situation once more, showing where each player's ships
   // are located
   displayBoard(1,  5, HUMAN, dumbComputerBoard);
   displayBoard(1, 40, HUMAN, smartComputerBoard);

   // Announce the winner
   if (numDumbComputerShipsSunk == 5 && numSmartComputerShipsSunk == 5) {
      writeMessage(21, 1, "The game is a tie.");
   } else if (numDumbComputerShipsSunk == 5) {
      writeMessage(21, 1, "Amazing, the dumb computer won.");
   } else {
      writeMessage(21, 1, "You won!!!  As you should have.");
   }

   // pause to let the result of the game sink in
   pauseForEnter();
   clearTheScreen();

   return 0;
}
