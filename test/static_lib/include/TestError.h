#ifndef TESTERROR_H
#define TESTERROR_H

#include <iostream>
#include "Test.h"
#include "Error.h"

using namespace SAF::UnifiedDataModel::System;

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

class TestError : public Test
{
    public:
        /** Default constructor */
        TestError();
        /** Default destructor */
        virtual ~TestError();

        /** Error Class Unit Test Routine
         *  \return A boolean value which indicates success
         */
        bool testRoutine();

    private:
        Error m_uut;
};
}   //end namespace Tests
}   //end namespace UnifiedDataModel
}   //end namespace SAF
#endif // TESTERROR_H
