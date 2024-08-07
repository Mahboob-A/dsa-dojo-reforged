
// Recap Basics: 070824, Wednesday, 09.00 am

#include <bits/stdc++.h>
#include "stack-template.h"

using namespace std;

int globalID = 101;

class Person
{

        int id;
        string name;
        float salary;

public:
        // Null Constructor
        Person()
        {
                name = "";
                id = -1;
                salary = -1.0;
        }

        void setName(string name)
        {
                this->name = name;
        }

        void setSalary(float salary)
        {
                this->salary = salary;
        }

        Person(string name, float salary)
        {
                setName(name);
                setSalary(salary);
                this->id = globalID;
                globalID++;
        }

        int getID()
        {
                return id;
        }

        float getSalary()
        {
                return salary;
        }

        string getName()
        {
                return name;
        }

        void print()
        {
                cout << "ID: " << id << " | " << "Name: " << name << " | " << "Salary: " << salary << "\n";
        }
};

void sol()
{
        Stack<Person> st;
        Person a("Kalam", 1001.34);
        Person b("Khan", 3453.08);
        Person c("Jamal", 3453.03);

        st.push(a);
        st.push(b);
        st.push(c);

        Person printObj;

        while (!st.empty())
        {
                // Person printObj;
                printObj = st.pop();
                printObj.print();
        }

        printObj = st.Top();
        printObj.print();

        cout << st.size() << endl; 
}

int main()
{

        sol();

        return 0;
}