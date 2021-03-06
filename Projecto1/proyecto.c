#include<stdio.h>
#include<math.h>

int main()
{
    //Declacion de variables
	FILE *fp;
	int i;
	double x[9],y[9],z[9],vx[9],vy[9],vz[9];
	double xi,yi,zi,vxi,vyi,vzi;
	double Msol,G,r,j,f[9],h[9];
	
    //Escaneo de datos
	fp=fopen("Planetas.txt","r");
	for(i=0;i<9;i++)
	{
	fscanf(fp,"%lf %lf %lf %lf %lf %lf",&x[i],&y[i],&z[i],&vx[i],&vy[i],&vz[i]);
	x[i]=x[i]*365.242;
	y[i]=y[i]*365.242;
	z[i]=z[i]*365.242;
	vx[i]=vx[i]*365.242;
	vy[i]=vy[i]*365.242;
	vz[i]=vz[i]*365.242;
	fscanf(fp,"%lf %lf",&f[i],&h[i]);
	}
	fscanf(fp,"%lf",&Msol);
	fclose(fp);

    //Operaciones e impresion de datos
	G=4.0*3.1416*3.1416;
	for(i=0;i<9;i++)
	{
		switch(i)
		{
		case 0: fp=fopen("mercurio.txt","w");
			break;
		case 1: fp=fopen("venus.txt","w");
			break;
		case 2: fp=fopen("tierra.txt","w");
			break;
		case 3: fp=fopen("marte.txt","w");
			break;
		case 4: fp=fopen("jupiter.txt","w");
			break;
		case 5: fp=fopen("saturno.txt","w");
			break;
		case 6: fp=fopen("urano.txt","w");
			break;
		case 7: fp=fopen("neptuno.txt","w");
			break;
		case 8: fp=fopen("pluton.txt","w");
			break;
		}
		
		fprintf(fp,"Posición\t\t\t\tVelocidad\n");
		fprintf(fp,"%lf %lf %lf %lf %lf %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);

		for(j=0;j<f[i];j+=h[i])
		{
		r=sqrt(pow(x[i],2)+pow(y[i],2)+pow(z[i],2));
		xi=x[i]+vx[i]*h[i];
		yi=y[i]+vy[i]*h[i];
		zi=z[i]+vz[i]*h[i];
		vxi=vx[i]-(h[i]*G*Msol*x[i]/pow(r,3));
		vyi=vy[i]-(h[i]*G*Msol*y[i]/pow(r,3));
		vzi=vz[i]-(h[i]*G*Msol*z[i]/pow(r,3));
		
		fprintf(fp,"%lf %lf %lf %lf %lf %lf\n",xi,yi,zi,vxi,vyi,vzi);

		x[i]=xi;
		y[i]=yi;
		z[i]=zi;
		vx[i]=vxi;
		vy[i]=vyi;
		vz[i]=vzi;
		}

		fclose(fp);
	}

return 0;
}
