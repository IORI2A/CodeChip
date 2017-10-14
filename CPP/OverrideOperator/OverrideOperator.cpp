//basic_ios::operator void *  
//operator void *( ) const;  Indicates if the stream is still good.  
  
#include <conio.h>  
#include <string.h>  
#include <iostream>  
  
class MyChar  
{  
public:  
    MyChar(char ch):  
        m_chValue(ch)  
    {  
        printf("Constructed: MyChar('%c')\n", ch);  
    }  
  
    MyChar():  
        m_chValue('*')  
    {  
        printf("Default Constructed: MyChar()\n");  
    }  
  
    ~MyChar()  
    {  
        printf("Default Destructed: ~MyChar()\n");  
    }  
  
    /****************** 类型转换函数 ***************/  
    operator char()  
    {  
        printf("Member Function: operator char()\n");  
        return m_chValue;  
    }  
  
    operator void*()  
    {  
        printf("Member Function: operator void*()\n");  
        return (m_chValue == '\0')?NULL:&m_chValue;  
    }  
  
    operator bool()    // 在需要BOOL表达式的地方，系统首先该转换函数  
    {  
        printf("Member Function: operator bool()\n");  
        return (bool)m_chValue;  
    }  
    /*********************************************/  
  
    MyChar &operator =(char ch)  
    {  
        printf("Member Function: operator=('%c')\n", ch);  
        m_chValue = ch;  
        return *this;  
    }  
  
private:  
    char m_chValue;  
};  
  
  
  
int main()  
{  
    int i = 10;  
    MyChar myCh;  
    while(myCh)    // 调用成员类型转换函数来满足 BOOL 类型的条件表达式。 测试调用成员类型转换函数的优先级：1.bool()；2.char()；3.void*()。  
    {  
        std::cout<<"while..."<<std::endl;  
  
        if(i)  
            i--;  
        else  
            break;  
    }  
  
    std::cin>>i;  // 阻止程序直接退出  
} 
