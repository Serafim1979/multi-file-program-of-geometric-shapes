#include<iostream>
#include<fstream>
#include <random>
#include <vector>
#include <iomanip>
#include <ctime>
#include"Shapes.h"


int main()
{
    const std::string file_name = "data_test.txt";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_real_distribution<> distribution(1., 10.);

    std::mt19937 generator2(random_device());
    std::uniform_int_distribution<>distribution2(0, 5);

    int size_array = 6;
    Shape* ptrShape[size_array];
    ptrShape[0] = new Circle(distribution(generator));
    ptrShape[1] = new Square(distribution(generator));
    ptrShape[2] = new Rectangle(distribution(generator), distribution(generator));
    ptrShape[3] = new Triangle(distribution(generator), distribution(generator), distribution(generator));
    ptrShape[4] = new Cube(distribution(generator));
    ptrShape[5] = new Sphere(distribution(generator));

    // Demonstration of user input (console)
    Circle c1;
    std::cin >> c1;
    c1.show_info();




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

//////////////////////////////-----FIND MAXIMUM-----///////////////////////////////////////////////

    double val_max = ptr_custom_array[0]->get_area();
    int ind = 0;
    std::vector<int>index;
    for(int i = 0; i < n - 1; i++)
    {
        if(val_max > ptr_custom_array[0]->get_area())
        {
            val_max = ptr_custom_array[i]->get_area();
            ind = i;
            index.push_back(ind);
        }
    }

    for(int j = 0; j < n; j++)
    {
        if(ptr_custom_array[ind]== ptr_custom_array[j])
        {
            index.push_back(j);
        }
    }

    std::cout << "Max area: " << val_max << " ";
    ptr_custom_array[ind]->show_info();


    std::cout << "====================================================" << std::endl;
    for(int i = 0; i < (int)index.size(); i++)
    {
        std::cout << "index: " << index[i] << ", ";
        ptr_custom_array[index[i]]->show_info();
    }


    std::ofstream out(file_name);

    if (out.is_open())
    {
        for(int i = 0; i < n; i++)
        {
            out << std::left <<"name: " << std::setw(9) << ptr_custom_array[i]->get_name() << " type: " << ptr_custom_array[i]->get_type() << " area: " <<  ptr_custom_array[i]->get_area() << std::endl;
        }
        out << std::endl << "******************************************************" << std::endl;
        out << "Figures with the maximum area." << std::endl;
        for(int i = 0; i < (int)index.size(); i++)
        {
            out << "index: " << index[i] << ", " << ptr_custom_array[index[i]]->get_name() << " " << ptr_custom_array[index[i]]->get_type() << " " << ptr_custom_array[index[i]]->get_area() << std::endl;
        }
    }
    else
    {
        std::cout << "Failed";
    }

    out.close();

    return 0;
}
