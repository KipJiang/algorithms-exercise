#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_array(vector<T>& array)
{
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}

// 整数或浮点数皆可使用，若要使用类(class)或结构体(struct)时必须重载大于(>)运算符
template <typename T>
void bubble_sort(vector<T>& array)
{
    int i, j;
    for (i = 0; i < array.size()-1; i++)
        for (j = 0; j < array.size()-1 - i; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}


template <typename T>
void selection_sort(vector<T>& array)
{
    for (int i = 0; i < array.size(); i++) {
        int min_index = i;
        for (int j = i+1; j < array.size(); j++) {
            if (array[j] < array[min_index])
                min_index = j;
        }
        if (min_index != i)
            swap(array[i], array[min_index]);
    }
}


template <typename T>
void insertion_sort(vector<T>& array)
{
    for (int i = 0; i < array.size()-1; i++) {
        int flag = i+1;
        int counter = i;
        while (counter >= 0) {
            if (array[flag] < array[counter]) {
                swap(array[counter], array[flag]);
                flag = counter;
            }
            counter--;
        }
    }
}


/* shell sort version 1 */
template <typename T>
void shell_sort(vector<T>& array)
{
    for (int gap = array.size() >> 1; gap > 0; gap >>= 1)
        for (int i = gap; i < array.size(); i++)
            for (int j = i-gap; j >= 0 && array[j] > array[j+gap]; j -= gap)
                swap(array[j+gap], array[j]);
}


/* shell sort version 2 */
// template <typename T>
// void shell_sort(vector<T>& array)
// {
//     for (int gap = array.size() >> 1; gap > 0; gap >>= 1)
//         for (int i = gap; i < array.size(); i++) {
//             int j;
//             T temp = array[i];
//             for (j = i-gap; j >=0 && array[j] > temp; j -= gap)
//                 array[j+gap] = array[j];
//             array[j+gap] = temp;
//         }
// }


template <typename T>
void merge(vector<T>& left, vector<T>& right)
{
    vector<T> res;
    
}


template <typename T>
void merge_sort(vector<T>& array)
{
    vector<T> left, right;
    int middle = array.size() / 2;
    
}


template <typename T>
void quick_sort(vector<T>& array)
{}


template <typename T>
void heapify_sort(vector<T>& array)
{}


template <typename T>
void counting_sort(vector<T>& array)
{}


template <typename T>
void bucket_sort(vector<T>& array)
{}


template <typename T>
void radix_sort(vector<T>& array)
{}


int main(int argc, char *argv[]) {
    vector<int> arr = {61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62};
    vector<float> arrf = {
        17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 
        19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4
        };
    
    if (argc == 2) {
        cout << "Before: \n" << "[ int ] ";
        print_array(arr);
        cout << "[float] ";
        print_array(arrf);

        switch (*argv[1] - '0')
        {
        case 1:
            cout << "bubble sort" << endl;
            bubble_sort(arr);
            bubble_sort(arrf);
            break;
        case 2:
            cout << "selection sort" << endl;
            selection_sort(arr);
            selection_sort(arrf);
            break;
        case 3:
            cout << "insertion sort" << endl;
            insertion_sort(arr);
            insertion_sort(arrf);
            break;
        case 4:
            cout << "shell sort" << endl;
            shell_sort(arr);
            shell_sort(arrf);
            break;
        case 5:
            cout << "merge sort" << endl;
            merge_sort(arr);
            merge_sort(arrf);
            break;
        case 6:
            cout << "quick sort" << endl;
            quick_sort(arr);
            quick_sort(arrf);
        case 7:
            cout << "heapipy sort" << endl;
            heapify_sort(arr);
            heapify_sort(arrf);
            break;
        case 8:
            cout << "counting sort" << endl;
            counting_sort(arr);
            counting_sort(arrf);
            break;
        case 9:
            cout << "bucket sort" << endl;
            bucket_sort(arr);
            bucket_sort(arrf);
            break;
        case 10:
            cout << "radix sort" << endl;
            radix_sort(arr);
            radix_sort(arrf);
            break;
        default:
            cout << "argv: " << argv[1] << endl;
            cout << "The algo does not choose." << endl;
            break;
        }

        cout << "After: \n" << "[ int ] ";
        print_array(arr);
        cout << "[float] ";
        print_array(arrf);

    } else {
        cout << "Choose a algorithm." << endl;
        return -1;
    }
    
    return 0;
}