#include <iostream>
using namespace std;
class Car
{
    char* model;
    int year;
    double price;
public:
    Car()
    {
        model = 0;
        year = 0;
        price = 0.0;
    }
    Car(const char* mod)
    {
        model = new char[strlen(mod) + 1];
        strcpy(model, mod);
    }
    Car(const char* mod, int y, double pr) : Car(mod)
    {

        year = y;
        price = pr;
    }
    Car& operator+=(double yvilichenie)
    {
        price += yvilichenie;
        return *this;
    }

    Car& operator-=(double ponizhenie)
    {
        price -= ponizhenie;
        return *this;
    }
    Car operator++(int)
    {
        Car temp = *this;
        ++year;
        return temp;
    }

    Car operator--(int)
    {
        Car temp = *this;
        --year;
        return temp;
    }
    double operator-(const Car& other)
    {
        return price - other.price;
    }
    double operator+(const Car& other)
    {
        return price + other.price;
    }

    Car(const Car& obj) :Car(obj.model, obj.year, obj.price)
    {}
    Car& operator=(const Car& obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        if (model != nullptr)
        {
            delete[] model;
        }
        model = new char[strlen(obj.model) + 1];
        strcpy(model, obj.model);
        year = obj.year;
        price = obj.price;
        return *this;

    };

    ~Car()
    {
        delete[] model;
    }
    const char* getModel()
    {
        return model;
    }
    int GetYear()
    {
        return year;
    }
    double GetPrice()
    {
        return price;
    }
    void SetModel(const char* mod)
    {
        if (model != nullptr)
            delete[] model;
        model = new char[strlen(mod) + 1];
        strcpy(model, mod);
    }
    void SetYear(int y)
    {
        year = y;
    }
    void SetPrice(double pr)
    {
        price = pr;
    }
};
ostream& operator<<(ostream& os, Car& obj)
{
    os << obj.getModel() << "\t" << "\t" << obj.GetYear() << "\t" << obj.GetPrice() << endl;
    return os;
}
istream& operator>>(istream& is, Car& obj)
{
    char buff[20];
    cout << "Enter model: ";
    is >> buff;
    obj.SetModel(buff);
    int y;
    double pr;
    cout << "Enter year: ";
    is >> y;
    obj.SetYear(y);
    cout << "Enter price: ";
    is >> pr;
    obj.SetPrice(pr);
    return is;

}

int main()
{
    Car obj1("Audi A5", 2023, 50000);
    cout << obj1 << endl;
    cin >> obj1;
    Car obj2("Porshe GT3RS", 2023, 200000);
    cout << obj2 << endl;



    obj1 += 1000;
    cout << "Увеличил на 1000: " << endl;
    cout << obj1 << endl;

    obj1 -= 1000;
    cout << "Понизил на 1000: " << endl;
    cout << obj1 << endl;


    obj1++;
    cout << "Увеличил год на 1: " << obj1 << endl;

    obj1--;
    cout << "Понизил год на 1: " << obj1 << endl;


    cout << "Разница в цене: " << obj2 - obj1 << endl;

    cout << "Cумма ценн: " << obj2 + obj1 << endl;
}