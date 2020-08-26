#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>

using namespace std;

const int SIZE = 10;
int long Binary(int);
int Octal(int);
int Decima(int);


int main()
{
	cout << setw(SIZE) << "Binary" 
		<< "\t" << setw(SIZE) << "Octal" 
		<< "\t" << setw(SIZE) << "Decima" << endl;
	
	//Natural Number
	for(int i = -256; i < 0; i++)
	{
		cout << setw(SIZE) << setfill(' ') << Binary(i);
		cout <<"\t" << setfill(' ')
			<< right << setw(SIZE)  << Octal(i) << "\t"
			<< right << setw(SIZE)  << Decima(i) << endl;
	}

	//Negative Number
	for (int i = 0; i <= 256; i++)
	{
		cout << setw(SIZE) << setfill('0') << Binary(i);
		cout << "\t" << setfill(' ')
			<< right << setw(SIZE) << Octal(i) << "\t"
			<< right << setw(SIZE) << Decima(i) << endl;
		//<< setw(SIZE) << CarryConversion.Hex(i) 
	}
}


int long Binary(int n)
{
	int long b = 0;
	if (n>=0)
	{
		for (int i = 9; i >= 0; i--)
		{
			if (pow(2, i) <= n)
			{
				b = b + 1 * pow(10, i);
				n = n - pow(2, i);
			}
		}
		return 	b;
	}
	else
	{
		n = (n+1) * -1;
		for (int i = 9; i >= 0; i--)
		{
			if (pow(2, i) <= n)
			{
				n = n - pow(2, i);
			}
			else
				if (pow(2, i) > n)
				{
					b = b + 1 * pow(10, i);
				}
		}
		return b;
	}

}

int Octal(int n)
{
	unsigned int b = Binary(n);
	unsigned int o = 0, m = 0;
	for (size_t i = 0; i < 3; i++)
	{
		m = b % 1000;
		if (m % 10 == 1)
			o = o + 1 * pow(10, i);
			m /= 10;

		if (m % 10 == 1)
			o = o + 2 * pow(10, i);
			m /= 10;

		if (m == 1)
			o = o + 4 * pow(10, i);
		
		b /= 1000;
	}

	return o;
}

int Decima(int n)
{
	return n;
}