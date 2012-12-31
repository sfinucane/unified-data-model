#include "Archivable.h"

namespace SAF{
namespace UnifiedDataModel{
namespace Foundation{

Archivable::Archivable()
{
    //ctor
}

Archivable::~Archivable()
{
    //dtor
}

UUID Archivable::getUUID() const
{
    return(this->m_UUID);
}

void Archivable::setUUID(const UUID& uuid)
{
    this->m_UUID = uuid;
}

}   //end namespace Foundation
}   //end namespace UnifiedDataModel
}   //end namespace SAF
