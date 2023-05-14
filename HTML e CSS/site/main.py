import cherrypy
import os
import time
from contato import paginaContato
from login import paginaLogin
from cardapio import paginaCardapio
from segunda import paginaSegunda
from terca import paginaTerca
from quarta import paginaQuarta
from quinta import paginaQuinta
from sexta import paginaSexta
from sabado import paginaSabado
from domingo import paginaDomingo
from cadastro import paginaCadastro
from portifolio import paginaPortifolio
local_dir = os.path.dirname(__file__)

class principal ():
    topo = open("html/header.html").read()
    rodape = open("html/footer.html").read()
    @cherrypy.expose()
    def index (self):
        html = self.topo
        tempo = time.strftime("%A")
        if(tempo == "Monday"):
            html=html+'''<h1 style=text-align:center;>Segunda</h1>
            <br>
            <br>
            <div style="display: flex; flex-direction: row; align-items: center;justify-content: center;">
                <img src="/img/Rolinho de folha de arroz com lagosta, omelete e abacaxi.webp" alt="img 1" style="width: 300px;">
                <img src="/img/Lagosta flambada com vagem.webp" alt="img 2" style="width: 300px;">
                <img src="/img/Pudim de tapioca.webp" alt="img 3" style="width: 300px;">
            </div>
            '''
        elif(tempo == "Tuesday"):
            html=html+'''<h1 style=text-align:center;>Terça</h1>
            <br>
            <br>
            <div style="display: flex; flex-direction: row; align-items: center;justify-content: center;">
                <img src="/img/Moqueca de lagosta.webp" alt="img 1" style="width: 300px;">
                <img src="/img/Macarrão com queijo e lagosta.webp" alt="img 2" style="width: 300px;">
                <img src="/img/Mungunza-tradicional.png" alt="img 3" style="width: 300px;">
            </div>
            '''
        elif(tempo == "Wednesday"):
            html=html+'''<h1 style=text-align:center;>Quarta</h1>
            <br>
            <br>
            <div style="display: flex; flex-direction: row; align-items: center;justify-content: center;">
                <img src="/img/Lagostim com tartare de banana e maracujá.webp" alt="img 1" style="width: 300px;">
                <img src="/img/Salada-lagosta-500x500.webp" alt="img 2" style="width: 300px;">
                <img src="/img/Bolo-rolo.jpg" alt="img 3" style="width: 300px;">
            </div>
            '''
        elif(tempo == "Thursday"):
            html=html+'''<h1 style=text-align:center;>Quinta</h1>
            <br>
            <br>
            <div style="display: flex; flex-direction: row; align-items: center;justify-content: center;">
                <img src="/img/Risoto de Lagosta.webp" alt="img 1" style="width: 300px;">
                <img src="/img/Logosta na brasa.jpg" alt="img 2" style="width: 300px;">
                <img src="/img/Tapioca doce.webp" alt="img 3" style="width: 300px;">
            </div>
            '''
        elif(tempo == "Friday"):
            html=html+'''<h1 style=text-align:center;>Sexta</h1>
            <br>
            <br>
            <div style="display: flex; flex-direction: row; align-items: center;justify-content: center;">
                <img src="/img/Pastel carne seca.jpg" alt="img 1" style="width: 300px;">
                <img src="/img/arroz cuxa.jpg" alt="img 2" style="width: 300px;">
                <img src="/img/salada de frutas.jpg" alt="img 3" style="width: 300px;">
            </div>
            '''
        elif(tempo == "Saturday"):
            html=html+'''<h1 style=text-align:center;>Sabado</h1>
            <br>
            <br>
            <div style="display: flex; flex-direction: row; align-items: center;justify-content: center;">
                <img src="/img/salada-de-legumes-cozidos-facil-00.webp" alt="img 1" style="width: 300px;">
                <img src="/img/lagosta gratinada.jpg" alt="img 2" style="width: 300px;">
                <img src="/img/sequilho com doce de leite.jpg" alt="img 3" style="width: 300px;">
            </div>
            '''
        elif(tempo == "Sunday"):
            html=html+'''<h1 style=text-align:center;>Domingo</h1>
            <br>
            <br>
            <div style="display: flex; flex-direction: row; align-items: center;justify-content: center;">
                <img src="/img/Carne de sol.jpg" alt="img 1" style="width: 300px;">
                <img src="/img/Baião de dois.jpg" alt="img 2" style="width: 300px;">
                <img src="/img/cocada.jpg" alt="img 3" style="width: 300px;">
            </div>
            '''
        html = html + '''
        </br>
        <main>
        <img src="/img/res1.jpg" alt="" style="width: 900px;">
        <div class="inicio">
        <h1>Orange Lobster</h1>
        <img src="/img/icone-til.png" alt="">
        <h2>Boas vindas ao Orange Lobster</h2>
        <p>É com muita alegria que compartilhamos com você as delícias e belezas de nossa terra. Orgulhosos de nossas raízes genuinamente potiguares, nossa história começou em 1989 e hoje contamos com seis unidades, sendo cinco na cidade de Natal e uma em São Paulo. <br> <br> Agradecemos a oportunidade de poder recebê-lo e desejamos um excelente apetite!</p>
        </div>
        </main>
        '''
        html = html + self.rodape

        return html

server_config={
'server.socket_host': '127.0.0.1',
'server.socket_port': 81
}
cherrypy.config.update(server_config)

local_config = {
    "/":{"tools.staticdir.on":True,
         "tools.staticdir.dir":local_dir},
}

root = principal()
root.inicio = principal()
root.contato = paginaContato()
root.login = paginaLogin()
root.cardapio = paginaCardapio()
root.segunda = paginaSegunda()
root.terca = paginaTerca()
root.quarta = paginaQuarta()
root.quinta = paginaQuinta()
root.sexta = paginaSexta()
root.sabado = paginaSabado()
root.domingo = paginaDomingo()
root.cadastro = paginaCadastro()
root.portifolio = paginaPortifolio()
cherrypy.quickstart(root,config=local_config)