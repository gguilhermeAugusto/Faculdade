from classes.banco import *

class Tipo():
    def __init__(self): 
        
        self.__id = 0
        self.__tipo= ''

        self.__banco = Banco()

    def set_id(self,pId):
       if pId>0:
           self.__id = pId
    def set_tipo(self, pTipo):
        if pTipo!='':
            self.__tipo = pTipo

    def get_id(self):
        return self.__id
    def get_tipo(self):
        return self.__tipo

    def obterTipo(self):
        sql = '''SELECT ID_TPP, Tipo_TPP
                 FROM Tipodoprato
                 ORDER by ID_TPP   '''

        return self.__banco.executarSelect(sql)

    def excluir(self):
        sql = 'delete from Tipodoprato where ID_TPP = #pId'
        sql = sql.replace('#pId', str(self.__id))
        return self.__banco.executarInsertUpdateDelete(sql)

    def gravar(self):
        sql = '''insert into Tipodoprato (Tipo_TPP)
                 values('#pTipo')
           '''
        sql = sql.replace("#pTipo", self.__tipo)
        return self.__banco.executarInsertUpdateDelete(sql)