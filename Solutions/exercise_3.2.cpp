#include<bits/stdc++.h>

using namespace std;

class Student{
    string theName;
    string theAddress;
    string theMatriculationNumber;
	
	public:
    //constructor
    Student(string aName, string anAddress, string aMatriculationNumber){
        this->theName = aName;
        this->theAddress = anAddress;
        this->theMatriculationNumber = aMatriculationNumber;
    }
    //getter
    string getTheName(){
        return this->theName;
    }
    
	string getTheAddress(){
        return this->theAddress;
    }
    
	string getTheMatriculationNumber(){
        return this->theMatriculationNumber;
    }
    
    //setter
    void setTheName(string theName){
        this->theName = theName;
    }
    
	void setTheAddress(string theAddress){
        this->theAddress = theAddress;
    }
    
	void setTheMatriculationNumber(string theMatriculationNumber){
        this->theMatriculationNumber = theMatriculationNumber;
    }
    //...
    //methods
    
    //display
    void display(){
        cout << "The Name: " << this->getTheName() << endl;
        cout << "The Address: " << this->getTheAddress() << endl;
        cout << "The MatriculationNumber: " << this->getTheMatriculationNumber() << endl;
    }
    
    //destructor
};

int main(){
    //declare objects
   Student a("Bac" , "KTX B", "1234");
   a.display();
   
   return 0;
}
