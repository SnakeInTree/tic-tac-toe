#include <iostream>

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

int main() {
	greetAndInstruct();
	return 0;
}