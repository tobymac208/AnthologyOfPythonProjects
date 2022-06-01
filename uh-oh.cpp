/* This source code is just a memory leak. */

#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
    std::string name;
    int age;
    std::string lname;
    std::string forMoreWastedSpace;

    Person() : name("adasd"), age(42), lname("waste it"), forMoreWastedSpace("yeah!"){
    }
};

int main(int argc, char** argv)
{
    while (1 == 1)
    {
        Person* ptr = (Person*)malloc(sizeof(Person) * 10);
        for(int i = 0; i < 10; i++) {
            *(&ptr + i) = new Person();
        }
    }
}
