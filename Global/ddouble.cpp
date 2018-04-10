//
// Created by jbmdu on 10/04/2018.
//

#include "ddouble.h"

// file ddouble.hpp, for automatic differentiation (single variable)
// adapted from M. Grundmann's MIPAD and compatible with f2c

// to test this file copy past the function main() at the end into a *.cpp file
/*
#ifndef _DDOUBLE__H_
#define _DDOUBLE__H_
*/
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include "ddouble.h"
using namespace std;

inline double sign(const ddouble& x)
{ return ( x < 0.0 ? -1.0 : 1.0); }

inline double sign(const ddouble& x, double y)
{ return ( x < 0.0 ? -fabs(y) : fabs(y)); }

// f2c

inline ddouble d_abs(ddouble * x){ return abs(*x);	}
inline ddouble d_cos(ddouble * x){ return cos(*x);	}
inline ddouble d_sin(ddouble * x){ return sin(*x);	}
inline ddouble d_tan(ddouble * x){ return tan(*x);	}
inline ddouble d_exp(ddouble * x){ return exp(*x);	}
inline ddouble d_log(ddouble * x){ return log(*x);	}

inline ddouble d_sign(ddouble * x){ return sign(*x);	}
inline ddouble d_sign(ddouble * x,double*y){ return sign(*x,*y);	}

inline ddouble d_sqrt(ddouble * x){ return sqrt(*x);	}

inline ddouble pow_dd(ddouble * x,ddouble*y)	{ return pow(*x,*y);	}
inline ddouble pow_dd(double * x,ddouble*y) 	{ return pow(*x,*y);	}
inline ddouble pow_dd(ddouble * x,double*y) 	{ return pow(*x,*y);	}
inline ddouble pow_di(ddouble * x,int*y)	{ return pow(*x,*y);	}

const double eps = 1.0e-50; // avoids NaN as in (sqrt(y)'at y=0

ostream& operator<<(ostream& f, const ddouble& a)
{ f << a[0] ; return f;}

/*
friend istream& operator>>(istream& f, const ddouble& a)
{ f >> a[0] ; return f;}
*/

ddouble ddouble::operator++(int)
{   ddouble r=(*this);  r[0]++; return r;}

ddouble ddouble::operator--(int)
{   ddouble r=(*this);  r[0]--; return r;}

ddouble& ddouble::operator++(){  (*this)[0]++; return *this;}

ddouble& ddouble::operator--(){  (*this)[0]--; return *this;}

ddouble& ddouble::operator += (double y)
{  (*this)[0] += y; return *this; }

ddouble operator - (const ddouble& a)
{ ddouble r; r[0] = -a[0]; r[1] = -a[1];    return r;}

ddouble& ddouble::operator -= (double y)
{  (*this)[0]-=y; return *this;}

ddouble& ddouble::operator += (const ddouble& y)
{   (*this)[0]+=y[0];(*this)[1]+=y[1]; return *this; }

ddouble& ddouble::operator -= (const ddouble& y)
{   (*this)[0]-=y[0];(*this)[1]-=y[1];   return *this; }

ddouble& ddouble::operator *= (double y)
{ (*this)[0] *=y; (*this)[1] *=y;  return *this;}

ddouble& ddouble::operator *= (const ddouble& y)
{ return *this = *this * y;}

ddouble& ddouble::operator /= (const ddouble& y)
{  return *this = *this / y;}

ddouble& ddouble::operator /= (double y)
{ const double inv = 1.0 / y;
    (*this)[1]  *= inv; (*this)[1]  *= inv;
    return *this;
}

int operator != (const ddouble& u,const ddouble& v)
{  return u[0] != v[0];}

int operator != (double u,const ddouble& v){  return u != v[0];}

int operator != (const ddouble& v,double u){  return v[0] != u;}

int operator == (const ddouble& u,const ddouble& v)
{  return u[0] == v[0];}

int operator == (double u,const ddouble& v){  return u == v[0];}

int operator == (const ddouble& v,double u){  return v[0] == u;}

int operator <= (const ddouble& u,const ddouble& v)
{  return u[0] <= v[0];}

int operator <= (double u,const ddouble& v){  return u <= v[0];}

int operator <= (const ddouble& v,double u){  return v[0] <= u;}

int operator >= (const ddouble& u,const ddouble& v)
{  return u[0] >= v[0];}

int operator >= (double u,const ddouble& v){  return u >= v[0];}

int operator >= (const ddouble& v,double u){  return v[0] >= u;}

int operator > (const ddouble& u,const ddouble& v)
{  return u[0] > v[0];}

int operator > (double u,const ddouble& v){  return u > v[0];}

int operator > (const ddouble& v,double u){  return v[0] > u;}

int operator < (const ddouble& u,const ddouble& v){  return u[0] < v[0];}

int operator < (double u,const ddouble& v){  return u < v[0];}

int operator < (const ddouble& v,double u){  return v[0] < u;}

ddouble operator + (const ddouble& x, const ddouble& y)
{ ddouble r;
    r[0]    = x[0] + y[0];r[1]  = x[1] + y[1];     return r;
}

ddouble operator + (double x, const ddouble& y)
{   ddouble r(y);  r[0] += x;  return r;}

ddouble operator + (const ddouble& y, double x)
{   ddouble r(y);  r[0] += x;  return r;}

ddouble operator - (const ddouble& x, const ddouble& y)
{   ddouble r;  r[0] = x[0] - y[0];r[1] = x[1] - y[1]; return r;}

ddouble operator - (double x, const ddouble& y)
{  ddouble r; r[1]  = - y[1];  r[0] = x - y[0];   return r;}

ddouble operator - (const ddouble& x, double y)
{  ddouble  r(x);  r[0] -= y;  return r;        }

ddouble operator * (const ddouble& x, const ddouble& y)
{ ddouble r; r[0] = x[0]*y[0]; r[1]=x[0]*y[1]+x[1]*y[0];return r;}

ddouble operator * (double x, const ddouble& y)
{ddouble r; r[0]    = x * y[0]; r[1]    = x * y[1];  return r;}

ddouble operator * ( const ddouble& y, double x)
{return x * y;}

ddouble operator / (const ddouble& x, const ddouble& y)
{  ddouble r; r[0] = x[0]/y[0]; r[1]=(x[1]-x[0]*y[1]/y[0])/y[0];return r;}

ddouble operator / (double x, const ddouble& y)
{ ddouble r; r[0] = x/y[0]; r[1]=-x*y[1]/y[0]/y[0]; return r;}

ddouble operator/(const ddouble& x, double y)
{ddouble r; r[0] = x[0]/y; r[1]=x[1]/y;return r;}

ddouble exp (const ddouble& x)
{  ddouble r;r[0] = exp(x[0]); r[1] = x[1]*r[0];return r;}

ddouble log (const ddouble& x)
{ ddouble r;r[0] = log(x[0]);r[1]     = x[1]/x[0];return r;}

ddouble sqrt (const ddouble& x)
{ ddouble r;r[0] = sqrt(x[0]); r[1] = 0.5*x[1]/(eps+r[0]);return r;}

ddouble sin (const ddouble& x)
{   ddouble r; r[0]=sin(x[0]); r[1]=x[1]*cos(x[0]);   return r;}

ddouble cos (const ddouble& x)
{   ddouble r; r[0]=cos(x[0]); r[1]=-x[1]*sin(x[0]);  return r;}

ddouble tan (const ddouble& x)
{ return (sin(x) / cos(x));}

ddouble pow (const ddouble& x,double y)
{return exp(log(x) * y);}

ddouble pow (const ddouble& x,const int y)
{	ddouble r=1;
    if(y>=0) for(int i=0;i<y;i++) r*=x;
    else for(int i=0; i<-y;i++) r/=x;
    return r;
}

ddouble pow (const ddouble& x,const ddouble& y)
{return exp(log(x) * y);}

ddouble abs (const ddouble& x)
{ ddouble y;if(x[0] >= 0) y=x; else y = -x; return y;}

ddouble fabs (const ddouble& x)
{ ddouble y;if(x[0] >= 0) y=x; else y = -x; return y;}

ddouble real (const ddouble& x)
{ return x;}

ddouble conj (const ddouble& x)
{ return x;}


