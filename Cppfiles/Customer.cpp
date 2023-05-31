#include<iostream>
#include<regex>
#include "../headerfiles/Customer.h"
#include "../Databaseconnection/DatabaseConnector.h"
#include <cppconn/prepared_statement.h>
#include <string>
#include<sstream>
using namespace std;

Customer::Customer(DatabaseConnector* connector) : dbConnector(connector) {}

void Customer:: CustomerUI(){
    int x;
    cout<<"Welcome to customer page"<<endl;
    cout<<"Enter 1 for ViewDetails"<<endl;
    cout<<"Enter 2 for MoneyTransfer"<<endl;
    cout<<"Enter 3 for Query "<<endl;
    cout<<"Enter your Choice : ";
    cin>>x;

switch (x){
    case 1:
        ViewDetails();
        
        break;
    case 2:
        MoneyTransfer();
        break;
    case 3:
        Query();
        break;
    default:
        cout<<"Enter Valid Choice :\n";
        CustomerUI();
        break;    
    }
}
void Customer :: ViewDetails()
{
cout<<"Welcome to view Details Method"<<endl;
}
void Customer :: MoneyTransfer(){
    cout<<"Welcome to Money Transfer method"<<endl;

}

void Customer :: Query(){
cout<<"Welcome to Customer Query method"<<endl;

}
