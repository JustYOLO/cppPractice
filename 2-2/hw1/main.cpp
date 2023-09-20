#include <iostream>
#include <string>
#include "DLinkedList.cpp" // 이중 링크드 리스트의 클래스를 담고있는 데이터
using std::cout, std::cin, std::string, std::endl;

template <class T>
void printAll(DLinkedList<T>& list);
// 이중 링크드 리스트의 모든 노드를 출력하는 함수

int main()
{
    DLinkedList<char> cList;
    // char의 데이터를 다루는 이중 링크드 리스트 생성
    DLinkedList<string> sList;
    // string의 데이터를 다루는 이중 링크드 리스트 생성
    DLinkedList<int> iList;
    // int의 데이터를 다루는 이중 링크드 리스트 생성

    string testCase[] = {"apple", "bleach", "cat", "data", "electron", "fan", "guns", "hex", "iridium", "jacket"};
    // string의 데이터를 다루는 sList에 넣을 테스트 데이터

    for(int i = 0; i < 10; i++) // 테스트 데이터 추가
    {
        cList.addBack((char) (97 + i));
        // 소문자 a부터 j까지 리스트에 추가
        sList.addBack(testCase[i]);
        // testCase의 데이터를 리스트에 추가
        iList.addBack(i);
        // 0부터 9까지 데이터를 리스트에 추가
    }
    cout << cList.front() << ", " << cList.back() << endl;
    cout << sList.front() << ", " << sList.back() << endl;
    cout << iList.front() << ", " << iList.back() << endl;
    // 각 리스트의 앞과 끝 데이터를 확인

    cList.removeFront(); cList.removeBack();
    sList.removeFront(); sList.removeBack();
    iList.removeFront(); iList.removeBack();
    // 각 리스트의 앞과 끝 노드를 삭제

    cList.addFront('A'); cList.addBack('J');
    sList.addFront("amplifier"); sList.addBack("jack");
    iList.addFront(11); iList.addBack(99);
    // 각 리스트의 앞과 끝에 새로운 노드를 추가

    cout << cList.front() << ", " << cList.back() << endl;
    cout << sList.front() << ", " << sList.back() << endl;
    cout << iList.front() << ", " << iList.back() << endl;
    // 새로운 노드를 확인

    printAll(cList);
    printAll(sList);
    printAll(iList);
    // 모든 노드를 출력

    return 0;
}

template <class T>
void printAll(DLinkedList<T>& list)
{ // 리스트의 모든데이터를 출력하는 함수
    while(!list.empty())
    { // 리스트가 비어있을때 까지
        cout << list.front() << ", "; // front 원소를 출력
        list.removeFront(); // 출력한 원소를 리스트에서 제거
    }
    cout << endl; // 리스트의 모든 원소가 출력되면 줄바꿈
}