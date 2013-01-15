#ifndef _BASISLOCAL_H_
#define _BASISLOCAL_H_

#include "Basis.h"

/**
   @interface BasisLocal
   @brief Common Interface of all Local Basis

   This class is the @em common @em interface for all Local Basis.
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
