#include <iostream>
#include <string>
using namespace std;

template<typename T>
class MyNode{
public:
    T e;
    MyNode<T> *next;
    MyNode(T e, MyNode *next): e(e), next(next){}
    MyNode(T e): e(e), next(nullptr){}
    MyNode(): e(), next(nullptr){}
private:


};

template<typename T>
class LinkedList{
public:
    LinkedList(){
        dummyHead = new MyNode<T>();
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void add(int index, T e){
        if (!(index>=0 && index<=size)){
            cout<<"add failed, illegal index, index:"<<index<<endl;
        }
        MyNode<T> *prev = dummyHead; //prev: 前一个的
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        prev->next = new MyNode<T>(e, prev->next);
        size++;
    }
    void addFirst(T e){
        add(0,e);
    }
    void addLast(T e){
        add(size,e);
    }
    T get(int index){
        if (!(index>=   0 && index<=size)){
            cout<<"get failed, illegal index, index:"<<index<<endl;
        }
        MyNode<T> *cur = dummyHead->next; //cur: 当前的
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->e;
    }
    T getFirst(){
        return get(0);
    }
    T getLast(){
        return get(size-1);
    }
    void set(int index, T e){
        if (!(index>=0 && index<=size)){
            cout<<"Set failed, illegal index, index:"<<index<<endl;
        }
        MyNode<T> *cur = dummyHead->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->e = e;
    }
    T remove(int index){
        if (!(index>=0 && index<=size)){
            cout<<"Remove failed, illegal index, index:"<<index<<endl;
        }
        auto *prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
        }
        auto *delNode = prev->next; //待删除节点
        prev->next = delNode->next; //待删除节点前一个节点, 指向但删除节点的后一个节点
        //对待删除节点进行删除
        delNode->next = nullptr;
        T dataTemp = delNode->e; //对但删除节点数据进行保存
        delete(delNode);
        size--;
        return dataTemp; //返回已删除节点的数据;
    }
    T removeFirst(){
        return remove(0);
    }
    T removeLast(){
        return remove(size - 1);
    }
    bool contains(T e){
        MyNode<T> *cur = dummyHead->next;
        while (cur!= nullptr){
            if (cur->e == e){
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    string toString(){
        string *res = new string;
//        MyNode<T> cur = dummyHead.next;
//        for (int i = 0; i < size; i++) {
//            res.append(cur.e + "->")
//            cur = cur.next;
//        }
        for (MyNode<T> *cur = dummyHead->next; cur != nullptr; cur = cur->next) {
//            res->append(cur->e + "->");
            res->append(std::to_string(cur->e) + "->"); //TODO:这里直接使用了std::toString进行转换, 应当加入自己的逻辑判断
        }
        res->append("NULL");
        res->append("\n");
        return *res;
    }

private:
    int size;
    MyNode<T> *dummyHead;
};