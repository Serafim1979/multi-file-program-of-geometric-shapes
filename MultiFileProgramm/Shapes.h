#ifndef SHAPES_H
#define SHAPES_H
#include<string>
#include<iostream>
#include <cmath>

////////////////////////////////////////////////////////////////////////////////
class Shape
{
protected:
    std::string name;
    std::string type;
public:
    Shape(std::string name, std::string type);
    std::string get_name()const;
    std::string get_type()const;
    void show_info()const;
    virtual double get_area()const = 0;
    friend std::ostream& operator << (std::ostream&, Shape *&);
};
////////////////////////////////////////////////////////////////////////////////
class Circle : public Shape
{
private:
    double radius;
public:
    Circle(std::string, double, std::string type = "2D");
    double get_area()const;
    double get_perimeter()const;
    void show_info()const;
};
////////////////////////////////////////////////////////////////////////////////
class Square : public Shape
{
private:
    double side;
public:
    Square(std::string, double, std::string type = "2D");
    double get_area()const;
    double get_perimeter()const;
    void show_info()const;
};
////////////////////////////////////////////////////////////////////////////////
class Rectangle : public Shape
{
private:
    double side_a, side_b;
public:
    Rectangle(std::string, double, double, std::string type = "2D");
    double get_area()const;
    double get_perimeter()const;
    void show_info()const;
};
////////////////////////////////////////////////////////////////////////////////
class Triangle : public Shape
{
private:
    double side_a, side_b, side_c;
public:
    Triangle(std::string, double, double, double, std::string type = "2D");
    double get_area()const;
    double get_perimeter()const;
    void show_info()const;
};
////////////////////////////////////////////////////////////////////////////////
class Cube : public Shape
{
private:
    double length;
public:
    Cube(std::string, double, std::string type = "3D");
    double get_area()const;
    double get_volume()const;
    double get_perimeter()const;
    void show_info()const;
};
////////////////////////////////////////////////////////////////////////////////
class Sphere : public Shape
{
private:
    double radius;
public:
    Sphere(std::string, double, std::string type = "3D");
    double get_area()const;
    double get_volume()const;
    void show_info()const;
};



#endif // SHAPES_H
