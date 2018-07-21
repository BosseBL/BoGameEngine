/*
*  BO_Physics.cpp
*  BO
*
*  Created by Daniel Lindfors on 5/27/12.
*  Copyright 2012 KTH. All rights reserved.
*
*/

/* to do:
 * make the trigonometry in these classes waterproof
 
 */

#include "BO_Physics.h"
#include <math.h>


//class definitions

	//BO_Cartesian_2DVector

BO_Cartesian_2DVector::BO_Cartesian_2DVector() 
:x(0), y(0) {}
BO_Cartesian_2DVector::BO_Cartesian_2DVector(float xcor, float ycor) 
:x(xcor), y(ycor) {}

BO_Cartesian_2DVector BO_Cartesian_2DVector::operator+(BO_Cartesian_2DVector& v) {
	return BO_Cartesian_2DVector(x + v.getX(), y + v.getY());
}
BO_Cartesian_2DVector BO_Cartesian_2DVector::operator+(BO_Polar_2DVector& v) {
	BO_Cartesian_2DVector cv = v.toCartesian();
	return BO_Cartesian_2DVector(x + cv.getX(), y + cv.getY());
}
BO_Cartesian_2DVector BO_Cartesian_2DVector::operator-(BO_Cartesian_2DVector& v) {
	return BO_Cartesian_2DVector(x - v.getX(), y - v.getY());
}
BO_Cartesian_2DVector BO_Cartesian_2DVector::operator-(BO_Polar_2DVector& v) {
	BO_Cartesian_2DVector cv = v.toCartesian();
	return BO_Cartesian_2DVector(x - cv.getX(), y - cv.getY());
}

BO_Cartesian_2DVector::operator BO_Polar_2DVector() {
	return toPolar();
}

template<typename num> BO_Cartesian_2DVector BO_Cartesian_2DVector::operator*(num& i) {
	BO_Cartesian_2DVector v = &this;
	if (i < 0) {
		v.getX() = -v.getX();
		v.getY() = -v.getY();
		i = -i;
	}
	double t = sqrt( double(i) );
	v.getX() *= t;
	v.getX() *= t;
	return v;
}


BO_Polar_2DVector BO_Cartesian_2DVector::toPolar() {
	return BO_Polar_2DVector(getRadius(), getAngle());
}


float BO_Cartesian_2DVector::getAngle() { // not defined
	return atan(y/x);
}
float BO_Cartesian_2DVector::getRadius() { // not defined
	return sqrt(pow(x,2) + pow(y,2) );
}
float BO_Cartesian_2DVector::getX() {
	return x;
}
float BO_Cartesian_2DVector::getY() {
	return y;
}

void BO_Cartesian_2DVector::setX(float f) {
	x = f;
}
void BO_Cartesian_2DVector::setY(float f) {
	y = f;
}
void BO_Cartesian_2DVector::setAngle(float a) {
	BO_Polar_2DVector v = toPolar();
	v.setAngle(a);
	BO_Cartesian_2DVector v2 = v.toCartesian();
	x = v2.getX();
	y = v2.getY();
} 
void BO_Cartesian_2DVector::setRadius(float r) {
	BO_Polar_2DVector v = toPolar();
	v.setRadius(r);
	BO_Cartesian_2DVector v2 = v.toCartesian();
	x = v2.getX();
	y = v2.getY();
}

void BO_Cartesian_2DVector::addX(float f) {
	x += f;
}
void BO_Cartesian_2DVector::addY(float f) {
	y += f;
}
void BO_Cartesian_2DVector::addAngle(float a) {
	BO_Polar_2DVector v = toPolar();
	v.addAngle(a);
	BO_Cartesian_2DVector v2 = v.toCartesian();
	x = v2.getX();
	y = v2.getY();
}
void BO_Cartesian_2DVector::addRadius(float r) {
	BO_Polar_2DVector v = toPolar();
	v.addRadius(r);
	BO_Cartesian_2DVector v2 = v.toCartesian();
	x = v2.getX();
	y = v2.getY();
}



	//BO_Polar_2DVector

BO_Polar_2DVector::BO_Polar_2DVector() 
:radius(0), angle(0) {}
BO_Polar_2DVector::BO_Polar_2DVector(float r, float a) {
	angle = a;
	if (radius < 0) {
		angle += M_PI;
		radius = -radius;
	}
	else {
		radius = r;
	}
}

BO_Polar_2DVector BO_Polar_2DVector::operator+(BO_Cartesian_2DVector& v) {
	BO_Cartesian_2DVector cv = toCartesian();
	return BO_Cartesian_2DVector(cv.getX() + v.getX(), cv.getY() + v.getY() ).toPolar();
}
BO_Polar_2DVector BO_Polar_2DVector::operator+(BO_Polar_2DVector& v) {
	BO_Cartesian_2DVector cv = toCartesian();
	BO_Cartesian_2DVector v2 = v.toCartesian();
	return BO_Cartesian_2DVector(cv.getX() + v2.getX(), cv.getY() + v2.getY() ).toPolar();
}
BO_Polar_2DVector BO_Polar_2DVector::operator-(BO_Cartesian_2DVector& v) {
	BO_Cartesian_2DVector cv = toCartesian();
	return BO_Cartesian_2DVector(cv.getX() - v.getX(), cv.getY() - v.getY()).toPolar();
}
BO_Polar_2DVector BO_Polar_2DVector::operator-(BO_Polar_2DVector& v) {
	BO_Cartesian_2DVector cv = toCartesian();
	BO_Cartesian_2DVector v2 = v.toCartesian();
	return BO_Cartesian_2DVector(cv.getX() - v2.getX(), cv.getY() - v2.getY()).toPolar();
}

BO_Polar_2DVector::operator BO_Cartesian_2DVector() {
	return toCartesian();
}

template<typename num> BO_Polar_2DVector BO_Polar_2DVector::operator*(num& i) {
	BO_Polar_2DVector v = &this;
	if (i < 0) {
		v.getAngle() += M_PI;
		i = -i;
	}
	v.getRadius() *= i;
	return v;
}


BO_Cartesian_2DVector BO_Polar_2DVector::toCartesian() {
	return BO_Cartesian_2DVector(getX(), getY() );
}


float BO_Polar_2DVector::getAngle() {
	return angle;
}
float BO_Polar_2DVector::getRadius() {
	return radius;
}
float BO_Polar_2DVector::getX() {
	return radius * cos(angle);
}
float BO_Polar_2DVector::getY() {
	return radius * sin(angle);
}

void BO_Polar_2DVector::setX(float f) {
	BO_Cartesian_2DVector v = toCartesian();
	v.setX(f);
	BO_Polar_2DVector v2 = v.toPolar();
	radius = v2.getRadius();
	angle = v2.getAngle();
} 
void BO_Polar_2DVector::setY(float f) {
	BO_Cartesian_2DVector v = toCartesian();
	v.setY(f);
	BO_Polar_2DVector v2 = v.toPolar();
	radius = v2.getRadius();
	angle = v2.getAngle();
}
void BO_Polar_2DVector::setAngle(float a) {
	angle = a;
}
void BO_Polar_2DVector::setRadius(float r) {
	radius = r;
}

void BO_Polar_2DVector::addX(float f) {
	BO_Cartesian_2DVector v = toCartesian();
	v.addX(f);
	BO_Polar_2DVector v2 = v.toPolar();
	radius = v2.getRadius();
	angle = v2.getAngle();
}
void BO_Polar_2DVector::addY(float f) {
	BO_Cartesian_2DVector v = toCartesian();
	v.addY(f);
	BO_Polar_2DVector v2 = v.toPolar();
	radius = v2.getRadius();
	angle = v2.getAngle();
}
void BO_Polar_2DVector::addAngle(float a) {
	angle += a;
}
void BO_Polar_2DVector::addRadius(float r) {
	radius += r;
}
