/**Brian Lee
 * 3620101
 * CMPSC 130B Prog4
 * Header file for
 * Prog4 Helper Functions
 **/

#ifndef PROG4_H_
#define PROG4_H_

#include <vector>

using namespace std;

struct Point
{
    double x;
    double y;
    double error;
    
    Point(): x(0.0), y(0.0), error(0.0){}
    Point(double x, double y): x(x), y(y),  error(0.0){}
    Point(double x, double y, double e): x(x), y(y), error(e){}
};

struct Line
{
    Point a;
    Point b;
    
    Line(): a(Point()), b(Point()){}
    Line(Point first, Point sec): a(first), b(sec){}
};

struct LineEq
{
    double slope;
    double yInt;
    
    LineEq(): slope(0.0), yInt(0.0){}
    LineEq(double m, double b): slope(m), yInt(b){}
};

double fittingError(Line l, Point p);

vector<Point> orderPoints(vector<Point> set);

double findMedian(vector<Point> set);

vector<Point> bestPoints(vector<Point> set);

bool lineInVector(Line l, vector<Line> set);

void printPoint(Point p);

void printLine(LineEq l);

LineEq bestFitLine(vector<Point> set);

#endif