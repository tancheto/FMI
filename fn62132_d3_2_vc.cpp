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

#include "stdafx.h"
#include <iostream>

int const minim = 1;
int const maxim = 20;

using namespace std;

bool input_validation(int s)//proverqvame dali chisloto e v dopustimite granici
{
	if (s >= minim && s <= maxim) { return true; }
	else { return false; }
}

int nod(int a, int b)//nai-golqm obsht delitel
{
	if (a > b) { a = a - b; }
	else { b = b - a; }

	if (a == b) { return a; }
	else { nod(a, b); }//rekursiq

}

int get_certain_capacity(int n, int m, int k)//funkciq, opredelqsha broq stupki
{
	int steps = 0,steps_1=0,steps_2=0;//purvonachalno sa 0
	int c, N, M;

	if (n < m) { c = n; n = m; m = c; }//veche n>m
									   //zapazvame purvonachalnite stoinosti na n i m
	N = n;
	M = m;
	//nulirame n i m- izprazvame sudovete
	n = 0;
	m = 0;

	if (k%nod(N, M) != 0) { return -1; }//ako broq litri, koito iskem da dostignem ne se deli na NOD-a na vmestimostta na dvata legena- zadachata nqma reshenie 
	if (k > N && k > M) { return -1; }//ako broq litri, koito iskame da dostignem e po-golqm ot vmestimostta na vseki edin o sudovete- zadachata nqma reshenie

	//algoritum za namirane na broq stupki- prava posoka, vinagi deistva, ako ima reshenie
	do//mojem da pulnim samo golemiq legen, da prelivame ot nego v malkiq i da izprazvame malkiq
	{
		if (n == 0) //ako po-golemiqt sud e prazen
		{
			n = N; //pulnim go
			steps++;// uvelichavame broq na stupkite
		}
		else //ako v golemiq sud ima voda
		{
			m = 0;//izprazvame po-malkq sud
			steps++;//uvelichavame broq na stupkite
		}

		if (M < n)//ako vmestimostta na po-malkiq sud e po-malka ot momentnoto kolichestvo voda v po-golemiq sud
		{
			n = n - (M - m);//prelivame vodata ot po-golemiq v po-malkiq
			m = M;//po-malkiqt sud se pulni izcqlo
			steps++;//uvelichavame broq na stupkite
		}
		else//inache
		{
			m = n;//prelivame cqloto kolichestvo ot golemiq v malkiq sud
			n = 0;//izprazvame golemiq
			steps++;//uvelichavame broq na stupkite
		}
	} while (n != k && m != k);//dokato legen1 ne e raven na iskanoto i legen2 ne e raven na iskanoto

	steps_1 = steps;//zapazvame broq na stupkite v praviq algoritum
	steps = 0;//zanulqvame broq na stupkite
	//izprazvame sudovete
	n = 0;
	m = 0;

	//obraten algoritum- ponqkoga e s po-maluk broi stupki, no ne vinagi deistva
	do//mojem da pulnim samo malkiq legen, da prelivame ot nego v golemq, da izprazvame golemiq
	{
		if (m == 0) //ako po-malkiqt sud e prazen
		{
			m = M; //pulnim go
			steps++;// uvelichavame broq na stupkite
		}
		else //ako v malkiq sud ima voda
		{
			if (m + n < N)//ako sbora na litrite voda v dvata suda e po-maluk ot vmrstimostta na po-golemiq legen
			{
				n = n + m;//prelivame ot po-malkata v po-golqmata
				m = 0;//malkata veche e prazna
				steps++;//uvelichavame broq na stupkite s 1
			}
			else//inache
			{
				m = m - (N - n);//prelivame voda ot po-malkiq v po-golemiq
				n = N;//golemiqt sud e pulen napulno
				steps++;//uvelichavame broq na stupkite
			}
			
		}

	} while (n != k && m != k && steps<steps_1);//dokato ne poluchim jelaniq broi litri ili stupkite stanat poveche ot veche poluchenite v praviq algoritum

	steps_2 = steps;//broi stupki v obratniq algoritum (ako raboti v dadeniq sluchai)

	if (steps_1 <= steps_2) { return steps_1; }//vrushta stoinostta na po-malkiq broi stupki
	else { return steps_2; }
}

int main()
{
	int n, m, k;

	cout << "Input the capcity of the 2 vessels:" << endl;
	cout << "Vessel 1:"; cin >> n;
	cout << "Vessel 2:"; cin >> m;

	cout << "Enter the capacity you want to get:";
	cin >> k;

	if (input_validation(m) && input_validation(n) && input_validation(k))//ako n,m,k sa v dopustimite granici
	{
		cout << "Number of steps needed:" << endl << get_certain_capacity(n, m, k) << endl;//vikame funkciqta
	}

	else { cout << "Invalid data!" << endl; }//ako n,m ili k ne sa v dopustimite granici

	return 0;
}

