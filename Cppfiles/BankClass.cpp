#include<iostream>
#include<regex>
#include "../headerfiles/BankClass.h"
#include "../Databaseconnection/DatabaseConnector.h"
#include <cppconn/prepared_statement.h>
#include <string>
#include<sstream>
using namespace std;

BankClass::BankClass(DatabaseConnector* connector) : dbConnector(connector) {}


void BankClass :: BankUI(){
    cout<<"Welcome to Bank clerk Page"<<endl;
    int x;
    cout<<"Enter 1 for Create CustomerAccount "<<endl;
    cout<<"Enter 2 for Delete CustomerAccount "<<endl;
    cout<<"Enter 3 for Modify Details"<<endl;
    cout<<"Enter 4 for Credit Money "<<endl;
    cout<<"Enter 5 for Debit Money "<<endl;
    cout<<"Enter 6 for Query "<<endl;
    cout<<"Enter Your Choice : ";
    cin>>x;

    switch(x){
        case 1:
            CreateAccount();
            break;
        case 2:
            DeleteCustomer();
            break;
        case 3:
            ModifyDetails();
            break;
        case 4:
            CreditMoney();
            break;
        case 5:
            DebitMoney();
            break;
        case 6 :
            Query();
            break;        
        default:
            cout<<"Please Enter Valid Choice:/n"<<endl;
            BankUI();
            break;
        }

    
}
void BankClass :: CreateAccount(){
        
std::string CustomerId, Name, Type, Address1, Address2, Address3, City, State, Country,PhoneNumber,Email,Pan,Password,UserType,AcntType,OpeningDate,Status;
    int Pincode, AccountNumber,UserId,LoginStatus;
    double Balance;

    std::cout << "Enter customer details:" << std::endl;
    std::cout << "Customer ID: ";
    std::cin >> CustomerId;

    // Check if the CustomerId is unique
    sql::Statement *stmt = dbConnector->getConnection()->createStatement();
    sql::ResultSet *res;
    do {
        stmt->execute("SELECT COUNT(*) FROM customerinformation WHERE CustomerId='" + CustomerId + "'");
        res = stmt->getResultSet();
        res->next();
        if (res->getInt(1) > 0) {
            std::cout << "Customer ID already exists. Please enter a unique CustomerId: ";
            std::cin >> CustomerId;
        }
    } while (res->getInt(1) > 0);
    delete res;
    delete stmt;
    cout<<"Password: ";
    cin>>Password;
    std::cout << "Name: ";
    std::cin>>Name;
    std::cout << "Type(Indivisual/Corporate): ";
    std::cin >> Type;
    std::cout << "Address line 1: ";
    std::cin>>Address1;
    std::cout << "Address line 2: ";
    std::cin>>Address2;
    std::cout << "Address line 3: ";
    std::cin>>Address3;
    std::cout << "City: ";
    std::cin>>City;
    std::cout << "State: ";
    std::cin >> State;
    std::cout << "Country: ";
    std::cin >> Country;
    std::cout << "Pin code: ";
    std::cin >> Pincode;
    cout<<"PhoneNumber: ";
    cin>>PhoneNumber;
    cout<<"Email: ";
    cin>>Email;
    cout<<"Pan:";
    cin>>Pan;
    cout<<"Acccount Number: ";
    cin>>AccountNumber;
    cout<<"Balance: ";
    cin>>Balance;
    cout<<"UserType: A/U ";
    cin>>UserType;
    cout<<"LoginStatus(0/1): ";
    cin>>LoginStatus;
    cout<<"Account Type(Saving/Current): ";
    cin>>AcntType;
    cout<<"Account opening Date : ";
    cin>>OpeningDate;
    cout<<"Status(Enabled/Disabled) : ";
    cin>>Status;
    UserId = 1000 + rand() % 9000;
    std::string UserIdStr = std::to_string(UserId);

// Check if the UserId is unique
do {
    stmt->execute("SELECT COUNT(*) FROM userinformation WHERE UserId='" + UserIdStr + "'");
    res = stmt->getResultSet();
    res->next();
    if (res->getInt(1) > 0) {
        UserId = 1000 + rand() % 9000;
        UserIdStr = std::to_string(UserId);
    }
} while (res->getInt(1) > 0);
delete res;
delete stmt;
// Convert UserId to string
    //  do {
    //     stmt->execute("SELECT COUNT(*) FROM userinformation WHERE UserId='" + UserId + "'");
    //     res = stmt->getResultSet();
    //     res->next();
    //     if (res->getInt(1) > 0) {
    //         std::cin >>UserId;
    //     }
    // } while (res->getInt(1) > 0);
    // delete res;
    // delete stmt;

    // Construct and execute the SQL query to insert the data
    
    std::string query = "INSERT INTO CustomerInformation (CustomerID, Name, Type, Address1, Address2, Address3, City, State, Country, Pincode, PhoneNumber,Email,Pan) VALUES ('" +
                        CustomerId + "', '" + Name + "', '" + Type + "', '" + Address1 + "', '" + Address2 + "', '" +
                        Address3 + "', '" + City + "', '" + State + "', '" + Country + "', '"+ std::to_string(Pincode)+"', '" +PhoneNumber+ "', '"+Email + "', '"+Pan+"')";
    
    sql::PreparedStatement *pstmt;
    pstmt = dbConnector->getConnection()->prepareStatement(query);
    sql::ResultSet *res2 = pstmt->executeQuery();

    // Close the connection
    
    string query1="INSERT INTO UserInformation(UserId,CustomerId,Password,UserType,LoginStatus) VALUES('" +UserIdStr + "', '" + CustomerId + "', '" + Password + "', '" + UserType + "', '" + to_string(LoginStatus) + "')";
    pstmt = dbConnector->getConnection()->prepareStatement(query1);
    sql::ResultSet *res1 = pstmt->executeQuery();
    // delete stmt;
    // delete dbConnector;
    string query2 = "insert into accountinformation(AccountNumber,Type,CustomerId,Status,Balance,OpeningDate) values('"+to_string(AccountNumber)+ "', '"+Type+"', '"+CustomerId+"', '"+Status+"', '"+to_string(Balance)+"', '"+OpeningDate+"')";
    
    pstmt = dbConnector->getConnection()->prepareStatement(query2);
    sql::ResultSet *res3 = pstmt->executeQuery();

    BankUI();
}
void BankClass :: DeleteCustomer(){
    cout<<"Welcome to DeleteCustomer"<<endl;
    string customerid;
    cout<<"Enter CustomerId to Delete :"<<endl;
    cin>>customerid;

    // sql::Statement *stmt = dbConnector->getConnection()->createStatement();
    // // sql::ResultSet *res;
    // // stmt = dbConnector->getConnection()->createStatement();
    std::string query = "DELETE from CustomerInformation where CustomerID='"+ customerid +"'" ;
//   stmt->executeQuery(query);
//   std::cout << "Customer deleted successfully!" << std::endl;
    // delete stmt;
    sql::PreparedStatement *pstmt;
    pstmt = dbConnector->getConnection()->prepareStatement(query);
    sql::ResultSet *res = pstmt->executeQuery();

    // sql::Statement *stmt1 = dbConnector->getConnection()->createStatement();
    string query1 = "Delete from userinformation where CustomerID='"+ customerid +"'";
    // stmt1->executeQuery(query1);
    // delete stmt1;
    // sql::Statement *stmt2 = dbConnector->getConnection()->createStatement();
  
    pstmt = dbConnector->getConnection()->prepareStatement(query1);
    sql::ResultSet *res1 = pstmt->executeQuery();

    string query2 = "Delete from accountinformation where CustomerId='"+customerid+"'";
    // stmt2->executeQuery(query2);
    // delete stmt2;

    pstmt = dbConnector->getConnection()->prepareStatement(query2);
    sql::ResultSet *res2= pstmt->executeQuery();
    cout<<"Customer deleted Successfully: "<<endl;
    BankUI();
}
void BankClass :: ModifyDetails(){
    string customerid;

    cout<<"Welcome to Modify Details"<<endl;
    cout<<"Enter Customer Id to Modify Details: "<<endl;
    cin>>customerid;
    string s1;
    string s2;
    cout<<"Enter  Name/Type(indiv/corp)/Address1/Address2/Address3/City/State/Country/Pincode/PhoneNumber/Email/Pan for modify: "<<endl;
    cin>>s1;
    cout<<"Enter new Value : "<<endl;
    cin>>s2;
     sql::Statement *stmt1 = dbConnector->getConnection()->createStatement();
        string query1 = "UPDATE customerinformation SET " + s1 + "='" + s2 + "' WHERE CustomerID='" + customerid + "'";
        stmt1->executeQuery(query1);

}
void BankClass :: CreditMoney(){
    cout<<"Welcome to Credit Money"<<endl;

}
void BankClass :: DebitMoney(){
    cout<<"Welcome to Debit Money"<<endl;
}
void BankClass :: Query(){
    cout<<"Welcome to Query Method"<<endl;
}
