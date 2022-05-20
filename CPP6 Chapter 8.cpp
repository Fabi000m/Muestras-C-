#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
T maxn(T [], int);

template<> const char* maxn<const char*>(const char* [], int);

const int ARRSIZE1 = 6;
const int ARRSIZE2 = 4;
const int ARRSIZE3 = 5;

int main()
{
	int Arr1[ARRSIZE1]    = {21, 15, 7, 3, 9, 11};
	double Arr2[ARRSIZE2] = {5.1, 6.3, 3.0, 7.2};
	const char * Arr3[ARRSIZE3] =
	{
		"Hola.",
		"Un gusto.",
		"Que cuentas?",
		"Un placer.",
		"Adios."
	};

	cout << maxn(Arr1, ARRSIZE1) << endl;
	cout << maxn(Arr2, ARRSIZE2) << endl;
	cout << maxn(Arr3, ARRSIZE3) << endl;

	cin.get();
}

template<typename T>
T maxn(T arr[], int size)
{
	T temp = arr[0];
	for(int i=1;i < size;i++)
	{
		if(temp < arr[i])
			temp = arr[i];
	}
	return temp;
}

template<> const char* maxn<const char*>(const char* Arr[], int size)
{
	unsigned StrLongestSize         = strlen(Arr[0]);
	switch(size)
	{
	case 1 :
		return Arr[0];
		break;
	case 2 :
		return strlen(Arr[0]) < strlen(Arr[1]) ? Arr[1] : Arr[0];
		break;
	default :
		for(int i=1;i < size;i++)
		{
			if(StrLongestSize < strlen(Arr[i]))
				StrLongestSize =  strlen(Arr[i]);
		}
		for(int i=0;i < size;i++){
			if(strlen(Arr[i]) == StrLongestSize)
				return Arr[i];
		}
	}
	return 0;
}









