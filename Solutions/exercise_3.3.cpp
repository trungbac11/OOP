#include<bits/stdc++.h>

using namespace std;

class House{
    string theAddress;
    int theNumberOfRoom;
	
	public:
    //constructor
    House(string theAddress, int theNumberOfRoom){
        this->setAddress(theAddress);
        this->setNumberOfRoom(theNumberOfRoom);
    }
    //getter
	string getTheAddress(){
        return this->theAddress;
    }
    
	int getTheNumberOfRoom(){
        return this->theNumberOfRoom;
    }
    
    //setter   
	void setAddress(string theAddress){
        this->theAddress = theAddress;
    }
    
	void setNumberOfRoom(int theNumberOfRoom){
        this->theNumberOfRoom = theNumberOfRoom;
    }
    //...
    //methods
    
    //display
    void display(){
        cout << "The Address: " << this->getTheAddress() << endl;
        cout << "The NumberOfRoom: " << this->getTheNumberOfRoom() << endl;
    }
    
    //destructor
};

int main(){
    //declare objects
   House a("KTX B",123);
   a.display();
   
   return 0;
}
