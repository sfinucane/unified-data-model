#include "TestError.h"

#include <sstream>

using namespace SAF::UnifiedDataModel::System;

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

TestError::TestError() : Test("Error"), m_uut()
{
    //ctor
}

TestError::~TestError()
{
    //dtor
}

bool TestError::testRoutine()
{
    //functional tests:

    this->printMessage("\tDefault Error Code: ");

    std::stringstream buffer;
    buffer << this->m_uut.getErrorCode() << "...\t\t";
    this->printMessage(buffer.str());

    //default error code should indicate NO ERROR.
    if(this->m_uut.getErrorCode() == Error::NONE)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }
    this->printMessage("\n");

    this->printMessage("\tDefault Error Message: \"" + this->m_uut.getErrorMessage() +"\"...\t\t");

    //default error message should be an EMPTY string
    if(this->m_uut.getErrorMessage() == "")
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }
    this->printMessage("\n");

    this->printMessage("\tAttempting to set error code to GENERIC FAILURE value...\t");
    this->m_uut.setErrorCode(Error::GENERIC_FAILURE);

    //the error code should be changed to GENERIC FAILURE value
    if(this->m_uut.getErrorCode() == Error::GENERIC_FAILURE)
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    this->printMessage("\n");

    std::string test_msg = "GENERIC FAILURE";
    this->printMessage("\tAttempting to set error message...\t");
    this->m_uut.setErrorMessage(test_msg);

    //the error message should be changed to "GENERIC FAILURE" value
    if(this->m_uut.getErrorMessage() == test_msg)
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
