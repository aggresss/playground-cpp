#include <cstdlib>

// 实例存储策略
template <typename T>
struct instance_data_policy  //无态类
{
    typedef T holder_type;
    typedef T value_type;

    // 在h上构造复制构造数据v的实例
    static void construct_data(holder_type &h, value_type const &v) {
        new (&h) holder_type(v);  // placement new语法，在已申请的空间地址上构造
    }

    // 从h上销毁数据
    static void destruct_data(holder_type const &h) {
        h.~holder_type();  // 只调用析构函数，不释放内存
    }

    // 两个取得数据引用的函数，分别返回只读及可写两种引用
    static value_type &get_value(holder_type &h) { return h; }

    static value_type const &get_const_value(holder_type const &h) { return h; }
};

// 指针存储策略
template <typename T>
struct pointer_data_policy {
    typedef T *holder_type;
    typedef T value_type;

    static void construct_data(holder_type &h, T const &v) {
        h = new T(v);  // 新申请空间复制构造v
    }

    static void destruct_data(holder_type h) {
        delete h;  // 析构及释放h所指空间
    }

    // 两个取得数据引用的函数，通过指针找到对应数据引用
    static value_type &get_value(holder_type &h) { return *h; }

    static value_type const &get_const_value(holder_type const &h) { return *h; }
};


#include <cstddef>

template <typename T,
          // data_policy是模板类模板函数
          template <typename> typename data_policy = instance_data_policy>  //数据的存储策略类作为模板参数供用户选择不同的策略
class vector                                                             //功能有限的vector
{
    typedef data_policy<T> policy_type;  // 由data_policy得到所需的策略类型
    typedef typename policy_type::holder_type holder_type;

   public:
    typedef size_t size_type;
    typedef T value_type;
    typedef value_type &reference;
    typedef value_type const &const_reference;

   private:
    holder_type *data_ptr;  // 数组指针
    size_type sz;           // 容器尺寸
    size_type buffer_sz;    // 所申请的空间尺寸

   public:
    // 在vector中我们用malloc/free申请及释放内存，用policy_type中的
    // 静态成员函数构造及析构数据
    // 在vector的构造函数中先预先申请存放一个数据的空间
    vector() : data_ptr((holder_type *)malloc(sizeof(holder_type))),
               sz(0),
               buffer_sz(1) {}

    template <typename I>
    vector(I begin, I end) : data_ptr((holder_type *)malloc(sizeof(holder_type))),
                             sz(0),
                             buffer_sz(1) {
        for (; begin != end; ++begin) push_back(*begin);
    }

    ~vector() {
        // 首先析构所有数据
        for (size_t i = 0; i < sz; ++i)
            policy_type::destruct_data(data_ptr[i]);
        free(data_ptr);  // 再释放内存
    }

    size_type size() const { return sz; }

    void push_back(value_type const &v) {
        if (sz == buffer_sz) {
            // 预留空间已用尽，须新申请更大空间
            buffer_sz *= 2;
            holder_type *new_data_ptr =
                (holder_type *)malloc(sizeof(holder_type) * buffer_sz);

            // 将旧空间内的holder_type数据利用placement new复制构造到新
            // 空间对应位置
            for (size_type i = 0; i < sz; ++i) {
                new (new_data_ptr + i) holder_type(data_ptr[i]);
                data_ptr[i].~holder_type();  // 同时析构旧空间中的
                                             // holder_type数据
            }
            free(data_ptr);
            data_ptr = new_data_ptr;
        }
        // 利用策略类的成员函数构造新数据
        policy_type::construct_data(data_ptr[sz++], v);
    }
    void pop_back() {
        // 利用策略类的成员函数析构数据
        policy_type::destruct_data(data_ptr[sz--]);
    }

    // 利用策略类成员函数取得所需数据引用。
    reference operator[](size_type pos) {
        return policy_type::get_value(data_ptr[pos]);
    }
    const_reference operator[](size_type pos) const {
        return policy_type::get_const_value(data_ptr[pos]);
    }
};

#include <iostream>

struct huge_data {
    static unsigned ever_copy_constructed;  // 记录调用构造函数的次数
    huge_data() {}
    huge_data(huge_data const &hd) { ++ever_copy_constructed; }
};

unsigned huge_data::ever_copy_constructed = 0;

void print_ecc() {
    static unsigned old_ecc = 0;
    std::cout << "ECC: " << huge_data::ever_copy_constructed
              << "\t delta ECC: " << (huge_data::ever_copy_constructed - old_ecc)
              << std::endl;
    old_ecc = huge_data::ever_copy_constructed;
}

int main() {
    huge_data array[] = {huge_data(), huge_data(), huge_data(),
                         huge_data(), huge_data(), huge_data(),
                         huge_data(), huge_data()};
    std::cout << "ECC means \"ever copy constructed\"." << std::endl;
    print_ecc();

    // 采用实例保存数据策略的容器
    vector<huge_data> v(array, array + 8);  //复制构造开销大
    print_ecc();

    // 采用指针保存数据策略的容器
    vector<huge_data, pointer_data_policy> pv(array, array + 8);
    print_ecc();
}
