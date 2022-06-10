#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <cmath>

#include <vector>
#define PI 3.14159265
#include <math.h>
#include <stdlib.h>
#include <ctype.h>  
#include "std_msgs/String.h"
#include <sstream>
 #include <ros/console.h>
#include <iostream>





struct Pointss{
  float x[100];
  float y[100];
  float theta[100];

};

// fonction 1
//**Pointss generPoint(int d, float v ,float dt,  float omega )
/*{   Pointss pInit ;

   pInit.x[0] = 0;
    pInit.y [0]= 0;
    pInit.theta[0] = 0*(PI/180) ;
		 for(int h=0 ;h<((d/v)/dt);h++){
		 
	        pInit.x[h+1]=pInit.x[h]-v*dt* sin(pInit.theta[h]+(dt*omega)/2);
	  	pInit.y[h+1]=pInit.y[h]+v*dt* cos(pInit.theta[h]+(dt*omega)/2);
	  	pInit.theta[h+1]=pInit.theta[h]+dt*omega;
	 	
		printf("Position du point: x:  %f\t y: %f\t z:  %f\t  \n" ,pInit.x[h+1],pInit.y[h+1],pInit.theta[h+1]);
	  
	  
		}return pInit;
	
}
**/

char * strtoupper( char * dest, const char * src ) {
    char * result = dest;
    while( *dest++ = toupper( *src++ ) );
    return result;
}


int main( int argc, char** argv )
{
ros::init(argc, argv, "spheres");
ros::NodeHandle n;
ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("ball_trajectory", 1);

ros::Rate r(30);

float f = 0.0;
while (ros::ok())
{ 

   struct Pointss pnt;

	const float pi =  3.14159265358979323846;
	struct Pointss pInit ; //point, pointFinal;
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
v=0.27;
dt=0.6;


//les zone definit pour les commande (radian)	 
	 deltafi_av=(0.3)/n;  // pour la commande avant
	 deltafi_dg=(0.4)/n;





visualization_msgs::Marker sphere_list;
sphere_list.header.frame_id= "/my_frame";
sphere_list.header.stamp= ros::Time::now();
sphere_list.ns= "spheres";
sphere_list.action= visualization_msgs::Marker::ADD;
sphere_list.pose.orientation.w= 1.0;
sphere_list.id = 0;

sphere_list.type = visualization_msgs::Marker::SPHERE_LIST;
// POINTS markers use x and y scale for width/height respectively
sphere_list.scale.x = 0.03;
sphere_list.scale.y = 0.03;
sphere_list.scale.z = 0.03;

// Points are green
sphere_list.color.r = 1.0f;
sphere_list.color.a = 1.0;
// Create the vertices for the points and lines

// la boucle de omega par rapport aux nmbrs de trajectoire 	 	
	 geometry_msgs::Point p, ps;
         ps.x=0;
         ps.y=0;
         ps.z=0;
         sphere_list.points.push_back(ps);
     
	pInit.x[0] = 0;
    pInit.y [0]= 0;
    pInit.theta[0] = 0*(PI/180) ;
   
i=(-(n-1)/2);

	 while  ( i<=(n-1)/2) {
	 

	 omega= (((0.8/n)/dt)*i);   //omerga calculer avec deltaFi(l'angle entre les trajectoires)
	
	
	

		
	   //pnt=generPoint( d,  v , dt,  omega );
		 for(int h=0 ;h<((d/v)/dt);h++){
		 	 
		 	 
		  
      	
		   
	        pInit.x[h+1]=pInit.x[h]-v*dt* sin(pInit.theta[h]+(dt*omega)/2);
	     	pInit.y[h+1]=pInit.y[h]+v*dt* cos(pInit.theta[h]+(dt*omega)/2);
	      	pInit.theta[h+1]=pInit.theta[h]+dt*omega;
	    
			  p.x = pInit.x[h+1];
              p.y = pInit.y[h+1];
              p.z = 0;
              sphere_list.points.push_back(p);
              
		 }
	      
	    
	

	  
      
	i++;
	 }
	
	marker_pub.publish(sphere_list);
	
/**for (uint32_t i = 0; i < 25; ++i)
{
float y = sin(f + i / 100.0f * 2 * M_PI);
float z = cos(f + i / 100.0f * 2 * M_PI);

geometry_msgs::Point p;
p.x = (int32_t)i*0.2;
p.y = y;
p.z = z;
sphere_list.points.push_back(p);

}
marker_pub.publish(sphere_list);**/

r.sleep();

f += 0.04;
}
}



