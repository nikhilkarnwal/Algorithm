import numpy as np

class Node:
    def __init__(self,value):
        self.data = value
        self.left = None
        self.right = None

class STree:
    """
    Class for creating segment tree
    """
    __rootNode = Node(None);
    __start=-1;
    __end=-1;
    def __init__(self,size,compute):
       """
       Initialize it, size: no. of elements, compute: function to compute node
       """
       self.__start = 1;
       self.__end = size;
       self.__compute = compute;

    def __ComputeNode(self,nodeLeft,nodeRight):
        """
        Compute Node
        """
        if nodeLeft == None or nodeRight == None:
            if nodeLeft == None:
                return nodeRight;
            else:
                return nodeLeft;
        else:
            return self.__compute(nodeLeft,nodeRight);

    def __InitializeTree(self,start,end,value):
        """
        Initialize Tree: Intrnal function
        """
        if start == end:
            return Node(value)
        else:
            node = Node(value);
            node.left= self.__InitializeTree(start,int((start+end)/2),value);
            node.right = self.__InitializeTree(int((start+end)/2)+1,end,value);
            node.data = self.__ComputeNode(node.left.data,node.right.data);
            return node;

    def Initialize(self,value):
        """
        Intialize Tree
        """
        self.__rootNode = self.__InitializeTree(self.__start,self.__end,value);

    def __QueryTree(self,node,start,end,rangeStart,rangeEnd):
        """
        Query Tree : Internal function
        """
        if rangeStart > end or rangeEnd < start:
            return None;
        elif rangeStart <= start and rangeEnd >= end:
            return node.data;
        else:
            leftValue = self.__QueryTree(node.left,start,int((start+end)/2),rangeStart, min(int((start+end)/2),rangeEnd));
            rightValue = self.__QueryTree(node.right, int((start+end)/2)+1,end, max(int((start+end)/2)+1,rangeStart),rangeEnd);
            return self.__ComputeNode(leftValue,rightValue);

    def Query(self,rangeStart,rangeEnd):
        """
        Query Tree
        """
        return self.__QueryTree(self.__rootNode,self.__start,self.__end,rangeStart,rangeEnd);

    def __UpdateTree(self,node,start,end,index,value):
        """
        Update Tree : Internal function
        """
        if start == end and start == index:
            node.data = value;
        else:
            midIndex = int((start+end)/2);
            if index <=midIndex:
                self.__UpdateTree(node.left,start,midIndex,index,value);
            else:
                self.__UpdateTree(node.right,midIndex+1,end,index,value);

            node.data = self.__ComputeNode(node.left.data,node.right.data);

    def Update(self,index,value):
        """
        Update Tree
        """
        self.__UpdateTree(self.__rootNode,self.__start,self.__end,index,value);

def funct(a,b):
    return a+b;

stree = STree(10,funct);
stree.Initialize(1);
print(stree.Query(1,3));
stree.Update(5,4);
print(stree.Query(4,5));

