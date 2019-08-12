#include "Ficha.h"

Ficha::Ficha(){	
}
//Metodos set y Get
void Ficha::setColor(int c){
	color=c;
}
int Ficha::getColor(){
	return color;
}
void Ficha::setX(int x){
		X=x;	
		}
void Ficha::setY(int y){
		Y=y;
		}
		
int Ficha::getX(){
	return X;
}
int Ficha::getY(){
	return Y;
}
void Ficha::setI_J_comodin(int i, int j){
i_comodin=i;
j_comodin=j;
}
int Ficha::getI_comodin(){
	return i_comodin;
}
int Ficha::getJ_comodin(){
	return j_comodin;
}
//Metodos de juego u otros

bool Ficha::Existe(int i, int j){//Determina si existe ficha

return ((ficha[i][j]==NULL)?false : true);
	
}
int Ficha::Tipo(int i,int j){//Determina el tipo de ficha
	if(ficha[i][j]->getColor()==0){//Si la ficha es negra retorna 1
		return 1;
	}
	if(ficha[i][j]->getColor()==15){//Sino retorna 2
		return 2;
	}
}
void Ficha::jugador(int con){//Determina un punto verde al turno de cada jugador 
	if(con%2==0){//Ficha Blanca
	int r=5;//Determinamos el valor del radio 
	setcolor(BLACK);//dibujamos un punto negro en el lugar del jugador contrario 
	setlinestyle(0,0,2);
	while(r!=0){
	circle(593,183,r);
	r--;
		}
	setlinestyle(0,0,0);//Dibujamos el punto verde en el jugador actual
	r=5;
	setcolor(GREEN);
	setlinestyle(0,0,2);
	while(r!=0){
	circle(593,33,r);
	r--;
		}
	setlinestyle(0,0,0);
		
	}
	else{
		int r=5;
	setcolor(BLACK);
	setlinestyle(0,0,2);
	while(r!=0){
	circle(593,33,r);
		r--;
		}
	setlinestyle(0,0,0);
	r=5;
	setcolor(GREEN);													
	setlinestyle(0,0,2);
	while(r!=0){
	circle(593,183,r);
	r--;
				}
	setlinestyle(0,0,0);
	}
}		
void Ficha::Cambiar_Color(int x,int y,int i,int j){
		
		if(ficha[i][j]!=NULL){//Aseguramos que donde vamos a convertir ya existe una ficha 
			if(ficha[i][j]->getColor()==15){//Ficha Negra a ficha blanca
				delay(100);
				Ficha_Negra(x,y);
				ficha[i][j]->setColor(0);//Cambiamos el atributo de color a un color contrario
				
			}
			else{
				if(ficha[i][j]!=NULL){
				
				if(ficha[i][j]->getColor()==0){
				
				delay(100);
				Ficha_Blanca(x,y);
				ficha[i][j]->setColor(15);
				}
			}
			}
		}
	}
void Ficha::Ficha_Negra(int x, int y){//Creacion de la ficha Negra
	int  r=17;
	setcolor(0);
	setlinestyle(0,0,2);
	while(r!=0){
		circle(x,y,r);
			r--;
	}
		setlinestyle(0,0,0);
	
}
void Ficha::Ficha_Blanca(int x, int y){//Creacion de la ficha Blanca
int  r=17;
	setcolor(15);
	setlinestyle(0,0,2);
	while(r!=0){
		circle(x,y,r);
			r--;
	}
	r=17;
	setlinestyle(0,0,2);
	setcolor(0);
	circle(x,y,r);
	setcolor(0);
	setlinestyle(0,0,0);
	
}
void Ficha::Agregar_Ficha(int x, int y,int i ,int j, int cont){	
			if(cont%2==0 && Existe(i,j)==false){//Mos aseguramos que el contador sea par para poner la ficha blanca y preguntamos que no exista alguna ficha en esa posicion 
				ficha[i][j]=new Ficha();
				delay(100);
				ficha[i][j]->setColor(15);//Agregamos los atributos a esa ficha
				ficha[i][j]->setX(x);
				ficha[i][j]->setY(y);
				Ficha_Blanca(x,y);
				
			
			}
			if(cont%2!=0 && Existe(i,j)==false){
				ficha[i][j]=new Ficha();
				delay(100);
				ficha[i][j]->setColor(0);
				ficha[i][j]->setX(x);
				ficha[i][j]->setY(y);
				Ficha_Negra(x,y);
				
			}			
}

void Ficha::Ficha_Inicial(){	
	int x=331, y=251;
	int x1=371, y1=251;
	int x2=331, y2=291;
	int x3=371, y3=291;
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)
		{
			ficha[i][j]=NULL;
		}
						 }
					ficha[4][4]=new Ficha();			
					ficha[4][4]->setColor(15);
					ficha[4][4]->setX(x);
					ficha[4][4]->setY(y);
					Ficha_Blanca(x,y);								
					ficha[4][5]=new Ficha();
					ficha[4][5]->setColor(0);
					ficha[4][5]->setX(x2);
					ficha[4][5]->setY(y2);
					Ficha_Negra(x1,y1);
					
					ficha[5][4]=new Ficha();
					ficha[5][4]->setColor(0);
					ficha[5][4]->setX(x1);
					ficha[5][4]->setY(y1);
					Ficha_Negra(x2,y2);
				
					ficha[5][5]=new Ficha();
					ficha[5][5]->setColor(15);
					ficha[5][5]->setX(x3);
					ficha[5][5]->setY(y3);
					Ficha_Blanca(x3,y3);		
			
		
	
}
void Ficha::Puntaje(){
	int con=0,con1=0;//Contadores para cada jugador
	int suma=0;//Determina cuantas fichas hay en total 
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(ficha[i][j]!=NULL){
				if(ficha[i][j]->getColor()==0){//Cuento cuantas fichas tiene el jugador con color negro
					suma+=1;
					con++;
										}
						else{
							suma+=1;
							con1++;	
							}
							}
							
						}
					}
	
					if(suma==100){//Si el tablero esta lleno termina el juego y determina quien es el jugador ganador 
						if(con>con1){
							setbkcolor(0);
							setcolor(15);
							delay(200);
							outtextxy(590,250,"Ganador");
							outtextxy(590,100,"Perdedor");
						}
						else{
							setbkcolor(0);
							setcolor(15);
							delay(200);
							outtextxy(590,100,"Ganador");
							outtextxy(590,250,"Perdedor");
						}
					}
					else{
					if(con<10){//Conversion de int a char con la funcion itoa
						char cont[1];
						itoa(con,cont,10);
						setbkcolor(0);
						setcolor(15);
						outtextxy(635,250,"                  ");
						setbkcolor(0);
						setcolor(15);
						outtextxy(640,250,cont);
					}
				
					if(con>=10){//Si el puntaje es de dos digitos
						setbkcolor(0);
						setcolor(15);
						outtextxy(640,250,"             ");
						char cont[1];
						char cont1[1];
						int c=con/10;//Consigo el primer digito
						int s=con%10;//Consigo el segundo digito
						setbkcolor(0);
						setcolor(15);
						itoa(c,cont,10);
						outtextxy(630,250,cont);
						setbkcolor(0);
						setcolor(15);
						itoa(s,cont1,10);
						outtextxy(650,250,cont1);
						
					}
					
					if(con1<10){
						char cont[1];
						itoa(con1,cont,10);
						setbkcolor(0);
						setcolor(15);
						outtextxy(635,100,"                 ");
						setbkcolor(0);
						setcolor(15);
						outtextxy(640,100,cont);
					}
					if(con1>=10){
						setbkcolor(0);
						setcolor(15);
						outtextxy(640,100,"             ");
						char cont[1];
						char cont1[1];
						int c=con1/10;
						int s=con1%10;
						setbkcolor(0);
						setcolor(15);
						itoa(c,cont,10);
						outtextxy(630,100,cont);
						setbkcolor(0);
						setcolor(15);
						itoa(s,cont1,10);
						outtextxy(650,100,cont1);
						
					}
					
					}
					
}
bool Ficha::poner_Ficha(int i, int j,int n){
i_actual=i;
j_actual=j;
int o=20;
bool bandera=false;
//Horizontal hacia izquierda
for(int p=j_actual-1;p>=0;p--){
	if(p>=0)
	if(Existe(i,p)==true){
		if(Tipo(i,p)==n && p!=j_actual-1){
		for(int k=p+1;k<j_actual;k++){
			if(Tipo(i,k)==n){
				k=j_actual+1;
				o=k;
							}
		}p=-1;	
			if(o!=j_actual+1){
				bandera=true;
							 }
								  }
						 }
		else{
		p=-1;
			}
			o=20;
					   }//Cierre for
	if(bandera==true){
		return bandera;
					 }
									
	//Abro else
	else{
	//Vertical hacia arriba
for(int p=i_actual-1;p>=0;p--){
	if(p>=0)
	if(Existe(p,j)==true){
		if(Tipo(p,j)==n && p!=i_actual-1){
			for(int k=p+1;k<i_actual;k++){
			if(Tipo(k,j)==n){
				k=i_actual+1;
				o=k;
			}	
			}	p=-1;
			if(o!=i_actual+1){
			bandera=true;	
							 }
										 }						 								 
						 }
	else{
		p=-1;
		}
		o=20;					  }//Cierre for	
		}
	if(bandera==true){
		return bandera;
					 }
	//Abro else
	else{
		//vertical hacia abajo	
for(int p=i_actual+1;p<10;p++){
	if(p<10)
	if(Existe(p,j)==true){
		if(Tipo(p,j)==n && p!=i_actual+1){
		for(int k=p-1;k>i_actual;k--){
			if(Tipo(k,j)==n){
				k=i_actual-1;
				o=k;
			}
		}p=10;
		if(o!=i_actual-1){
		bandera=true;	
		}
									     }				 
						 }
	else{
		p=10;
		}
		o=20;					   }//Cierre for
		if(bandera==true){
			return bandera;
						 }
		//Abro Else				 
		else{
			//Horizontal hacia derecha	
for(int p=j_actual+1;p<10;p++){
	if(p<10)
	if(Existe(i,p)==true){
		if(Tipo(i,p)==n && p!=j_actual+1){
			for(int k=p-1;k>j_actual;k--){
				if(Tipo(i,k)==n){
				k=j_actual-1;
				o=k;
				}
			}p=10;
			if(o!=j_actual-1){
			bandera=true;	
			}
					            		}
					 }
	else{
		p=11;
		}
		o=20;					  }//Cierre for
		if(bandera==true){
			return bandera;
						 }
		//Abro Else
		else{
		//Diagonal hacia abajo derecha
int q=i_actual;
	for(int p=j_actual+1;p<10;p++){
		q=q+1;
		if(p<10 && q<10)
		if(Existe(q,p)==true){
			if(Tipo(q,p)==n && p!=j_actual+1 && q!=i_actual+1){
			for(int k=p-1;k>j_actual;k--){
				q=q-1;
				if(Tipo(q,k)==n){
					k=j_actual-1;
					o=k;
				}
			}p=10;
			if(o!=j_actual-1){
				bandera=true;
			}	
								    						  }				    						 			 
							 }
		else{
			p=10;
			}
			o=20;					  }//Cierre for
			if(bandera==true){
				return bandera;
						     }
			//Abro Else
			else{
				//Diagonal hacia arriba izquierda
int l=j_actual;
	for(int p=i_actual-1;p>=0;p--){
		l=l-1;
		if(p>=0 && l>=0)
		if(Existe(p,l)==true){
			if(Tipo(p,l)==n && p!=i_actual-1){
				for(int k=p+1;k<i_actual;k++){
					l=l+1;
					if(Tipo(k,l)==n){
						k=i_actual+1;
						o=k;
					}
				}p=-1;
				if(o!=i_actual+1){
				bandera=true;	
				}
															  }												  
							 }
		else{
			p=-1;
			}
			o=20;					  }//Cierre for
			if(bandera==true){
				return bandera;
							 }
			//Abro Else
			else{
				//Diagonal hacia abajo izquierda		
int s=j_actual;
for(int p=i_actual+1;p<10;p++){
	s=s-1;
	if(p<10 && s>=0)
	if(Existe(p,s)==true){
		if(Tipo(p,s)==n && p!=i_actual+1 && s!=j_actual-1){
			for(int k=p-1;k>i_actual;k--){
				s=s+1;
				if(Tipo(k,s)==n){
					k=i_actual-1;
					o=k;
				}
			}p=10;
			if(o!=i_actual-1){
				bandera=true;	
				}
			
														}															
						 }
	else{
		p=11;
		}
		o=20;					  }//Cierre for
		if(bandera==true){
			return bandera;
						 }
		//Abro Else
		else{
			
//Diagonal hacia arriba derecha
int m=i_actual;
for(int p=j_actual+1;p<10;p++){
	m=m-1;
	if(p<10 && m>=0)
	if(Existe(m,p)==true){
		if(Tipo(m,p)==n && p!=j_actual+1){
			for(int k=p-1;k>j_actual;k--){
				m=m+1;
				if(Tipo(m,k)==n){
					k=j_actual-1;
					o=k;
				}
			}
			p=10;
			if(o!=j_actual-1){
			bandera=true;	
			}
						    						      }				    						      
						 }
	else{
		p=11;
		}
			o=20;				   }
		if(bandera==true){
			return bandera;
						 }					   	
			}				 
				}				 					  
				}			     
			}//Cierro Else
							 	
			}				 					   
		}
		return bandera;				 	
}

void Ficha::Convertir_Fichas(int i, int j,int x, int y){
i_actual=i;
j_actual=j;
//Horizontal hacia izquierda
for(int p=j_actual-1;p>=0;p--){
	if(p>=0)
	if(Existe(i,p)==true){
		if(Tipo(i,p)==Tipo(i,j)){
			for(int k=p+1;k<j_actual;k++){
			Cambiar_Color(ficha[i][k]->getX(),ficha[i][k]->getY(),i,k);
			
			}
			p=-1;
		}
	}
	else{
		p=-1;
	}
}
//Vertical hacia arriba
for(int p=i_actual-1;p>=0;p--){
	if(p>=0)
	if(Existe(p,j)==true){
		if(Tipo(p,j)==Tipo(i,j)){
			for(int k=p+1;k<i_actual;k++){
			Cambiar_Color(ficha[k][j]->getX(),ficha[k][j]->getY(),k,j);
			}
			p=-1;
		}
	}
	else{
		p=-1;
	}
	}
//vertical hacia abajo	
for(int p=i_actual+1;p<10;p++){
	if(p<10)
	if(Existe(p,j)==true){
		if(Tipo(p,j)==Tipo(i,j)){
			for(int k=p-1;k>i_actual;k--){
			Cambiar_Color(ficha[k][j]->getX(),ficha[k][j]->getY(),k,j);
			}
			p=11;
		}
	}
	else{
		p=11;
	}
	}
//Horizontal hacia derecha	
for(int p=j_actual+1;p<10;p++){
	if(p<10)
	if(Existe(i,p)==true){
		if(Tipo(i,p)==Tipo(i,j)){
			for(int k=p-1;k>j_actual;k--){
			Cambiar_Color(ficha[i][k]->getX(),ficha[i][k]->getY(),i,k);
			}
			p=11;
		}
	}
	else{
		p=11;
	}
}

//Diagonal hacia abajo derecha
int q=i_actual;
	for(int p=j_actual+1;p<10;p++){
		q=q+1;
		if(p<10 && q<10)
		if(Existe(q,p)==true){
			if(Tipo(q,p)==Tipo(i,j)){
				for(int r=p-1;r>j_actual;r--){
					q=q-1;
				Cambiar_Color(ficha[q][r]->getX(),ficha[q][r]->getY(),q,r);	
				}
				p=11;
			}
		}
		else{
			p=11;
		}
		
}

//Diagonal hacia arriba izquierda
int l=j_actual;
	for(int p=i_actual-1;p>=0;p--){
		l=l-1;
		if(p>=0 && l>=0)
		if(Existe(p,l)==true){
			if(Tipo(p,l)==Tipo(i,j)){
				for(int r=p+1;r<i_actual;r++){
					l=l+1;
					Cambiar_Color(ficha[r][l]->getX(),ficha[r][l]->getY(),r,l);	
				}
				p=-1;
			}
		}
		else{
			p=-1;
		}
		}
//Diagonal hacia abajo izquierda		
int s=j_actual;
for(int p=i_actual+1;p<10;p++){
	s=s-1;
	if(p<10 && s>=0)
	if(Existe(p,s)==true){
		if(Tipo(p,s)==Tipo(i,j)){
			for(int r=p-1;r>i_actual;r--){
				s=s+1;
				Cambiar_Color(ficha[r][s]->getX(),ficha[r][s]->getY(),r,s);
			}
			p=11;
		}
	}
	else{
		p=11;
	}
}

//Diagonal hacia arriba derecha
int m=i_actual;
for(int p=j_actual+1;p<10;p++){
	m=m-1;
	if(p<10 && m>=0)
	if(Existe(m,p)==true){
		if(Tipo(m,p)==Tipo(i,j)){
			for(int r=p-1;r>j_actual;r--){
				m=m+1;
				Cambiar_Color(ficha[m][r]->getX(),ficha[m][r]->getY(),m,r);
			}
			p=11;
		}
	}
	else{
		p=11;
	}
}		
}
void Ficha::colocar_comodin(int i, int j,int n,int x,int y){
	if(n==1){//Ficha Negra											
		if(Existe(i,j)==true){//Si existe ficha
			if(Tipo(i,j)!=n){//Solo si es blanca convertimos
				Cambiar_Color(x,y,i,j);
									}
							  }
			else{//Si no existe Agregamos una ficha
				Agregar_Ficha(x,y,i,j,1);
										}
				}
		else{	
			if(Existe(i,j)==true){
				if(Tipo(i,j)!=n){
					Cambiar_Color(x,y,i,j);
										}
									}
				else{
					Agregar_Ficha(x,y,i,j,2);
										    }
											
												}
													
}
void Ficha::comodin(){
	srand(time(NULL));
	int i=rand()%10;//Creamos una variable i alazar para poner el comodin 
	int j=rand()%10;//Creamos una variable j
	if(Existe(i,j)==false){//La almacenamos solamente si en i o j no existe alguna ficha
		setI_J_comodin(i,j);
	}
	else{
		if(Existe(i,j)==true){//Si existe ya una ficha en esas posiciones llamamos denuevo al metodo
		comodin();
	}
	}
}


void Ficha::Guardar(){
	FILE *archivo;
	archivo = fopen("Guardar.txt","w+");	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			fwrite(ficha[i][j],sizeof(Ficha),1,archivo);
		}
		}
		fclose(archivo);
}
void Ficha::Cargar(){
FILE*archivo;
archivo=fopen("Guardar.txt","r");
for(int i=0;i<10;i++){
	for(int j=0;j<10;j++){
		Ficha*nuevo=new Ficha();
		fread(nuevo,sizeof(Ficha),1,archivo);
		ficha[i][j]=nuevo;
	}
}
fclose(archivo);
}
void Ficha::Cargar_Ficha(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(Existe(i,j)){
				cout<<ficha[i][j]->getX()<<endl;
				cout<<ficha[i][j]->getY()<<endl;
				cout<<i<<" "<<j<<endl;
				system("PAUSE");
				if(Tipo(i,j)==1){
					Ficha_Negra(ficha[i][j]->getX(),ficha[i][j]->getY());
				}
				if(Tipo(i,j)==2){
					Ficha_Blanca(ficha[i][j]->getX(),ficha[i][j]->getY());
				}
			}
		}
	}
}
