#include <iostream>
#include <vector>

#include "TestError.h"
#include "TestUUID.h"
#include "TestDatumField.h"
#include "TestVolatileArchive.h"

using namespace std;
using namespace SAF::UnifiedDataModel::Tests;

int main()
{
    vector<Test*> tests;

    //populate test list:
    Test* error_test = new TestError();
    tests.push_back(error_test);

    Test* uuid_test = new TestUUID();
    tests.push_back(uuid_test);

    Test* datumfield_test = new TestDatumField();
    tests.push_back(datumfield_test);

    Test* volatilearchive_test = new TestVolatileArchive();
    tests.push_back(volatilearchive_test);

    //run tests until either one fails, or done:
    vector<Test*>::iterator tstIter = tests.begin();
    for(; tstIter != tests.end(); ++tstIter)
    {
        bool passed = (*tstIter)->run(cin, cout);

        if(!passed)
            break;
    }

    //garbage collection:
    tstIter = tests.begin();
    for(; tstIter != tests.end(); ++tstIter)
    {
        delete (*tstIter);
        (*tstIter) = NULL;
    }

    return 0;
}
