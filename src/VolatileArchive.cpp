#include "VolatileArchive.h"

using namespace SAF::UnifiedDataModel::System;

namespace SAF{
namespace UnifiedDataModel{
namespace Foundation{

VolatileArchive::VolatileArchive() : repository()
{
    //ctor
    this->m_Open = false;
}

VolatileArchive::~VolatileArchive()
{
    //dtor
}

Error VolatileArchive::insert(const Archivable& item)
{
    if(!(this->isOpen()))
        return( Error(Error::GENERIC_FAILURE, "Archive is closed!") );

    //invariant: archive is open.

    //decompose the archivable object:
    std::vector<DatumField> attribs;
    attribs = item.decompose();

    //insert:
    std::string uuid = item.getUUID().getValue();
    this->repository[uuid] = attribs;

    //check for success:
    bool success = ( this->repository.find(uuid) == this->repository.end() ) ? false : true;
    if(!success)
        return(Error( Error::GENERIC_FAILURE, "VolatileArchive insertion failed! UUID: " + item.getUUID().getValue() ));

    //success!
    return(Error(Error::NONE));
}

Error VolatileArchive::retrieve(const UUID& uuid, Archivable& container)
{
    if(!(this->isOpen()))
        return( Error(Error::GENERIC_FAILURE, "Archive is closed!") );

    //invariant: archive is open.

    //find the archivable object's components:
    std::vector<DatumField> attribs;
    attribs = this->repository[ uuid.getValue() ];

    return(container.compose(attribs));
}

bool VolatileArchive::isOpen()
{
    return(this->m_Open);
}

Error VolatileArchive::open()
{
    this->m_Open = true;
    return(Error(Error::NONE));
}

Error VolatileArchive::close()
{
    this->m_Open = false;
    return(Error(Error::NONE));
}

}   //end namespace Foundation
}   //end namespace UnifiedDataModel
}   //end namespace SAF
