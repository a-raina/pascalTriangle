// A program to compute the value of a given position in Pascal's triangle.

#include <iostream>
#include <stdlib.h>

using namespace std;

#define DEFAULT_LIMIT 1

bool checkValidInput(int row, int column){
	if (column>=0 && column <= row){
		return  true;
	}
	return false;
}

int factorial(int number, int limit){
	if(number == limit){
		if(limit == 0){
			return 1;
		}
		return limit;
	}
	else if (number == 1 || number == 0){
		return 1;
	}
	else {
		return number*factorial(number-1, limit);
	}
}

int numberAtPos(int &row, int &column){
	int numerator = factorial(row,row-column);
	int denominator = factorial(column, DEFAULT_LIMIT);

	return numerator/denominator;
}

void main(){
	int row, column;
	cout<<"This program computes the value of a given position in Pascal's triangle."
		  "For example, the first element of the triangle (1) will be row 0 position 0.\n\n";
	cout<<"Please enter the row and the position on the row:\n";
	cout<<"Row: ";
	cin>>row;
	cout<<"Position: ";
	cin>>column; 

	if(checkValidInput(row, column)){
		cout<<"\n\nDesired value: "<<numberAtPos(row, column );
	}
	else{
		cout<<"\n\nInput was invalid.";
	}

	cout<<"\n";
	system("pause");
}