#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class tel
{
public:
    int rollNO, roll1;
    char name[20];
    char div;
    char address[50];
    void accept()
    {
        cout << "\nEnter Roll Number:- ";
        cin >> rollNO;
        cout << "\nEnter the Name:";
        cin >> name;
        cout << "\nEnter the division:";
        cin >> div;
        cout << "\nEnter the address:";
        cin >> address;
    }
    void accept2()
    {
        cout << "Enter the Roll NO. to modify: ";
        cin >> rollNO;
    }
    void accept3()
    {
        cout << "\nEnter the name to modify:";
        cin >> name;
    }
    int getRollNo()
    {
        return rollNO;
    }
    void show()
    {
        cout << "\n\t" << rollNO << "\t\t" << name << "\t\t" << div << "\t\t" << address;
    }
};
int main()
{
    int i, n, ch, ch1, rec, start, count, add, n1, add2, start2, n2, y, a, b, on, oname, add3, start3, n3, y1, add4, start4, n4;
    char name[20], name2[20];
    tel t1;
    count = 0;
    fstream g, f;
    do
    {
        cout << "\n---------MENU------\n";
        cout << "\n1.Insert and Overwrite\n2.Show\n3.Search and Edit(number)\n4.Search and Edit(name)\n5.Search and Edit(only number)\n6.Search and Edit(only name)\n7.Delete a Student Record\n8.Exit\nEnter the choice:-  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            f.open("stuRecord.txt", ios::out);
        x:
            t1.accept();
            f.write((char *)&t1, (sizeof(t1)));
            cout << "Do yo want to enter more records ? \n1.Yes\n2.NO";
            cin >> ch1;
            if (ch1 == 1)
                goto x;
            else
            {
                f.close();
                break;
            }

        case 2:
            f.open("stuRecord.txt", ios::in);
            f.read((char *)&t1, (sizeof(t1)));
            while (f)
            {
                t1.show();
                f.read((char *)&t1, (sizeof(t1)));
            }
            f.close();
            break;

        case 3:
            cout << "Enter the roll number you want to find:";
            cin >> rec;
            f.open("stuRecord.txt", ios::in | ios::out);
            f.read((char *)&t1, (sizeof(t1)));
            while (f)
            {
                if (rec == t1.rollNO)
                {
                    cout << "\nRecord found";
                    add = f.tellg();
                    f.seekg(0, ios::beg);
                    start = f.tellg();
                    n1 = (add - start) / sizeof(t1);
                    f.seekp((n1 - 1) * sizeof(t1), ios::beg);
                    t1.accept();
                    f.write((char *)&t1, (sizeof(t1)));
                    f.close();
                    count++;
                    break;
                }
                f.read((char *)&t1, (sizeof(t1)));
            }
            if (count == 0)
                cout << "\nRecord not found";
            f.close();
            break;

        case 4:
            cout << "\nEnter the name you want to find and ecit:";
            cin >> name;
            f.open("stuTecord.txt", ios::in | ios::out);
            f.read((char *)&t1, (sizeof(t1)));
            while (f)
            {
                y = (strcmp(name, t1.name));
                if (y == 0)
                {
                    cout << "\nName found";
                    add2 = f.tellg();
                    f.seekg(0, ios::beg);
                    start2 = f.tellg();
                    n2 = (add2 - start2) / sizeof(t1);
                    f.seekp((n2 - 1) * sizeof(t1), ios::beg);
                    t1.accept();
                    f.write((char *)&t1, (sizeof(t1)));
                    f.close();
                    break;
                }
                f.read((char *)&t1, (sizeof(t1)));
            }
            break;

        case 5:
            cout << "\n\tEnter the roll number you want to modify: ";
            cin >> on;
            f.open("stuRecord.txt", ios::in | ios::out);
            f.read((char *)&t1, (sizeof(t1)));
            while (f)
            {
                if (on == t1.rollNO)
                {
                    cout << "\n\t Number found";
                    add3 = f.tellg();
                    f.seekg(0, ios::beg);
                    start3 = f.tellg();
                    n3 = (add3 - start3) / (sizeof(t1));
                    f.seekp((n3 - 1) * (sizeof(t1)), ios::beg);
                    t1.accept2();
                    f.write((char *)&t1, (sizeof(t1)));
                    f.close();
                    break;
                }
                f.read((char *)&t1, (sizeof(t1)));
            }
            break;

        case 6:
            cout << "\nEnter the name you want ot find and edit: ";
            cin >> name2;
            f.open("stuRecord.txt", ios::in | ios::out);
            f.read((char *)&t1, (sizeof(t1)));
            while (f)
            {
                y1 = (strcmp(name2, t1.name));
                if (y1 == 0)
                {
                    cout << "\n\t Name found";
                    add4 = f.tellg();
                    f.seekg(0, ios::beg);
                    start4 = f.tellg();
                    n4 = (add4 - start4) / (sizeof(t1));
                    f.seekp((n4 - 1) * sizeof(t1), ios::beg);
                    t1.accept3();
                    f.read((char *)&t1, (sizeof(t1)));
                    f.close();
                    break;
                }
                f.read((char *)&t1, (sizeof(t1)));
            }
            break;

        case 7:
            int roll;
            cout << "Please Enter the Roll No. of Student Whose Info You Want to Delete: ";
            cin >> roll;
            f.open("stuRecord.txt", ios::in);
            g.open("tmep.txt", ios::out);
            f.read((char *)&t1, (sizeof(t1)));
            while (!f.eof())
            {
                if (t1.getRollNo() != roll)
                    g.read((char *)&t1, (sizeof(t1)));
                f.read((char *)&t1, (sizeof(t1)));
            }
            cout << "The record with the roll no " << roll << " has been deleted" << endl;
            f.close();
            g.close();
            remove("stuRecord.txt");
            rename("temp.txt", "stuRecord.txt");
            break;

        case 8:
            cout << "\n\tThanks";
            break;

        default:
            cout << "Invalid";
            break;
        }
    } while (ch != 8);
    return 0;
}