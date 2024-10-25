/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  // brute force approach 
  var maxi  =0 ;
  let n = prices.length ; 
  var minPrice = Number.MAX_SAFE_INTEGER;
  for (let i=0 ;i<n  ;i++ ){
    
            minPrice = Math.min(minPrice, prices[i]);
            maxi = Math.max(maxi , (prices[i]-minPrice));
        
    }
  
  return maxi ;

};