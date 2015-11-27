#include<stdio.h> 
#include<stdlib.h>
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
	return 0;
}
