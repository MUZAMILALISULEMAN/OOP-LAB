#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class DatabaseException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "A DATABASE ERROR OCCURRED.";
    }
};

// Derived Exception Classes
class ConnectionFailedException : public DatabaseException
{
};
class QueryTimeoutException : public DatabaseException
{
};

template <typename T>
class DatabaseConnector
{
private:
    string dbName;

public:
    DatabaseConnector(const string &name) : dbName(name) {}

    void establishConnection()
    {
        if (dbName == "invalid_db")
        {
            throw ConnectionFailedException();
        }
        else if (dbName == "slow_db")
        {
            throw QueryTimeoutException();
        }
        else
        {
            cout << "CONNECTED SUCCESSFULLY TO " << dbName << "!\n";
        }
    }
};

int main()
{
    try
    {
        cout << "ATTEMPTING TO CONNECT TO INVALID_DB...\n";
        DatabaseConnector<int> db1("invalid_db");
        db1.establishConnection();
    }
    catch (const ConnectionFailedException &e)
    {
        cout << "CAUGHT CONNECTIONFAILEDEXCEPTION WHAT(): " << e.what() << endl;
    }

    try
    {
        cout << "\nATTEMPTING TO CONNECT TO SLOW_DB...\n";
        DatabaseConnector<double> db2("slow_db");
        db2.establishConnection();
    }
    catch (const DatabaseException &e)
    {
        cout << "CAUGHT A GENERAL DATABASEEXCEPTION WHAT(): " << e.what() << endl;
    }

    return 0;
}