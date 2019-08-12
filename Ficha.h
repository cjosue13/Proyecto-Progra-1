#ifndef FICHA_H
#define FICHA_H
#include "Tablero.h"
#include<time.h>
class Ficha
{	
	
	int color;
	int X;
	int Y;
	int j_comodin;
	int i_comodin;
	public:
		Ficha();
		Ficha*ficha[10][10];
		bool Existe(int i, int j);
		int Tipo(int i,int j);
		int i_actual;
		int j_actual;
		void Convertir_Fichas(int i, int j,int x, int y);
		void Ficha_Negra(int x, int y);
		void Ficha_Blanca(int x, int y);
		void Ficha_Inicial();
		void jugador(int con);
		void comodin();
		void colocar_comodin(int i,int j, int n,int x, int y);
		void setI_J_comodin(int i, int j);
		int getI_comodin();
		int getJ_comodin();
		void Agregar_Ficha(int x, int y,int i, int j,int cont);
		bool poner_Ficha(int i, int j,int n);
		void Cambiar_Color(int x,int y,int i,int j);
		void setColor(int c);
		int getColor();
		void Puntaje();
		void setX(int x);
		void setY(int y);
		int getX();
		int getY();
		void Guardar();
		void Cargar();
		void Cargar_Ficha();
	protected:
};

#endif
