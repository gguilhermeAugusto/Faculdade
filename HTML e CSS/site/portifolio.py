import cherrypy

class paginaPortifolio ():
    topo = open("html/header.html").read()
    rodape = open("html/footer.html").read()
    @cherrypy.expose()
    def index (self):
        html = self.topo
        html+='''
        <br/>
        <br/>
        <br/>
        <br/>
        <br/>
        <br/>
        <br/>
        <style>
            .nomes{
                background-color: yellow;
                display: flex;
                justify-content: space-around;
                align-items: center;
                width: 100%;
            }
        </style>
        <div class = "nomes" class = "menu">
            <a href ="/Guilherme/portifolio.html" target="_blank">Guilherme</a>
            <a href = "/Felipe/onepage.html" target="_blank">Felipe</a>
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