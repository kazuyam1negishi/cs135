#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> vector2d;
    int width = 0;
    int height = 0;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;
    for(int i = 1; i <= height; i++){
        // Create new row to add to our 2D vector
        vector<int> newRow;
        for(int j = 1; j <= width; j++){
            newRow.push_back(i*j);
        }
        vector2d.push_back(newRow);
    }
}