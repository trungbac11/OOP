#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person{
private:
    int id;
    string name;
    vector<class House*> houses;

public:
    Person(int id, string name) {
        this->setID(id);
        this->setName(name);
    }
	
	//set
    void setID(int id){
        this->id = id;
    }

    int getID(){
        return id;
    }
	
	//get
    void setName(string name){
        this->name = name;
    }

    string getName(){
        return name;
    }
	//behav
    void addHouse(House* house);
	//display
    void display();
};

class House{
private:
    int id;
    string address;
    vector<Person*> owners;

public:

    House(int id, string address) {
        this->setId(id);
        this->setAddress(address);
    }
    
	//set
    void setId(int id){
        this->id = id;
    }
	
	void setAddress(string address){
        this->address = address;
    }
	
	//get
	int getId(){
        return id;
    }
    
    string getAddress(){
        return address;
    }
	//behav
    void addOwner(Person* person){
        owners.push_back(person);
    }
	//display
    void display();
};

void Person::addHouse(House* house){
    houses.push_back(house);
    house->addOwner(this);
}
void Person::display() {
    cout << "ID: " << this->getID() << ", Name: " << this->getName() << endl;
	cout<<"Houses owned: " << endl;
    for (House* house : houses){
        cout << "House ID: " << house->getId() <<" | " <<"Address: " << house->getAddress()  << endl;
    }
    cout << endl;
}

void House::display() {
    cout << "House ID: " << this->getId() << ", Address: " << this->getAddress() << ", Owners: ";
    for (Person* person : owners){
        cout << person->getName() << ", ";
    }
    cout << endl;
}


int main(){
    Person* p1 = new Person(1, "Tran");
    Person* p2 = new Person(2, "Trung");
    Person* p3 = new Person(3, "Bac");

   
    House* h1 = new House(101, "KTXA");
    House* h2 = new House(102, "KTXB");

    p1->addHouse(h1);
    p2->addHouse(h1);

    p3->addHouse(h1);
    p3->addHouse(h2);

    cout << "Persons Information:" << endl;
    p1->display();
    p2->display();
    p3->display();

    cout << "\nHouses Information:" << endl;
    h1->display();
    h2->display();

    return 0;
}
