// Sss.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include <vector>
#define PI 3.14159265
#include <math.h>



class Point {
public:
	double x, y, z, vl, va;

	Point(double x, double y, double z, double vl, double va) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->vl = vl;
		this->va = va;

	};
};




int main(int argc, char* argv[]) {

	int np, nh, j, d;
	double tmin, tmax, t, zmin, zmax;
	double xf, yf;s
	double zf;
	double cx=0;
	double cz=0;
	double cy=45*PI/180;
	np = 3;
	nh = 3;
	d = 2;
	tmin = -45 * (PI / 180);
	tmax = 45 * (PI / 180);
	zmin = -45 * (PI / 180);
	zmax = 45 * (PI / 180);
	Point p(0, 0, 0, 0, 0);
	Point v[4][4] = { {p,p,p,p},{p,p,p,p},{p,p,p,p},{p,p,p,p} };
	//std::vector < std::vector <Point> > vt;
	//std::vector<double> X;
	//std::vector<double> Y;
	double tmp = 2;

	int i = 0;
	j = 0;


	for (i = 0; i <= np - 1; i++)
	{
	

       for(j=0;j<1;j++)
		{
		  printf("Le point initial : Position x: %f , Position y: %f, L'angle: %f  test\n", cx, cy, cz);
		


		
				t = tmin + (((tmax - tmin) * i) / (np - 1));
				
				xf = cx + d * (cos((t + cz)));
				yf = cy + d* (sin((t + cz)));
				zf = cz + zmin + (zmax - zmin)*j +t;
				v[i][j].x = xf;
				v[i][j].y = yf;
				v[i][j].z = zf;
				v[i][j].vl = 0;
				v[i][j].va = 0;

			




			//X[j] = xf;
			//Y[j] = yf;
			printf("Position x: %f , Position y: %f, L'angle: %f", v[i][j].x, v[i][j].y, v[i][j].z);
			printf("\n");

	}
		printf("\n");
	}
	double disl, disa;
	disl = 0;
	disa;
	printf("Resultat avec les vitesses\n");

	for (i = 0; i <= np - 1; i++)
	{
		for (j = 0; j < 1; j++)
		{
			if (j < nh)
			{
				disl = sqrt(pow((v[i][j + 1].x - v[i][j].x), 2) + pow((v[i][j + 1].y - v[i][j].y), 2));
				v[i][j].vl = disl / tmp;
				disa = (v[i][j + 1].z - v[i][j].z);
				v[i][j].va = disa / tmp;
			}
			else
			{

				v[i][j].vl = 0;

				v[i][j].va = 0;
			}

			printf("Position x: %f , Position y: %f, L'angle: %f,La vitesse Angulaire: %f, La vitesse Lineaire: %f", v[i][j].x, v[i][j].y, v[i][j].z, v[i][j].va, v[i][j].vl);
			printf("\n");


		}


		printf("\n");

	}



	printf("Position x: %f , Position y: %f, L'angle: %f,La vitesse Angulaire: %f, La vitesse Lineaire: %f", v[0][0].x, v[0][0].y, v[0][0].z, v[0][0].va, v[0][0].vl);
	printf("\n");










	return 0;
}













