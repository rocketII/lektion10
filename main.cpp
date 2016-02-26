#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
/*
 * sort and search.
 * kommer på tentan.
 * Template
 * Template class
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
 * 067189
 * 061789
 * 016789
 * --------search-----------------
 * linear search/ sequential
 * binear search (sorted array)
 *      0123456789
 * find middle
 * search for 8
 * 8 < middle?
 * look at greater part than middle
 *      6789
 * new middle
 *      89
 * return 6+1
*/
//header
template<typename T>

class vector
{
private:
    T *items;
    int nrOfItems;
    int capacity;
    int capacityIncrement;
    void expand();
public:
    vector();//A1
    vector(int capacity); //same as A1
    vector(int capacity, int capacityIncrement);//same as A1
    ~vector();
    vector(const vector<T> &obj);
    vector<T>& operator=(const vector &obj);
    vector<T>& operator+(const vector &obj);// vector< > vect4; vect4=vect1 + vect2;
    vector<T>& operator[](const vector &obj);//obj[2] returns value at 2 element;
    void addLast(T item);
    void addFirst(T item);
    void addAt(int index, T item);
    T getFirst();
    T getLast();
    T getAt();
    T removeFirst();
    T removeLast();
    T removeAt(int index);
    void removeBetween(int start, int end);
    void clear();//delete array and create new empty;

};

template <typename T>
void vector<T>::expand()
{
    T* temp=new T [this->capacity+this->capacityIncrement];
    for(int i=0; i < this->nrOfItems; i++)
    {
        temp[i]=this->items[i];
    }
    delete [] this->items;
    this->items=temp;
}
template <typename T>
void vector<T>::addAt(int index, T item)throw(...) //throw(...) ... means accept any type.
{
    if(index > this->nrOfItems)
    {
        throw "not allowed position!";

        /*
         * in main
         * try
         * {
         *   vect.addAt(2,items);
         * }
         * catch(char *e)
         * {
         *  cout << e << endl;
         * }
         */
    }
    //if array full. expand and additem
    if(this->nrOfItems== this->capacity)
    {
        this->expand();
        this->items[this->nrOfItems++]=this->items[index];
        this->items[index]=item;
    }
}


template<typename T>
vector<T>::vector()
{
    this->capacity=10;
    this->capacityIncrement=10;
    this->nrOfItems=0;
    this->items=new T[this->capacity];

}
template<typename T>
vector<T>::~vector()
{
    delete [] this->items;
}
template<typename T>
vector<T>::vector(const vector<T> &obj)
{
    this->capacity=obj.capacity;
    this->capacityIncrement=obj.capacityIncrement;
    this->nrOfItems=obj.nrOfItems;
    this->items= new T [this->capacity];
    for(int i=0; i < this->nrOfItems; i++)
    {
        this->items[i]=obj.items[i];
    }
}
template<typename T>
vector<T>& vector<T>::operator =(const vector<T> &obj)
{
    if(this != &obj)
    {
        delete [] this->items;
        this->capacity=obj.capacity;
        this->capacityIncrement=obj.capacityIncrement;
        this->nrOfItems=obj.nrOfItems;
        this->items= new T [this->capacity];
        for(int i =0; i < this->nrOfItems; i++)
        {
            this->items[i]=obj.items[i];
        }
    }
    return *this;
}
template<typename T>
vector<T>& vector<T>::operator+(const vector &obj)
{
    /*
    vector vect 1; //array of of size 10
    vect1.addAt(0,1);
    vector vect2;
    vect2.addAt(0,1);
    vect2.addAt(1,2);
    vector vect3;
    vect3 = vect1+vect2
            */
    vector<T> v;
    for(int i=0; i< this->nrOfItems; i++)
    {
        v.addLast(this->items[i]);

    }
    for(int i=0; i< obj.nrOfItems; i++)
    {
        v.addLast(obj.items[i]);

    }

    return v ;

}
template<typename T>
T vector<T>::operator[](int index)const throw(...)//throw check valid index
{
    if(index < 0 || index >this->nrOfItems)
    {
        throw "Totz invalid index!!";
    }
    return this->getAt(index);

}
template<typename T>
void vector<T>::addLast(T item)
{
    if(this->capacity==this->nrOfItems)
        expand();
    this->items[nrofItems++]=item;
}

template<typename T>
void vector<T>::removeBetween(int start, int end)throw(...)
{
    if(this->nrOfItems ==0)
    {
        throw "no item!";
    }
    if(start < 0 || end > this->nrOfItems)
        throw "Totz invalid interval!";
    for(int i=start; i<end;i++)
    {
        this->items[i]=this->items[--this->nrOfItems];
    }
}

template<typename T>
void vector<T>::clear()
{
    delete [] this->items;
    this->capacity=10;
    this->capacityIncrement=10;
    this->nrOfItems=0;
    this->items= new T[this->capacity];
}

/////////////////////////////////////////////////////////////////////////////////

void generatRandomValues(string arr[] , int SIZE); //fill arr
template <typename T>
void printAllValues(T arr[], int SIZE);//print with for looping
template <typename T>//only one function at a time.
void selection_sort(T arr[], int SIZE);//sort low 2 big
template <typename T>//only one function at a time.
void insertion_sort(T arr[], int SIZE);//sort low 2 big
template <typename T>//only one function at a time.
void bubble_sort(T arr[], int SIZE);//sort low 2 big
template <typename T>//only one function at a time.
int linear_search(T arr[], int SIZE, T key);//sort low 2 big
template <typename T>//only one function at a time.
int binary_search(T arr[], int SIZE, T key);//
//void swap(string &a, string &b);
//int findMinimumPosition(string arr[], int SIZE);

//////////////////////////////////////////////////////
/// \brief main
/// \return
//////////////////////////////////////////////////////
//#include vector.h
int main()
{
    ///////test vector
    vector<int> vect1;
    try
    {
        vect1.getFirst();//Error!
        vect1.addFirst(19);
        vect1.addLast(27);   /// |19|27 | | | | | | | | |
        vect1.addAt(4,12);   ///bad! get u error :'(  index < item
        vect1.addAt(0,14);   /// |18||27 |19|14| | | | | |
        vect1.addFirst(18);  /// |18||27 |19|14| | | | | |   //
        for(int i =0; i < vect1.size(); i++)
        {
            cout << vect1.getAt(i);
            cout << vect1[i];
        }
        vector<int> vect1;
        vect1.addFirst(16);
        vector <int> vect2; //copy  = vect1
        vect2.addFirst(18);
        vect2.addLast(2);
        vect1=vect2; //assignment
        vector <int> vect3;
        vect3=vect1+vect2; // |16|18|2|
        vect1.removeBetween(1,4);
    }
    catch(char *e)
    {
        cout << e << endl;
    }

    ///////test sort search
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



//////////////////////////////////////////////////
///
//////////////////////////////////////////////////

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

template <typename T>//only one function at a time.
int linear_search(T arr[], int SIZE, T key)
{
    int pos=-1;
    for(int i=0; i < SIZE; i++)
    {
        if(arr[i]==key)
        {
            pos=i;
        }
    }
    return pos +1;
}

template <typename T>//only one function at a time.

int binary_search(T arr[], int SIZE, T key)
{
    int start =0;
    int end = SIZE -1;
    int mid=(start+end)/2;
    while(end >= start && arr[mid] != key)
    {

        if(key > arr[mid])
        {
            start = mid +1;

        }
        else
        {
            end = mid-1;
        }
        mid=(start+end)/2;

    }
    if(start > end)
    {
        mid= -1;
    }


    return mid+1;
}

/*void swap(string &a, string &b)
{
    ;
}*/

/*int findMinimumPosition(string arr[], int SIZE)
{
    return 0;
}*/
