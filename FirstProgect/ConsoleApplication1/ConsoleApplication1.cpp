#include <iostream>
#include "ConsoleApplication1.h"

using namespace std;

class Person {
public:
    Person(string name, int height)
    {
        _name = name;
        _height = height;
    }
    ~Person() { cout << "Bye!" << endl; }

    void setName(string name) { _name = name; }
    string getName() const { return _name; }
private:
    string _name;
    int _height;
};
class Man: public Person {
public:
    Man (string name, int height): Person(name, height) {}

private:
    bool is_man = true;
};
class Women: public Person{
    public:
        Women(string name, int height) : Person(name, height) { cout << "RR" << endl; }
        string getName() const { return "No sex today!"; }
    private:
        bool is_man = false;
};

int main()
{
    Women person{"Sergey", 175};
    person.setName("Katy");
    cout << person.getName() << endl;
}