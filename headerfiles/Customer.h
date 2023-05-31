#include<iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include "../Databaseconnection/DatabaseConnector.h"
using namespace std;
class Customer {
private:
    DatabaseConnector* dbConnector;

public:
    Customer(DatabaseConnector* connector);
    void CustomerUI();
    void ViewDetails();
    void MoneyTransfer();
    void Query();
};
