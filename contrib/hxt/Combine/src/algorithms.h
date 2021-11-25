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
 * Identity functor to serve as default template argument of ParallelArrayFiller
 */
template <typename T>
struct Identity {
  T operator()(const T& object){ return object; }
};

/**
 * Generic structure for a vector that can be filled by multiple threads
 * simultaneously.
 *
 * Element of type `BufferType` are stored in a separate buffer for each
 * thread. Whenever such a buffer fills up, they are converted to elements of
 * type `ValueType` and moved to the global array.
 *
 * The amount of elements in a buffer, determined by `BUFFER_SIZE`, can be
 * adjusted to reduce contention at the cost of more memory usage.
 * 
 * \author Kilian Verhetsel
 */
template<typename ValueType, typename BufferType = ValueType,
  typename Function = Identity<BufferType>, std::size_t BUFFER_SIZE = 4096>
class ParallelArrayFiller {
public:
  ParallelArrayFiller(int threadNum, std::vector<ValueType> &array, Function F = Function()):
    inResize_(false), numFill_(0),
    buffers_(nullptr), bufferSizes_(threadNum, 0),
    globalArray_(array), size_(0),
    function_(F)
    {
      if (hxtAlignedMalloc((void*)&buffers_,
                           sizeof(BufferType) * threadNum * BUFFER_SIZE) !=
          HXT_STATUS_OK)
        throw std::bad_alloc();
    }

  ~ParallelArrayFiller() {
    if (buffers_) hxtAlignedFree((void*)&buffers_);
  }

  /**
   * Reserves space in the global array. This operation is not thread safe.
   */
  void reserve(std::size_t n) {
    globalArray_.resize(n);
  }

  /**
   * Constructs an element in place in the buffer allocated for the current
   * thread.
   *
   * \param threadId Identifier of the current thread.
   * \param args Arguments for the constructor of an element of the buffer.
   */
  template<typename... Args>
  BufferType &emplaceBack(int threadId, Args &&... args) {
    flushIfNeeded(threadId);

    BufferType *buffer = &buffers_[BUFFER_SIZE * threadId];
    std::size_t size = bufferSizes_[threadId];
    new (buffer + size) BufferType(std::forward<Args>(args)...);
    return buffer[bufferSizes_[threadId]++];
  }

  /**
   * Copies an element in the buffer allocated for the thread.
   *
   * \param threadId Identifier of the current thread.
   * \param args Arguments for the constructor of an element of the buffer.
   */
  BufferType &pushBack(int threadId, const BufferType &obj) {
    flushIfNeeded(threadId);

    BufferType *buffer = &buffers_[BUFFER_SIZE * threadId];
    std::size_t size = bufferSizes_[threadId];
    new (buffer + size) BufferType(obj);
    return buffer[bufferSizes_[threadId]++];
  }

  /**
   * Moves an element in the buffer allocated for the thread.
   *
   * \param threadId Identifier of the current thread.
   * \param args Arguments for the constructor of an element of the buffer.
   */
  BufferType &pushBack(int threadId, BufferType &&obj) {
    flushIfNeeded(threadId);

    BufferType *buffer = &buffers_[BUFFER_SIZE * threadId];
    std::size_t size = bufferSizes_[threadId];
    new (buffer + size) BufferType(obj);
    return buffer[bufferSizes_[threadId]++];
  }

  /**
   * Removes the last.
   *
   * This is only guaranteed to work for elements that have been inserted since
   * the last time the buffer was flushed.
   */
  void popBack(int threadId) {
    int offset = --bufferSizes_[threadId];
    BufferType &value = buffers_[BUFFER_SIZE * threadId + offset];
    value.~BufferType();
  }

  /**
   * Flushes the buffer of all threads.
   *
   * Must always be called after all elements have been pushed.
   */
  void flush() {
    std::size_t toAdd = 0;
    for (std::size_t i = 0; i < bufferSizes_.size(); i++)
      toAdd += bufferSizes_[i];
    globalArray_.resize(size_ + toAdd);

    for (std::size_t i = 0; i < bufferSizes_.size(); i++) {
      std::size_t start = size_;
      std::size_t size = bufferSizes_[i];

      BufferType *array = &buffers_[BUFFER_SIZE * i];
      for (std::size_t j = 0; j < size; j++) {
        new (&globalArray_[start + j])  ValueType(function_(array[j]));
        array[j].~BufferType();
      }

      size_ += size;
    }
  }

  /**
   * Copies data from a thread's buffer to the shared array, but only if the
   * thread's buffer is currently full.
   */
  void flushIfNeeded(int threadId) {
    if (bufferSizes_[threadId] == BUFFER_SIZE)
      flush(threadId);
  }

  /**
   * Copies data from a thread's buffer to the shared array.
   */
  void flush(int threadId) {
    std::size_t toReserve = bufferSizes_[threadId];
    copyBuffer(threadId, reserveEntries(toReserve), toReserve);
  }

private:
  /**
   * Reserves memory for entries in the global array.
   *
   * \param num The amount of objects to be inserted.
   * \return The index of a block of `num` consecutive objects.
   */
  std::size_t reserveEntries(std::size_t num) {
    std::unique_lock<std::mutex> lock(mutex_);
    while (inResize_ || numFill_ > 0)
      resizeVar_.wait(lock);

    inResize_ = true;

    std::size_t offset = size_;
    size_ += num;

    if (size_ >= globalArray_.size())
      globalArray_.resize(std::max((globalArray_.size() * 3) / 2,
                                   size_ + num));

    inResize_ = false;

    lock.unlock();
    resizeVar_.notify_one();
    fillVar_.notify_all();

    return offset;
  }

  /**
   * Copies data from a thread's buffer to the shared array.
   *
   * \param threadId The identifier of the current thread.
   * \param offset Offset within the shared array where data will be written.
   * \param num Amount of elements to copy.
   */
  void copyBuffer(int threadId, std::size_t offset, std::size_t num) {
    {
      std::unique_lock<std::mutex> lock(mutex_);
      while (inResize_) fillVar_.wait(lock);
      numFill_++;
    }

    BufferType *array = &buffers_[BUFFER_SIZE * threadId];
    for (std::size_t i = 0; i < num; i++) {
      new (&globalArray_[offset + i]) ValueType(function_(array[i]));
      array[i].~BufferType();
    }
    bufferSizes_[threadId] = 0;

    {
      std::lock_guard<std::mutex> lock(mutex_);
      numFill_--;
    }

    if (numFill_ == 0) resizeVar_.notify_one();
  }

private:
  /**
   * Mutex used to block acess to the shared array as well as status flags such
   * as \ref inResize_ and  \ref numFill_.
   */
  std::mutex mutex_;

  /**
   * Condition variable on which threads must wait before being allowed to
   * resize the buffer.
   */
  std::condition_variable resizeVar_;

  /**
   * Condition variable on which threads must wait before being allowed to copy
   * data from their local buffer to the shared array.
   */
  std::condition_variable fillVar_;

  /**
   * Flag set to true if a thread is currently in the process of resizing the
   * shared array.
   */
  bool inResize_;

  /**
   * Amount of threads currently filling the shared array.
   */
  std::size_t numFill_;

  /**
   * A buffer used by a single thread, before copying its contents to the global
   * array.
   */
  BufferType *buffers_;

  /**
   * Amount of elements used in each buffer.
   */
  std::vector<std::size_t> bufferSizes_;

  /**
   * Reference to a shared array, filled by multiple threads in parallel.
   */
  std::vector<ValueType> &globalArray_;

  /**
   * Amount of elements occupied in the shared array.
   *
   * The actual size of the vector is not used as the vector needs to be resized
   * before threads can start filling it.
   */
  std::size_t size_;

  /**
   * A function to convert a BufferType object to a ValueType object 
   */
  Function function_;
};

/**
* @}
*/

#endif
