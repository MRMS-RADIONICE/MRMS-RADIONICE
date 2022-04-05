// Start the Serial Monitor and enter: x

/****TESTING DEVICES****/
// led - Test 8x8 
// imu - Test IMU 
// li2 - Test lidar 2m
// dgr - Test digital line sensors
// anr - Test analog line sensors 
// mot - Test motors
// msh - Motor short test
// ser - Test servo 

/*****CALIBRATING DEVICES*****/
// lic - Calibrating lidar
// cal - Calibrating line sensors

/*******MAIN FUNCTIONS********/
// go(left motors speed, right motors speed) - used to run the robot, values from -127 to 127
// line(sensor number) - if the sensor sees the line the value is true
// front() - reads the distance from the front LIDAR sensor
// frontLeft() - reads the distance from the front left LIDAR sensor 
// frontRight() - reads the distance from the front right LIDAR sensor 
// pitch() - reads the inclination of the robot, negative number represents that the robot is climbing and positive that is decending 
// servo(angle, servo number) - 0 is the big servo, 1 is the left finger servo, 2 is the right finger servo
// delayMs(delay in miliseconds) - Used with go to keep the motors runing
// display("string") - Dispalys a string on a 8x8 mrm display
// lineAny() - true if any line sensor detects a line
// end() - ends all the robots behaviour 
// stop() - stops the motors, usually combined with delayMs 

#pragma once
#include <mrm-8x8a.h>
#include <mrm-col-can.h>
#include <mrm-fet-can.h>
#include <mrm-imu.h>
#include <mrm-lid-can-b.h>
#include <mrm-lid-can-b2.h>
#include <mrm-mot4x3.6can.h>
#include <mrm-mot4x10.h>
#include "mrm-robot-line.h"
#include <mrm-servo.h>
#include <mrm-therm-b-can.h>