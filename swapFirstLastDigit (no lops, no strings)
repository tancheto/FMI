/**
*
* Solution to homework task
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

/*
Description:

5. Napishete programa, v koyato vuvedeno ot klaviaturata
tsyalo chislo (po-malko ot 2 ^ 32-1), izpisva na ekrana chislo, na koeto
sa razmeneni purvata i poslednata tsifra spryamo vuvedenoto.
Za reshavane na zadachata ne se dopuska izpolzvaneto na simvolni nizove
i operatori za tsikul.

*/

#include "stdafx.h"
#include<iostream>
#include<math.h>
#include <climits>
using namespace std;


int main()
{
	int N, n, swap, digits, last, first;

	cout << "Vuvedete cqlo chislo(<2^31-1):";
	cin >> N;

	if (N >= INT_MIN && N <= INT_MAX)
	{
		if (N < 0) { n = -N; }//zapazvame znaka na vuvedenoto chislo
		else { n = N; }

		digits = log10(n) + 1;//broqt na cifrite na chisloto  
		last = n % 10; //cifrata na edinicite(poslednata cifra)
		first = n / pow(10, digits - 1); //purvata cifra

		swap = n + (first - last) + (last - first)*pow(10, digits - 1);
		/*formula za razmqna na purva i posledna cifra; pri namirane na tqhnata razlika suotvetno q pribavqme na purva i posledna poziciq, no s obraten znak */

		if (N < 0) { swap = -swap; }//ako vuvedenoto e otricatelno, to i chisloto na izhoda e otricatelno

		cout << "Chisloto s razmeneni purva i posledna cifra e:" << swap << endl;

	}

	else
	{
		cout << "Vuvedete chislo v granicite na tip integer!" << endl;
	}

	system("pause");
	return 0;
}

