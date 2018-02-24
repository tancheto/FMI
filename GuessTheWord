/**
*
* Solution to second homework task
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
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <ctype.h>
using namespace std;

int const MAX = 100;//maksimum simvoli pri vhod
int const total = 30;//vsichki dumi
int const letters = 15;//maksimalna duljina na 1 duma

char DB[total][letters] = { "student","refrigerator","pointless","board","girl",
"dog","kite","knife","horse","allergic",
"avenue","pineapple","message","binomial","bachelor",
"cafeteria","digger","engineer","software","native",
"radioactive","radius","fairness","jewel","ladybird",
"gallery","absent","iguana","wanderlust","quarter" };

char *random()//generator na dluchaini dumi, izpolzvasht vremeto
{
	srand(time(NULL));
	return &DB[rand() % 30][letters];
}

int main()
{
	char word[letters];//originalna duma
	char word_out[letters];//izvejdana duma
	char level[MAX];//nivo
	char let[MAX];//vuvedena bukva
	int attempt;//broi opiti
	bool bul = true, suc, err = false;//bulevi stoinosti po default

	strncpy_s(word,letters,(random()),letters);//masivut word priema stoinost na proizvolna duma
	strncpy_s(word_out,letters, word, letters);//masivut word_out priema stoinost na masiva word

	cout << "***GUESS THE WORD***"<<endl;
	cout << "Choose a level:\n";
	cout << "*Beginner(8 attempts)-enter 1;\n";
	cout << "*Intermediate(5 attempts)-enter 2;\n";
	cout << "*Expert(3 attempts)-enter 3;\n";

	do
	{
		cout << "Your level:";
		cin.getline(level, MAX);//vuvejda se nivoto
		
		for (int i = 0; i < strlen(level); i++)
		{
			if (!isdigit(level[i]) || strlen(level)>1)//proverka za validnost na vhoda-ako ne e chislo ili e s duljina >1
			{
				cout << "\nInvalid input! Enter a number.\n";
				err = true;
			}
			else//ako vhodut e validen
			{
				switch (level[0])
				{
				case '1'://nachnaesht
					cout << "\nYou chose the Beginner level! You have 8 attempts.\n";
					err = false;
					attempt = 8;
					break;
				case '2'://naprednal
					cout << "\nYou chose the Intermediate level! You have 5 attempts.\n";
					err = false;
					attempt = 5;
					break;
				case '3'://ekspert
					cout << "\nYou chose the Expert level! You have 3 attempts.\n";
					err = false;
					attempt = 3;
					break;
				default://ako ne e vuvedeno 1,2 ili 3
					cout << "\nError! Enter only one valid number.\n";
					err = true;
					attempt = 8;//by default
					break;
				}
			}
		}

	} while (err);

	for (int i = 0; i < strlen(word); i++)//obhojdame vsqka bukva v dumata-nachalno izvejdane
	{
		if (word[0] == word[i])//ako tekushtata bukva e sustata kato purvata bukva 
		{
			word_out[i] = word[i];//tekushtata bukva v izvejdanata duma priema stoinostta na tekushtata bukva
			cout << word_out[i];
		}
		else if (word[strlen(word) - 1] == word[i])// ako tekushtata bukva e sushtata kato poslednata
		{
			word_out[i] = word[i];//tekushtata bukva v izvejdanata duma priema stoinostta na tekushtata bukva
			cout << word_out[i];
		}
		else// v protiven sluchai
		{
			word_out[i] = '_';//tekushtata bukva vse oshte ne e poznata
			cout << word_out[i];
			bul = false;//kogato dumata vse oshte ne e poznata bul=false
		}
	}

	while (bul == false || attempt > 0)//dokato dumata ne e poznata ili opitite sa >0
	{

		bul = true;//priemame po default dumata za poznata- v po natatushen moment stoinostta na tazi promenliva moje da se promeni
		suc = false;//priemame po default, che nqma poznata bukva- v po natatushen moment stoinostta na tazi promenliva moje da se promeni
		cout << "\nYour next letter:";
		cin.getline(let, MAX);//vuvejdame sledvashtata bukva

		for (int j = 0; j < strlen(let); j++)//proverka po vhod na vhoda
		{
			if (!isalpha(let[j]) || strlen(let) > 1)// ako vhodut ne e validen- ne e bukva ili e s duljina, po-golqma ot 1
			{
				cout << "\nInvalid input! Enter only ine letter.\n";
				err = true;//ima error
			}
			else//v protiven sluchai
			{
				err = false;//nqma error
			}
		}
		if (!err)//ako nqma error na vhoda
		{
			if (let[0] >= 'A' && let[0] <= 'Z') { let[0] += 32; }//ako e vuvedena glavna bukva

			for (int i = 0; i < strlen(word); i++)//obhojdame originalnata duma bukva po bukva
			{
				if (word[i] == let[0])//ako tekushtata bukva v originalnata duma e sushtata kato vuvedenata 
				{
					suc = true;//ima poznata bukva- success
					word_out[i] = word[i];//tekushtata bukva v izvejdanata duma priema stoinostta na originalnata duma
				}

				if (word_out[i] == '_')//ako bukvata ne e poznata (ima pone edna nepoznata bukva)
				{ bul = false; }//dumata ne e poznata

				cout << word_out[i];//izvejdame tekushtiqt simvol ot izvejdanata duma
			}

			if (suc)//ako ima pone edna poznata bukva
			{
				if (bul) { cout << "\nCongratulations, you win!\nThe word is '" << word << "'.\n"; break; }//ako dumata e poznata
				else { cout << "\nSuccess!\n"; }//ako cqlata duma vse oshte ne e poznata
			}
			else//ako nqma poznata bukva
			{
				if (attempt > 0) { cout << "\nError!\n"; attempt--; }//ako ostavashtite opiti sa poveche ot 0- namalqme gi 
				if (attempt == 0) { cout << "\nGAME OVER! Sorry, you lost! Try again...\n"; break; }//ako sa 0- krai na igrata, break
			}

			cout << "Attempts left:" << attempt << endl;//ostavashti opiti- ako sa poveche ot 0 se izvejdat
		}
	}
	
	system("pause");
	return 0;
}

