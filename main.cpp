#include <iostream>
#include <string>  
#include <stdio.h>
#include <stdlib.h>    
#include <time.h> 
#include "functions.cpp"
#include "board.h"

char main_board[27];
using namespace std;

int main() {

	//setup board
	for (int i=0; i<27; i++) {
		main_board[i] = 'n';
	}

	bool done = false;

	greetAndInstruct();

	cout << endl;

	while (!done) {

		displayBoard(main_board);

		if (checkWinner(main_board)) {
			cout << "Congratulations! There is a winner!" << endl;
			exit(0);
		}

		cout << "Please enter a number between 1 and 27: ";
		string user_in;
		cin >> user_in;

		int user_int = stoi(user_in);

		if (!(checkIfLegal(user_int, main_board))) continue;

		main_board[user_int - 1] = 'x';

		computerMove(main_board);

	}

	return 0;
}