#ifndef SAF_UDM_TEST_H
#define SAF_UDM_TEST_H

#include <iostream>
#include <string>

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

class Test
{
    public:
        /** Default constructor */
        Test();
        /** Default destructor */
        virtual ~Test();
        /** Constructor with unit name parameter
         *  \param The name of the unit to be tested
         */
        Test(std::string unitName);
        /** Run test
         *  \param instream Input stream
         *  \param outstream Output stream
         *  \return A bool which indicates the success of the test
         */
        bool run(std::istream& instream, std::ostream& outstream);
        /** Get Last Error
         *  \return An Error object which indicates what error occurred on the previous run
         */
        bool getLastSuccess() const;
        /** Get Unit Name
         *  \return The name of the unit under test (uut)
         */
        std::string getUnitName() const;
    protected:
        /** Unit Test Routine
         *  \note Must be defined in sub-type.
         *  \note printMessage(std::string msg) is available for outputting text.
         *  \note std::string getInput() is available for gathering input text.
         *  \note printPassed() and printFailed() are available for outputting passed/failed labels.
         *  \brief The test routine for the specific unit under test (uut)
         *  \return A bool which indicates the success of the test
         */
        virtual bool testRoutine()=0;
        /** Print Message
         *  \brief Inserts the given message into the output stream
         *  \param msg The message to print
         */
        void printMessage(const std::string& msg);
        /** Get Input
         *  \brief Extracts a single datum from the input stream
         *  \return The text of a single datum from the input stream
         */
        std::string getInput() const;
        /** Print Passed
         *  \brief Inserts a standard PASSED label into the output stream
         */
        void printPassed();
        /** Print Failed
         *  \brief Inserts a standard FAILED label into the output stream
         */
        void printFailed();

    private:
        /** Print Test Routine Header
         *  \brief Unless overridden, this will insert a standard test routine header into the output stream
         */
        void printHeader();
        /** Print Test Routine Footer
         *  \brief Inserts a standard test routine footer into the output stream
         */
        void printFooter(bool success);

        bool m_LastSuccess;
        std::string m_UnitName;
        std::istream *m_pInstream;
        std::ostream *m_pOutstream;
};
}   // end namespace Tests
}   // end namespace UnifiedDataModel
}   // end namespace SAF
#endif // TEST_H
