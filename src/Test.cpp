#include "Test.h"

namespace SAF {
namespace UnifiedDataModel {
namespace Tests {

Test::Test() : m_UnitName()
{
    //ctor
    //assume failed until tested!
    this->m_LastSuccess = false;
}

Test::~Test()
{
    //dtor
}

Test::Test(std::string unitName) : m_UnitName(unitName)
{
    //ctor with unit name param
    //assume failed until tested!
    this->m_LastSuccess = false;
}

bool Test::run(std::istream& instream, std::ostream& outstream)
{
    //set the input and output stream pointers FIRST!
    this->m_pInstream = &instream;
    this->m_pOutstream = &outstream;

    this->printHeader();

    bool succUnitTest = this->testRoutine();
    this->m_LastSuccess = succUnitTest;

    this->printMessage("\n");
    this->printFooter(succUnitTest);

    outstream.flush();

    return(succUnitTest);
}

bool Test::getLastSuccess() const
{
    return(this->m_LastSuccess);
}

std::string Test::getUnitName() const
{
    return(this->m_UnitName);
}

void Test::printMessage(const std::string& msg)
{
    if( this->m_pInstream == NULL || this->m_pOutstream == NULL )
        return;
    *(this->m_pOutstream) << msg;
    this->m_pOutstream->flush();
}

std::string Test::getInput() const
{
    std::string val;
    *(this->m_pInstream) >> val;

    return(val);
}

void Test::printHeader()
{
    std::string header = "\n[BEGIN Test on unit of type: ";
    header += this->getUnitName();
    header += "]\n";

    this->printMessage(header);
}

void Test::printFooter(bool success)
{
    std::string footer = "\n[END Test on unit of type: ";
    footer += this->getUnitName();
    footer += "] Result: ";

    this->printMessage(footer);

    if(success)
        this->printPassed();
    else
        this->printFailed();

    this->printMessage("\n");
}

void Test::printPassed()
{
    printMessage("[PASSED]");
}

void Test::printFailed()
{
    printMessage("[FAILED]");
}

}   // end namespace Tests
}   // end namespace UnifiedDataModel
}   // end namespace SAF
