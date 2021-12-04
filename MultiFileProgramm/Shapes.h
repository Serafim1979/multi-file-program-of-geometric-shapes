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
    virtual void show_info()const = 0;
    virtual double get_area()const = 0;
    friend std::ostream& operator << (std::ostream&, Shape *&);
    friend std::istream& operator >> (std::istream&, Shape &);
};
////////////////////////////////////////////////////////////////////////////////
class Circle : public Shape
{
private:
    double radius;
public:
    Circle();
    Circle(double, std::string name = "Circle", std::string type = "2D");
    void set_name(std::string);
    double get_area()const;
    double get_perimeter()const;
    void show_info()const;
    friend std::istream& operator >> (std::istream&, Circle &);
};
////////////////////////////////////////////////////////////////////////////////
class Square : public Shape
{
private:
    double side;
public:
    Square();
    Square(double, std::string name = "Square", std::string type = "2D");
    double get_area()const;
    double get_perimeter()const;
    void show_info()const;
    friend std::istream& operator >> (std::istream&, Square &);
};
////////////////////////////////////////////////////////////////////////////////
class Rectangle : public Shape
{
private:
    double side_a, side_b;
public:
    Rectangle();
    Rectangle(double, double, std::string name = "Rectangle", std::string type = "2D");
    double get_area()const;
    double get_perimeter()const;
    void show_info()const;
    friend std::istream& operator >> (std::istream&, Rectangle &);
};
////////////////////////////////////////////////////////////////////////////////
class Triangle : public Shape
{
private:
    double side_a, side_b, side_c;
public:
    Triangle();
    Triangle(double, double, double, std::string name = "Triangle", std::string type = "2D");
    double get_area()const;
    double get_perimeter()const;
    void show_info()const;
    friend std::istream& operator >> (std::istream&, Triangle &);
};
////////////////////////////////////////////////////////////////////////////////
class Cube : public Shape
{
private:
    double length;
public:
    Cube();
    Cube(double, std::string name = "Cube", std::string type = "3D");
    double get_area()const;
    double get_volume()const;
    double get_perimeter()const;
    void show_info()const;
    friend std::istream& operator >> (std::istream&, Cube &);
};
////////////////////////////////////////////////////////////////////////////////
class Sphere : public Shape
{
private:
    double radius;
public:
    Sphere();
    Sphere(double, std::string name = "Sphere", std::string type = "3D");
    double get_area()const;
    double get_volume()const;
    void show_info()const;
    friend std::istream& operator >> (std::istream&, Sphere &);
};

#endif // SHAPES_H
