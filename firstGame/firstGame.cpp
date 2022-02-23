/*
Игра "Крестики-нолики"

Этапы создания:
	1. создать игровое поле
	2. ход игрока, обработка данных
	3. условия победы и присуждение выигрыша
	4. главный модуль, сборка всех ф-й

*/

#include <iostream>
using namespace std;

int counter;

//список позиций игрового поля
string board_list[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

int player_checkpoint; // ввод числа игроком

// игровое поле
void gameBoard() {
	cout << string(13, '-') << endl;
	for (int i = 0; i < 3; i++) {
		cout << "| " << board_list[0 + i * 3] << " | " << board_list[1 + i * 3]
			<< " | " << board_list[2 + i * 3] << " |\n";
	}
	cout << string(13, '-') << endl;
}


// ввод хода игроков, внесение данных в таблицу
void playerCheck(string a, string player) {

	cout << player <<" игрок, куда поставить " << a << "? \n";
	while (true)
	{
	
			cin >> player_checkpoint;

		if (player_checkpoint <= 9 && player_checkpoint >= 1) {
			if (board_list[player_checkpoint - 1] != "X" &&
				board_list[player_checkpoint - 1] != "O") {

				board_list[player_checkpoint - 1] = a;
				counter++;
				break;
			}

			else {
				cout << "Клетка занята, выбирите другую.\n";
				continue;
			}
		}
		else
		{
			cout << "Введите корректное число (от 1 до 9)\n";
			continue;
		}
	
		
	}
}

// ф-я проверки на победу
int win() {
	if (board_list[0] == board_list[1] && board_list[1] == board_list[2])
		return 1;
	else if (board_list[3] == board_list[4] && board_list[4] == board_list[5])
		return 1;
	else if (board_list[6] == board_list[7] && board_list[7] == board_list[8])
		return 1;
	else if (board_list[0] == board_list[3] && board_list[3] == board_list[6])
		return 1;
	else if (board_list[1] == board_list[4] && board_list[4] == board_list[7])
		return 1;
	else if (board_list[2] == board_list[5] && board_list[5] == board_list[8])
		return 1;
	else if (board_list[0] == board_list[4] && board_list[4] == board_list[8])
		return 1;
	else if (board_list[2] == board_list[4] && board_list[4] == board_list[6])
		return 1;
	else
		return 0;

}

int main()
{
	setlocale(LC_ALL, "");
	counter = 0;
	int count_step = 0;
	bool flag = false;
	while (!flag)
	{
		gameBoard();
		if (counter % 2 == 0) {
			playerCheck("X", "Первый");
			
		}
		else
		{
			playerCheck("O", "Второй");
			
		}

		count_step++;
		flag = win();

		system("cls");

		if (count_step == 9)
			break;
	}

	gameBoard();
	if (flag == true) {
		((counter - 1) % 2 == 0) ? cout << "Победа 1 игрока\n" :
			cout << "Победа 2го игрока\n";
	}
	else
		cout << "Ничья!\n";
	
	//выход из игры в конце
	string exit;
	cout << "Нажмите 0 для выхода\n";
	cin >> exit;
}
