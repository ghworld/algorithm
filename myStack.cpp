//
// Created by mi on 7/4/17.
//

#include <iostream>
#include <vector>
#include <exception>

using std::vector;

using namespace std;



//typename可以表示任何类型，而class只能表示类
template<typename T,typename container>
class stack
{
public:
//栈是否为空
    bool empty( ) const
    {
        return index==0;
    }

//出栈
    void pop( )
    {
        if(empty())
        {
          throw exception();
        }
        arr[index-1]=0;
        --index;
    }

//出栈，如果默认数组未满继续添加数据，如果已满，重新分配一个两倍的数组，
//把默认数组中的数据拷贝过来，释放默认数组,将指针指向新数组
    void push(const T& val)
    {
        if(index<=capacity-1)
        {
            arr[index++]=val;
        }else
        {
            capacity<<=1;//capacity对应的二进制数左移一位
            int*tmp=new int[capacity];
            for(int i=0;i<index;i++)
            {
                tmp[i]=arr[i];
            }
            tmp[index++]=val;
            delete arr;
            arr=tmp;
        }
    }

//栈中元素个数
    int size( ) const
    {
        return index;
    }

    stack( )
    {
//默认栈中能存放4个元素，当然你会说这样不好，因为如果没有向栈中添加数据，却分配了四个元素的空间，显然不理想。
//为了避免这个问题，可以在push方法的开始判断栈中是否有元素，如果没有元素，就开始分配空间，有元素当然就不用，
//但是有个问题就是每次添加元素都要判断，如果添加元素较多的话，或许你会讨厌总要执行这多余的判断
//缓式评估告诉我们，只有到万不得已的情况下才定义变量和分配空间，不然就可能是定义的多余变量和不需要分配的空间
//但当某个变量是必须的，用缓式评估反而影响效率，因为为了实现缓式评估也是要代价的。
        initialize(4);
    }

//预设栈能容纳cap个元素
    stack(int cap)
    {
        initialize(cap);
    }

//explicit防止出现类型转换
    explicit stack(const container& cont)
    {
        initialize(cont.size());
        vector <int>::const_iterator iter=cont.begin();
        while(iter!=cont.end())
        {
            push(*iter++);
        }
    }

//析构
    ~stack()
    {
        delete arr;
    }

//输出栈顶元素
    T& top( )
    {
        return arr[index-1];
    }

//在C++中，可以重载const和non-const
    const T& top( ) const
    {
        return arr[index-1];
    }

private :
    int capacity;//容量
    int index;//顶部元素的位置
    T *arr;//数组

//初始化
//当然，初始化列表比赋值效率高，赋值多调用了一次constructor
    void initialize(int cap)
    {
        capacity=cap;
        arr=new T[capacity];
        index=0;
    }
};

