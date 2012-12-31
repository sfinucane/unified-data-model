#ifndef SAF_UDM_VOLATILEARCHIVE_H
#define SAF_UDM_VOLATILEARCHIVE_H

#include <string>
#include <vector>
#include <boost/unordered_map.hpp>

#include "Error.h"
#include "Archive.h"
#include "Archivable.h"

using namespace SAF::UnifiedDataModel::System;

namespace SAF{
namespace UnifiedDataModel{
namespace Foundation{

/** \class VolatileArchive
 *  \brief An in-memory, non-persistent archive implementation.
 *  \note Controller.
 *  \note Depends on the Boost::unordered_map data structure (version 1.52)
 */
class VolatileArchive : public Archive
{
    public:
        /** Default constructor */
        VolatileArchive();
        /** Default destructor */
        virtual ~VolatileArchive();
        /** Insertion Method
         *  \param item Item to be inserted/updated
         *  \return An Error object which indicates if an error occurred
         *  during the insertion/update
         */
        Error insert(const Archivable& item);
        /** General Retrieval Method
         *  \param uuid Universal Unique Identifier of the desired archivable object
         *  \param error An Error object which will be updated to indicate if an error occurred
         *  \return An Archivable object with the given UUID
         */
        Error retrieve(const UUID& uuid, Archivable& container);
        /** Is Open
         *  \return A boolean indicating whether the archive is open for use.
         */
        bool isOpen();
        /** Open Archive
         *  \brief Opens the archive for use.
         *  \return An Error object which indicates what error occurred.
         */
        Error open();
        /** Close Archive
         *  \brief Closes the archive. Performs all necessary garbage collection, resource releasing, etc.
         *  \return An Error object which indicates what error occurred.
         */
        Error close();
    private:
        bool m_Open;
        boost::unordered_map< std::string, std::vector<DatumField> > repository;
};
}   //end namespace Foundation
}   //end namespace UnifiedDataModel
}   //end namespace SAF
#endif // VOLATILEARCHIVE_H
