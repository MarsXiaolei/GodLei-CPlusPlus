### 访问类成员
可以使用句点运算符`.`和指针运算符`->`访问类成员
```cpp
Human firstMan;
firstMan.name = "Adam";
firstMan.age = 30;
```
```cpp
Human* firstWoman = new Human();
firstWoman->dateOfBirth = "1970";
firstWoman->IntroduceSelf();
delete firstWoman;
```

### 构造函数
* 默认构造函数
* 有参构造函数
* 拷贝构造函数
http://c.biancheng.net/view/2221.html

### 析构函数

### 类成员变量初始化
* C++类中成员变量的初始化有两种方式：构造函数初始化列表和构造函数体内赋值<br>
* 注意：这两种方式不能同时出现，同名同参数属于函数重复定义<br>
* 初始化列表由包含在括号中的参数声明后面的冒号标识，冒号后面列出了各个成员变量及其初始值<br>
* 初始值可以是参数，也可以是固定的值<br>

`Phone.h`

```cpp
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
```

`Phone.cpp`

```cpp
/*
 * C++类中成员变量的初始化有两种方式：构造函数初始化列表和构造函数体内赋值
 * 注意：这两种方式不能同时出现，同名同参数属于函数重复定义
 * 初始化列表由包含在括号中的参数声明后面的冒号标识，冒号后面列出了各个成员变量及其初始值。
 * 初始值可以是参数，也可以是固定的值
 */
#include "Phone.h"

/**
 * @brief 默认构造函数
 */
Phone::Phone()
{
    m_brand = "";        // 品牌
    m_model = "";        // 型号
    m_color = "";        // 颜色
    m_price = 0;         // 价格
}

/**
 * @brief 通过构造函数初始化列表方式初始化类成员变量
 * @param brand
 * @param model
 * @param color
 * @param price
 */
Phone::Phone(const std::string brand, const std::string model, const std::string color, const int price)
    :m_brand(brand),m_model(model),m_color(color),m_price(price)
{
    std::cout<<"m_brand "<<m_brand<<"\n"
            <<"m_model "<<m_model<<"\n"
           <<"m_color "<< m_color<<"\n"
          <<"m_price "<<m_price;
}


/**
 * @brief 通过构造函数内赋值初始化类成员变量
 * @param brand
 * @param model
 * @param color
 * @param price
 */
//Phone::Phone(const std::string brand, const std::string model, const std::string color, const int price)
//{
//    m_brand = brand;        // 品牌
//    m_model = model;        // 型号
//    m_color = color;        // 颜色
//    m_price = price;        // 价格

//    std::cout<<"m_brand "<<m_brand<<"\n"
//            <<"m_model "<<m_model<<"\n"
//           <<"m_color "<< m_color<<"\n"
//          <<"m_price "<<m_price;
//}

Phone::~Phone()
{

}

void Phone::setBrand(const std::string brand)
{
    m_brand = brand;
}

std::string Phone::getBrand()
{
    return m_brand;
}

void Phone::setModel(const std::string model)
{
    m_model = model;
}

std::string Phone::getModel()
{
    return m_model;
}

void Phone::setColor(const std::string color)
{
    m_color = color;
}

std::string Phone::getColor()
{
    return m_color;
}

void Phone::setPrice(const int price)
{
    m_price = price;
}

int Phone::getPrice()
{
    return m_price;
}
```
`main.cpp`

```cpp
#include <iostream>
#include <string>
#include "Phone.h"

using namespace std;

int main()
{
    Phone phone("XiaoMi","Mi11","white",3999);

    Phone phone_2;
    phone_2.setBrand("HuaWei");
    phone_2.setColor("black");
    phone_2.setModel("P40");
    phone_2.setPrice(5999);
    std::cout<<"\n------ phone_2 --------\n"
            <<"m_brand "<<phone_2.getBrand()<<"\n"
            <<"m_model "<<phone_2.getColor()<<"\n"
           <<"m_color "<<phone_2.getModel()<<"\n"
          <<"m_price "<<phone_2.getPrice();

    return 0;
}
```
