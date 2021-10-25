#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sudoku.h>

using namespace std;

int main ()
{

    try {
        char op;
        int cond{0};
        sudoku su1;
        cin>>su1;
        cout<<su1;
        cout<<endl;

        if(su1.solve() == true){
            cout<<su1;
            return 0;
        }
        else
            cout<<"Sin solucion";
            while(cond==0){
                cout<<"Quieres volver a intentarlo S/N: ";
                cin>>op;
                if(su1.solve() == true){
                    cout<<su1;
                    cond = 1;
                }

            }

    }  catch (string x){
        cout << x << endl;
    }



}
