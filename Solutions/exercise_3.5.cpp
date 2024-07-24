#include<bits/stdc++.h>

using namespace std;

class Point {
    double theX;
    double theY;
    
	public:
    //constructor
    Point(){}
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

class Line {
    Point theStart;
    Point theEnd;
    
	public:
    Line(Point* aStart, Point* anEnd) {
        this->setStart(aStart);
        this->setEnd(anEnd);
    }
    //getters
    Point getStart() {
        return this->theStart;
    }
    Point getEnd() {
        return this->theEnd;
    }
    //setters
    void setStart(Point* aStart) {
        this->theStart = *aStart;
    }
    void setEnd(Point* anEnd) {
        this->theEnd = *anEnd;
    }
    //methods
    bool isHorizontal() {
        return this->getStart().getX() == this->getEnd().getY();
    }
    bool isVertical() {
        return this->getStart().getX() == this->getEnd().getX();
    }
    void moveBy(double anX, double anY) {
        Point a(this->getStart().getX() + anX, this->getStart().getY() + anY);
        Point b(this->getEnd().getX() + anX, this->getEnd().getY() + anY);
        this->setStart(&a);
        this->setEnd(&b);
    }
    void display() {
        if (this->isHorizontal())
            cout << "Horizontal Line" << endl;
        else if (this->isVertical())
            cout << "Vertical Line" << endl;
        else
            cout << "Cross Line L: (" << this->getStart().getX() << ", " << this->getStart().getY() << ") to (" << this->getEnd().getX() << ", " << this->getEnd().getY() << ")" << endl;
    }
};

int main() {
    //declare objects
    Point a(1, -1);
    Point b(2, 3);
    Line l(&a, &b);
    //call the method
    l.moveBy(4, 3);
    l.display();
}
