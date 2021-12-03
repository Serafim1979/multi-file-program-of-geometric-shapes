#include<iostream>
#include<fstream>
#include <random>
#include <ctime>
#include"Shapes.h"

const int max_number = 100;
int generate_date(std::string file_name)
{
    const int number_of_names = 6;
    std::string names[number_of_names] = {"Circle", "Square", "Rectangle", "Triangle", "Cube", "Sphere"};
    std::string types[] = {"2D", "3D"};
    int number_of_people = rand() % (max_number + 1);

    std::ofstream out(file_name);

    for(int i = 0; i < number_of_people; i++)
    {
        int type = rand() % 2;
        out << types[type] << " " << names[rand() % number_of_names] << " ";
    }

}

int main()
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_real_distribution<> distribution(1., 10.);

    std::mt19937 generator2(random_device());
    std::uniform_int_distribution<>distribution2(0, 6);

    int size_array = 6;
    Shape* ptrShape[size_array];
    ptrShape[0] = new Circle(distribution(generator));
    ptrShape[1] = new Square(distribution(generator));
    ptrShape[2] = new Rectangle(distribution(generator), distribution(generator));
    ptrShape[3] = new Triangle(distribution(generator), distribution(generator), distribution(generator));
    ptrShape[4] = new Cube(distribution(generator));
    ptrShape[5] = new Sphere(distribution(generator));


    std::cout << "---------------------------------------------" << std::endl;
    for(int i = 0; i < size_array; i++)
    {
        ptrShape[i]->show_info();
    }

    std::cout << "====================================================" << std::endl;
    int n;
    std::cout << "Enter size: " << std::endl;
    std::cin >> n;

    Shape* ptr_custom_array[n];
    for(int i = 0; i < n; i++)
    {
        ptr_custom_array[i] = ptrShape[distribution2(generator2)];
    }

    for(int i = 0; i < n; i++)
    {
        ptr_custom_array[i]->show_info();
    }




    for(int i = 0; i < size_array; i++)
    {
        delete ptrShape[i];
    }
    delete [] ptrShape;
    return 0;
}
