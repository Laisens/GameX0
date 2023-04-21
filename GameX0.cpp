// GameX0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
using namespace std;

//если moveType true ходит игрок;
bool moveType;
const int length = 3;
char playingField[length][length];

void Move(char X0typePlaye, char X0typeBot)
{
	if (moveType) {
		do
		{
			int x, y;
			cout << "Ваш ход:" << endl;
			cin >> x;
			cin >> y;
			if (playingField[x][y] == ' ') {
				playingField[x][y] = X0typePlaye;
				break;
			}
		} while (true);
		moveType = false;
	}
	else
	{
		srand(time(NULL));
		do
		{
			int x = rand() % 3;
			int y = rand() % 3;
			if (playingField[x][y] == ' ') {
				playingField[x][y] = X0typeBot;
				break;
			}

		} while (true);
		moveType = true;
	}
}
void Display() 
{
	cout << "#0 1 2#"<<endl;
	for (int i = 0; i < length; i++) 
	{
		cout << i;
		for (int j = 0; j < length; j++)
		{
			cout<<playingField[i][j];
			if (j < length - 1)
				cout << '|';
		}
		if (i < length - 1)
			cout << endl << " ----- " << endl;
	}
	cout << endl;
}
void ClearDisplay()
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			playingField[i][j] = ' ';
		}
	}
}
void clear() {
	std::cout << "\x1B[2J\x1B[H";
}

bool CheckForVictory() {
	if ((playingField[0][0] == 'X' && playingField[0][1] == 'X' && playingField[0][2] == 'X') ||
		(playingField[1][0] == 'X' && playingField[1][1] == 'X' && playingField[1][2] == 'X') ||
		(playingField[2][0] == 'X' && playingField[2][1] == 'X' && playingField[2][2] == 'X') ||

		(playingField[0][0] == 'X' && playingField[1][0] == 'X' && playingField[2][0] == 'X') ||
		(playingField[0][1] == 'X' && playingField[1][1] == 'X' && playingField[2][1] == 'X') ||
		(playingField[0][2] == 'X' && playingField[1][2] == 'X' && playingField[2][2] == 'X') ||

		(playingField[0][0] == 'X' && playingField[1][1] == 'X' && playingField[2][2] == 'X') ||
		(playingField[0][2] == 'X' && playingField[1][1] == 'X' && playingField[2][0] == 'X')   )
	{
		return true;
	}if ((playingField[0][0] == '0' && playingField[0][1] == '0' && playingField[0][2] == '0') ||
		 (playingField[1][0] == '0' && playingField[1][1] == '0' && playingField[1][2] == '0') ||
		 (playingField[2][0] == '0' && playingField[2][1] == '0' && playingField[2][2] == '0') ||

		 (playingField[0][0] == '0' && playingField[1][0] == '0' && playingField[2][0] == '0') ||
		 (playingField[0][1] == '0' && playingField[1][1] == '0' && playingField[2][1] == '0') ||
		 (playingField[0][2] == '0' && playingField[1][2] == '0' && playingField[2][2] == '0') ||

		 (playingField[0][0] == '0' && playingField[1][1] == '0' && playingField[2][2] == '0') ||
		 (playingField[0][2] == '0' && playingField[1][1] == '0' && playingField[2][0] == '0')   )
	{
		return true;
	}
	return false;
}

int main()
{	
	setlocale(LC_ALL, "ru");
	char X0typePlayer, X0typeBot;
	int playing = 1;
	int moveCounter = 0;
	do {
		moveCounter = 0;
		ClearDisplay();
		do
		{
			int temp;
			cout << "1 = X\t2 = 0\n";
			cin >> temp;
			if (temp == 1) {
				X0typePlayer = 'X';
				X0typeBot = '0';
				moveType = true;
				break;
			}
			if (temp == 2) {
				X0typePlayer = '0';
				X0typeBot = 'X';
				moveType = false;
				break;
			}
		} while (true); // выбор играть X или 0
		do {
			clear();
			Display();
			Move(X0typePlayer, X0typeBot);
			moveCounter++;
			clear();
			Display();
			if (CheckForVictory())
			{
				if (!moveType)
					cout << "Ты победил!" << endl;
				else
					cout << "Ты проиграл!" << endl;
				break;
			}
			if (moveCounter == 9) {
				cout << "Ничья!" << endl;
				break;
			}
		} while (true);
		cout << "Повторим?\n0 - Выход" << endl;
		cin >> playing;
	} while (playing != 0);
}
