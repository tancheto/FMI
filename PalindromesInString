/**
*
* Solution to second homework task
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
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
int const maxim = 50;

void palindrome(char string[])
{
	short int n, m;
	short int count = 0;//obsht broi na palindromite
	short length[maxim];//duljina na vseki palindrom
	char all_palindromes[maxim][maxim];//tuk shte zapazim vsichki palindromi

	bool equal;//proverka dali dva palindroma sa ednakvi
	short number[maxim];//broi na ednakvite palindromi
	bool marked[maxim];//markirani palindromi- ako veche sa sreshtani
	

	for (int i = 0; i < strlen(string); i++)//proverka za palindromi
	{
		if (i != 0 && i != strlen(string) - 1 && string[i - 1] == string[i + 1])//necheten palindrom-palindrom s necheten broi simvoli
		{
			n = 1;//interval, v koito proverqvame za palindromi			
			while (string[i - n] == string[i + n])//dokato ima nov palindrom
			{
				int q = 0;//broi simvoli v palindroma- nachalna inicializaciq
				for (int j = i - n; j <= i + n; j++)//i- os na simetriq
				{
					all_palindromes[count][q] = string[j];//dobavqme simvol po simvol palindroma v masiva s vsichki palindromi
					q++;//uvelchavame broq na simvolite v palindroma
				}

				length[count] = q;//duljinata na palindroma e broqt na simvolite, sreshtani v nego
				count++;//uvelichavame broq na sreshtnatite palindromite
				n++;//uvelichavame intervala, v koito proverqvame za palindromi
			}
		}


		if (i != strlen(string) - 1 && string[i] == string[i + 1])//cheten palindrom-palindrom s cheten broi simvoli
		{
			m = 1;//interval, v koito proverqvame za palindromi	
			while (string[i - m + 1] == string[i + m])//dokato ima nov palindrom
			{
				int q = 0;//broi simvoli v palindroma- nachalna inicializaciq
				
				for (int j = i - m + 1; j <= i + m; j++)//i - os na simetriq
				{
					all_palindromes[count][q] = string[j];//dobavqme simvol po simvol palindroma v masiva s vsichki palindromi
					q++;//uvelchavame broq na simvolite v palindroma
				}
				length[count] = q;//duljinata na palindroma e broqt na simvolite, sreshtani v nego
				count++;//uvelichavame broq na sreshtnatite palindromite
				m++;//uvelichavame intervala, v koito proverqvame za palindromi
			}
		}

	}

	//tuk veche vsichki palindromi sa otkriti

	for (int n = 0; n < count; n++) { number[n] = 1; marked[n] = false; }//v nachaloto vsichki palindromi se sreshtat po vednuj i sa nemarkirani, dokato ne opredelim koi ot tqh se povtarqt

	for (int a = 0; a < count; a++)//proverqvame edin po edin palindromite
	{
		for (int b = a + 1; b < count; b++)//s vsichki sled tekushtiq
		{
				for (int c = 0; c < length[a]/2; c++)//palindromite sa simetrichni otnosno sredata im, zatova mojem da proverim dali suvpadat samo purvata polovina simvoli
				{
					//ako duljinite na dvata palindromi sa ednakvi i tekushtite im simvoli sa ednakvi i vtoriqt sravnqvan palindrom ne e markiran
					if (length[a]==length[b] && all_palindromes[a][c] == all_palindromes[b][c] && marked[b]==false) { equal = true; }//obqvqvame gi vremenno za ednakvi
					else { equal = false; break; }//ako edno ot gornite usloviq e greshno, to palindromite ne sa ednakvi, break
				}
				
				if (equal)//ako palindromite sa ednakvi
				{
					marked[b] = true; //markiran palindrom, veche e sreshtan 
					number[a]++;//[b] palindrom e sustiqt palindrom kato tozi na poziciq [a], uvelichavame broqt na sreshtaniqata na [a]
				}
			
		}
	}

	cout << "Palindromes:" << endl;

	for (int t = 0; t < count; t++)
	{
		if (marked[t] == false)//ako ne sa markirani- izvejdame gi, zaedno s broq na sreshtaniqta im
		{
			for (int s = 0; s < length[t]; s++)
			{
				cout << all_palindromes[t][s];
			}
			cout << " - " << number[t] << endl;
		}
	}
	}//void- end

	


int main()
{
	char str[maxim];
	cout << "Enter string, please:";
	cin.getline(str, maxim);//vuvejdame string

	if (strlen(str) > maxim) { cout << "Invalid input. Enter a string up to 50 symbols."; }//ako vuvedeniqt string e nad dopustimiq broi simvoli
	else//inache:
	{
		palindrome(str);
	}

	system("pause");
	return 0;
}


