#ifndef SAF_UDM_TESTDATUMFIELD_H
#define SAF_UDM_TESTDATUMFIELD_H

#include "Test.h"
#include "DatumField.h"

using namespace SAF::UnifiedDataModel::Foundation;
using namespace SAF::UnifiedDataModel::System;

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

class TestDatumField : public Test
{
    public:
        /** Default constructor */
        TestDatumField();
        /** Default destructor */
        virtual ~TestDatumField();
        /** DatumField Class Unit Test Routine
         *  \return A boolean value which indicates success
         */
        bool testRoutine();
    private:
        DatumField m_uut;
};
}   //end namespace Tests
}   //end namespace UnifiedDataModel
}   //end namespace SAF
#endif // TESTDATUMFIELD_H
