from classes.banco import *

class Prato():
    
    def __init__(self): 
        self.__id = 0
        self.__dia= 0
        self.__imagem= ''
        self.__nome = ''
        self.__tipo = 0
        self.__preco = 0

        self.__banco = Banco()

    
    def set_id(self,pId):
       if pId>0:
           self.__id = pId
    def set_dia(self, pDia):
        if pDia>0:
            self.__dia = pDia
    def set_imagem(self, pImagem):
        if pImagem!='':
            self.__imagem = pImagem
    def set_nome(self, pNome):
        if pNome!='':
            self.__nome = pNome
    def set_tipo(self, pTipo):
        if pTipo>0:
            self.__tipo = pTipo
    def set_preco(self, pPreco):
        if pPreco>0:
            self.__preco = pPreco

    def get_id(self):
        return self.__id
    def get_dia(self):
        return self.__dia
    def get_imagem(self):
        return self.__imagem
    def get_nome(self):
        return self.__nome
    def get_tipo(self):
        return self.__tipo
    def get_preco(self):
        return self.__preco


    
    def obterPratos(self):
        sql = '''SELECT ID, Dia,Imagem,NomeDoPrato,TIpoDoPrato,Preco
                 FROM Pratos
                 ORDER by TIpoDoPrato   '''

        return self.__banco.executarSelect(sql)
    
    def excluir(self):
        sql = 'delete from Pratos where ID = #pId'
        sql = sql.replace('#pId', str(self.__id))
        return self.__banco.executarInsertUpdateDelete(sql)
    
    def gravar(self):
        sql = '''insert into Pratos (Dia,Imagem,NomeDoPrato,TIpoDoPrato,Preco)
                 values(#pDia,'#pImagem','#pNome',#pTipo,#pPreco)
           '''
        sql = sql.replace("#pDia", str(self.__dia))
        sql = sql.replace("#pImagem", self.__imagem)
        sql = sql.replace("#pNome", self.__nome)
        sql = sql.replace("#pTipo", str(self.__tipo))
        sql = sql.replace("#pPreco", str(self.__preco))
        return self.__banco.executarInsertUpdateDelete(sql)