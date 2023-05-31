#include<iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include "../Databaseconnection/DatabaseConnector.h"
using namespace std;
class BankClass {
private:
    DatabaseConnector* dbConnector;
public:
    BankClass(DatabaseConnector* connector);
    void BankUI();
    void CreateAccount();
    void DeleteCustomer();
    void ModifyDetails();
    void CreditMoney();
    void DebitMoney();
    void Query();
};