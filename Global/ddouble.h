#ifndef NN_DDOUBLE_H
#define NN_DDOUBLE_H

// file ddouble.hpp, for automatic differentiation (single variable)
// adapted from M. Grundmann's MIPAD and compatible with f2c

#include <stdlib.h>
#include <cmath>
#include <iostream>
using namespace std;

class ddouble
{
 public:  double val[2]; // val[0] is value and val[1] is the derivative
	ddouble() { val[0] = 0; val[1] = 0; }
	ddouble(const ddouble& a){ val[0] = a.val[0]; val[1] = a.val[1];  }
	ddouble(double a, double b=0,double c=0){ val[0]=a; val[1]=b;} // specifies var for diff
	void set(const double a,double b=0) { val[0]=a; val[1]=b;}
	void set(const ddouble& a,double b) { val[0] = a.val[0]; val[1] = b;  }

	ddouble& operator=(double a)
		{ val[0] = a; val[1] = 0.0; return *this;}
	ddouble& operator=(const ddouble& a)
		{ val[0] = a.val[0]; val[1] = a.val[1]; return *this;}

	double& operator[](const int ii){ return this->val[ii];}
	double operator[](const int ii) const { return this->val[ii];}
//	operator int(){return (int)this->val[0];}
//	operator double(){return this->val[0];}
	ddouble& operator  + (){return *this;};
	ddouble& operator += (double);
	ddouble& operator += (const ddouble&);
	ddouble& operator -= (double );
	ddouble& operator -= (const ddouble&);
	ddouble& operator *= (double);
	ddouble& operator *= (const ddouble&);
	ddouble& operator /= (double) ;
	ddouble& operator /= (const ddouble&) ;


	ddouble operator++(int);
	ddouble operator--(int);
	ddouble&  operator++();
	ddouble&  operator--();

	friend ostream& operator << (ostream& f, const ddouble&);
	friend ddouble& operator << (ddouble&,double);

	friend ddouble parameter(double);

	friend int operator != (const ddouble&,const ddouble&);
	friend int operator != (double,const ddouble&);

	friend int operator != (const ddouble&,double);

	friend int operator == (const ddouble&,const ddouble&);
	friend int operator == (double,const ddouble&);
	friend int operator == (const ddouble&,double);
	friend int operator >= (const ddouble&,const ddouble&);
	friend int operator >= (double,const ddouble&);
	friend int operator >= (const ddouble&,double);
	friend int operator <= (const ddouble&,const ddouble&);
	friend int operator <= (double,const ddouble&);
	friend int operator <= (const ddouble&,double);
	friend int operator > (const ddouble&,const ddouble&);
	friend int operator > (double,const ddouble&);
	friend int operator > (const ddouble&,double);
	friend int operator < (const ddouble&,const ddouble&);
	friend int operator < (double,const ddouble&);
	friend int operator < (const ddouble&,double);

	friend ddouble operator + (const ddouble& x); //{return x + 0.0 ;} ;
	friend ddouble operator + (const ddouble&,const ddouble&);
	friend ddouble operator + (double, const ddouble&);
	friend ddouble operator + (const ddouble&, double);
	friend ddouble operator - (const ddouble& x ,double y); //{return (-y)+x;};
	friend ddouble operator - (const ddouble&,const ddouble&);
	friend ddouble operator - (double, const ddouble&);
	friend ddouble operator - ( const ddouble& );
	friend ddouble operator * (const ddouble&,const ddouble&);
	friend ddouble operator * (double, const ddouble& );
	friend ddouble operator * (const ddouble& x, double y);
	friend ddouble operator / (const ddouble& x, double y);
	friend ddouble operator / (const ddouble&,const ddouble&);
	friend ddouble operator / (double,const ddouble&) ;
	friend ddouble exp (const ddouble&);
	friend ddouble log (const ddouble&) ;
	friend ddouble sqrt (const ddouble&) ;
	friend ddouble sin (const ddouble&);
	friend ddouble cos (const ddouble&);
	friend ddouble tan (const ddouble&);
	friend ddouble pow (const ddouble&,double);
	friend ddouble pow (const ddouble&,const ddouble&);
	friend ddouble pow (const ddouble&, const int);
	friend ddouble abs (const ddouble&) ;

	friend ddouble fabs (const ddouble&) ;
	friend ddouble real (const ddouble&) ;
	friend ddouble conj (const ddouble&) ;
};



#endif //NN_DDOUBLE_H
