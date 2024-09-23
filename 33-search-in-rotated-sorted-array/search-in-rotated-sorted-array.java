class Solution {
    public int bs(int[]nums  , int target,int start ,int end ){
    
        while (start<=end){
            int mid = (start +end)/2;
            if (nums[mid]== target ){
                return mid ;
            }
            else if (nums[mid] <target ){
               start = mid + 1; 
            }
            else{
                end = mid-1 ;
            }
        }
        return -1;
    }
    
    public int pivot(int[] nums ){
        // binary search 
        int n = nums.length; 
        int start=0 , end=n-1 ; 
        while (start<end){
                        int mid = (start +end)/2;
            if (nums[mid]>= nums[0]){
               start = mid + 1; 
            }
            else{
                end = mid ;
            }
        }
        return start;
    }
    public int search(int[] nums, int target) {
        
        
        int n = nums.length;
        if (n==1 ){
            if (nums[0]== target )return 0 ;
            else return -1;
        }
        // make the portion of search by finding the pivot index and apply the binary search algo 
        int pvt = pivot(nums  );
      System.out.println(pvt);
        if (target>=nums[0] && target<= nums[pvt-1] ){
            return bs(nums,target,0,pvt-1);
        }
        else if (target>=nums[pvt] && target<=nums[n-1])
        {
            return bs(nums,target,pvt,n-1);
        }
        else
        {
            return -1 ;
        }

    }
}