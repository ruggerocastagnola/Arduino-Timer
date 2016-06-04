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

#include "Timer.h"

Timer::Timer() {
  // set default values
  duration = 1000;
  loop = false;

  _startTime = 0;
  _isActive = false;
}

// set the duration of a single cycle
void Timer::setDuration( int _duration ) {
  duration = _duration;
}

// get the duration of a single cycle
int Timer::getDuration() {
  return duration;
}

// set if the timer must be looping or not
void Timer::setLoop( bool _loop ) {
  loop = _loop;
}

// get if the timer is looping or not
bool Timer::isLoop() {
  return loop;
}

// get if the timer is currently running
bool Timer::isActive() {
  return _isActive;
}

// start the timer
void Timer::start() {
  _startTime = millis();
  _isActive = true;
}

// convenience method to start the timer setting 
// duration and loop flag right away
void Timer::start( int _duration, bool _loop ) {
  setLoop( _loop );
  setDuration( _duration );
  start();
}

// stop the timer
void Timer::stop() {
  _startTime = -1;
  _isActive = false;
}

// check how much time has passed since Timer::start()
// if loop = false and the Timer::hasFinished(), returns -1
int Timer::checkTime() {
  if( !isFinished() ) {
    return millis() - _startTime;
  } else {
    return -1;
  }
}

// check if the timer has finished this cycle
bool Timer::isFinished() {
  if( _isActive ) {

    int _passedTime = millis() - _startTime;
    if( _passedTime >= duration ) {

      if( loop ) {
        start();
      } else {
        stop();
      }
      
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}

// convenience method with callback
bool Timer::isFinished( void(*callback)() ) {
  if( _isActive ) {

    int _passedTime = millis() - _startTime;
    if( _passedTime >= duration ) {
      
      if( callback )
        callback();

      if( loop ) {
        start();
      } else {
        stop();
      }
      
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}