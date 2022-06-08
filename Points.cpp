// Sss.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
 #include <ros/console.h>
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



ros::init(argc, argv, "Points");
        ros::NodeHandle nd;
        ros::Publisher talk_pub=nd.advertise<std_msgs::String>("very_important_message",100);
        ros::Rate loop_rate(1); //hz
        while(ros::ok())

{       loop_rate.sleep();

	int np, nh, j, d;
	double  t;
	double xf, yf;
	double zf;
	double cx=0;
	double cz=45*PI/180;
	double cy=0;
	np = 3;
	
	d = 2;

	Point p(0, 0, 0, 0, 0);
	Point v[4][1] = { {p},{p},{p},{p} };
	
	double tmp = 2;

	int i = 0;
	j = 0;


	for (i = 0; i <=( np - 1); i++)
	{
	

       for(j=0;j<1;j++)
		{
                   ROS_INFO("usage: add_two_ints_client X Y");
		  printf("Le point initial : Position x: %f , Position y: %f, L'angle: %f  test\n", cx, cy, cz);
		


		
				t = (cz*i) / (np - 1);
				
				xf = cx + d * (cos((t + cz)));
				yf = cy + d* (sin((t + cz)));
				zf = cz   +t;
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
	disa=0;
	printf("Resultat avec les vitesses\n");

	for (i = 0; i <= np - 1; i++)
	{
		for (j = 0; j < 1; j++)
		{
				disl = sqrt(pow((v[i][j].x - cx), 2) + pow((v[i][j].y - cy), 2));
		
					v[i][j].vl = disl / tmp;
				disa = (v[i][j].z - cz);
				v[i][j].va = disa / tmp;
			

			printf("Position x: %f , Position y: %f, L'angle: %f,La vitesse Angulaire: %f, La vitesse Lineaire: %f", v[i][j].x, v[i][j].y, v[i][j].z, v[i][j].va, v[i][j].vl);
			printf("\n");


		}


		printf("\n");

	}





ros::spinOnce();
loop_rate.sleep();
}
  





	return 0;
}
