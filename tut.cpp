#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
 #include <ros/console.h>
#include <iostream>


#include <vector>
#define PI 3.14159265
#include <math.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  

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
const float pi =  3.14159265358979323846;
// fonction 1
void generPoint(int d, float v ,float dt,  float omega )
{   Point pInit ;

   pInit.x[0] = 0;
    pInit.y [0]= 0;
    pInit.theta[0] = 0*(pi/180) ;
		 for(int h=0 ;h<((d/v)/dt);h++){
		 
	    pInit.x[h+1]=pInit.x[h]-v*dt* sin(pInit.theta[h]+(dt*omega)/2);
	  	pInit.y[h+1]=pInit.y[h]+v*dt* cos(pInit.theta[h]+(dt*omega)/2);
	  	pInit.theta[h+1]=pInit.theta[h]+dt*omega;
	 	
		printf(" coord d'un point (x,y,theta)  %f\t  %f\t  %f\t  \n" ,pInit.x[h+1],pInit.y[h+1],pInit.theta[h+1]);
	  
	  
		}
	
}

// fonction 2
//float move_forward(float deltafi,int q )
//{  
 //float omegaa = deltafi*q ;
//return (omegaa);
//}
 

int main(int argc, char** argv) {
	ros::NodeHandle nd;
        ros::Publisher talk_pub=nd.advertise<std_msgs::String>("very_important_message",100);
        ros::Rate loop_rate(1); //hz
	const float pi =  3.14159265358979323846;
	struct Point pInit ; //point, pointFinal;
	int n,d,q,i,k,j,a;   //le nombre de trajectoire
	
     d=1;    // la distance en metre 
    float deltafi_av,deltafi_dg,omega,omegaa, dt,v; // les parametres
  
 while(ros::ok())

{       loop_rate.sleep();   
    char commande[20]  ;
//initialisation des points (x,y,theta)
	
   
    printf("Coordonees du point initial sont x ,y ,theta : %f \t  %f \t   %f \n", pInit.x[0],pInit.y[0],pInit.theta[0]);

 // commande pour declarer le n ,dt,v
 printf("Donner la val de n " );
scanf("%d",&n);

	 scanf("%f",&v);
	 printf("donner la valeur de dt ");
	 scanf("%f",&dt);


//les zone definit pour les commande (radion)	 
	 deltafi_av=(0.3)/n;  // pour la commande avant
	 deltafi_dg=(0.4)/n;



// la boucle de omega par rapport aux nmbrs de trajectoire 	 	 
i=(-(n-1)/2);

	 while  (i<=(n-1)/2) {
	 

	 omega= (((0.8/n)/dt)*i);   //omerga calculer avec deltaFi(l'angle entre les trajectoires)
	
	
	
// pour chaque omega un nmbr h de point generer 
	printf(" pour la val omega %f\n", omega);
		
	   generPoint( d,  v , dt,  omega );
	
	i++;
	
	   
	  
    
	
	 }

//-------------------------la commande  -------------------------------	 
	 while (k ) {
	 	
	 	  printf("Donner la commande :");
	    scanf("%s",commande);
    char * input = commande ;
    char result[20];

   strtoupper( result, input );
   //printf("%s", result);
   
           char E[] = "AV";
          char A[] = "AG";
           char B[] = "AD";

	    if( strcmp(result,E) == 0)
	    {
	// trajectoires de la commande avant    	
	    for (int q=(-(n-1)/2);q<=((n-1)/2);q++)	{
	 
		 omegaa = (deltafi_av/dt)*q   ; 
		

			printf(" pour la val omega %f\n", omegaa);
				
	      generPoint( d,  v , dt,  omegaa );
	      
	  }
}
 else if ( strcmp(result,A) == 0) 
    // trajectoires	pour la commande gauche   
	    { for(int q=0 ; q< n;q++) {
		
	 
	 omegaa = (0.3/dt) +((deltafi_dg/dt)*q);  // omega + (0.3/dt)=> omega + le omega dela dernier trajectoire de la commande avant
	 
		printf(" pour la val omega %f\n", omegaa);
	       generPoint( d,  v , dt,  omegaa );
}
}

else if  ( strcmp(result,B) == 0) 
     // trajectoires pour la commande droit
{		for(int q=0; q<n ;q++) {
		
	 
	 omegaa = (-0.3/dt)+((deltafi_dg/dt)*-q);
	 
			printf(" pour la val omega %f\n", omegaa);
	        generPoint( d,  v , dt,  omegaa );
		
}
}
else    k++ ; 

}

ros::spinOnce();
loop_rate.sleep();
}
 

	return 0;
}
