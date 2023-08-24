#include <iostream>


template <class T>

class table{
public:
    table (const table&) = delete;
    table &operator= (const table&) = delete;

    table(int r, int c):row_(r), column_(c){
        create_array();
        fill_array();
    }

    ~table(){
        delete_array();
    }

    const T * operator[](int n) const{
        return array_[n];
    }


    T * operator [](int n){
        return array_[n];
    }

    int size() const {
        return row_ * column_;
    }



private:
    int row_;
    int column_;
    T **array_ = nullptr;
    
    void create_array(){
        array_ = new T *[row_];
        for (int i = 0; i < row_; ++i){
            array_[i] = new T [column_];
        }
    }

    void fill_array(){
        for (int i = 0; i < row_; ++i){
            for (int j = 0; j < column_; ++j){
                array_[i][j] = 0;
            }
        }
    }

    void delete_array(){
        for (int i = 0; i < row_; ++i){
            delete [] array_[i];
        }
        delete [] array_;
    }
};


int main(){
    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;
    std::cout << test.size();

    return 0;
}