// this grogram is a game of tic-Tac-Toe
//==================================================================================================================
#include <iostream>
using namespace std;
// input: two chars that represent the location in wich the player wants to place his move.
// output: the gameboard and a message that indicate if the move played is legal and whether there is a winner.

// this data structure allow to store three chars, two for a location on the board and one to store x o or space.
struct BOX {
	char row;
	char coll;
	char play;
};
typedef struct BOX BOX;

// this data structure allow to store nine chars to store x o or space to be printed on the screen as the board.
struct BOARD {
	char b1;
	char b2;
	char b3;
	char b4;
	char b5;
	char b6;
	char b7;
	char b8;
	char b9;
};
typedef struct BOARD BOARD;

void printBoard(BOARD board);
BOX getNextMove(BOARD board, char turn);
BOARD installMove(BOX nextMove, BOARD board);
bool isValid(BOX nextMove);
bool isTaken(BOARD board, BOX move);
int isOver(BOARD board);

// in the main I set the BOX and BOARD data sctructures to the defult. next, in a loop we call for the getNextMove
// function install the move to the board with the installMove function, change the players turn,
//  and check whether or not the game is finished and print a message accordingly.
int main() {
	BOX b1 = { '1','A',' ' }, b2 = { '1','B',' ' }, b3 = { '1','C',' ' };
	BOX b4 = { '2','A',' ' }, b5 = { '2','B ',' ' };
	BOX b6 = { '2','C',' ' }, b7 = { '3','A',' ' }, b8 = { '3','B',' ' }, b9 = { '3','C',' ' };
	BOX nextMove;
	BOARD board = { b1.play,b2.play,b3.play,b4.play,b5.play,b6.play,b7.play,b8.play,b9.play};
	int counter=0, endGame = 0;
	char turn= 'X';

	printBoard(board);

	while (endGame == 0 && counter < 9) {
		nextMove = getNextMove(board, turn);
		board= installMove(nextMove, board);
		
		if (turn == 'X')
		turn = 'O';
		else
		turn = 'X';

		endGame = isOver(board);
		printBoard(board);

		if (endGame == 1)
			cout << "the first player won!!!" << endl;
		if (endGame == 2)
			cout << "the second player won!!!" << endl;
		if (counter == 8 && endGame == 0) {
			cout << endl <<  "its a draw!!" << endl;
		}
		counter++;
	}
}

// this function prints the gameboard with the chars that are store in the BOARD data structure.
void printBoard(BOARD board) {
	cout << "     A   B   C" << "\n \n" << "1    "<< board.b1 << "   " << board.b2 << "   " << board.b3 << "\n \n";
	cout << "2    " << board.b4 << "   " << board.b5 << "   " << board.b6 << "\n \n";
	cout << "3    " <<  board.b7 << "   " << board.b8 << "   " << board.b9 << endl << endl;
}

// this function ask the user to enter two chars that indicate his next play, than the function call for another 
// function isValid to check if the move is legal and isTaken to check that the location on the board is empty.
// if there is a problem with the play the program will say so and ask for a do over and if the play is good it will store the dats.
BOX getNextMove(BOARD board, char turn) {
	BOX move;
	bool legal = false, taken = false;

	cout << "please enter a valid move (example: A2)" << endl;
	while (legal == false || taken == false) {
		
		 cin >> move.coll;
		cin >> move.row;
		legal = isValid(move);
		taken = isTaken(board, move);

		if (!legal ||!taken) {
			printBoard(board);
			
			if (!legal)
			cout << "not a valid move, please try again (example: A2)" << endl;
			
			if (!taken)
				cout << "this box is taken, please choose another one" << endl;
			cin.ignore();
		}
	}
	move.play = turn;
	return move;
}

// this function checks if the move is legal by checking if the user enter A or B oe C for the columns and 1 or 2 or 3 for the rows.
	bool isValid(BOX move){
		if (move.coll == 'A' || move.coll == 'B' || move.coll == 'C') {
			if (move.row == '1' || move.row == '2' || move.row == '3') {
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}

// this function checks if the location the user chose is empty by checking if ther either x or o in the BOARD char.
	bool isTaken(BOARD board, BOX move) {
		if (move.coll == 'A') {

			if (move.row == '1') {
				if (board.b1 == 'X' || board.b1 == 'O') {
					return false;
				}
			}
			else if (move.row == '2') {
				if (board.b4 == 'X' || board.b4 == 'O') {
					return false;
				}
			}
			else if (move.row == '3') {
				if (board.b7 == 'X' || board.b7 == 'O') {
					return false;
				}
			}
		}

		else if (move.coll == 'B') {

			if (move.row == '1') {
				if (board.b2 == 'X' || board.b2 == 'O') {
					return false;
				}
			}
			else if (move.row == '2') {
				if (board.b5 == 'X' || board.b5 == 'O') {
					return false;
				}
			}
			else if (move.row == '3') {
				if (board.b8 == 'X' || board.b8 == 'O') {
					return false;
				}
			}
		}

		else if (move.coll == 'C') {

			if (move.row == '1') {
				if (board.b3 == 'X' || board.b3 == 'O') {
					return false;
				}
			}
			else if (move.row == '2') {
				if (board.b6 == 'X' || board.b6 == 'O') {
					return false;
				}
			}
			else if (move.row == '3') {
				if (board.b9 == 'X' || board.b9 == 'O') {
					return false;
				}
			}
		}
		else
			return true;
	}

// this function install the turn x or o to the box the player chose on the board.
	BOARD installMove(BOX nextMove, BOARD board) {
		if (nextMove.coll == 'A') {
			if (nextMove.row == '1') {
				board.b1 = nextMove.play;
			}
			else if (nextMove.row == '2') {
				board.b4 = nextMove.play;
			}
			else if (nextMove.row == '3') {
				board.b7 = nextMove.play;
			}
		}

		else if (nextMove.coll == 'B') {
			if (nextMove.row == '1') {
				board.b2 = nextMove.play;
			}
			else if (nextMove.row == '2') {
				board.b5 = nextMove.play;
			}
			else if (nextMove.row == '3') {
				board.b8 = nextMove.play;
			}
		}

		if (nextMove.coll == 'C') {
			if (nextMove.row == '1') {
				board.b3 = nextMove.play;
			}
			else if (nextMove.row == '2') {
				board.b6 = nextMove.play;
			}
			else if (nextMove.row == '3') {
				board.b9 = nextMove.play;
			}
		}
		return board;
	}

// this function check whether or not one of the players won the game.
	int isOver(BOARD board) {
		if (board.b1 == 'X' && board.b4 == 'X' && board.b7 == 'X')
			return 1;
		else if (board.b2 == 'X' && board.b5 == 'X' && board.b8 == 'X')
			return 1;
		else if (board.b3 == 'X' && board.b6 == 'X' && board.b9 == 'X')
			return 1;
		else if (board.b1 == 'X' && board.b2 == 'X' && board.b3 == 'X')
			return 1;
		else if (board.b4 == 'X' && board.b5 == 'X' && board.b6 == 'X')
			return 1;
		else if (board.b7 == 'X' && board.b8 == 'X' && board.b9 == 'X')
			return 1;
		else if (board.b1 == 'X' && board.b5 == 'X' && board.b9 == 'X')
			return 1;
		else if (board.b3 == 'X' && board.b5 == 'X' && board.b7 == 'X')
			return 1;

		else if (board.b1 == 'O' && board.b4 == 'O' && board.b7 == 'O')
			return 2;
		else if (board.b2 == 'O' && board.b5 == 'O' && board.b8 == 'O')
			return 2;
		else if (board.b3 == 'O' && board.b6 == 'O' && board.b9 == 'O')
			return 2;
		else if (board.b1 == 'O' && board.b2 == 'O' && board.b3 == 'O')
			return 2;
		else if (board.b4 == 'O' && board.b5 == 'O' && board.b6 == 'O')
			return 2;
		else if (board.b7 == 'O' && board.b8 == 'O' && board.b9 == 'O')
			return 2;
		else if (board.b1 == 'O' && board.b5 == 'O' && board.b9 == 'O')
			return 2;
		else if (board.b3 == 'O' && board.b5 == 'O' && board.b7 == 'O')
			return 2;
		else
			return 0;
	}
