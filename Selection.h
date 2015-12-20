template<class T>
class Selection
{
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
};

template<class T>
void Selection<T>::sort(T* array, int length)
{
	for(int i = 0; i != length; i++)
	{
		int min = i;
		for(int j = i+1; j != length; j++)
		{
			if(less(array[j],array[min])) min = j;
		}
		exch(array, i, min);
	}
}
