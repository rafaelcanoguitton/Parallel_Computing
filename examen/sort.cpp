#include "mpi.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <cstdlib>
using namespace std;

long original_len;
int rank;
int proc_number;
int IncOrder(const void *e1, const void *e2)
{
	return (*((long *)e1) - *((long *)e2));
}
void compare_exchange_min(long *array, long *recv, long n)
{
	long a = 0, b = 0, c = 0;
	long *temp = new long[n];
	while (c < n)
	{
		if (array[a] <= recv[b])
		{
			temp[c++] = array[a++];
		}
		else
		{
			temp[c++] = recv[b++];
		}
	}
	memcpy(array, temp, n * sizeof(long));
}
void compare_exchange_max(long *array, long *recv, long n)
{
	long a = n - 1, b = n - 1, c = n - 1;
	long *temp = new long[n];
	while (c >= 0)
	{
		if (array[a] >= recv[b])
		{
			temp[c--] = array[a--];
		}
		else
		{
			temp[c--] = recv[b--];
		}
	}
	memcpy(array, temp, n * sizeof(long));
}
int main(int argc, char **argv)
{
	long proc_data_size;
	long *proc_data;
	long *original;
	int odd_rank;
	int even_rank;
	long *received;
	long *final;
	double exec_time;
	MPI_Init(&argc, &argv);
	MPI_Barrier(MPI_COMM_WORLD);
	exec_time = -MPI_Wtime();
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &proc_number);
	if (0 == rank)
	{
		original = data_loading(argv[1]);
		proc_data_size = original_len / proc_number;
		cout << proc_data_size << endl;
	}
	MPI_Bcast(&proc_data_size, 1, MPI_LONG, 0, MPI_COMM_WORLD);
	proc_data = new long[proc_data_size];
	received = new long[proc_data_size];
	final = new long[original_len];
	MPI_Scatter(original, proc_data_size, MPI_LONG, proc_data, proc_data_size, MPI_LONG, 0, MPI_COMM_WORLD);
	qsort(proc_data, proc_data_size, sizeof(long), IncOrder);
	if (rank % 2 == 0)
	{
		odd_rank = rank - 1;
		even_rank = rank + 1;
	}
	else
	{
		odd_rank = rank + 1;
		even_rank = rank - 1;
	}
	MPI_Status status;
	for (int i = 0; i < proc_number; i++)
	{
		if (i % 2 == 1)
		{
			if (odd_rank >= 0 && odd_rank < proc_number)
			{
				MPI_Sendrecv(proc_data, proc_data_size, MPI_LONG, odd_rank, 0, received, proc_data_size, MPI_LONG, odd_rank, 0, MPI_COMM_WORLD, &status);
				if (rank % 2 == 1)
				{
					compare_exchange_min(proc_data, received, proc_data_size);
				}
				else
				{
					compare_exchange_max(proc_data, received, proc_data_size);
				}
			}
		}
		else
		{
			if (even_rank >= 0 && even_rank < proc_number)
			{
				MPI_Sendrecv(proc_data, proc_data_size, MPI_LONG, even_rank, 0, received, proc_data_size, MPI_LONG, even_rank, 0, MPI_COMM_WORLD, &status);
				if (rank % 2 == 0)
				{
					compare_exchange_min(proc_data, received, proc_data_size);
				}
				else
				{
					compare_exchange_max(proc_data, received, proc_data_size);
				}
			}
		}
	}
	MPI_Gather(proc_data, proc_data_size, MPI_LONG, final, proc_data_size, MPI_LONG, 0, MPI_COMM_WORLD);
	MPI_Finalize();
	return 0;
}
