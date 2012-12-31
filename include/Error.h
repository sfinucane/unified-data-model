#ifndef SAF_UDM_ERROR_H
#define SAF_UDM_ERROR_H

#include <string>

namespace SAF {
namespace UnifiedDataModel {
/** \namespace System
 *  \brief All of the core system classes for the Development Assistance Framework
 */
namespace System {

/** \class Error
 *  \brief Represents an error (or lack thereof). Can be used to return error state information.
 */
class Error
{
    public:
        /** Default constructor */
        Error();
        /** Default destructor */
        virtual ~Error();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Error(const Error& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Error& operator=(const Error& other);
        /** Error code assignment operator
         *  \param rhs An unsigned int to assign error code from
         *  \return A reference to this
         */
        Error& operator=(const unsigned int& rhs);
        /** Error message assignment operator
         *  \param rhs std::string object to assign error message from
         *  \return A reference to this
         */
        Error& operator=(const std::string& rhs);
        /** General constructor with all parameters
         *  \param err_code Error code (see class constants)
         *  \param err_msg An error message
         */
        Error(unsigned int err_code, const std::string& err_msg="");
        /** Error code accessor
         *  \return An unsigned integer which indicates a specific system error (see class constants)
         */
        unsigned int getErrorCode() const;
        /** Error message accessor
         *  \return A std::string which contains a custom error message
         */
        std::string getErrorMessage() const;
        /** Error code mutator
         *  \param err_code The error code (see class constants)
         */
        void setErrorCode(unsigned int err_code);
        /** Error message mutator
         *  \param err_msg A custom error message (should be descriptive & suggest a solution)
         */
        void setErrorMessage(const std::string& err_msg);

        /** Error Codes
         */
        static const unsigned int NONE = 0;
        static const unsigned int GENERIC_FAILURE = 1;
    private:
        unsigned int m_ErrorCode;
        std::string m_ErrorMsg;
};
}   // end namespace System
}   // end namespace UnifiedDataModel
}   // end namespace SAF
#endif // ERROR_H
