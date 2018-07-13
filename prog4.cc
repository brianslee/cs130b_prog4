/**Brian Lee
 * 3620101
 * CMPSC 130B Prog4
 * Implementation file for
 * Prog4 Helper Functions
 **/
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <iostream>

#include "prog4.h"

using namespace std;

int compareError(const void* a, const void* b)
{
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    
    return (p1->error - p2->error);
}

double fittingError(Line l, Point p)
{
    double num, den;
    double x, y;
    x = l.b.x - l.a.x;
    y = l.b.y - l.a.y;
    
    num = abs((y * p.x) - (x * p.y) + (l.b.x * l.a.y) - (l.b.y * l.a.x));
    
    x = x * x;
    y = y * y;
    
    den = sqrt(y + x);
    
    double error = num/den;
    return error;
}

bool lineInVector(Line l, vector<Line> set)
{
    if(set.size() == 0)
    {
        return true;
    }
    
    for(int i = 0; i < set.size(); ++i)
    {
        if((l.a.x == set[i].a.x && l.a.y == set[i].a.y ) || (l.a.x == set[i].b.x && l.a.y == set[i].b.y))
        {
            if((l.b.x == set[i].a.x && l.b.y == set[i].a.y) || (l.b.x == set[i].b.x && l.b.y == set[i].b.y))
            {
                return false;
            }
        }
    }
    
    return true;
}

void printPoint(Point p)
{
    cout << "(" << p.x << ", " << p.y << ")";
}

void printLine(LineEq l)
{
    cout << "a = " << l.slope << endl;
    
    cout << "b = " << l.yInt << endl;
}

LineEq bestFitLine(vector<Point> set)
{
    double xMean = 0.0;
    double yMean = 0.0;
    double m, b;
    double denom = 0.0;
    double num = 0.0;
    
    for(int i = 0; i < set.size(); ++i)
    {
        xMean = xMean + set[i].x;
        yMean = yMean + set[i].y;
    }
    xMean = xMean/set.size();
    yMean = yMean/set.size();
    
    for(int i = 0; i < set.size(); i++)
    {
        num = ((set[i].x - xMean) * (set[i].y - yMean)) + num;
        denom = denom + ((set[i].x - xMean) * (set[i].x - xMean));
    }
    m = num/denom;
    b = yMean - (xMean * m);
    
    LineEq best(m, b);
    return best;
}

vector<Point> orderPoints(vector<Point> set)
{
    Point temp[set.size()];
    for (int i = 0; i < set.size(); ++i)
    {
        temp[i] = set[i];
    }
    qsort(temp, set.size(), sizeof(Point), compareError);
    for (int i = 0; i < set.size(); ++i)
    {
        set[i] = temp[i];
    }
    
    return set;
}

double findMedian(vector<Point> set)
{
    if(set.size() % 2 == 1)
    {
        int location = set.size() / 2;
        return set[location].error;
    }
    else
    {
        int y = set.size() / 2;
        int x = y - 1;
        double med = set[y].error + set[x].error;
        med = med / 2;
        return med;
    }
}

vector<Point> bestPoints(vector<Point> set)
{
    vector<Point> out;
    for(int i = 0; i < (set.size() / 2); ++i)
    {
        out.push_back(set[i]);
    }
    return out;
}