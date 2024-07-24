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
class Line{
	Point theStart;
	Point theEnd;
	
	public:
	//constructure
	Line(Point theStart, Point theEnd) : theStart(theStart), theEnd(theEnd) {}

	
	//getter
	Point getTheStart() {
        return this->theStart;
    }
    Point getTheEnd() {
        return this->theEnd;
    }
    
    //setter
	void setTheStart(Point theStart) {
        this->theStart = theStart;
    }
    void setTheEnd(Point theEnd) {
        this->theEnd = theEnd;
    }
	//method
	bool isHorizontal(){
        return theStart.getY() == theEnd.getY();
    }
    
    bool isVertical(){
        return theStart.getX() == theEnd.getX();
    }
  
    void moveBy(double dx, double dy){
        theStart.moveBy(dx, dy);
        theEnd.moveBy(dx, dy);
    }
    
    //display
    void check(){
    	if (this->isHorizontal()){
    		cout<<"horizontal"<<endl;
		} else if(this->isVertical()){
			cout<<"vertical"<<endl;
		} else {
			cout<<"not horizontal or vertical";
		}
	}
	void display(){
		theStart.display();
        theEnd.display();
	}
	
};
int main(){
    //declare objects
   Point a(2,1);
   Point b(3,1);
   
   Line c(a,b);
   c.check();
   c.moveBy(2,2);
   c.display();
   
   return 0;
}
