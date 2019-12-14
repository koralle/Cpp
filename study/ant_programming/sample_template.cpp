#include <iostream>

// このtemplate宣言が重要
template<typename T>
class testClass {
private:
    T val;
public:
    testClass(void){}
    T getVal(void){
        return val;
    }
    void setVal(T v){
        val = v;
    }
};

int main(void) {
    
    // intじゃなくてもstringでもfloatでもok
    testClass<int> tc1;
    tc1.setVal(123);

    std::cout << tc1.getVal() << std::endl;
    return 0;
}