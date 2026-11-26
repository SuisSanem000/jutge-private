from yogi import read

#---------------------------------------------------------------------

class Set:

    #------------------- nested _Node class --------------------------
    class _Node:
        __slots__ = '_element', '_parent', '_left', '_right', '_height'   # streamline memory usage

        def __init__(self, element, parent = None, left = None, right = None):
            self._element = element
            self._parent  = parent
            self._left    = left
            self._right   = right
            self._updateHeight()

        def _updateHeight(self):
            self._height = 1 + max( self._left._height  if self._left  is not None else -1, 
                                    self._right._height if self._right is not None else -1 )
        
    #--------------- Set (AVL) public methods ------------------------

    # Constructor
    def __init__(self):
        self.__root   = None
        self.__cursor = None
        self.__n      = 0

    # Finding elements
    # Find the smallest item in the (non-empty) Set.
    def findMin(self):
        assert not self.empty()
        return self.__findMin(self.__root)._element

    # Find the largest item in the (non-empty) Set.
    def findMax(self):
        assert not self.empty()
        return self.__findMax(self.__root)._element

    # Find an item in the set.
    # Returns true if found, and false otherwise. 
    def contains(self, x):
        return self.__contains(x, self.__root)

    # Define len(set), that is, 'size' in a pythonic way
    def __len__(self):
        return self.__n
    
    # Checks whether the tree is empty. 
    def empty(self):
        return self.__root == None

    # Builds a list with all the elements of the tree
    def elements(self):
        return self.__elements(self.__root)

    # returns the height of the tree
    def height(self):
        return self.__root._height if self.__root is not None else -1
    
    # Insert/remove methods
    def insert(self, x):
        self.__root = self.__insert(x, None, self.__root)

    def remove(self, x):
        self.__root = self.__remove(x, self.__root)

    # Cursor related methods:
    # Methods to iterate the elements of the tree in
    # ascending o descending order.

    def get_cursor(self):
        if self.__cursor is not None:
            return self.__cursor._element
        else:
            return None

    # Iterate in ascending order (S is a Set):
    # S.begin()
    # p = S.get_cursor()
    # while p is not None
    #   <process the element p>
    #   S.succ()
    #   p = S.get_cursor()
        
    def begin(self):
        self.__cursor = self.__findMin(self.__root)

    def succ(self): 
        # self.__cursor is a _Node in the BST tree  
        # if self.__cursor gets the value None, it was the largest element in the tree
        # (there was no successor)
        n = self.__cursor
        if n is not None:
            if n._right is not None: 
                self.__cursor = self.__findMin(n._right)
            else:
                p = n._parent 
                while (p is not None) and (n == p._right): 
                    n = p  
                    p = p._parent
                self.__cursor = p
    
    # Iterate in decreasing order (S is a Set):
    # S.end()
    # p = S.get_cursor()
    # while p is not None
    #   <process the element p>
    #   S.pred()
    #   p = S.get_cursor()
        
    def end(self):
        self.__cursor = self.__findMax(self.__root)
        
    def pred(self):
        # self.__cursor is a _Node in the BST tree  
        # if self.__cursor gets the value None, it was the smallest element in the tree
        # (there was no predecessor)
        n = self.__cursor
        if n is not None:
            if n._left is not None: 
                self.__cursor = self.__findMax(n._left)
            else:
                p = n._parent 
                while (p is not None) and (n == p._left): 
                    n = p  
                    p = p._parent 
                self.__cursor = p 
    
    #------------------- Set (AVL) private methods -------------------------

    # Find the smallest item in the (non-empty) subtree t.
    # Returns (a ptr to) the node with the smallest item.
    def __findMin(self, t):
        if t._left == None:
            return t
        return self.__findMin(t._left)

    # Find the largest item in the (non-empty) subtree t.
    # Returns (a ptr to) the node with the largest item.
    def __findMax(self, t):
        tt = t
        while tt._right != None:
            tt = tt._right
        return tt

    # List with all the elements of the tree, sorted according
    # to the insertion criterion (inorder traversal)
    def __elements(self,t):
        if t is None:
            return []
        else:
            l = self.__elements(t._left)
            r = self.__elements(t._right)
            return l + [t._element] + r

    # Find an item in the subtree represented by t.
    # Returns true if found, and false otherwise. 
    def __contains(self, x, t):
        if t == None:
            return False
        if x < t._element:
            return self.__contains(x, t._left)
        if x > t._element:
            return self.__contains(x, t._right)
        return True

    # Insert/remove methods
    def __insert(self, x, p, t):
        if t == None:
            self.__n += 1
            return self._Node(x, p)
        elif x < t._element:
            t._left = self.__insert(x, t, t._left)
            dif = t._left._height - (t._right._height if t._right is not None else -1) 
            if dif == 2:
                if x < t._left._element:
                    self.__LL(t)
                else:
                    self.__LR(t)
                return t._parent
            else:
                t._updateHeight()
                return t
        elif x > t._element:
            t._right = self.__insert(x, t, t._right)
            dif = t._right._height - (t._left._height if t._left is not None else -1) 
            if dif == 2:
                if x > t._right._element:
                    self.__RR(t)
                else:
                    self.__RL(t)
                return t._parent
            else:
                t._updateHeight()
                return t
        else:
            return t

    def __remove(self, x, t):
        if t != None:
            if x < t._element:
                t._left = self.__remove(x, t._left)
                return self.__rebalanceLeft(t)
            elif x > t._element:
                t._right = self.__remove(x, t._right)
                return self.__rebalanceRight(t)
            else:  # x == t._element
                if t._left == None:
                    self.__n -= 1
                    if t._right != None:
                        t._right._parent = t._parent
                    return t._right
                elif t._right == None:
                    self.__n -= 1
                    t._left._parent = t._parent
                    return t._left
                else:  # t._left is not None and t._right is not None
                    self.__n -= 1
                    q = self.__extractMinimum(t._right)
                    q._left   = t._left
                    q._right  = t._right
                    q._parent = t._parent
                    q._left._parent  = q
                    if q._right is not None:
                        q._right._parent = q
                    if t._parent is not None:
                        if t._parent._left == t:
                            t._parent._left  = q
                        else:
                            t._parent._right = q
                    return self.__rebalanceRight(q)

    # Methods related to balance keeping
    # (after http://www.cs.upc.edu/eda/data/uploads/eda-codis.pdf)

    # Left-Left rotation assuming a non empty _Node p with a non empty left child
    def __LL(self, p):
        parent = p._parent
        isLeft = parent._left == p if parent is not None else "does not matter"
        # update _left and _right references
        q = p
        p = p._left
        q._left = p._right
        p._right = q
        # update heights 
        q._updateHeight()
        p._updateHeight()
        # update parents
        p._parent = parent
        q._parent = p
        if q._left is not None:
            q._left._parent = q
        # update parent reference
        if parent is not None:
            if isLeft:
                parent._left  = p            
            else:
                parent._right = p
        else:
            self.__root = p

    # Right-Right rotation assuming a non empty _Node p with a non empty right child
    def __RR(self, p):
        parent = p._parent
        isLeft = parent._left == p if parent is not None else "does not matter"
        # update _left and _right references
        q = p
        p = p._right
        q._right = p._left
        p._left = q
        # update heights 
        q._updateHeight()
        p._updateHeight()
        # update parents
        p._parent = parent
        q._parent = p
        if q._right is not None:
            q._right._parent = q
        # update parent reference
        if parent is not None:
            if isLeft:
                parent._left  = p            
            else:
                parent._right = p
        else:
            self.__root = p

    # Left-Right double rotation assuming a non empty _Node p with a non empty left child
    # that has a non empty right child
    def __LR(self, p):
        self.__RR(p._left)
        self.__LL(p)

    # Right-Left double rotation assuming a non empty _Node p with a non empty right child
    # that has a non empty left child
    def __RL(self, p):
        self.__LL(p._right)
        self.__RR(p)

    #
    # Auxiliary functions to rebalance the tree
    #

    def __rebalanceLeft(self, p):
        hr  = p._right._height if p._right is not None else -1
        hl  = p._left._height  if p._left  is not None else -1
        hrl = p._right._left._height  if p._right is not None and p._right._left  is not None else -1
        hrr = p._right._right._height if p._right is not None and p._right._right is not None else -1
        if (hr - hl) == 2:
            if (hrl - hrr) == 1:
                self.__RL(p)
            else:
                self.__RR(p)
            return p._parent    
        else:
            p._updateHeight()
            return p

    def __rebalanceRight(self, p):
        hl  = p._left._height  if p._left  is not None else -1
        hr  = p._right._height if p._right is not None else -1
        hlr = p._left._right._height if p._left is not None and p._left._right is not None else -1
        hll = p._left._left._height  if p._left is not None and p._left._left  is not None else -1
        if (hl - hr) == 2:
            if (hlr - hll) == 1:
                self.__LR(p)
            else:
                self.__LL(p)
            return p._parent    
        else:
            p._updateHeight()
            return p

    def __extractMinimum(self, p):
        if p._left is not None:
            q = self.__extractMinimum(p._left)
            self.__rebalanceLeft(p)
            return q
        else:
            if p._parent._left == p:
                p._parent._left  = p._right
            else:
                p._parent._right = p._right
            if p._right is not None:
                p._right._parent = p._parent
            return p
        
#---------------------------------------------------------------------

def main():
    n = read(int)
    while n is not None:
        m = read(int)
        grau = [0] * n
        G = [None] * n
        for i in range(n):
            G[i] = []
        for i in range(m):
            x = read(int)
            y = read(int)
            G[x].append(y)
            grau[y] += 1

        S = Set()
        for i in range(n):
            if grau[i] == 0:
                S.insert(i)
        for j in range(n):
            assert not S.empty()
            x = S.findMin()
            S.remove(x)
            print(" " if j > 0 else "", x, sep='', end='')
            for i in range(len(G[x])):
                y = G[x][i]
                grau[y] -= 1
                if grau[y] == 0:
                    S.insert(y)
        print()
        n = read(int)

main()

