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
    std::cout << "name: " << name << ", type: " << type << ", area: " << get_area();
}

//------Start of class implementation Circle--------
Circle::Circle() : Shape(name, type){}
Circle::Circle(double radius, std::string name, std::string type) : Shape(name, type)
{
    this->radius = radius;
}
void Circle::set_name(std::string name)
{
    this->name = name;
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
    out << crcl->get_name() << " " << crcl->get_type() << " " << crcl->get_area() << " " << crcl->get_perimeter();
    return out;
}
std::istream& operator >> (std::istream& in, Circle &crcl)
{
    std::cout << "Input name: ";
    in >> crcl.name;
    std::cout << "Input type: ";
    in >> crcl.type;
    std::cout << "Input radius: ";
    in >> crcl.radius;
    return in;
}

////------Start of class implementation Square--------
Square::Square(double side, std::string name, std::string type) : Shape(name, type)
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
std::ostream& operator << (std::ostream& out, Square*& sqr)
{
    out << sqr->get_name() << " " << sqr->get_type() << " " << sqr->get_area() << " " << sqr->get_perimeter();
    return out;
}

////------Start of class implementation Rectangle--------
Rectangle::Rectangle(double side_a, double side_b, std::string name, std::string type) : Shape(name, type)
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
std::ostream& operator << (std::ostream& out, Rectangle*& rect)
{
    out << rect->get_name() << " " << rect->get_type() << " " << rect->get_area() << " " << rect->get_perimeter();
    return out;
}

////------Start of class implementation Triangle--------
Triangle::Triangle(double side_a, double side_b, double side_c, std::string name, std::string type) : Shape(name, type)
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
std::ostream& operator << (std::ostream& out, Triangle*& trndl)
{
    out << trndl->get_name() << " " << trndl->get_type() << " " << trndl->get_area() << " " << trndl->get_perimeter();
    return out;
}

////------Start of class implementation Cube--------
Cube::Cube(double length, std::string name, std::string type) : Shape(name, type)
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
std::ostream& operator << (std::ostream& out, Cube*& cube)
{
    out << cube->get_name() << " " << cube->get_type() << " " << cube->get_area() << " " << cube->get_volume() << " " << cube->get_perimeter();
    return out;
}

////------Start of class implementation Sphere--------
Sphere::Sphere(double radius, std::string name, std::string type) : Shape(name, type)
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
std::ostream& operator << (std::ostream& out, Sphere*& sph)
{
    out << sph->get_name() << " " << sph->get_type() << " " << sph->get_area() << " " << sph->get_volume();
    return out;
}

