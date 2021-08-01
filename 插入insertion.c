void Insertion_Sort ( ElementTypre A[] , int N )
{  for ( P=1; P<N; P++){               //外部循环进行抓牌，认为第零张牌已经在手中
     Tmp = A[P];
     for ( i=P; i>0 && A[i-1]>Tmp; i--)//内部循环从大到小比较，往后错位
       A[i]=A[i-1];
     A[i]=Tmp;                         //插入到留出的空位
  }   
}
