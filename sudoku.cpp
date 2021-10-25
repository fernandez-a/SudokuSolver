#include "sudoku.h"

using namespace std;

void sudoku::getFile(){
    string archivo;
    cout<<"Introduce ruta del archivo SIN COMILLAS: ";
    getline(cin,archivo);
    string linea;
    ifstream fichero (archivo);
    if(fichero.fail()){
        throw string {"ERROR, el nombre del archivo no es correcto o no se ha encontrado."};
    }
    while (!fichero.eof())
    {
        getline(fichero,linea);
        {
            tablero.push_back(linea);
        }
    }
    fichero.close();
}

void sudoku::refractor(){
    for(int i{0}; i < tablero.size(); i++){
        for(int j{0}; j < tablero[i].size(); j++){
            if(tablero.at(i).at(j) == '-'){
                tablero[i][j] = '0';
            }
            else if(tablero.at(i).at(j) == '0' || 0){
                tablero[i][j] = '0';
            }
        }


    }
    for(int i{0}; i < tablero.size(); i++){
        vector<int> temp;
        for(int j{0}; j < tablero[i].size(); j++){
            if(tablero[i][j] == ' '){
                j++;
                char a = tablero[i][j];
                int ia = a - '0';
                temp.push_back(ia);
            }
            else {
                char b = tablero[i][j];
                int ib = b - '0';
                temp.push_back(ib);
            }

        }
        Sudoku.push_back(temp);
    }
}

bool sudoku::possibleCol(int col, int n){
    for(int row{0}; row < Sudoku.size(); row++){
        if (Sudoku[row][col] == n){
            return true;
        }
    }
    return false;
}

bool sudoku::possiblFil(int row, int n){
    for(int col{0}; col < Sudoku.size(); col++){
        if (Sudoku[row][col] == n){
            return true;
        }
    }
    return false;
}

bool sudoku::inBox(int startFil, int startCol, int num){
    for(int i{0}; i < 3; i++){
        for(int j{0}; j < 3; j++){
            if(Sudoku[i+startFil][j+startCol] == num){
                return true;
            }
        }
    }
    return false;
}

bool sudoku::findCeros(int &row, int &cols){
    for(row = 0; row < Sudoku.size(); row++){
        for(cols = 0; cols < Sudoku.size(); cols++){
            if(Sudoku[row][cols] == 0){
                return true;
            }
        }
    }
    return false;
}

bool sudoku::findValid(int row, int col, int num){
    return !possiblFil(row,num) && !possibleCol(col,num) && !inBox(row - row%3, col - col%3,num);
}

bool sudoku::solve(){
    int row,col;
    if(!findCeros(row,col)){
        return true;
    }
    for(int num = 1; num <= 9; num++){
        if(findValid(row,col,num)){
            Sudoku[row][col] = num;
            if(solve()){
                return true;
            }
            Sudoku[row][col] = 0;
        }
    }
    return false;
}

int sudoku::getSize(){
    int siz{0};
    for(int i{0}; i < Sudoku.size(); i++){
        siz++;
    }
    return siz;
}

int sudoku::getValue(int i, int j){
    return Sudoku[i][j];
}

ostream &operator <<(ostream &os, sudoku &s){
    for(int i{0}; i < s.getSize(); i++){
        for(int j{0}; j < s.getSize(); j++){
            if(j==3 || j== 6){
                os<<"| "<<s.getValue(i,j)<<" ";
            }
            else
                os <<" "<<s.getValue(i,j)<<" ";
        }
        if(i == 2 || i == 5){
            os<<endl;
            for(int i{0}; i < s.getSize();i++){
                os<<"---";
            }
        }
        os<<endl;
    }
    return os;
}

istream &operator >>(istream &is, sudoku &s){
    s.getFile();
    s.refractor();
    return is;
}
