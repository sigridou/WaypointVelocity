

#include <iostream>


#include <vector>
#define PI 3.14159265
#include <math.h>
#include <stdlib.h>
#include <ctype.h>  


#include <cmath>

class Pointm {
public:
	double xt, yt, zt, vl, va;

	Pointm(double xt, double yt, double zt, double vl, double va) {
		this->xt = xt;
		this->yt = yt;
		this->zt = zt;
		this->vl = vl;
		this->va = va;

	};
};


struct Pointss{
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
/**Pointss generPoint(int d, float v ,float dt,  float omega )
{   Pointss pInit ;

    pInit.x[0] = 0;
    pInit.y [0]= 0;
    pInit.theta[0] = 0*(PI/180) ;
		 for(int h=0 ;h<((d/v)/dt);h++){
		 
	        pInit.x[h+1]=pInit.x[h]-v*dt* sin(pInit.theta[h]+(dt*omega)/2);
	     	pInit.y[h+1]=pInit.y[h]+v*dt* cos(pInit.theta[h]+(dt*omega)/2);
	      	pInit.theta[h+1]=pInit.theta[h]+dt*omega;
	 	
		printf("Position du point: x:  %f\t y: %f\t z:  %f\t  \n" ,pInit.x[h+1],pInit.y[h+1],pInit.theta[h+1]);
	  
	  
		}return pInit;
	
}**/

// fonction 2
//float move_forward(float deltafi,int q )
//{  
 //float omegaa = deltafi*q ;
//return (omegaa);
//}
 

int main(int argc, char** argv) {

   Pointm pt(0, 0, 0, 0, 0);
   Pointm vec[7][4] = { {pt,pt,pt,pt},{pt,pt,pt,pt},{pt,pt,pt,pt},{pt,pt,pt,pt},{pt,pt,pt,pt},{pt,pt,pt,pt},{pt,pt,pt,pt} };

       struct Pointss p;
       int b;

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
v=0.2;
dt=2;


//les zone definit pour les commande (radian)	 
	 deltafi_av=(0.3)/n;  // pour la commande avant
	 deltafi_dg=(0.4)/n;

pInit.x[0] = 0;
    pInit.y [0]= 0;
    pInit.theta[0] = 0*(PI/180) ;
    vec[0][0].xt=0;
    vec[0][0].yt=0;
    vec[0][0].zt=0;

// la boucle de omega par rapport aux nmbrs de trajectoire 	 	 
i=(-(n-1)/2);

	 while  (i<=(n-1)/2) {
	 

	 omega= (((0.8/n)/dt)*i);   //omerga calculer avec deltaFi(l'angle entre les trajectoires)
	
	
	
// pour chaque omega un nmbr h de point generer 
   printf("\n");
	printf(" Avec une vitesse angulaire Omega = %f :\n  ", omega);
		
	   //p=generPoint( d,  v , dt,  omega );
	   

    
		 for(int h=0 ;h<((d/v)/dt);h++){
		 	 
		 	 b=h;
		  
      	
		   
	        pInit.x[h+1]=pInit.x[h]-v*dt* sin(pInit.theta[h]+(dt*omega)/2);
	     	pInit.y[h+1]=pInit.y[h]+v*dt* cos(pInit.theta[h]+(dt*omega)/2);
	      	pInit.theta[h+1]=pInit.theta[h]+dt*omega;
	      	vec[i][b].xt=pInit.x[h+1];
	      	vec[i][b].yt=	pInit.y[h+1];
	      	vec[i][b].zt=pInit.theta[h+1];
	      
	  
	 	
	    	printf("Position du point: x:  %f\t y: %f\t z:  %f\t  \n", vec[i][b].xt,vec[i][b].yt,vec[i][b].zt);
	  
}
          	
	
	   
	  
    
	
	      
	      i++;
}
	


 

	return 0;
}

