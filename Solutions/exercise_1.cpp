#include<bits/stdc++.h>
using namespace std;

class Person{
	string theName = "Bac";
	string dateOfBirth = "28112004";
	
	public:
		string getName(){
			return this->theName;
		}
		string getDateOfBirth(){
			return this->dateOfBirth;
		}
		
};

int main(){
	Person a;
	cout<<a.getName();
	return 0;
}
