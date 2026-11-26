// The MAT pipeline reports through Gmsh's message system (terminal, message
// console, log file, General.Verbosity), never on standard output.
//
// Short messages call Msg::Info directly. The diagnostic lines of the legacy
// filter and of the projection have many fields of several types and are
// written with stream insertion: matInfo is an output stream that hands each
// completed line to Msg::Info (a last line without end is sent when the
// stream is destroyed).
//
//   matInfo() << "surfaces=" << surfaces << " faces=" << faces;
//
//   matInfo report; // for the functions that write a report to a stream
//   mat.filterSmallTerminalBranches(colors, &report);
#ifndef MAT_MESSAGE_H
#define MAT_MESSAGE_H

#include <ostream>
#include <streambuf>
#include <string>
#include "GmshMessage.h"

class matInfo : public std::ostream {
public:
  matInfo() : std::ostream(nullptr) { rdbuf(&buffer_); }
  matInfo(const matInfo &) = delete;
  matInfo &operator=(const matInfo &) = delete;
  ~matInfo() { buffer_.send(); }

private:
  class Buffer : public std::streambuf {
  public:
    void send()
    {
      if(!line_.empty()) Msg::Info("%s", line_.c_str());
      line_.clear();
    }

  protected:
    int_type overflow(int_type c) override
    {
      if(traits_type::eq_int_type(c, traits_type::eof()))
        return traits_type::not_eof(c);
      put(traits_type::to_char_type(c));
      return c;
    }
    std::streamsize xsputn(const char *text, std::streamsize count) override
    {
      for(std::streamsize i = 0; i < count; ++i) put(text[i]);
      return count;
    }

  private:
    void put(char c)
    {
      if(c == '\n')
        send();
      else
        line_.push_back(c);
    }
    std::string line_;
  };
  Buffer buffer_;
};

#endif
