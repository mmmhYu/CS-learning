#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class person
{
    public:
        string name;
        int age;
        person(string name,int age):name(name),age(age){}

};

void myprint(person p){
    cout << "name:" << p.name << " age:" << p.age << endl;
}

void test(vector<person> arr){
    for_each(arr.begin(),arr.end(),myprint);
}

int main(){
    person p1("Mike",17),p2("Joy",16);
    vector<person> arr = {p1,p2};
    test(arr);
}