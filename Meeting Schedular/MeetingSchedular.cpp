#include<bits/stdc++.h>
using namespace std;
class Room;
class Meeting;

typedef vector<Meeting>Calender;

class Room{

 private:
    string name;
    Calender calender;
public:

    string getName() const { return name; }
    void setName(const string &name_) { name = name_; }
    Room(string);
    bool book(int,int);
};

class Meeting{

private:
int start;
int end;
Room room;
public:
Meeting(int,int,Room);

int getStart() const { return start; }

int getEnd() const { return end; }
void setEnd(int end_) { end = end_; }

};
Meeting:: Meeting(int start,int end,Room room):room(room){
    this->start=start;
    this->end=end;
}
class Schedular{
vector<Room>rooms;

public:
Schedular(vector<Room>);
string book(int,int);
};
Schedular::Schedular(vector<Room>rooms){
    this->rooms=rooms;
}
bool Room :: book(int start,int end){
    for(Meeting m:calender){
      if(m.getStart()<end&&start<m.getEnd()){
        return false;
      }
    }
    Meeting meeting(start,end,*this);
    //cout<<meeting.getStart()<<" "<<meeting.getEnd();
   calender.push_back(meeting);
   return true;
}
Room::Room(string name){
    this->name=name;
}
string Schedular::book(int start,int end){
    for(Room &room:rooms){
        bool check=room.book(start,end);
        if(check){
            return room.getName();
        }
    }
    return "No room available";
}
int main(){
    Room room1("A");
    Room room2("B");
    Room room3("c");
    vector<Room>vec_room;
    vec_room.push_back(room1);
    vec_room.push_back(room2);
    vec_room.push_back(room3);
    Schedular s(vec_room);

    cout<<s.book(2,5)<<endl;
    cout<<s.book(2,5)<<endl;
     //cout<<s.book(2,5)<<endl;
      cout<<s.book(1,3)<<endl;
}