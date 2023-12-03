#include <iostream>
#include <array>
#include <memory>
using namespace std;

class ShopItem
{
private:
    int product_id;
    double product_price;
    string product_name;
public:
    ShopItem(int p_id, double p_price, string p_name) : product_id(p_id), product_price(p_price), product_name(p_name) {}

    int getProductId() const 
    { 
        return product_id; 
    }

    double getProductPrice() const 
    { 
        return product_price; 
    }

    string getProductName() const 
    {
        return product_name; 
    }

    void getInfo() const
    {
        cout << "|--------------------------------------------------|" << endl;
        cout << "|Ідентифікатор товару: " << product_id << "                           |" << endl;
        cout << "|Назва товару        : " << product_name << endl;
        cout << "|Ціна за одиницю     : " << product_price << " грн." << "                 |" << endl;
    }
};

class ShopOrder
{
private:
    array<shared_ptr<ShopItem>, 6> ordered_products;
public:
    ShopOrder(const array<shared_ptr<ShopItem>, 6>& products) : ordered_products(products) {}

    double calculateTotalCost() const
    {
        double totalCost = 0.0;
        for (const auto& product : ordered_products)
        {
            totalCost += product->getProductPrice();
        }
        return totalCost;
    }

    void displayOrder() const
    {
        cout << "|--------------------------------------------------|" << endl;
        cout << "|               Замовлені товари                   |" << endl;

        for (const auto& product : ordered_products)
        {
            product->getInfo();
        }

        cout << "|--------------------------------------------------|" << endl;
        cout << "|                                                  |" << endl;
        cout << "|--------------------------------------------------|" << endl;
        cout << "|     Загальна вартість замовлення: " << calculateTotalCost() << " грн.     |" << endl;
        cout << "|--------------------------------------------------|" << endl;
    }
};

int main()
{
    system("chcp 1251>nul");

    array<shared_ptr<ShopItem>, 6> Products
    {
        make_shared<ShopItem>(1, 9954.4, "Системний блок              |"),
        make_shared<ShopItem>(2, 6432.7, "Монітор                     |"),
        make_shared<ShopItem>(3, 1245.5, "Комп'ютерна мишка           |"),
        make_shared<ShopItem>(4, 210.24, "Килимок для мишки           |"),
        make_shared<ShopItem>(5, 566.75, "Клавіатура                  |"),
        make_shared<ShopItem>(6, 873.41, "Навушники                   |")
    };

    ShopOrder order(Products);
    order.displayOrder();

    return 0;
}
