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

#include <visualization_msgs/Marker.h>

#include <cmath>

struct Points{
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
Points generPoint(int d, float v ,float dt,  float omega )
{   Points pInit ;

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

// fonction 2
//float move_forward(float deltafi,int q )
//{  
 //float omegaa = deltafi*q ;
//return (omegaa);
//}
 

int main(int argc, char** argv) {

ros::init(argc, argv, "Points");
        ros::NodeHandle nd;
        ros::Publisher talk_pub=nd.advertise<visualization_msgs::Marke>("visualization_marker", 10);
        ros::Rate loop_rate(1); //hz
        while(ros::ok())

{       loop_rate.sleep();


     visualization_msgs::Marker points, line_strip, line_list;
    points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "/my_frame";
    points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    points.ns = line_strip.ns = line_list.ns = "points_and_lines";
    points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;



points.id = 0;
    line_strip.id = 1;
    line_list.id = 2;



    points.type = visualization_msgs::Marker::POINTS;
    line_strip.type = visualization_msgs::Marker::LINE_STRIP;
    line_list.type = visualization_msgs::Marker::LINE_LIST;



    // POINTS markers use x and y scale for width/height respectively
    points.scale.x = 0.2;
    points.scale.y = 0.2;

    // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
    line_strip.scale.x = 0.1;
    line_list.scale.x = 0.1;



    // Points are green
    points.color.g = 1.0f;
    points.color.a = 1.0;

    // Line strip is blue
    line_strip.color.b = 1.0;
    line_strip.color.a = 1.0;

    // Line list is red
    line_list.color.r = 1.0;
    line_list.color.a = 1.0;



    Point p[100];

	const float pi =  3.14159265358979323846;
	struct Points pInit ; //point, pointFinal;
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
		
	   p[i]=generPoint( d,  v , dt,  omega );
	    geometry_msgs::Point dot;
         dot.x = p[i].x;
         dot.y = p[i].y;
         dot.z = p[i].theta;
         
         points.points.push_back(p);
       line_strip.points.push_back(p);

      // The line list needs two points for each line
      line_list.points.push_back(p);
      p.z += 1.0;
      line_list.points.push_back(p);

	i++;
	
	   
	  
    
	
	 }
	 
	  marker_pub.publish(points);
    marker_pub.publish(line_strip);
    marker_pub.publish(line_list);

ros::spinOnce();
loop_rate.sleep();
}

 

	return 0;
}
