#include "Tablero.h"
Tablero::Tablero()
{ 
}

void Tablero::crear_Tablero(){
	bar(9,500,178,532);
	setbkcolor(15);
	setcolor(0);
	outtextxy(16,502,"Pasar turno");
	bar(9,10,100,42);
	setbkcolor(15);
	setcolor(0);
	outtextxy(16,12,"Atras");//Creo botones de atras y guardar 
	bar(590,490,711,522);
	setbkcolor(15);
	setcolor(0);
	outtextxy(593,492,"Guardar");
	setcolor(15);
	setbkcolor(0);
	

	
	outtextxy(600,20,"Blancas");//Informacion de jugadores
	outtextxy(584,50,"Jugador 1");
	outtextxy(600,170,"Negras");
	outtextxy(584,200,"Jugador 2");
	int izq=150, arriba=70, abajo=110, derecha=190;
	int cont=0;	
	while(cont<10){
		for(int i=0;i<10;i++){
		setcolor(0);
		bar(izq,arriba,derecha, abajo);//Creo celda por celda con un tamano determinado
		rectangle(izq, arriba,derecha, abajo);
		
		setCoordenadasX(i,0,izq);//almaceno la cordenada menor de la celda X en una matriz 
		setCoordenadasX(i,1,derecha);//almaceno la cordenada mayor de la celda X en una matriz 
		izq+=40, derecha+=40;
			 		 	     }
		setCoordenadasY(cont,0,arriba);//almaceno la cordenada menor de la celda Y en una matriz 
		setCoordenadasY(cont,1,abajo);//almaceno la cordenada mayor de la celda Y en una matriz
			 		 	     
			arriba+=40, abajo+=40;
			izq=150, derecha=190;//Reseteo las coordenadas X
			cont++;
		
	}
	

}


int Tablero::setCoordenadasX(int i, int j, int n){
	CoordenadasX[i][j]=n;
}


int Tablero::getCoordenadasX(int i, int j){
return CoordenadasX[i][j];
}

int Tablero::setCoordenadasY(int i, int j, int n){
	CoordenadasY[i][j]=n;
}

int Tablero::getCoordenadasY(int i, int j){
return CoordenadasY[i][j];
}

void Tablero::Mouse_en_Matriz(int n){
	Ficha* f1=new Ficha();
		if(n==1){
		f1->Ficha_Inicial();//Creo las fichas iniciales		
		f1->comodin();//Coloco el comodin en lugar alazar de la matriz
		}
		else{
			f1->Cargar();
			f1->Cargar_Ficha();
		}
		
		f1->Puntaje();//Inicio el puntaje
		
	int cont=0;
while(!ismouseclick(WM_LBUTTONDOWN)){
f1->jugador(cont);//Define el turno de cada jugador y el contador define si es negra o blanca
 int x=0,y=0;
	delay(100);
	getmouseclick(WM_LBUTTONDOWN,x,y);
	if( y>=70 && y<=470 && x>=150 && x<=550 ){//Evalua que esta dentro del tablero
		for(int i=0;i<10;i++){
			if(x>=getCoordenadasX(i,0) && x<=getCoordenadasX(i,1))//Evalua si el mouse esta dentro de la matriz en las coordenadas X(Celda) 
			{
				for(int j=0;j<10;j++){
				if(y>=getCoordenadasY(j,0) && y<=getCoordenadasY(j,1)){//Evalua si el mouse esta dentro de la matriz en las coordenadas Y(Celda) 
					if(f1->Existe(i,j)==false){//Preguntamos si en esa posicion existe algo
						if(f1->getI_comodin()==i && f1->getJ_comodin()==j){//Preguntamos si al dar click en la matriz coincide con la ficha comodin
						for(int i2=i-1;i2<=i+1;i2++){
							for(int j2=j-1;j2<=j+1;j2++){
								if(i2>=0 && i2<10){//Evaluamos que no se salga de los limites de la matriz
									if(j2>=0 && j2<10){
									if(cont%2==0){//Si es par es una ficha Blanca
									x=getCoordenadasX(i2,0)+21;//Aumento en 21 las coordenadas x e y para centrar las fichas
									y=getCoordenadasY(j2,0)+21;
									f1->colocar_comodin(i2,j2,2,x,y);//Realiza la funcion del comodin
									}
									else{//Sino es Ficha Negra
									x=getCoordenadasX(i2,0)+21;
									y=getCoordenadasY(j2,0)+21;
									f1->colocar_comodin(i2,j2,1,x,y);
										}
											}
												}
													}
														}
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(120,17,"Encotraste la ficha comodin...");
									delay(1000);
									setbkcolor(BLACK);
									setcolor(BLACK);
									outtextxy(120,17,"Encotraste la ficha comodin...");
									cont++;	
									f1->Puntaje();			}
												
						else{
						for(int i2=i-1;i2<=i+1;i2++){
							for(int j2=j-1;j2<=j+1;j2++){
								if(i2>=0 && i2<10){
									if(j2>=0 && j2<10){
										if(f1->Existe(i2,j2)==true){//Preguntamos si existe fichas alrededor
											if(cont%2==0){//Ficha blanca
												if(f1->Tipo(i2,j2)==1){//Preguntamos si esa ficha es del color contrario
												if(f1->poner_Ficha(i,j,2)==true){//Validamos si podemos poner la ficha
													x=getCoordenadasX(i,0)+21;
													y=getCoordenadasY(j,0)+21;
													f1->Agregar_Ficha(x,y,i,j,cont);//Agrego la ficha en las posiciones del click
													f1->Convertir_Fichas(i,j,x,y);//Realizamos toda validacion para convertir fichas
													i2=i+2;//forzamos a salir del ciclo para evitar errores
													j2=j+2;
													cont++;//aumentamos el contador para determinar que sigue el siguiente jugador
													}
												}
											}
											else{
												if(f1->Tipo(i2,j2)==2){
													if(f1->poner_Ficha(i,j,1)==true){	
													x=getCoordenadasX(i,0)+21;
													y=getCoordenadasY(j,0)+21;
													f1->Agregar_Ficha(x,y,i,j,cont);
													f1->Convertir_Fichas(i,j,x,y);
													i2=i+2;
													j2=j+2;
													cont++;	
													}
													}
											}
								
									}
									}
								}
								
							}
						}
					
				}
					f1->Puntaje();
					
					}
					}
				}
			}
		}
	
								}
		if(x>=9 && y>=500 && x<=178 && y<=532){
			cont++;
		}						
		if(y>=10 && y<=42 && x>=9 && x<=100){//Boton de atras
			cleardevice();
			inicio();
		}
		
		if(y>=490 && y<=522 && x>=590 && x<=711)//Boton de guardar
			{
			
			f1->Guardar();
			cleardevice();
			inicio();
			
			}
								
}

}

void Tablero::inicio(){
	setcolor(15);//Creamos los botones al inicio del juego
	bar(270,100,460,150);
	bar(270,180,460,230);
	bar(270,260,460,310);
	setcolor(0);
	setbkcolor(15);
	settextstyle(6,0,3);
	outtextxy(325,110,"Jugar");
	outtextxy(273,190,"Cargar Juego");
	outtextxy(330,270,"Salir");
	setcolor(15);
	setbkcolor(0);
	outtextxy(312,50,"Othello");
	while(!ismouseclick(WM_LBUTTONDOWN)){

	int x,y;
	delay(100);
	getmouseclick(WM_LBUTTONDOWN,x,y);
	if(x>=270 && x<=460 && y>=100 && y<=150){//Inicio de Juego
		cleardevice();
		setbkcolor(0);
		Tablero *t=new Tablero();
		t->crear_Tablero();
		t->Mouse_en_Matriz(1);
		
	}
	if(x>=270 && x<=460 && y>=180 && y<=230){//Cargar
		cleardevice();
		setbkcolor(0);
		Ficha *f=new Ficha();
		Tablero *t=new Tablero();
		t->crear_Tablero();
		t->Mouse_en_Matriz(2);
	}
	if(x>=270 && x<=460 && y>=260 && y<=310){//Boton de salir
		closegraph();
	}
}

}



