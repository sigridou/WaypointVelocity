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
	double xf, yf;
	double zf;
	double cx=0;
	double cz=45*PI/180;
	double cy=0;
	np = 4;
	
	d = 2;
	tmin = -45 * (PI / 180);
	tmax = 45 * (PI / 180);
	zmin = -45 * (PI / 180);
	zmax = 45 * (PI / 180);
	Point p(0, 0, 0, 0, 0);
	Point v[4][1] = { {p},{p},{p},{p} };
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
		


		
				t = (cz* i) / (np - 1);
				
				xf = cx + d * (cos((t + cz)));
				yf = cy + d* (sin((t + cz)));
				zf = cz +zmin + ((zmax - zmin) * 1) +t;
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
				disl = sqrt(pow((v[i][j].x - cx), 2) + pow((v[i][j].y - cy), 2));
				v[i][j].vl = disl / tmp;
				disa = (v[i][j].z - cz);
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













	return 0;
}













