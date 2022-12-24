#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i<m && j<n){
            if(nums2[j]<nums1[i]){
                //removing empty 0
                nums1.pop_back();
                nums1.insert(nums1.begin()+i, nums2[j++]);
                //size would also increase while inserting element
                m++;
            }
            i++;
        }
        while(j<n){
            nums1.pop_back();
            nums1.insert(nums1.begin()+i, nums2[j++]);
            i++;
       }
    }
};

int main(){

 return 0;
}