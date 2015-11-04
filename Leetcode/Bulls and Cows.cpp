class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        int h[10] = {0}, f[10] = {0};
        for(int i = 0 ; i < secret.size(); i++) {
            if(secret[i] == guess[i]) A++;
            else {
                h[secret[i] - '0']++;
                f[guess[i] - '0' ]++;
            }
        }
        for(int i = 0; i < 10; i++) B += min(f[i], h[i]);
        ostringstream os;
        os << A << "A" << B << "B";
        return os.str();
    }
};
