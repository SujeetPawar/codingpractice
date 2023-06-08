import random
class Node(object):
    def __init__(self,key,level):
        self.key = key
        self.forward = [None] * (level+1)

class Skiplist(object):
    def __init__(self,max_lvl,p):
        self.MaxLvl = max_lvl
        self.p = p
        self.header = self.createNode(self.MaxLvl,-1)
        self.level = 0
    #create new node 
    def createNode(self,lvl,key):
        n = Node(key,lvl)
        return n
    #create random level for node 
    def random_event(self):
        lvl = 0
        while random.random()<self.p and lvl <self.MaxLvl:
            lvl +=1
        return lvl
    #insert given key in skip list 
    def insertElement(self,key):
        update = [None] * (self.MaxLvl+1)
        current = self.header 
        for i in range(self.level, -1,-1):
            while current.forward[i] and current.forward[i].key<key:
                current = current.forward[i]
            update[i] = current
        current = current.forward[0]
        if current == None or current.key != key:
            rlevel = self.random_event()
        if rlevel >self.level:
            for i in range (self.level+1,rlevel + 1):
                update[i] = self.header
            self.level = rlevel
        n = self.createNode(rlevel, key)
        #insert node by rearranging ref
        for i in range (rlevel+1):
            n.forward[i] = update[i].forward[i]
            update[i].forward[i] = n
        print("Successfully Inserted Key {}".format(key))
    #delete node
    def deleteElement(self,search_key):
        update = [None] * (self.MaxLvl+1)
        current = self.header
        for i in range(self.level,-1,-1):
            while current.forward[i] and current.forward[i].key<search_key :
                current = current.forward[i]
            update[i] = current
            current = current.forward[0]
    #if current node is targed node
        if current != None and current.key == search_key:
            for i in range(self.level+1):
                if update[i].forward[i] != current:
                    break
                update[i].forward[i] = current.forward[i]
            #remove level having no elements
            while self.level>0 and self.header.forward[self.level] == None:
                self.level = 1
            print("Successfully delete {}".format(search_key))
    #searching an element 
    def searchElement(self,key):
        current = self.header
        for i in range(self.level , -1,-1):
            while current.forward[i] and current.forward[i].key<key:
                current = current .forward[i]
            current = current.forward[0]
        #if current node have key equal to search key 
        if current and current.key == key:
            print("found key",key)
        else:
            print("Not found",key)
    #display list
    def displayList(self):
        print("\n-----Skip List-----")
        head = self.header
        for lvl in range(self.level+1):
            print("Level {}:".format(lvl),end="")
            node = head.forward[lvl]
            while(node != None):
                print(node.key, end = " ")
                node = node.forward[lvl]
            print("")
def main():
        lst = Skiplist(3,0.5)
        start = 0
        while start != 5:
            opr= input("\nPlease Select opration from the Following\n 1. To Insert Element \n 2. To Delete Element \n 3. To display the Skip List \n 4. To Search the Element\n 5. To Exit \n")  
            if opr=="1":
                element = int(input("Enter The element: "))
                lst.insertElement(element)   
            elif opr =="2":
                element = int(input("Enter The element: "))
                lst.deleteElement(element)
            elif opr=="3":
                lst.displayList()
            elif opr=="4":
                element = int(input("Enter The element: "))
                lst.searchElement(element)
            elif opr=="5":
                start=5
                break
            else:
                print("Select Correct Operation!")
main()
