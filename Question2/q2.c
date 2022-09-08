#include<stdio.h>

int main()
{
    int i,j,temp,n;
    printf("Enter The Size Of Array\n");
    scanf("%d",&n);

    int arr[n];

    printf("Enter Element Of Array\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=1;i<n;i++)
    {   
        temp=arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

	for (i=0;i<n;i++)
	    printf("%d\t",arr[i]);
	printf("\n");

	return 0;
}
