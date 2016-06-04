/*
 * timer.h
 *
 * timer - A basic timer library for Arduino
 *
 * It is meant as a basic and rough timer utility
 * for reading values out of a sensor every n ms 
 * or triggering an action once.
 *
 * Extended from Daniel Shiffman's O-o timer for Processing
 * found in: Learning Processing, Example 10.5
 * Author: ruggerocastagnola@gmail.com
 * Released under the public domain
 *
 * This library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser
 * General Public License as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser
 * General Public License along with this library; if not,
 * write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#ifndef Timer_h
#define Timer_h

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

typedef void (*callback)(void);

class Timer {
    public: 
      // duration of a single loop
      int duration;

      // true/false if looping or not
      bool loop;

      // constructor
      Timer();

      // set the duration of a single cycle
      void setDuration(int);

      // get the duration of a single cycle
      int getDuration();

      // set if the timer is looping or not
      void setLoop(bool);

      // get if the timer is looping or not
      bool isLoop();

      // get if the timer is currently running
      bool isActive();

      // start the timer
      void start();

      // convenience method to start the timer setting 
      // duration and loop flag right away
      void start( int, bool );

      // stop the timer
      void stop();

      // check how much time has passed since Timer::start()
      // if loop = false and the Timer::hasFinished(), returns -1
      int checkTime();  

      // check if the timer has finished this cycle
      bool isFinished();

      // convenience method with callback
      bool isFinished( callback );
      
    private:
      // flag to determine whether the timer is running
      bool _isActive;

      // stores millis() when the timer starts running
      int _startTime;
  };

#endif