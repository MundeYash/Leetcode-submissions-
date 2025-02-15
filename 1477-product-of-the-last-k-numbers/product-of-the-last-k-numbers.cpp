class ProductOfNumbers {
public:
    vector<int>productValue ;
    ProductOfNumbers() {
        // step 1 : while initialization of values push it 1
        productValue.push_back(1);
        
    }
    
    void add(int num) {
        if (num ==0 ){
            productValue.clear(); 
            productValue.push_back(1);

        }
        else{
            productValue.push_back(productValue.back()* num);
        }
        
    }
    
    int getProduct(int k) {
        int n = productValue.size();
        if (k>=n)return 0;
        int ans = (productValue.back()/productValue[n-k-1]);
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */