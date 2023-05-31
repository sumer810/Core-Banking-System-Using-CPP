#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <stdlib.h>
#include "headerfiles/Customer.h"
#include "headerfiles/BankClass.h"
#include "Databaseconnection/DatabaseConnector.h"
using namespace std;

int main() {
    
    DatabaseConnector dbConnector("tcp://127.0.0.1:3306", "root", "S1u2m3e4r@1234", "Banking");
   dbConnector.connect();
    Customer loginManager(&dbConnector);
    BankClass b1(&dbConnector);
    bool n=false;
       std::string name, password;
    do{
 
    std::cout << "Enter username: ";
    std::cin >> name;
    std::cout << "Enter password: ";
    std::cin >> password;
    
    
    std::string query = "SELECT * FROM UserInformation WHERE CustomerId = '" + name + "' AND Password = '" + password + "'";

    sql::Statement *stmt;
    stmt = dbConnector.getConnection()->createStatement();
    sql::ResultSet *res = stmt->executeQuery(query);

    if (res->next()) {
      string usertype = res->getString("UserType");
        
        if (usertype == "U") {
                loginManager.CustomerUI();
                
            }
            else if (usertype == "A") {
                b1.BankUI();
                
            }
            n = true;
    }
    else{
        cout<<"Invalid username and password"<<endl;
    }
    

    delete res;
    delete stmt;
    }
    while (!n);
   
    return 0;
}