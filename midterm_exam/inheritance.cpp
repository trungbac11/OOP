#include<bits/stdc++.h>
using namespace std;

class Employee{
	private:
		string number;
		double salary;
		string name;
		
	public:
	//constructure
		Employee(string aNumber, double aSalary, string aName){
			this->number=aNumber;
			this->salary=aSalary;
			this->name=aName;
		}
		
	//setter
		void setNumber(string number){
        	this->number = number;
	    }
	
	    void setName(string name){
	        this->name = name;
	    }
	
	    void setSalary(double salary){
	        this->salary = salary;
	    }
	    
	//getter
	    string getNumber(){
        	return this->number;
	    }
	
	    string getName(){
	        return this->name;
	    }
	
	    double getSalary(){
	        return this->salary;
	    }

	//method
	//display
		void display(){
	        cout << "Number: " << getNumber() << endl;
	        cout << "Name: " << getName() << endl;
	        cout << "Salary: " << getSalary() << endl;
	    }
};

class Programmer: public Employee{
	private:
		string language;
		
	public:
	//constructure	
		Programmer(string aNumber, double aSalary, string aName, string aLanguage) : Employee(aNumber, aSalary, aName){
        	this->language = aLanguage;
		}
		
	//setter
		void setLanguage(string language){
        	this->language = language;
   	 	}
	//getter
		string getLanguage(){
        	return this->language;
    	}
    //method
    	void display(){
	        Employee::display();
	        cout << "Language: " << getLanguage() << endl;
  		}
};

class ProjectLeader : public Programmer{
	private:
		list<Programmer*> abc;
	
	public:
	//constructure
		ProjectLeader(string aNumber, double aSalary, string aName, string aLanguage) : Programmer(aNumber, aSalary, aName, aLanguage){}
	 
	//setter
		void setProgrammers(list<Programmer*> p){
     	   this->abc = p;
    	}
    	
    //getter
	    list<Programmer*> getProgrammers(){
	        return this->abc;
	    }
	
	//adding a programmer in project
	    void addProgrammer(Programmer *p){
	        abc.push_back(p);
	    }
	    
	//display
		void displayProgrammers(){
        	cout << "All programmers have in the project: " << endl;
       		for(auto it : this->getProgrammers()){
            	(*it).display();
            	cout<<"-----------------------------"<<endl;
	        }
	    }    
		void display(){
	        Programmer::display();
	        displayProgrammers();
    	}
};

int main(){
	Employee a("123",123,"trungbac");
	//a.display();
	
	Programmer b("P001",123,"bac", "C++");
  //  b.display();
    
    Programmer c("C001",123,"trung", "Python");
    //c.display();
    
    ProjectLeader pl1("PL001", 111111, "trungbac", "Python");
    cout << "Project Leader Details:" << endl;
    pl1.display();
    
    cout<<endl;
    
    pl1.addProgrammer(&b);
    pl1.addProgrammer(&c);
    cout << "Project Leader's Programmers:" << endl;
    pl1.displayProgrammers();
    cout << endl;
    
    
	return 0;
}
