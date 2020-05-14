[点我获取Github readme 编写语法规则]https://blog.csdn.net/guodongxiaren/article/details/23690801<br>
`程序追求的最高境界是:高内聚（函数功能越单一越好，目标越专一越好），低耦合（类与其他类关系越少越好）`
## CPlusPlus 使用C++语言编写的代码<br>

1、结构体和类的区别？<br>
2、两种单次编译方式的区别？<br>
3、const和宏的区别。<br>
4、函数参数按值、按指针、按引用、按const 引用传递的区别？<br>

### 什么时候使用类前置声明？<br>
`class A;`

### 类与类之间关系？<br>
`(1)has-a 组合关系，人包含头、身体、手和脚。`<br>
`(2)is-a 继承关系，具有传递性,不具有对称性`<br>
[其他关系]https://www.cnblogs.com/xiaojiang1025/p/6677978.html<br>
[其他关系]https://blog.csdn.net/qq_39551987/article/details/80730664<br>
[其他关系]https://blog.csdn.net/chongji_liang/article/details/51819811<br>

### 如何正确使用访问标识符private、public、protected？
`(1)需要被外界访问的成员直接设置为public。`<br>
`(2)只能在当前类中访问的成员设置为private。`<br>
`(3)只能在当前类和子类中访问的成员设置为protected，protected成员的访问权限介于public和private之间。`<br>
![](https://github.com/MarsXiaolei/CPlusPlus/blob/master/%E6%89%B9%E6%B3%A8%202020-05-14%20113253.png)

### 多态成立的条件是什么？<br>
`（1）要有继承。`<br>
`（2）要有虚函数重写。`<br>
`（3）父类指针指向子类对象。`<br>

### 5、如何区分类中的重载、重写、隐藏？<br>
`相同点：就是大家的名称相同。`<br>
`重载是在同一个类中，而重写和隐藏是在基类和派生类中，这个很好区分，重点是区分重写和隐藏。`<br>
`（1）参数相同，如果有virtual，则为重写；如果无virtual，则为隐藏。`<br>
`（2）参数不同，不管有无virtual，都为隐藏。`<br>
`或者这样区分，更好理解，重写必须有virtual,且参数相同；参数不同和无virtual的都是隐藏。`<br>
`（1）有virtual，如果参数相同，则为重写；如果参数不同，则为隐藏。`<br>
`（2）无virtual，不管参数相不相同，都为隐藏。`<br>

6、什么时候使用内联函数，有什么优缺点？<br>
8、使用智能指针的好处是什么？<br>
9、bool和BOOL的区别？<br>
10、函数默认参数怎么使用？<br>
11、派生类的访问权限是什么？<br>
12、什么是封装、继承、多态，有什么好处？<br>
13、什么是纯虚函数和抽象类？<br>
14、为什么要重载运算符？<br>
15、如何使用条件编译？<br>
16、如何使用名称空间？<br>


## 【1】多态
![Image text](https://github.com/MarsXiaolei/image/blob/master/%E5%A4%9A%E6%80%811.png)
![Image text](https://github.com/MarsXiaolei/image/blob/master/%E5%A4%9A%E6%80%812.png)
![Image text](https://github.com/MarsXiaolei/image/blob/master/%E5%A4%9A%E6%80%813.png)


