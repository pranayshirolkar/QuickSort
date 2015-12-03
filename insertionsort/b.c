#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
void quickSort(double [], int, int);
int partition(double [], int, int);
void insertionSort(double [], int, int);
int main(int argc, char *argv[]) 
{
	FILE *inputFile,*outputFile;
	int arraySize,i;
	double *array,time_spent;
	clock_t begin,end;
	srand(time(NULL));
	if(argc!=2)
	{
		printf("usage: %s <filename>\n",argv[0]);
		return 0;
	}
	//building array out of the input file
	inputFile=fopen(argv[1],"r");
	if (inputFile == NULL) return 0;
	fscanf(inputFile,"%d",&arraySize);
	printf("arraySize: %d\n",arraySize);
	i=0;
	array=(double *)malloc(sizeof(double)*(arraySize));
	while(i<arraySize)
	{
	fscanf(inputFile,"%lf",&array[i]);
//	printf("array[%d]: %.2f\n",i,array[i]);
	i++;
	}
	printf("Array building from file complete...\n");
	begin=clock();
	quickSort(array,0,arraySize-1);
	end=clock();
	time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Sorting Complete. Time Spent %.2f sec= \n",time_spent);
	i=0;
	outputFile=fopen("output.txt","wb");
	while(i<arraySize)
{
	fprintf(outputFile,"%f\n",array[i]);
	//printf("%.2f\n",array[i]);
i++;
}
	return 0;
}
void quickSort(double array[], int left, int right)
{
//double pivot;
//pivot=array[left];
int partitionPoint=partition(array,left,right);
if((right-left) < 9)//defining l = 9 to switch to insertion sort
{
	insertionSort(array,left,right+1);
}
else
{
	if(left<partitionPoint-1) quickSort(array,left,partitionPoint-1);
	if(partitionPoint<right) quickSort(array,partitionPoint,right);
}
}
int partition(double array[], int left, int right)
{
//	printf("modulo: %d\n",right+1-left);
	int pivotIndex=(rand()%(right+1-left))+left;
	double pivot=array[pivotIndex];
	double tmp;
	int a;
	int i,j;
	//	printf("pivotIndex: %d",pivotIndex);
	i=left;
	j=right;
	//printf("left: %d right: %d\n",i,j);
	//printf("Pivot: %.2f\n",pivot);
//	scanf("%d",&a);
	while(i<=j)
	{
//printf("loop chala\n");
		while(i<=right)
		{
//			printf("left: at array[%d]:%.2f\n",i,array[i]);
//scanf("%d",&a);
			if(array[i]>=pivot)
			{
				break;
			}
			i++;
		}
		while(j>=left)
		{
///			printf("right: at array[%d]:%.2f\n",j,array[j]);
//scanf("%d",&a);
			if(array[j]<=pivot)
			{
				break;
			}
			j--;
		}
		if(i<=j)
		{
			//swap
//			printf("Swapping values [%d]: %.2f and [%d]: %.2f now...\n",i,array[i],j,array[j]);
			//scanf("%d",&a);
			tmp=array[i];
//			printf("god\n");
			array[i]=array[j];
//			printf("is\n");
			array[j]=tmp;
//			printf("great\n");
			i++;
			j--;
//			printf("i=%d\n",i);	
//			printf("j=%d\n",j);
		}
//		printf("god is in detail\n");
	}
//printf("returning: %d\n",i);
//scanf("%d",&a);
	return i;
}
void insertionSort(double array[], int left, int right)
{
int x=left+1;
while(x<right)
{
double val=array[x];
int j=x-1;
while( j>=0 && val<array[j])
{
array[j+1]=array[j];
j--;
}
array[j+1]=val;
x++;
}
}
