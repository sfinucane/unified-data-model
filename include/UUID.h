#ifndef SAF_UDM_UUID_H
#define SAF_UDM_UUID_H

#include <string>

namespace SAF {
namespace UnifiedDataModel {
namespace Foundation {

/** \class UUID
 *  \brief A container for Universal Unique Identifiers (generated elsewhere).
 */
class UUID
{
    public:
        /** Default constructor */
        UUID();
        /** Default destructor */
        virtual ~UUID();
        /** Copy constructor
         *  \param other Object to copy from
         */
        UUID(const UUID& other);
        /** Constructor with std::string value parameter
         *  \param value An initial value.
         */
        UUID(const std::string& value);
        /** Basic Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        UUID& operator=(const UUID& other);
        /** std::string Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        UUID& operator=(const std::string& other);
        /** Equality Operator
         *  \param rhs Another UUID object to which the UUID will be compared
         *  \return A bool indicating equality
         */
        bool operator==(const UUID& rhs) const;
        /** std::string Equality Operator
         *  \param rhs A std::string object to which the UUID will be compared
         *  \return A bool indicating equality
         */
        bool operator==(const std::string& rhs) const;
        /** General Value Accessor
         *  \return A string object containing the Universal Unique Identifier
         */
        virtual std::string getValue() const;
        /** General Value Mutator
         *  \param value A string object containing the new Universal Unique Identifier
         */
        virtual void setValue(const std::string& value);
    private:
        std::string m_Value;
};
}   // end namespace foundation
}   // end namespace devAssist
}   // end namespace SAF
#endif // UUID_H
