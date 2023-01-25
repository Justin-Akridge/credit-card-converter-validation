#include <iostream>
#include <string>

using namespace std;

int get_digit(int number){
    if (number <= 9){
        return number;
    }
    return number / 10 + number % 10;
}

int get_size(long d) {
    string num = to_string(d);
    return num.length();
}

long get_prefix(long number, int k){
    if (get_size(number) > k) {
        string num = to_string(number);
        return stol(num.substr(0, k));   
    }
    return number;
}

bool prefix_matched(long number, int d){
   return get_prefix(number, get_size(d)) == d;
} 

int sum_of_double_even_place(long int number) {
    int sum = 0;
    string num = to_string(number);
    for (int i = get_size(number) - 2; i >= 0; i -= 2){
        sum += get_digit(int(num[i] - '0') * 2);
    }
    return sum;
}

int sum_of_odd_place(long number) {
    int sum = 0;
    string num = to_string(number);
    for (int i = get_size(number) - 1; i >= 0; i -= 2) { 
        sum += num[i] - '0';
    }
    return sum;
}

bool is_valid(long int number) {
    return (get_size(number) >= 13 &&
            get_size(number) <= 16) &&
            (prefix_matched(number, 4) ||
            prefix_matched(number, 5) ||
            prefix_matched(number, 37) ||
            prefix_matched(number, 6)) &&
            ((sum_of_double_even_place(number) +
            sum_of_odd_place(number)) % 10 == 0);
}

int main() {
    long int number = 51960818885000645L; 
    cout << number << " is " << (is_valid(number) ? "Valid" : "invalid") << '\n';
    return 0;
}

