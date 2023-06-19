#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

class Meshgenerator{
  public:
  Meshgenerator()=default;
  ~Meshgenerator()=default;
  void points_on_line_generator(double x1, double y1,
  double x2, double y2, 
  double dist,vector<pair<double, double>> &coordinates);
  
};

void Meshgenerator::points_on_line_generator(double x1, double y1, double x2, double y2, double dist, vector<pair<double, double>> &coordinates)
{
    if(x2<x1){
        double temp=x2;
        x2=x1;
        x1=temp;
        temp=y2;
        y2=y1;
        y1=temp;
    }
    
    else if(x1==0 && x2 ==0){
        if(y2<y1){
            double temp=y2;
            y2=y1;
            y1=temp;
        }
    }
    double dx = x2 - x1;
    double dy = y2 - y1;
    // Calculate the length of the direction vector
    double length = std::sqrt(dx * dx + dy * dy);
    // Calculate the unit direction vector
    double ux = dx / length;
    double uy = dy / length;
    // Calculate the coordinates of the new points
    double newX = x1 + ux * dist;
    double newY = y1 + uy * dist;
    // double newX2 = x2 + ux * dist;
    // double newY2 = y2 + uy * dist;
    coordinates.push_back(pair(newX,newY));
}

int main(){
    Meshgenerator m1;
    vector<pair<double, double>> coordinates;
    m1.points_on_line_generator(0,0,0,-2,1,coordinates);
    for(auto c:coordinates){
        cout<<"new x coordinate: "<<c.first<<'\n'<< "new y coordinate: "<<c.second<<endl;
    }
}
