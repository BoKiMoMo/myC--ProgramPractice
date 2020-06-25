#include <iostream>

using namespace std;

int main(){

	int number_1 = 0, number_2 = 0;
	
	cout<<"Enter two integer to compare :"<<endl;
	cin>>number_1>>number_2;
	
		if(number_1==number_2)
			cout<<number_1<<" = "<<number_2<<endl;
		if(number_1!=number_2)
			cout<<number_1<<" != "<<number_2<<endl;
		if(number_1<number_2)
			cout<<number_1<<" < "<<number_2<<endl;
		if(number_1>number_2)                      
			cout<<number_1<<" > "<<number_2<<endl;
		if(number_1<=number_2)
			cout<<number_1<<" <= "<<number_2<<endl;
		if(number_1>=number_2)                      
			cout<<number_1<<" >= "<<number_2<<endl;

return 0;                   
} 					
