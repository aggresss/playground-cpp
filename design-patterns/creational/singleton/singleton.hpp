#include <functional>

template <class T>
class Singular
{
public:
    template <class... Args>
    static T* Instance(Args... _args) {
        static auto getInstance = [_args...]() -> T& {
            return GetInstance(_args...);
        };
        return GetOne(getInstance);
    }
protected:
    Singular() = delete;
    ~Singular() = delete;
    Singular(Singular&) = delete;
    Singular& operator=(const Singular&) = delete;
private:
    static T* GetOne(const std::function<T&()>& _getInstance) {
        static T& instance = _getInstance();
        return &instance;
    }
    template<class... Args>
    static T& GetInstance(Args... _args) {
        static T instance{std::forward<Args>(_args)...};
        return instance;
    }
};
