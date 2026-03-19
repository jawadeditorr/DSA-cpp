#include <iostream>
using namespace std;

struct Student{
public:
    int rollNo;
    string name;
};//default--->private
struct Teacher{
    string subject;
    string name;
};//default--->public
int main(){
    Student s1;
    s1.rollNo = 182;//error because default=private in class
    Student s2;
    s2.rollNo = 182;
    Student s3;
    s3.rollNo = 182;
    Student s4;
    s4.rollNo = 182;

    Student array[4]={
        
    };

    Student s5;
    Student *p = &s5;
    p->rollNo = 45;
    return 0;
}