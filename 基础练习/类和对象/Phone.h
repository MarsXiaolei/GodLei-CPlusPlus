#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <string>

class Phone{
public:
    Phone();
    Phone(const std::string brand, const std::string model, const std::string color, const int price);
    ~Phone();

    void setBrand(const std::string brand);
    std::string getBrand();

    void setModel(const std::string model);
    std::string getModel();

    void setColor(const std::string color);
    std::string getColor();

    void setPrice(const int price);
    int getPrice();

private:
    std::string m_brand;        // 品牌
    std::string m_model;        // 型号
    std::string m_color;        // 颜色
    int m_price;                // 价格
};

#endif // PHONE_H
