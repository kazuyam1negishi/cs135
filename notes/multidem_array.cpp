#include <iostream>
#include <cstdlib>
using namespace std;

const int MINIMUM_VALUE = 1;
const int MAXIMUM_VALUE = 100;
int grid[5][10][8];

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 8; k++){
                grid[i][j][k] = 0;
            }
        }
    }
}
