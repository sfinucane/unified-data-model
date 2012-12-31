#ifndef SAF_UDM_ARCHIVABLE_H
#define SAF_UDM_ARCHIVABLE_H

#include <vector>

#include "UUID.h"   //universal unique identifier
#include "DatumField.h"

using namespace SAF::UnifiedDataModel::System;

namespace SAF{
namespace UnifiedDataModel{
namespace Foundation{

/** \class Archivable
 *  \brief Abstract; Represents an object which is capable of being decomposed and archived, as well as composed from archive data.
 *  \note Requires UUID, DatumField
 */
class Archivable
{
    public:
        /** Default constructor */
        Archivable();
        /** Default destructor */
        virtual ~Archivable();
        /** UUID Accessor
         *  \return The Universal Unique Identifier
         */
        UUID getUUID() const;
        /** UUID Mutator
         *  \param The new Universal Unique Identifier
         */
        void setUUID(const UUID& uuid);
        /** Decompose into attribute container objects
         *  \return A vector of attribute objects (DatumFields).
         */
        virtual std::vector<DatumField> decompose() const=0;
        /** Compose from attribute container objects
         *  \param attributes A vector filled with attribute container objects (DatumField).
         *  \return An Error object which indicates what error occurred.
         */
        virtual Error compose(const std::vector<DatumField>& attributes)=0;
    private:
        UUID m_UUID;
};

/** \class nullArchivable
 *  \brief Represents an empty archivable. Should be returned when no archivable can be retrieved.
 */
class nullArchivable : public Archivable
{
    public:
        nullArchivable(){};
        virtual ~nullArchivable(){};
        std::vector<DatumField> decompose(){return(std::vector<DatumField>());};
        Error compose(const std::vector<DatumField>& attributes){return( Error(Error::GENERIC_FAILURE, "Cannot compose a NULL Archivable!") );};
};

}   //end namespace Foundation
}   //end namespace UnifiedDataModel
}   //end namespace SAF
#endif // ARCHIVABLE_H
