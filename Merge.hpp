template<class T>
class Merge
{
public:
	static void sort(T a[], int len);
	static void show(T* array, int length)
	{
		for (int i = 0; i != length; i++)
			std::cout << array[i] << " ";
	}
private:
	static T *aus;
	static void sort(T a[], int low, int high);
	static void merge(T a[], int low, int mid, int high);
	static bool less(T i, T j)
	{
		return i < j;
	}
	static void exch(T* array, int i, int j)
	{
		T temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

};

//特化
template <>
int* Merge<int>::aus = nullptr;

template<class T>
void Merge<T>::sort(T a[], int len)
{
	aus = new T[len];
	sort(a, 0, len - 1);
	delete[] aus;
}

template<class T>
void Merge<T>::sort(T a[], int low, int high)
{
	if (high <= low) return;
	int mid = low +  (high - low) / 2;
	sort(a, low, mid);
	sort(a, mid + 1, high);
	merge(a, low, mid, high);
}

template<class T>
void Merge<T>::merge(T a[], int low, int mid, int high)
{
	int i = low, j = mid + 1;
	for (int k = low; k <= high; k++)
		aus[k] = a[k];
	for (int k = low; k <= high; k++){
		if (i > mid)	a[k] = aus[j++];
		else if (j > high) a[k] = aus[i++];
		else if (less(aus[j], aus[i])) a[k] = aus[j++];
		else	a[k] = aus[i++];
	}
}