#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

class sudoku{
public:
    void getFile(); //Nos abrira el archivo
    void refractor(); //El sudoku como strings nos lo convertira a ints cambiara los '-' por 0 y los espacios los eliminara
    bool findCeros(int &row, int &cols); //Checkeara en las posiciones [x][y] donde hay 0,
    bool possibleCol(int col,int n); //Devolvera true si no se puede poner el numero ya que ya existe ese numero en esa columna
    bool possiblFil(int row,int n); //Devolvera true si no se puede poner el numero ya que ya existe ese numero en esa fila
    bool inBox(int startFil, int startCol, int num); //Nos ayudara a comprobar la caja que queremos comprobar
    bool findValid(int row, int col, int num);
    bool solve();//Funcion recursiva que nos generara los numeros entre 1 y 9 para asi ir comprabando todos y
    int getSize();
    int getValue(int i, int j);
private:
    vector<string> tablero;
    vector<vector<int>>Sudoku;
};

ostream &operator <<(ostream &os, sudoku &s);
istream &operator >>(istream &is, sudoku &s);
#endif // SUDOKU_H
