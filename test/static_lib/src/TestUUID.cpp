#include "TestUUID.h"

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

TestUUID::TestUUID() : Test("UUID"), m_uut()
{
    //ctor
}

TestUUID::~TestUUID()
{
    //dtor
}

bool TestUUID::testRoutine()
{
    //functional tests:

    //default value should be empty:
    this->printMessage("\tDefault Value: " + this->m_uut.getValue() + "...\t\t");
    if(this->m_uut.getValue() == "")
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    //should be able to change the value with method:
    this->printMessage("\n\tAttempting to set value...\t\t");
    std::string new_value = "0AF0";
    this->m_uut.setValue(new_value);

    if(this->m_uut.getValue() == new_value)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    //should be able to test value using only equality operator:
    this->printMessage("\n\tChecking the class equality operator...\t\t");
    if(this->m_uut == this->m_uut)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    this->printMessage("\n\tChecking the std::string equality operator...\t\t");
    if(this->m_uut == new_value)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    //should be able to change the value with assignment operator:
    this->printMessage("\n\tAttempting to assign a std::string value...\t\t");
    new_value = "0123456789";
    this->m_uut = new_value;

    if(this->m_uut.getValue() == new_value)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    // success!
    return(true);
}

}   //end namespace Tests
}   //end namespace UnifiedDataModel
}   //end namespace SAF
