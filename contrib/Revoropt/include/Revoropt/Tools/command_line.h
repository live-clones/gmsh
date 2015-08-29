// @licstart revoropt
// This file is part of Revoropt, a library for the computation and 
// optimization of restricted Voronoi diagrams.
//
// Copyright (C) 2013 Vincent Nivoliers <vincent.nivoliers@univ-lyon1.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
// @licend revoropt

#ifndef _REVOROPT_COMMAND_LINE_H_
#define _REVOROPT_COMMAND_LINE_H_

#include <algorithm>
#include <string>
#include <sstream>

namespace Revoropt {

char* get_cmd_option( char ** begin, char ** end, 
                      const std::string & option
                    ) {
    char ** itr = std::find(begin, end, "--" + option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmd_option_exists( char** begin, char** end, 
                        const std::string& option
                      ) {
    return std::find(begin, end, "--" + option) != end;
}

template<typename T>
bool get_cmd_value(
    char ** begin, 
    char** end, 
    const std::string& option,
    T* output
    ) {
  if(cmd_option_exists(begin, end, option)) {
    std::stringstream ss ;
    ss << get_cmd_option(begin, end, option) ;
    T t ;
    ss >> t ;
    if(!ss.fail()) {
      *output = t ;
      return true ;
    }
  }
  return false ;
}

} //end of namespace Revoropt

#endif
