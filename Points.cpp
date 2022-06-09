
// Sss.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
 #include <ros/console.h>
#include <iostream>


#include <vector>
#define PI 3.14159265
#include <math.h>
#include <stdlib.h>
#include <ctype.h>  
#define PI 3.14159265


struct Point{
  float x[100];
  float y[100];
  float theta[100];

};


char * strtoupper( char * dest, const char * src ) {
    char * result = dest;
    while( *dest++ = toupper( *src++ ) );
    return result;
}

// fonction 1
void generPoint(int d, float v ,float dt,  float omega )
{   Point pInit ;

   pInit.x[0] = 0;
    pInit.y [0]= 0;
    pInit.theta[0] = 0*(PI/180) ;
		 for(int h=0 ;h<((d/v)/dt);h++){
		 
	    pInit.x[h+1]=pInit.x[h]-v*dt* sin(pInit.theta[h]+(dt*omega)/2);
	  	pInit.y[h+1]=pInit.y[h]+v*dt* cos(pInit.theta[h]+(dt*omega)/2);
	  	pInit.theta[h+1]=pInit.theta[h]+dt*omega;
	 	
		printf("Position du point: x:  %f\t y: %f\t z:  %f\t  \n" ,pInit.x[h+1],pInit.y[h+1],pInit.theta[h+1]);
	  
	  
		}
	
}

// fonction 2
//float move_forward(float deltafi,int q )
//{  
 //float omegaa = deltafi*q ;
//return (omegaa);
//}
 

int main(int argc, char** argv) {

ros::init(argc, argv, "Points");
        ros::NodeHandle nd;
        ros::Publisher talk_pub=nd.advertise<std_msgs::String>("very_important_message",100);
        ros::Rate loop_rate(1); //hz
        while(ros::ok())

{       loop_rate.sleep();


	const float pi =  3.14159265358979323846;
	struct Point pInit ; //point, pointFinal;
	int n,d,q,i,k,j,a;   //le nombre de trajectoire
	
     d=1;    // la distance en metre 
    float deltafi_av,deltafi_dg,omega,omegaa, dt,v; // les parametres
  

    char commande[20]  ;
//initialisation des points (x,y,theta)
	
   
    printf("Coordonees du point initial sont x ,y ,theta : %f \t  %f \t   %f \n", pInit.x[0],pInit.y[0],pInit.theta[0]);

 // commande pour declarer le n ,dt,v
 n=7;
printf("Pour une trajectoire avec n=7 points on a :\n");
printf("Vitesse lineaire = 0.2m/s et un temps de deplacement delta t = 2s\n");
v=0.2;
dt=2;


//les zone definit pour les commande (radian)	 
	 deltafi_av=(0.3)/n;  // pour la commande avant
	 deltafi_dg=(0.4)/n;



// la boucle de omega par rapport aux nmbrs de trajectoire 	 	 
i=(-(n-1)/2);

	 while  (i<=(n-1)/2) {
	 

	 omega= (((0.8/n)/dt)*i);   //omerga calculer avec deltaFi(l'angle entre les trajectoires)
	
	
	
// pour chaque omega un nmbr h de point generer 
   printf("\n");
	printf(" Avec une vitesse angulaire Omega = %f :\n  ", omega);
		
	   generPoint( d,  v , dt,  omega );
	
	i++;
	
	   
	  
    
	
	 }
ros::spinOnce();
loop_rate.sleep();
}

 

	return 0;
}
