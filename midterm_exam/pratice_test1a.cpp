#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AccountOwner; 

class Account{
private:
    int id;
    double balance;
    vector<AccountOwner*> owners;  
    
public:
    Account(int id, double balance){
		this->setId(id);
		this->setBalance(balance);
	}

    //set
    void setId(int id){
    	this->id = id;
	}
	void setBalance(double balance){
    	this->balance = balance;
	}

    //get
    int getId(){
        return id;
    }
    double getBalance(){
        return this->balance;
    }
	//behac
	void addOwner(AccountOwner* owner);
    
    // display
    void display();
};

class AccountOwner{
private:
    string name;
    vector<Account*> accounts;  
    
public:
    AccountOwner(string name){
		this->setName(name);
	}

    //set
    void setName(string name){
    	this->name = name;
	}
	
	//get
    string getName(){
        return this->name;
    }
    
    //behav
    void addAccount(Account* account);
	
	//display
    void display();
};


void Account::addOwner(AccountOwner* owner){
	owners.push_back(owner);
}
void Account::display(){
	cout << "Account ID: " << id << ", Balance: " << balance << endl;
    cout << "Owners: ";
    for (const auto& owner : owners) {
        cout << owner->getName() << " ";
    }
    cout << endl;
}

void AccountOwner::addAccount(Account* account){
	accounts.push_back(account);
    account->addOwner(this);
}
void AccountOwner::display(){
	cout << "Owner: " << name << endl;
    cout << "Accounts: ";
    for (const auto& account : accounts) {
        cout << "ID: " << account->getId() << ", Balance: " << account->getBalance() << " ";
    }
    cout << endl;
}

int main(){
    Account account1(101, 1000.0);
    Account account2(102, 1500.0);
    Account account3(103, 2000.0);

	AccountOwner owner1("Alice");
    AccountOwner owner2("Bob");
	
	owner1.addAccount(&account1);
    owner1.addAccount(&account2);

    owner1.addAccount(&account3);
    owner2.addAccount(&account3);

    cout << "Account Information:" << endl;
    account1.display();
    account2.display();
    account3.display();

    cout << "\nOwner Information:" << endl;
    owner1.display();
    owner2.display();

    return 0;
}

