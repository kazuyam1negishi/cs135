#include <iostream>
using namespace std;

int factorial(int n, int r){
	if(n == 0){
		return r;
	}
	return factorial(n-1, n*r);
}

int main(){
	factorial(5, 1);
	return(0);
}
