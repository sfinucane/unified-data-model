#include "Error.h"

namespace SAF {
namespace UnifiedDataModel {
namespace System {

Error::Error() : m_ErrorMsg()
{
    //ctor
    this->setErrorCode(this->NONE);
}

Error::~Error()
{
    //dtor
}

Error::Error(const Error& other) : m_ErrorMsg()
{
    //copy ctor
    this->setErrorCode(other.getErrorCode());
    this->setErrorMessage(other.getErrorMessage());
}

Error::Error(unsigned int err_code, const std::string& err_msg) : m_ErrorMsg()
{
    this->setErrorCode(err_code);
    this->setErrorMessage(err_msg);
}

//assignments operators
Error& Error::operator=(const Error& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    // basic assigment operator
    this->setErrorCode(rhs.getErrorCode());
    this->setErrorMessage(rhs.getErrorMessage());
    return *this;
}

Error& Error::operator=(const unsigned int& rhs)
{
    if ((void*)this == (void*)&rhs) return *this; // handle self assignment
    // error code assigment operator
    this->setErrorCode(rhs);
    return *this;
}

Error& Error::operator=(const std::string& rhs)
{
    if ((void*)this == (void*)&rhs) return *this; // handle self assignment
    // error code assigment operator
    this->setErrorMessage(rhs);
    return *this;
}

//accessors
unsigned int Error::getErrorCode() const
{
    return(this->m_ErrorCode);
}

std::string Error::getErrorMessage() const
{
    return(this->m_ErrorMsg);
}

//mutators
void Error::setErrorCode(unsigned int err_code)
{
    this->m_ErrorCode = err_code;
}

void Error::setErrorMessage(const std::string& err_msg)
{
    this->m_ErrorMsg = err_msg;
}

}   // end namespace System
}   // end namespace UnifiedDataModel
}   // end namespace SAF
