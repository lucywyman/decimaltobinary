/**************************************************************
 *Program Filename: assignment2.cpp;
 *Author: Lucy Wyman;
 *Date: January 31, 2014;
 *Description: This program has two parts--in the first we convert a decimal number from the user to binary, then we test the number of iterations it takes to lose precision with floats and doubles.
 *Input: none;
 *Output: Answers to these questions and many more!  Stay tuned.
 ***************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cfloat>
#include<string>
#include<cstdlib>

using namespace std;

int checkNumber(){
	/*So I heard you like variables*/
	string number;
	string intmax = "4294967295";

	/*Get user input and check to make sure it's valid (positive integer, no floats or negatives*/
	cout<<"Please enter a positive integer ";
	cin>>number;
	for(char& c : number){
		if (isdigit(c)==false){
			cout<<"You did not input a valid number!  Please try again."<<endl;
			return 0;
		}
	}

	/*Make sure that worked*/
	cout<<number<<endl;

	/*Check if the number entered is too big or too small.  This could get lengthy*/

	if (number.length()>10){
		cout<<"The number you entered is too big!  Please enter another number"<<endl;
		return 0;
	}
	else if (number.length()==10){
		for (int i = 0; i<number.length();i++){
			int testNumber = number[i];
			int testIntMax = intmax[i];
			if (testNumber>testIntMax){
				cout<<"The number you entered is too big! Please enter another number"<<endl;
				return 0;
			}
		}
	}
	int numero = atoi(number.c_str());
	return numero;
}

/*Wooo!  Now that our number is in the approved range, and also a number, we'll convert it to binary*/

int binary(int numero){
	int array [32]={};
	int j = 0;
	while (numero>0){
		array[j]=numero%2;
		numero = numero/2;
		/*cout<<array[j]<<endl;*/
		j++;
	}
	j = j-1;
	cout<<"Your number in binary is: ";	
	for(j;j>=0;j--){
		cout<<array[j];
	}
	cout<<endl;
	return 0;
}

/*Awesome!  Now that our number is in binary, we'll move on to the next part of the assignment: Determining when a loss of precision happens*/

int checkFloatPrecision(){
	/*Declaring more variables.*/
	long double userNumber1;
	long double userPrecision;
	/*First we'll find how many iterations it takes to lose precision within tolerance for floats*/

	cout<<"Now for part two of the assignment!  Please enter a float: "<<endl;
	cin>>userNumber1;
	cout<<"How precise do you want your float to be?  Please enter the tolerance for how imprecise it can be (ie. to within .00001): "<<endl;
	cin>>userPrecision;
	int k = 0;
	float testCase = userNumber1;
	while((fabs(testCase-userNumber1))<userPrecision){
		userNumber1 = userNumber1-.01;
		testCase = testCase-.01;
		k++;
	}
	cout<<"It took "<<k<<" iterations to lose precision within tolerance."<<endl;	
	return k;
}

/*And now we'll do the same for doubles*/

int checkDoublePrecision(){
	long double userNumber2;	
	long double userPrecision2;
	cout<<"Please enter a double (or any number, in case you aren't familiar with what a double is!): "<<endl;
	cin>>userNumber2;
	cout<<"How precise do you want your double to be? "<<endl;
	cin>>userPrecision2;
	int i = 0;
	double testCase2 = userNumber2;
	while((fabs(testCase2-userNumber2))<userPrecision2){
		userNumber2 -= .01;
		testCase2 -= .01;
		i++;
	}
	cout<<"It took "<<i<<" iterations to lose precision within tolerance."<<endl;
	return i;
}
int main(){
	int numero = checkNumber();
	binary (numero);
	checkFloatPrecision();
	checkDoublePrecision();
	return 0;
}
