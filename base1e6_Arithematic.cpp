// legacy code now !! .. already switched to base 10^9


// Work Under Progress ...



#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int64_t> add_vector_base6(const vector<int64_t> &num1, const vector<int64_t> &num2) {
    vector<int64_t> result_num;

    const vector<int64_t> *bigger;
    const vector<int64_t> *smaller;

    int size_num1 = num1.size();
    int size_num2 = num2.size();

    int size1, size2;

    if (size_num1 >= size_num2) {
        size1 = size_num2;
        size2 = size_num1;
        bigger = &num1;
        smaller = &num2;
    } else {
        size1 = size_num1;
        size2 = size_num2;
        bigger = &num2;
        smaller = &num1;
    }

    int64_t carry = 0;

    for (int i = 0; i < size1; i++) {
        int64_t sum = (*bigger)[i] + (*smaller)[i] + carry;
        if (sum >= 1000000) {
            carry = 1;
            sum %= 1000000;
        } else {
            carry = 0;
        }
        result_num.push_back(sum);
    }

    for (int i = size1; i < size2; i++) {
        int64_t sum = (*bigger)[i] + carry;
        if (sum >= 1000000) {
            carry = 1;
            sum -= 1000000;
        } else {
            carry = 0;
        }
        result_num.push_back(sum);
    }

    if (carry > 0) {
        result_num.push_back(1);
    }

    return result_num;
}

vector<int64_t> vector_product_base6(const vector<int64_t> &num1, const vector<int64_t> &num2) {
    vector<int64_t> result;

    for (int i = 0; i < num2.size(); i++) {
        vector<int64_t> num(i, 0); // Add i zeros

        int64_t carry = 0;
        for (int j = 0; j < num1.size(); j++) {
            int64_t product = num2[i] * num1[j] + carry;

            if (product >= 1000000) {
                carry = product / 1000000;
                product %= 1000000;
            } else {
                carry = 0;
            }
            num.push_back(product);
        }

        if (carry > 0) {
            num.push_back(carry);
        }

        result = add_vector_base6(result, num);
    }

    return result;
}

string base6_vector_to_str(const vector<int64_t> &num) {
    string result = to_string(num.back());

    for (int i = num.size() - 2; i >= 0; --i) {
        string digits = to_string(num[i]);
        while (digits.size() < 6) {
            digits = "0" + digits;
        }
        result += digits;
    }

    return result;
}

string factorial(int num) {
    vector<int64_t> result = {1};
    vector<int64_t> count = {1};

    for (int i = 1; i <= num; ++i) {
        result = vector_product_base6(result, count);
        count = add_vector_base6(count, {1});
    }

    return base6_vector_to_str(result);
}

int main() {
    int x = 10000;

    auto start = high_resolution_clock::now();
    string result = factorial (x) ;
    cout << result << endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "\nTime taken: " << duration.count() << " milliseconds" << endl;

    cout << "Total Digits : " << result.size() ;
    return 0;
}
