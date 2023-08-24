#include <iostream>
#include <vector>
#include <algorithm>

class counter_functor{
public:
    counter_functor(): sum_(0), count_(0){
    }

    int get_sum(){
        return sum_;
    }

    int get_count(){
        return count_;
    }

    void operator()(int a){
        if (a % 3 == 0){
            sum_ += a;
            count_++;
        }
    }

private:
    int sum_;
    int count_;
};

template <class T>
std::ostream &operator<< (std::ostream &out, std::vector<T> &v){
    for (int i = 0; i < v.size() - 1; ++i){
        out << v[i] << " ";
    }
    out << v[v.size() - 1];
    return out;
}


int main(){
    std::vector<int> v = {4,1,3,6,25,54};
    std::cout << "[IN] " << v << "\n";
    counter_functor t = std::for_each (v.begin(), v.end(), counter_functor());
    std::cout << "[OUT]: get_sum() = " << t.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << t.get_count() << "\n";        
    return 0;
}