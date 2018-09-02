cmake_minimum_required(VERSION 3.6)
project(algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        用两个栈实现一个队列/twoStackAQueue.cpp
        BinaryTree.cpp
        binaryTreeMaxLen.cpp
        biSearch.cpp
        Box.cpp
        Box.h
        climbStairs.cpp
        extractSummary.cpp
        findFirstCommonNode.cpp
        getKSamllNumberss.cpp
        堆排序/heapSort.cpp
        heapSort2.cpp
        LCS.cpp
        LIS.cpp
        LRUCache.cpp
        main.cpp
        maximumSubarray.cpp
        mergeSort.cpp
        mergeTwoLists.cpp
        myStack.cpp
        nQueen.cpp
        快速排序/quickSort.cpp
        removeDuplicates.cpp
        rotateString.cpp
        search2DMatrix.cpp
        searchRotatedSortedArray.cpp
        sqrt.cpp
        stackQuene.cpp
        test.cpp
        trailingZeroes.cpp
        Utils.h
        yinYong_dizhi.cpp
        最小栈/minStack.cpp
        最大乘积子序列/maxProduct.cpp
        两个队列实现一个栈/twoQueueAStack.cpp
        二叉树的镜像/bTreeRotate.cpp
        最大和子串/masSum.cpp
        最长公共子序列/LCS.cpp
        二叉树中节点的最远距离/binaryTreeMaxDistance.cpp
        二叉树双向链表/BiTree2LinkList.cpp
        二叉树双向链表/BiTree2LinkList_v2.cpp
        AB/AB.cpp 016-反转链表/reverselist1.cpp 二叉树遍历/BiTreePreTraversal.cpp 010-二进制中1的数个/numberOf1_2.cpp 堆排序/heapSort_20180812.cpp 快速排序/quickSort_20180812.cpp)

add_executable(algorithm ${SOURCE_FILES})