/**
*
* Solution to homework task
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

/*
Description:

3. Da se ​​napishe programa, koyato interpretira vuvedeno
tsyalo polozhitelno chislo kato broi sekundi izminali ot
nachaloto na tekushtiya den (ne se dopuska vuvezhdaneto
na poveche ot 24 chasa) i da izvede na ekrana kolko e
chasut v momenta HH:MM, spored tozi broi sekundi.
Za reshavaneto na zadachata ne se izpolzvat operatorite za tsikul.

*/

#include "stdafx.h"
#include<iostream>
using namespace std;


int main()
{
	int sec, min, hour;

	cout << "Vuvedete kolko sekundi sa minali ot nachaloto na tekushtiq den:";
	cin >> sec;

	if (sec>60 * 60 * 24)//ako sa vuvedeni sekundi, otgovarqshti na poveche ot 24 chasa
	{
		cout << "GRESHKA! Poveche ot 24 chasa!" << endl;
	}
	else
	{
		hour = sec / 3600;//v 1 chas ima 3600 sec
		min = (sec / 60) % 60;//v edna minuta ima 60 secundi; delim s ostatuk na 60, zashtoto v zapisa HH:MM minutite sa nai-mnogo 59


		cout << "Chasut e:" << endl;

		if (hour < 10) { cout << "0"; }//zaradi zapisa HH:MM 
		cout << hour << ":";
		if (min< 10) { cout << "0"; }//zaradi zapisa HH:MM 
		cout << min << endl;
	}

	system("pause");
	return 0;
}
