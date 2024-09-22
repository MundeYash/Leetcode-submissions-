/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    // finding peak element 
    int peakElement(MountainArray arr , int target ){
        int n = arr.length();
        int s=0 , e=n-1 ; 
        while (s<e ){
            int mid = (s+ (e-s)/2); 
            if (arr.get(mid)<arr.get(mid+1)){
                s = mid + 1; 
            }
            else{
                e = mid ;
            }
        }
        return s ;
    }
    

    // first occur ; 
    int firstOccurInc(MountainArray arr , int target,int s,int e ){
        
        int ans =-1 ;
        while (s<=e ){
            int mid = (s+ (e-s)/2); 
            if (  arr.get(mid)== target ){
                ans = mid ; 
                // check in left 
                e = mid -1 ;
            }
            else if (arr.get(mid) >target ){
                e=mid-1 ;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
    int firstOccurDec(MountainArray arr , int target,int s,int e ){
        
        int ans =-1 ;
        while (s<=e ){
            int mid = (s+ (e-s)/2); 
            if (  arr.get(mid)== target ){
                ans = mid ; 
                // check in left 
                e = mid -1 ;
            }
            else if (arr.get(mid) >target ){
                s = mid + 1;
                
            }
            else{
                e=mid-1 ;
            }
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        // mountain array find 
        int n = arr.length();
        int pvt = peakElement(arr,target);
        cout<<pvt;
        int left = firstOccurInc(arr , target ,0, pvt); 
        cout<<left ;
        int right = firstOccurDec(arr , target , pvt+1 , n-1);
        cout<<right ;
        if (left!=- 1)return left ; 
        else if (left ==-1 && right !=-1 )return right ; 
        else return -1 ;

    }
};