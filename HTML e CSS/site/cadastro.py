import cherrypy
from classes.prato import Prato
from classes.tipo import Tipo

class paginaCadastro ():
    topo = open("html/header.html").read()
    rodape = open("html/footer.html").read()
    @cherrypy.expose()
    def index(self):
        return self.mostrarFormulario()

    def mostrarFormulario(self,pID=0,pDia=0,pImagem='',pNome='',pTipo=0,pPreco=0):
        html = self.topo
        html += '''
        <style>
            .prato{
                margin-left:20%;
                display:flex;
                flex-direction: column;
                display:inline-block;
            }
            .tipo{
                margin-right:20%;
                diplay:flex;
                float: right;
            }
            .alinha{
                width:80%;
                margin:0 auto;
            }
            td{
                border:3px solid gray;
                text-align: center;
            }
            tr,th{
                background-color: #e0e0e0;border:3px solid gray;
            }
        </style>
        '''
        html += '''
        <br/>
        <div class="prato">
            <h1>Adicionar Prato</h1>
            <br/>
            <form name="FormCadastro" action = "gravarPrato" method="post">
            <p>
                <input type = "hidden" id="txtId" name="txtId" value="%s"/>
                <br>
                <label><b>Dia do Prato</b></label>
                <br>
                <input type = "text" id="txtDia" name="txtDia" value="%s" size="20" maxlength="1" required="required"/>
                <br>
                <label><b>Imagem</b></label>
                <br>
                <input type = "text" id="txtImagem" name="txtImagem" value="%s" size="20" maxlength="20"/>
                <br>
                <label><b>Nome do Prato</b></label>
                <br>
                <input type = "text" id="txtNome" name="txtNome" value="%s" size="20" maxlength="40" required="required"/>
                <br>
                <label><b>Tipo do Prato</b></label>
                <br>
                <input type = "text" id="txtTipo" name="txtTipo" value="%s" size="20" maxlength="1" required="required""/>
                <br>
                <label><b>Preço</b></label>
                <br>
                <input type = "text" id="txtPreco" name="txtPreco" value="%s" size="20" maxlength="10" required="required"/>
                <br>
            </p>
                <input type="submit" id="btnGravar" name="btnAcao" value="Gravar"/>
                <input type="submit" id="btnCancelar" name="btnAcao" value="Cancelar"/>
            </form>
        </div>
        <br> ''' % (pID,pDia,pImagem,pNome,pTipo,pPreco)
        html += self.montarTabela()
        html = html+self.rodape
        return html

    def montarTabela (self,pIdTipo=0,pTiopoT=''):
        html = '''
        <br> 
        <table class="alinha">
                 <tr>
                     <th>Nome Prato</th>
                     <th>Tipo</th>
                     <th>Dia</th>
                     <th>Preço</th>
                     <th>Exclusão</th>
                 </tr>'''

        objPrato = Prato()
        listaPratos = objPrato.obterPratos()
        for part in listaPratos:
                html+='''<tr>
                        <td>%s</td><td>%s</td><td>%s</td><td>%s</td>
                        <td style= "text-align:center">
                            <a href=excluirPrato?idPrato=%s>Excluir</a>
                        </td>
                        </tr>
                    ''' % (part['NomeDoPrato'],
                            part['TIpoDoPrato'],part['Dia'],part['Preco'],part['ID'])
        html+='</table>'
        html+= '''
        <br>
        <div class="prato">
            <h1>Adicionar Tipo de Prato</h1>
            <br>
            <br>
            <form name="FormCadastro" action = "gravarTipo" method="post">
            <p>
                <input type = "hidden" id="txtIdTipo" name="txtId" value="%s"/>
                <label><b>Tipo de prato</b></label>
                <br>
                <input type = "text" id="txtTipo" name="txtTipo" value="%s" size="20" maxlength="20" required="required"/>
            </p>
            <input type="submit" id="btnEnviar" name="btnAcao" value="Enviar"/>
            </form>
        </div>
        <br>
        '''%(pIdTipo,pTiopoT)
        html+= '''
        <br> 
        <table class="alinha">
                 <tr>
                     <th>Tipo de prato [ID]</th>
                     <th>Tipo de prato</th>
                     <th>Exclusão</th>
                 </tr>
        '''
        objTipo = Tipo()
        listaTipo = objTipo.obterTipo()
        for tipo in listaTipo:
            html+= '''<tr>
                        <td>%s</td><td>%s</td>
                        <td style= "text-align:center">
                            <a href=excluirTipo?idTipo=%s>Excluir</a>
                        </td>
                        </tr>
                    ''' % (tipo['ID_TPP'],
                            tipo['Tipo_TPP'],tipo['ID_TPP'])
        html+='</table>'
        return html
    @cherrypy.expose()
    def excluirPrato(self, idPrato):
        objPrato = Prato()
        objPrato.set_id(int(idPrato))
        if objPrato.excluir()>0: 
            raise cherrypy.HTTPRedirect('/cadastro') 
        else:
            return '''<h2>Houve problemas, não executou a exclusão...</h2>
                      <a href="/cadastro">Voltar</a>
                   '''
    @cherrypy.expose()

    def gravarPrato(self, txtId, txtDia, txtImagem,txtNome,txtTipo,txtPreco,btnAcao):
        if (btnAcao) == "Gravar":
            if len(txtNome)>0 : 
                objPrato = Prato()
                objPrato.set_dia(int(txtDia))
                objPrato.set_imagem(txtImagem) 
                objPrato.set_nome(txtNome)
                objPrato.set_tipo(int(txtTipo))
                objPrato.set_preco(int(txtPreco))
                retorno = 0 
                if int(txtId) == 0: 
                    retorno = objPrato.gravar()
                if retorno>0:
                    return '''
                       <h2>O prato %s foi armazenado com sucesso!!</h2>
                       <a href="/cadastro">Voltar</a>
                    ''' % (txtNome)
                else:
                    return '''
                       <h2>Erro ao gravar o prato!!</h2>
                       <a href="/cadastro">Voltar</a>
                    '''
            else:
                return '''
                   <h2>Os campos devem estar preenchidos!!</h2>
                   <a href="/cadastro">Voltar</a>
                '''
        elif (btnAcao) == "Cancelar":
            raise cherrypy.HTTPRedirect('/cadastro')

    @cherrypy.expose()

    def excluirTipo(self, idTipo):
        objTipo = Tipo()
        objTipo.set_id(int(idTipo))
        if objTipo.excluir()>0: 
            raise cherrypy.HTTPRedirect('/cadastro') 
        else:
            return '''<h2>Houve problemas, não executou a exclusão...</h2>
                      <a href="/cadastro">Voltar</a>
                   '''
    @cherrypy.expose()

    def gravarTipo(self, txtId, txtTipo,btnAcao):
        if (btnAcao) == "Enviar":
            if len(txtTipo)>0 : 
                objTipo = Tipo()
                objTipo.set_tipo(txtTipo)
                retorno = 0 
                if int(txtId) == 0: 
                    retorno = objTipo.gravar()
                if retorno>0:
                    return '''
                       <h2>O Tipo %s foi armazenado com sucesso!!</h2>
                       <a href="/cadastro">Voltar</a>
                    ''' % (txtTipo)
                else:
                    return '''
                       <h2>Erro ao gravar o Tipo!!</h2>
                       <a href="/cadastro">Voltar</a>
                    '''
            else:
                return '''
                   <h2>O campo deve estar preenchido!!</h2>
                   <a href="/cadastro">Voltar</a>
                '''
        elif (btnAcao) == "Cancelar": 
            raise cherrypy.HTTPRedirect('/cadastro')

    @cherrypy.expose()

    def voltar ():
        return 0