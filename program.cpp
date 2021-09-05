#include <iostream>
using namespace std;

void print(int n, int *ar);

int main(){
    int n, r, c, *ptr;
    cout<<"Enter order of the required magic square : ";
    cin>>n;
    int Magic_Square[n][n];

/*
**For some reason Magic_Square[n][n] = {0}; was leaving some elements as unset(garbage value),
**so I've manually set every element as 0
*/
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n; j++)
            Magic_Square[i][j] = 0;

    r = n/2; c = n-1;
    
    for(int i = 1; i <= n*n; i++){
        Magic_Square[r][c] = i;
        r -= 1;
        c += 1;

        wrapAround:
            if(-1 == r && n == c){
                r = 0; 
                c = n-2;
            }
            else if ( -1 == r)
                r = n-1;
            else if (n == c)
                c = 0;
            if(Magic_Square[r][c]){
                r += 1;
                c -= 2;
                goto wrapAround;
            }
    }
    print(n, (int*)Magic_Square);

}

void print(int n, int *ar){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<*((ar+i*n) + j)<<" ";
        cout<<endl;
    }
}