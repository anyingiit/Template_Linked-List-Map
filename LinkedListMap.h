#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

//template<typename Key, typename Value>
//class MyMapNode{
//public:
//    Key key;
//    Value value;
//    MyMapNode<Key,Value> *next;
//    MyMapNode(Key key, Value value, MyMapNode<Key,Value> *next):key(key),value(value),next(next){}
//    MyMapNode(Key key):key(key),value(),next(nullptr){}
//    MyMapNode():key(),value(),next(nullptr){}
////    string toString(){ //因为Value类型的不确定性, 所以不应当设置toString类型
////        auto *res = new string;
////        res->append(std::to_string(key));
////        res->append(":");
////        res->append(value);
////        return *res;
//////        return to_string(key) + ":";
////    }
//};


template<typename Key, typename Value>
class LinkedListMap:Map<Key, Value>{ //实现了Map接口
public:
    LinkedListMap(){
        dummyHead = new MyMapNode<Key, Value>(); //dummyHead指向一个键,值,next均为空的节点
        size = 0;
    }
    void add(Key key,Value value){
        MyMapNode<Key,Value> *node = getNode(key);
        if (node == nullptr){//如果找不到该节点, 那么在链表头添加元素
            dummyHead->next = new MyMapNode<Key, Value>(key,value,dummyHead->next);
            size++;
        } else{ //否则为该节点已经存在 //否则更新这个值 //这里可以选择抛出异常或者更新
            node->value = value;
        }
    }
    Value remove(Key key){
        MyMapNode<Key, Value> *prev = dummyHead;
        while (prev->next != nullptr){
            if (prev->next->key == key){
                break;
            }
        }
        if (prev->next != nullptr){ //找到了
            auto *delNode = prev->next; //待删除节点
            prev->next = delNode->next; //待删除节点前一个节点, 指向但删除节点的后一个节点
            //对待删除节点进行删除
            delNode->next = nullptr;
            Value dataTemp = delNode->value; //对但删除节点数据进行保存
            delete(delNode);
            size--;
            return dataTemp; //返回已删除节点的数据;
        }
        cout<<"Remove failed, illegal key!"<<endl;
        return Value();//没找到, 直接返回空
    }
    Value get(Key key){//使用get要特别注意, 应该提前判断该值是否存在, 存在再get
        MyMapNode<Key, Value> *node = getNode(key);
        //这里处理用户传入一个不存在的key时的处理方法是提示错误,并且返回空数据
        if (node == nullptr){cout<<"Get failed, illegal key"<<endl;}
        return node == nullptr?Value():node->value;
    }
    bool contains(Key key){
        return getNode(key) != nullptr;
    }
    void set(Key key, Value newValue){
        MyMapNode<Key, Value> *node = getNode(key);
        if (node == nullptr){//TODO: 抛出异常
            cout<<"Set failed, key:"<<key<<"doesn't exist!"<<endl;
        }
        node->value = newValue;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
//    string toString(){
//        auto *res = new string;
//        for (auto *cur = dummyHead->next;cur != nullptr;cur = cur->next){
//            res->append(cur->toString());
//        }
//        return *res;
//    }
//    string toString(){
//        string *res = new string;
//        for (auto *cur = dummyHead->next;cur != nullptr;cur = cur->next) {
//            cout<<cur->key<<endl;
////            if (typeid(cur->value) == typeid(string)){
////                cout<<"yes"<<endl;
////            } else{
////                cout<<"no"<<endl;
////            }
//            typeid(cur->value) == typeid(string)?cout<<"yes"<<endl:cout<<"no"<<endl;
//            auto valueRst = new string;
//            if (typeid(cur->value) == typeid(string)){
//                valueRst = cur->value;
//            } else{
////                valueRst = std::to_string(cur->value);
//            }
////            res->append(std::to_string(cur->key) + ":" +valueRst);
////            res->append(std::to_string(cur->key) + ":" + typeid(cur->value) == typeid(string)?cur->value:std::to_string(cur->value));
//        }
//        return *res;
//    }


private:
    template<typename K, typename V>
    class MyMapNode{
    public:
        K key;
        V value;
        MyMapNode<K,V> *next;
        MyMapNode(K key, V value, MyMapNode<K,V> *next):key(key),value(value),next(next){}
        MyMapNode(K key):key(key),value(),next(nullptr){}
        MyMapNode():key(),value(),next(nullptr){}
//    string toString(){ //因为Value类型的不确定性, 所以不应当设置toString类型
//        auto *res = new string;
//        res->append(std::to_string(key));
//        res->append(":");
//        res->append(value);
//        return *res;
////        return to_string(key) + ":";
//    }
    };

    MyMapNode<Key, Value> *dummyHead;
    int size;

    MyMapNode<Key,Value> *getNode(Key key) {
        for (auto *cur = dummyHead->next; cur != nullptr; cur = cur->next) {
            if (cur->key == key) {
                return cur;
            }
        }
        return nullptr;
    }

//        MyMapNode<Key, Value> *cur = dummyHead->next;
//        while (cur != nullptr) {
//            if (cur->key == key) {
//                return cur;
//            }
//            cur = cur->next;
//        }
//        return nullptr;
//    }
};