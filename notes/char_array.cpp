#include <iostream>
using namespace std;

const int ARRAY_SIZE = 10;
const int STRING_LENGTH = 14;

int main(){
    char message[STRING_LENGTH] = "Hello, world!";
    for(int i = 0; i < STRING_LENGTH; i++){
        cout << static_cast<int>(message[i]) << endl;
    }
}