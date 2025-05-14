class Solution {
public:
    string addBinary(string a, string b) {
        int pointerA = a.size() - 1;
        int pointerB = b.size() - 1;
        int carry = 0;
        string result = "";

        while (pointerA >= 0 || pointerB >= 0 || carry != 0) {
            int sum = carry;

            if (pointerA >= 0) {
                sum += a[pointerA] - '0';
                pointerA--;
            }

            if (pointerB >= 0) {
                sum += b[pointerB] - '0';
                pointerB--;
            }

            carry = sum / 2;
            result.push_back((sum % 2) + '0');
        }

        // Reverse the result
        int left = 0;
        int right = result.size() - 1;
        while (left < right) {
            char temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        }

        return result;
    }
};