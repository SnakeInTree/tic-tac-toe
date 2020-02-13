#include <iostream>
#include<string>  

using namespace std;

//simple string concat function 
string makeLine(string a, string b, string c) {
	string result = " " + a + " | " + b + " | " + c;
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
		cout << "success";
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

	string sep =    "------------";
	string sep_bl = "              ";
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

//flatten the 3 boards and check for the 8 poss. overlaps 
bool checkWinner(char board[]) {

	char fboard[9];
	for (int j=0; j < 9; j++) {
		fboard[j] = '-';
	}

	//go thru each of the 3 boards
	for (int i=0; i<27; i++) {
		if (board[i] != 'n') {
			fboard[i % 9] = board[i];
		}
	}

	// for (int k=0; k<9; k++) {
	// 	cout << fboard[k];
	// }
	 cout << (fboard[2] == fboard[8]);

	
	//MAKE THESE ALL CHECK FOR = 1! FOR CHAR EQ. IF THE CHARS ARE EQUAL WE GET 1!!

	//top horz 
	if ((fboard[0] == fboard[1] == && fboard[1] == fboard[2]) {
		return true;
	}

	//middle horz
	else if (fboard[3] == fboard[4] && fboard[4] == fboard[5]) {
		return true;

	}

	//bottom horz
	else if (fboard[6] == fboard[7] && fboard[7] == fboard[8]) {
		return true;

	}

	//left vert
	else if (fboard[0] == fboard[3] && fboard[3] == fboard[6]) {
		return true;

	}

	//mid vert
	else if (fboard[1] == fboard[4] && fboard[4] == fboard[7]) {
		return true;

	}

	//right vert
	else if (fboard[2] == fboard[5] && fboard[5] == fboard[8]) {
		return true;

	}

	else if (fboard[0] == fboard[4] && fboard[4] == fboard[8]) {
		return true;

	}

	else if (fboard[2] == fboard[4] && fboard[4] == fboard[6]) {
		return true;

	}
	else{
		return false;
	}
}

bool checkIfLegal(int cNbre, char board[]) {

	if (cNbre < 1 || cNbre > 27) {

		//false

	}

	else if (board[cNbre - 1] != 'n') {

		//cell is occupied 

	}

	//players are o's I suppose 
	else {
		board[cNbre - 1] = 'o';
	}
	return true;


}

int main() {

	char board[27];
	for (int i=0; i<27; i++) {
		board[i] = 'n';
	}

	board[10] = 'x';
	board[20] = 'x';
	board[0] = 'x';

	//greetAndInstruct();

	//displayBoard(board);
	bool res = checkWinner(board);

	cout << res;
	return 0;
}