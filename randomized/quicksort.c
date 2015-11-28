#include<stdio.h> 
#include<stdlib.h>
void quickSort(double [], int, int);
int partition(double [], int, int);
int main(int argc, char *argv[]) 
{
	FILE *inputFile;
	int arraySize,i;
	double *array;
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
	printf("array[%d]: %.2f\n",i,array[i]);
	i++;
	}
	printf("Array building from file complete...\n");
	quickSort(array,0,arraySize-1);
	printf("Sorting Complete\n");
	i=0;
	while(i<arraySize)
{
	printf("%.2f\n",array[i]);
i++;
}
	return 0;
}
void quickSort(double array[], int left, int right)
{
//double pivot;
//pivot=array[left];
int partitionPoint=partition(array,left,right);
if(!(left==partitionPoint-1))
quickSort(array,left,partitionPoint-1);
if(!(partitionPoint==right))
quickSort(array,partitionPoint,right);
}
int partition(double array[], int left, int right)
{
	int pivotIndex=rand()%((right+1-left)+left);
	double pivot=array[pivotIndex];
	double tmp;
	int a;
	int i,j;
	i=left;
	j=right;
	printf("left: %d right: %d\n",i,j);
	printf("Pivot: %.2f\n",pivot);
	scanf("%d",&a);
	while(i<=j)
	{
		while(i<=right)
		{
			printf("left: at array[%d]:%.2f\n",i,array[i]);
scanf("%d",&a);
			if(array[i]>=pivot)
			{
				break;
			}
			i++;
		}
		while(j>=left)
		{
			printf("right: at array[%d]:%.2f\n",j,array[j]);
scanf("%d",&a);
			if(array[j]<=pivot)
			{
				break;
			}
			j--;
		}
		if(i<=j)
		{
			//swap
			printf("Swapping values [%d]: %.2f and [%d]: %.2f now...\n",i,array[i],j,array[j]);
scanf("%d",&a);
			tmp=array[i];
			array[i]=array[j];
			array[j]=tmp;
			i++;
			j--;
		}
	}
printf("returning: %d",i);
scanf("%d",&a);
	return i;
}
