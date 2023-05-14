import cherrypy
from segunda import paginaSegunda

class paginaCardapio ():
    topo = open("html/header.html").read()
    rodape = open("html/footer.html").read()
    @cherrypy.expose()
    def index (self):
        html = self.topo
        html = html + '''
        <br/>
        <br/>
        <br/>
        <br/>
        <br/>
        <br/>
        <br/>
        <style>
            .cardapio{
                background-color: yellow;
                display: flex;
                justify-content: space-around;
                align-items: center;
                width: 100%;
            }
        </style>
        <div class = "cardapio" class = "menu">
            <a href ="/segunda">Segunda</a>
            <a href = "/terca">Terça</a>
            <a href = "/quarta">Quarta</a>
            <a href = "/quinta">Quinta</a>
            <a href = "/sexta">Sexta</a>
            <a href = "/sabado">Sabado</a>
            <a href = "/domingo">Domingo</a>
        </div>
        <br/>
        <br/>
        <br/>
        <br/>
        <br/>
        <br/>
        '''
        html = html+self.rodape
        return html