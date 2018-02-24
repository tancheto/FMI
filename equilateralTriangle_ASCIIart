/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Tanya Hristova
* @idnumber 62132
* @task 6
* @compiler VC
*
*/

/*
Description:

6. Da se ​​napishe programa, koyato risuva na ekrana (v konzolata)
ravnostranen triugulnik, sus simvol, vuveden ot klaviaturata.
Razmerut na triugulnika se opredelya ot visochinata mu, koqto
sushto se vuvezhda ot klaviaturata, kato tryabva da otgovarya
na uslovieto da se subira na standarten ekran s razmer 25 reda.

*/

#include "stdafx.h"
#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	char sym;
	int h,i,j;

	cout << "Vuvedete simvol:";
	cin >> sym;

	cout << "Vuvedete visochina na triugulnika(<=25):";
	cin >> h;

	if (h > 25) { cout << "Nevalidni vhodni danni! Visochinata e tvurde golqma."<<endl; }//ako visochinata e poveche ot 25 
	else
	{
		cout << "Ravnostranen triugulnik s visochina " << h << " ot simvoli " << sym <<":"<< endl;
		for (i = 1; i <= h; i++)
		{
			cout << setw(h-i+10);//kolko svobodni mesta da se ostavqt predi da se izvedat suotvetnie simvoli; centrira se triugulnikut
			for (j = 1; j <= i; j++)//kolko simvola da se izvedat na suotvetniq red
			{
				cout << sym <<" ";//izvejdame simvolite
			}
			cout << endl;//nov red 
		}
	}


	system("pause");
	return 0;
}

