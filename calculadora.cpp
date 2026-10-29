#include <iostream>
using namespace std;

class Calculadora {
	private:
		int primero;
		int segundo;
	    int comprobar();
	public:
		Calculadora();		
		void setNumeros(int a,int b);
		int getPrimero();
		int getSegundo();
		int sumar();
		int restar();
		int multiplicar();
		void dividir();
};
Calculadora::Calculadora(){
	primero=0;
	segundo=0;
}
int Calculadora ::comprobar(){
	if(segundo==0){
		return 0;
	}
	else{
		return 1;
	}
}
void Calculadora :: setNumeros(int a,int b){
	primero=a;
	segundo=b;
}
int Calculadora :: getPrimero(){
	return primero;
}
int Calculadora :: getSegundo(){
	return segundo;
}
int Calculadora :: sumar(){
	return primero+segundo;
}
int Calculadora :: restar(){
	return primero-segundo;
}
int Calculadora :: multiplicar(){
	return primero*segundo;
}
void Calculadora :: dividir(){
	if (comprobar()==1){
		cout << primero/segundo;
	}
	else{
		cout << "No se puede efctuar la division porque el divisor es igual a cero";
	}
}
 
int main(){
	Calculadora casio;
	int r,n,c,cen=1;
	cout<<"Ingresa los dos numeros:"<<endl;
	cin >> r >> n;
	casio.setNumeros(r,n);
	while(cen==1){
		cout << "Que quieres hacer?"<<endl;
		cout << "1.Sumar" <<endl<< "2.Restar" <<endl<< "3.Multiplicar"<<endl<<"4.Dividir"<<endl<<"5.Cambiar Numeros"<<endl;
		cin >> c;
		cout << endl;
		switch(c){
			case 1:
				cout << casio.sumar();
				break;
			case 2:
				cout << casio.restar();
				break;
			case 3:
				cout << casio.multiplicar();
				break;
			case 4:
				casio.dividir();
				break;
			case 5:
				cout<<"Ingresa los dos numeros:"<< endl;
				cin >> r >> n;
				casio.setNumeros(r,n);
				break;
		}
		cout <<endl<< "Deseas continuar SI/NO: (0/1)"<< endl;
		cin >> cen;
	}
	return 0;
}


