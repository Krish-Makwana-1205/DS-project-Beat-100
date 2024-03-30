#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/*1*/
void vectorInput(vector<int> &v)
{
    int n;
    cout << "Enter the Number of Elements in the Vector: ";
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cout << "Enter Element at " << i << "index: ";
        cin >> v[i];
    }
}

/*2*/
void vectorOutput(vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }

    cout << endl;
}

/*3*/
int getMin(vector<int> v)
{
    int minEle = INT_MIN;
    for (int i = 0; i < v.size(); ++i)
    {
        minEle = min(minEle, v[i]);
    }

    return minEle;
}

/*4*/
int getMax(vector<int> v)
{
    int maxEle = INT_MAX;
    for (int i = 0; i < v.size(); ++i)
    {
        maxEle = min(maxEle, v[i]);
    }

    return maxEle;
}

/*5*/
long long int getTotal(vector<int> v)
{
    long long int sum = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        sum += v[i];
    }

    return sum;
}

/*6*/
double average(vector<int> v)
{
    double sum = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        sum += v[i];
    }

    return (sum / v.size());
}

/*7*/
void reverseArray(vector<int> &v)
{
    int right = 0;
    int left = v.size() - 1;

    while (right < left)
    {
        swap(v[right], v[left]);
    }

    return;
}

/*8*/
void bubbleSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                isSorted = true;
            }
        }
        if (isSorted == false)
        {
            return;
        }
    }

    return;
}

/*9*/
int maxSumSubarray(vector<int> v)
{
    int n = v.size();
    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        maxEndingHere = max(maxEndingHere + v[i], v[i]);
        maxSoFar = max(maxEndingHere, maxSoFar);
    }

    return maxSoFar;
}

/*10*/
int linearSearchIterative(vector<int> v, int target)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == target)
        {
            return i;
        }
    }

    return -1;
}

/*11*/
int linearSearchRecursive(vector<int> &arr, int target, int index)
{
    if (index == arr.size())
    {
        return -1;
    }

    if (arr[index] == target)
    {
        return index;
    }

    return linearSearchRecursive(arr, target, index + 1);
}

/*12*/
int binarySearchIterative(vector<int> v, int target)
{
    int low = 0;
    int high = v.size() - 1;

    while (low < high)
    {
        int mid = low + ((high - low) / 2);

        if (v[mid] == target)
        {
            return mid;
        }
        else if (v[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

/*13*/
int binarySearchRecursive(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearchRecursive(arr, target, mid + 1, high);
    }
    else
    {
        return binarySearchRecursive(arr, target, low, mid - 1);
    }
}

/*14*/
void selectionSort(vector<int> &array)
{
    int size = array.size();

    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        int minValue = INT_MAX;

        for (int j = i; j < size; ++j)
        {
            if (minValue > array[j])
            {
                minValue = array[j];
                minIndex = j;
            }
        }

        swap(array[i], array[minIndex]);
    }
}

/*15*/
void insertionSort(vector<int> &arr)
{
    int size = arr.size();

    for (int currentIndex = 1; currentIndex < size; ++currentIndex)
    {
        int tempIndex = currentIndex;

        while (tempIndex >= 1 and arr[tempIndex] < arr[tempIndex - 1])
        {
            swap(arr[tempIndex], arr[tempIndex - 1]);
            tempIndex--;
        }
    }

    return;
}

/*16*/
void merge(vector<int> &arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    vector<int> b;

    while (i <= mid and j <= high)
    {
        if (arr[i] < arr[j])
        {
            b.push_back(arr[i]);
            i++;
        }
        else
        {
            b.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        b.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        b.push_back(arr[j]);
        j++;
    }

    for (int k = low; k <= high; ++k)
    {
        arr[k] = b[k - low];
    }
}

void mergeSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, mid, high);
    }
}

/*17*/
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int left = low;
    int right = high;

    while (left < right)
    {
        if (arr[left] > pivot && arr[right] < pivot)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        else if (arr[left] <= pivot)
        {
            left++;
        }
        else if (arr[right] >= pivot)
        {
            right--;
        }
    }

    swap(arr[left], arr[high]);

    return left;
}

void quickSort(vector<int> &v, int first, int last)
{
    if (first < last)
    {
        int partitionIdx = partition(v, first, last);
        quickSort(v, first, partitionIdx - 1);
        quickSort(v, partitionIdx + 1, last);
    }
}

/*18*/
void countSort(vector<int> &inputArray)
{
    int arraySize = inputArray.size();
    if (arraySize <= 1)
    {
        return;
    }

    int maxElement = INT_MIN;

    for (int i = 0; i < arraySize; ++i)
    {
        if (maxElement < inputArray[i])
            maxElement = inputArray[i];
    }

    vector<int> elementCount(maxElement + 1, 0);

    for (int i = 0; i < arraySize; ++i)
    {
        elementCount[inputArray[i]] += 1;
    }

    for (int i = 1; i <= maxElement; ++i)
    {
        elementCount[i] += elementCount[i - 1];
    }

    vector<int> sortedArray(arraySize);
    for (int i = arraySize - 1; i >= 0; --i)
    {
        sortedArray[--elementCount[inputArray[i]]] = inputArray[i];
    }

    for (int i = 0; i < arraySize; ++i)
    {
        inputArray[i] = sortedArray[i];
    }
}

/*19*/
void bucketSort(vector<float> &inputArray)
{
    int arraySize = inputArray.size();
    vector<vector<float> > buckets(arraySize, vector<float>());

    float maxValue = INT_MIN;
    float minValue = INT_MAX;

    for (int i = 0; i < arraySize; ++i)
    {
        if (maxValue < inputArray[i])
            maxValue = inputArray[i];

        if (minValue > inputArray[i])
            minValue = inputArray[i];
    }

    float range = (maxValue - minValue) / arraySize;

    for (int i = 0; i < arraySize; ++i)
    {
        int bucketIndex = (inputArray[i] - minValue) / range;

        float fractionalPart = (inputArray[i] - minValue) / range - bucketIndex;
        if (fractionalPart == 0 && inputArray[i] != minValue)
            bucketIndex -= 1;

        buckets[bucketIndex].push_back(inputArray[i]);
    }

    for (int i = 0; i < arraySize; ++i)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int currentIndex = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            inputArray[currentIndex++] = buckets[i][j];
        }
    }
}

/*20*/
void radixSort(vector<int> &inputArray)
{
    int arraySize = inputArray.size();

    if (arraySize == 0)
    {
        return;
    }

    int maxElement = INT_MIN;
    for (int i = 0; i < arraySize; ++i)
    {
        maxElement = max(maxElement, inputArray[i]);
    }

    for (int position = 1; position <= maxElement; position *= 10)
    {
        int digitFrequency[10] = {0};

        for (int i = 0; i < arraySize; i++)
        {
            digitFrequency[(inputArray[i] / position) % 10]++;
        }

        for (int i = 1; i < 10; ++i)
        {
            digitFrequency[i] += digitFrequency[i - 1];
        }

        vector<int> sortedArray(arraySize, 0);
        for (int i = arraySize - 1; i >= 0; --i)
        {
            sortedArray[--digitFrequency[(inputArray[i] / position) % 10]] = inputArray[i];
        }

        for (int i = 0; i < arraySize; ++i)
        {
            inputArray[i] = sortedArray[i];
        }
    }
}

/*21*/
void rotateArrayByK(vector<int> v, int k)
{
    int n = v.size();
    k = k % n;

    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        swap(v[low], v[high]);
    }

    low = 0;
    high = k - 1;
    while (low < high)
    {
        swap(v[low], v[high]);
    }

    low = k;
    high = n - 1;

    while (low < high)
    {
        swap(v[low], v[high]);
    }
}

/*22*/
int countIf(vector<int> v, int target)
{
    int count = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == target)
        {
            count++;
        }
    }

    return count;
}

/*23*/
void matrixInput()
{
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int> > matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "Enter the element at position (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }
}

/*24*/
bool isPalindrome(vector<int> v)
{
    for (int right = 0, left = v.size() - 1; right < left; right++, left--)
    {
        if (v[right] != v[left])
        {
            return false;
        }
    }

    return true;
}

/*25*/
void shuffleArray(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

int main()
{
    return 0;
}
