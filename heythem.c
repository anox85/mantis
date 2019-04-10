#include "heythem.h"


SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y) 
{

SDL_Color color ;
Uint32 col=0;
char* pPosition = (char*) pSurface->pixels ;
pPosition += (pSurface->pitch * y);
pPosition += (pSurface->format->BytesPerPixel * x);

memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );


return (color) ;

}

/*__________________________________________________
______________________________________*/


//pour mettre a jour les points de collision ! on 12 points de collision !!!


void update_points_de_collision(Hero* hero)
{				

  //points a droite de l'hero 

	hero->x1=hero->x + PLAYER_WIDTH ;
	hero->y1=hero->y ;												

	hero->x2=  hero->x + PLAYER_WIDTH;
	hero->y2= hero->y + 28  ;


	hero->x3=hero->x + PLAYER_WIDTH ;
	hero->y3= hero->y + 56 ;


	hero->x4=hero->x + PLAYER_WIDTH ;
	hero->y4= hero->y + 85  ;


	//hero->x5=hero->x + PLAYER_WIDTH ;
	//hero->y5= hero->y + 115  ;

	//points a gauche de l'hero 

	hero->x6=  hero->x ;
	hero->y6=  hero->y ;

	hero->x7=  hero->x ;
	hero->y7=  hero->y + 28 ;

	hero->x8= hero->x  ;
	hero->y8=  hero->y + 56;

	hero->x9=  hero->x ;
	hero->y9=  hero->y + 85 ;

	//hero->x10=  hero->x ;
	//hero->y10=  hero->y + 150 ;

	//points au milieu de l'hero 

	hero->x11=  hero->x+35 ;
	hero->y11=  hero->y  ;

	hero->x12=  hero->x+35  ;
	hero->y12=  hero->y+PLAYER_HEIGHT ;
        
        hero->x13=   hero->x + 38;
	hero->y13=  hero->y+PLAYER_HEIGHT ;
       
        hero->x14=  hero->x+32 ;
	hero->y14=  hero->y+PLAYER_HEIGHT ;


}


/*________________________________________________________________________________________*/

//fonction de verification de collision entre le bachground du premier stage et l'hero ! cette fonction retourne 1 en cas de collision sinon 0


int verification_collision_player_map_droite(Acteurs* acteurs , Hero* hero)
{

SDL_Color color1 , color2 , color3 , color4 , color5 ;

int coll = 0;

color1=GetPixel (acteurs->backg_collision , hero->x1 , hero->y1) ; 
color2=GetPixel (acteurs->backg_collision , hero->x2 , hero->y2) ; 
color3=GetPixel (acteurs->backg_collision , hero->x3 , hero->y3) ;
color4=GetPixel (acteurs->backg_collision , hero->x4 , hero->y4) ;     
color5=GetPixel (acteurs->backg_collision , hero->x5 , hero->y5) ;

  
if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255)) 
	|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255) ) || ((color4.r==255)  &&  (color4.g==255)  &&  (color4.b==255)) 
	|| ((color5.r==255)  &&  (color5.g==255)  &&  (color5.b==255) ))  
{
	coll = Collision_droite;
}

return coll;
}

int verification_collision_player_map_gauche(Acteurs* acteurs , Hero* hero)
{

SDL_Color color6 , color7 , color8 , color9 , color10 ;

int coll = 0;

color6=GetPixel (acteurs->backg_collision , hero->x6 , hero->y6) ;
color7=GetPixel (acteurs->backg_collision , hero->x7 , hero->y7) ;
color8=GetPixel (acteurs->backg_collision , hero->x8 , hero->y8) ;
color9=GetPixel (acteurs->backg_collision , hero->x9 , hero->y9) ;
color10=GetPixel (acteurs->backg_collision , hero->x10 , hero->y10) ;
  
if(((color6.r==255)  &&  (color6.g==255)  &&  (color6.b==255) ) 
	|| ((color7.r==255)  &&  (color7.g==255)  &&  (color7.b==255) ) || ((color8.r==255)  &&  (color8.g==255)  &&  (color8.b==255) )
	 || ((color9.r==255)  &&  (color9.g==255)  &&  (color9.b==255) ) || ((color10.r==255)  &&  (color10.g==255)  &&  (color10.b==255)))
{
	coll = Collision_gauche;
}

return coll;
}

int verification_collision_player_map_top(Acteurs* acteurs , Hero* hero)
{

SDL_Color  color11  ;

int coll = 0;

color11=GetPixel (acteurs->backg_collision , hero->x11 , hero->y11) ;

if(((color11.r==255)  &&  (color11.g==255)  &&  (color11.b==255) ))
{
	coll =1;
}

return coll;
}

int verification_collision_player_map_bas(Acteurs* acteurs , Hero* hero)
{

SDL_Color color1 , color2 , color3  ;

int coll = 0;

color1=GetPixel (acteurs->backg_collision , hero->x12 , hero->y12) ; 
color2=GetPixel (acteurs->backg_collision , hero->x13 , hero->y13) ; 
color3=GetPixel (acteurs->backg_collision , hero->x14 , hero->y14) ;


  
if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255)) 
	|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255) ))  
{
	coll = Collision_bas;
}


return coll;
}


/*________________________________________________________________________________________*/
