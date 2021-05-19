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
