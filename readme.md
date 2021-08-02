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

