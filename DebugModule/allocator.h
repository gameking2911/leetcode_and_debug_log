#pragma once
//template<class T>
class allocator
{
public:
	allocator();
	~allocator();
	enum
	{	
		align_size = 8,
		max_size = 128,
		chunk_size = max_size/align_size,
	};
	static void* allocate(size_t);
	static void* allocate(void);
	static void deallocate(T*,size_t);
	static void deallocate(T*);
	static char* chunk_alloc(size_t size);
private:
	union obj
	{
		union obj* free_list_link;
		char client_data[1];
	};

	static obj* free_list[chunk_size];
	static size_t FreelistIndex(size_t);
};

size_t allocator::FreelistIndex(size_t size)
{
	(size + align_size - 1) / align_size - 1;
}

void* allocator::allocate(size_t n)
{
	my_free_list = free_list + FreelistIndex(n);
	result = *my_free_list;
	if (result == 0)
	{
		void *r = refill(n);
		return r;
	}
	*my_free_list = result->free_list_link;
	return result;
}

void allocator::deallocate(void* p,size_t n)
{
	my_free_list = free_list + FreelistIndex(n);
	result = *my_free_list;
	obj* q = reinterpret_cast<obj*>(p);
	q->free_list_link = result;
	*my_free_list = q;
	//return *my_free_list;
}

char* allocator::chunk_alloc(size_t size)
{
	char* result;
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free;

	if (bytes_left >= total_bytes)
	{
		result = start_free;
		start_free += total_bytes;
		return(result);

	}
}

void* refill(size_t n)
{
	int nobjs = 20;
	char* chunk = chunk_alloc(n, nobjs);
	obj** my_free_list;
	
	my_free_list = free_list + Freelist_index(n);
	result = (obj*)chunk;
	*my_free_list = (obj*)(chunk + n);

}