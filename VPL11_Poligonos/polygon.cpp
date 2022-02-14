/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {

  int confere = 0;
  for(int i = 0; i < lhs.limits.size(); i++)
  {
    for(int j = 0; i < rhs.limits.size(); j++)
    {
      if(lhs.limits.size() > rhs.limits.size())
      {
        if(rhs.limits[i] == lhs.limits[j])
        {
          confere++;
          break;
        }
      }else{

        if(lhs.limits[i] == rhs.limits[j])
        {
          confere++;
          break;
        }

      }
    }
  }

  if(lhs.limits.size() > rhs.limits.size() && confere == rhs.limits.size())
      {
        return true;
      }else if (lhs.limits.size() < rhs.limits.size() && confere == lhs.limits.size())
      {
        return true;
      }else
        return false;

}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {

  bool teste = 0;
  
  for(int i = 0; i < limits.size(); i++)
  {
    if(this->limits[i].x == p.x && this->limits[i].y == p.y)
    {
      teste = true;
      break;
    }else
      teste = false;
      break;
  }
  
  return teste;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  
  limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {

  Point p0(x0,y0);
  Point p1(x1,y1);
}