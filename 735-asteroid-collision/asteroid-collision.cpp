class Solution {
public:
   vector<int> asteroidCollision(vector<int>& arr) {

    vector<int> st;

    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] > 0) {
            st.push_back(arr[i]);
        }
        else {

            // Remove all smaller positive asteroids
            while(!st.empty() &&
                  st.back() > 0 &&
                  st.back() < abs(arr[i])) {

                st.pop_back();
            }

            // Equal size => both destroyed
            if(!st.empty() &&
               st.back() == abs(arr[i])) {

                st.pop_back();
            }

            // No collision possible
            else if(st.empty() ||
                    st.back() < 0) {

                st.push_back(arr[i]);
            }

            // If st.back() > abs(arr[i])
            // current negative asteroid gets destroyed
        }
    }

    return st;
}
};