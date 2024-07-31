#include<bits/stdc++.h>
using namespace std;

class Book{
    private:
        string theCatalogueNumber;
        string theAuthor;
        string theTitle;
    
	public:
        Book(string aCatalogueNumber,string anAuthor,string aTitle) 
        {
            this->setTheCatalogueNumber(aCatalogueNumber);
            this -> setTheAuthor(anAuthor);
            this -> setTheTitle(aTitle);
        }
		
		//getter
        string getTheCatalogueNumber(){
            return this->theCatalogueNumber;
        }
        
        string getTheAuthor(){
            return this->theAuthor;
        }
        
        string getTheTitle(){
            return this->theTitle;
        }
		
		//setter
        void setTheCatalogueNumber(string aCatalogueNumber){
            this->theCatalogueNumber= aCatalogueNumber;
        }
        
		void setTheAuthor(string anAuthor){
            this->theAuthor = anAuthor;
        }
        
        void setTheTitle(string aTitle){
            this->theTitle = aTitle;
        }
        
        void display(){
            cout << "theCatalogueNumber = " << this->theCatalogueNumber << endl;
            cout << "theTitle : "<< this->theTitle << endl;
            cout << "theAuthor : "<< this->theAuthor << endl;
        }
};


class Library{
    private:
        string theName;
        list<Book*> stock;
    public :
        Library(string aName)
        {
            this -> setTheName(aName);
        }
		
		//getter
	    string getTheName(){
	        return this->theName;
	    }
	    
	    void Display(){
	        for(auto i:this->stock)
	            i->display();
	    }
	    
	    
	//setter:
	    void setTheName(string aName){
	        this->theName = aName;
	    }
	    
	    void addOneBook(Book* book){
            this->stock.push_back(book);
        }
    
};

int main() {
    cout <<"The Library Application\n" << endl;
    
    Book* first = new Book("000","Lewis Carol","Alice in Wonderland");
    first->display();
    
    Book second("001","Huynh Quang Vu","Giai Tich Ham Nang Cao");
    second.display();
    Library library("HCM");
    library.addOneBook(&second);
    library.Display();
    delete(first);
    return 0;
}
