/**
 * @file dlbuffer_headers.h
 * @brief Buffer function prototypes. Buffers are simply arraylists that allow
 * for the adding of elements at the end of the array, and dynamically 
 * expaneded. The elements in the buffer are accessed as:
 *
 * for (i=0;i<buf->size;++i) {
 *   elem = buf->elements[i];
 * }
 *
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-10-04
 */


/* prefixing ugliness */
#define DLBUFFER_PRE2(prefix,suffix) prefix ## _ ## suffix
#define DLBUFFER_PRE1(prefix,suffix) DLBUFFER_PRE2(prefix,suffix)
#define DLBUFFER_PUB(name) DLBUFFER_PRE1(DLBUFFER_PREFIX,name)
#define DLBUFFER_PRI(name) DLBUFFER_PRE1(_,DLBUFFER_PRE1(DLBUFFER_PREFIX,name))


/**
 * @brief The buffer structure.
 *
 */
typedef struct DLBUFFER_PUB(buffer_t) {
  size_t size; /* the number of elements in the buffer */
  size_t maxsize; /* size of the allocated array */
  size_t defsize; /* the initial maximum size */
  DLBUFFER_TYPE_T * elements; /* the elements in the buffer */
} DLBUFFER_PUB(buffer_t);


#ifndef DLBUFFER_STATIC



/**
 * @brief Initialization functino for the buffer.
 *
 * @param size The initial size of the buffer.
 * @param b The buffer structure to initialize
 *
 * @return The initialized buffer (b), unless an error is encountered.
 */
DLBUFFER_PUB(buffer_t) * DLBUFFER_PUB(buffer_init)(size_t size,
    DLBUFFER_PUB(buffer_t) * b);


/**
 * @brief Allocate and initialize a new buffer.
 *
 * @param size The initial maximum size of the allocated buffer.
 * 
 * @return The new buffer, or NULL if there is an error.
 */
DLBUFFER_PUB(buffer_t) * DLBUFFER_PUB(buffer_create)(size_t size);


/**
 * @brief This function adds an element to the buffer, and expands it if
 * necessary. If buf->size == buf->maxsize, the next call to thsi function will
 * cause the buffer to be expanded.
 *
 * @param val The value to add to the buffer.
 * @param b The buffer to which to add.
 *
 * @return The number of elements in the buffer, or 0 if there was an error.
 */
size_t DLBUFFER_PUB(buffer_add)(DLBUFFER_TYPE_T val, 
    DLBUFFER_PUB(buffer_t) * b);


/**
 * @brief Reset the size of the buffer to zero. This is a constant time
 * operation as it does not change the conents of the allocatd array.
 *
 * @param b The buffer to be cleared. 
 *
 * @return The number of elements removed from the buffer.
 */
size_t DLBUFFER_PUB(buffer_clear)(DLBUFFER_PUB(buffer_t) * b);


/**
 * @brief Reset the buffer to initial state. The array is re-allocated to the
 * size initially used to create the buffer and it's size is set to zero.
 *
 * @param b The buffer to be reset.
 *
 * @return The number of elements removed from the buffer.
 */
size_t DLBUFFER_PUB(buffer_reset)(DLBUFFER_PUB(buffer_t) * b);


/**
 * @brief De-allocate the buffer and any associated memory structures.
 *
 * @param b THe buffer to be free'd.
 */
void DLBUFFER_PUB(buffer_free)(DLBUFFER_PUB(buffer_t) * b);


#undef DLBUFFER_PRE2
#undef DLBUFFER_PRE1
#undef DLBUFFER_PUB
#undef DLBUFFER_PRI


#else


#define DLBUFFER_VISIBILITY static
#include "dlbuffer_funcs.h"
#undef DLBUFFER_VISIBILITY


#undef DLBUFFER_PRE2
#undef DLBUFFER_PRE1
#undef DLBUFFER_PUB
#undef DLBUFFER_PRI


#endif


