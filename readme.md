# **Sort**
数据结构排序算法  
## 简单排序
### 前提
* 排序算法的统一写法：  `void x_sort (elementype[] , int n ）`  
分别对应 `存贮要排序元素的数组`和 `排序的个数`  
* n为合法的正整数
* 只讨论基于比较的排序
* *稳定性*：任意两个相等的数据，排序的前后相对位置不发生改变
* 没有一种排序是任何情况下都表现最好的，所以有很多排序算法
### 冒泡排序
重复地走访过要排序的队列，依次比较两个相邻的元素，如果顺序（如从大到小）错误就把他们交换过来。走访元素的工作是重复地进行直到没有相邻元素需要交换，也就是说该元素列已经排序完成。  
* 每走访一趟最大元素的位置就会被确认，下一趟只需走访n-1个元素。
>这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端（升序或降序排列），就如同碳酸饮料中二氧化碳的气泡最终会上浮到顶端一样，故名“冒泡排序”。    
* [代码](https://github.com/Neural1996/Sort/blob/main/%E5%86%92%E6%B3%A1bubble.c)  
* 缺点：时间复杂度高，效率差 最好N，最坏N^2
* 优点：代码简单，按顺序依次比较，每次交换相邻两位，可以适用于链表
### 插入排序
插入排序是一种最简单的排序方法，它的基本思想是将一个记录插入到已经排好序的有序表中，从而一个新的、记录数增1的有序表。在其实现过程使用双层循环，外层循环对除了第一个元素之外的所有元素，内层循环对当前元素前面有序表进行待插入位置查找，并进行移动。
* 就像玩扑克牌要捋牌一样，新抓一张牌，从大到小比较，当他比最后一张小，最后一张向后移一位
* [代码](https://github.com/Neural1996/Sort/blob/main/%E6%8F%92%E5%85%A5insertion.c)
* 缺点：时间复杂度高，效率差 最好N，最坏N^2
* 优点：程序简单

插入排序与冒泡排序都相当于每次交换两个相邻元素，每交换一次，消去一个逆序对，所以有多少个逆序对就要交换几次。
>逆序对：如果存在正整数 i, j 使得 1 ≤ i < j ≤ n 且 A[i] > A[j]，则 <A[i], A[j]> 这个有序对称为 A 的一个逆序对。  
所以这两算法之所以慢，是因为每次交换只能去掉一个逆序对，当每次两元素相隔较远时，能提升效率。  
### 希尔排序 shell_sort
希尔排序是插入排序的一种又称“缩小增量排序”（Diminishing Increment Sort），是直接插入排序算法的一种更高效的改进版本。  
* 定义从大到小的增量间隔 Dm > Dm-1 > ... > D1=1 
* 当进行小间隔排序后，之前的间隔仍然保持有序 
## 堆排序
### 选择排序
![图片](https://user-images.githubusercontent.com/88218815/127792650-6f33508b-ddd1-44a3-b0ab-7b17829931ca.png)
* 最小元交换时，两个元素可能相距很远，所以一次可能消掉了很多逆序对
* 使用最小堆来找到最小元
### 堆排序 
利用最大堆，先将队列建成最大堆，然后取出根节点A[0]与最末尾元素交换，再对剩下的N-1个元素进行排序  
![图片](https://user-images.githubusercontent.com/88218815/127794145-c99a8daf-bc1c-4730-8e1e-e2484d90b7b6.png)
* [代码](https://github.com/Neural1996/Sort/blob/main/%E5%A0%86%E6%8E%92%E5%BA%8Fheapsort.c)
## 归并排序
* 核心： 两个有序子列的归并  
>假设有两个已经排好序的子序列，目的将他们有序的放入同一数组中。    
![图片](https://user-images.githubusercontent.com/88218815/127796640-5f6381b2-7e55-4013-97ac-0605ac01a46e.png)
* 每个元素被扫描存储一次，时间复杂度为 N  
* 代码：  
```
  void Merge(ElementType A[], ElenmetType TmpA[], int L, int R, int RigehtEnd )  // L=左起始位置，R=右起始位置，RightEnd=右边终点位置
 {    LeftEnd = R-1;
      Tmp = L;   //存放结果的数组的起始位置
      NumElements=RightEnd-L+1;  //总共排序的元素个数
      while(L<=LeftEnd && R<=RightEnd){
           if(A[L] <= A[R])     TmpA[Tmp++]=A[L++];      //之所以用Tmp是每次都在临时数组的对应段落做操作
           else                 TmpA[Tmp++]=A[R++];
      }
      while(L<=LeftEnd)
           TmpA[Tmp++]=A[L++];
      while(R<=ReftEnd)
           TmpA[Tmp++]=A[R++];
      for(i=0; i<NumElements; i++, RightEnd--)     //从后往前将临时数组中排好序的拷贝到数组A中
           A[RightEnd]=TmpA[RightEnd];
} 
```  
### 用递归来实现归并排序  
![图片](https://user-images.githubusercontent.com/88218815/127874947-554c8b62-acc7-4dcf-86c2-e2a459bd190d.png)  
`分而治之的时间复杂度计算方法：先假设 整体复杂度为N，则递归的前一步时间复杂度为N/2`
* 归并排序是稳定排序 
* 分配统一的函数接口
```
void Merge_sort(ElementType A[], int N)
{   ElementType * TmpA;
    TmpA=malloc(N * sizeof(ElementType)) //申请动态空间，c99直接可以用动态数组
    if(TmpA != NULL) {      //看能否申请到空间，严谨！
        MSort(A, TmpA, 0, N-1);   
        free(TmpA);
    }
    else Error("空间不足")；
 }
 ```
### 非递归归并
![图片](https://user-images.githubusercontent.com/88218815/127942841-9b3e766c-802c-429d-bd00-917e5c2992d1.png)
* 核心代码：![图片](https://user-images.githubusercontent.com/88218815/127942648-9c3efd44-c963-4d0f-a5a2-187a90d5a1e8.png)  
* 整理函数接口：![图片](https://user-images.githubusercontent.com/88218815/127943387-9c87d149-9b1a-4c1f-a4b3-8e0154377547.png)
>归并排序时间复杂度是NlogN，也是稳定的，但是缺点在于无论是否递归，都要有一个临时数组TmpA[],占用内存空间。  
## 快速排序
算法概述：![图片](https://user-images.githubusercontent.com/88218815/127948255-2d6353ad-62b1-47da-948d-07051e71a625.png)
* 选择主元(pivot)：取头、中、尾的中位数
![图片](https://user-images.githubusercontent.com/88218815/127950276-5ffd9543-3d97-4eb2-86fe-cd9f5e55a74e.png)
* 子集划分：  
![图片](https://user-images.githubusercontent.com/88218815/127952503-a22606d3-0119-437f-9809-e02ee67fa955.png)
![图片](https://user-images.githubusercontent.com/88218815/127952925-ff7a34cf-8fcb-42d8-930b-5b512bc7c76c.png)
![图片](https://user-images.githubusercontent.com/88218815/127952721-a748fb68-733d-4b20-8cb6-1cb238148f93.png)  
* 如果有与主元相等的元素，也依旧交换。  
>从图中可以看出，每次划分子集后，主元都放入了正确的位置，而且在之后的递归中位置保持不变，所以这种排序的速度更快。而且如果有与主元相等的元素，也依旧交换。  
>对于快速排序，在数据规模大的时候效率高，在小规模数据排序时可能还不如简单排序快，因此可以在程序中加一个阈值，使得在递归到数据规模充分小时，停止递归，直接调用简单排序。  
* 算法实现：  
![图片](https://user-images.githubusercontent.com/88218815/128649697-98b8dc77-a6bb-4183-801c-8486a9b401d6.png)
## 表排序
>当每个待排元素都是一个庞大的个体（结构体）时，移动一个元素会占用很多时间，表排序不移动原始数据，而是移动指向它们的指针。  
* 算法概述： 又称间接排序，第一一个指针数组作为“表” table。 
* 这里的指针不一定是真正的指针，也可以是数组下标。而且对于指针的则进行最简单的插入排序。
![图片](https://user-images.githubusercontent.com/88218815/128653226-20405ba0-b7ca-4681-a68d-e3c443766744.png)  
## 桶排序
![图片](https://user-images.githubusercontent.com/88218815/128656716-60d505ff-c835-41c9-b047-cf5af6a4cbd0.png)  
count是一个链表数组
## 基数排序
![图片](https://user-images.githubusercontent.com/88218815/128657336-47ea15cc-9c4a-43f8-8ac3-a500bbda383e.png)

## 排序方法的比较  
![图片](https://user-images.githubusercontent.com/88218815/128674151-6a22161a-bb6a-4363-8170-c8a6ae450de7.png)

 



