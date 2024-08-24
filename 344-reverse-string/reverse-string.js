/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
 
class Stack {
    constructor() {
        this.items = [];
    }

    // Push an element onto the stack
    push(element) {
        this.items.push(element);
    }

    // Pop an element off the stack
    pop() {
        if (this.isEmpty()) {
            return "Stack is empty";
        }
        return this.items.pop();
    }

    // Peek at the top element of the stack
    peek() {
        if (this.isEmpty()) {
            return "Stack is empty";
        }
        return this.items[this.items.length - 1];
    }

    // Check if the stack is empty
    isEmpty() {
        return this.items.length === 0;
    }

    // Get the size of the stack
    size() {
        return this.items.length;
    }

    // Clear the stack
    clear() {
        this.items = [];
    }

    // Print the stack (for debugging purposes)
    printStack() {
        console.log(this.items.toString());
    }
};

var reverseString = function(s) {
    var ans = s; 
   var st = new Stack(); 

    for (let i =0 ;i<s.length;i++ ){
        st.push(s[i]);
    }

    let i=0 ;
    while (!st.isEmpty()){
        ans [i++] = st.peek() ; 
        st.pop();
    }

    return ans;


};