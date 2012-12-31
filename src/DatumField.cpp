#include "DatumField.h"

using namespace SAF::UnifiedDataModel::System;

namespace SAF{
namespace UnifiedDataModel{
namespace Foundation{

DatumField::DatumField() : m_Name(), m_Type(), m_RawData()
{
    //ctor
}

DatumField::~DatumField()
{
    //dtor
}

DatumField::DatumField(std::string name, std::string type, std::vector<char> rawData) : m_Name(name), m_Type(type), m_RawData(rawData)
{
    //ctor with all params
}

std::string DatumField::getName() const
{
    return(this->m_Name);
}

void DatumField::setName(const std::string& name)
{
    this->m_Name = name;
}

std::string DatumField::getType() const
{
    return(this->m_Type);
}

void DatumField::setType(const std::string& type)
{
    this->m_Type = type;
}

std::vector<char> DatumField::getRawData() const
{
    return(this->m_RawData);
}

Error DatumField::setRawData(const std::vector<char>& rawData)
{
    this->m_RawData = rawData;
    return(Error(Error::NONE));
}

}   //end namespace Foundation
}   //end namespace UnifiedDataModel
}   //end namespace SAF
