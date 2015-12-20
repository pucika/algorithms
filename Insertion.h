template<class T>
class Insertion{
public:
	static void sort(T* array, int length);
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
	static void show(T* array, int length)
	{
		for(int i = 0; i!= length; i++)
			std::cout << array[i] << " ";
	}
};

template<class T>
void Insertion<T>::sort(T* array, int length)
{
	for(int i= 1; i!= length; i++)
	{
		for(int j = i; j > 0 && less(j - 1); j--)
			exch(array[j],array[j-1]);
	}
}