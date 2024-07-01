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
    void showInfo() override
    {
        cout << name << endl;
        cout << price << endl;
    }
private:
    string name = "GOLD";
    int price = 100;
};

class Ruby : public Jewelry
{
public:
    void showInfo() override
    {
        cout << name << endl;
        cout << price << endl;
    }
private:
    string name = "Ruby";
    int price = 200;
};

class Diamond : public Jewelry
{
public:
    void showInfo() override
    {
        cout << name << endl;
        cout << price << endl;
    }
private:
    string name = "Diamond";
    int price = 300;
};

class JewelryFactory
{
public:
    static JewelryFactory& getInstance()  
    {
        static JewelryFactory instance;
        return instance;
    }

    Jewelry* makeJewelry(string name)
    {
        if (name == "gold") return new Gold();
        if (name == "ruby") return new Ruby();
        if (name == "diamond") return new Diamond();
        return nullptr;
    }

private:
    JewelryFactory() {}
};

int main() {
    JewelryFactory& fac = JewelryFactory::getInstance();
    fac.makeJewelry("gold")->showInfo();
    fac.makeJewelry("ruby")->showInfo();
    fac.makeJewelry("diamond")->showInfo();
}