#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct pueblo{
	string nom;
	int puntuacion = (rand() % 100);
};

vector <string> v {"Barcelona", "Lleida", "Girona", "Tarragona", "Aragon", "Madrid", "Avila", "Vitoria", "Cantabria", "Mérida", "Mallorca", "Menorca", "Castellon", "Blanes"};
vector <pueblo> p;


void reordena(int a){

	for(int i = a; i<p.size(); i++){
		p[i] = p[i+1];
	}
	p.pop_back();
}


void calculapobles(int &a,int &b){
	int newa = rand() % p.size();
	int newb = rand() % p.size();
	if (newa == newb) calculapobles(a,b);
	else {
		a = newa;
		b = newb;
	}
}

int fesbatalla( int a, int b){


	bool Guanyador1 = (rand() % 100) < p[a].puntuacion;
	bool Guanyador2 = (rand() % 100) < p[b].puntuacion;

	if((p[a].puntuacion!=100 and p[b].puntuacion!=100)){
		if((Guanyador2 and Guanyador1) or (a == b)){
			fesbatalla(a,b);
		}
		else if(Guanyador1 or Guanyador2){
			cout<<endl<<"BATALLA: "<<p[a].nom<<" VS "<<p[b].nom<<endl;
			if(Guanyador1) {
				p[a].puntuacion++;
				cout<<"GANADOR: "<<p[a].nom<<" Con "<<p[a].puntuacion<<" puntos"<<endl; 
				reordena(b);
				return a;
			}
			p[b].puntuacion++;
			cout<<"GANADOR: "<<p[b].nom<<" Con "<<p[b].puntuacion<<"  puntos"<<endl; 
			reordena(a);
			return b;
		}
	}


}


int main(){
	srand(time(NULL));


//Declaraciones de los pueblos
	for(int i = 0; i<v.size(); i++){ //Numero de pueblos
		pueblo pu;
		pu.nom = v[i];
		p.push_back(pu);
	}
	cout<<endl;
	cout<<"Los pueblos Participantes en la batalla con sus respectivos puntos iniciales son: ";
	for(int i = 0; i<p.size(); i++){
		cout<<p[i].nom<<" "<<p[i].puntuacion<<"   ";
	}
	cout<<endl<<endl;



//Guerra


	while(p.size()!=1){

	int a,b;
	calculapobles(a,b);
	fesbatalla(a,b);
	}
	cout<<"GANADOR: "<<p[0].nom<<endl;


}
