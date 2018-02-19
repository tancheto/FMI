/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Tanya Hristova
* @idnumber 62132
* @task 1
* @compiler VC
*
*/

/*
Description:

1. Narichame reditsa ot estestveni chisla:
● Namalyavashto, ako vsyako sledvashto chislo e po-malko ot predishnoto
● Narastvashta, ako vsyako sledvashto chislo e po-golyamo ot predishnoto
● Neopredeleno, ako ne e v sila nito edno ot gornite usloviya
Napishete programa na C ++, chrez koyato potrebitelyat vuvezhda posledovatelno,
edno po edno, estestveni cifri ot klaviaturata (otritsatelna chisla ili nula se schita za krai na vuvezhdaneto)
i vuzmozhno nai-rano izvezhda na ekrana kakuv vid ot posochenite e reditsata
(t.e. ako reditsata stane neopredelena, sushto ima krai na vuvezhdaneto).
Za reshavaneto na zadachata ne se dopuska izpolzvaneto na masivi.

*/

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	int n, maxi, mini;
	short val = 0;
	/*val ukazva kakva e redicata;
	narastvashta->(1);
	namalqvashta->(-1)
	za momenta redicata ne e nito narastvashta, nito namalqvashta->(0)*/

	cout << "Vuvedete chislo:";//vuvejdane na purvoto chilso izvun cikul, za da moje da s sravni s vtoroto, vuvedeno v cikula
	cin >> n;
	maxi = mini = n;

	do
	{
		cout << "Vuvedete chislo:";
		cin >> n;
		if (n > maxi)//ako chisloto e po-golqmo ot nai-golqmoto, vuvedeno do momenta
		{
			if (val == -1) //ako na predishniq hod e bila namalqvashta
			{
				cout << "Redicata veche e neopredelena." << endl;
				break;//krai na do while
			}
			else//ako na preden hod e bila narastvashta
			{
				cout << "Redicata e narastvashta." << endl;//ostava sushtata, vse oshte e opredelena
				maxi = n;//nai-golqm element stava toku-shto vuvedeniqt
				val = 1;//ukazatel, che redicata e narastvashta
			}
		}
		else if (n < mini) //ako chisloto e po-malko ot nai-malkoto, vuvedeno do momenta 
		{
			if (val == 1) //ako na predishniq hod e bila narastvashta
			{
				cout << "Redicata veche e neopredelena." << endl;
				break; //krai na do while
			}
			else//ako na preden hod e bila namalqvashta 
			{
				cout << "Redicata e namalqvashta." << endl;//ostava sushtata, vse oshte e opredelena
				mini = n;//nai-maluk element stava toku-shto vuvedeniqt
				val = -1;//ukazatel, che redicata e namalqvashta
			}
		}
		else //ako vuvedenoto chislo ne e nito po-golqmo ot maksimalnoto, nito po-malko ot minimalnoto
		{
			cout << "Redicata veche e neopredelena." << endl; //redicata stava neopredelena
			break; //krai na do while
		}
	} while (n > 0);

	if (n <= 0) { cout << "Vie vuvedohte otricatelno chislo ili 0." << endl; }

	system("pause");
	return 0;
}

