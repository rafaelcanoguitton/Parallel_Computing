
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    //imprimiendo filas y columnas
    int n=10;
    int m=12;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++){
            cout << "*";
            cout<< endl;
            cout<< "Para celda: "<< i << "," << j << endl;
            cout<<"Se suma celda :"<<i-1<<","<<j<<endl;
            cout<<"Con: "<<i-1<<","<<j-1<<endl;
        }
            //a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
    
}