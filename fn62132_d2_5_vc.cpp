/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Tanya Hristova
* @idnumber 62132
* @task 5
* @compiler VC
*
*/

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <Windows.h>
using namespace std;
const int maxim = 80;

void GoToXY(int column, int line)//funkciq, opredelqstha na koi red i stulb shte otide kursorut
{
	COORD coord;
	coord.X = column;
	coord.Y = line;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!SetConsoleCursorPosition(hConsole, coord))
	{
	}
}

int main()
{
	short int stars;//kolko sa zvezdite
	short int border[maxim];//dolni granici za zvezdite
	short int column[maxim];//v koq kolona se namira zvezdata
	short int row[maxim] = {};//na koi red e zvezdata
	short int length_tail[maxim] = {};//nachalna inicializaciq- s 0
	char tail;

	cout << "The number of the stars is:"; cin >> stars;
	cout << "What is the symbol for the shooting star tail:"; cin >> tail;
	system("cls");//chistim ekrana na konzolata

	if (stars >= 3 && stars <= 80)//ako broqt na zvezdite e v dopustimite stoinosti
	{
		for (int i = 0; i < stars; i++)//za vsqka zvezda generirme sluchaina kolona i granica-red, do koito da stigne i da preustanovi dvijenieto si
		{
			column[i] = rand() % 81;//mejdu 0 i 80
			border[i] = rand() % 20 + 6;//mejdu 6 i 25
		}


		while (!(GetKeyState(3) & 0x8000))//3=Ctrl+C- dokato ne e natisnata klavishnata kombinaciq Ctrl+C
		{

			for (int i = 0; i < stars; i++)//vsichki zvezdi
			{
				for (int j = length_tail[i]; j>0; j--)//otpechatvame opashkata na tekushtata zvezda
				{
					GoToXY(column[i], row[i] - j);
					cout << tail;
				}

				GoToXY(column[i], row[i]);//otpechatvame zvezdata
				cout << "*";

				row[i]++;
				if (length_tail[i] < 6) { length_tail[i]++; }//dokato opashkata na  zvezdata e s duljina 6, tq se uvelichava s 1 na vseki hod
				if (row[i] == border[i])//ako zvezdata stigne do predvaritelno opredelenata i granica
				{//generirame nova zvezda na indeksa na tekushtata
					column[i] = rand() % 81;//mejdu 0 i 80
					border[i] = rand() % 20 + 6;//mejdu 6 i 25
					row[i] = 0;
					length_tail[i] = 0;
				}
			}
			Sleep(100);//ekranut zamruzva, sled kato sa otpechatani vsichki zvezdi za momenta
			system("cls");//chistim ekrana,za da otpechatame zvezdite v sledvashtata im poziciq
			cout << endl;
		}
	}

	else { cout << "The number of stars should be between 3 and 80." << endl; }//ako vhodut e nevaliden

	system("pause");
	return 0;
}
