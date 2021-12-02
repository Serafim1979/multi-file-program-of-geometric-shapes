#include"Shapes.h"

//------Start of class implementation Shapes--------
Shape::Shape(std::string name, std::string type)
{
    this->name = name;
    this->type = type;
}
std::string Shape::get_name()const
{
    return name;
}
std::string Shape::get_type()const
{
    return type;
}
void Shape::show_info()const
{
    std::cout << name << " type: " << type << ", area: " << get_area();
}

//------Start of class implementation Circle--------
Circle::Circle(std::string name, double radius , std::string type) : Shape(name, type)
{
    this->radius = radius;
}
double Circle::get_area()const {return 3.14 * radius * radius;}
double Circle::get_perimeter()const {return 2 * 3.14 * radius;}
void Circle::show_info()const
{
    Shape::show_info();
    std::cout << ", perimeter: " << get_perimeter() << std::endl;
}
std::ostream& operator << (std::ostream& out, Circle*& crcl)
{
    out << crcl->get_name() << " " << crcl->get_type();
    return out;
}

////------Start of class implementation Square--------
Square::Square(std::string name, double side, std::string type) : Shape(name, type)
{
    this->side = side;;
}
double Square::get_area()const{return side * side;}
double Square::get_perimeter()const{return 4 * side;}
void Square::show_info()const
{
    Shape::show_info();
    std::cout << ", perimeter: " << get_perimeter() << std::endl;
}

////------Start of class implementation Rectangle--------
Rectangle::Rectangle(std::string name, double side_a, double side_b, std::string type) : Shape(name, type)
{
    this->side_a = side_a;
    this->side_b = side_b;
}
double Rectangle::get_area()const{return side_a * side_b;}
double Rectangle::get_perimeter()const{return 2 * (side_a + side_b);}
void Rectangle::show_info()const
{
    Shape::show_info();
    std::cout << ", perimeter: " << get_perimeter() << std::endl;
}

////------Start of class implementation Triangle--------
Triangle::Triangle(std::string name, double side_a, double side_b, double side_c, std::string type) : Shape(name, type)
{
    this->side_a = side_a;
    this->side_b = side_b;
    this->side_c = side_c;
}
double Triangle::get_area()const
{
    double p = (side_a + side_b + side_c) / 2;
    return std::sqrt(p *(p - side_a) *(p - side_b)*(p - side_c));
}
double Triangle::get_perimeter()const{return side_a + side_b + side_c;}
void Triangle::show_info()const
{
    Shape::show_info();
    std::cout << ", perimeter: " << get_perimeter() << std::endl;
}

////------Start of class implementation Cube--------
Cube::Cube(std::string name, double length, std::string type) : Shape(name, type)
{
    this->length = length;
}
double Cube::get_area()const{return 6 * length * length;}
double Cube::get_volume()const{return length * length * length;}
double Cube::get_perimeter()const{return 12 * length;}
void Cube::show_info()const
{
    Shape::show_info();
    std::cout <<  ", volume: " << get_volume() << ", perimeter: " << get_perimeter() << std::endl;
}

////------Start of class implementation Sphere--------
Sphere::Sphere(std::string name, double radius, std::string type) : Shape(name, type)
{
    this->radius = radius;
}
double Sphere::get_area()const{return 4 * 3.14 * radius * radius;}
double Sphere::get_volume()const{return (4 / 3) * 3.14 * radius * radius * radius;}
void Sphere::show_info()const
{
    Shape::show_info();
    std::cout << ", volume: " << get_volume() << std::endl;
}

