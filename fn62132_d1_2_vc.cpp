/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Tanya Hristova
* @idnumber 62132
* @task 2
* @compiler VC
*
*/

/*
Description:

2. Da se ​​napishe programa, koyato po vuvedenoto ot klaviaturata
cyalo polozhitelno desetichno chislo, da izvede na ekrana
shestnadesetichnoto predstavyane na chisloto,
procheteno obratno.
Primer: Vhod: 51; Izhod: F.

*/

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int n, N, digit;
	int cifra, ost, i = 0, j;

	cout << "Vuvedete cyalo polozhitelno desetichno chislo:";//vuvejdaame chislo
	cin >> n;

   
	N = n % 10;//prisvoqvame na N stoinost, ravna na poslednata cifra na n (na edinicite)
	n /= 10;//premahvame cifrata na edincite ot chisloto n
	
	while (n > 0)
	{
		digit = n % 10;//novata poslednata cifra na n (na edinicite)
		N = 10 * N + digit;//tuk natrupvame cifrite ot n na obratno 
		n /= 10;//premahvame cifrata na edincite ot chisloto n
	}

	//cout << "Oburnatoto chilo na vuvedenoto e: " << N << endl;
	cout << "V shestnadesetichna sistema chisloto se predstavq:";
	
	cout << hex << uppercase << N << endl;//chisloto v 16-ichna broina sistema

	system("pause");
	return 0;
}

