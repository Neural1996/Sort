void Bubble_Sort(ElementType A[], int N) 
{ for(P=N-1; P>=0; P--){                     //总共循环p=n-1到p=0趟
     flag=0;
     for(i=0; i<P; i++)                      //一趟冒泡
       if(A[i] > A[i+1]){
         swap(A[i] , A[i+1]);
         flag=1;                             //如果放生过交换，让标记等于1
       }
  }
  if( flag==0 ) break;                       //说明全程无交换，队列已经排序好了
}
//时间复杂度，为N~N^2
