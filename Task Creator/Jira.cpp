#include<bits/stdc++.h>
using namespace std;

class Sprint{
int start;
int end;
string name;
vector<Task>tasks;
public:
Sprint(int,int,string);
void addTask(Task);
getEnd() const { return end; }
int getStart() const { return start; }
string getName() const { return name; }

}
class Task{

}
class User{

}
Sprint::Sprint(int start,int end,string name){
    this->start=start;
    this->end=end;
    this->name=name;
}
void Sprint::addTask(Task &task){
    tasks.push_back(task);
}
int main(){

}