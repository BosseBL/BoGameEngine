/*
 *  BO_Physics.h
 *  BO
 *
 *  Created by Daniel Lindfors on 5/27/12.
 *  Copyright 2012 KTH. All rights reserved.
 *
 */

#ifndef BO_PHYSICS_H
#define BO_PHYSICS_H



using namespace std;



struct BO_Point {		// simple little point structure. aimed for pixles on a screen of course.
	int x, y;
};



struct Orgentation3D {
	int x, y, z;
	int w, l, h;
	float horizontalAngle, verticalAngle;
	int refX, refY, refZ;
};



class BO_Polar_2DVector;		// forward declaration. as you will see, the two classes declare here next has a pretty complex mutual relationship 

class BO_Cartesian_2DVector  {		// this class is aimed to do all that is 2D vector handling. this one handles vectors defined in a cartesian cordinate system
private:
	
	float x, y;
	
public:
	
	BO_Cartesian_2DVector();
	BO_Cartesian_2DVector(float x, float y);
	
	BO_Cartesian_2DVector operator+(BO_Cartesian_2DVector& v);		// here are som operator overloading. both BO_Cartesian_2DVector and BO_Polar_2DVector made to cooperate well with each other
	BO_Cartesian_2DVector operator+(BO_Polar_2DVector& v);
	BO_Cartesian_2DVector operator-(BO_Cartesian_2DVector& v);
	BO_Cartesian_2DVector operator-(BO_Polar_2DVector& v);
	
	operator BO_Polar_2DVector();									// type casting to BO_Polar_2DVector
	
	template<typename num> BO_Cartesian_2DVector operator*(num& i);		//Vectors can be multiplyed with reel values. acctualy, what gets multiplyed with is the radius of the vector.
	
	
	BO_Polar_2DVector toPolar();									// returns a BO_Polar_2DVector representation of BO_Cartesian_2DVector this is the glue that holds these two classes togheter
	
	
	void setX(float f);											// all the setters, getters and adders. the make good use of the toPolar() function.
	void setY(float f);
	void setAngle(float a);
	void setRadius(float r);
	
	void addX(float f);
	void addY(float f);
	void addAngle(float a);
	void addRadius(float r);
	
	float getAngle();
	float getRadius();
	float getX();
	float getY();
};


class BO_Polar_2DVector {				// almost identical to the BO_Cartesian_2DVector in use. only difrence is that this does everything the oposit way.
private:
	
	float radius, angle;
	
public:
	
	BO_Polar_2DVector();
	BO_Polar_2DVector(float r, float a);
	
	
	BO_Polar_2DVector operator+(BO_Cartesian_2DVector& v);
	BO_Polar_2DVector operator+(BO_Polar_2DVector& v);
	BO_Polar_2DVector operator-(BO_Cartesian_2DVector& v);
	BO_Polar_2DVector operator-(BO_Polar_2DVector& v);
	
	operator BO_Cartesian_2DVector();
	
	template<typename num> BO_Polar_2DVector operator*(num& i);
	
	
	BO_Cartesian_2DVector toCartesian();
	
	
	void setX(float f);
	void setY(float f);
	void setAngle(float a);
	void setRadius(float r);
	
	void addX(float f);
	void addY(float f);
	void addAngle(float a);
	void addRadius(float r);
	
	float getAngle();
	float getRadius();
	float getX();
	float getY();	
};



struct BO_Physical_Properties {
	BO_Point position;
	BO_Cartesian_2DVector velocity;
	BO_Cartesian_2DVector acceleration;
	float mass;
	float density;
	BO_Point mass_middpoint;
	float angle;
	float friction;
};







#endif