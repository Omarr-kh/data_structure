#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

namespace sortlib
{
    // inplace and stable
    template <class T>
    void insertionSort(T data[], int n)
    {
        for (int i = 1, j; i < n; i++)
        {
            // { 5, 7, 6, 1, 4, 3, 9, 8, 2 }
            T temp = data[i];

            for (j = i; j > 0 && temp < data[j - 1]; j--)
                data[j] = data[j - 1];
            data[j] = temp;
        }
    }

    // inplace and stable
    template <class T>
    void selection_sort(T data[], int n)
    {
        T smallest;
        for (int i = 0; i < n - 1; i++)
        {
            smallest = i;
            for (int j = i + 1; j < n; j++)
            {
                if (data[j] < data[smallest])
                    smallest = j;
            }
            std::swap(data[i], data[smallest]);
        }
    }


    template <class T>
    void bubble_sort(T data[], int n)
    {
        // { 5, 7, 6, 1, 4, 3, 9, 8, 2 }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (data[j + 1] < data[j])
                {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }


    // merge sort algoritm
    template <class T>
    void merge(T data[], int l, int middle, int r)
    {
        int nl = middle - l + 1;
        int nr = r - middle;

        T* larray = new T[nl];
        T* rarray = new T[nr];

        for (int i = 0; i < nl; i++)
        {
            larray[i] = data[l + i];
        }

        for (int i = 0; i < nr; i++)
        {
            rarray[i] = data[middle + i + 1];
        }

        int l_index = 0; int r_index = 0; int data_index = l;

        while (l_index < nl && r_index < nr)
        {
            if (larray[l_index] < rarray[r_index])
            {
                data[data_index] = larray[l_index];
                l_index++;
            }
            else
            {
                data[data_index] = rarray[r_index];
                r_index++;
            }
            data_index++;
        }

        while (l_index < nl)
        {
            data[data_index] = larray[l_index];
            l_index++;
            data_index++;
        }

        while (l_index < nl)
        {
            data[data_index] = rarray[r_index];
            r_index++;
            data_index++;
        }
        delete[] larray;
        delete[] rarray;

    }

    template <class T>
    void merge_sort(T data[], int l, int r)
    {
        if (l >= r)
            return;
        else
        {
            int middle = l + ((r - l) / 2);
            merge_sort(data, l, middle);
            merge_sort(data, middle + 1, r);
            merge(data, l, middle, r);
        }
    }


    template <typename T>
    int partition(T data[], int l, int r)
    {
        int pivot = data[l];
        // { 5, 7, 6, 1, 4, 3, 9, 8, 2 }
        int i, j;
        for (j = l + 1, i = l; j <= r; j++)
        {
            if (data[j] < pivot)
            {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[l], data[i]);
        return i;

    }


    template <typename T>
    void quick_sort(T data[], int l, int r)
    {
        if (l >= r)
            return;

        int partition_index = partition(data, l, r);

        quick_sort(data, l, partition_index - 1);
        quick_sort(data, partition_index + 1, r);

    }


    // O(n^1.5)
    template <class T>
    void shell_sort(T data[], int n)
    {
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                T temp = data[i];

                int j;
                for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
                {
                    data[j] = data[j - gap];
                }
                data[j] = temp;
            }
        }
    }


    void countSort(int array[], int size) {
        int output[9];
        int count[10];
        int max = array[0];

        for (int i = 1; i < size; i++) {
            if (array[i] > max)
                max = array[i];
        }

        for (int i = 0; i <= max; ++i) {
            count[i] = 0;
        }

        for (int i = 0; i < size; i++) {
            count[array[i]]++;
        }

        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        for (int i = 0; i < size; i++) {
            array[i] = output[i];
        }
    }

}

int main()
{
    random_device rd;
    uniform_int_distribution<int> dist(1, 500);
    const int size = 1000;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = dist(rd);
    }
    cout << "starting" << endl;
    auto start = chrono::high_resolution_clock::now();
    sortlib::insertionSort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "time taken = " << duration.count() << endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
};


