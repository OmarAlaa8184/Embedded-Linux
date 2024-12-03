#include <stdio.h>

void bubble_sorting(int* array, int size);
int Binary_Search(int* array, int size, int search);

void main(void)
{
   int array[10];
   int size = 10;
   int i, search;
            
   /**************************** Scan the Values *************************/
     
   for (i = 0; i < 10; i++)
   {
         printf("Please Enter number %d:  ", i);
         scanf("%d", &array[i]);
   }
                          
	  bubble_sorting(array, size);

    /************************** Scan the value to search *******************/
		
	  printf("Please Enter number to search:  ");
	
	  scanf("%d", &search);


	  int index = Binary_Search(array, size, search);

	  printf("index = %d\n", index+1);
}

void bubble_sorting(int* array, int size)
{
	 
     	/**************** Sort the Values using bubble sorting ****************/

	int i, j, z;


	
	for (i = 0; i < size - 1; i++) 
	{
 
   	 for (j = 0; j < size - i - 1; j++)
	 {
	
	    if (array[j] > array[j + 1]) 
	    {	  
		    /* Swap */

		     z = array[j + 1];
			 
		     array[j + 1] = array[j];
											                    
		     array[j] = z;
	

	    }
		
	 }
	
	}
}

int Binary_Search(int* array, int size, int search)
{
	
     	/************************* Binary Search *******************************/
	 
     	int Left = 0, Right = size - 1;
	
	int FoundFlag = 0;

	int counter;


	while (Left <= Right)
       	{

		counter = Left + (Right - Left) / 2;
				       
	       	if (search == array[counter])
	       	{

			FoundFlag = 1;
								                
			break;


		} 
		else if (search > array[counter])
	       	{	
			Left = counter + 1;
		
		} 
		else
	       	{
			Right = counter - 1;
																	     
	     	}
	
	}

			    
	if (FoundFlag == 1)
       	{
	
		return counter;
					        
	} 
	else
       	{
		return -1;
	
	}
}
