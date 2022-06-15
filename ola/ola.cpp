#include<bits/stdc++.h>
using namespace  std;

class Person{
public:
     string name;
};
enum RideStatus{IDLE,COMPLETED,WITHDRAWN,CREATED};
class Ride{
     int id;
     int origin;
     int destination;
     int seats;
     RideStatus rideStatus;
     int amtChargerkm=20;
public: Ride();
public:
      int calculateAmt(bool);
      
public:
     RideStatus getRideStatus()
     {
          return this->rideStatus;
     }

public:
     void setRideStatus(RideStatus rideStatus)
     {
          this->rideStatus = rideStatus;
     }


public:  Ride(int,int,int,int);
public:
     int getId()
     {
          return this->id;
     }

public:
     void setId(int id)
     {
          this->id = id;
     }


public:
     void setOrigin(int origin)
     {
          this->origin = origin;
     }

public:
     void setDestination(int destination)
     {
          this->destination = destination;
     }

public:
     void setSeats(int seats)
     {
          this->seats = seats;
     }


};

Ride::Ride(){
     id=origin=destination=seats=0;
   rideStatus=IDLE;
}
int Ride::calculateAmt(bool ispriority){
  int amt=0;
  int dist=this->destination-this->origin;
  if(seats<2){
   amt= dist* (this->seats)* amtChargerkm *(ispriority?0.75:1);
  }else{
      amt= dist* (this->seats)* amtChargerkm *(ispriority?0.5:0.75); 
  }
 return amt;
}
class Rider: private Person{
private: 
vector<Ride>completedRide;
 Ride currentRide;
public:
Rider(string);
void createRide(int,int,int,int);
void updateRide(int,int,int,int);
void withdraw(int);
int closeRide();
vector<Ride>getCompletedRide(){
     return completedRide;
}
};
void Rider::createRide(int id,int origin,int destination,int seats){
     if(origin>destination){
          cout<<"Origin is greater than destination,so Ride can not be created. ";
          return;
     }
     currentRide.setId(id);
     currentRide.setDestination(destination);
     currentRide.setOrigin(origin);
     currentRide.setSeats(seats);
     currentRide.setRideStatus(RideStatus::CREATED);
     cout<<"Ride is created with id "<<id<<endl;
}
void Rider::updateRide(int id,int origin,int destination,int seats){
     if(currentRide.getRideStatus()==RideStatus::COMPLETED||currentRide.getRideStatus()==RideStatus::WITHDRAWN){
          cout<<"Ride doesnt exists";
          return;
     }
     if(currentRide.getId()!=id){
          cout<<"Id not same as current ride, so cannot update ride.";
          return;
     }
     createRide(id,origin,destination,seats);
}
void Rider::withdraw(int id){
     if(currentRide.getRideStatus()==RideStatus::COMPLETED||currentRide.getRideStatus()==RideStatus::WITHDRAWN){
          cout<<"Ride doesnt exists";
          return;
     }
     if(currentRide.getId()!=id){
          cout<<"Id not same as current ride, so cannot update ride.";
          return;
     }
     currentRide.setRideStatus(RideStatus::WITHDRAWN); 
}
int Rider::closeRide(){
 if(currentRide.getRideStatus()!=RideStatus::CREATED){
      cout<<"Ride doesnt exists";
      return 0;
 }
 currentRide.setRideStatus(RideStatus::COMPLETED);
 completedRide.push_back(currentRide);
 return currentRide.calculateAmt(completedRide.size()>=10);  

}

Rider::Rider(string  name){
this->name=name;
}

class Driver:private Person{
Driver(string);
};
Driver:: Driver(string name){
this->name=name;
}




int main(){
Rider rider("Tejas");
rider.createRide(1,3,20,2);
cout<<rider.closeRide();
rider.closeRide();
}
