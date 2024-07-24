#include<bits/stdc++.h>

using namespace std;

class Point{
    double theX;
    double theY;
	
	public:
    //constructor
    Point(double theX, double theY){
        this->setX(theX);
        this->setY(theY);
    }
    //getter
	double getX(){
        return this->theX;
    }
    
	double getY(){
        return this->theY;
    }
    
    //setter   
	void setX(double theX){
        this->theX = theX;
    }
    
	void setY(double theY){
        this->theY = theY;
    }
    //...
    //methods
    
	void moveBy(double dx, double dy){
        this->setX(this->getX() + dx);
        this->setY(this->getY() + dy);
    }
    //display
    void display(){
        cout <<this->getX()<<", "<<this->getY() << endl;
    }
    
    //destructor
};

int main(){
    //declare objects
   Point a(2,2);
   a.display();
   a.moveBy(1,1);
   a.display();
   return 0;
}
