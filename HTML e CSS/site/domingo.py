import cherrypy
from classes.prato import Prato

class paginaDomingo ():
    topo = open("html/header.html").read()
    rodape = open("html/footer.html").read()
    @cherrypy.expose()
    def index(self):
        return self.mostrarFormulario()

    def mostrarFormulario(self):
        html = self.topo
        html += self.montarTabela()
        return html

    def montarTabela(self):
        html = '''
                <style>
                    .alinha{
                        width:80%;
                        margin:0 auto;
                    }
                    td{
                        border:3px solid gray;
                        text-align: center;
                    }
                    tr,th{background-color: #e0e0e0;border:3px solid gray;}
                </style>
               <br> 
               <table class="alinha">
                 <tr>
                     <th>Nome Prato</th>
                     <th>Tipo</th>
                     <th>Preço</th>
                 </tr>'''

        objPrato = Prato()
        listaPratos = objPrato.obterPratos()
        for part in listaPratos:
            if(part['Dia'] == 7):
                html+='''<tr>
                        <td>%s</td><td>%s</td><td>%s</td>
                        </tr>
                    ''' % (part['NomeDoPrato'],
                            part['TIpoDoPrato'],part['Preco'])
        html+='</table>'
        return html