/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Tanya Hristova
* @idnumber 62132
* @task 7
* @compiler VC
*
*/

/*
Description:

7. Vseki triugulnik moje da se opredeli v dekartova koordinatna sistema 
s koordinatite na trite mu vurha. Shte narichame daden triugulnik "izpraven",
ako nyakoya ot stranite mu e usporedna na abscisnata os. 
Da se ​​napishe programa, koyato vuvezhda ot klaviaturata koordinatite na 
vurhovete na dva triugulnika i:
a. Proveryava dali triugulnicite sa ravnostranni.
b. Proveryava dali triugulnicite sa izpraveni.
c. Ako gornite dve usloviya sa izpulneni, namira liceto na obshtoto im sechenie, v
   protiven sluchai izvezhda suobshtenie za neizpulnenie na suotvetnite usloviya.

*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <float.h>
#include <iomanip>


const double epsilon = 0.0001;//konstanta- dostatuchno malko polojitelo chislo epsilon
using namespace std;

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	return fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}//lice na triugulnik s koordinati (x1,y1)(x2,y2)(x3,y3)


bool isInside(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y)
{
	double A = area(x1, y1, x2, y2, x3, y3);//lice na triugulnik ABC
	double A1 = area(x, y, x2, y2, x3, y3);//lice na triugulnik PBC
	double A2 = area(x1, y1, x, y, x3, y3);//lice na triugulnik PAC
	double A3 = area(x1, y1, x2, y2, x, y);//lice na triugulnik PAB
	
	return (A == A1 + A2 + A3);// Proverqva dali sumata na A1, A2 i A3 e sushtata kato na A 
}
/* funkciq, koqto proverqva dali tochkata P(x, y) leji v triugulnika, formiran ot 
 tochkite A(x1, y1), B(x2, y2) i C(x3, y3) */

double length(double x1, double y1, double x2, double y2)
{
	double length;
	length = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return length;
}// duljina na otsechka pri dadeni koordinati na dvata i kraq

double minim(double n, double m)
{
	double minim = (n + m - abs(n - m))/2;//formula za po-malko ot dve chisla
	return minim;
}
double maxim(double n, double m)
{
	double maxim = (n + m + abs(n - m))/2;//formula za po-golqmo ot dve chisla 
	return maxim;
}

double equation_of_lines_x(double x_1, double x_2, double y_1, double y_2, double x1_1, double x1_2, double y1_1, double y1_2)//koordinata x na presechna tochka na dve otsechki 
{
	double A, B, C, A1, B1, C1;
	double x;//x koordinata na presechna tochka

	A = y_1 - y_2;
	B = x_2 - x_1;
	C = x_1*y_2 - x_2*y_1;
	A1 = y1_1 - y1_2;
	B1 = x1_2 - x1_1;
	C1 = x1_1*y1_2 - x1_2*y1_1;

	if (A*B1 - A1*B == 0) { return std::numeric_limits<double>::quiet_NaN(); }//x=NaN, otsechkite sa usporedni ili lejat na edna prava
	else
	{
		x = ((-C)*B1 + C1*B) / (A*B1 - A1*B);//formula za x koordinata- chez determinanta 
		if (x >= minim(x_1, x_2) && x <= maxim(x_1, x_2) && x >= minim(x1_1, x1_2) && x <= maxim(x1_1, x1_2)) {return x;}//ako x e mejdu x koordinatite na kraishtata na otsechkite, to otsechkite se presichat
		else { return std::numeric_limits<double>::quiet_NaN(); }//x=NaN, ako pravite se presichat, no samite otsechki- ne
	}
}

double equation_of_lines_y(double x_1, double x_2, double y_1, double y_2, double x1_1, double x1_2, double y1_1, double y1_2)//koordinata y na presechna tochka na dve otsechki 
{
	double A, B, C, A1, B1, C1;
	double y;//y koordinata na presechna tochka

	A = y_1 - y_2;
	B = x_2 - x_1;
	C = x_1*y_2 - x_2*y_1;
	A1 = y1_1 - y1_2;
	B1 = x1_2 - x1_1;
	C1 = x1_1*y1_2 - x1_2*y1_1;

	if (A*B1 - A1*B == 0) { return std::numeric_limits<double>::quiet_NaN(); }//y=NaN, otsechkite sa usporedni ili lejat na edna prava
	else
	{
		y = (A*(-C1) + A1*C) / (A*B1 - A1*B);//formula za y koordinata- chez determinanta 
		if (y >= minim(y_1, y_2) && y <= maxim(y_1, y_2) && y >= minim(y1_1, y1_2) && y <= maxim(y1_1, y1_2)) { return y; }//ako y e mejdu x koordinatite na kraishtata na otsechkite, to otsechkite se presichat
		else { return std::numeric_limits<double>::quiet_NaN(); }//y=NaN, ako pravite se presichat, no samite otsechki- ne

	}
}

int main()
{
	double a_x,a_y,b_x,b_y,c_x,c_y;//koordinati na vurhove na purvi triugulnik ABC
	double AB, BC, AC;//duljini na otsechkite na triugulnik ABC
	double d_x,d_y,e_x,e_y,f_x,f_y;//koordinati na vurhove na vtori triugulnik DEF
	double DE, EF, DF;//duljini na otsechkite na triugulnik DEF
	double x_AB_DE, y_AB_DE, x_AB_EF, y_AB_EF, x_AB_DF, y_AB_DF,
		   x_BC_DE, y_BC_DE, x_BC_EF, y_BC_EF, x_BC_DF, y_BC_DF,
		   x_AC_DE, y_AC_DE, x_AC_EF, y_AC_EF, x_AC_DF, y_AC_DF;//x i y koordinati na vurhovete na ABC i DEF
	bool bul = true;//kogato nqma error, to bul=true

	double koord[9][2];//masiv s koordinati na presechni tochki ili tochki, koito sa v triugulnika
	int t = -1, s = 0;//slujat za iteraciq prez masiva
	
	cout << "Vuvedete vurhovete na purviq triugulnik:"<<endl;
	cout << "x(A):"; cin >> a_x;
	cout << "y(A):"; cin >> a_y;
	cout << "x(B):"; cin >> b_x;
	cout << "y(B):"; cin >> b_y;	
	cout << "x(C):"; cin >> c_x;
	cout << "y(C):"; cin >> c_y;

	cout << "Vuvedete vurhovete na vtoriq triugulnik:"<<endl;
	cout << "x(D):"; cin >> d_x;
	cout << "y(D):"; cin >> d_y;
	cout << "x(E):"; cin >> e_x;
	cout << "y(E):"; cin >> e_y;
	cout << "x(F):"; cin >> f_x;
	cout << "y(F):"; cin >> f_y;

	//duljini na stranite na triugulnicite

	AB = length(a_x, a_y, b_x, b_y);
	BC = length(b_x, b_y, c_x, c_y);
	AC = length(a_x, a_y, c_x, c_y);
	DE = length(d_x, d_y, e_x, e_y);
	EF = length(e_x, e_y, f_x, f_y);
	DF = length(d_x, d_y, f_x, f_y);

	if ((AB < BC + AC && BC < AB + AC && AC < AB + BC) && (DE < EF + DF && EF < DE + DF && DF < DE + EF))// ako e izpulneno neravenstvoto na triugulnika za ABC i DEF
	{
		if (fabs(AB - BC) < epsilon && fabs(AB - AC) < epsilon && fabs(BC - AC) < epsilon)//ravnostranen triugulnik- ako stranite sa s dostatuchno malka razlika pomejdu si, mojem da schitame, che sa ravni 
		{
			cout << "Triugulnik ABC e ravnostranen!" << endl;
		}
		else { bul = false; cout << "Triugulnik ABC ne e ravnostranen!" << endl; }//bul=false => error

		if (fabs(DE - EF) < epsilon && fabs(DE - DF) < epsilon && fabs(EF - DF) < epsilon)//ravnostranen triugulnik- ako stranite sa s dostatuchno malka razlika pomejdu si, mojem da schitame, che sa ravni
		{
			cout << "Triugulnik DEF e ravnostranen!" << endl;
		}
		else { bul = false; cout << "Triugulnik DEF ne e ravnostranen!" << endl; }//bul=false => error

		if ((a_y == b_y && c_y > a_y) || (a_y == c_y && b_y > a_y) || (b_y == c_y && a_y > b_y))//izpraven triugulnik- dve ot y koordinatite da sa ravni(usporedna strana na abscisnata os) i tretata y koordinata da e nad drugite 2
		{
			cout << "Triugulnik ABC e izpraven!" << endl;
		}
		else { bul = false; cout << "Triugulnik ABC ne e izpraven!" << endl; }//bul=false => error

		if ((d_y == e_y && f_y > d_y) || (d_y == f_y && e_y > d_y) || (e_y == f_y && d_y > e_y))//izpraven triugulnik- dve ot y koordinatite da sa ravni(usporedna strana na abscisnata os) i tretata y koordinata da e nad drugite 2
		{
			cout << "Triugulnik DEF e izpraven!" << endl;
		}
		else { bul = false; cout << "Triugulnik DEF ne e izpraven!" << endl; }//bul=false => error

		if (bul)//if bul==true => no errors, vsichki usloviq za triugulnicite sa izpulneni
		{
			if (isInside(a_x, a_y, b_x, b_y, c_x, c_y, d_x, d_y))//ako D e v triugulnik ABC
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == d_x && koord[i][1] == d_y) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break 
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = d_x;
				s++;
				koord[t][s] = d_y;
				s = 0;
			}

			if (isInside(a_x, a_y, b_x, b_y, c_x, c_y, e_x, e_y))//ako E e v triugulnik ABC
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == e_x && koord[i][1] == e_y) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = e_x;
				s++;
				koord[t][s] = e_y;				
				s = 0;
			}
			if (isInside(a_x, a_y, b_x, b_y, c_x, c_y, f_x, f_y))//ako F e v triugulnik ABC
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == f_x && koord[i][1] == f_y) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = f_x;
				s++;
				koord[t][s] = f_y;
				s = 0;
			}
			if (isInside(d_x, d_y, e_x, e_y, f_x, f_y, a_x, a_y))//ako A e v triugulnik DEF
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == a_x && koord[i][1] == a_y) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = a_x;
				s++;
				koord[t][s] = a_y;			
				s = 0;
			}
			if (isInside(d_x, d_y, e_x, e_y, f_x, f_y, b_x, b_y))//ako B e v triugulnik DEF
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == b_x && koord[i][1] == b_y) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = b_x;
				s++;
				koord[t][s] = b_y;
				s = 0;
			}
			if (isInside(d_x, d_y, e_x, e_y, f_x, f_y, c_x, c_y))//ako C e v triugulnik DEF
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == c_x && koord[i][1] == c_y) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = c_x;
				s++;
				koord[t][s] = c_y;				
				s = 0;
			}

			x_AB_DE = equation_of_lines_x(a_x, b_x, a_y, b_y, d_x, e_x, d_y, e_y);//x koordinata na presechna tochka na AB i DE
			y_AB_DE = equation_of_lines_y(a_x, b_x, a_y, b_y, d_x, e_x, d_y, e_y);//y koordinata na presechna tochka na AB i DE
			if (!isnan(x_AB_DE) && !isnan(y_AB_DE))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_AB_DE && koord[i][1] == y_AB_DE) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_AB_DE;
				s++;
				koord[t][s] = y_AB_DE;				
				s = 0;
			}

			x_AB_EF = equation_of_lines_x(a_x, b_x, a_y, b_y, e_x, f_x, e_y, f_y);//x koordinata na presechna tochka na AB i EF
			y_AB_EF = equation_of_lines_y(a_x, b_x, a_y, b_y, e_x, f_x, e_y, f_y);//y koordinata na presechna tochka na AB i EF
			if (!isnan(x_AB_EF) && !isnan(y_AB_EF))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_AB_EF && koord[i][1] == y_AB_EF) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_AB_EF;
				s++;
				koord[t][s] = y_AB_EF;				
				s = 0;
			}

			x_AB_DF = equation_of_lines_x(a_x, b_x, a_y, b_y, d_x, f_x, d_y, f_y);//x koordinata na presechna tochka na AB i DF
			y_AB_DF = equation_of_lines_y(a_x, b_x, a_y, b_y, d_x, f_x, d_y, f_y);//y koordinata na presechna tochka na AB i DF
			if (!isnan(x_AB_DF) && !isnan(y_AB_DF))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_AB_DF && koord[i][1] == y_AB_DF) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_AB_DF;
				s++;
				koord[t][s] = y_AB_DF;				
				s = 0;
			}

			x_BC_DE = equation_of_lines_x(b_x, c_x, b_y, c_y, d_x, e_x, d_y, e_y);//x koordinata na presechna tochka na BC i DE
			y_BC_DE = equation_of_lines_y(b_x, c_x, b_y, c_y, d_x, e_x, d_y, e_y);//y koordinata na presechna tochka na BC i DE
			if (!isnan(x_BC_DE) && !isnan(y_BC_DE))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_BC_DE && koord[i][1] == y_BC_DE) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_BC_DE;
				s++;
				koord[t][s] = y_BC_DE;
				s = 0;
			}

			x_BC_EF = equation_of_lines_x(b_x, c_x, b_y, c_y, e_x, f_x, e_y, f_y);//x koordinata na presechna tochka na BC i EF
			y_BC_EF = equation_of_lines_y(b_x, c_x, b_y, c_y, e_x, f_x, e_y, f_y);//y koordinata na presechna tochka na BC i EF
			if (!isnan(x_BC_EF) && !isnan(y_BC_EF))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_BC_EF && koord[i][1] == y_BC_EF) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_BC_EF;
				s++;
				koord[t][s] = y_BC_EF;				
				s = 0;
			}

			x_BC_DF = equation_of_lines_x(b_x, c_x, b_y, c_y, d_x, f_x, d_y, f_y);//x koordinata na presechna tochka na BC i DF
			y_BC_DF = equation_of_lines_y(b_x, c_x, b_y, c_y, d_x, f_x, d_y, f_y);//y koordinata na presechna tochka na BC i DF
			if (!isnan(x_BC_DF) && !isnan(y_BC_DF))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_BC_DF && koord[i][1] == y_BC_DF) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_BC_DF;
				s++;
				koord[t][s] = y_BC_DF;				
				s = 0;
			}

			x_AC_DE = equation_of_lines_x(a_x, c_x, a_y, c_y, d_x, e_x, d_y, e_y);//x koordinata na presechna tochka na AC i DE
			y_AC_DE = equation_of_lines_y(a_x, c_x, a_y, c_y, d_x, e_x, d_y, e_y);//y koordinata na presechna tochka na AC i DE
			if (!isnan(x_AC_DE) && !isnan(y_AC_DE))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_AC_DE && koord[i][1] == y_AC_DE) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_AC_DE;
				s++;
				koord[t][s] = y_AC_DE;				
				s = 0;
			}

			x_AC_EF = equation_of_lines_x(a_x, c_x, a_y, c_y, e_x, f_x, e_y, f_y);//x koordinata na presechna tochka na AC i EF
			y_AC_EF = equation_of_lines_y(a_x, c_x, a_y, c_y, e_x, f_x, e_y, f_y);//y koordinata na presechna tochka na AC i EF
			if (!isnan(x_AC_EF) && !isnan(y_AC_EF))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_AC_EF && koord[i][1] == y_AC_EF) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_AC_EF;
				s++;
				koord[t][s] = y_AC_EF;				
				s = 0;
			}

			x_AC_DF = equation_of_lines_x(a_x, c_x, a_y, c_y, d_x, f_x, d_y, f_y);//x koordinata na presechna tochka na AC i DF
			y_AC_DF = equation_of_lines_y(a_x, c_x, a_y, c_y, d_x, f_x, d_y, f_y);//y koordinata na presechna tochka na AC i DF
			if (!isnan(x_AC_DF) && !isnan(y_AC_DF))//ako tova sa koordinati na sushtestvuvashti presechni tochki
			{
				for (int i = 0; i <= t; i++)
				{
					if (koord[i][0] == x_AC_DF && koord[i][1] == y_AC_DF) break;//ako do momenta v masiva sushtestvuvat tekushtite koordinati => break
				}
				//ako do momenta v masiva lipsvat tekushtite koordinati, dobavqme gi kum masiva
				t++;
				koord[t][s] = x_AC_DF;
				s++;
				koord[t][s] = y_AC_DF;				
				s = 0;
			}

			cout << "Liceto na sechenieto na dvata triugulnika e:";
		if (t == 2)//ako 3 ot redovete sa zapulneni s koordinati (0,1,2), to veche e obrazuvan triugulnik ot sechenieto na dvata drugi
		{
			cout << fixed << setprecision(9) << area(koord[0][0], koord[0][1], koord[1][0], koord[1][1], koord[2][0], koord[2][1]) << endl;//lice na triugulnika s koordinati- tezi ot masiva
		}
		else { cout << 0 << endl; }//inache- presechnite tochki sa tvurde malko, liceto na sechenieto e ravno na 0
	
	}
	}

	else { cout << "Triugulnik(ci) s takiva duljini na stranite ne sushtestvuva(t)! Vuvedete drugi koordinati!"<<endl;}//ako neravenstvoto na triugulnika ne e izpulnenoza ABC i/ili DEF

	system("pause");
    return 0;
}

