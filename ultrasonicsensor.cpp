/*
============================================================================
	File: 		ultrasonicsensor.cpp
	Part of:	program for IPASS
	Contains:	Implementation of the functions declared in
	the header file ultrasonicsensor.hpp
	Made by:	Arco Gelderblom 2016
	Distributed under the Boost Software License, Version 1.0.		
 	(See accompanying file LICENSE_1_0.txt in folder 'License' or 
	copy at http://www.boost.org/LICENSE_1_0.txt) 
============================================================================
*/

#include "ultrasonicsensor.hpp"

ultrasonic_sensor::ultrasonic_sensor(due::pin_out trig, due::pin_in echo) :
	trig( trig ),
	echo( echo )
{}

int ultrasonic_sensor::get_distance() {
	trig.set(0);
	hwlib::wait_us(5);
	trig.set(1);
	hwlib::wait_us(10);
	trig.set(0);
	while(echo.get() == 0);
	long long int time_start = hwlib::now_us();
	while(echo.get() == 1);
	long long int time_end = (hwlib::now_us() - time_start);
	int distance = ((time_end/2)/29); // sound of speed is 29 us per cm
	return distance;
}