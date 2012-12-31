#ifndef SAF_UDM_DATUMFIELD_H
#define SAF_UDM_DATUMFIELD_H

#include <string>
#include <vector>

#include "Error.h"

using namespace SAF::UnifiedDataModel::System;

namespace SAF{
namespace UnifiedDataModel{
namespace Foundation{

/** \class DatumField
 *  \brief Abstract; augments a datum with field-related meta-data.
 */
class DatumField
{
    public:
        /** Default constructor */
        DatumField();
        /** Default destructor */
        virtual ~DatumField();
        /** Constructor with all parameters
         *  \param name The name of the field.
         *  \param type The type identifier for the field datum. Default is an empty string.
         *  \param rawData The raw (char) data form of the datum. Default is an empty vector of chars.
         */
        DatumField(std::string name, std::string type="", std::vector<char> rawData=std::vector<char>());
        /** Get Name
         *  \return The name of the field.
         */
        std::string getName() const;
        /** Set Name
         *  \param name The name of the field.
         */
        void setName(const std::string& name);
        /** Get Type
         *  \return The type identifier for the encapsulated datum.
         *  \note Type determinations are for the controller to determine.
         */
        std::string getType() const;
        /** Set Type Code
         *  \param type The type identifier for the encapsulated datum.
         *  \note Type determinations are for the controller to determine.
         */
        void setType(const std::string& type);
        /** Get Raw Data
         *  \return A vector containing the raw data as char.
         *  \note  return type indicates that type determinations are for the controller to determine.
         */
         std::vector<char> getRawData() const;
        /** Set Raw Data
         *  \param A vector containing the raw data as char.
         */
         Error setRawData(const std::vector<char>& rawData);
    private:
        std::string m_Name;
        std::string m_Type;
        std::vector<char> m_RawData;
};
}   //end namespace Foundation
}   //end namespace UnifiedDataModel
}   //end namespace SAF
#endif // DATUMFIELD_H
