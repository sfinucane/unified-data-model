#include "UUID.h"

namespace SAF {
namespace UnifiedDataModel {
namespace Foundation {

UUID::UUID() : m_Value()
{
    //ctor
}

UUID::~UUID()
{
    //dtor
}

UUID::UUID(const UUID& other) : m_Value()
{
    //copy ctor
    this->setValue(other.getValue());
}

UUID::UUID(const std::string& value) : m_Value()
{
    this->setValue(value);
}

UUID& UUID::operator=(const UUID& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //basic assignment operator
    this->setValue(rhs.getValue());

    return *this;
}

UUID& UUID::operator=(const std::string& rhs)
{
    if ((void*)this == (void*)&rhs) return *this; // handle self assignment
    //std::string assignment operator
    this->setValue(rhs);

    return *this;
}

bool UUID::operator==(const UUID& rhs) const
{
    if(this->getValue() == rhs.getValue())
        return(true);

    return(false);
}

bool UUID::operator==(const std::string& rhs) const
{
    if(this->getValue() == rhs)
        return(true);

    return(false);
}

std::string UUID::getValue() const
{
    return(this->m_Value);
}

void UUID::setValue(const std::string& value)
{
    this->m_Value = value;
}

}   // end namespace foundation
}   // end namespace devAssist
}   // end namespace SAF
