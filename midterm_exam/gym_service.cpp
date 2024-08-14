#include<bits/stdc++.h>
using namespace std;

class Plan; 

class Customer {
private:
    int id;
    string name;
    Plan* registeredPlan;  
    
public:
    
	Customer(int id, string name){
			this->setId(id);
			this->setName(name);
			this->registeredPlan = nullptr; 
	}

    //set
    void setId(int id) {
        this->id = id;
    }
    
    void setName(string name) {
        this->name = name;
    }

    //get
    int getId() {
        return id;
    }
    
    string getName() {
        return name;
    }

    void registerPlan(Plan* plan);
    void deregisterPlan(); 
	void transferPlan(Customer* newOwner);
    void display();
};

class Plan {
private:
    string namePlan;
    string time;
    vector<Customer*> customers;  

public:
    //constructor
    Plan(string namePlan, string time){
		this->setNamePlan(namePlan);
		this->setTime(time);
	}

    //set
    void setNamePlan(string namePlan) {
        this->namePlan = namePlan;
    }
    
    void setTime(string time) {
        this->time = time;
    }

    //get
    string getNamePlan() {
        return namePlan;
    }
    
    string getTime() {
        return time;
    }

	void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    void removeCustomer(Customer* customer) {
        customers.erase(remove(customers.begin(), customers.end(), customer), customers.end());
    }
    
    void display() {
        cout << "Plan: " << getNamePlan() << " | Time: " << getTime() << endl;
    }
};

void Customer::registerPlan(Plan* plan) {
    if (registeredPlan) {
        registeredPlan->removeCustomer(this);
    }
	registeredPlan = plan;
    plan->addCustomer(this);
}

void Customer::deregisterPlan() {
    if (registeredPlan) {
        registeredPlan->removeCustomer(this);
        registeredPlan = nullptr;
    }
}

void Customer::transferPlan(Customer* newOwner) {
    if (registeredPlan && newOwner) {
        newOwner->registerPlan(registeredPlan);
        deregisterPlan();
    }
}

void Customer::display() {
    cout << "ID: " << getId() << " | Name: " << getName();
    if (registeredPlan != nullptr) {
        cout << " | Plan: " << registeredPlan->getNamePlan();
    }
    cout << endl;
}

class Stationn{
private:
    string nameSta;
    vector<Plan*> plans;

public:
    Stationn(string nameSta){
		this->setNameSta(nameSta);
	}
	
	//set
	void setNameSta(string nameSta) {
        this->nameSta = nameSta;
    }
    
    //get
    string getNameSta(){
    	return nameSta;
	}
	
    void addPlan(Plan* plan) {
        plans.push_back(plan);
    }

    void display() {
        cout << "Station: " << getNameSta() << endl;
        for (auto& plan : plans) {
            plan->display();
        }
    }
};



int main(){
    Customer a(1, "Trung Bac");
	Customer b(2, "Yen Nhi");
	Customer c(3, "Be Mon");
	
    Plan p1("basic", "30 days");
	Plan p2("advanced", "60 days");
    
    Stationn station("City Gym");

    station.addPlan(&p1);
    station.addPlan(&p2);

    a.registerPlan(&p2);
    b.registerPlan(&p1);
	b.deregisterPlan(); //cancel
    b.registerPlan(&p2);
    a.transferPlan(&c); //transfer

    a.display();
    b.display();
    c.display();

	station.display();
    
    return 0;
}

