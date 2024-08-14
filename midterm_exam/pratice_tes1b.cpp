#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Instructor;

class Room {
private:
    int roomNumber;
    int capacity;
    Instructor* instructor;

public:
    Room(int roomNumber, int capacity) {
        this->roomNumber = roomNumber;
        this->capacity = capacity;
        this->instructor = nullptr;
    }

    //set
    void setRoomNumber(int roomNumber) {
        this->roomNumber = roomNumber;
    }
    void setCapacity(int capacity) {
        this->capacity = capacity;
    }

    //get
    int getRoomNumber() {
        return this->roomNumber;
    }
    int getCapacity() {
        return this->capacity;
    }
    Instructor* getInstructor() {
        return this->instructor;
    }

    //behav
    void attachInstructor(Instructor* instructor) {
        this->instructor = instructor;
    }
    void detachInstructor() {
        this->instructor = nullptr;
    }
};

class Instructor {
private:
    string name;
    vector<Room*> rooms;

public:
    Instructor(string name) {
        this->name = name;
    }

    // set
    void setName(string name) {
        this->name = name;
    }

    // get
    string getName() {
        return this->name;
    }

    //dis
    void display();
    void bookRoom(Room* room);
    void returnRoom(Room* room);
};

void Instructor::display(){
	cout << "Instructor: " << getName() << endl;
    cout << "Rooms using: " << endl;
    for (int i = 0; i < rooms.size(); i++) {
        cout << rooms[i]->getRoomNumber() << endl;
    }
}

void Instructor::bookRoom(Room* room){
	if (room->getInstructor() == nullptr) {
        this->rooms.push_back(room);
        room->attachInstructor(this);
        cout << "Room " << room->getRoomNumber() << " booked by " << this->getName() << "!" << endl;
    } else {
        cout << "Room " << room->getRoomNumber() << " is already booked!" << endl;
    }
}
void Instructor::returnRoom(Room* room){
	for (int i = 0; i < this->rooms.size(); i++) {
            if (this->rooms[i] == room) {
                this->rooms.erase(this->rooms.begin() + i);
                room->detachInstructor();
                cout << "Room " << room->getRoomNumber() << " returned by " << this->getName() << "!" << endl;
                return;
            }
        }
    cout << "Room " << room->getRoomNumber() << " was not booked by " << this->getName() << "!" << endl;
}
int main() {
    Instructor instructor1("John");
    Instructor instructor2("Jane");
    Room room1(1, 30);
    Room room2(2, 40);
    Room room3(3, 50);

    instructor1.bookRoom(&room1);
    instructor1.bookRoom(&room2);
    instructor2.bookRoom(&room3);

    cout << "\nInstructor 1 returns room 1 for Instructor 2" << endl;
    instructor1.returnRoom(&room1);
    instructor2.bookRoom(&room1);

    instructor1.display();
    instructor2.display();

    return 0;
}

