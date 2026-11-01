#include <iostream>
#include <string>
using namespace std;

class Boligrafo{
	private:
		int tinta;
		std::string color;
	public:
		Boligrafo();
		string getColor();
		int getTinta();
		void setColor(string color);
		void escribir(int unidades);
		void recargar(int unidades);
		void mostrarEstados();

};
Boligrafo::Boligrafo(){
	tinta=100;
	color="AZUL";
};
string Boligrafo::getColor(){	
	return color;
}	
int Boligrafo::getTinta(){
	return tinta;
}
void Boligrafo::setColor(string ncolor){
	color=ncolor;
}
void Boligrafo::escribir(int unidades){
	if(unidades<=0){
		cout << "La cantidad ha gastar debe ser mayor a cero.";
	}else if(unidades<tinta){
		tinta=tinta-unidades;
		cout << "Se ha utilizado "<< unidades << " unidades de tinta.";
	}
	else{
		cout << endl << "La cantidad de tinta ha gastar es mayor a la que le queda al boligrafo"<<endl;
	}
}	
void Boligrafo::recargar(int unidades){
	if(unidades<=0){
		cout << "La cantidad ha recargar debe ser mayor a cero.";
	}
	cout << "Ingrese la cantidad de tinta a recargar: ";cin >>unidades;cout<<endl;
	tinta=tinta+unidades;
	if(tinta>100){
	tinta=100;
	}
}
void Boligrafo::mostrarEstados(){
	cout << "la cantidad de tinta restante es: "<< tinta<<endl;
	cout << "el color de la tinta es: " << color<<endl;
}
int main(){
	Boligrafo pilot;
	int tin,recarga,c,u,cen=1;
	string col;
	while(cen==1){
	cout << "Que desea hacer?: "<<endl<<"  1.Ver la tinta restante"<<endl<<"  2.Ver el color de la tinta"<<endl<<"  3.Cambiar el color de la tinta"<<endl<<"  4.Gastar la tinta"<<endl<<"  5.Recargar la tinta"<<endl<<"  6.Mostrar estados"<<endl<<"  0.Salir"<<endl;
	cin >> c;
	switch(c){
		case 0:
			cen=0;
			break;
		case 1:
			cout <<"Queda "<<pilot.getTinta()<<"/100 de tinta"<< endl;
			break;
		case 2:
			cout <<"El color del boligrafo es "<< pilot.getColor()<<endl;
			break;
		case 3:
			cout << "Ingrese el nuevo color del boligrafo: ";
			cin>> col;
			pilot.setColor(col);
			break;
		case 4:
			cout << "Ingrese la cantidad de tinta ha gastar: ";
			cin >> u;
			cout << endl;
			pilot.escribir(u);
			break;
		case 5:
			cout << "Ingrese la cantidad que desa recargar: ";
			cin >> u;
			pilot.recargar(u);
			break;
		case 6:
			pilot.mostrarEstados();
			break;
		default:
			cout << "Opcion no valida.";
			break;
	}
	}
}
