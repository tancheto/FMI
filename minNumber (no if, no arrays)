/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Tanya Hristova
* @idnumber 62132
* @task 4
* @compiler VC
*
*/

/*
Description:

4. Da se ​​napishe programa, koyato vuvezhda estestveni chisla ot klaviaturata,
do vuvezhdaneto na chisloto 0. Da se ​​izvede na ekrana nai-malkoto vuvedeno chislo.
Za reshavaneto na zadachata ne se dopuska izpolzvaneto na operator if.
Za reshavaneto na zadachata ne se dopuska izpolzvaneto na masivi.

*/


#include "stdafx.h"
#include<iostream>
#include<math.h>//ima matematicheski funkcii, izpolzvani v programata

using namespace std;

int main()
{
	int n, min;

	cout << "Vuvedete estestveno chilso:";
	cin >> n;

	min = n;//na min prisvoqvame purvata vuvedena stoinost

	do
	{
		min = (n + min - abs(n - min)) / 2;//formula za opredelqne na po-malkoto ot dve chisla
		cout << "Vuvedete estestveno chilso:";
		cin >> n;

	} while (n > 0);//dokato ne se vuvede 0 ili otricatelno chislo

	cout << "Nai-malkoto vuvedeno chislo e:" << min << endl;

	system("pause");
	return 0;
}
