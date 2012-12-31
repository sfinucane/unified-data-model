#ifndef SAF_UDM_ARCHIVE_H
#define SAF_UDM_ARCHIVE_H

#include "Error.h"
#include "UUID.h"
#include "Archivable.h"

namespace SAF {
namespace UnifiedDataModel {
namespace Foundation {

/** \class Archive
 *  \brief Abstract Interface; requires the implementation of retrieval
 *  and insertion methods for various target archival media.
 *
 *  An archive represents a persistent data store. The detailed implementation of
 *  such a data store is left to the sub-types which inherit from Archive.
 *
 *  \note Controller.
 */
class Archive
{
    public:
        /** Default constructor */
        Archive();
        /** Default destructor */
        virtual ~Archive();
        /** Insertion Method
         *  \param item Item to be inserted/updated
         *  \return An Error object which indicates if an error occurred
         *  during the insertion/update
         */
        virtual Error insert(const Archivable& item)=0;
        /** General Retrieval Method
         *  \param uuid Universal Unique Identifier of the desired archivable object
         *  \param error An Error object which will be updated to indicate if an error occurred
         *  \return An Archivable object with the given UUID
         */
        virtual Error retrieve(const UUID& uuid, Archivable& container)=0;
        /** Is Open
         *  \return A boolean indicating whether the archive is open for use.
         */
        virtual bool isOpen()=0;
        /** Open Archive
         *  \brief Opens the archive for use.
         *  \return An Error object which indicates what error occurred.
         */
        virtual Error open()=0;
        /** Close Archive
         *  \brief Closes the archive. Performs all necessary garbage collection, resource releasing, etc.
         *  \return An Error object which indicates what error occurred.
         */
        virtual Error close()=0;
};
}   // end namespace foundation
}   // end namespace devAssist
}   // end namespace SAF
#endif // ARCHIVE_H
