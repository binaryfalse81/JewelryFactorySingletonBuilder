#include <iostream>
#define interface struct
using namespace std;

interface Jewelry
{
    virtual void showInfo() = 0;
};

class Gold : public Jewelry
{
public:
    class Builder
    {
    public:
        Builder& setName(string name)
        {
            this->name = name;
            return *this;
        }

        Builder& setPrice(int price)
        {
            this->price = price;
            return *this;
        }

        Gold* build()
        {
            return new Gold{ name, price };
        }

    private:
        string name;
        int price;
    };

    void showInfo() override
    {
        cout << name << endl;
        cout << price << endl;
    }
private:
    Gold(string alias, int price)
        : name{ name }, price{ price } { }

    string name;
    int price;
};

class Ruby : public Jewelry
{
public:
    Ruby(string name, int price)
        : name{ name }, price{ price } { }

    void showInfo() override
    {
        cout << name << endl;
        cout << price << endl;
    }
private:
    string name;
    int price;
};

class Diamond : public Jewelry
{
public:
    Diamond(string name, int price)
        : name{ name }, price{ price } { }

    void showInfo() override
    {
        cout << name << endl;
        cout << price << endl;
    }
private:
    string name;
    int price;
};

class JewelryFactory
{
public:
    static JewelryFactory& getInstance()  
    {
        static JewelryFactory instance;
        return instance;
    }

    Jewelry* makeJewelry(string name, int price)
    {
        if (name == "ruby") return new Ruby(name, price);
        if (name == "diamond") return new Diamond(name, price);
        return Gold::Builder().setName(name).setPrice(price).build();
    }

private:
    JewelryFactory() {}
};

int main()
{
    JewelryFactory& fac = JewelryFactory::getInstance();
    Jewelry* mine = fac.makeJewelry("gold", 1000);

    mine->showInfo();
}