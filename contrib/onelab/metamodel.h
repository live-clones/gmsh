#include <string>

namespace onelab{ class client; }

int metamodel(const std::string &todo);
void initializeMetamodel(const std::string &, onelab::client *,  void (*wait)(double time));
