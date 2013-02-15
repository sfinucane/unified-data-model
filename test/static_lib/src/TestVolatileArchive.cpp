#include "TestVolatileArchive.h"

#include <sstream>

using namespace SAF::UnifiedDataModel::Foundation;
using namespace SAF::UnifiedDataModel::System;

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

TestVolatileArchive::TestVolatileArchive() : Test("VolatileArchive")
{
    //ctor
}

TestVolatileArchive::~TestVolatileArchive()
{
    //dtor
}

bool TestVolatileArchive::testRoutine()
{
    //open the archive:
    this->m_uut.open();

    if(!(this->m_uut.isOpen()))
        return(false);

    //boundary test: single item insertion and retrieval:
    SimpleArchivable arcItem0;
    UUID uuid0("0");

    arcItem0.setUUID(uuid0);
    arcItem0.setValue(1988);

    //attempt insertion:
    std::stringstream buffer;
    buffer << "\n\tAttempting insertion and retrieval...\n\t\t[inserting] UUID: " << uuid0.getValue() << " | VALUE: " << arcItem0.getValue();
    this->printMessage(buffer.str());

    this->m_uut.insert(arcItem0);

    //attempt retrieval:
    SimpleArchivable arcItem1;
    this->m_uut.retrieve(uuid0, arcItem1);

    //assign same UUID, as WE KNOW it is an EXACT duplicate.
    arcItem1.setUUID(uuid0);

    //clear conversion buffer
    std::stringstream buffer2;

    buffer2 << "\n\t\t[retrieved] UUID: " << arcItem1.getUUID().getValue() << " | VALUE: " << arcItem1.getValue() << "\t";
    this->printMessage(buffer2.str());

    if( arcItem1.getUUID() == arcItem0.getUUID() && arcItem1.getValue() == arcItem0.getValue() )    // equality operator instead, eh?
        this->printPassed();
    else
    {
        this->printFailed();
        return(false);
    }

    this->m_uut.close();

    //success!
    return(true);
}

}   //end namespace Tests
}   //end namespace UnifiedDataModel
}   //end namespace SAF
