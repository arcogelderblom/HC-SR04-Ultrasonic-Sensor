/*
============================================================================
	File: 		ultrasonicsensor.hpp
	Part of:	program for IPASS
	Contains:	Initializes everything for the ultrasonic
	sensor to work and makes sure there is a get_distance() 
	function to actually get distances.
	Made by:	Arco Gelderblom 2016
	Distributed under the Boost Software License, Version 1.0.		
 	(See accompanying file LICENSE_1_0.txt in folder 'License' or 
	copy at http://www.boost.org/LICENSE_1_0.txt) 
============================================================================
*/
/// @file

#ifndef ULTRASONICSENSOR_HPP
#define ULTRASONICSENSOR_HPP

#include "hwlib.hpp"

/// Ultrasonic Sensor class
//
/// This class sets up everything to get a distance from a ultrasonic sensor (HC-SR04).
class ultrasonic_sensor {
private:
	/// To start a measurement we need to send a single to the trig, because of this a pin_out.
	due::pin_out trig;
	/// Echo gives a pulse the length of time it takes for the sound to go back and forth, it is something we receive so it’s pin_in.
	due::pin_in echo;
public:
	/// Constructor ultrasonic sensor
	//
	/// Setup everything for the ultrasonic sensor to get a distance when needed
	ultrasonic_sensor(due::pin_out trig, due::pin_in echo);
	
	/// Get a distance reading from the sensor.
	//
	/// Set the trigger to start a pulse. Wait for the echo start returning a 		/// pulse and count how long the returning pulse is. Than calculate the 		/// distance and return this as a int for further use.
	int get_distance();
};

#endif //ULTRASONICSENSOR_HPP