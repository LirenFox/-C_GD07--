#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n;
    long long int sum=0;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());//由小到大排序
    vector<int> num1,num2;
    //找到第一個不是零的數 push_back後刪除
    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            num1.push_back(arr[i]);
            num2.push_back(arr[i+1]);
            arr.erase(arr.begin()+i, arr.begin()+i+2);
            break;
        }
    }
    //一次將最小的兩個數分別放入num1 和num2
    for(int i=0; i<n-2; i+=2){
        num1.push_back(arr[i]);
        if(i+1<n-2)
            num2.push_back(arr[i+1]);
    }
	//算出num1 + num2
    for(int i=0; i<num1.size(); i++)
        sum+=(long long int)num1[i]*pow(10, num1.size()-i-1);
    for(int i=0; i<num2.size(); i++)
        sum+=(long long int)num2[i]*pow(10, num2.size()-i-1);
    cout << sum <<endl;
    return 0;
}
