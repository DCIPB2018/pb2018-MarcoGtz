/*Este programa evalua un valor x con las funciones exp, log, sin, cos y sqrt en un intervalo y espaciado dado por el usuario.
Programa hecho el 03/09/2018 por Marco Gutiérrez.*/
#include<stdio.h>
#include<math.h>

int main()
{
	float x,i,a,b; //i=contador a=intervalo b=espaciado

	printf("Dime desde que número comienzo a evaluar:\n");
	scanf("%f",&x);
	printf("Dime hasta que número termino de evaluar:\n");
	scanf("%f",&a);
	printf("Dime el espaciado que hay entre cada numero del intervalo:\n");
	scanf("%f",&b);

	for(i=x; i<=a; i+=b)
	{
	printf("\nNúmero evaluado: %f\n\n",i);
	x=exp(i);
	printf("Exponencial:\t%f\n",x);
	x=log(i);
	printf("Logaritmo:\t%f\n",x);
	x=sin(i);
	printf("Seno:\t\t%f\n",x);
	x=cos(i);
	printf("Coseno:\t\t%f\n",x);
	x=sqrt(i);
	printf("Raíz cuadrada:\t%f\n\n",x);
	}

	return 0;
}
