#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> Array = {};

	for (size_t i = 0; i <= Array.size();)
	{
		int n = 1;
		cin >> n;
		if (10 <= n && n <= 100)
		{
			Array[i] = n;
			for (size_t m = 0; m <= Array.size(); m++)
			{
				if (n == Array[i+1])
					if (i != m)
					{
						Array[i] = 0;
						i--;
						break;
					}
			}
			i++;
		}

	}

	for (size_t i = 0; i < Array.size(); i++)
		cout << Array[i] << " ";
}