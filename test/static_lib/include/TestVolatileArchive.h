#ifndef TESTARCHIVE_H
#define TESTARCHIVE_H

#include "Test.h"
#include "VolatileArchive.h"

using namespace SAF::UnifiedDataModel::Foundation;
using namespace SAF::UnifiedDataModel::System;

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

//a simple archivable object for testing:

const std::string SIMPLE_ARCHIVABLE_NAME = "SIMPLE_ARCHIVABLE";
const std::string SIMPLE_ARCHIVABLE_TYPE = "INTEGER";

class SimpleArchivable : public Archivable
{
    public:
        /** Default constructor */
        SimpleArchivable()
            {
                this->m_Value = 0;
            };
        /** Default destructor */
        virtual ~SimpleArchivable(){};
        /** Decompose into attribute container objects
         *  \return A vector of attribute objects (DatumFields).
         */
        std::vector<DatumField> decompose() const
            {
                //deconstruct the encapsulated integer value:
                std::vector<char> rawData;
                int sValue = sizeof(this->m_Value); // number of chars

                char* valueChars = (char*)&(this->m_Value);

                for(int i=0; i < sValue; ++i)
                {
                    rawData.push_back(valueChars[i]);
                }

                //invariant: rawData contains raw char version of the encapsulated integer value
                DatumField datValue;
                datValue.setName(SIMPLE_ARCHIVABLE_NAME);
                datValue.setType(SIMPLE_ARCHIVABLE_TYPE);
                datValue.setRawData(rawData);

                //invariant: datValue is an attribute object containing the value attribute

                //populate the returnable attribute list:
                std::vector<DatumField> attributes;
                attributes.push_back(datValue);

                return(attributes);
            };
        /** Compose from attribute container objects
         *  \param attributes A vector filled with attribute container objects (DatumField).
         *  \return An Error object which indicates what error occurred.
         */
        Error compose(const std::vector<DatumField>& attributes)
            {
                //iterate through the data and use any relevant data:
                for(unsigned int i=0; i < attributes.size(); ++i)
                {
                    std::string attrName = attributes[i].getName();
                    std::string attrType = attributes[i].getType();

                    if( attrName == SIMPLE_ARCHIVABLE_NAME && attrType == SIMPLE_ARCHIVABLE_TYPE )
                    {
                        //reconstruct the integer data:
                        std::vector<char> rawData = attributes[i].getRawData();

                        unsigned int sInt = sizeof(int);
                        int value = 0;
                        char* valueChars = (char*)&value;

                        for(unsigned int j=0; (j < sInt) && (j < rawData.size()); ++j)
                        {
                            valueChars[j] = rawData[j];
                        }

                        //invariant: value contains the reconstructed integer
                        this->m_Value = value;

                        //stops after first successful attribute encountered!
                        break;
                    }
                }

                return(Error(Error::NONE));
            };
        /** Set Value
         *  \param value The desired new value
         */
        void setValue(int value)
            {
                this->m_Value = value;
            };
        /** Get Value
         *  \return The encapsulated integer value.
         */
        int getValue() const
            {
                return(this->m_Value);
            };
    private:
        int m_Value;
};

class TestVolatileArchive : public Test
{
    public:
        /** Default constructor */
        TestVolatileArchive();
        /** Default destructor */
        virtual ~TestVolatileArchive();

        /** Volatile Archive Class Unit Test Routine
         *  \return A boolean value which indicates success
         */
        bool testRoutine();

    private:
        VolatileArchive m_uut;
};
}   //end namespace Tests
}   //end namespace UnifiedDataModel
}   //end namespace SAF
#endif // TESTARCHIVE_H
