#include<bits/stdc++.h>
using namespace std;

class Account{
	string theNumber;
	int theBalance;
	
	public:
		Account(string theNumber, int theBalance){
			this->theNumber = theNumber;
			this->theBalance = theBalance;	
		}
		
		int getBalance(){
			return this->theBalance;
		}
		
};
int main(){
	Account a("123",123);
	cout<<a.getBalance();
	return 0;
}
