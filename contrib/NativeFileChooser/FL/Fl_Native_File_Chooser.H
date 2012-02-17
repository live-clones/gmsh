//
// Fl_Native_File_Chooser.H -- FLTK native OS file chooser widget
//
// Copyright 2004 by Greg Ercolano.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
// USA.
//

#ifndef FL_NATIVE_FILE_CHOOSER_H
#define FL_NATIVE_FILE_CHOOSER_H

// Use Windows' chooser
#ifdef _WIN32
#include <FL/Fl_Native_File_Chooser_WIN32.H>
#endif

// Use Apple's chooser
#ifdef __APPLE__
#include <FL/Fl_Native_File_Chooser_MAC.H>
#endif

// All else falls back to FLTK's own chooser
#if ! defined(__APPLE__) && !defined(_WIN32)
#include <FL/Fl_Native_File_Chooser_FLTK.H>
#endif

#endif /*FL_NATIVE_FILE_CHOOSER_H*/
