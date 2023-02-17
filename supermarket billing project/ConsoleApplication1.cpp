// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping::menu()
{m:
    int choise;
    string username;
    string password;

    cout << "\t\t......................................................." << endl;
    cout << "\t\t.....................THE MAIN MENU....................." << endl<<endl;
    cout << "\t\t......................................................." << endl;
    cout << "\t\t|         (1)Adminstrator         |" << endl << endl;
    cout << "\t\t|         (2)Buyer                |" << endl << endl;
    cout << "\t\t|         (3)Exit                 |" << endl<<endl;
    cout << "\t\tplease enter your choise " << endl;
    cin >> choise;
    switch (choise) {
    case 1: {
        cout << "\t\t      |Please enter user name and password|      " << endl << endl;
        cout << "\t\t Enter the user name :";
        cin >> username;
        cout << "\t\t Enter the password:";
        cin >> password;
        if (username == "bunny" && password == "anjana225") {
            administrator();
        }
        else {
            cout << " Access denied " << endl;

        }
        break;
    }
    case 02:{
        buyer();
          }
    case 03: {
        exit(0);
    }
    default:cout << "Enter valid option.... " << endl;
    }
    goto m;
}

void shopping::administrator() {
    int choise;
    m:
    cout << "\t\t\t.........ADMINISTRATOR MENU........." << endl<<endl;
    cout << "\t\t\t|       (1)Add new product         |" << endl << endl;
    cout << "\t\t\t|       (2)Modify the product      |" << endl << endl;
    cout << "\t\t\t|       (3)Delete the product      | " << endl << endl;
    cout << "\t\t\t|       (4)Go back to main menu    |" << endl << endl;
    cout << "\t\t enter your option : ";
    cin >> choise;

    switch (choise) {
    case 1:add();
        break;
    
    case 2:edit();
        break;
    
    case 3:rem();
        break;
    case 4:menu();
        break;
    default:
        cout << "invalid choise.." << endl;

    }
    goto m;

}
void shopping::buyer() {
    int choise;
    m:
    cout << "\t\t\t BUYERS MENU " << endl << endl;
    cout <<"...................................." << endl;
    cout << "\t\t(1)Buy a product " << endl<<endl;
    cout << "\t\t(2) Go bake to main manu" << endl << endl;
    cout << "Enter your chise :";
    cin >> choise;
    switch (choise) {
    case 1:receipt();
        break;
    case 2:menu();
        break;
    default:cout << "Invalid choise.." << endl;
    }
    goto m;
}
void shopping::add() {
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t  ADD NEW PRODUCT "<<endl<<endl;
    cout << "\t\t(1)product code of the product : ";
    cin >> pcode;
    cout << "\n\t\t(2)name of the product :";
    cin >> pname;
    cout << "\n\t\t(3)price of the product :";
    cin >> price;
    cout << "\n\t\t(4)discout of the product :";
    cin >> dis;
    data.open("database.txt", ios::in);
    if (!data) {
        data.open("database.txt", ios::in | ios::app);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else {
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (c == pcode) {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1) {
            goto m;
        }
        else {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();

        }
        }
    cout << "\n\n\t\tYour record inserted"<<endl;
    }

void shopping::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\t\t\t MODIFY THE RECORD .." << endl << endl;
    cout << "\t\t product code:";
    cin >> pkey;
     
    data.open("database.txt", ios::in);   
    if (!data) {
        cout << "\n\nFile does not exist"<<endl;
    }
    else {
        data1.open("database1.txt.ios::app|ios::out");
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\t\tnew product code:";
                cin >> c;
                cout << "\t\tnew product name:";
                cin >> n;
                cout << "\t\tprice:";
                cin >> p;
                cout << "\t\tdiscount:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << endl;
                cout << "given record edited" << endl;
                token++;
            }
            else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0) {
            cout << "\n\nRecord not found sorry!";
        }
    }
    
}

void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token=0;
    cout << "\n\n\tDelete product..." << endl<<endl;
    cout << "\tEnter the product code:";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "n\file does not exist" << endl;
    }
    else {
        data1.open("database.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\nproduct delete succusfully" << endl;
                token++;
            }
            else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;

            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n product is not found" << endl;
        }
    }
}
void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    cout << endl<<endl;
    cout << " product\t\tname\t\tprice"<<endl;
    cout << endl << endl;
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << dis;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shopping::receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choise;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t RECEIPT "<<endl;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty database" << endl;

    }
    else {
        data.close();
        list();
        cout << endl;
        cout << "\n....................................\n";
        cout << "\n|                                   \n";
        cout << "\n         please place the oder      \n";
        cout << "\n|                                   \n";
        cout << "\n....................................\n";
        do {
            m:
            cout << "\n\nEnter the product code:";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity:";
            cin>>arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrq[i]) {
                    cout << "\n\n Dupicate product code"<<endl<<"Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If YES then press Y else no";
            cin >> choise;
} 
        while (choise == 'y');
cout << "\n\n\t\t\t..............RECEIPT.............\n";
cout << "\nProduct No\t product name\t product quantity\tprice\tamount\tamount with discount\n";
for (int i = 0; i < c; i++) {
    data.open("database.txt", ios::in);
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        if (pcode == arrc[i]) {
            amount = price * arrq[i];
            dis = amount - (amount * dis / 100);
            total = total + dis;
            cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
        }
        data >> pcode >> pname >> price >> dis;
    }
}
data.close();
    }
    cout << "\n....................................\n";
    cout << "\n\tTotal amount is =" << total;
    
}
int main()
{
    shopping s;
    s.menu();
    cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
