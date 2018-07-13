/**Brian Lee
 * 3620101
 * CMPSC 130B Prog4
 * Best Fit Line
 **/
#include <vector>
#include <cstdlib>
#include <ctime>
#include <float.h>
#include <iostream>

#include "prog4.h"

using namespace std;

int main()
{
    //Get inputs
    int n;
    cout << "Number of Points: ";
    cin >> n;
    
    vector<Point> pointSet;
    
    for(int i = 0; i < n; ++i)
    {
        double x, y;
        cout << "Point Coordinates: ";
        cin >> x >> y;
        Point input(x, y);
        pointSet.push_back(input);
    }
    
    vector<Line> checkedLine;
    int numLines = n * (n - 1);
    
    double minMedianError = DBL_MAX;
    LineEq bestLine;
    vector<Point> errors = pointSet;
    
    //Find best line
    for(int i = 0; i < 25; ++i) //adjust numbers
    {
        int a, b;
        bool unique = false;
        Line check;
        
        //Create a line that has not been checked yet.
        while(unique == false)
        {
            srand((int) time(0));
            a = rand() % n;
            b = rand() % n;
            while (a == b)
            {
                b = rand() % n;
            }
            
            Line temp(pointSet.at(a), pointSet.at(b));
            check = temp;
            unique = lineInVector(check, checkedLine);
        }
        
        //Create vector of errors from line
        vector<Point> tempError = pointSet;
        for(int i = 0; i < pointSet.size(); ++i)
        {
            if(pointSet[i].x != check.a.x || pointSet[i].y != check.a.y || pointSet[i].x != check.b.x || pointSet[i].y != check.b.y)
            {
                double pointError = fittingError(check, tempError[i]);
                tempError[i].error = pointError;
            }
        }
        //Find Median Error
        tempError = orderPoints(tempError);
        double tempMed = findMedian(tempError);
        
        //Check Median Error
        if(tempMed < minMedianError)
        {
            minMedianError = tempMed;
            errors = tempError;
        }
        
        checkedLine.push_back(check);
    }
    
    //Create Line of Best Fit
    errors = bestPoints(errors);
    bestLine = bestFitLine(errors);
    
    //Output Line
    printLine(bestLine);
    
    return 0;
}