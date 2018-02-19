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

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool brackets(string content, long i, long m, bool cor, long open)//rekursivna funkciq
{
	if (content[i] == '(') //ako imame otvarqshta skova, broqt im se uvelichava
	{
		open++;
	}
	if (content[i] == ')')//ako imame zatvarqshta skoba
	{
		if (open == 0)//ako dosega sme nqmali otvarqshta
		{
			cor = false;//error
		}
		else//inache
		{
			open--;//na otvarqshtata otgovarq zatvarqshta, namalqme broq na otvarqshtite
			cor = true;//no error
		}
	}

	if (i == m || cor == false) //ako sme dostignali dunoto na rekursiqta, ili ima error
	{
		if (open != 0) //ako otvarqshtite sa razlichen broi ot otvarqshtite
		{
			cor = false;
		} //error
		return cor; //rezultat
	}
	else { return brackets(content, i + 1, m, cor, open); }//inache produljavame rekursiqta


}//function-end

int main()
{
	string str;
	cout << "Enter string:";
	getline(cin, str);//vuvejdame stringa
	if (!cin) { cout << "Invalid input!" << endl; }//validaciq po vhod
	else
	{
		if (brackets(str, 0, str.size(), true, 0)) { cout << "correct" << endl; }//ako nqma error- correct
		else { cout << "incorrect" << endl; }//inache- incorrect
	}

	//system("pause");
	return 0;
}
