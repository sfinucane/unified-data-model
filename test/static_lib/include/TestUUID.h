#ifndef TESTUUID_H
#define TESTUUID_H

#include "Test.h"
#include "UUID.h"

using namespace SAF::UnifiedDataModel::Foundation;

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

class TestUUID : public Test
{
    public:
        /** Default constructor */
        TestUUID();
        /** Default destructor */
        virtual ~TestUUID();
        /** UUID Class Unit Test Routine
         *  \return A boolean value which indicates success
         */
        bool testRoutine();
    private:
        UUID m_uut;
};
}   //end namespace Tests
}   //end namespace UnifiedDataModel
}   //end namespace SAF
#endif // TESTUUID_H
