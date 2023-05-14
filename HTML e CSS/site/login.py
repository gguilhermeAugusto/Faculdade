import cherrypy

class paginaLogin ():
    topo = open("html/header.html").read()
    rodape = open("html/footer.html").read()
    @cherrypy.expose()
    def index (self):
        html = self.topo
        html = html + '''
        </br>
            <style>
        body{
            font-family: Arial, Helvetica, sans-serif;
        }
        .login{
            background-color: rgba(0, 0,0, 0.8);
            position: absolute;
            top: 65%;
            left: 50%;
            transform: translate(-50%,-50%);
            padding: 80px;
            border-radius: 15px;
            color: white;
        }
        .inputLogin{
            padding: 15px;
            border: none;
            outline: none;
            font-size: 15px;
        }
        .botaoLogin{
            background-color: dodgerblue;
            border: none;
            padding: 15px;
            width: 100%;
            border-radius: 10px;
            color: white;
            font-size: 15px;
            cursor: pointer;
        }
    </style>
</head>
<body>
    <form action="">
        <div class="login">
            <h1>Login</h1>
            <input class="inputLogin" type="text" placeholder="Nome">
            <br><br>
            <input class="inputLogin" type="password" placeholder="Senha">
            <br><br>
            <a class="botaoLogin" href="/cadastro"> Enviar </a>
        </div>
    </form>
</body>
        '''
        html = html 
        return html