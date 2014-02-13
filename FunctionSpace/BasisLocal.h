#ifndef _BASISLOCAL_H_
#define _BASISLOCAL_H_

#include "Basis.h"

/**
   @interface BasisLocal
   @brief Common interface of all local Basis

   This class is the common interface for all local Basis.
 */

class BasisLocal: public Basis{
 public:
  //! Deletes this BasisLocal
  //!
  virtual ~BasisLocal(void);

 protected:
  //! @internal
  //! Instantiate a new BasisLocal
  //!
  //! @endinternal
  BasisLocal(void);
};

#endif
