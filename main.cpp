#include <iostream>
using namespace std;
#define SIZE 30
class Heaps
{
    int max;
public:
    int *arr;
	int size=0;

private:
	int parent(int i)
	{
		return i / 2;
	}
	int left(int i)
	{
		return (2 * i);
	}
	int right(int i)
	{
		return ((2 * i) + 1);
	}

	void swap(int *a, int *b)
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}


	void decrease(int i, int new_value){

        arr[i] = new_value;
        while (i != 0 && arr[parent(i)] > arr[i]){
                swap(&arr[i], &arr[parent(i)]);
                i = parent(i);
        }
	}

	int extractmin(){
		if (size <= 0)
			return INT_MAX;
		if (size == 1)
		{
			size--;
			return arr[0];
		}

		int root = arr[0];
		arr[0] = arr[size - 1];
		size--;
		minHeapify(0);

		return root;

	}

	void heapify(int arr[], int n, int i)
	{
		int smallest = i;
		int l = left(i);
		int r = right(i);


		if (l < n && arr[l] < arr[smallest])
		{
			smallest = l;
		}


		if (r < n && arr[r] < arr[smallest])
		{
			smallest = r;
		}

		if (smallest != i) {
			swap(&arr[i], &arr[smallest]);


			heapify(arr, n, smallest);
		}
	}

public:
	Heaps(int limit)	{
		max = limit;
		arr = new int[max];
	}


	int size_func()
	{
		return size;
	}


	void top()
	{
		cout << "Minimum number " << arr[0] << endl;
	}
	int pop(int i)
	{
	 decrease(i, INT_MIN);
	 extractmin();
	}

	void push(int value)
	{
		if (size == max){
			cout << "Heap is already full. Remove an element to insert another." << endl;
			return;
		}

		    size++;
		    int i= size-1;
		    arr[i]=value;

		    while(i!=0 && arr[parent(i)]>arr[i]){
                swap(&arr[i],&arr[parent(i)]);
                i=parent(i);

		}
	}

	bool isEmpty()
	{
		if (size == 0)
		{
			cout << "heap is empty" << endl;
			return 1;
		}
		else
		{
			cout << "heap is not empty" << endl;
			return 0;
		}
	}
	int height()
	{
		int height=0;
		int node = size;
		while (node != 1)
		{
			node = node / 2;
			height++;
		}
		cout << "Height of the Heap: " << height << endl;
		return height;
	}

	void buildHeap(int array[], int n)
	{
	int start=n;
	for(int i=start;i>=0;i--){
        heapify(array,n,i);
        }
	}



	void print()
	{
		cout << "min heap" << endl;
		for (int i = 0; i <= size; i++)
		{
			cout << arr[i] << " --> ";
		}
	}



	void minHeapify(int i)
	{
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<size && arr[l]<arr[i])
        smallest=l;
    if(r<size && arr[r]<arr[smallest])
        smallest=r;
    if (smallest != i){
        swap(&arr[i],&arr[smallest]);
        minHeapify(smallest);
    }
	}
};
int main()
{
	int choice = 0, value;
	Heaps heap1(30);
	do
	{
		cout << "\nChoose the operation"
			<< endl;
		cout << "1. Minimum Element\n2. Pop Element\n3. Push Element\n4. Check if Empty\n5. Return Size" <<
			endl;
		cout << "6. Return Height\n7. Build Min Heap\n8. Print" << endl;
		cin >> choice;
		switch (choice) //switch case
		{
		case 1:
			heap1.top();
			break;
		case 2:
			heap1.pop(30);
			break;
		case 3:
			cout << "Enter the value you wish to insert: ";
			cin >> value;
			heap1.push(value);
			break;
		case 4:
			heap1.isEmpty();
			break;
		case 5:
			cout << "Size of the Heap: " << heap1.size_func() << endl;
			break;
		case 6:
			heap1.height();
			break;
		case 7:
			int  arr[30];int n;int z;
			cout << "Choose the size of your heap: ";
			cin >> z;
			heap1.push(z);

			for (int i = 1; i <= n; i++)
			{
				cout << "Element " << i << ": ";
				cin >> heap1.arr[i];
				heap1.push(i);
			}
			heap1.buildHeap(arr, n);
			break;

			heap1.print();
			break;
		default:
			cout << "Invalid operation selected!" << endl;
			break;
		}
	} while (1);
	return 0;
}
