#include <iostream>
using namespace std;
class Reloj {
	private:
		int horas,minutos,segundos;
		int bateria;
		bool esHoraValida(int h, int m, int s){
     	   return (h >= 0 && h <= 23) && (m >= 0 && m <= 59) && (s >= 0 && s <= 59);
    	}
	public:
		Reloj(int h,int m,int s,int b){
			if(esHoraValida(h,m,s) && b>=0 && b<=100){
				horas=h;
				minutos=m;
				segundos=s;
				bateria=b;
			}
			else{
				horas=0;
				minutos=0;
				segundos=0;
				bateria=0;
			}
		}
		
		bool ajustarHora(int h, int m, int s){
			if(esHoraValida(h,m,s)){
				horas=h;
				minutos=m;
				segundos=s;
				return true;
			}
			else{
				return false;
			}
		}
		
		int getHoras(){
			return horas;
		}
		int getMinutos(){
			return minutos;
		}
		int getSegundos(){
			return segundos;
		}
		int getBateria(){
			return bateria;
		}
		
		void tic_tac(){
			if(estaParado()){
				return;
			}
			segundos++;
			if(segundos==60){
				minutos++;
				if(minutos==60){
					horas++;
					if(horas==24){
						horas=0;
					}
				}
			}
		}
		void avanza(int h, int m, int s){
			if(esHoraValida( h, m, s)){
				segundos=segundos+s;
				minutos=minutos+(segundos/60);
				horas=horas+(minutos/60);
				segundos=segundos%60;
				minutos=minutos%60;
				horas=horas%24;
			}
			else{
				cout<<"Hora no valida xd"<<endl;
			}
		}
		void atrasa(int h, int m, int s){
			if(esHoraValida(h,m,s)){
				if(segundos==0){
					minutos--;
					if(minutos==0){
						horas--;
					}
				}
				segundos=segundos-s;
				minutos=minutos-m;
				horas=horas-h;
			}
			else{
				cout<<"Hora no valida xd"<<endl;
			}
		}
		bool estaParado(){
			if(bateria==0){
				return true;
			}
			else{
				return false;
			}
		}
		void recargaBateria(int b){
			if(b==0 || b<0 || bateria+b>100){
				return;
			}
			else{
				bateria=bateria+b;
			}
		}
		
		void horaFormato12hrs();
		void horaFormato24hrs();
};
