#ifndef TABLERO_H
#define TABLERO_H
#include<iostream>
#include<graphics.h>
#include <cstdio>
#include<conio.h>
#include<dos.h>
#include "Ficha.h"
using namespace std;

class Tablero
{

	public:
		Tablero();
		void crear_Tablero();
		int CoordenadasX[10][2];
		int setCoordenadasX(int i,int j, int n);
		int getCoordenadasX(int i, int j );
		int CoordenadasY[10][2];
		int setCoordenadasY(int i,int j, int n);
		int getCoordenadasY(int i, int j );
		void Mouse_en_Matriz(int n);
		void inicio();

	protected:
};

#endif
