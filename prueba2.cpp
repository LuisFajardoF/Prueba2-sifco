#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <algorithm>
#include <limits.h>
#include <vector>

// PRUEBA 2 - Ejercicio 1
int max_value, min_value;

void set_values()
{
    max_value = 0, min_value = INT_MAX;
}

void max_and_min_value(int *arr, int size)
{
    set_values();
    for ( int i = 0; i < size; i++ ) {
        if ( arr[i] < min_value )
            min_value = arr[i];
        if ( arr[i] > max_value )
            max_value = arr[i];
    }
}

// TEST - Ejercicio 1
TEST_CASE("Testing Max and Min Value Function") 
{
    int arr[] = {25, 12, 33, 90, 9, 88, 46};
    int size = sizeof(arr) / sizeof(int); 
    
    max_and_min_value(arr, size);
    CHECK(max_value == 90);
    CHECK(min_value == 9);

    int other_arr[] = {167, 16, 21, 4, 67, 90, 55, 44};
    size = sizeof(other_arr) / sizeof(int);

    max_and_min_value(other_arr, size);
    CHECK(max_value == 167);
    CHECK(min_value == 4);


    int zeroes_arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size = sizeof(zeroes_arr) / sizeof(int);
    
    max_and_min_value(zeroes_arr, size);
    CHECK(max_value == 0);
    CHECK(min_value == 0);
}

// PRUEBA 2 - Ejercicio 2
void sort_array(int *arr, int size)
{
    int current;
    for ( int i = 1, j; i < size; i++ ) {
        current = arr[i];
        for ( j = i - 1; j >= 0 && arr[j] > current; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = current;
    }
}

// TEST - Ejercicio 2
TEST_CASE("Testing Sort Array Function") 
{
    int arr[] = {25, 12, 33, 90, 9, 88, 46};
    int size = sizeof(arr) / sizeof(int);

    sort_array(arr, size);
    CHECK(arr[0] == 9);    
    CHECK(arr[1] == 12);    
    CHECK(arr[2] == 25);    
    CHECK(arr[3] == 33);    
    CHECK(arr[4] == 46);    
    CHECK(arr[5] == 88);    
    CHECK(arr[6] == 90);    
}

// PRUEBA 2 - Ejercicio 3
std::vector<int> set_representation(std::vector<int> x_vec)
{
    std::vector<int> y_vec;
    std::vector<int>::iterator it;

    for ( auto temp : x_vec) {
        it = std::find(y_vec.begin(), y_vec.end(), temp);
        if ( it == y_vec.end())
            y_vec.emplace_back(temp);
    }

    return y_vec;
}

// TEST - Ejercicio 3
TEST_CASE("Testing Set Representation Function") 
{
    std::vector<int> elements = {67, 12, 33, 78, 33, 40, 45, 12, 90, 54, 45, 2};
    std::vector<int> result;

    result = set_representation(elements);

    CHECK_EQ(result[0], 67);
    CHECK_EQ(result[1], 12);
    CHECK_EQ(result[2], 33);
    CHECK_EQ(result[3], 78);
    CHECK_EQ(result[4], 40);
    CHECK_EQ(result[5], 45);
    CHECK_EQ(result[6], 90);
    CHECK_EQ(result[7], 54);
    CHECK_EQ(result[8], 2);
}