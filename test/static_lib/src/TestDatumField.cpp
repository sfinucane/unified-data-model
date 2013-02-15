#include "TestDatumField.h"

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace SAF::UnifiedDataModel::Foundation;

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

TestDatumField::TestDatumField() : Test("DatumField")
{
    //ctor
}

TestDatumField::~TestDatumField()
{
    //dtor
}

bool TestDatumField::testRoutine()
{
    //functional testing:
    std::string fieldName = "TEST DATUM";
    this->m_uut.setName(fieldName);

    std::string typeName = "ASCII CHARACTER STRING";
    this->m_uut.setType(typeName);

    std::vector<char> rawData(fieldName.size());
    std::copy(fieldName.begin(), fieldName.end(), rawData.begin());

    this->m_uut.setRawData(rawData);

    //ensure that all mutator operations functioned properly:
    this->printMessage("\tChecking the ability to set values...\t\t");

    if(this->m_uut.getName() == fieldName && this->m_uut.getType() == typeName && this->m_uut.getRawData() == rawData)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    this->printMessage("\n\tChecking Integrity of stored data...");
    this->printMessage("\n\t\tInitial Data: " + fieldName);

    std::string final_data;
    for(unsigned int i=0; i < rawData.size(); ++i)
    {
        final_data += "0";
    }

    std::copy(rawData.begin(), rawData.end(), final_data.begin());
    this->printMessage(" | Final Data: " + final_data + "\t");

    if(fieldName == final_data)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    //store integer data, and test integrity of stored data:
    int testInteger = 2012;
    unsigned int sInt = sizeof(int); // number of chars

    char* testIntegerChars = (char*)&testInteger;

    rawData.clear();
    for(unsigned int i=0; i < sInt; ++i)
    {
        rawData.push_back(testIntegerChars[i]);
    }

    //for completeness, pass the data through the object:
    this->m_uut.setRawData(rawData);
    rawData = this->m_uut.getRawData();

    //convert back to integer:
    int testIntegerFinal = 0;
    testIntegerChars = (char*)&testIntegerFinal;

    for(unsigned int i=0; (i < sInt) && (i < rawData.size()); ++i)
    {
        testIntegerChars[i] = rawData[i];
    }

    std::stringstream buffer;
    buffer << "\n\t\tInitial Data: " << testInteger << " | Final Data: " << testIntegerFinal << "\t";

    this->printMessage(buffer.str());

    if(testInteger == testIntegerFinal)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    //success!
    return(true);
}

}   //end namespace Tests
}   //end namespace UnifiedDataModel
}   //end namespace SAF
