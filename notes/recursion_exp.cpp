#include <iostream>
using namespace std;

// Main idea of recursion:
// A function calls itself, similar to a loop.
int factorial(int n){
	if(n == 0){
		return(1);
	}
	// This return statement makes this
	// a recurring function.
	return(n*factorial(n-1));
}

int main(){
	cout << factorial(5) << endl;
	return(0);
}
