#include <iostream>
#include<string>  
#include <stdio.h>
#include <stdlib.h>    
#include <time.h>  

using namespace std;



//simple string concat function 
string makeLine(string a, string b, string c) {
	string result = "  " + a + "  |  " + b + "  |  " + c;
	return result;
}

void greetAndInstruct() {

	string line1 = "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer.";
	string line2 = "The board is numbered from 1 to 27 as per the following:";
	string line3 = "Player starts first. Simply input the number of the cell you want to occupy.";
	string line4 = "Player's move is marked with X. Computer's move is marked with O.";
	string line5 = "Start? (y/n): ";

	string a = makeLine("1 ", "2 ", "3 ");
	string b = makeLine("4 ", "5 ", "6 ");
	string c = makeLine("7 ", "8 ", "9 ");

	string d = makeLine("10", "11", "12");
	string e = makeLine("13", "14", "15");
	string f = makeLine("16", "17", "18");
 
 	string g = makeLine("19", "20", "21");
	string h = makeLine("22", "23", "24");
	string i = makeLine("25", "26", "27");

	string sep =    "-------------";
	string sep_bl = "              ";


	cout << line1 << endl << line2 << endl << endl;

	/*cout << a << endl << sep << endl << b << endl << sep << endl << c;*/

	cout << a << sep_bl << d << sep_bl << g << endl;
	cout << sep << sep_bl << sep << sep_bl << sep << endl;
	cout << b << sep_bl << e << sep_bl << h << endl;
	cout << sep << sep_bl << sep << sep_bl << sep << endl;
	cout << c << sep_bl << f << sep_bl << i << endl << endl;

	cout << line3 << endl << line4 << endl << endl << line5;

	string user_in;
	cin >> user_in;

	if (user_in.compare("y") == 0) {
		 
	}
	else {
		exit(0);
	}
}

string checkChar(char c, int pos) {

	string ret;
	if (c == 'n') {
		return to_string(pos + 1);
	}
	else if (c == 'o') {
		return "o";
	}
	else if (c == 'x') {
		return "x";
	}
	else {
		return "Fail"; 
	}

}

void displayBoard(char board[]) {

	string sep =    " ---------------";
	string sep_bl = "                ";
	string a, b, c, d, e, f, g, h, i1;

	//check for n, o and x
	for (int i=0; i< 9; i++) {

		int curr = i * 3;
		
		//get all of the chars for a row
		char a1 = board[curr];
		char b1 = board[curr + 1];
		char c1 = board[curr + 2];

		string r_1 = checkChar(a1, curr);
		string r_2 = checkChar(b1, (curr+1));
		string r_3 = checkChar(c1, (curr+2));

		string l1 = makeLine(r_1, r_2, r_3);
		if (i == 0) {
			a = l1;
		}
		else if (i == 1) {
			b = l1;
		}
		else if (i == 2) {
			c = l1;
		}
		else if (i == 3) {
			d = l1;
		}
		else if (i == 4) {
			e = l1;
		}
		else if (i == 5) {
			f = l1;
		}
		else if (i == 6) {
			g = l1;
		}
		else if (i == 7) {
			h = l1;
		}
		else if (i == 8) {
			i1 = l1;
		}
		else {}
	}

	cout << a << sep_bl << d << sep_bl << g << endl;

	cout << sep << sep_bl << sep << sep_bl << sep << endl;

	cout << b << sep_bl << e << sep_bl << h << endl;

	cout << sep << sep_bl << sep << sep_bl << sep << endl;

	cout << c << sep_bl << f << sep_bl << i1 << endl << endl;

}

bool stringContains(string src, string t) {

	int pos = src.find(t);

	if (pos < 10 && pos > 0) return true;
	else return false;

}

//check the flattened board given the board and the player being checked 
bool checkBoard(string board[], string player) {

	if (stringContains(board[0], player) && stringContains(board[1], player) && stringContains(board[2], player)) {
		
		return true;
	}

	else if (stringContains(board[3], player) && stringContains(board[4], player) && stringContains(board[5], player)) {
		
		return true;
	}

	else if (stringContains(board[6], player) && stringContains(board[7], player) && stringContains(board[8], player)) {
		
		return true;
	}

	else if (stringContains(board[0], player) && stringContains(board[3], player) && stringContains(board[6], player)) {
		
		return true;
	}

	else if (stringContains(board[1], player) && stringContains(board[4], player) && stringContains(board[7], player)) {
		
		return true;
	}

	else if (stringContains(board[2], player) && stringContains(board[5], player) && stringContains(board[8], player)) {
		
		return true;
	}

	else if (stringContains(board[0], player) && stringContains(board[4], player) && stringContains(board[8], player)) {
		
		return true;
	}

	else if (stringContains(board[2], player) && stringContains(board[4], player) && stringContains(board[6], player)) {
		
		return true;
	}

	else {
		return false;
	}

}

//function to check for a tie
bool checkTie(char board[]) {

	//go thru all 27 cells and try to find one 'n' char, this being an unused slot. 
	
	for (int i=0; i<27; i++) {
		if (board[i] == 'n') return false;
	}

	return true;

}


//flatten the 3 boards and check for the 8 poss. overlaps 
bool checkWinner(char board[]) {

	//if we find a tie, kill the program.
	if (checkTie(board)) {
		cout << "There has been a tie! The Game is Over." << endl;
		exit(0);
	}

	string fboard[9];

	//initialize fboard - this being a flattened version of all 3 boards
	for (int j=0; j < 9; j++) {
		fboard[j] = "-";
	}

	for (int i=0; i<27; i++) {

		char c = board[i];

		if (c == 'o') {

			string o = fboard[i % 9] + "o";
			fboard[i % 9] = o;
		}
		if (c == 'x') {

			string x = fboard[i % 9] + "x";
			fboard[i % 9] = x;
		}
	}

	bool res = checkBoard(fboard, "x");
	bool res2 = checkBoard(fboard, "o");

	cout << "x: " << res << endl;
	cout << "o: " << res2 << endl;


	return res;


}


//input a number 1-9, find which spot 1-27 
int findMove(char board[], int pos) {

	int board2 = pos + 9;
	int board3 = pos + 18;

	if (board[pos] == 'n') {
		return pos;
	}
	else if (board[board2] == 'n') {
		return board2;
	}
	else if (board[board3] == 'n') {
		return board3;
	}
	else {
		return -1;
	}



}


bool checkIfLegal(int cNbre, char board[]) {

	if (cNbre < 1 || cNbre > 27) {
		cout << "This number is not within the acceptable range. Please input a number between 1 and 27 (inclusive)." << endl;
		return false;
	}
	else if (board[cNbre - 1] != 'n') {

		cout << "This space is already occupied. Please input a number between 1 and 27 (inclusive)." << endl;
		return false;
	}
	else {
		return true;
	}
	return false;
	
}

//First, check if the computer has two lined up, then if the player has two.

//find if there are two checked boxes in a row
int checkTwo(string board[], string player, char ogboard[]) {

	if (stringContains(board[0], player) && stringContains(board[1], player)) {
		
		int pos = findMove(ogboard, 2);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[1], player) && stringContains(board[2], player)) {
		
		int pos = findMove(ogboard,0);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[0], player) && stringContains(board[2], player)) {
		
		int pos = findMove(ogboard,1);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[0], player) && stringContains(board[3], player)) {
		
		int pos = findMove(ogboard,6);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[3], player) && stringContains(board[6], player)) {
		
		int pos = findMove(ogboard,0);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[0], player) && stringContains(board[6], player)) {
		
		int pos = findMove(ogboard,3);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[2], player) && stringContains(board[5], player)) {
		
		int pos = findMove(ogboard,8);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[5], player) && stringContains(board[8], player)) {
		
		int pos = findMove(ogboard,2);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[2], player) && stringContains(board[8], player)) {
		
		int pos = findMove(ogboard,5);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[6], player) && stringContains(board[7], player)) {
		
		int pos = findMove(ogboard,8);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[7], player) && stringContains(board[8], player)) {
		
		int pos = findMove(ogboard,6);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[6], player) && stringContains(board[8], player)) {
		
		int pos = findMove(ogboard,7);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[4], player) && stringContains(board[5], player)) {
		
		int pos = findMove(ogboard,3);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[3], player) && stringContains(board[4], player)) {
		
		int pos = findMove(ogboard,5);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[3], player) && stringContains(board[5], player)) {
		
		int pos = findMove(ogboard,4);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[1], player) && stringContains(board[4], player)) {
		
		int pos = findMove(ogboard,7);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[4], player) && stringContains(board[7], player)) {
		
		int pos = findMove(ogboard,1);
		if (pos > 0) {
			return pos;
		}
	}
	if (stringContains(board[1], player) && stringContains(board[7], player)) {
		
		int pos = findMove(ogboard,4);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[0], player) && stringContains(board[4], player)) {
		
		int pos = findMove(ogboard,8);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[4], player) && stringContains(board[8], player)) {
		
		int pos = findMove(ogboard,0);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[0], player) && stringContains(board[8], player)) {
		
		int pos = findMove(ogboard,4);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[2], player) && stringContains(board[4], player)) {
		
		int pos = findMove(ogboard,6);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[4], player) && stringContains(board[6], player)) {
		
		int pos = findMove(ogboard,2);
		if (pos > 0) {
			return pos;
		}
	}

	if (stringContains(board[2], player) && stringContains(board[6], player)) {
		
		int pos = findMove(ogboard,4);
		if (pos > 0) {
			return pos;
		}
	}

	return -1;
}



void computerMove(char board[]) {

	string fboard[9];

	//initialize fboard - this being a flattened version of all 3 boards
	for (int j=0; j < 9; j++) {
		fboard[j] = "-";
	}

	for (int i=0; i<27; i++) {

		char c = board[i];

		if (c == 'o') {

			string o = fboard[i % 9] + "o";
			fboard[i % 9] = o;
		}
		if (c == 'x') {

			string x = fboard[i % 9] + "x";
			fboard[i % 9] = x;
		}
	}

	int move = checkTwo(fboard, "x", board);
	
	int move2 = checkTwo(fboard, "o", board);

	if (move < 0) {
	
	
		//do move
	
	
	}	
	else if(move2 < 0) {



	}
	else {

		int pos = getRand(board);

	}

  	


	

}

int getRand(char board[]) {

	bool found = false;
	int r;

	while (!found) {

		srand (time(NULL));

		/* generate random number between 0 and 27: */
		r = rand() % 28;

		if (board[r] == 'n') found = true;

	}

	return r;
}

int main() {

	//setup board
	char board[27];
	for (int i=0; i<27; i++) {
		board[i] = 'n';
	}

	board[0] = 'x';
	board[1] = 'o';



	displayBoard(board);
	computerMove(board);
	
	
	
	//bool res = checkWinner(board);


	//greetAndInstruct();
	
	// bool winnerFound = false;


	// while (!winnerFound) {

	// 	displayBoard(board);
	// 	//get player input 

	// 	//checkLegal

	// 	//checkWinner 

	// 	//computer move 

	// }

	return 0;
}