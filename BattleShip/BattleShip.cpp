#include<iostream>
#include<string>
#include<iomanip>
#include<chrono>
#include <thread>
#include<fstream>
using namespace std;

//variable declaration
int ship_rotate, state = 0, player_choice;
int starting_pos_i, starting_pos_j, ending_pos_i, ending_pos_j;
char chooseShip;
string playerOne_Name, playerTwo_Name;
const int size2 = 10;

//setting up default state
char PlayerOne_Board[size2][size2] = {
	{'C','B','D','S',' ',' ',' ',' ', ' ',' '},
	{ 'c','b','d','s',' ',' ',' ',' ', ' ',' ' },
	{ 'c','b','d',' ',' ',' ',' ',' ', ' ',' ' },
	{ 'c','b',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ 'c',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
};
char PlayerTwo_Board[size2][size2] =
{
	{' ',' ',' ',' ',' ',' ',' ',' ', ' ',' '},
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ 'c',' ',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ 'c','b',' ',' ',' ',' ',' ',' ', ' ',' ' },
	{ 'c','b','d',' ',' ',' ',' ',' ', ' ',' ' },
	{ 'c','b','d','s',' ',' ',' ',' ', ' ',' ' },
	{ 'C','B','D','S',' ',' ',' ',' ', ' ',' ' },
};

//functions
void player1();
void Instructions();
void show();
void Input();
void update();
void check();
void removePrevpos(int ship_size);
void player2();
void game();
void Playerwins(int p);
void Gamesplayed(const string& player1,const string& player2, const string& winner);
void DisplayGamesHistory();
void start();






//int main() {
//	cout << "\033[0;95m\n\n\n\n\n\n\n" << R"(
//          /$$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$       /$$$$$$$$        /$$$$$$  /$$   /$$ /$$$$$$ /$$$$$$$       
//         | $$__  $$ /$$__  $$|__  $$__/|__  $$__/| $$      | $$_____/       /$$__  $$| $$  | $$|_  $$_/| $$__  $$      
//         | $$  \ $$| $$  \ $$   | $$      | $$   | $$      | $$            | $$  \__/| $$  | $$  | $$  | $$  \ $$      
//         | $$$$$$$ | $$$$$$$$   | $$      | $$   | $$      | $$$$$         |  $$$$$$ | $$$$$$$$  | $$  | $$$$$$$/      
//         | $$__  $$| $$__  $$   | $$      | $$   | $$      | $$__/          \____  $$| $$__  $$  | $$  | $$____/       
//         | $$  \ $$| $$  | $$   | $$      | $$   | $$      | $$             /$$  \ $$| $$  | $$  | $$  | $$            
//         | $$$$$$$/| $$  | $$   | $$      | $$   | $$$$$$$$| $$$$$$$$      |  $$$$$$/| $$  | $$ /$$$$$$| $$            
//         |_______/ |__/  |__/   |__/      |__/   |________/|________/       \______/ |__/  |__/|______/|__/ 
//)";
//	this_thread::sleep_for(chrono::seconds(1));
//	system("cls");
//	start();
//	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\033[1;91mPlayer Red Name : \033[0;1m";
//	getline(cin, playerOne_Name);
//	if (playerOne_Name[0] == '\0') {
//		playerOne_Name = "RED";
//	}
//
//	cout << "\n\n\t\t\t\t\t\033[1;94mPlayer Blue Name : \033[0;1m";
//	getline(cin, playerTwo_Name);
//	if (playerTwo_Name[0] == '\0') {
//		playerTwo_Name = "BLUE";
//	}
//	Instructions();
//	system("cls");
//	player1();
//	system("cls");
//	player2();
//	cin.ignore();
//	game();
//	return 0;
//}
//void start() {
//	system("cls");
//	cout << "\n\n\n\n\n\n\n\n\n\n\n\033[0;95m                                  -----------------------------------------------------------                      " << endl;
//	cout << "                                  |                                                         |                      " << endl;
//	cout << "                                  |                 1. PLAY                                 |                      " << endl;
//	cout << "                                  |                 2. GAME LOG                             |                      " << endl;
//	cout << "                                  |                 3. EXIT                                 |                      " << endl;
//	cout << "                                  |                                                         |                      " << endl;
//	cout << "                                  -----------------------------------------------------------                      " << endl;
//
//	int option;
//	cin >> option;
//	if (option == 2) {
//		system("cls");
//		DisplayGamesHistory();
//		this_thread::sleep_for(chrono::seconds(10));
//		start();
//
//	}
//	else if (option == 3) {
//		system("cls");
//		cout << "\n\n\n\n\n\n\n                   ___________________________________________________________________________________" << endl;
//		cout << "                  |Game Ended*|" << endl;
//		cout << "                   -----------------------------------------------------------------------------------" << endl;
//		this_thread::sleep_for(chrono::seconds(1));
//		exit(0);
//	}
//}
int main() {
	cout << "\033[0;95m\n\n\n\n\n\n\n" << R"(


          /$$$$$$$   /$$$$$$  /$$$$$$$$ /$$$$$$$$ /$$       /$$$$$$$$        /$$$$$$  /$$   /$$ /$$$$$$ /$$$$$$$       
         | $$__  $$ /$$__  $$|__  $$__/|__  $$__/| $$      | $$_____/       /$$__  $$| $$  | $$|_  $$_/| $$__  $$      
         | $$  \ $$| $$  \ $$   | $$      | $$   | $$      | $$            | $$  \__/| $$  | $$  | $$  | $$  \ $$      
         | $$$$$$$ | $$$$$$$$   | $$      | $$   | $$      | $$$$$         |  $$$$$$ | $$$$$$$$  | $$  | $$$$$$$/      
         | $$__  $$| $$__  $$   | $$      | $$   | $$      | $$__/          \____  $$| $$__  $$  | $$  | $$____/       
         | $$  \ $$| $$  | $$   | $$      | $$   | $$      | $$             /$$  \ $$| $$  | $$  | $$  | $$            
         | $$$$$$$/| $$  | $$   | $$      | $$   | $$$$$$$$| $$$$$$$$      |  $$$$$$/| $$  | $$ /$$$$$$| $$            
         |_______/ |__/  |__/   |__/      |__/   |________/|________/       \______/ |__/  |__/|______/|__/ 
)";
	this_thread::sleep_for(chrono::seconds(1));
	start();
	system("cls");
	cin.ignore();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\033[1;91mPlayer Red Name : \033[0;1m";
	getline(cin, playerOne_Name);
	if (playerOne_Name[0] == '\0') {
		playerOne_Name = "RED";
	}

	cout << "\n\n\t\t\t\t\t\033[1;94mPlayer Blue Name : \033[0;1m";
	getline(cin, playerTwo_Name);
	if (playerTwo_Name[0] == '\0') {
		playerTwo_Name = "BLUE";
	}
	Instructions();
	system("cls");
	player1();
	system("cls");
	player2();
	cin.ignore();
	game();
	return 0;
}

void start() {
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\033[0;95m                                  -----------------------------------------------------------                      " << endl;
	cout << "                                  |                                                         |                      " << endl;
	cout << "                                  |                 1. PLAY                                 |                      " << endl;
	cout << "                                  |                 2. GAME LOG                             |                      " << endl;
	cout << "                                  |                 3. EXIT                                 |                      " << endl;
	cout << "                                  |                                                         |                      " << endl;
	cout << "                                  -----------------------------------------------------------                      " << endl;

	int option;
	cin >> option;
	if (option == 2) {
		system("cls");
		DisplayGamesHistory();
		this_thread::sleep_for(chrono::seconds(10));
		start();

	}
	else if (option == 3) {
		system("cls");
		cout << "\n\n\n\n\n\n\n                   ___________________________________________________________________________________" << endl;
		cout << "                  |Game Ended*|" << endl;
		cout << "                   -----------------------------------------------------------------------------------" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		exit(0);

	}

}
void Instructions() {
	system("cls");
	cout << "\033[0;32m" << endl;
	cout << "     -------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "     |                      ___________________________________________________________________________________        |" << endl;
	cout << "     |                     |                               Welcome to the Game!                                |       |" << endl;
	cout << "     |                     |-----------------------------------------------------------------------------------|       |" << endl;
	cout << "     |                     |  Player 1: " << setw(20) << left << playerOne_Name << "    Player 2: " << setw(20) << left << playerTwo_Name << "                 |       |" << endl;
	cout << "     |                     |                                                                                   |       |" << endl;
	cout << "     |                      -----------------------------------------------------------------------------------        |" << endl;
	cout << "     |                                 -----------------------------------------------------------                     |" << endl;
	cout << "     |                                 |               There are 4 types of Ships                |                     |" << endl;
	cout << "     |                                 |                 Carrier ship   (Size=5)                 |                     |" << endl;
	cout << "     |                                 |                 Battle ship    (Size=4)                 |                     |" << endl;
	cout << "     |                                 |                 Cruiser ship   (Size=3)                 |                     |" << endl;
	cout << "     |                                 |                 Destroyer ship (Size=2)                 |                     |" << endl;
	cout << "     |                                 -----------------------------------------------------------                     |" << endl;
	cout << "     |                                 -----------------------------------------------------------                     |" << endl;
	cout << "     |                                 |               You Can Rotate The Ship                   |                     |" << endl;
	cout << "     |                                 |                     Vertically                          |                     |" << endl;
	cout << "     |                                 |                    Horizontally                         |                     |" << endl;
	cout << "     |                                 -----------------------------------------------------------                     |" << endl;
	cout << "     |                        ---------------------------------------------------------------------------              |" << endl;
	cout << "     |                        |                             INSTRUCTIONS                                |              |" << endl;
	cout << "     |                        --------------------------------------------------------------------------               |" << endl;
	cout << "     |                        |    1)The Index Of Rows Should Be Given By Writing Alphabets from A-J    |              |" << endl;
	cout << "     |                        |    2)The Index Of Columns Should Be Give By writing Letters From 1-10   |              |" << endl;
	cout << "     |                        ---------------------------------------------------------------------------              |" << endl;
	cout << "     |_________________________________________________________________________________________________________________|" << endl;
	cout << "                                                Press Enter To Continue.....";
	cin.get();
	system("cls");
}

void player1() {
	player_choice = 1;
	show();
}
void player2() {
	player_choice = 2;
	show();
}

//Initial Board show
void show() {
	system("cls");
	if (player_choice == 1) {
		cout << "\033[0;91m                                                 Current Board: " << playerOne_Name << "                 \n" << endl;
	}
	if (player_choice == 2) {
		cout << "\033[0;94m                                                 Current Board: " << playerTwo_Name << "                 \n" << endl;
	}
	cout << "\t\t\t\t\t    ";
	for (int i = 0; i < size2; i++) {
		cout << i + 1 << "   ";
	}
	cout << endl;

	for (int i = 0; i < size2; i++) {
		cout << "\t\t\t\t\t  ";
		for (int j = 0; j < size2; j++) {
			cout << "+---";
		}
		cout << "+" << endl;

		cout << "\t\t\t\t\t" << char(i + 65) << " ";

		for (int j = 0; j < size2; j++) {
			if (player_choice == 1) {
				if (PlayerOne_Board[i][j] == 'C' || PlayerOne_Board[i][j] == 'c') {
					cout << "|\033[0;43m " << PlayerOne_Board[i][j] << " \033[0;91m";
				}
				else 	if (PlayerOne_Board[i][j] == 'B' || PlayerOne_Board[i][j] == 'b') {
					cout << "|\033[0;44m " << PlayerOne_Board[i][j] << " \033[0;91m";
				}
				else 	if (PlayerOne_Board[i][j] == 'S' || PlayerOne_Board[i][j] == 's') {
					cout << "|\033[0;45m " << PlayerOne_Board[i][j] << " \033[0;91m";
				}
				else 	if (PlayerOne_Board[i][j] == 'D' || PlayerOne_Board[i][j] == 'd') {
					cout << "|\033[0;46m " << PlayerOne_Board[i][j] << " \033[0;91m";
				}
				else {
					cout << "| " << PlayerOne_Board[i][j] << " ";
				}

			}
			else if (player_choice == 2) {

				if (PlayerTwo_Board[i][j] == 'C' || PlayerTwo_Board[i][j] == 'c') {
					cout << "|\033[0;43m " << PlayerTwo_Board[i][j] << " \033[0;94m";
				}
				else 	if (PlayerTwo_Board[i][j] == 'B' || PlayerTwo_Board[i][j] == 'b') {
					cout << "|\033[0;44m " << PlayerTwo_Board[i][j] << " \033[0;94m";
				}
				else 	if (PlayerTwo_Board[i][j] == 'S' || PlayerTwo_Board[i][j] == 's') {
					cout << "|\033[0;45m " << PlayerTwo_Board[i][j] << " \033[0;94m";
				}
				else 	if (PlayerTwo_Board[i][j] == 'D' || PlayerTwo_Board[i][j] == 'd') {
					cout << "|\033[0;46m " << PlayerTwo_Board[i][j] << " \033[0;94m";
				}
				else {
					cout << "| " << PlayerTwo_Board[i][j] << " ";
				}
			}
		}
		cout << "|" << endl;
	}

	cout << "\t\t\t\t\t  ";
	for (int j = 0; j < size2; j++) {
		cout << "+---";
	}
	cout << "+" << endl;
	check();
	return;
}
void check() {
	char Choice;
	cout << "\033[0;1m                                 -------------------------------------------------------- " << endl;
	cout << "                                 |      DO You Want to Change Any Ship's Location.      |" << endl;
	cout << "                                 |               Enter (Y or y) for YES                 |" << endl;
	cout << "                                 |               Enter (N or n) for NO                  |" << endl;
	cout << "                                 --------------------------------------------------------" << endl;
Invalidcheck_4:	cout << "                                                     Your choice : ";
	cin >> Choice;
	if (cin.fail() || (Choice != 'y' && Choice != 'Y') && (Choice != 'N' && Choice != 'n')) {
		cout << "Please Enter only Character (Y or y) or Character (N or n)" << endl;
		goto Invalidcheck_4;
	}
	else if (Choice == 'Y' || Choice == 'y') {
		Input();
	}
	else if (Choice == 'N' || Choice == 'n') {
		return;
	}
}
void Input() {
	system("cls");
	cout << "                                           __________________________________" << endl;
	cout << "                                           |       Ship Selection            |" << endl;
	cout << "                                           |  Press C For Carrier ship.      |" << endl;
	cout << "                                           |  Press B For Battle ship        |" << endl;
	cout << "                                           |  Press S For Submarine.         |" << endl;
	cout << "                                           |  Press D For Destroyer ship.    |" << endl;
	cout << "                                           -----------------------------------" << endl;
Invalidcheck_1:	cout << "                                                  Choose Your Ship : ";
	cin >> chooseShip;
	//Input Validation
	if (cin.fail()) {
		cout << "Invalid Input. Please Enter a Character Alphabet." << endl;
		cin.clear();
		goto Invalidcheck_1;
	}
	if (chooseShip != 'C' && chooseShip != 'B' && chooseShip != 'S' && chooseShip != 'D') {
		cout << "Invalid Input!! Please Enter a Character." << endl;
		goto Invalidcheck_1;
	}
	cout << "                                           __________________________________" << endl;
	cout << "                                           |       Ship Rotation             |" << endl;
	cout << "                                           |  Press 1 TO Rotate Vertically.  |" << endl;
	cout << "                                           |  Press 2 TO Rotate Horizontally |" << endl;
	cout << "                                           -----------------------------------" << endl;
Invalidcheck_2:cout << "                                                  Choose Rotation : ";
	cin >> ship_rotate;
	//Input Validation
	if (cin.fail()) {
		cout << "Invalid Input. Please Enter An Integer Number." << endl;
		cin.clear();
		cin.ignore(132, '\n');
		goto Invalidcheck_2;
	}
	if (ship_rotate < 1 || ship_rotate>2) {
		cout << "Invalid Input!! Please Enter An Integer from 1-2." << endl;
		goto Invalidcheck_2;
	}
	update();
}
void removePrevpos(int ship_size) {
	if (player_choice == 1) {
		bool flag = true;
		for (int i = 0; i < size2; i++) {
			for (int j = 0; j < size2; j++) {
				if (PlayerOne_Board[i][j] == chooseShip) {
					starting_pos_i = i;
					starting_pos_j = j;
					flag = false;
					break;
				}
			}
			if (flag == false) {
				break;
			}
		}
		if (PlayerOne_Board[starting_pos_i + 1][starting_pos_j] == (chooseShip + 32)) {
			for (int i = starting_pos_i; i < (starting_pos_i + ship_size); i++) {
				PlayerOne_Board[i][starting_pos_j] = ' ';
			}
		}
		else {
			for (int j = starting_pos_j; j < starting_pos_j + ship_size; j++) {
				PlayerOne_Board[starting_pos_i][j] = ' ';
			}
		}
	}
	else {
		bool flag1 = true;
		for (int i = 0; i < size2; i++) {
			for (int j = 0; j < size2; j++) {
				if (PlayerTwo_Board[i][j] == chooseShip) {
					starting_pos_i = i;
					starting_pos_j = j;
					flag1 = false;
					break;
				}
			}
			if (flag1 == false) {
				break;
			}
		}
		if (PlayerTwo_Board[starting_pos_i - 1][starting_pos_j] == (chooseShip + 32)) {
			for (int i = starting_pos_i; i > (starting_pos_i - ship_size); i--) {
				PlayerTwo_Board[i][starting_pos_j] = ' ';
			}
		}
		else {
			for (int j = starting_pos_j; j > starting_pos_j - ship_size; j--) {
				PlayerTwo_Board[starting_pos_i][j] = ' ';
			}
		}
	}
}
void update() {
	char row, check;
	int col, row_index = 0, ship_size;
	switch (chooseShip)
	{
	case 'C':
		ship_size = 5;
		break;
	case 'B':
		ship_size = 4;
		break;
	case 'D':
		ship_size = 3;
		break;
	case 'S':
		ship_size = 2;
		break;
	}
	removePrevpos(ship_size);
	system("cls");
	if (player_choice == 1) {
		cout << "\033[0;91m                                                         " << playerOne_Name << "'s Board                 \n" << endl;
	}
	if (player_choice == 2) {
		cout << "\033[0;93m                                                         " << playerTwo_Name << "'s Board                 \n" << endl;
	}
	cout << "\t\t\t\t\t    ";
	for (int i = 0; i < size2; i++) {
		cout << i + 1 << "   ";
	}
	cout << endl;

	for (int i = 0; i < size2; i++) {
		cout << "\t\t\t\t\t  ";
		for (int j = 0; j < size2; j++) {
			cout << "+---";
		}
		cout << "+" << endl;

		cout << "\t\t\t\t\t" << char(i + 65) << " ";

		for (int j = 0; j < size2; j++) {
			if (player_choice == 1) {
				if (PlayerOne_Board[i][j] == 'C' || PlayerOne_Board[i][j] == 'c') {
					cout << "|\033[0;43m " << PlayerOne_Board[i][j] << " \033[0;91m";
				}
				else 	if (PlayerOne_Board[i][j] == 'B' || PlayerOne_Board[i][j] == 'b') {
					cout << "|\033[0;44m " << PlayerOne_Board[i][j] << " \033[0;91m";
				}
				else 	if (PlayerOne_Board[i][j] == 'S' || PlayerOne_Board[i][j] == 's') {
					cout << "|\033[0;45m " << PlayerOne_Board[i][j] << " \033[0;91m";
				}
				else 	if (PlayerOne_Board[i][j] == 'D' || PlayerOne_Board[i][j] == 'd') {
					cout << "|\033[0;46m " << PlayerOne_Board[i][j] << " \033[0;91m";
				}
				else {
					cout << "| " << PlayerOne_Board[i][j] << " ";
				}
			}
			else if (player_choice == 2) {
				if (PlayerTwo_Board[i][j] == 'C' || PlayerTwo_Board[i][j] == 'c') {
					cout << "|\033[0;43m " << PlayerTwo_Board[i][j] << " \033[0;94m";
				}
				else 	if (PlayerTwo_Board[i][j] == 'B' || PlayerTwo_Board[i][j] == 'b') {
					cout << "|\033[0;44m " << PlayerTwo_Board[i][j] << " \033[0;94m";
				}
				else 	if (PlayerTwo_Board[i][j] == 'S' || PlayerTwo_Board[i][j] == 's') {
					cout << "|\033[0;45m " << PlayerTwo_Board[i][j] << " \033[0;94m";
				}
				else 	if (PlayerTwo_Board[i][j] == 'D' || PlayerTwo_Board[i][j] == 'd') {
					cout << "|\033[0;46m " << PlayerTwo_Board[i][j] << " \033[0;94m";
				}
				else {
					cout << "| " << PlayerTwo_Board[i][j] << " ";
				}
			}
		}
		cout << "|" << endl;
	}
	cout << "\t\t\t\t\t  ";
	for (int j = 0; j < size2; j++) {
		cout << "+---";
	}
	cout << "+\033[0;1m" << endl;
InvalidCheck_3:	cout << "Input the Row Index(A-J) : ";
	cin >> row;
	if (row >= 65 && row <= 75) {
		row = row;
	}
	else if (row >= 97 && row <= 106) {
		row = row;
	}
	else {
		cout << "Invalid Input. Please enter Alphabet in the Range(A-J)" << endl;
		goto InvalidCheck_3;
	}
InvalidCheck_4:	cout << "Input the Column Index(1-10) : ";
	cin >> col;
	if (cin.fail()) {
		cout << "Invalid Input. Please Enter A Integer Number." << endl;
		cin.clear();
		cin.ignore(132, '\n');
		goto InvalidCheck_4;
	}
	else if (col < 1 || col>10) {
		cout << "Invalid Input. Please Enter In the range 1-10." << endl;
		goto InvalidCheck_4;
	}
	switch (row) {
	case 'A':case 'a':
		row_index = 0;
		break;
	case 'B':case 'b':
		row_index = 1;
		break;
	case 'C':case 'c':
		row_index = 2;
		break;
	case 'D':case 'd':
		row_index = 3;
		break;
	case 'E':case 'e':
		row_index = 4;
		break;
	case 'F':case 'f':
		row_index = 5;
		break;
	case 'G':case 'g':
		row_index = 6;
		break;
	case 'H':case 'h':
		row_index = 7;
		break;
	case 'I':case 'i':
		row_index = 8;
		break;
	case 'J':case 'j':
		row_index = 9;
		break;
	}
	if (player_choice == 1) {
		int iterator = row_index;
		int iterator2 = col;
		if (ship_rotate == 1) {
			if ((row_index + 1) < ship_size) {
				cout << "It Can't Be Fitted In." << endl;
				goto InvalidCheck_3;
			}
			for (int i = 1; i <= ship_size; i++) {
				if (PlayerOne_Board[iterator][col - 1] != ' ') {
					cout << "There is an existing ship Here." << endl;
					goto InvalidCheck_3;
				}
				iterator--;
			}
			for (int i = row_index + 1, j = 1; i > (row_index + 1) - ship_size; j++, i--) {
				if (i == (row_index - ship_size) + 2) {
					PlayerOne_Board[i - 1][col - 1] = chooseShip;
				}
				else {
					PlayerOne_Board[i - 1][col - 1] = chooseShip + 32;
				}

			}
		}
		else if (ship_rotate == 2) {
			if (col < ship_size) {
				cout << "It Can't Be Fitted In." << endl;
				goto InvalidCheck_3;
			}
			for (int i = 1; i <= ship_size; i++) {
				if (PlayerOne_Board[row_index][iterator2 - 1] != ' ') {
					cout << "There is an existing ship Here." << endl;
					goto InvalidCheck_3;
				}
				iterator2--;
			}
			int iterator3 = col;
			int store2 = ship_size;
			for (int i = 1; i <= ship_size; i++) {
				if (i == ship_size) {
					PlayerOne_Board[row_index][iterator3 - 1] = chooseShip;
				}
				else {
					PlayerOne_Board[row_index][iterator3 - 1] = chooseShip + 32;

				}
				iterator3--;
			}
		}
	}
	if (player_choice == 2) {
		int iterator = row_index;
		int iterator2 = col;
		if (ship_rotate == 1) {
			if (row_index + ship_size > 10) {
				cout << "It Can't Be Fitted In." << endl;
				goto InvalidCheck_3;
			}
			for (int i = 1; i <= ship_size; i++) {
				if (PlayerTwo_Board[iterator][col - 1] != ' ') {
					cout << "There is an existing ship Here." << endl;
					goto InvalidCheck_3;
				}
				iterator++;
			}

			for (int i = row_index + 1, j = 1; i < (row_index + 1) + ship_size; j++, i++) {
				if (i == (row_index + ship_size)) {
					PlayerTwo_Board[i - 1][col - 1] = chooseShip;
				}
				else {
					PlayerTwo_Board[i - 1][col - 1] = chooseShip + 32;
				}

			}
		}
		else if (ship_rotate == 2) {
			if (col + ship_size > 11) {
				cout << "It Can't Be Fitted In." << endl;
				goto InvalidCheck_3;
			}
			for (int i = 1; i <= ship_size; i++) {
				if (PlayerTwo_Board[row_index][iterator2 - 1] != ' ') {
					cout << "There is an existing ship Here." << endl;
					goto InvalidCheck_3;
				}
				iterator2++;
			}
			int iterator3 = col;
			int store2 = ship_size;
			for (int i = row_index + 1, j = 1; i > (row_index + 1) - ship_size; j++, i--) {
				if (i == (row_index - ship_size) + 2) {
					PlayerTwo_Board[row_index][iterator3 - 1] = chooseShip;
				}
				else {
					PlayerTwo_Board[row_index][iterator3 - 1] = chooseShip + 32;

				}
				iterator3++;
			}
		}
	}
	show();
}
void game() {
	while (true) {
		system("cls");
		char Location[4] = { ' ',' ',' ','\0' };


		if (state % 2 == 0) {
			cout << "\033[0;91m                                              " << playerOne_Name << "'s Turn " << endl;

			cout << "\n\n\033[0;94m                                              Current Board: " << playerTwo_Name << "                 " << endl;
			cout << "\t\t\t\t\t    ";
			for (int i = 0; i < size2; i++) {
				cout << i + 1 << "   ";
			}
			cout << endl;

			for (int i = 0; i < size2; i++) {
				cout << "\t\t\t\t\t  ";
				for (int j = 0; j < size2; j++) {
					cout << "+---";
				}
				cout << "+" << endl;

				cout << "\t\t\t\t\t" << char(i + 65) << " ";

				for (int j = 0; j < size2; j++) {
					if (PlayerTwo_Board[i][j] == ' ' || PlayerTwo_Board[i][j] == 'A' || PlayerTwo_Board[i][j] == '*') {
						cout << "| " << PlayerTwo_Board[i][j] << " ";
					}
					else {
						cout << "|   ";
					}
				}
				cout << "|" << endl;
			}

			cout << "\t\t\t\t\t  ";
			for (int j = 0; j < size2; j++) {
				cout << "+---";
			}
			cout << "+\033[0;1m" << endl;


		InvalidCheck_3:
			cout << "\nEnter the Location to attack (For Example: A4) or Enter Es to Exit: ";
			cin.getline(Location, 4);

			if (Location[0] == 'E' && Location[1] == 's') {
				Playerwins(2);
				return;
			}

			else if ((Location[0] >= 'A' && Location[0] <= 'J') || (Location[0] >= 'a' && Location[0] <= 'j')) {
				if (Location[0] >= 'a') {
					Location[0] -= 32;
				}
			}
			else {
				cout << "Invalid Input. Please enter an alphabet in the range A-J." << endl;
				goto InvalidCheck_3;
			}

			int column;
			if (Location[1] == '1' && Location[2] == '0') {
				column = 10;
			}
			else if (Location[2] != ' ' && Location[2] != '\0') {
				cout << "Invalid Input. Please enter a number in the range 1-10." << endl;
				goto InvalidCheck_3;
			}
			else {
				column = Location[1] - '0';
				if (column < 1 || column > 10) {
					cout << "Invalid Input. Please enter a number in the range 1-10." << endl;
					goto InvalidCheck_3;
				}
			}

			if (PlayerTwo_Board[Location[0] - 65][column - 1] == '*' || PlayerTwo_Board[Location[0] - 65][column - 1] == 'A') {
				cout << "Location Already Attacked! Try Again. " << endl;
				goto InvalidCheck_3;
			}

			if (PlayerTwo_Board[Location[0] - 65][column - 1] != ' ') {
				char currentCell = PlayerTwo_Board[Location[0] - 65][column - 1];

				if (currentCell >= 'A' && currentCell <= 'Z') {
					PlayerTwo_Board[Location[0] - 65][column - 1] = 'A';

					for (int y = 0; y < 10; y++) {
						for (int x = 0; x < 10; x++) {
							if (PlayerTwo_Board[y][x] == currentCell + 32) {
								PlayerTwo_Board[y][x] = 'A';
							}
						}
					}
				}

				else if (currentCell >= 'a' && currentCell <= 'z') {
					PlayerTwo_Board[Location[0] - 65][column - 1] = 'A';
				}
			}
			else {
				PlayerTwo_Board[Location[0] - 65][column - 1] = '*';
			}

			int count = 0;
			bool flag = true;
			for (int y = 0; y < 10; y++) {
				for (int x = 0; x < 10; x++) {
					if (PlayerTwo_Board[y][x] == 'A' || PlayerTwo_Board[y][x] == ' ' || PlayerTwo_Board[y][x] == '*') {
						if (PlayerTwo_Board[y][x] == 'A') {
							count++;
						}
					}
					else {
						flag = false;
						break;
					}
				}
				if (flag == false) {
					break;
				}
			}
			if (count == 14) {
				Playerwins(1);
				return;
			}


		}
		else if (state % 2 != 0) {

			cout << "\033[0;94m                                              " << playerTwo_Name << "'s Turn" << endl;

			cout << "\n\n\033[0;91m                                               Current Board: " << playerOne_Name << "                " << endl;
			cout << "\t\t\t\t\t    ";
			for (int i = 0; i < size2; i++) {
				cout << i + 1 << "   ";
			}
			cout << endl;

			for (int i = 0; i < size2; i++) {
				cout << "\t\t\t\t\t  ";
				for (int j = 0; j < size2; j++) {
					cout << "+---";
				}
				cout << "+" << endl;

				cout << "\t\t\t\t\t" << char(i + 65) << " ";

				for (int j = 0; j < size2; j++) {
					if (PlayerOne_Board[i][j] == ' ' || PlayerOne_Board[i][j] == 'A' || PlayerOne_Board[i][j] == '*') {
						cout << "| " << PlayerOne_Board[i][j] << " ";
					}
					else {
						cout << "|   ";
					}
				}
				cout << "|" << endl;
			}

			cout << "\t\t\t\t\t  ";
			for (int j = 0; j < size2; j++) {
				cout << "+---";
			}
			cout << "+\033[0;1m" << endl;


			cout << "\nEnter the Location to attack (For Example: A4) or Enter Es to Exit: ";
			cin.getline(Location, 4);

			if (Location[0] == 'E' && Location[1] == 's') {
				Playerwins(1);
				return;
			}
			else if ((Location[0] >= 'A' && Location[0] <= 'J') || (Location[0] >= 'a' && Location[0] <= 'j')) {
				if (Location[0] >= 'a') {
					Location[0] -= 32;
				}
			}
			else {
				cout << "Invalid Input. Please enter an alphabet in the range A-J." << endl;
				goto InvalidCheck_3;
			}

			int column;
			if (Location[1] == '1' && Location[2] == '0') {
				column = 10;
			}
			else {
				column = Location[1] - '0';
				if (column < 1 || column > 10) {
					cout << "Invalid Input. Please enter a number in the range 1-10." << endl;
					goto InvalidCheck_3;
				}
			}

			if (PlayerOne_Board[Location[0] - 65][column - 1] == '*' || PlayerOne_Board[Location[0] - 65][column - 1] == 'A') {
				cout << "Location Already Attacked! Try Again. " << endl;
				goto InvalidCheck_3;
			}

			if (PlayerOne_Board[Location[0] - 65][column - 1] != ' ') {
				char currentCell = PlayerOne_Board[Location[0] - 65][column - 1];

				if (currentCell >= 'A' && currentCell <= 'Z') {
					PlayerOne_Board[Location[0] - 65][column - 1] = 'A';

					for (int y = 0; y < 10; y++) {
						for (int x = 0; x < 10; x++) {
							if (PlayerOne_Board[y][x] == currentCell + 32) {
								PlayerOne_Board[y][x] = 'A';
							}
						}
					}
				}

				else if (currentCell >= 'a' && currentCell <= 'z') {
					PlayerOne_Board[Location[0] - 65][column - 1] = 'A';
				}
			}
			else {
				PlayerOne_Board[Location[0] - 65][column - 1] = '*';
			}

			int count = 0;
			bool flag = true;
			for (int y = 0; y < 10; y++) {
				for (int x = 0; x < 10; x++) {
					if (PlayerOne_Board[y][x] == 'A' || PlayerOne_Board[y][x] == ' ' || PlayerOne_Board[y][x] == '*') {
						if (PlayerOne_Board[y][x] == 'A') {
							count++;
						}
					}
					else {
						flag = false;
						break;
					}
				}
				if (flag == false) {
					break;
				}
			}
			if (count == 14) {
				Playerwins(2);
				return;
			}
		}
		state++;
	}
}

void Playerwins(int p) {
	if (p == 1) {
		system("cls");
		cout << "\033[0;91m\n\n\n\n\n\n\n" << R"(                                                                                          
                _/      _/                       _/          _/                      _/   
                 /  _/    _//    /    _/     _/          _/    _//    //_/    _/    
                  _/    _/    _/  _/    _/     _/    _/    _/  _/    _/  _/    _/  _/     
                 _/    _/    _/  _/    _/       _/  _/  _/    _/    _/  _/    _/          
                /      _//      ///         _/  _/        _//    _/    _/  _/       
                                                                                          
                                                                                          )" << "\033[0;1m\n\n\n\n\n\n\n";

		Gamesplayed(playerOne_Name, playerTwo_Name, playerOne_Name);

	}
	else {

		system("cls");

		cout << "\033[0;94m\n\n\n\n\n\n\n" << R"(                                                                                          
                _/      _/                       _/          _/                      _/   
                 /  _/    _//    /    _/     _/          _/    _//    //_/    _/    
                  _/    _/    _/  _/    _/     _/    _/    _/  _/    _/  _/    _/  _/     
                 _/    _/    _/  _/    _/       _/  _/  _/    _/    _/  _/    _/          
                /      _//      ///         _/  _/        _//    _/    _/  _/       
                                                                                          
                                                                                          )" << "\033[0;1m\n\n\n\n\n\n\n";
		Gamesplayed(playerOne_Name, playerTwo_Name, playerTwo_Name);
	}

}
void Gamesplayed(const string& player1, const string& player2, const string& winner) {
	ofstream file("Gamesplayed.txt", ios::app);

	if (file.is_open()) {
		file << player1 << " Vs " << player2 << "     " << winner << " won" << std::endl;

		file.close();
	}
	else {
		cerr << "Error: Could not open the file!" << std::endl;
	}
}
void DisplayGamesHistory() {
	ifstream file("Gamesplayed.txt");

	if (file.is_open()) {
		string line;
		cout << "\t\t\t\t\t\t\033[1;93mGame History:\n\n\n";

		while (getline(file, line)) {
			cout << "\t\t\t\t\t\033[1;93m" << line << endl;
		}

		file.close();
	}
	else {
		cerr << "Error: Could not open the file!" << endl;
	}
	cout << "\n\n\n\n\n\033[0;34mGame Log Will Automatically Disappear after 5 seconds";
}