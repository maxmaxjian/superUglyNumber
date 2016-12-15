#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// class solution {
//   public:
//     int nthSuperUglyNumber(int n, const std::vector<int> & primes) {
//         std::vector<int> super{1};
//         super = grow(n, primes, super);
//         return super[n-1];
//     }

//   private:
//     std::vector<int> grow(int n, const std::vector<int> & primes, const std::vector<int> & curr) {
//         std::vector<int> result;
//         if (curr.size() >= n)
//             result = curr;
//         else {
//             // auto it = find_if(curr.begin(), curr.end(), [&](int i){return find(curr.begin(), curr.end(), i*primes[0]) == curr.end();});
//             // auto cpy = curr;
//             // std::transform(primes.begin(), primes.end(), std::inserter(cpy, cpy.end()), [&](int i){return i**it;});

            
//             std::sort(cpy.begin(), cpy.end());
//             result = grow(n, primes, cpy);
//         }
//         std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));
//         std::cout << std::endl;
        
//         return result;
//     }
// };

class solution {
  public:
    int nthSuperUglyNumber(int n, const std::vector<int> & primes) {
        std::vector<int> supers;
        int i = 1;
        while (supers.size() < n) {
            if (isSuperUgly(i, primes))
                supers.push_back(i);
            i++;
        }
        std::copy(supers.begin(), supers.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        return supers.back();
    }
    
  private:
    bool isSuperUgly(int num, const std::vector<int> & primes) {
        if (num == 1)
            return true;
        else {
            for (int i = 2; i <= num; i++) {
                if (isPrime(i) && num%i == 0) {
                    if (std::find(primes.begin(), primes.end(), i) != primes.end())
                        return isSuperUgly(num/i, primes);
                    else
                        return false;
                }
            }
        }
    }

    bool isPrime(int num) {
        if (num == 2)
            return true;
        else {
            for (int i = 2; i < num; i++)
                if (num%i == 0)
                    return false;
            return true;
        }
    }
};

int main() {
    std::vector<int> primes{2,7,13,19};
    int n = 12;

    solution soln;
    int nth = soln.nthSuperUglyNumber(n, primes);
    std::cout << "The " << n << "th super ugly number is:\n"
              << nth << std::endl;
}
