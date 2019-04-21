#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <SFML/Graphics.hpp>
using namespace sf;

class PERSON
{
public:
  float dx,dy;
  FloatRect rect;
  Sprite sprite;
  float currentFrame;

  virtual void Collision(int num = 0) = 0;
  virtual void update(float time) = 0;

};


#endif // PERSON_H_INCLUDED
