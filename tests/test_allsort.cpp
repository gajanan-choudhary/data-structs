#include "doctest.h"
#include "allsort.h"
#include <chrono>
/******************************************************************************/
#include <random>     // mt19937 and uniform_int_distribution
#include <algorithm>  // generate
#include <vector>     // vector
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind
#include <iostream>   // cout
std::vector<int> create_random_data(int n) {
  std::random_device r;
  std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
  std::mt19937       eng(seed); // a source of random data

  std::uniform_int_distribution<int> dist;
  std::vector<int> v(n);

  generate(begin(v), end(v), bind(dist, eng));
  return v;
}
/******************************************************************************/

using namespace std;

template <typename T, typename S, typename R>
void sorttemplate(T &v, const int &nelems, const int &sorter, std::string &type, S &start1, S &stop1, R &duration1){
    //for (const auto &i : v) cout << i << ' ';
    //cout << endl;
    auto mysort = bubblesort<T>;
    mysort=nullptr;
    switch (sorter){
        case (0):
            type = "Bubble";
            mysort = bubblesort<T>;
            break;
        case (1):
            type = "Insert";
            mysort = insertsort<T>;
            break;
        case (2):
            type = "Select";
            mysort = selectsort<T>;
            break;
        case (3):
            type = "Quick ";
            mysort = quicksort<T>;
            break;
        default:
            throw std::runtime_error("Sort function type does not exist");
            break;
    }

    start1 = chrono::high_resolution_clock::now();
    mysort(v, 0, nelems);
    stop1 = chrono::high_resolution_clock::now();
    duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);

    //for (const auto &i : v) cout << i << ' ';
    //cout << endl;
    cout << type << " sort (nelems = " << nelems << ") timing  : " << duration1.count() << "µs" << endl;
}

/******************************************************************************/
TEST_CASE("Sort vector<int>") {
    int NELEMS[2] = {1118, 1119};
    for (const auto &nelems : NELEMS){
        std::cout << std::endl;
        auto random_data = create_random_data(nelems);
        auto sorted_data = random_data;
        auto oppsorted_data = random_data;
        std::sort(oppsorted_data.begin(), oppsorted_data.end(),std::greater<int>());

        auto start = chrono::high_resolution_clock::now();
        std::sort(sorted_data.begin(), sorted_data.end());
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "std::sort   (nelems = " << nelems << ") timing   : " << duration.count() << "µs" << endl;

        std::string type;
        auto start1 = start;
        auto stop1 = stop;
        auto duration1 = duration;

        std::cout << "Sorting random data" << std::endl;
        for (const auto &sorter : {0, 1, 2, 3}){
            std::vector<int> *v = new std::vector<int>(random_data);
            sorttemplate(*v, nelems, sorter, type, start1, stop1, duration1);
            for(int i=0; i<nelems; i++){
                CHECK((*v)[i] == sorted_data[i]);
            }
            delete v;
        }
        std::cout << "Sorting already sorted data" << std::endl;
        for (const auto &sorter : {0, 1, 2, 3}){
            std::vector<int> *v = new std::vector<int>(sorted_data);
            sorttemplate(*v, nelems, sorter, type, start1, stop1, duration1);
            for(int i=0; i<nelems; i++){
                CHECK((*v)[i] == sorted_data[i]);
            }
            delete v;
        }
        std::cout << "Sorting oppositely sorted data" << std::endl;
        for (const auto &sorter : {0, 1, 2, 3}){
            std::vector<int> *v = new std::vector<int>(oppsorted_data);
            sorttemplate(*v, nelems, sorter, type, start1, stop1, duration1);
            for(int i=0; i<nelems; i++){
                CHECK((*v)[i] == sorted_data[i]);
            }
            delete v;
        }

    }
}

