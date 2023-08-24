#include <iostream>
#include <vector>

template <class T>
T squaring(T num){
    return num * num;
}

template <class T>
std::vector<T> squaring (std::vector<T> &vec){
    std::vector<T> result(vec.size());

    for (int i = 0; i < vec.size(); ++i ){
        result[i] = vec[i] * vec[i];
    }
    return result;
}

template <class T>
void vector_print(const std::vector<T> &vec){
    for (const auto v : vec){
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main(){
    int m = 4;
    std::cout << "[IN] " << m << std::endl;
    std::cout << "[OUT] " << squaring(m) << std::endl;

    std::vector<int> vec = {-1, 15, 12};
    
    std::cout << "[IN] ";
    vector_print(vec);

    std::vector<int> s_vec = squaring(vec);
    std::cout << "[OUT] ";
    vector_print(s_vec);

    return 0;
}
