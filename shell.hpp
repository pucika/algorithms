template<class T>
class Shell
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
void Shell<T>::sort(T* array, int length)
{
	int N = length;
	int h = 1;
	while(h < N/3) h = 3 * h + 1;
	while(h > 1)
	{
		for(int i = h; i < N ; i++)
		{
			for(int j = h; j >= h && less(array[j], array[j - h]); j -= h)
			{
				exch(array, j, j - h);
			}
		}
	}
}