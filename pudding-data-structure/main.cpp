
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <Windows.h>
#include <stdio.h>
#include <time.h>

#include "Stack.h"
#include "mergesort.h"
#include "quicksort.h"
#include "insertionsort.h"

#pragma warning(disable : 4996)


int comp( int a, int b )
{
	if( a > b )
		return true;
	else 
		return false;
}

void TESTMergeSort()
{
	FILE* in = fopen( "input.txt", "r");

	int n;

	LARGE_INTEGER freq, t1, t2;
	QueryPerformanceFrequency(&freq);


	fscanf(in, "%d", &n);

	int* arr = new int[n];
	int i;
	for( i=0; i<n; i++ )
		fscanf(in, "%d", &arr[i]);


	QueryPerformanceCounter(&t1);
	printf("--Pre sorting--\nTime : %lld\n\n", t1.QuadPart);

	mergesort( arr, 0, n, comp );
	//mergesort_without_recursion( arr, 0, n, comp );
	
	QueryPerformanceCounter(&t2);
	printf("--Sorted--\nTime : %lld\n\n", t2.QuadPart);

	printf("Time diff = %lld\n\n", (t2.QuadPart - t1.QuadPart) );


	FILE* out = fopen( "output.txt", "w" );
	fprintf(out, "%d\n", n);
	for( i=0; i<n; i++ )
		fprintf(out, "%d\n", arr[i]);

	delete[] arr;

	fclose(in);
	fclose(out);
}

void TESTQuickSort()
{
	FILE* in = fopen( "input.txt", "r");

	int n;

	LARGE_INTEGER freq, t1, t2;
	QueryPerformanceFrequency(&freq);


	fscanf(in, "%d", &n);

	int* arr = new int[n];
	int i;
	for( i=0; i<n; i++ )
		fscanf(in, "%d", &arr[i]);


	QueryPerformanceCounter(&t1);
	printf("--Pre sorting--\nTime : %lld\n\n", t1.QuadPart);

	quicksort( arr, n, comp );
	
	QueryPerformanceCounter(&t2);
	printf("--Sorted--\nTime : %lld\n\n", t2.QuadPart);

	printf("Time diff = %lld\n\n", (t2.QuadPart - t1.QuadPart) );


	FILE* out = fopen( "output.txt", "w" );
	fprintf(out, "%d\n", n);
	for( i=0; i<n; i++ )
		fprintf(out, "%d\n", arr[i]);

	delete[] arr;

	fclose(in);
	fclose(out);
}

void TESTInsertionSort()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10	};

	insertionsort( arr, 10 );
	//insert( arr, 10, 0, 999 );

	for( int i=0; i<10; i++ )
		printf("%4d", arr[i]);
	printf("\n");
}

void TESTStack()
{
	HongStack<int> hs(5);

	/*hs.push( new int(1) );
	hs.push( new int(1) );
	hs.push( new int(1) );*/
}

int main()
{
	// Check memory leak
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	_CrtDumpMemoryLeaks();

	srand( (unsigned)time(NULL) );

	//TESTStack();
	//TESTQuickSort();
	TESTQuickSort();
	//TESTInsertionSort();
	
	return 0;
}