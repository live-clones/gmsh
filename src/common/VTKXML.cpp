// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include "GmshConfig.h"
#include "VTKXML.h"
#include "OS.h"
#include "GmshMessage.h"

#if defined(HAVE_LIBZ)
#include <zlib.h>
#endif

vtkXMLWriter::vtkXMLWriter(FILE *fp, Encoding encoding)
  : _fp(fp), _encoding(encoding)
{
#if !defined(HAVE_LIBZ)
  if(_encoding == COMPRESSED) _encoding = BINARY;
#endif
}

std::string vtkXMLWriter::fileAttributes(bool lagrangeHexahedra) const
{
  const std::uint16_t one = 1;
  bool little = *(const unsigned char *)&one;
  std::string s = lagrangeHexahedra ? "version=\"2.2\"" : "version=\"1.0\"";
  s += " byte_order=\"";
  s += little ? "LittleEndian\"" : "BigEndian\"";
  if(_encoding != ASCII) s += " header_type=\"UInt64\"";
  if(_encoding == COMPRESSED) s += " compressor=\"vtkZLibDataCompressor\"";
  return s;
}

std::string vtkXMLWriter::escape(const std::string &s)
{
  std::string out;
  for(char c : s) {
    switch(c) {
    case '&': out += "&amp;"; break;
    case '<': out += "&lt;"; break;
    case '>': out += "&gt;"; break;
    case '"': out += "&quot;"; break;
    default: out += c;
    }
  }
  return out;
}

void vtkXMLWriter::_open(const std::string &name, const char *type,
                         int numComp)
{
  fprintf(_fp, "<DataArray type=\"%s\" Name=\"%s\"", type, name.c_str());
  if(numComp > 1) fprintf(_fp, " NumberOfComponents=\"%d\"", numComp);
  fprintf(_fp, " format=\"%s\">\n", _encoding == ASCII ? "ascii" : "binary");
}

void vtkXMLWriter::_base64(const unsigned char *data, std::size_t numBytes)
{
  static const char *t =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  std::string out;
  out.reserve(4 * ((numBytes + 2) / 3));
  std::size_t i = 0;
  for(; i + 2 < numBytes; i += 3) {
    unsigned int v = (data[i] << 16) | (data[i + 1] << 8) | data[i + 2];
    out += t[(v >> 18) & 63];
    out += t[(v >> 12) & 63];
    out += t[(v >> 6) & 63];
    out += t[v & 63];
  }
  if(i < numBytes) {
    bool two = (i + 1 < numBytes);
    unsigned int v = (data[i] << 16) | (two ? (data[i + 1] << 8) : 0);
    out += t[(v >> 18) & 63];
    out += t[(v >> 12) & 63];
    out += two ? t[(v >> 6) & 63] : '=';
    out += '=';
  }
  fwrite(out.data(), 1, out.size(), _fp);
}

void vtkXMLWriter::_binary(const void *data, std::size_t numBytes)
{
  const unsigned char *bytes = (const unsigned char *)data;
#if defined(HAVE_LIBZ)
  if(_encoding == COMPRESSED) {
    // header: number of blocks, block size, size of the last block if it is
    // partial, compressed size of each block; encoded apart from the blocks
    const std::size_t blockSize = 1 << 20;
    std::size_t numBlocks = (numBytes + blockSize - 1) / blockSize;
    std::vector<std::uint64_t> header(3 + numBlocks);
    header[0] = numBlocks;
    header[1] = blockSize;
    header[2] = numBytes % blockSize;
    std::vector<unsigned char> out, block(compressBound(blockSize));
    for(std::size_t b = 0; b < numBlocks; b++) {
      std::size_t n = std::min(blockSize, numBytes - b * blockSize);
      uLongf size = block.size();
      compress2(block.data(), &size, bytes + b * blockSize, n,
                Z_DEFAULT_COMPRESSION);
      header[3 + b] = size;
      out.insert(out.end(), block.begin(), block.begin() + size);
    }
    _base64((const unsigned char *)header.data(),
            header.size() * sizeof(std::uint64_t));
    _base64(out.data(), out.size());
    fprintf(_fp, "\n");
    return;
  }
#endif
  // header: number of bytes; encoded together with the data
  std::uint64_t header = numBytes;
  std::vector<unsigned char> all(sizeof(header) + numBytes);
  memcpy(all.data(), &header, sizeof(header));
  if(numBytes) memcpy(all.data() + sizeof(header), bytes, numBytes);
  _base64(all.data(), all.size());
  fprintf(_fp, "\n");
}

template <class T>
static void writeASCII(FILE *fp, const std::vector<T> &data, int numComp,
                       const char *format)
{
  int perLine = (numComp > 1) ? numComp : 10;
  for(std::size_t i = 0; i < data.size(); i++) {
    fprintf(fp, format, data[i]);
    fputc(((int)(i % perLine) == perLine - 1) ? '\n' : ' ', fp);
  }
  if(data.size() % perLine) fputc('\n', fp);
}

void vtkXMLWriter::dataArray(const std::string &name, int numComp,
                             const std::vector<double> &data)
{
  _open(name, "Float64", numComp);
  if(_encoding == ASCII)
    writeASCII(_fp, data, numComp, "%.16g");
  else
    _binary(data.data(), data.size() * sizeof(double));
  fprintf(_fp, "</DataArray>\n");
}

void vtkXMLWriter::dataArray(const std::string &name, int numComp,
                             const std::vector<std::int64_t> &data)
{
  _open(name, "Int64", numComp);
  if(_encoding == ASCII) {
    std::vector<long long> d(data.begin(), data.end());
    writeASCII(_fp, d, numComp, "%lld");
  }
  else
    _binary(data.data(), data.size() * sizeof(std::int64_t));
  fprintf(_fp, "</DataArray>\n");
}

void vtkXMLWriter::dataArray(const std::string &name, int numComp,
                             const std::vector<std::int32_t> &data)
{
  _open(name, "Int32", numComp);
  if(_encoding == ASCII)
    writeASCII(_fp, data, numComp, "%d");
  else
    _binary(data.data(), data.size() * sizeof(std::int32_t));
  fprintf(_fp, "</DataArray>\n");
}

void vtkXMLWriter::dataArray(const std::string &name, int numComp,
                             const std::vector<std::uint8_t> &data)
{
  _open(name, "UInt8", numComp);
  if(_encoding == ASCII) {
    std::vector<int> d(data.begin(), data.end());
    writeASCII(_fp, d, numComp, "%d");
  }
  else
    _binary(data.data(), data.size());
  fprintf(_fp, "</DataArray>\n");
}

std::string vtkXMLGrid::uniqueName(const std::string &name) const
{
  auto used = [&](const std::string &n) {
    for(auto &a : cellTags)
      if(a.name == n) return true;
    for(auto &a : pointData)
      if(a.name == n) return true;
    for(auto &a : cellData)
      if(a.name == n) return true;
    return false;
  };
  std::string n = name.empty() ? "data" : name;
  for(int i = 2; used(n); i++) n = name + " (" + std::to_string(i) + ")";
  return n;
}

bool vtkXMLGrid::write(const std::string &fileName, bool binary,
                       const std::string &comment) const
{
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }
  bool lagrangeHexahedra =
    (std::find(types.begin(), types.end(), 72) != types.end());

  vtkXMLWriter w(fp, binary ? vtkXMLWriter::COMPRESSED : vtkXMLWriter::ASCII);
  fprintf(fp, "<?xml version=\"1.0\"?>\n");
  fprintf(fp, "<!-- %s -->\n", comment.c_str());
  fprintf(fp, "<VTKFile type=\"UnstructuredGrid\" %s>\n",
          w.fileAttributes(lagrangeHexahedra).c_str());
  fprintf(fp, "<UnstructuredGrid>\n");
  fprintf(fp, "<Piece NumberOfPoints=\"%zu\" NumberOfCells=\"%zu\">\n",
          points.size() / 3, types.size());
  fprintf(fp, "<Points>\n");
  w.dataArray("Points", 3, points);
  fprintf(fp, "</Points>\n");
  fprintf(fp, "<Cells>\n");
  w.dataArray("connectivity", 1, connectivity);
  w.dataArray("offsets", 1, offsets);
  w.dataArray("types", 1, types);
  if(faces.size()) {
    w.dataArray("faces", 1, faces);
    w.dataArray("faceoffsets", 1, faceOffsets);
  }
  fprintf(fp, "</Cells>\n");
  fprintf(fp, "<PointData>\n");
  for(auto &a : pointData) w.dataArray(vtkXMLWriter::escape(a.name), a.numComp, a.data);
  fprintf(fp, "</PointData>\n");
  fprintf(fp, "<CellData>\n");
  for(auto &a : cellTags) w.dataArray(vtkXMLWriter::escape(a.name), 1, a.data);
  for(auto &a : cellData) w.dataArray(vtkXMLWriter::escape(a.name), a.numComp, a.data);
  fprintf(fp, "</CellData>\n");
  fprintf(fp, "</Piece>\n");
  fprintf(fp, "</UnstructuredGrid>\n");
  fprintf(fp, "</VTKFile>\n");
  fclose(fp);
  return true;
}

bool writePVD(const std::string &fileName,
              const std::vector<std::vector<std::string> > &files,
              const std::vector<double> &times)
{
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }
  fprintf(fp, "<?xml version=\"1.0\"?>\n");
  fprintf(fp, "<VTKFile type=\"Collection\" version=\"0.1\">\n");
  fprintf(fp, "<Collection>\n");
  for(std::size_t i = 0; i < files.size(); i++)
    for(std::size_t j = 0; j < files[i].size(); j++)
      fprintf(fp, "<DataSet timestep=\"%.16g\" part=\"%zu\" file=\"%s\"/>\n",
              times[i], j, vtkXMLWriter::escape(files[i][j]).c_str());
  fprintf(fp, "</Collection>\n");
  fprintf(fp, "</VTKFile>\n");
  fclose(fp);
  return true;
}

// Reading. VTK XML files are regular enough for a scanner of tags and
// attributes; a real XML parser would choke on raw appended data anyway.

namespace {

  struct xmlTag {
    std::string name;
    std::map<std::string, std::string> attributes;
    bool closing, empty;
    std::size_t contentStart; // what follows the tag
    std::string get(const std::string &key, const std::string &def = "") const
    {
      auto it = attributes.find(key);
      return it == attributes.end() ? def : it->second;
    }
  };

  std::string unescape(const std::string &s)
  {
    static const char *from[] = {"&lt;", "&gt;", "&quot;", "&apos;", "&amp;"};
    static const char *to[] = {"<", ">", "\"", "'", "&"};
    std::string out = s;
    for(int i = 0; i < 5; i++) {
      std::size_t pos = 0;
      while((pos = out.find(from[i], pos)) != std::string::npos) {
        out.replace(pos, strlen(from[i]), to[i]);
        pos++;
      }
    }
    return out;
  }

  // the next tag from pos on (comments and declarations skipped)
  bool nextTag(const std::string &s, std::size_t &pos, xmlTag &tag)
  {
    while(1) {
      pos = s.find('<', pos);
      if(pos == std::string::npos) return false;
      if(!s.compare(pos, 4, "<!--")) {
        pos = s.find("-->", pos);
        if(pos == std::string::npos) return false;
      }
      else if(pos + 1 < s.size() && (s[pos + 1] == '?' || s[pos + 1] == '!'))
        pos++;
      else
        break;
    }
    std::size_t end = pos + 1;
    // a '>' can only be found in a quoted value
    for(char quote = 0; end < s.size(); end++) {
      if(quote) {
        if(s[end] == quote) quote = 0;
      }
      else if(s[end] == '"' || s[end] == '\'')
        quote = s[end];
      else if(s[end] == '>')
        break;
    }
    if(end >= s.size()) return false;
    std::size_t i = pos + 1;
    tag.attributes.clear();
    tag.closing = (s[i] == '/');
    if(tag.closing) i++;
    tag.empty = (s[end - 1] == '/');
    std::size_t j = i;
    while(j < end && !isspace((unsigned char)s[j]) && s[j] != '/') j++;
    tag.name = s.substr(i, j - i);
    while(j < end) {
      while(j < end && (isspace((unsigned char)s[j]) || s[j] == '/')) j++;
      std::size_t k = j;
      while(k < end && s[k] != '=' && !isspace((unsigned char)s[k])) k++;
      if(k >= end) break;
      std::string key = s.substr(j, k - j);
      k = s.find_first_of("\"'", k);
      if(k == std::string::npos || k >= end) break;
      std::size_t l = s.find(s[k], k + 1);
      if(l == std::string::npos || l >= end) break;
      tag.attributes[key] = unescape(s.substr(k + 1, l - k - 1));
      j = l + 1;
    }
    tag.contentStart = end + 1;
    pos = end + 1;
    return true;
  }

  // Bytes out of raw data, or of base64 text: padding ends a run of encoded
  // bytes and another can follow (a header encoded apart from its data)
  class byteStream {
    const char *_p, *_end;
    bool _base64;
    unsigned char _buf[3];
    int _have, _idx;
    static int _value(char c)
    {
      if(c >= 'A' && c <= 'Z') return c - 'A';
      if(c >= 'a' && c <= 'z') return c - 'a' + 26;
      if(c >= '0' && c <= '9') return c - '0' + 52;
      if(c == '+') return 62;
      if(c == '/') return 63;
      return -1;
    }
    bool _group()
    {
      int v[4], n = 0;
      while(n < 4 && _p < _end) {
        char c = *_p++;
        if(c == '=')
          v[n++] = -2;
        else if(_value(c) >= 0)
          v[n++] = _value(c);
        else if(!isspace((unsigned char)c))
          return false;
      }
      if(n < 4 || v[0] < 0 || v[1] < 0) return false;
      _buf[0] = (v[0] << 2) | (v[1] >> 4);
      _have = 1;
      if(v[2] >= 0) {
        _buf[1] = ((v[1] & 15) << 4) | (v[2] >> 2);
        _have = 2;
        if(v[3] >= 0) {
          _buf[2] = ((v[2] & 3) << 6) | v[3];
          _have = 3;
        }
      }
      _idx = 0;
      return true;
    }

  public:
    byteStream(const char *p, const char *end, bool base64)
      : _p(p), _end(end), _base64(base64), _have(0), _idx(0)
    {
    }
    bool read(void *dst, std::size_t n)
    {
      unsigned char *d = (unsigned char *)dst;
      if(!_base64) {
        if((std::size_t)(_end - _p) < n) return false;
        memcpy(d, _p, n);
        _p += n;
        return true;
      }
      while(n) {
        if(_idx == _have && !_group()) return false;
        while(n && _idx < _have) {
          *d++ = _buf[_idx++];
          n--;
        }
      }
      return true;
    }
    // (the header of compressed data is a run of its own)
    void endRun() { _idx = _have = 0; }
  };

  void swapBytes(void *data, std::size_t size, std::size_t n)
  {
    unsigned char *p = (unsigned char *)data;
    for(std::size_t i = 0; i < n; i++, p += size)
      std::reverse(p, p + size);
  }

  struct vtuContext {
    const std::string *text;
    bool swap, header64, compressed;
    std::size_t appendedStart;
    bool appendedBase64;
  };

  bool readHeader(byteStream &in, const vtuContext &ctx, std::size_t n,
                  std::vector<std::uint64_t> &h)
  {
    h.resize(n);
    for(std::size_t i = 0; i < n; i++) {
      if(ctx.header64) {
        std::uint64_t v;
        if(!in.read(&v, 8)) return false;
        if(ctx.swap) swapBytes(&v, 8, 1);
        h[i] = v;
      }
      else {
        std::uint32_t v;
        if(!in.read(&v, 4)) return false;
        if(ctx.swap) swapBytes(&v, 4, 1);
        h[i] = v;
      }
    }
    return true;
  }

  bool readBytes(byteStream &in, const vtuContext &ctx,
                 std::vector<unsigned char> &bytes)
  {
    std::vector<std::uint64_t> h;
    if(!ctx.compressed) {
      if(!readHeader(in, ctx, 1, h)) return false;
      bytes.resize(h[0]);
      return bytes.empty() || in.read(bytes.data(), bytes.size());
    }
#if defined(HAVE_LIBZ)
    if(!readHeader(in, ctx, 3, h)) return false;
    std::size_t numBlocks = h[0], blockSize = h[1], lastSize = h[2];
    std::vector<std::uint64_t> sizes;
    if(!readHeader(in, ctx, numBlocks, sizes)) return false;
    in.endRun();
    bytes.resize(numBlocks ? (numBlocks - 1) * blockSize +
                               (lastSize ? lastSize : blockSize) : 0);
    std::vector<unsigned char> block;
    std::size_t done = 0;
    for(std::size_t b = 0; b < numBlocks; b++) {
      block.resize(sizes[b]);
      if(!in.read(block.data(), block.size())) return false;
      uLongf size = bytes.size() - done;
      if(uncompress(bytes.data() + done, &size, block.data(), block.size()) !=
         Z_OK)
        return false;
      done += size;
    }
    return done == bytes.size();
#else
    Msg::Error("Gmsh must be compiled with zlib to read compressed VTK files");
    return false;
#endif
  }

  template <class T, class Out>
  void convert(std::vector<unsigned char> &bytes, bool swap,
               std::vector<Out> &out)
  {
    std::size_t n = bytes.size() / sizeof(T);
    if(swap) swapBytes(bytes.data(), sizeof(T), n);
    out.resize(n);
    for(std::size_t i = 0; i < n; i++) {
      T v;
      memcpy(&v, &bytes[i * sizeof(T)], sizeof(T));
      out[i] = (Out)v;
    }
  }

  template <class Out>
  bool readDataArray(const xmlTag &tag, const vtuContext &ctx,
                     std::vector<Out> &out)
  {
    const std::string &s = *ctx.text;
    std::string format = tag.get("format", "ascii"), type = tag.get("type");
    out.clear();
    if(format == "ascii") {
      if(tag.empty) return true;
      const char *p = s.c_str() + tag.contentStart;
      while(1) {
        char *end;
        double v = strtod(p, &end);
        if(end == p) break;
        out.push_back((Out)v);
        p = end;
      }
      return true;
    }
    std::vector<unsigned char> bytes;
    if(format == "binary") {
      std::size_t end = s.find('<', tag.contentStart);
      if(tag.empty || end == std::string::npos) return false;
      byteStream in(s.c_str() + tag.contentStart, s.c_str() + end, true);
      if(!readBytes(in, ctx, bytes)) return false;
    }
    else if(format == "appended") {
      std::size_t start = ctx.appendedStart + strtoull(tag.get("offset", "0").c_str(), nullptr, 10);
      if(!ctx.appendedStart || start > s.size()) return false;
      byteStream in(s.c_str() + start, s.c_str() + s.size(),
                    ctx.appendedBase64);
      if(!readBytes(in, ctx, bytes)) return false;
    }
    else
      return false;

    if(type == "Float64") convert<double>(bytes, ctx.swap, out);
    else if(type == "Float32") convert<float>(bytes, ctx.swap, out);
    else if(type == "Int64") convert<std::int64_t>(bytes, ctx.swap, out);
    else if(type == "UInt64") convert<std::uint64_t>(bytes, ctx.swap, out);
    else if(type == "Int32") convert<std::int32_t>(bytes, ctx.swap, out);
    else if(type == "UInt32") convert<std::uint32_t>(bytes, ctx.swap, out);
    else if(type == "Int16") convert<std::int16_t>(bytes, ctx.swap, out);
    else if(type == "UInt16") convert<std::uint16_t>(bytes, ctx.swap, out);
    else if(type == "Int8") convert<std::int8_t>(bytes, ctx.swap, out);
    else if(type == "UInt8") convert<std::uint8_t>(bytes, ctx.swap, out);
    else return false;
    return true;
  }

  bool readFile(const std::string &fileName, std::string &text)
  {
    FILE *fp = Fopen(fileName.c_str(), "rb");
    if(!fp) {
      Msg::Error("Unable to open file '%s'", fileName.c_str());
      return false;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    text.resize(size > 0 ? size : 0);
    bool ok = text.empty() || fread(&text[0], 1, text.size(), fp) == text.size();
    fclose(fp);
    return ok;
  }

} // namespace

bool vtkXMLGrid::read(const std::string &fileName)
{
  std::string text;
  if(!readFile(fileName, text)) return false;

  vtuContext ctx;
  ctx.text = &text;
  ctx.swap = ctx.header64 = ctx.compressed = ctx.appendedBase64 = false;
  ctx.appendedStart = 0;

  // the appended data first, as the arrays that point to it come before
  xmlTag tag;
  std::size_t pos = 0, xmlEnd = text.size();
  if((pos = text.find("<AppendedData")) != std::string::npos) {
    xmlEnd = pos;
    if(!nextTag(text, pos, tag)) return false;
    ctx.appendedBase64 = (tag.get("encoding", "base64") != "raw");
    std::size_t mark = text.find('_', tag.contentStart);
    if(mark == std::string::npos) return false;
    ctx.appendedStart = mark + 1;
  }

  std::string section;
  bool found = false;
  pos = 0;
  while(pos < xmlEnd && nextTag(text, pos, tag)) {
    if(tag.contentStart > xmlEnd && tag.name != "AppendedData") break;
    if(tag.closing) {
      if(tag.name == section) section = "";
      continue;
    }
    if(tag.name == "VTKFile") {
      if(tag.get("type") != "UnstructuredGrid") {
        Msg::Error("'%s' is a VTK %s: only unstructured grids can be read",
                   fileName.c_str(), tag.get("type").c_str());
        return false;
      }
      const std::uint16_t one = 1;
      bool little = *(const unsigned char *)&one;
      ctx.swap = ((tag.get("byte_order", "LittleEndian") == "LittleEndian") !=
                  little);
      ctx.header64 = (tag.get("header_type", "UInt32") == "UInt64");
      std::string compressor = tag.get("compressor");
      ctx.compressed = !compressor.empty();
      if(ctx.compressed && compressor != "vtkZLibDataCompressor") {
        Msg::Error("Unsupported compression '%s' in '%s' (only zlib is)",
                   compressor.c_str(), fileName.c_str());
        return false;
      }
      found = true;
    }
    else if(tag.name == "Piece") {
      // the points are numbered from 0 in each piece
      _pieceStart = points.size() / 3;
      _pieceConnectivity = connectivity.size();
      _pieceFaces = faces.size();
    }
    else if(tag.name == "Points" || tag.name == "Cells" ||
            tag.name == "PointData" || tag.name == "CellData") {
      if(!tag.empty) section = tag.name;
    }
    else if(tag.name == "DataArray" && !section.empty()) {
      std::string name = tag.get("Name");
      bool ok = true;
      if(section == "Points") {
        std::vector<double> p;
        ok = readDataArray(tag, ctx, p);
        points.insert(points.end(), p.begin(), p.end());
      }
      else if(section == "Cells") {
        std::vector<std::int64_t> a;
        ok = readDataArray(tag, ctx, a);
        if(name == "connectivity") {
          for(auto &i : a) i += _pieceStart;
          connectivity.insert(connectivity.end(), a.begin(), a.end());
        }
        else if(name == "offsets") {
          for(auto &i : a) i += _pieceConnectivity;
          offsets.insert(offsets.end(), a.begin(), a.end());
        }
        else if(name == "types")
          types.insert(types.end(), a.begin(), a.end());
        else if(name == "faces") {
          // [number of faces, [number of points, points...]...] per cell
          for(std::size_t i = 0; i < a.size();) {
            std::int64_t numFaces = a[i++];
            for(std::int64_t f = 0; f < numFaces && i < a.size(); f++) {
              std::int64_t n = a[i++];
              for(std::int64_t k = 0; k < n && i < a.size(); k++)
                a[i++] += _pieceStart;
            }
          }
          faces.insert(faces.end(), a.begin(), a.end());
        }
        else if(name == "faceoffsets") {
          for(auto &i : a)
            if(i >= 0) i += _pieceFaces;
          faceOffsets.insert(faceOffsets.end(), a.begin(), a.end());
        }
      }
      else {
        std::vector<realArray> &arrays =
          (section == "PointData") ? pointData : cellData;
        realArray r;
        r.name = name;
        r.numComp = std::max(1, atoi(tag.get("NumberOfComponents", "1").c_str()));
        ok = readDataArray(tag, ctx, r.data);
        auto it = std::find_if(arrays.begin(), arrays.end(),
                               [&](const realArray &o) { return o.name == name; });
        if(it == arrays.end())
          arrays.push_back(r);
        else // another piece
          it->data.insert(it->data.end(), r.data.begin(), r.data.end());
      }
      if(!ok) {
        Msg::Error("Could not read data array '%s' in '%s'", name.c_str(),
                   fileName.c_str());
        return false;
      }
    }
  }
  if(!found) {
    Msg::Error("'%s' is not a VTK XML file", fileName.c_str());
    return false;
  }
  if(offsets.size() != types.size() ||
     (offsets.size() && offsets.back() != (std::int64_t)connectivity.size())) {
    Msg::Error("Inconsistent cells in '%s'", fileName.c_str());
    return false;
  }
  return true;
}

bool readPVD(const std::string &fileName,
             std::vector<std::vector<std::string> > &files,
             std::vector<double> &times)
{
  std::string text;
  if(!readFile(fileName, text)) return false;
  files.clear();
  times.clear();
  xmlTag tag;
  std::size_t pos = 0;
  while(nextTag(text, pos, tag)) {
    if(tag.closing || tag.name != "DataSet") continue;
    double t = atof(tag.get("timestep", "0").c_str());
    if(times.empty() || t != times.back()) {
      times.push_back(t);
      files.push_back(std::vector<std::string>());
    }
    files.back().push_back(tag.get("file"));
  }
  return !files.empty();
}
