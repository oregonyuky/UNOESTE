import express from "express";
import session from "express-session";

const porta = 3000;
const host = "localhost";
const app = express();

app.use(express.static("publico")); 

app.use(session({
    secret: "123455",
    resave: true,
    saveUninitialized: false,
    cookie: {
        maxAge: 100000,
        httpOnly: true
    }
}));

app.use(express.urlencoded({ extended: true }));
app.use(express.json());

function verificar(req, res, next) {
    if (req.session.autenticado) next();
    else res.redirect("/login");
}


app.get("/", (req, res) => {
    res.redirect("/index.html");
});


app.get("/login", (req, res) => {
    const conteudo = `
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Login</title>
    <link rel="stylesheet" href="/css/estilo.css">
</head>
<body>
    <div style="display: flex; justify-content: center; align-items: center; height: 100vh;">
    <form action="/login" method="POST" style="text-align: center">
        <h1>Informe o usuário e a senha</h1>
        <label>Usuário
            <input type="text" name="usuario" required>
        </label><br><br>
        <label>Senha
            <input type="password" name="senha" required>
        </label><br><br>
        <button type="submit">Entrar</button>
    </form>
    </div>
</body>
</html>
    `;
    res.send(conteudo);
});

app.post("/login", (req, res) => {
    const { usuario, senha } = req.body;
    if (usuario === "admin" && senha === "admin") {
        req.session.autenticado = true;
        res.redirect("/livros");
    } else {
        res.send(`<h1>Login inválido</h1><a href='/login'>Voltar</a>`);
    }
});

app.get("/livros", verificar, (req, res) => {
    res.redirect("/privado/html/livros.html");
});

app.use("/privado", verificar, express.static("./privado"));


app.post("/livros", verificar, (req, res) => {
    const livro = req.body;
    fetch("http://localhost:4000/livros", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(livro)
    })
        .then(apiRes => {
            if (apiRes.ok) return apiRes.json();
            else throw new Error("Erro ao cadastrar");
        })
        .then(resposta => {
            res.send(`<h1>Livro cadastrado com sucesso!</h1><a href="/livros">Cadastrar outro</a>`);
        })
        .catch(erro => {
            res.status(500).send("Erro ao cadastrar livro.");
        });
});


app.listen(porta, host, () => {
    console.log(`Servidor rodando em http://${host}:${porta}/`);
});
