#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <Windows.h> 

using namespace std;

struct PlayerM {
	string name;
	int maxhp;
	int hp;
	int armor;
	int attack;
	int x;
	int y;
};
struct ColorM {
	int Mob;
	int Health;
	int Exit;
	int Wall;
	int Player;
	int Interface;
	int BackGorund_Interface;
};
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
ColorM Color_Game = {};
char GenarationAscci(int map_lvl_1[][11], int i, int j);
void mout(int map_lvl_1[][11], PlayerM Player_My);
void interface_PlayerM(PlayerM Player_My, ColorM& Color_Game);
void went(PlayerM& Player_My, int  map_lvl_1[][11], char keyboard);
void Distribution(int value, char * keyboard, PlayerM& Player_My, char * lvl_map);
void Play_Mob(int value, PlayerM& Player_My, char ** keyboard, char lvl_map);
void Give_Prize(PlayerM& Player_My);
void Play_Boss(int value, PlayerM& Player_My, char ** keyboard, char lvl_map);
void Loot_Mob(PlayerM& Player_My);
void SetColor(int text, int background);
void Information_for_Player(char keyboard, ColorM& Color_Game);
void Change_Color_Player(ColorM& Color_Game);
void Aggression_of_Enemy(PlayerM& Player_My, int map_lvl[][11], char * keyboard, char lvl_map);

int main(void) {
	Color_Game.Mob = 12;
	Color_Game.Health = 14;
	Color_Game.Exit = 10;
	Color_Game.Wall = 11;
	Color_Game.Player = 4;
	Color_Game.Interface = 14;
	Color_Game.BackGorund_Interface = 5;
	setlocale(LC_ALL, "Ru");
	PlayerM Player_My = {};

	Player_My.name = "Player_My";
	Player_My.maxhp = 150;
	Player_My.hp = 100;
	Player_My.armor = rand() % 10 + 1;
	Player_My.attack = 25;
	Player_My.y = 5;
	Player_My.x = 0;
	int map_lvl_1[10][11] = {
		{ 2, 6, 2, 5, 5, 6, 5, 5, 2, 6, 2 },
		{ 2, 9, 2, 5, 5, 0, 2, 5, 2, 9, 4 },
		{ 2, 5, 2, 0, 0, 2, 2, 5, 2, 9, 2 },
		{ 2, 5, 2, 0, 2, 6, 6, 2, 7, 9, 2 },
		{ 0, 0, 0, 0, 2, 5, 5, 2, 7, 7, 2 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6 },
		{ 0, 0, 0, 0, 5, 0, 0, 0, 2, 2, 2 },
		{ 2, 2, 2, 0, 0, 0, 0, 0, 7, 9, 8 },
		{ 6, 5, 5, 0, 0, 5, 0, 5, 2, 2, 2 },
	};
	int map_lvl_2[10][11] = {
		{ 3, 2, 7, 0, 0, 0, 0, 2, 9, 6, 8 },
		{ 0, 1, 2, 0, 0, 0, 2, 0, 2, 0, 9 },
		{ 0, 2, 5, 0, 0, 2, 5, 0, 7, 0, 0 },
		{ 0, 2, 2, 2, 0, 2, 0, 2, 2, 5, 0 },
		{ 0, 0, 0, 0, 0, 2, 2, 2, 6, 0, 2 },       
		{ 0, 2, 2, 2, 0, 2, 0, 2, 2, 0, 2 },
		{ 0, 0, 0, 2, 5, 2, 5, 0, 2, 0, 2 },
		{ 5, 2, 0, 2, 0, 2, 0, 0, 2, 0, 2 },
		{ 0, 2, 5, 5, 7, 2, 2, 2, 2, 6, 2 },
		{ 6, 2, 0, 2, 0, 5, 0, 0, 0, 5, 7 }
	};
	int map_lvl_3[10][11] = {
		{ 3, 2, 2, 2, 0, 0, 2, 5, 7, 9, 8 },
		{ 5, 7, 9, 2, 0, 0, 2, 7, 7, 9, 9 },
		{ 0, 2, 7, 9, 0, 0, 2, 5, 5, 7, 5 },
		{ 0, 2, 2, 9, 2, 0, 2, 0, 7, 5, 5 },
		{ 5, 7, 2, 4, 9, 0, 0, 2, 2, 2, 9 },
		{ 5, 5, 2, 9, 2, 0, 2, 2, 0, 5, 7 },
		{ 5, 7, 2, 9, 0, 0, 2, 7, 9, 0, 2 },
		{ 0, 7, 2, 7, 2, 0, 2, 0, 5, 7, 0 },
		{ 0, 2, 0, 9, 2, 2, 2, 7, 0, 5, 0 },
		{ 0, 7, 0, 0, 5, 0, 7, 0, 0, 5, 0 },
	};
	char lvl_map = (int)49;
	char keyboard = '+';
	Change_Color_Player(Color_Game);
	Information_for_Player(keyboard, Color_Game);
	for (int time = 7000; time >= 1; time-=50) {
		cout << "До начала игры " << time << "ms" << endl;
		Sleep(1);
		system("cls");
	}
	while (true) {
		switch (lvl_map) {
		case '0': {
			keyboard = '=';
			break;
		}

		case '1': {
			if (Player_My.hp > 0) {
				cout << "Welcome to lvl-1" << endl;
				Sleep(1000);
				keyboard = '+';
				Player_My.y = 5;
				Player_My.x = 0;
				while (true) {
					system("cls");
					mout(map_lvl_1, Player_My);
					interface_PlayerM(Player_My, Color_Game);
					Aggression_of_Enemy(Player_My, map_lvl_1, &keyboard, lvl_map);
					went(Player_My, map_lvl_1, keyboard);
					Distribution(map_lvl_1[Player_My.y][Player_My.x], &keyboard, Player_My, &lvl_map);
					if (keyboard == ']') {
						break;
					}
				}
			}
			break;
		}
		case '2': {
			if (Player_My.hp > 0) {
				cout << "Welcome to lvl-2" << endl;
				Player_My.x = 1;
				Player_My.y = 1;
				Sleep(1000);
				keyboard = '+';
				while (true) {
					system("cls");
					mout(map_lvl_2, Player_My);
					interface_PlayerM(Player_My, Color_Game);
					Aggression_of_Enemy(Player_My, map_lvl_2, &keyboard, lvl_map);
					went(Player_My, map_lvl_2, keyboard);
					Distribution(map_lvl_2[Player_My.y][Player_My.x], &keyboard, Player_My, &lvl_map);
					if (keyboard == ']') {
						break;
					}
				}
			}
			break;
		}
		case '3': {
			if (Player_My.hp > 0) {
				cout << "Welcome to lvl-3" << endl;
				Player_My.x = 1;
				Player_My.y = 1;
				Sleep(1000);
				keyboard = '+';
				while (true) {
					system("cls");
					mout(map_lvl_3, Player_My);
					interface_PlayerM(Player_My, Color_Game);
					Aggression_of_Enemy(Player_My, map_lvl_3, &keyboard, lvl_map);
					went(Player_My, map_lvl_3, keyboard);                                                                                           
					Distribution(map_lvl_3[Player_My.y][Player_My.x], &keyboard, Player_My, &lvl_map);
					if (keyboard == ']') {
						break;
					}
				}
			}
			break;
		}
		}
		if (Player_My.hp <= 0) break;
		if (keyboard == '=') {
			break;
		}
	}
	system("pause");
	return 0;
}

char GenarationAscci(int map_lvl_1[][11], int i, int j) {
	switch (map_lvl_1[i][j]) {
	case 0: return 48;
	case 1: return 64;
	case 2: return 83;
	case 3: return 60;
	case 4: return 69;
	case 5: return 77;
	case 6: return 80;
	case 7: return 72;
	case 8: return 62; 
	case 9: return 66;
	default:
		return 0;
	}
	return 0;
}

void mout(int map_lvl_1[][11], PlayerM Player_My) {	
	map_lvl_1[Player_My.y][Player_My.x] = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 11; j++) {
			switch (map_lvl_1[i][j]) {
			case 0: {
				SetColor(LightGray, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}
			case 1: {
				SetColor(Color_Game.Player, White);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}
			case 2: {
				SetColor(Color_Game.Wall, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}
			case 3: {
				SetColor(Color_Game.Exit, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}
			case 4: {
				SetColor(Color_Game.Exit, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}
			case 5: {
				SetColor(Color_Game.Mob, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			case 6: {
				SetColor(Color_Game.Health, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}
			case 7: {
				SetColor(Color_Game.Health, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}
			}
			case 8: {
				SetColor(Color_Game.Exit, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}
			case 9: {
				SetColor(Color_Game.Mob, Black);
				cout << GenarationAscci(map_lvl_1, i, j) << " ";
				break;
			}

			default: break;
			}
			
		}
		cout << endl;
	}
}

void interface_PlayerM(PlayerM Player_My, ColorM& Color_Game) {	
	SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
	cout << "|-------------------------|" << endl;
	cout <<"\t " << Player_My.name << endl;
	cout << "\t HP: " << Player_My.hp << "/" << Player_My.maxhp << endl;
	cout << "\t Armor: " << Player_My.armor << endl;
	cout << "\t attack: " << Player_My.attack << endl;
	cout << "|-------------------------|" << endl;
}

void went(PlayerM& Player_My, int  map_lvl_1[][11], char keyboard) { 
	cin.get(keyboard);
	int x = Player_My.x;
	int y = Player_My.y;
	switch (keyboard) {
	case 'a': if (Player_My.x != 0) {
		if (map_lvl_1[Player_My.y][Player_My.x - 1] != 2) {
			map_lvl_1[Player_My.y][Player_My.x] = 0;
			Player_My.x--;

		}
		break;
	}		
	case 'd': if (Player_My.x != 10) {
		if (map_lvl_1[Player_My.y][Player_My.x + 1] != 2) {
			map_lvl_1[Player_My.y][Player_My.x] = 0;
			Player_My.x++;

		}
		break;
	}			
	case 's': if (Player_My.y != 9) {
		if (map_lvl_1[Player_My.y + 1][Player_My.x] != 2) {
			map_lvl_1[Player_My.y][Player_My.x] = 0;
			Player_My.y++;

		}
		break;
	}			
	case 'w': { if (Player_My.y != 0) {
		if (map_lvl_1[Player_My.y - 1][Player_My.x] != 2) {
			map_lvl_1[Player_My.y][Player_My.x] = 0;
			Player_My.y--;
		}
	}	//W 
		break;
	}
	case '0': {
		Player_My.hp = Player_My.maxhp;
		break;
	}
	case '9': {
		Player_My.attack += 10;
		break;
	}
	case '8': {
		Player_My.armor += 5;
		break;
	}
	default: break;
	}
}

void Distribution(int value, char * keyboard, PlayerM& Player_My, char * lvl_map) { 
	switch (value)
	{
	case 8: {
		system("cls");
		*keyboard = ']';
		switch (*lvl_map) {
		case '1': {
			*lvl_map = '2';
			break;
		}
		case '2': {
			*lvl_map = '3';
			break;
		}
		case '3': {
			system("cls");
			cout << "You passed the game. Thank you for spending your time on my game." << endl;
			*keyboard = ']';
			*lvl_map = '0';
			break;
		}
		default: break;
		}
		break;
	};
	case 3: {
		switch (*lvl_map) {
		case '2': {
			*lvl_map = '1';
			break;
		}
		case '3': {
			*lvl_map = '2';
			break;
		}
		default: break;
		}
		*keyboard = ']';
		break;
	}
	case 5: {
		Play_Mob(value, Player_My, &keyboard, *lvl_map);
		break;
	}
	case 6: {
		Give_Prize(Player_My);
		Sleep(2000);
		break;
	}
	case 7: {
		if (Player_My.hp + 50 > Player_My.maxhp) {
			Player_My.hp = Player_My.maxhp;
		}
		else {
			Player_My.hp = Player_My.hp + 50;
		}
		break;
	}
	case 4: {
		system("cls");
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "|The end ultra. Yes, you just zadrot ... Congratulations), thanks for your time. |" << endl;
		cout << "----------------------------------------------------------------------------------" << endl;
		*keyboard = ']';
		*lvl_map = '0';
		break;
	}
	case 9: {
		Play_Boss(value, Player_My, &keyboard, *lvl_map);
		break;
	}
	default:
		break;
	}

}

void Play_Mob(int value, PlayerM& Player_My, char** keyboard, char lvl_map) {
	int map_attack_coefficient = 1, map_armor_coefficient = 1;
	switch (lvl_map) {
	case 1: {
		map_attack_coefficient = 15;
		map_armor_coefficient = 5;
		break;
	}
	case 2: {
		map_attack_coefficient = 30;
		map_armor_coefficient = 10;
		break;
	}
	case 3: {
		map_attack_coefficient = 45;
		map_armor_coefficient = 15;
		break;
	}
	default: break;
	}
	srand(time(0));
	string Selection_Player = "";
	int Escape = 0;
	PlayerM Mob = {};
	Mob.name = "Enemy(Mob)";
	Mob.maxhp = 100;
	Mob.hp = 100;
	Mob.armor = rand() % 10 + map_armor_coefficient;
	Mob.attack = rand() % 20 + map_attack_coefficient;
	while ((Mob.hp > 0) && (Escape != 2) && (Player_My.hp > 0)) {
		system("cls");
		interface_PlayerM(Player_My, Color_Game);
		interface_PlayerM(Mob, Color_Game);
		cout << "1 - Attack" << endl;
		cout << "2 - Run away" << endl;
		cout << "3 - Protect" << endl;
		cin >> Selection_Player;
		if (Selection_Player == "1") {
			Mob.hp = Mob.hp - (Player_My.attack - Mob.armor);
			if (Mob.attack - Player_My.armor >= 0) {
				Player_My.hp = Player_My.hp - (Mob.attack - Player_My.armor);
			}
			else {
				Player_My.hp = Player_My.hp - 0;
			}

		}
		else if (Selection_Player == "2") {
			Escape = rand() % 2 + 1;
			if (Escape != 2) {
				Player_My.hp = Player_My.hp - (int)(Mob.attack - Player_My.armor)*1.5;
			}
		}
		else if (Selection_Player == "3") {
			Player_My.hp = Player_My.hp - (int)(Mob.attack - Player_My.armor) / 3;

		}
		if (Mob.hp <= 0) {
			cout << "You killed then enemy." << endl;
			Loot_Mob(Player_My);
			Sleep(2000);
		}
		if (Player_My.hp <= 0) {
			system("cls");
			cout << "Game over. You died." << endl;
			**keyboard = ']';
		}
	}
}

void Give_Prize(PlayerM& Player_My) {
	int Prize = 0;
	Prize = rand() % 15 + 1;
	int give_pr = 0;
	switch (Prize)
	{
	case 1: Prize++;
	case 2: Prize++;
	case 3: {
		give_pr = rand() % 15 + 1;
		Player_My.attack = Player_My.attack + give_pr;
		cout << "Give to: " << give_pr << " attack" << endl;
		break;
	}
	case 4: Prize++;
	case 5: Prize++;
	case 6: Prize++;
	case 7: Prize++;
	case 8: {
		if (Player_My.hp + 50 > Player_My.maxhp) {
			Player_My.hp = Player_My.maxhp;
		}
		else {
			Player_My.hp = Player_My.hp + 50;
			cout << "Gite to: " << 50 << " hp" << endl;
		}
		break;
	}
	case 9: Prize++;
	case 10: Prize++;
	case 11: Prize++;
	case 12: {
		give_pr = rand() % 12 + 3;
		Player_My.armor = Player_My.armor + give_pr;
		cout << "Give to: " << give_pr << " armor" << endl;
		break;
	}
	case 13: Prize++;
	case 14: Prize++;
	case 15: {
		give_pr = rand() % 50 + 1;
		Player_My.maxhp = Player_My.maxhp + give_pr;
		cout << "Give to: " << give_pr << " maxhp" << endl;
		break;
	}
	default:
		break;
	}
}

void Play_Boss(int value, PlayerM& Player_My, char** keyboard, char lvl_map) {
	int map_attack_coefficient = 5, map_armor_coefficient = 5;
	switch (lvl_map) {
	case 1: {
		map_attack_coefficient = 25;
		map_armor_coefficient = 10;
		break;
	}
	case 2: {
		map_attack_coefficient = 50;
		map_armor_coefficient = 20;
		break;
	}
	case 3: {
		map_attack_coefficient = 75;
		map_armor_coefficient = 30;
		break;
	}
	default: break;
	}
	srand(time(0));
	string Selection_Player = "";
	int Escape = 0;
	PlayerM Boss = {};
	Boss.name = "Enemy(Boss)";
	Boss.maxhp = 1000;
	Boss.hp = rand() % 700 + 300;
	Boss.armor = rand() % 50 + map_armor_coefficient;
	Boss.attack = rand() % 150 + map_attack_coefficient;
	while ((Boss.hp > 0) && (Escape != 2) && (Player_My.hp > 0)) {
		system("cls");
		interface_PlayerM(Player_My, Color_Game);
		interface_PlayerM(Boss, Color_Game);
		cout << "1 - Attack" << endl;
		cout << "2 - Run away" << endl;
		cout << "3 - Protect" << endl;
		cin >> Selection_Player;
		if (Selection_Player == "1") {
			Boss.hp = Boss.hp - (Player_My.attack - Boss.armor);
			if (Boss.attack - Player_My.armor >= 0) {
				Player_My.hp = Player_My.hp - (Boss.attack - Player_My.armor);
			}
			else {
				Player_My.hp = Player_My.hp - 0;
			}
		}
		else if (Selection_Player == "2") {
			Escape = rand() % 2 + 1;
			if (Escape != 2) {
				Player_My.hp = Player_My.hp - (int)(Boss.attack - Player_My.armor)*1.5;
			}
		}
		else if (Selection_Player == "3") {
			Player_My.hp = Player_My.hp - (int)(Boss.attack - Player_My.armor) / 3;

		}
		if (Boss.hp <= 0) {
			cout << "You killed then enemy." << endl;
			Give_Prize(Player_My);
			Sleep(2000);
		}
		if (Player_My.hp <= 0) {
			system("cls");
			cout << "You died." << endl;
			**keyboard = ']';
		}
	}
}

void Loot_Mob(PlayerM& Player_My) {
	int Loot = 0;
	int give_loot = 0;
	Loot = rand() % 15 + 1;
	switch (Loot)
	{
	case 1: Loot++;
	case 2: Loot++;
	case 3: {
		give_loot = rand() % 5 + 1;
		Player_My.attack = Player_My.attack + give_loot;
		cout << "Give to: " << give_loot << " attack" << endl;
		break;
	}
	case 4: Loot++;
	case 5: Loot++;
	case 6: Loot++;
	case 7: Loot++;
	case 8: {
		if (Player_My.hp + 20 > Player_My.maxhp) {
			Player_My.hp = Player_My.maxhp;
		}
		else {
			Player_My.hp = Player_My.hp + 20;
			cout << "Give to: " << 20 << " hp" << endl;
		}
		break;
	}
	case 9: Loot++;
	case 10: Loot++;
	case 11: Loot++;
	case 12: {
		give_loot = rand() % 4 + 2;
		Player_My.armor = Player_My.armor + give_loot;
		cout << "Give to: " << give_loot << " armor" << endl;
		break;
	}
	case 13: Loot++;
	case 14: Loot++;
	case 15: {
		give_loot = rand() % 25 + 1;
		Player_My.maxhp = Player_My.maxhp + give_loot;
		cout << "Give to: " << give_loot << " maxhp" << endl;
		break;
	}
	default:
		break;
	}
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));

}

void Information_for_Player(char keyboard, ColorM& Color_Game) {
	while (true) {
	system("cls");
	SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
	cout << "Movement is carried out by pressing the keys:" << endl
		<< "'w' - Upward movement;" << endl
		<< "'a' - Move left;" << endl
		<< "'s' - Move down;" << endl
		<< "'d' - Move right." << endl
		<< "Symbols on the map:" << endl
		<< " M - Mob(Enemy);" << endl
		<< " B - Boss(Enemy);" << endl
		<< " S - Wall;" << endl
		<< " H - Health;" << endl
		<< " P - Prize;" << endl
		<< " E - Exit for game;" << endl
		<< " > - Go to the next level;" << endl
		<< " < - Go to the previous level." << endl
		<< "To continue the game, click the '/'." << endl;
		cin.get(keyboard);
		if (keyboard == '/') {
			break;
		}

	}
}

void Change_Color_Player(ColorM& Color_Game) {
	int color_key = -1; char object_key = '.';
	while (object_key != '/' && color_key != 66) {
		system("cls");
		SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
		cout << "Возможные цвета:" << endl
			<< "Black = 0," << endl
			<< "Blue = 1," << endl
			<< "Green = 2," << endl
			<< "Cyan = 3," << endl
			<< "Red = 4," << endl
			<< "Magenta = 5," << endl
			<< "Brown = 6," << endl
			<< "LightGray = 7," << endl
			<< "DarkGray = 8," << endl
			<< "LightBlue = 9," << endl
			<< "LightGreen = 10," << endl
			<< "LightCyan = 11," << endl
			<< "LightRed = 12," << endl
			<< "LightMagenta = 13," << endl
			<< "Yellow = 14," << endl
			<< "White = 15" << endl
			<< "Выход из выбора цвета игры - 66" << endl
			<< "Введите один из номеров цвета." << endl;
		cin >> color_key;
		if (color_key != 66) {
			//system("cls");
			cout << "Выберите кому присвоить данный цвет: " << endl;
			cout << "Мобам и Боссам - 1 -->"; SetColor(Color_Game.Mob, Black); cout << "M, B" << endl; 
				SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
			cout << "Лечению и призам - 2 -->"; SetColor(Color_Game.Health, Black); cout << "H, P" << endl;
				SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
			cout << "Переходам между уровнями и выходу - 3 ------------->"; SetColor(Color_Game.Exit, Black); cout << "<, >, E" << endl;
				SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
			cout << "Стенам - 4 -->"; SetColor(Color_Game.Wall, Black); cout << "S" << endl;
				SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
			cout << "Цвету пол. интерфейса - 5" << endl;
				SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
			cout << "Фону - 6" << endl;
				SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
			cout << "Игроку - 7 -->"; SetColor(Color_Game.Player, White); cout << "@" << endl;
				SetColor(Color_Game.Interface, Color_Game.BackGorund_Interface);
			cout << "Выход из выбора цвета игры - '/'" << endl;
			cin >> object_key;
			switch (object_key) {
			case '1': {
				Color_Game.Mob = color_key;
				break;
			}
			case '2': {
				Color_Game.Health = color_key;
				break;
			}
			case '3': {
				Color_Game.Exit = color_key;
				break;
			}
			case '4': {
				Color_Game.Wall = color_key;
				break;
			}
			case '5': {
				Color_Game.Interface = color_key;
				break;
			}
			case '6': {
				Color_Game.BackGorund_Interface = color_key;
				break;
			}
			case '7': {
				Color_Game.Player = color_key;
				break;
			}
			default: break;

			}
			if (object_key == '/') break;
		}
	}
}

void Aggression_of_Enemy(PlayerM& Player_My, int map_lvl[][11], char * keyboard, char lvl_map) {
	srand(time(0));
	int probability_of_agr = rand() % 100 + 1;
	int Cheking = 0;
	int Mob_x = 0;
	int Mob_y = 0;
	if (map_lvl[Player_My.y + 1][Player_My.x] == 5) {
		Mob_y = Player_My.y + 1;
		Mob_x = Player_My.x;
		Cheking = 1;
	}
	if (map_lvl[Player_My.y - 1][Player_My.x] == 5) {
		Mob_y = Player_My.y - 1;
		Mob_x = Player_My.x;
		Cheking = 1;
	}
	if (map_lvl[Player_My.y][Player_My.x + 1] == 5) {
		Mob_y = Player_My.y;
		Mob_x = Player_My.x + 1;
		Cheking = 1;
	}
	if (map_lvl[Player_My.y][Player_My.x - 1] == 5) {
		Mob_y = Player_My.y;
		Mob_x = Player_My.x - 1;
		Cheking = 1;
	}
	if (Cheking == 1 && probability_of_agr % 3 == 0) {
		map_lvl[Player_My.y][Player_My.x] = 0;
		Player_My.x = Mob_x;
		Player_My.y = Mob_y;
		Play_Mob(map_lvl[Player_My.y][Player_My.x], Player_My, &keyboard, lvl_map);
		map_lvl[Player_My.y][Player_My.x] = 1;
	}
}