// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstring>
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
