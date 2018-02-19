/**
*
* Solution to second homework task
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

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int maxim = 100;//maksimalna duljina na izrechenieto

char ch[12] = {'.', '!', '?', ',', '…', ';', ':', '-', '"'};//globalen char masiv sus simvoli

bool exist(char sym)//proverka dali daden simvol se sudurja v globalniq masiv
{
	int count = 0;
	for (int i = 0; i < 12; i++)
	{
		if (sym == ch[i]) { count++; }//ako dadeniqt simvol se sudurja v globalniq masiv, count++
	}
	if (count != 0) { return true; }//ako simvolut se sreshta v globalniq masiv, to funkciqta vrushta rezultat true
	if(count==0) { return false; }//ako simvolut ne se sreshta v globalniq masiv, funkciqta vrushta rezultat false
}

void frame(char sent[maxim])
{
	int max = 0, counter = 0, blank;
	bool punct = false;

	if (strlen(sent) > maxim) { cout << "Invalid input. Enter a sentence up to 100 symbols."; }//ako duljinata na izrechenieto e nad dopustimite 100 simvola
	else //v protiven sluchai
	{
		for (unsigned int i = 0; i < strlen(sent); i++)
		{
			if ((sent[i] >= 'a' && sent[i] <= 'z') || (sent[i] >= 'A' && sent[i] <= 'Z'))//broim duljinata na nai-dulgata duma
			{
				counter++;
				if (counter > max) { max = counter; }
			}
			else { counter = 0; }
		}
		blank = max + 1;//prazno mqsto sled dumata- nachalna inicializaciq

		for (int i = 0; i < max + 2; i++)//otpechatvame gorna strana na ramkata, max+2 zaradi || ot dvete strani na ramkata
		{
			cout << "-";
		}

		cout << endl << "|";
		for (unsigned int i = 0; i < strlen(sent); i++)
		{

			if ((sent[i] >= 'a' && sent[i] <= 'z') || (sent[i] >= 'A' && sent[i] <= 'Z'))//ako tekushtiqt simvol e bukva
			{
				cout << sent[i];//izvejdame tekushtata bukva
				blank--;//praznoto mqsto sled dumata v ramkata namalqq
				punct = false;// ne e punktuacionen znak
			}

			if (!punct && (exist(sent[i]) || sent[i]==char(32) || sent[i]==char(9)))//ako tekushtiqt simvol e prepinatelen znak, tab ili space i ako predishniqt e bukva
			{
				cout << setw(blank) << "|" << endl << "|";//oformqme kraq na tekushtiq red i nacaloto na sledvashtiq
				blank = max + 1;//svobodnoto mqsto otnovo e maksimalno
				punct = true;//punktuacionen znak e
			}
		}
		
		if (!punct)// ako posledniqt ne e punktuacionen znak
		{
			cout << setw(blank) << "|" << endl;
		}
		else { cout << (char)8; }//backspace,ako posledniqt znak e punktuacionen- triem eventualnata | cherta v nachaloto na posledniq red 

		for (int i = 0; i < max + 2; i++)//dolna strana na ramkata
		{
			cout << "-";
		}
	}
}

int main()
{
	char sent[maxim];
	cout << "Please, enter a sentence:" << endl;
	cin.getline(sent,maxim);
	frame(sent);
	cout << endl;

	system("pause"); 
    return 0;
}

