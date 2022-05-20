#include "salesy.h"
#include <iostream>

namespace SALES
{
	using namespace std;

	// copies the lesser of 4 or n items from the array ar
	// to the sales member of s and computes and stores the
	// average, maximum, and minimum values of the entered items;
	// remaining elements of sales, if any, set to 0
	void setSales(Sales & s, const double ar[], int n)
	{
		const int ARRSIZE = 4;
		double lesserelements[ARRSIZE] = {};
		bool aux = true;

		for(int i=0;i < ARRSIZE; ++i)
		{
			double temp = ar[0];

			for(int j=0;j < (n-1);++j)
			{
				if(!(temp < ar[j+1]))
				{
					for(int k=0;k < ARRSIZE;++k)
					{
						if(ar[j+1] == lesserelements[k])
						{
							aux = false;
							break;
						}
					}
					if(aux)
						temp = ar[j+1];
				}
			}
			lesserelements[i] = temp;
		}
		
		for(int i=0;i < ARRSIZE;++i)
			s.sales[i] = ar[i];

		double holder = 0;

		for(int i=0;i < n;++i)
			holder += ar[i];

		s.average = holder / n;

		double tempmin = lesserelements[0];

		for(int i=0;i < 3;++i)
		{
			if(tempmin > lesserelements[i+1])
				tempmin = lesserelements[i+1];
		}

		s.min = tempmin;

		double tempmax = ar[0];

		for(int i=0;i < (n-1);++i)
		{
			if(tempmax < ar[i+1])
				tempmax = ar[i+1];
		}
			
		s.max = tempmax;
	}
		

	// gathers sales for 4 quarters interactively, stores them
	// in the sales member of s and computes and stores the
	// average, maximum, and minimum values
	void setSales(Sales & s)
	{
		s.sales[0] = 0.1;
		s.sales[1] = 0.2;
		s.sales[2] = 0.3;
		s.sales[3] = 0.4;
	}

	// display all information in structure s
	void showSales(const Sales & s)
	{
		cout << "Mostrando salarios" << endl;
		for(int i=0;i <4;i++)
			cout << s.sales[i] << endl;
		cout << s.average << endl;
		cout << s.max << endl;
		cout << s.min << endl;

	}
}