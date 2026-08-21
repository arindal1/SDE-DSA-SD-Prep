            int sumSubarrayMins(vector<int>& arr) {
                vector<int> nse = nextSmaller(arr);
                vector<int> pse = prevSmaller(arr);
                int n = arr.size();
                long long tot = 0;
                const int MOD = 1'000'000'007;

                for (int i = 0; i < n; i++) {
                    long long left  = i - pse[i];
                    long long right = nse[i] - i;
                    long long contrib = (left * right) % MOD;

                    contrib = (contrib * (arr[i] % MOD)) % MOD;
                    tot += contrib;
                    if (tot >= MOD)
                        tot -= MOD;
                }
                return (int)tot;
            }

            vector<int> nextSmaller(vector<int>& arr) {
                stack<int> st;
                int n = arr.size();
                vector<int> ans(n);
                for (int i = n - 1; i >= 0; i--) {
                    while (!st.empty() && arr[st.top()] > arr[i]) {
                        st.pop();
                    }
                    ans[i] = st.empty() ? n : st.top();
                    st.push(i);
                }
                return ans;
            }

            vector<int> prevSmaller(vector<int>& arr) {
                stack<int> st;
                int n = arr.size();
                vector<int> ans(n);
                for (int i = 0; i < n; i++) {
                    while (!st.empty() && arr[st.top()] >= arr[i]) {
                        st.pop();
                    }
                    ans[i] = st.empty() ? -1 : st.top();
                    st.push(i);
                }
                return ans;
            }
