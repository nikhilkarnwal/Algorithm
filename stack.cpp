#include<iostream>
using namespace std;
template <typename T> class stackN{
private:
    int capacity;
    T* arr;
    int top;
public:
    stackN(int sz){
    capacity = sz;
    arr = new int[sz];
    top = -1;
    }
    bool push(T data);
    bool isFull();
    bool isEmpty();
    T pop();
};
template <typename T> bool stackN<T>::push(T data){
    if(!isFull()){
        top++;
        arr[top]=data;
        return true;
    }
    return false;
}
template <typename T> bool stackN<T>::isFull(){
    return top == (capacity-1);
}

template <typename T> bool stackN<T>::isEmpty(){
    return top == -1;
}
template <typename T> T stackN<T>::pop(){
    if(!isEmpty()){
        T temp = arr[top];
        top--;
        return temp;
    }
    return NULL;
}
int main(){
    stackN<int> stk = stackN<int>(5);
    stk.push(5);
    stk.push(4);
    stk.push(2);
    while(stk.isEmpty()==false){
        cout<<stk.pop();
    }
    return 0;
}
