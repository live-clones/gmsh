// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_COMPAT_H
#define GMSH_COMPAT_H

// Gates for language features newer than the C++17 baseline. Each one tests
// the feature-test macro and falls back to plain C++17.

// consteval (C++20): a function that must run at compile time. Falls back to
// constexpr, which also allows calls at runtime.
#if defined(__cpp_consteval)
#define GMSH_CONSTEVAL consteval
#else
#define GMSH_CONSTEVAL constexpr
#endif

// constinit (C++20): a static variable that must be initialized at compile
// time, with no code run at startup. Falls back to nothing.
#if defined(__cpp_constinit)
#define GMSH_CONSTINIT constinit
#else
#define GMSH_CONSTINIT
#endif

#endif
