// Internal numerical containment contract for extension and its kernel tests.
#ifndef MAT_EXTENSION_INTERNAL_H
#define MAT_EXTENSION_INTERNAL_H
#include "MatPipeline.h"
namespace matgmsh_native {
bool validateExtensionContainment(const Mesh&, const Mesh&, std::string&,
                                  double* outsideArea = nullptr);
}
#endif
