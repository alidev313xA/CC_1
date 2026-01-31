void solve(ll test_case) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // 1. Count frequencies
    vector<int> count(26);   
    for(auto c: s) count[c - 'a']++; 

    // 2. remove the smallest frequency character 
    vector<int> removed(26);

    for (int i = 0; i < 26 && k > 0; i++) {
        int remove = min(k, count[i]); 
        k -= remove; 
        removed[i] = remove; 
    }

    // 3. build the string 
    string ans = ""; 

    for (auto c: s) {
        if (removed[c - 'a'] > 0) removed[c - 'a']--; 
        else ans += c; 
    }

    cout << ans << "\n";
}
