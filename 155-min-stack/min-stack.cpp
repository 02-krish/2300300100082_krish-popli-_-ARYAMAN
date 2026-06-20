class MinStack {
 
public:
     stack<long long> st;
    long long mini;
    MinStack() {
        // Nothing to initialize
    }
    
    void push(int value) {
        
        // First element
        if(st.empty()) {
            mini = value;
            st.push(value);
            return;
        }

        // Normal value
        if(value >= mini) {
            st.push(value);
        }
        else {
            /*
                New minimum found.

                Store encoded value:
                encoded = 2*value - mini

                Example:
                mini = 5
                value = 2

                encoded = 2*2 - 5 = -1

                Push -1 and update minimum.
            */
            st.push(2LL * value - mini);
            mini = value;
        }
    }
    
    void pop() {

        long long topElement = st.top();
        st.pop();

        /*
            If topElement < mini
            => it is an encoded value.

            Recover previous minimum:

            previousMin = 2*mini - encoded
        */
        if(topElement < mini) {
            mini = 2 * mini - topElement;
        }
    }
    
    int top() {

        long long topElement = st.top();

        /*
            Encoded value detected.

            Actual top element is current minimum.
        */
        if(topElement < mini)
            return mini;

        return topElement;
    }
    
    int getMin() {
        return mini;
    }
};