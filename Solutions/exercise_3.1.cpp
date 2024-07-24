#include<bits/stdc++.h>
using namespace std;

class Car{
	string theMake;
	string theMethod;
	int theCapacity;
	
	public:
		//constructor
		Car(string Make, string Method, int Capacity){
			this->theMake = Make;
			this->theMethod = Method;	
			this->theCapacity = Capacity;
		}
		//getter
		string getTheMake(){
			return this->theMake;
		}
		
		string getTheMethod(){
			return this->theMethod;
		}
		
		int getTheCapacity(){
			return this->theCapacity;
		}
		
		//setter
		void setTheMake(string theMake){
        	this -> theMake = theMake;
    	}
    	
    	void setTheMethod(string theMethod){
        	this -> theMethod = theMethod;
    	}
    	
    	void setTheCapacitt(int theCapacity){
        	this -> theCapacity = theCapacity;
    	}
		//methodl;
		//display;
		void display(){
			cout << this->getTheMake() << endl;
			cout << this->getTheMethod() << endl;
			cout << this->getTheCapacity() << endl;
		}
};
int main(){
	Car xe("Lamborghini","Sani2021",4);
	xe.display();
	return 0;
}
