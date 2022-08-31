#include<bits/stdc++.h>
using namespace std;
class System{
    list<Employee>employees;
    unordered_map<int,Employee*>map;
    public:
    System();
    void registerEmployee(Employee);
    void registerManager(int,int);
    void printDetails(int);
    void printDetails(string);
}
void System::registerEmployee(Employee employee){
    employees.push_back(employee);
    map[employee->getid()]=&employees.back();
}
void System::registerManager(int id,int managerid){
    if(!map.count(id)||!map.count(managerid)){
        cout<<"Either employee ormanager does not exixst";
    }
    map[id]->setManagerId(managerid);
    map[managerid]->addSubordinate(*(map[id]));
}
void System::printDetails(int id){
    if(!map.count(id)){
        cout<<"Id with this employee not registered";
    }
    cout<<id<<endl;
    cout<<map[id]->getname()<<endl;
}
class Employee{
    string name;
    int id;
    list<Employee>subordinate;
    int managerId;
public:
Employee(string);
 void addSubordinate(Employee);
 void genUniqueId();
 int getid();
 string getname();
 void setname(string);
 void setManagerId(int);
}
Employee::Employee(string name){
    this->name=name;
    this->id=genUniqueId();
    this->managerId=0;
}
void Employee::addSubordinate(Employee employee){
    subordinate.push_back(employee);
}
void Employee::genUniqueId(){
    static int uniqueid=1;
    id=uniqueid;
    uniqueid++;
}
int Employee::getid(){
return id;
}
string Employee::getname(){
    return name;
}
void Employee::setname(string name){
    this->name=name;
}
void Employee::setManagerId(int managerId){
    this->managerId=managerId;
}
int main(){
    return 0;
}