#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int countcmp=0;
//================Print the list================
void printlist(int list[],int n)
{
   int i;
   for(i=0;i<n;i++)
      printf("%d\t",list[i]);
}
//=========SWAP============//
void swap(int *x,int *y){
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;

}

//=================SELECTION SORT====================//
    void selection_sort(int list[], int n){
  int i, j, min;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i+1; j < n; j++)
    {
       if (list[j] < list[min])
       {        countcmp++;    //counter gia sigkriseis
          min = j;
       }
    }
    swap(&list[i], &list[min]);
  }
}


//=============BubbleSort==================================
void bubbleSort(int arr[], int n) {
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {countcmp++; //counter gia sigkriseis
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
                  }
            }
      }
      }

//=============INSERTIONSORT========================
void insertionSort(int arr[], int length) {
      int i, j, tmp;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j]) {countcmp++; //counter gia sigkriseis
                  tmp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tmp;
                  j--;
            }
      }
}
//=============HEAPSORT===============================================

void siftDown(int numbers[], int root, int bottom)
{
  int done, maxChild, temp;

  done = 0;
  while ((root*2 <= bottom) && (!done))
  {
    if (root*2 == bottom)
      {maxChild = root * 2;    countcmp++;} //counter gia sigkriseis
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      {maxChild = root * 2; countcmp++;} //counter gia sigkriseis
    else
      maxChild = root * 2 + 1;

    if (numbers[root] < numbers[maxChild])
    {                                     countcmp++; //counter gia sigkriseis
      temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
  }
}

void heapSort(int numbers[], int array_size)
{
  int i, temp;

  for (i = (array_size / 2)-1; i >= 0; i--)
    siftDown(numbers, i, array_size);

  for (i = array_size-1; i >= 1; i--)
  {                              countcmp++; //counter gia sigkriseis
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i-1);
  }
}





//=========MERGE===========================
// Mix two sorted tables in one and split the result into these two tables.  
int *Mix(int *tab1,int *tab2,int count1,int count2)  
{  
  int i,i1,i2;  
  i = i1 = i2 = 0;  
  int * temp = (int *)malloc(sizeof(int)*(count1+count2));  
  
  while((i1<count1) && (i2<count2))  
  {  
    while((i1<count1) && (*(tab1+i1)<=*(tab2+i2)))  
    {  
      *(temp+i++) = *(tab1+i1);                     countcmp++; //counter gia sigkriseis
      i1++;  
    }  
    if (i1<count1)  
    {  
      while((i2<count2) && (*(tab2+i2)<=*(tab1+i1)))  
      {  
        *(temp+i++) = *(tab2+i2);                     countcmp++; //counter gia sigkriseis
        i2++;  
      }  
    }  
  }  
  
  memcpy(temp+i,tab1+i1,(count1-i1)*sizeof(int));  
  memcpy(tab1,temp,count1*sizeof(int));  
  
  memcpy(temp+i,tab2+i2,(count2-i2)*sizeof(int));  
  memcpy(tab2,temp+count1,count2*sizeof(int));  
  // These two lines can be:  
  // memcpy(tab2,temp+count1,i2*sizeof(int));  
  free(temp);  
}  
  
// MergeSort a table of integer of size count.  
// Never tested.  
void MergeSort(int *tab,int count)  
{  
  if (count==1) return;  
  
  MergeSort(tab,count/2);  
  MergeSort(tab+count/2,(count+1)/2);  
  Mix(tab,tab+count/2,count/2,(count+1)/2);  
}  

//==================Quicksort=================
int choose_pivot(int i,int j ){
   return((i+j) /2);
}

void quicksort(int list[],int m,int n){
   int key,i,j,k;
   if( m < n)
   {
      k = choose_pivot(m,n);  countcmp++; //counter gia sigkriseis
      swap(&list[m],&list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                {i++; countcmp++; }//counter gia sigkriseis
         while((j >= m) && (list[j] > key))
                {j--;   countcmp++; } //counter gia sigkriseis
         if( i < j)
                {swap(&list[i],&list[j]);       countcmp++; } //counter gia sigkriseis
      }
      // swap two elements
      swap(&list[m],&list[j]);
      // recursively sort the lesser list
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);
   }
}


//===============MAIN=======================//
int main(){
     int choice=0;
     int i = 0;
     int MAX_ELEMENTS = 10;
     
  top:
          std::cout<<  "1.selection_sort\n"
                << "2.insertionSort\n"
                << "3.bubbleSort\n"
                << "4.heapSort\n"
                << "5.MergeSort\n"
                << "6.quicksort\n"
                << "7.exit\n";
          cout<<"Choose algo:";
           std::cin>>choice;
    
    
  
   cout<<"Give the array length: ";
   cin>>MAX_ELEMENTS;
   if (MAX_ELEMENTS < 0) goto top;
   int list[MAX_ELEMENTS];
  
  
  clock_t start, end; 
  double elapsed;
  
  
  
 for (int counter=0; counter<10; counter++){ 
      
   // generate random numbers and fill them to the list
   srand((long) 2007102);
   for(i = 0; i < MAX_ELEMENTS; i++ ){
       list[i] = 1+rand()%30000;
   }
    //===for debug below===
  // printf("The list before sorting is:\n");
  // printlist(list,MAX_ELEMENTS);
   
   
     
 start = clock();
 switch(choice){
                case 1:selection_sort(list,MAX_ELEMENTS);break;
                case 2:insertionSort(list,MAX_ELEMENTS);break;
                case 3:bubbleSort(list,MAX_ELEMENTS);break;
                case 4:heapSort(list,MAX_ELEMENTS);break;
                case 5:MergeSort(list,MAX_ELEMENTS);break;
                case 6:quicksort(list,0,MAX_ELEMENTS-1);break;
                case 7:return 0;
                default: return 0;}
                end = clock();
                elapsed += ((double) (end - start)) / CLOCKS_PER_SEC;
  
}
cout<<"\nO xronos pou xreiastike einai:"<<elapsed/10<<"sec"<<endl;
cout<<"\nO mesos arithmos sigkrisewn einai:"<<countcmp/10<<endl;
  //==for debug==
 //  printf("The list after sorting:\n");
  // printlist(list,MAX_ELEMENTS);
   system("pause");
   return 0;
}

    
    
    
