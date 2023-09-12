#include <iostream>
using namespace std;

// Good practice to use this!
const int ARRAY_SIZE = 10;

int main(){
    int array[ARRAY_SIZE];
    /* You can also initialize like this, but only
    if you don't use a constant.

    int array[] = {1,2,3,4,5,6,7,8,9,0}; */

    /*IMPORTANT!
    Make sure you don't modify your array outside
    of the range! You can change your vars or parts
    of your code, which can happen, for example, in
    the code below if you set the condition to a
    number higher than the constant size.
    */

    for(int i = 0; i < 10; i++){
        cout << "Array[" << i << "]: " << array[i] << endl;
    }
    cout << "End of program.";
}