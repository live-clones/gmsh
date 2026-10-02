// Numerical tests use the production scalar LBFGS implementation; only its
// application logging and wall clock dependencies are supplied here.
#include "GmshMessage.h"
#include <chrono>

void Msg::Info(const char *, ...) {}

double TimeOfDay()
{
  using Clock = std::chrono::steady_clock;
  return std::chrono::duration<double>(Clock::now().time_since_epoch()).count();
}
