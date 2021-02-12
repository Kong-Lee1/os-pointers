#include <iostream>
#include <thread>

//to compile --> g++ -o threads threads.cpp -lpthread

int sumIntArray(int *array, int start_int, int stop_int);

int main(int argc, char argv){

    int *shared_array = new int[10000];

    int i;
    for(i = 0; i < 10000; i++){

        shared_array[i] = 2;
    }
    
    int t1_sum;
    std::thread t1 = std::thread(sumIntArray, shared_array, 0, 5000, &t1_sum);
    int main_sum;//sum the second half of the array
    sumIntArray(shared_array, 5000, 10000, &main_sum);

    //need to wait for t1 to finish
    t1.join();

    //combine the sums
    int total_sum = t1_sum + main_sum;

    std::cout << "sum of values in array: " << total_sum << std::endl;

    return 0;
}

void sumIntArray(int *array, int start_idx, int stop_idx, int *result)
{

    int i;
    int sum = 0;

    for(i = start_idx; 1 < stop_idx; i++){
        sum += array[i];
    }

    *result = sum;
}