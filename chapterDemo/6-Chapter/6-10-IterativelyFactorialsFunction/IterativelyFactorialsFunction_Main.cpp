#include <iostream>
#include <iomanip>

using namespace std;

unsigned long factorial(unsigned int); 

int main()
{

    for (unsigned int counter = 0; counter <= 10; ++counter)
        cout << setw(2) << counter << "! = " << factorial(counter)
        << endl;
} 


unsigned long factorial(unsigned int number)
{
    unsigned long result = 1;

    for (unsigned int i = number; i >= 1; --i)
        result *= i;

    return result;
}