// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef VTK_XML_H
#define VTK_XML_H

#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>

// Writes the data arrays of VTK XML files (.vtu, .vtp, ...), inline: as text,
// or as base64 with a UInt64 header, compressed with zlib if available.
class vtkXMLWriter {
public:
  enum Encoding { ASCII, BINARY, COMPRESSED };

  // falls back to BINARY if COMPRESSED is asked for without zlib
  vtkXMLWriter(FILE *fp, Encoding encoding);

  // the attributes to give the VTKFile element; VTK reads the Lagrange
  // hexahedra of files older than version 2.2 with another edge order
  std::string fileAttributes(bool lagrangeHexahedra = false) const;

  // a string as the value of an attribute
  static std::string escape(const std::string &s);

  void dataArray(const std::string &name, int numComp,
                 const std::vector<double> &data);
  void dataArray(const std::string &name, int numComp,
                 const std::vector<std::int64_t> &data);
  void dataArray(const std::string &name, int numComp,
                 const std::vector<std::int32_t> &data);
  void dataArray(const std::string &name, int numComp,
                 const std::vector<std::uint8_t> &data);

private:
  FILE *_fp;
  Encoding _encoding;
  void _open(const std::string &name, const char *type, int numComp);
  void _binary(const void *data, std::size_t numBytes);
  void _base64(const unsigned char *data, std::size_t numBytes);
};

// An unstructured grid and its data, as a .vtu file holds them. Polyhedra
// are described by their faces as well, for which the other cells have a -1.
struct vtkXMLGrid {
  struct intArray {
    std::string name;
    std::vector<std::int32_t> data;
  };
  struct realArray {
    std::string name;
    int numComp;
    std::vector<double> data;
  };
  std::vector<double> points;
  std::vector<std::int64_t> connectivity, offsets, faces, faceOffsets;
  std::vector<std::uint8_t> types;
  std::vector<intArray> cellTags;
  std::vector<realArray> pointData, cellData;
  // what VTK calls GlobalNodeIds: the same number for the copies of a point
  // in the pieces of a partitioned grid (empty if not needed)
  std::vector<std::int64_t> globalNodeIds;
  // a name no other array has
  std::string uniqueName(const std::string &name) const;
  bool write(const std::string &fileName, bool binary,
             const std::string &comment) const;
  // the .pvtu file that makes one grid of pieces written with write(), all
  // with the arrays of this one
  bool writeParallel(const std::string &fileName,
                     const std::vector<std::string> &pieces,
                     const std::string &comment) const;
  // the pieces of the file (a .vtu, or a .pvtu and the files it lists) merged
  // in one grid; all the data arrays are read as reals
  bool read(const std::string &fileName);

private:
  std::size_t _pieceStart = 0, _pieceConnectivity = 0, _pieceFaces = 0;
};

// The .pvd file that makes a time series (of one or several parts) out of
// files[step][part]
bool writePVD(const std::string &fileName,
              const std::vector<std::vector<std::string> > &files,
              const std::vector<double> &times);
bool readPVD(const std::string &fileName,
             std::vector<std::vector<std::string> > &files,
             std::vector<double> &times);

// How the elements of a MSH type are written: the VTK cell type (0 if none),
// and for each node of the VTK cell the index of the node in the element.
// Elements with no VTK equivalent are written as first order cells.
struct vtkXMLCell {
  int type;
  std::vector<int> nodes;
};
const vtkXMLCell &getVTKXMLCell(int mshType, bool warn = true);
// the MSH type of a VTK cell (0 if none)
int getMSHTypeOfVTKXMLCell(int vtkType, int numNodes);

#endif
