#include<bits/stdc++.h>
using namespace std;
#define CONDITION_1 input[i][j] > input[i-1][j] && input[i][j] > input[i][j-1]
#define CONDITION_2 input[i][j] > input[i][j+1] && input[i][j] > input[i+1][j]

int main(){

    int n;
    char input[101][101];

    cin >> n;
    for(int i = 0; i < n; i++){
 for(int j = 0; j < n; j++){
    cin >> input[i][j];
 }
    }
    for(int i = 1; i < n-1; i++){
 for(int j = 1; j < n-1; j++){
     if(CONDITION_1 && CONDITION_2){
  input[i][j] = 'X';
     }
 }
    }
    for(int i = 0; i < n; i++){
 for(int j = 0; j < n; j++)cout << input[i][j];
 cout << endl;
    }
    return 0;
}