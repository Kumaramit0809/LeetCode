class Solution 
{
public:
    std::vector<int> findEvenNumbers(std::vector<int>& digits) 
    {
        std::set<int> set;

        // Step 1: Try all 3-digit combinations
        for (int i = 0; i < digits.size(); i++) 
        {
            for (int j = 0; j < digits.size(); j++) 
            {
                for (int k = 0; k < digits.size(); k++) 
                {
                    // Step 2: Ensure indices are distinct
                    if (i == j || i == k || j == k)
                    {
                        continue;
                    }

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];

                    // Step 3: Check if valid even number
                    if (digits[i] != 0 && num % 2 == 0)
                    {
                        set.insert(num);
                    }
                }
            }
        }

        // Step 4: Copy to vector and return
        std::vector<int> result(set.begin(), set.end());
        return result;
    }
};