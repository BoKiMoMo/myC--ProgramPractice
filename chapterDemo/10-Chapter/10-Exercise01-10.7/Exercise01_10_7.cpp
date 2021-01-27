#include "Exercise01_10_7.h"
#include <iomanip>
#include <stdexcept> 

using namespace std;

DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c)
	:row(r),column(c)
{
	array = new int* [row];
	for (size_t i = 0; i < row; i++)
		array[i] = new int[column];
}

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& right)
	:row(right.row),column(right.column)
{
	array = new int* [row];
	for (size_t i = 0; i < row; i++)
		array[i] = new int[column];

	for (size_t i = 0; i < row; ++i)
		for (size_t j = 0; j < column; j++)
			array[i][j] = right.array[i][j];
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
	for (size_t i = 0; i < row; i++)
		delete[] array[i];
	delete[] array;
}

size_t DoubleSubscriptedArray::getRow() const
{
	return row;
}

size_t DoubleSubscriptedArray::getColumn() const
{
	return column;
}

int& DoubleSubscriptedArray::operator()(int r, int c)
{
	return array[r][c];
}

int DoubleSubscriptedArray::operator()(int r, int c) const
{
	return array[r][c];
}

const DoubleSubscriptedArray& DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& right)
{
	if (&right != this)
	{
		if (column != right.column || row != right.row)
		{
			for (size_t i = 0; i < row; i++)
				delete[] array[i];
			delete[] array;
			row = right.row;
			column = right.column;
			array = new int* [row];
			for (size_t i = 0; i < row; i++)
				array[i] = new int[column];
		}
		for (size_t i = 0; i < row; ++i)
			for (size_t j = 0; j < column; j++)
				array[i][j] = right.array[i][j];
	}

	return *this;
}

bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& right) const
{
	if(row!=right.row)
		return false;

	if(column!=right.column)
		return false;

	for (size_t i = 0; i < row; ++i)
		for (size_t j = 0; j < column; j++)
			if (array[i][j] != right.array[i][j])
				return false;
	
	return true;
}

std::ostream& operator<<(std::ostream& output, const DoubleSubscriptedArray& right)
{
	for (size_t i = 0; i < right.row; ++i)
	{
		for (size_t j = 0; j < right.column; j++)
			output << setw(4) << right.array[i][j];
		output << endl;
	}
	return output;
}

std::istream& operator>>(std::istream& input, DoubleSubscriptedArray& right)
{
	for (size_t i = 0; i < right.row; ++i)
		for (size_t j = 0; j < right.column; ++j)
			input >> right.array[i][j];

	return input;
}
