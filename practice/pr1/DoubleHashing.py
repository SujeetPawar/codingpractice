from Record import Record 
class doubleHashTable:
    def __init__(self):
        self.size = int(input("Enter the size of the hash table: "))
        self.table = list(None for i in range(self.size))
        self.elementCount = 0
        self.comparisons = 0
    def isFull(self):
        if self.elementCount == self.size:
            return True
        else:
            return False
    def h1(self,element):
        return (element%self.size)
    def h2(self,element):
        reutrn (5-(element%5))
    def doubleHashing(self,record):
        posFound = False
        limit = self.size
        i = 1
        while i<= limit:
            newPosition = (self.h1(record.get_number())+i *self.h2(record.get_number())) % self.size
            if self.table[newPosition] == None:
                posFound = True
                break
            else:
                i +=1
        return posFound,newPosition
    def insert(self,record):
        if self.isFull():
            print("Hash Table Full")
            return False
        posFound = False
        position = self.h1(record.get_number())
        if self.table[position] == None:
            self.table[position] = record
            print("Phoone number of "+record.get_number()+" is at position "+str(position))
            isStored = True
            self.elementCount += 1
        else:
            print("Collision has occured for "+record.get_name()+"'s phone number at positon "+str(position)+" finding new Position.")
            while not posFound:
                posFound, position = self.doubleHashing(record)
                if posFound:
                    self.table[position] = record
                    print(self.table[position])
                    self.elementCount += 1
                    print(position)
                    print(posFound)
                    print("Phone number of"+record.get_name()+" is at position "+ str(position))
        return posFound
    def search(self,record):
        found = False
        position = self.h1(record.get_number())
        self.comparisons += 1
        if(self.table[position] != None):
            if(self.table[position].get_name()==record.get_name()):
                print("Phone number found at position {}".format(position)+" and total comparisons are "+str(1))
                return position
            else:
                limit = self.size
                i = 1
                newPosition = position
                while i<= limit:
                    position = (self.h1(record.get_number())+i*self.h2(record.get_number())) % self.size
                    self.comparisons += 1
                    if(self.table[position] != None):
                        if self.table[position].get_name() == record.get_name():
                            found = True
                            break
                        else:
                            i +=1
            if found:
                print("Phone number found at position{}".format(position)+" and total comparisons are "+str(i+1))
                return (position)
            else:
                print("Record not Found")
                return found
    def display(self):
        print("\n")
        for i in range(self.size):
            print("Hash value: "+str(i)+"\t\t"+str(self.table[i]))
        print("The number of phonebook records in the Table are: "+str(self.elementCount))       


