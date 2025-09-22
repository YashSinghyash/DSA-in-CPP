#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }

            else
            {
                return;
            }
        }

        return;
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteroot(){

        arr[1] = arr[size];
        size--;
        int index = 1;
        

        while (index <= size ){
            int leftC = 2*index;
            int rightC = 2*index+1;
            int largest = index;
            if (leftC <= size && arr[leftC]  > arr[largest] ){
                largest = leftC;
                
            }
            if (rightC <= size && arr[rightC]  > arr[largest] ){
                largest = rightC;
                
            }
            if (largest != index){
                swap(arr[index] , arr[largest]);
                index = largest;
            }
            else {
                return;
            }


        }

    }
};

int main()
{
    heap h;
    h.insert(30);
    h.insert(15);
    h.insert(45);
    h.insert(44);
    h.print();
    return 0;
}