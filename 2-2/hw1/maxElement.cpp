#include <iostream>
#include <climits>
using std::cout, std::endl;

int maxElement(int *arr, int size, int idx = 0, int max = INT_MIN);
// recursive하게 int array의 원소의 최대값을 찾는 함수
/*
arr는 찾는 대상, size는 배열의 크기, idx는 현재 조사하는 배열의 인덱스, 
max는 원소의 최댓값을 저장하는 변수
max가 최대값을 가지게 하기 위해 초기값을 int형 변수가 가질수 있는 최소 값(climits의
INT_MIN)으로 초기화
*/ 

int main()
{
    int arr[5] = {1, 2, 4, 5, 6}; // 테스트 케이스
    cout << maxElement(arr, 5) << endl; 

    return 0;
}

int maxElement(int *arr, int size, int idx, int max)
{
    if(size <= idx) // 인덱스가 배열의 사이즈보다 크거나 같아질 경우 -> 모든 원소를 확인 한 경우  
        return max;
    else
    { // 아직 확인할 원소가 남은 경우
        if(*(arr + idx) > max) // 배열의 해당 원소의 값을 확인해서 최댓값 보다 클 경우
            max = *(arr + idx);  // 새로운 최대값을 저장
    }
    return maxElement(arr, size, ++idx, max); // 모든 원소를 확인할때까지 recursive
}
