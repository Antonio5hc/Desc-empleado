/* Programa elaborado por Herberth Antonio Portillo Cuz PC18022

se usan las librerias principales*/
#include<iostream>
#include <iomanip>

// Para ahorrar tiempo al proramar
using namespace std; 

//Estructura para definir la cantidad de empleados
struct Empleados{
	char cod[5];
	char nombre[50];
	int edad;
	float salbase;
	float salliquido;
	float afp;
	float isss;
	float renta;
	float totalprestamo;
	char departamento[60];
	char puesto;
	
};

//estructura de las sucursal 
struct Sucursal{
	int numsucursal;
	char nombresucural[60];
};

// Funcion paara calcular ISSS
float calisss(float sal, float tope) {
	float isss = 0;
	
	isss = sal * 0.03;
	return isss;

}

// FFuncion para calcular la AFP
float calAfp(float sal, float tope){
	float afp;
	
	afp = sal * 0.0625;
	return afp;
	
}

// Funcion para calcular la renta
float calRenta (float sal, float isss, float afp, float renta){
	float res;
	float pors;
	float resf; 
	
	//condicion 1 para calculo de la renta
	if (renta > 0.01 && renta <= 472){
		
		return renta;
	}
	//condicion 2 para calculo de la renta
	if (renta > 472.01 && renta <= 895.24){
	
		resf = ((renta - 472) * 0.1) + 17.67; ; 
		
		return resf;
	} 
	
	//condicion 2 para calculo de la renta
	else if (renta > 895.25 && renta <= 2098.10){
		resf = ((renta - 895.24) * 0.2 )+ 60.00;
		
		return resf;
	} 
	
	//condicion 2 para calculo de la renta
	else if (renta > 2038.11 ){
		resf = ((renta - 2038.10) * 0.3 )+ 288.57;
		
		return resf;
	} 
}


int main(){
	int n;
	float sf;
	float renta;
	
	system("color 2B");
	
	//ciclo para ingresar la cantidad de empleados
	do{
	cin.clear();
	system("cls");
	cin.ignore(1000,'\n');
	cout<<"Cuantos empleados tiene: "; cin>>n;
	} while (n <= 0 || cin.fail());
	
	Empleados e[n];
	Sucursal s[2];
	
	system("cls");
	
//Operador para volver a mostrar los datos segun la cantidad de empleados introducidos
	for (int i=0; i<n; i++){
	cout<< "     EMPLEADO"<<i+1<<endl;
	cout<<"cod: "; cin>>e[i].cod;
	cout<<"nombre:  "; cin>>e[i].nombre;
	cout<<"edad "; cin>>e[i].edad;	
	cout<<" Salbase: "; cin>>e[i].salbase;
	e[i].isss = calisss(e[i].salbase,0.03);
	e[i].afp = calAfp (e[i].salbase,7.25);
	renta = e[i].salbase - ( e[i].isss + e[i].afp);
	cout<<endl<<endl;
}

	system("pause");
	system("cls");
	
	cout<<"\n  RESULTADOS \n";

// Ciclo for para mostrar los resultados
	for (int i=0; i<n; i++){
	cout<<"cod: "<<e[i].cod<<endl;
	cout<<"nombre : "<<e[i].nombre<<endl;
	cout<<"edad : "<<e[i].edad<<endl;
	cout<<"Salbase: "<<e[i].salbase<<endl;
	cout<<"ISSS: "<<e[i].isss<<endl;
	cout<< "AFP: "<<e[i].afp<<endl;
	cout<<"Salario -(isss+afp): "<<renta<<endl;
	if (renta > 0.01 && renta <= 472){
		cout<<"No se aplica renta..."<<endl;
	}
	
	else{
	e[i].renta = calRenta (e[i].salbase, e[i].afp, e[i].isss, renta);
	cout<<"Renta: "<<e[i].renta<<endl;
	sf = e[i].salbase - e[i].renta;
	cout<<"Salario - (renta): "<<sf<<endl;
	}
	
	cout<<"\n\n";
}


	return 0;//no retorna
}
