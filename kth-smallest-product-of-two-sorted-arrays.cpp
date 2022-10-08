//https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
//----------------------------------------------------------------------------------//

class Solution {
public:
    bool check(long long midval,vector<int>& nums1, vector<int>& nums2, long long k){
        long long cnt=0;
        for(int i=0;i<nums1.size();i++)
        {
            long long val=nums1[i];
                        
			//If val == 0, product of val and each element in nums2 will be 0. And if midval>=0, then because all
			//products are 0, all products will be smaller or equal to midval. So we can add all products in the answer
			if(val==0 and midval>=0)
                cnt+=nums2.size();
            
            else if(val>0)
                cnt+=findmaxIndex(nums2,val,midval);
            
            else if(val<0)
                cnt+=findminIndex(nums2,val,midval);
        }
        return cnt>=k;
    }
    
    int findmaxIndex(vector<int>&nums2 , long long  val , long long midval)
    {
        int l = 0  , r = nums2.size()-1 , res=  -1;
        while(l<=r)
        {
            long long mid = (l+r)/2;
            if(val*nums2[mid]<=midval)
            {
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return res+1;
    }
    
    int findminIndex(vector<int>&nums2 , long long  val , long long midval)
    {
        int l = 0  , r = nums2.size()-1 , res=  r+1;
        while(l<=r)
        {
            long long mid = (l+r)/2;
            if(val*nums2[mid]<=midval)
            {
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return nums2.size()-res;
    }
    
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l=-1e10,r=1e10,res=-1;
        while(l<=r){
            long long mid = (l+r)/2;
            // cout<<mid<<endl;
            if(check(mid,nums1,nums2,k)) {
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};

//----------------------------------------------------------------------------------------//
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
    }
};
   
