/**
 * @file dlutil.h
 * @brief Utility functions (moslty timing)
 * @author Dominique LaSalle <lasalle@cs.umn.edu>
 * Copyright (c) 2013-2015, Dominique LaSalle
 * @version 1
 * @date 2013-09-11
 */


#ifndef DL_UTIL_H
#define DL_UTIL_H

#include "domlib.h"




/******************************************************************************
* Enums and Structs ***********************************************************
******************************************************************************/


typedef enum dl_timer_state_t {
  DL_TIMER_RUNNING = 1,
  DL_TIMER_STOPPED = 2
} dl_timer_state_t;


typedef struct dl_timer_t {
    double duration;
    double start;
    dl_timer_state_t state;
} dl_timer_t;




/******************************************************************************
* Function Prototypes *********************************************************
******************************************************************************/


/**
 * @brief Convert a set of elements to network byte order.
 *
 * @param dst Where to write the bytes.
 * @param src The source elements.
 * @param width The width of each element (in bytes).
 */
void dl_to_bytes(
    void * dst, 
    void const * src, 
    size_t width);


/**
 * @brief Convert a set of bytes in network byte order to native machine order.
 * 
 * @param dst Where to write the elmenents.
 * @param src Where to read the bytes from.
 * @param width The width of each elements.
 */
void dl_from_bytes(
    void * dst, 
    void const * src, 
    size_t width);


/**
 * @brief Retrieve the wall clock time from the system as a double (seconds
 * from the epoch).
 *
 * @return The seconds passed since 1/1/1970. 
 */
double dl_wctime(void);


/**
 * @brief Initialize a wall clock timer structure.
 *
 * @param timer The timer to initialize.
 */
void dl_init_timer(
    dl_timer_t * timer);


/**
 * @brief Start/resume a wall clock timer. 
 *
 * @param timer The timer to start/resume.
 *
 * @return The time on the timer when it starts.
 */
double dl_start_timer(
    dl_timer_t * timer);


/**
 * @brief Stop a wall clock timer.
 *
 * @param timer The timer to stop.
 *
 * @return The time on the timer.
 */
double dl_stop_timer(
    dl_timer_t * timer);


/**
 * @brief Reset a timer so that the elapsed time is 0.
 *
 * @param timer The timer to reset.
 *
 * @return The time on timer before it was cleared.
 */
double dl_reset_timer(
    dl_timer_t * timer);


/**
 * @brief Retrieve the amount of time on a (stopped) wall clock timer.
 *
 * @param timer The timer to get the time from.
 *
 * @return The elapsed time.
 */
double dl_poll_timer(
    dl_timer_t const * timer);


/**
 * @brief Combine the time of two timers.
 *
 * @param timer1 The timer to increase the duration of.
 * @param timer2 The timer to add to the first timer.
 *
 */
void dl_combine_timer(
    dl_timer_t * timer1,
    dl_timer_t const * timer2);


/**
 * @brief Compare the elapsed time in two timers. They should both be stopped.
 *
 * @param timer1 The first timer.
 * @param timer2 The second timer.
 *
 * @return The difference in elapsed time.
 */
double dl_diff_timer(
    dl_timer_t const * timer1, 
    dl_timer_t const * timer2);


/**
 * @brief Initialize the random seed using the system clock.
 */
void dl_init_rand(void); 


/**
 * @brief Set the random seed to use.
 *
 * @param seed The random seed.
 */
void dl_set_rand(
    unsigned int seed);


/**
 * @brief Generate a 32-bit random number.
 *
 * @return The generated number.
 */
unsigned int * dl_get_rand(void);




#endif
