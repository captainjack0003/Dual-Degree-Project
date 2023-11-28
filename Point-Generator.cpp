// *********************************************************************************************************
// *********************************************************************************************************
// *********************************************************************************************************
// *********************************************************************************************************
//  Developer:                                      @ Rohan Jain
// *********************************************************************************************************
// *********************************************************************************************************
// *********************************************************************************************************
// *********************************************************************************************************

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<random>
#include <delaunator.hpp>
#include <cstdio>


struct Point
{
    double x;
    double y;
};

class Rectangle
{
private:
    Point topLeft;
    Point bottomRight;

public:
    Rectangle() = default;

    Rectangle(double x1, double y1, double x2, double y2)
    {
        topLeft.x = x1;
        topLeft.y = y1;
        bottomRight.x = x2;
        bottomRight.y = y2;
    }

    ~Rectangle() = default;

    std::vector<Point> generatePointsOnRect(int numPoints);

    std::vector<Point> generateInteriorPoints(int m);
};

// Function to generate 'n' points symmetrically on the rectangle
std::vector<Point> Rectangle::generatePointsOnRect(int numPoints)
{
    std::vector<Point> points(4 * numPoints);

    double width = bottomRight.x - topLeft.x;
    double height = bottomRight.y - topLeft.y;

    double stepX = width / (numPoints - 1);
    double stepY = height / (numPoints - 1);

    // Generate points along the top side
    for (int i = 0; i < numPoints; ++i)
    {
        double x = topLeft.x + i * stepX;
        double y = topLeft.y;
        points[i].x = x;
        points[i].y = y;
    }

    // Generate points along the right side
    for (int i = 0; i < numPoints; ++i)
    {
        double x = bottomRight.x;
        double y = topLeft.y + i * stepY;
        points[numPoints + i].x = x;
        points[numPoints + i].y = y;
    }

    // Generate points along the bottom side
    for (int i = 0; i < numPoints; ++i)
    {
        double x = bottomRight.x - i * stepX;
        double y = bottomRight.y;
        points[2 * numPoints + i].x = x;
        points[2 * numPoints + i].y = y;
    }

    // Generate points along the left side
    for (int i = 0; i < numPoints; ++i)
    {
        double x = topLeft.x;
        double y = bottomRight.y - i * stepY;
        points[3 * numPoints + i].x = x;
        points[3 * numPoints + i].y = y;
    }

    return points;
}

// Function to generate 'm' points symmetrically inside the rectangle
std::vector<Point> Rectangle::generateInteriorPoints(int numPointsInRect)
{

    std::vector<Point> points;
    double centerX = (topLeft.x + bottomRight.x) / 2.0;
    double centerY = (bottomRight.y + topLeft.y) / 2.0;

    srand(time(0)); // Seed the random number generator with current time

    for (int i = 0; i < numPointsInRect; ++i)
    {
        double x = topLeft.x + (rand() / (RAND_MAX + 1.0)) * (bottomRight.x - topLeft.x);
        double y = bottomRight.y + (rand() / (RAND_MAX + 1.0)) * (topLeft.y - bottomRight.y);

        // Calculate the symmetrical point inside the rectangle
        double symmetricalX = 2 * centerX - x;
        double symmetricalY = 2 * centerY - y;

        points.push_back({x, y});
        points.push_back({symmetricalX, symmetricalY});
    }

    return points;
}

class Circle
{

private:
    Point center;
    double Radius;

public:
    Circle() = default;

    Circle(double x1, double y1, double radius)
    {
        center.x = x1;
        center.y = y1;
        Radius = radius;
    }

    ~Circle() = default;
    std::vector<Point> generateEquidistantPoints(Point center, int numPointsonCir);
    std::vector<Point> generateEquidistantPointsInside(Point center, int numPointsInCir);
};

// Function to generate 'n' points symmetrically on the Circle
std::vector<Point> Circle::generateEquidistantPoints(Point center, int numPointsonCir)
{
    std::vector<Point> points;
    double angle = 2 * M_PI / numPointsonCir; // Angle between each point
    for (int i = 0; i < numPointsonCir; ++i)
    {
        double theta = i * angle;
        double x = center.x + Radius * cos(theta);
        double y = center.y + Radius * sin(theta);
        points.push_back({x, y});
    }
    return points;
}



std::vector<Point> Circle::generateEquidistantPointsInside(Point center, int numPointsInCir) {
    std::vector<Point> points;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < numPointsInCir; ++i) {
        double r = Radius * std::sqrt(dis(gen));
        double theta = 2 * M_PI * dis(gen);
        double x = center.x + r * std::cos(theta);
        double y = center.y + r * std::sin(theta);
        points.push_back({x, y});
    }
    return points;
}



int main()

{
    double x1, y1, x2, y2;
    int numPointsOnRect, numPointsInRect, numPointsonCir;

    double radius;
    Point center;

    // Input rectangle coordinates
    std::cout << "Enter top-left coordinates (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter bottom-right coordinates (x2, y2): ";
    std::cin >> x2 >> y2;

    // Create rectangle object
    Rectangle rectangle(x1, y1, x2, y2);

    // Circle c1(2,3,1);
    // c1.printer();

    // Input number of points on the rectangle
    std::cout << "Enter the number of points on the rectangle: ";
    std::cin >> numPointsOnRect;
    numPointsOnRect /= 4;

    std::cout << "Enter the number of points inside the rectangle (m): ";
    std::cin >> numPointsInRect;
    numPointsInRect /= 2;

    // Generate points on the rectangle
    std::vector<Point> pointsOnRect = rectangle.generatePointsOnRect(numPointsOnRect);
    std::vector<Point> interiorPoints_REC = rectangle.generateInteriorPoints(numPointsInRect);

    // Output points on the rectangle
    std::cout << "\nPoints on the rectangle:\n";
    for (const auto &point : pointsOnRect)
    {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    std::cout << "Points inside the rectangle (symmetrical pairs):" << std::endl;
    for (const auto &point : interiorPoints_REC)
    {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    std::cout << "Enter the center coordinates (x, y) of the circle: ";
    std::cin >> center.x >> center.y;

    std::cout << "Enter the number of equidistant points to generate: ";
    std::cin >> numPointsonCir;

    Circle c1(center.x, center.y, radius);

    std::vector<Point> equidistantPoints_CIR = c1.generateEquidistantPoints(center, numPointsonCir);
    int n;
    std::cout << "Enter the number of equidistant points to generate: ";
    std::cin >> n;

    std::vector<Point> equidistantPointsInside_CIR = c1.generateEquidistantPointsInside(center, n);

    std::cout << "Equidistant points inside the circle:" << std::endl;
    for (const auto& point : equidistantPoints_CIR) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    std::cout << "Equidistant points on the circle:" << std::endl;
    for (const auto &point : equidistantPointsInside_CIR)
    {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }
    
    
    
    
    //********************************************************************************************************************************
    
    //testing for rectangle inside points for triangulation thing
    //********************************************************************************************************************************
    /* x0, y0, x1, y1, ... */
    
    std::vector<double> coords = {};
    
    for(auto it:interiorPoints_REC){
	    coords.push_back(it.x);
	    coords.push_back(it.y);
    }

    //triangulation happens here
    delaunator::Delaunator d(coords);

    for(std::size_t i = 0; i < d.triangles.size(); i+=3) {
        printf(
            "Triangle points: [[%f, %f], [%f, %f], [%f, %f]]\n",
            d.coords[2 * d.triangles[i]],        //tx0
            d.coords[2 * d.triangles[i] + 1],    //ty0
            d.coords[2 * d.triangles[i + 1]],    //tx1
            d.coords[2 * d.triangles[i + 1] + 1],//ty1
            d.coords[2 * d.triangles[i + 2]],    //tx2
            d.coords[2 * d.triangles[i + 2] + 1] //ty2
        );
    }

    return 0;
}
