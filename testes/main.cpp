#include<iostream>
#include<string>
#include<math.h>
#include"Triangulo.hpp"
#include"Retangulo.hpp"
#include"Circunferencia.hpp"

using namespace std;

int main()
{
	cout << "- TESTE TRIÂNGULOS - "<< endl <<endl;
	Triangulo t1;
	t1.p[0].atribuir(0,14);
	t1.p[1].atribuir(0,9);
	t1.p[2].atribuir(2,7);
	cout << "TRINGÂNGULO 1" << endl;
	cout << "O valor do perímetro : "<< t1.perimetro() << endl;
	cout << "O valor da área: " << t1.area() << endl;
	if(t1.equilatero() == true)
		cout << "O triângulo é equilátero" << endl;
	else
		cout << "O triângulo não é equilátero" << endl;
	cout << endl;

	Triangulo t2;
	t2.p[0].atribuir(0,28);
	t2.p[1].atribuir(0,18);
	t2.p[2].atribuir(4,14);
	cout << "TRINGÂNGULO 2" << endl;
	cout << "O valor do perímetro : "<< t2.perimetro() << endl;
	cout << "O valor da área: " << t2.area() << endl;
	if(t2.equilatero() == true)
		cout << "O triângulo é equilátero" << endl;
	else
		cout << "O triângulo não é equilátero" << endl;
	cout << endl;

	Triangulo t3;
	t3.p[0].atribuir(0,0);
	t3.p[1].atribuir(2,0);
	t3.p[2].atribuir(1,sqrt(3));
	cout << "TRINGÂNGULO 3" << endl;
	cout << "O valor do perímetro : "<< t3.perimetro() << endl;
	cout << "O valor da área: " << t3.area() << endl;
	if(t3.equilatero() == true)
		cout << "O triângulo é equilátero" << endl;
	else
		cout << "O triângulo não é equilátero" << endl;
	cout << endl;
	

	if(t1.semelhante(t2) == true)
		cout << "Os triângulos 1 e 2 são semelhantes" << endl;
	else
		cout << "Os triângulos 1 e 2 não são semelhantes" << endl;

	if(t1.semelhante(t3) == true)
		cout << "Os triângulos 1 e 3 são semelhantes" << endl;
	else
		cout << "Os triângulos 1 e 3 não são semelhantes" << endl;


	// ///////////////////////////////////////////////////// // 

	cout << "- TESTE RETÂNGULOS - "<< endl <<endl;
	Retangulo r1;
	r1.p[0].atribuir(0,0);
	r1.p[1].atribuir(1,0);
	r1.p[2].atribuir(1,1);
	r1.p[3].atribuir(0,1);
	cout << "RETÂNGULO 1"<< endl;
	cout << "O valor do perímetro é: " << r1.perimetro() << endl;
	cout << "O valor da área é: " << r1.area() << endl; 
	if(r1.quadrado() == true)
		cout << "O retângulo é quadrado"<< endl;
	else
		cout << "O retângulo não é quadrado"<< endl;

	Retangulo r2;
	r2.p[0].atribuir(0,0);
	r2.p[1].atribuir(3,0);
	r2.p[2].atribuir(3,10);
	r2.p[3].atribuir(0,10);
	cout << "RETÂNGULO 2"<< endl;
	cout << "O valor do perímetro é: " << r2.perimetro() << endl;
	cout << "O valor da área é: " << r2.area() << endl; 
	if(r2.quadrado() == true)
		cout << "O retângulo é quadrado"<< endl;
	else
		cout << "O retângulo não é quadrado"<< endl;


	Retangulo r3;
	r3.p[0].atribuir(0,0);
	r3.p[1].atribuir(3,0);
	r3.p[2].atribuir(1,7);
	r3.p[3].atribuir(0,10);
	cout << "RETÂNGULO 3"<< endl;
	cout << "O valor do perímetro é: " << r3.perimetro() << endl;
	cout << "O valor da área é: " << r3.area() << endl; 
	if(r3.quadrado() == true)
		cout << "O retângulo é quadrado"<< endl;
	else
		cout << "O retângulo não é quadrado"<< endl;


	// //////////////////////////////////////////////// //

	cout << "- TESTE CIRCUNFERENCIA - "<<endl;
	Circunferencia c1;
	Ponto ponto1;
	Ponto ponto2;
	ponto1.atribuir(0.5,0);
	ponto2.atribuir(-sqrt(2)/2,0);
	c1.p[0].atribuir(0,0);
	c1.p[1].atribuir((sqrt(2))/2,0);
	cout << "CIRCUNFÊRENCIA 1" << endl;
	cout << "O valor do perímetro é: " << c1.perimetro() << endl;
	cout << "O valor da area é: " << c1.area() << endl;
	if(c1.contem(ponto1) == true)
		cout << "O ponto (0.5,0) pertence à circunferência" << endl;
	else	
		cout << "O ponto (0.5,0) não pertence à circunferência" << endl;
	if(c1.contem(r1) == true)
		cout << "O retângulo 1 pertence à circunferência" << endl;
	else	
		cout << "O retângulo 1 não pertence à circunferência" << endl;
	if(c1.contem(t1) == true)
		cout << "O triângulo 1 pertence à circunferência" << endl;
	else	
		cout << "O triângulo 1 não pertence à circunferência" << endl;
	if(c1.pertence(ponto2) == true)
		cout << "O ponto (-sqrt(2)/2,0) pertence à circunferência" << endl;
	else
		cout << "O ponto (-sqrt(2)/2,0) não pertence à circunferência" << endl;	
	if(c1.circunscrita(t1) == true)
		cout << "O triângulo 1 circunscreve à circunferência" << endl;
	else	
		cout << "O triângulo 1 não circunscreve à circunferência" << endl;
	if(c1.circunscrita(r1) == true)
		cout << "O retângulo 1 circunscreve à circunferência" << endl;
	else	
		cout << "O retângulo 1 não circunscreve à circunferência" << endl;

	





}