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
* 缺点：时间复杂度高，效率差
* 优点：代码简单，按顺序依次比较，每次交换相邻两位，可以适用于链表
