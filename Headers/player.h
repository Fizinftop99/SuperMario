#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "person.h"

extern float offsetX, offsetY;
extern String TileMap[];


class PLAYER : public PERSON
{
public:
    bool onGround;

    PLAYER(Texture &image) //конструктор класса
       {
            sprite.setTexture(image);
            rect = FloatRect(100,180,16,16); //две координаты, ширина, высота

            dx=dy=0.1;
            currentFrame = 0;
       }


       virtual void update(float time)
       {

         rect.left += dx * time;
         Collision(0);


         if (!onGround) dy=dy+0.0005*time;  //равноускоренно падаем!
         rect.top += dy*time;
         onGround=false;
         Collision(1);


         currentFrame += time * 0.005;
         if (currentFrame > 3) currentFrame -= 3;


        if (dx>0) sprite.setTextureRect(IntRect(112+31*int(currentFrame),144,16,16));      //сдвигаем координату текстуры
        if (dx<0) sprite.setTextureRect(IntRect(112+31*int(currentFrame)+16,144,-16,16));


         sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

         dx=0;
   }


   virtual void Collision(int num = 0)
{

	for (int i = rect.top/16 ; i<(rect.top+rect.height)/16; i++)
		for (int j = rect.left/16; j<(rect.left+rect.width)/16; j++)
			 {
				 if ((TileMap[i][j]=='P') || (TileMap[i][j]=='k') || (TileMap[i][j]=='0') || (TileMap[i][j]=='r') || (TileMap[i][j]=='t'))
				                         {
												   if (dy>0 && num==1)
												   { rect.top =   i*16 -  rect.height;  dy=0;   onGround=true; }
											       if (dy<0 && num==1)
												   { rect.top = i*16 + 16;   dy=0;}
												   if (dx>0 && num==0)
												   { rect.left =  j*16 -  rect.width; }
											       if (dx<0 && num==0)
												   { rect.left =  j*16 +16;}
										 }

				 if (TileMap[i][j]=='c') {
												 TileMap[i][j]=' ';
			                          	 }
			 }

}

};

#endif // PLAYER_H_INCLUDED
