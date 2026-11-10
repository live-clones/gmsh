#ifndef HXT_COMBINE_ALGORITHMS_
#define HXT_COMBINE_ALGORITHMS_

#include <algorithm>
#include <condition_variable>
#include <mutex>
#include <vector>

#include <string>
#include <hxt_tools.h>

/**
* \addtogroup Combine
* @{
*/

/**
* \file algorithms.h Useful C++ functions to operate on structures used in the Combine module
*
* \authors Jeanne Pellerin, Kilian Verhetsel
*/

inline std::string base_name(const std::string& path)
{
  return path.substr(path.find_last_of("/\\") + 1);
}

inline std::string remove_extension(const std::string& filename)
{
  const std::string::size_type p(filename.find_last_of('.'));
  return p > 0 && p != std::string::npos ? filename.substr(0, p) : filename;
}

void enumerateFiles( 
  const std::string& directory,
  const std::string& extension,
  std::vector<std::string>& filenames);

/** 
 *  Copy of the contents of a vector of vectors
 *  Vectors of vectors are not copied rightly by the standard library
 */
template<class T>
inline std::vector<std::vector<T>> copyVectorVector(const std::vector<std::vector<T>>& in) {
  std::vector<std::vector<T>> out(in.size());
  for (unsigned int i = 0; i <in.size(); ++i) {
    out[i] = in[i];
  }
  return out;
}

/**
*  Copy of the contents of a vector of vectors
*  Vectors of vectors are not copied rightly by the standard library
*/
template<class T>
inline void copyVectorVector(
  const std::vector<std::vector<T>>& in, std::vector<std::vector<T>>& out)
{
  out.resize(in.size());
  for (unsigned int i = 0; i <in.size(); ++i) {
    out[i] = in[i];
  }
}

inline unsigned int nbTrueValues(const std::vector<bool>& data)
{
  return std::count(data.begin(), data.end(), true);
}


/**
 * Functor compare the sizes of vector to sort them 
 */
struct VectorSizeCompare {
  template <class T>
  bool operator()(const std::vector<T>& A, const std::vector<T>& B) const {
    return A.size() < B.size();
  }
};

/**
* @}
*/

#endif
