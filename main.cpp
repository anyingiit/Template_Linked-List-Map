#include <iostream>
#include <map>
#include <vector>
#include "LinkedList.h"
#include "LinkedListMap.h"
#include "FileOps.h"

int main() {
//    auto *linkedListMap = new LinkedListMap<int,std::string>();
//    linkedListMap->add(5,"a");
//    cout<<linkedListMap->getSize()<<endl;
//    cout<<linkedListMap->get(5)<<endl;
//    linkedListMap->remove(5);
//    cout<<linkedListMap->get(5)<<endl;
//    cout<<linkedListMap->toString()<<endl;
//    cout<<linkedListMap->toString()<<endl;
//    auto *linkedListMap = new LinkedListMap<int,int>();
//    linkedListMap->add(1,10);
//    string *test = new string;
//    test->append("test");
//    cout<<*test<<endl;
//    cout<<linkedListMap->toString()<<endl;
//    std::map<int,string> *myMap = new std::map<int,string>();
//    myMap->insert(pair < int,string > (1,"Jim"));
//    myMap->size();
//    auto *linkedListMap = new LinkedListMap<int,std::string>();
//    for (int i = 0; i < 1000; i++) {
//        linkedListMap->add(i,std::to_string(1000+i));
//    }
//    for (int i = 0; i < 1001; i++) {
//        if (linkedListMap->contains(i)){
//            cout<<i<<":"<<linkedListMap->get(i)<<endl;
//        } else{
//            cout<<"key:["<<i<<"] illegal!"<<endl;
//        }
//    }
//    for (int i = 1000; i > 980 ; i--) {
//        if (linkedListMap->contains(i)) {
//            linkedListMap->remove(i);
//        }
//    }
//    for (int i = 0; i < 1001; i++) {
//        if (linkedListMap->contains(i)){
//            cout<<i<<":"<<linkedListMap->get(i)<<endl;
//        } else{
//            cout<<"key:["<<i<<"] illegal!"<<endl;
//        }
//    }
////    linkedListMap->get(1);
//    return 0;
    std::cout << "pride-and-prejudice.txt" << std::endl;
    string filename = "../pride-and-prejudice.txt";
    LinkedListMap<string, int> *linkedListMap = new LinkedListMap<string, int>();
    vector<string> words;
    if (FileOps::readFile(filename, words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words) {
            if (linkedListMap->contains(word)) {
                linkedListMap->set(word, linkedListMap->get(word) + 1);
            } else {
                linkedListMap->add(word, 1);
            }
        }
        std::cout << "Total different words: " << linkedListMap->getSize() << std::endl;
        std::cout << "Frequency of PRIDE: " << linkedListMap->get("pride") << std::endl;
        std::cout << "Frequency of PREJUDICE: " << linkedListMap->get("prejudice") << std::endl;
    }
    return 0;
}
