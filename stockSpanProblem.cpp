// 60 10  20  40  35  30  50  70  65  
// //////  if there is a greater element on the left side 
// span = (index of current element) - (index of closest greater element on left side)
// /////// if there is no greater element on the left i.e. the current element is the max element so far
// then in that case
// span = index of curr element + 1


class Solution
{
    public:
    //Function to calculate the span of stocks price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<int> s;
        s.push(0);
        vector <int>  ans(n);
        
        //span value of first day is always 1. 
        ans[0] =1;
        
        for(int i=1;i<n;i++)
        {
            //we pop elements from the stack till price at top of stack 
            //is less than or equal to current price.
            while(s.empty()==false and price[s.top()] <= price[i])
                s.pop();
            
            //if stack becomes empty, then price[i] is greater than all 
            //elements on left of it in list so span is i+1.
            //Else price[i] is greater than elements after value at top of stack.
            int span = (s.empty()) ? (i+1) : (i-s.top());
            ans[i] = span;
            
            //pushing this element to stack.
            s.push(i);
        }
        //returning the list.
        return ans;
    }   
};