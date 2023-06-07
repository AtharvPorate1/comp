#include <iostream>
#include <cstring>
using namespace std;
class Telephone
{
    unsigned long long key;
    int address;
    int num;
    unsigned long long mobile[10];
    string name[10];

public:
    Telephone()
    {

        for (int i = 0; i < 10; i++)
        {
            mobile[i] = 0;
        }
        for (int i = 0; i < 10; i++)
        {
            name[i] = "-";
        }
    }
    void insert_record()
    {
        cout << "Enter no of records you want to enter :- ";
        cin >> num;
        cout << "Which collision handling technique you want to use" << endl
             << "1. Linear Probing" << endl
             << "2. Quadratic Probing" << endl;
        int flag;
        cout << "Enter your choice :- ";
        cin >> flag;
        cout << endl;
        while (num--)
        {
            cout << "Enter Telephone Number :-";
            cin >> key;
            cout << endl;
            address = hash_function(key);
            if (mobile[address] == 0)
            {
                mobile[address] = key;
                cout << "Enter name of the person :-";
                cin >> name[address];
                cout << endl;
            }
            else if (flag == 1)
            {
                hash_collision_linear_probing(mobile, name, key);
            }
            else if (flag == 1)
            {
                hash_collision_quadratic_probing(mobile, name, key);
            }
        }
    }
    void hash_collision_linear_probing(unsigned long long mobile[], string name[], unsigned long long key)
    {
        int adr = hash_function(key);
        while (mobile[(adr % 10)] != 0)
        {
            adr++;
        }
        mobile[adr % 10] = key;
        cout << "Enter name of the person :-";
        cin >> name[adr % 10];
        cout << endl;
    }
    void hash_collision_quadratic_probing(unsigned long long mobile[], string name[], unsigned long long key)
    {
        int adr = hash_function(key);
        int i = 1;
        while (mobile[(adr % 10)] != 0)
        {
            adr += (i * i);
            i++;
        }
        mobile[adr % 10] = key;
        cout << "Enter name of person :-";
        cin >> name[adr % 10];
        cout << endl;
    }
    void display()
    {
        cout << "Index\tName\tMobile" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << "\t" << name[i] << "\t" << mobile[i] << endl;
        }
    }
    int hash_function(unsigned long long key)
    {
        return key % 10;
    }
};
int main()
{
    Telephone t1;
    int choice;
    char ch;
    do
    {
        cout << "*Telephone Directory*" << endl;
        cout << "1. Insert record in directory" << endl;
        cout << "2. Display Telephone Directory" << endl;
        cout << "3. Exit" << endl;
        cout << endl
             << "Enter your Choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            t1.insert_record();
            break;
        case 2:
            t1.display();
            break;
        }
    } while (choice < 3);
    cout << "Thanks" << endl;
    return 0;
}
