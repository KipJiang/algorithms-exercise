/**
 * 十大经典排序算法
 * https://www.runoob.com/w3cnote/ten-sorting-algorithm.html
 * 算法复杂度
 * https://www.runoob.com/wp-content/uploads/2019/03/sort.png
 */
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template <typename T>
void print_array(vector<T>& array)
{
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}


/**
 * @brief 冒泡排序
 * 从头到尾，每次比较相邻的两个元素，逆序即做交换；
 * 多次循环换，直到所有元素从小到大有序排列。
 */
template <typename T>
void bubble_sort(vector<T>& array)
{
    int i, j;
    for (i = 0; i < array.size()-1; i++)
        for (j = 0; j < array.size()-1 - i; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}


/**
 * @brief 选择排序
 * 假定一个最小元素（比如首元素），然后依次同其后的元素比较，
 * 每当比这个假定值小时即做交换，从而得到最小元素；循环多次，知道数组有序。
 */
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


/**
 * @brief 插入排序
 * 每次从前往后选定一个子序列，接着设置其后的一个元素为 flag，使用 flag 元素，对子序列
 * 从后往前一次比较其中元素，小于前一个则做交换；循环多次，直到所有元素有序。
 */
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


/**
 * @brief 希尔排序
 * 以间隔 gap（通常是数组大小的一般） 选择子序列，对子序列排序；
 * 再使得 gap 减半（或者自己设定缩减值），再次对子序列排序；
 * 直到 gap 减为 1，做最后一次排序。
 */
/** 
 * shell sort version 1 
 * using swap function
 */
template <typename T>
void shell_sort(vector<T>& array)
{
    for (int gap = array.size() >> 1; gap > 0; gap >>= 1)
        for (int i = gap; i < array.size(); i++)
            for (int j = i-gap; j >= 0 && array[j] > array[j+gap]; j -= gap)
                swap(array[j+gap], array[j]);
}

/** 
 * shell sort version 2
 * exchange the values continuously
 */
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


/**
 * @brief 归并排序
 * 将数组划分为左右两个一样大小的子序列，假定这两个子序列是有序的，可以通过简单的大小比
 * 较，合并两个子序列，从而得到一个有序数组；
 * 而为了使这两个子序列有序，可以按上述方式递归，将子序列再划分，直到仅仅比较两个元素的大
 * 小。
 */
/** 
 * Recursive version 1
 */
template <typename T>
void merge(vector<T>& array, int front, int mid, int end)
{
    /**
     * Preconditions:
     * array[front, ..., mid] is sorted, --> left
     * array[mid+1, ..., end] is sorted, --> right
     */
    vector<T> left(array.begin()+front, array.begin()+mid+1);
    vector<T> right(array.begin()+mid+1, array.begin()+end+1);
    
    int idx_left = 0;
    int idx_right = 0;
    // numeric_limits<int>::max() -- int 整型的最大值
    // vector.insert() -- 内置函数，在指定位置之前，插入新元素
    left.insert(left.end(), numeric_limits<int>::max());
    right.insert(right.end(), numeric_limits<int>::max());
    // cout << left.size() << " " << right.size() << endl;
    // return;

    // pick up the minus one of left[idx_left] and right[idx_right], and put it 
    // to array[i]
    for (int i = front; i <= end; i++) {
        if (left[idx_left] < right[idx_right]) {
            array[i] = left[idx_left];
            idx_left++;
        } else {
            array[i] = right[idx_right];
            idx_right++;
        }
    }
}

template <typename T>
void merge_sort(vector<T>& array, int front, int end)
{
    if (front >= end)
        return;
    int mid = (front+end) / 2;
    merge_sort(array, front, mid);
    merge_sort(array, mid+1, end);
    merge(array, front, mid, end);
}

/**
 * Iterative version 2 
 * 
 */
// template <typename T>
// vector<T> merge(vector<T>& left, vector<T>& right)
// {

// }

// template <typename T>
// void merge_sort(vector<T>& array)
// {}

/**
 * @brief 快速排序
 */
template <typename T>
void quick_sort(vector<T>& array)
{}


/**
 * @brief 堆排序
 */
template <typename T>
void heapify_sort(vector<T>& array)
{}


/**
 * @brief 计数排序
 */
template <typename T>
void counting_sort(vector<T>& array)
{}


/**
 * @brief 桶排序
 */
template <typename T>
void bucket_sort(vector<T>& array)
{}


/**
 * @brief 基数排序
 */
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
            merge_sort(arr, 0, arr.size()-1);
            merge_sort(arrf, 0, arrf.size()-1);
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