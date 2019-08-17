#include <iostream>
#include <cmath>
#include <algorithm> 
#include <vector>
#include <tuple>
#include <set>
#include <iomanip>
using namespace std;

template <typename vec>
void print_T(const vec &T) {
    for (int i = 0; i < T.size(); ++i) {
        for (int j = 0; j < T[i].size(); ++j) {
            std::cout << T[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}

void print_D(set<int> &set) {
    for (int const& i : set){
        cout << i << ' ';
    }
    cout << endl;
}

void print_A(vector<float> &T) {
    for (int i = 0; i < T.size(); ++i) {
        std::cout << T[i] << ", ";
    }
    std::cout << std::endl;

}
int main(){
    int n = 0;

    vector<float> yes;
    cin >> n;
    yes.reserve(n);

    int k = 0;

    cin >> k;
    float input = 0.0;

    for(int i = 0; i < n; i++) {
        cin >> input;
        yes.push_back(input);
    }

    sort(yes.begin(), yes.end());
    int r = (n*(n-1))/2;

    int rows = 3;
    double matrix[rows][r];

    int count = 0;
    float maximum = 0.0;
    int posi = 0, posj = 0, col_in_matrix = 0;
    vector<vector<int>> index;

    for(int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i != j){
                matrix[0][count] = (1.0 - yes[i])*(1.0 - yes[j]);
                matrix[1][count] = yes[i] + yes[j] - (2.0 * yes[i] * yes[j]);
                matrix[2][count] = yes[i] * yes[j];
                vector <int> pos;
                pos.push_back(i);
                pos.push_back(j);

                index.push_back(pos);
                if (maximum<matrix[1][count]) {
                    maximum = matrix[1][count];
                    posi = i;
                    posj = j;
                    col_in_matrix = count;
                }
                count = count + 1;
            }
        }
    }



    set<int> combination;
    combination.insert(posi);
    combination.insert(posj);
    vector<float> oldarray(k + 1);
    oldarray[0] = (matrix[0][col_in_matrix]);
    oldarray[1] = (matrix[1][col_in_matrix]);
    oldarray[2] = (matrix[2][col_in_matrix]);
    vector<float> oldarray_new_version (k + 1);
    int target = k/2;
    int current_k = 2;



    while (combination.size() != k) {
        float value = 0.0;
        float compare = 0.0;
        for (int i = 0; i < index.size(); ++i) {
            int index_i = index[i][0];
            int index_j = index[i][1];
            if ((find(combination.begin(), combination.end(), index_i) == combination.end()) &&
                (find(combination.begin(), combination.end(), index_j) == combination.end())) {
                int first = (current_k + 2)/2;
                int second = first - 1;
                int third = second - 1;
                compare =   oldarray[first] * matrix[0][i] +
                            oldarray[second] * matrix[1][i] +
                            oldarray[third] * matrix[2][i];
                if (compare > value) {
                    value = compare;
                    posi = index_i;
                    posj = index_j;
                    col_in_matrix = i;
                }
            }
        }
        combination.insert(posi);
        combination.insert(posj);

        oldarray_new_version[0] = oldarray[0] * matrix[0][col_in_matrix];
        oldarray_new_version[1] = oldarray[1] * matrix[0][col_in_matrix] + oldarray[0] * matrix[1][col_in_matrix];
        for (int i = 2; i < oldarray.size(); ++i) {
            oldarray_new_version[i] =   oldarray[i] * matrix[0][col_in_matrix] +
                                        oldarray[i - 1] * matrix[1][col_in_matrix] +
                                        oldarray[i - 2] * matrix[2][col_in_matrix];
        }

        oldarray_new_version[current_k + 1] = oldarray[current_k - 1] * matrix[2][col_in_matrix] +
                                              oldarray[current_k] * matrix[1][col_in_matrix];
        oldarray_new_version[current_k + 2] = oldarray[current_k] * matrix[2][col_in_matrix];

        current_k += 2;
        oldarray.swap(oldarray_new_version);
    }

    cout << setprecision(3) << oldarray[target] <<endl;
            
}

