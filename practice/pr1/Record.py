class Record:
    def __init__(self):
        self.name = None
        self.number = None
    def get_name(self):
        return self._name
    def get_number(self):
        return self._number
    def set_name(self,name):
        self._name = name
    def set_number(self,number):
        self._number = number
    def __str__(self):
        record = "Name: "+ str(self.get_name())+"\t"+"\tNumbeer: "+str(self.get_number())
        return record