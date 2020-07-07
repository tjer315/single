// quicksort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <mutex>
using namespace std;

class  Singleton
{
public:

    ~Singleton() = default;
    static Singleton* GetInstance();
    static void Destory();
    static void Print();

private:

    static Singleton* m_instance;
    static mutex mu;

private:
    Singleton()= default;
    Singleton(const Singleton& pInstance) = delete;
    Singleton& operator =(const Singleton& pInstance) = delete;
};

Singleton* Singleton::m_instance = nullptr;
std::mutex Singleton::mu;



Singleton* Singleton::GetInstance()
{

    if (nullptr == m_instance)
    {
        lock_guard<mutex> lock(mu);
        if (nullptr == m_instance)
        {
            m_instance = new Singleton();
        }
    }
    return m_instance;
}

void Singleton::Destory()
{
    if (m_instance)
    {
        delete m_instance;
        m_instance = nullptr;
    }
}

void Singleton::Print()
{

    cout << "单例调用！" << endl;
}



int main()
{


    Singleton* s = Singleton::GetInstance();
    s->Print();

}


