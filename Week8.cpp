#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int maximum = root; 
    int left = 2*root + 1; // left child = 2*i + 1
    int right = 2*root + 2; // right child = 2*i + 2
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[maximum])
        maximum = left;
 
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[maximum])
        maximum = right;
 
    // If largest is not root
    if (maximum != root)
    {
        swap(arr[root], arr[maximum]);
 
       
        heapify(arr, n, maximum);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(arr, n, i);
  
   // extracting elements from heap one by one
   for (int i=n-1; i>=0; i--)
   {
       swap(arr[0], arr[i]);
  
       // heapify the reduced heap
       heapify(arr, i, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n;
   vector<int> heap_arr_vec;
   std::string input_string;
   cout << "Enter the elements to be sorted: ";
   std::getline(std::cin,input_string);
   std::stringstream ss(input_string);
   int num;
   // Split the string into individual integers
    while (ss >> num) {
        heap_arr_vec.push_back(num);
    }
   
   int* heap_arr = heap_arr_vec.data();
   n = heap_arr_vec.size();

   cout<<"Input array: ";
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array: ";
   displayArray(heap_arr, n);
}
