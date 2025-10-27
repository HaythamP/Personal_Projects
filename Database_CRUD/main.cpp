#include <iostream>
#include <fstream>

#include "Database.h"
#include "InsertQuery.h"
#include "SearchQuery.h"
#include "UpdateQuery.h"
#include "RemoveQuery.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Database *dbptr = Database::buildFromSchema("firstName:text,lastName:text,studentNumber:int");
    Database &dbref = *dbptr;
    ifstream input("students.csv");
    input >> dbref;
    input.close();
    cout << dbref << endl
         << endl;   

    delete dbptr;
    return 0;
}
