//https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
class Solution {
public:
   long countNoOfElements(vector<int>&nums1, vector<int>&nums2, long dotProduct){
//      
        long count = 0;
        for(int ele : nums1){
            if(ele >= 0){
                int li = 0, ri = nums2.size();
                while(li < ri){
                    int mid = (li + ri) / 2;
                    if((long) ele * nums2[mid] < dotProduct) li = mid + 1;
                    else ri = mid;
                }
                
                count += li;
            }else{
                int li = 0, ri = nums2.size();
                while(li < ri){
                    int mid = (li + ri) / 2;
                    if((long) ele * nums2[mid] >= dotProduct) li = mid + 1;
                    else ri = mid ;
                }
                
                count += nums2.size() - ri;
            }
        }
        
        return count;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
         long lb = (long) -1e10, rb = (long) 1e10;
        
        while(lb <= rb){
            long dotProduct = (lb + rb) / 2;
            if(countNoOfElements(nums1,nums2,dotProduct) < k)
                lb = dotProduct + 1;
            else 
                rb = dotProduct - 1;
            cout<<dotProduct<<" ";
        }
        
        return rb;
//      
    }
};
   