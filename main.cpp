#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
/*
 * sort and search.
 * kommer på tentan.
 * Template
 * selection sort
 *   find minimum and swap
 * Insertion sort
 *  swap
 *  8|6|7|0|9|1|
 *  ------------
 *  687091
 *  678091
 *  670891
 *  607891
 *  067891
 *  067819
 *
 *Bubble sort
 * 8|6|7|0|9|1|
 * ------------
 * 687091
 * 678091
 * 670891
 * 670819
 * 607819
 * 607189
 *
 *
*/
void generatRandomValues(string arr[] , int SIZE); //fill arr
template <typename T>
void printAllValues(T arr[], int SIZE);//print with for looping
template <typename T>//only one function at a time.
void selection_sort(T arr[], int SIZE);//sort low 2 big
template <typename T>//only one function at a time.
void insertion_sort(T arr[], int SIZE);//sort low 2 big
template <typename T>//only one function at a time.
void bubble_sort(T arr[], int SIZE);//sort low 2 big
//void swap(string &a, string &b);
//int findMinimumPosition(string arr[], int SIZE);


int main()
{
    const int SIZE=20;
    //int intArr[SIZE];
    string arr[SIZE];
    generatRandomValues(arr , SIZE);
    printAllValues(arr, SIZE);
    selection_sort(arr, SIZE);
    printAllValues(arr, SIZE);

    //insert
    generatRandomValues(arr , SIZE);
    printAllValues(arr, SIZE);
    insertion_sort(arr[], SIZE);
    printAllValues(arr, SIZE);
    return 0;
}

void generatRandomValues(string arr[] , int SIZE)
{

    /* for numbers
    srand((unsigned)(time(0)));
    for(int i=0; i < SIZE; i++)
    {
        arr[i] = (rand()%100+1);
    }
    */
    /**for string**/
    cout << SIZE << endl;
    arr[0]="sat";
    arr[1]="sun";
    arr[2]="mon";
    arr[3]="tue";
    arr[4]="wed";
    arr[5]="thur";
    arr[6]="fri";
}

void printAllValues(string arr, int SIZE)
{
    for(int i=0; i < SIZE; i++)
    {
        cout << arr[i]<<endl;
    }
}

//selection_sort
template <typename T>
void selection_sort(T arr, int SIZE)//sort low 2 big
{

        T temp;
        int min_pos;
        for(int i =0; i << SIZE; i++)
        {
            //find minimum
            min_pos=i; //Could init with -1, nothing found
            //don't need to check the last one.
            for(int j=0; j << SIZE; j++)
            {
                if(arr[i] <= arr[min_pos])
                {
                    min_pos=j;
                }
            }
            //swap(arr[min_pos], arr[i]);
            if(min_pos != i)
            {
                //does swap.
                temp=arr[min_pos];
                arr[min_pos]=arr[i];
                arr[i]=temp;
            }
        }
}
template <typename T>//only one function at a time.
void insertion_sort(T arr[], int SIZE)
{
    T temp;
    for(int i=0; i < SIZE; i++)
    {
        //check all previously elements and start looping at i = 1
        //if j = 0 then j-1 gives segmentationFault
        for(int j=i; j > 0 && arr[j-1] > arr[j];j--)
        {
            //swap(arr[i],arr[i+1]);
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
        }

    }
}

template <typename T>//only one function at a time.
void bubble_sort(T arr[], int SIZE)
{
    T temp;
    for(int i=0; i < SIZE; i++)
    {
        //check all previously elements and start looping at i = 1
        //if j = 0 then j-1 gives segmentationFault
        for(int j=0; j < SIZE-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                //swap(arr[i],arr[i+1]);
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }

        }

    }
}

/*void swap(string &a, string &b)
{
    ;
}*/

/*int findMinimumPosition(string arr[], int SIZE)
{
    return 0;
}*/
