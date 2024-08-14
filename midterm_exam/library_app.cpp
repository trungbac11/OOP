#include <iostream>
#include <string.h>
#include <list>
using namespace std;

class book;
class borrowerRecord;

//classes
class book {
private:
    string theTitle;
    string theAuthor;
    string theCatalogueNumber;
    borrowerRecord* borrower;
    
public:
	
    book(string aTitle, string anAuthor, string aCatalogueNumber) {
        this->setTitle(aTitle);
        this->setAuthor(anAuthor);
        this->setCatalogueNumber(aCatalogueNumber);
    }
    //get
    string getTitle();
    string getAuthor();
    string getCatalogueNumber();
    borrowerRecord* getBorrower();
    
	//set
    void setTitle(string aTitle);
    void setAuthor(string anAuthor);
    void setCatalogueNumber(string aCatalogueNumber);
    void setBorrower(borrowerRecord* bR);
    
	//methods
    void attachBorrower(borrowerRecord* bR);
    void detachBorrower();
    
	//display
    void display();
    void displayBorrower();
};

class borrowerRecord {
private:
    string theName;
    list<book*> books;
public:
	borrowerRecord(string aName) {
        this->setName(aName);
    }
    //get
    string getName();
    list<book*> getBook();
    
	//set
    void setName(string aName);
    void setBook(list<book*> books);
    
	//methods
    void attachBook(book* book);
    void detachBook();
    
	//display
    void display();
    void displayBooks();
};

class library {
private:
    string theName;
    list<book*> stock;
    list<borrowerRecord*> borrower;
public:
    library(string aName) {
        this->setName(aName);
    }
    
    //get
    string getName();
    list<book*> getStock();
    list<borrowerRecord*> getBorrower();
    
    //set
    void setName(string aName);
    void setStock(list<book*> aStock);
    void setBorrower(list<borrowerRecord*> aBorrower);
    
    //methods
    void regiserOneBorrower(string aBorrowerName);
    ~library();
    void addOneBook(book* aBook);
    void lendOneBook(string name, string catalogueNumber);
    void returnOneBook(string catalogueNumber);
    
	//display
    void displayBooks();
    void displayBorrowers();
    void displayBookAvailableForLoan();
    void displayBookOnLoan();
};

// belongs to class "book"
string book::getTitle() {
    return this->theTitle;
}
string book::getAuthor() {
    return this->theAuthor;
}
string book::getCatalogueNumber() {
    return this->theCatalogueNumber;
}
borrowerRecord* book::getBorrower() {
    return this->borrower;
}
void book::setTitle(string aTitle) {
    this->theTitle = aTitle;
}
void book::setAuthor(string anAuthor) {
    this->theAuthor = anAuthor;
}
void book::setCatalogueNumber(string aCatalogueNumber) {
    this->theCatalogueNumber = aCatalogueNumber;
}
void book::setBorrower(borrowerRecord* bR) {
    this->borrower = bR;
}
void book::attachBorrower(borrowerRecord* bR) {
    this->setBorrower(bR);
}
void book::detachBorrower() {
    this->setBorrower(0);
}
void book::display() {
    cout<<"Book: "<<this->getTitle()<<" | "<<"Author: "<< this->getAuthor()<<" | "<<"Catalogue Number: "<< this->getCatalogueNumber()<<endl;
}
void book::displayBorrower() {
    cout<<"Borrower: "<<this->getBorrower()->getName()<<endl;
}

// belongs to class "borrowerRecord"
string borrowerRecord::getName() {
    return this->theName;
}
list<book*> borrowerRecord::getBook() {
    return this->books;
}
void borrowerRecord::setName(string aName) {
    this->theName = aName;
}
void borrowerRecord::setBook(list<book*> books) {
    this->books = books;
}
void borrowerRecord::attachBook(book* book) {
    this->books.push_back(book);
}
void borrowerRecord::detachBook() {
    this->books.push_back(0);
}
void borrowerRecord::display() {
    cout<<"Borrower: "<<this->getName();
}
void borrowerRecord::displayBooks() {
    for (auto i : this->getBook())
        i->display();
}

// belongs to class "library"
string library::getName() {
    return this->theName;
}
list<book*> library::getStock() {
    return this->stock;
}
list<borrowerRecord*> library::getBorrower() {
    return this->borrower;
}
void library::setName(string aName) {
    this->theName = aName;
}
void library::setStock(list<book*> aStock) {
    this->stock = aStock;
}
void library::setBorrower(list<borrowerRecord*> aBorrower) {
    this->borrower = aBorrower;
}
void library::regiserOneBorrower(string aBorrowerName) {
    this->borrower.push_back(new borrowerRecord(aBorrowerName));
}
void library::addOneBook(book* aBook) {
    stock.push_back(aBook);
}
void library::lendOneBook(string name, string catalogueNumber) {
    for (auto i : this->getStock())
        for (auto j : this->getBorrower()) {
            if (i->getCatalogueNumber() == catalogueNumber && j->getName() == name) {
                i->attachBorrower(j);
                j->attachBook(i);
                return;
            }
        }
    cout << "Not found!";
}
void library::returnOneBook(string catalogueNumber) {
    for (auto i : this->getStock())
        if (i->getCatalogueNumber() == catalogueNumber) {
            i->getBorrower()->detachBook();
            i->detachBorrower();
            break;
        }
}
void library::displayBooks() {
    cout<<"Library: "<<this->getName()<<endl;
	cout<<"Books list: "<<endl;
    for (auto i : this->getStock()) {
        i->display();
        cout << endl;
    }
    //cout<<endl;
}
void library::displayBorrowers() {
	cout<<"Borrower list: "<<endl;
    for (auto j : this->getBorrower()) {
        j->display();
        cout << endl;
    }
    //cout<<endl;
}
void library::displayBookAvailableForLoan() {
    cout<<"BookAvailableForLoan"<<endl;
    for (auto i : this->getStock()) {
        int index = 0;
        for (auto j : this->getBorrower())
            if (i->getBorrower() == j) {
                index++;
                break;
            }
        if (index == 0)
            cout << i->getTitle() << ", " << i->getAuthor() << ", " << i->getCatalogueNumber() << endl;
    }
    cout<<endl;
}
void library::displayBookOnLoan(){
    cout<<"BookOnLoan"<<endl;
    for (auto i : this->getStock())
        for (auto j : this->getBorrower()) {
            if (i->getBorrower() == j) {
                cout << i->getTitle() << ", " << i->getAuthor() << ", " << i->getCatalogueNumber()<<endl;
                cout <<"Borrower: " << i->getBorrower()->getName() << endl;
                return;
            }
        }
}
library::~library() {
    for (auto x : this->getBorrower())
        delete x;
    getBorrower().clear();
}

int main() {
    book b1("OOP", "HVT1", "tth23");
    book b2("DSA", "NHL", "tth24");
    book b3("DATABASE", "HVT2", "tth22");
    borrowerRecord r("Hung");
    library lib("HCMUS");
    lib.addOneBook(&b1);
    lib.addOneBook(&b2);
    lib.addOneBook(&b3);
    
    lib.regiserOneBorrower("Huy");
    lib.regiserOneBorrower("Lam");
    lib.regiserOneBorrower(r.getName());
    
    lib.displayBooks();
    lib.displayBorrowers();
    cout << "\n";
    
   	b1.attachBorrower(&r); 
	b1.displayBorrower();
    
	r.attachBook(&b2);
    r.displayBooks();
    cout << "\n";
    
    lib.lendOneBook("Lam", "tth24");
    lib.displayBookAvailableForLoan();
    lib.displayBookOnLoan();
    
    lib.returnOneBook("tth24");
    lib.displayBookAvailableForLoan();
    lib.displayBookOnLoan();
    return 0;
}
