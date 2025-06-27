import express from "express";
import session from "express-session";

const porta = 3000;
const host = "localhost";
const app = express();

app.use(express.static("./publico"));
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
app.use(express.static("publico"));

function verificar(req, res, next) {
    if (req.session.autenticado) next();
    else res.redirect("/login");
}

app.use(express.static("public"));
app.get("/login", (req, res) => {
    let conteudo = `
        <!DOCTYPE html>
<html lang="en">
<head>
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link rel="stylesheet" href="./publico/css/estilo.css">
</head>
<body>
    <div style="display: flex; justify-content: center; align-items: center; height: 100vh;">
    <form action="/login" method="POST" style="text-align: center">
        <h1>Informe o usuario e a senha para ver o relatorio de vendas</h1>
        <label>Usuário
            <input type="text" name="usuario" required>
        </label>
        <label>Senha
            <input type="password" name="senha" required>
        </label>
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
        res.redirect("/vendas");
    } else {
        let conteudo = `
        <!DOCTYPE html>
        <html lang="pt-br">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Login</title>
            <link rel="stylesheet" href="./publico/css/estilo.css">
        </head>
        <body>
            <div style="display: flex; justify-content: center; align-items: center; height: 100vh;">
            <form action="/login" method="POST" style="text-align: center">
                <h1>Informe o usuario e a senha para ver o relatorio de vendas</h1>
                <label>Usuário
                    <input type="text" name="usuario" required>
                </label>
                <label>Senha
                    <input type="password" name="senha" required>
                </label>
                <button type="submit">Entrar</button>
            </form>
            </div>
        </body>
        </html>
        
        `;
        res.send(conteudo);
        res.end();
    }
});
app.get("/comprar", (req, res) => {
    const id = req.query.id;
    if (!id) return res.status(400).send("ID do filme não informado.");

    fetch(`http://localhost:4000/salas/${id}`)
        .then(apiRes => apiRes.json())
        .then(comprar => {
            const html = `
            <!DOCTYPE html>
            <html lang="pt-br">
            <head>
              <meta charset="UTF-8">
              <title>Comprar Ingresso</title>
              <link rel="stylesheet" href="estilos.css">
            </head>
            <body>
              <h2>BEM-VINDO AO FIPP - CINEMA</h2>
              <div id="filme-info" style="text-align:center;"></div>
              <div style="text-align: center; margin-top: 20px;">
                <input type="text" id="ra" placeholder="Digite seu RA" />
                <input type="text" id="assentoEscolhido" readonly placeholder="Assento escolhido" />
                <select id="sessao"></select>
                <button id="btnConfirmar">Confirmar Compra</button>
              </div>
              <script src="js/comprar.js"></script>
            </body>
            </html>
            
            `;
            res.send(html);
        })
        .catch(erro => {
            res.status(500).send("Erro ao buscar dados do filme.");
        });
});
app.post("/comprar/:id", (req, res) => {
    const comprar = req.body;
    fetch("http://localhost:4000/comprar/id", {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify(comprar)
    })
        .then(res => {
            if (res.ok) return res.json();
        }).then(comprar => {
            res.json(comprar);
        }).catch(erro => {
            res.status(500).json({ erro: "Erro ao cadastrar comprar" });
    })
})
app.get("/vendas", verificar, async (req, res) => {
    try {
        const vendasRes = await fetch("http://localhost:4000/vendas");
        const salasRes = await fetch("http://localhost:4000/salas");
        const vendas = await vendasRes.json();
        const salas = await salasRes.json();
        let html = `
            <!DOCTYPE html>
            <html lang="pt-br">
            <head>
                <meta charset="UTF-8">
                <title>Relatório de Vendas</title>
                <style>
                    table {
                        border-collapse: collapse;
                        width: 80%;
                        margin: auto;
                        margin-top: 40px;
                    }
                    th, td {
                        border: 1px solid #ccc;
                        padding: 10px;
                        text-align: center;
                    }
                    h1 {
                        text-align: center;
                        margin-top: 20px;
                    }
                </style>
            </head>
            <body>
                <h1>Relatório de Vendas</h1>
                <table>
                    <thead>
                        <tr>
                            <th>RA</th>
                            <th>Filme</th>
                            <th>Sessão</th>
                            <th>Assento</th>
                        </tr>
                    </thead>
                    <tbody>
        `;
        for (const venda of vendas) {
            const sala = salas.find(s => parseInt(s.id) === parseInt(venda.filme_id));
            const nomeFilme = sala ? sala.filme : "Filme desconhecido";
            html += `
                <tr>
                    <td>${venda.RA}</td>
                    <td>${nomeFilme}</td>
                    <td>${venda.sessao}</td>
                    <td>${venda.assento}</td>
                </tr>
            `;
        }
        html += `
                    </tbody>
                </table>
            </body>
            </html>
        `;
        res.send(html);
    } catch (erro) {
        console.error("Erro ao gerar relatório:", erro);
        res.status(500).send("Erro ao gerar relatório.");
    }
});
app.listen(porta, host, () => {
    console.log(`Servidor rodando em http://${host}:${porta}`);
});