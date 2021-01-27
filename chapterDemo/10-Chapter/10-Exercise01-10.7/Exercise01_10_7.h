#ifndef EXERCISE01_10_7
#define EXERCISE01_10_7

#include<iostream>

class DoubleSubscriptedArray
{
	friend std::ostream& operator<<(std::ostream&, const DoubleSubscriptedArray&);
	friend std::istream& operator>>(std::istream&, DoubleSubscriptedArray&);
public :
	explicit DoubleSubscriptedArray(int = 2, int = 2);
	DoubleSubscriptedArray(const DoubleSubscriptedArray&);
	~DoubleSubscriptedArray();

	size_t getRow() const;
	size_t getColumn() const;

	int& operator() (int, int);
	int operator() (int, int) const;
	const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray&);
	bool operator==(const DoubleSubscriptedArray&) const;
	bool operator!=(const DoubleSubscriptedArray& right) const
	{
		return !(*this == right);
	}
private :
	int row, column;
	int** array;
};

#endif // !EXERCISE01_10_7