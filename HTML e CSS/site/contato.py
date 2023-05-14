import cherrypy

class paginaContato ():
    topo = open("html/header.html").read()
    rodape = open("html/footer.html").read()
    @cherrypy.expose()
    def index (self):
        html = self.topo
        html = html + '''
        </br>
           <main>
        <div class="formula"><div class="inicio">
           
        <div class="mapouter"><div class="gmap_canvas"><iframe class="gmap_iframe" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="https://maps.google.com/maps?width=600&amp;height=400&amp;hl=en&amp;q=unoeste&amp;t=&amp;z=14&amp;ie=UTF8&amp;iwloc=B&amp;output=embed"></iframe><a href="https://mcpenation.com/">Minecraft Website</a></div><style>.mapouter{width:300px;height:400px;}.gmap_canvas {overflow:hidden;background:none!important;width:600px;height:400px;}.gmap_iframe {width:600px!important;height:400px!important;}</style></div>
        </div>

        <div class="lora"> 
          
            <h1>Fale conosco</h1>
            <p>Dúvidas? Sugestões? Preencha os campos abaixo para enviar uma mensagem e responderemos em breve!</p>
            <form name="Contcli" id="Contcli" >
            <label for="tNome"  ></label>
            <input type="text" name="tNome" id="tNome" placeholder=" Nome"
                  size="50" maxlength="30" autofocus="true" required="required"
                  />
            <label for="email"></label><br>
            <input type="email" id="email" size="50" placeholder="E-mail"/>
            <label for="Telefone"></label><br>
            <input type="text" id="telefone" size="50" placeholder="Telefone">
            <label for="Assunto"></label><br>
            <input type="text" id="Assunto" size="50" placeholder="Assunto">
            <br><textarea rows="4" cols="50">
Mensagem
            </textarea>
            <br>
            <button type="submit">Enviar</button>
            </form>
            
        </div>
        
        
        </div>
        

    </main>
        '''
        html = html + self.rodape

        return html