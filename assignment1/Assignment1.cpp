#include<iostream>
#include<string>
using namespace std;
class student
{
    public:
    string Name ;
    int RollNumber ;
    string Course ;
    int age ;

     void GetDetails () 
    {
    cout<<"Student name is :"<<Name<<endl;
    cout<<"Student RollNumber is :"<<RollNumber<<endl;
    cout<<"Student Course is :"<<Course<<endl;
    cout<<"Student age is :"<<age<<endl;
    cout<< "------------------------"<<endl;
    }


};

int main ()
{
    student obj1;
    student obj2;
    student obj3;

    obj1.Name = "Parth Shrivastava";
    obj1.RollNumber = 134;
    obj1.Course = "B.Tech";
    obj1.age = 21;

    obj2.Name = "Abhijeet Thakur";
    obj2.RollNumber = 101;
    obj2.Course = "Phd";
    obj2.age = 22;

    obj3.Name = "Chandra gupta";
    obj3.RollNumber = 169 ;
    obj3.Course = "ILP";
    obj3.age = 23;

   obj1.GetDetails();
   obj2.GetDetails();
   obj3.GetDetails();
   

}