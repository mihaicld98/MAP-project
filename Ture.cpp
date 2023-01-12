#include <iostream>

using namespace std;

#define linMax 5
#define colMax 5

void InitTabla(int tabla[linMax][colMax])
{
	for (int lin = 0; lin < linMax; lin++)
		for (int col = 0; col < colMax; col++)
			tabla[lin][col] = 0;
}


void Afisare(int tabla[linMax][colMax])
{
	for (int lin = 0; lin < linMax; lin++)
	{
		cout << " ";
		for (int col = 0; col < colMax; col++)
			if (tabla[lin][col] == -1)
				cout << "* ";
			else
				cout << "@ ";

		cout << "\n";
	}
	cout << "\n<--------------->\n\n";
}

void fct(int tabla[linMax][colMax], int lin, int& sol)
{
	if (lin == linMax)
	{
		Afisare(tabla);	
		sol++;			 
	}
	else
	{
		for (int col = 0; col < colMax; col++)
			if (tabla[lin][col] == 0)
			{
				for (int i = 0; i < linMax; i++)
					if (i == lin)
						continue;
					else
						tabla[i][col] = -1;

				fct(tabla, lin + 1, sol);

				for (int i = 0; i < linMax; i++)
					tabla[i][col] = 0;

			}
	}


} 

int main()
{
	int tabla[linMax][colMax];
	int lin = 0;
	int sol = 0;

	InitTabla(tabla);
	fct(tabla, lin, sol);

	cout << sol;
}