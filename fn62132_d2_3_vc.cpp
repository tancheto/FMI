/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Tanya Hristova
* @idnumber 62132
* @task 3
* @compiler VC
*
*/


#include "stdafx.h"
#include<iostream>
using namespace std;

void contain(int number)
{
	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };//zapazvame po kolko puti se sreshtat cifrite 0,1,2,3,4,5,6,7,8,9 
	short int remain, max = 0, index;

	while (number > 0)// shte izvlechem vsichki cifri na chisloto
	{
		remain = number % 10;//posledna cifra na chisloto
		arr[remain]++;//uveluchavame s 1 broq na sreshtaniqta na suotvetnata cifra 
		number /= 10;// delim na 10, za da se osvobodim ot poslednata cifra i da preminem kum sledvashtata
	}

	for (int j = 0; j <= 9; j++)//namirame maksimalniq broi sreshtaniq na nqkoq cifra; max=0-nachalna inicializaciq
	{
		if (arr[j] > max)
		{
			max = arr[j];
		}
	}
	for (int j = 0; j <= 9; j++)//izvejdame vsichki cifri, koito se sreshtat max na broi puti
	{
		if (max == arr[j])
		{
			cout << "Most frequently used numbers are:" << endl << j << "->" << arr[j] << " times." << endl;
		}
	}

}


int main()
{
	int num;

	cout << "Please enter a number:";
	cin >> num;

	if (cin.fail())// ako input-ut e greshen, t.e. ako ne e ot tip int
	{
		cout << -1 << endl;//error
	}
	else
	{
		if (num < 0) { num = -num; }// ako vuvedenoto chislo e otricatelno
		contain(num);// izpulnenie na void
	}

	system("pause");
	return 0;
}



