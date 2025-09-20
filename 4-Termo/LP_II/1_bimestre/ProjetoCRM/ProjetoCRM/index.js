const fs = require('fs');
const url = require('url');
const http = require('http');

const port = 3000;

//verifica se existe os diretorios
if (!fs.existsSync('leads')) 
    fs.mkdirSync('leads');
if (!fs.existsSync('atividades')) 
    fs.mkdirSync('atividades');

const servidor = http.createServer((req, res) => {
    fs.readFile("index.html", function(err, baseHtml) {
        if (err) {
            res.writeHead(500, { 'Content-Type': 'text/html; charset=utf-8' });
            res.end("<h1>Erro: Não foi possível ler o arquivo index.html</h1>");
            return;
        }

        const urlInfo = url.parse(req.url, true);
        const query = urlInfo.query;
        let contentHtml = ''; // armazena o conteudo dinamico

        // qual html deve ser gerado
        if (query.funcao === 'exibirPipeline') {
            contentHtml = exibirPipeline();
        } else if (query.funcao === 'cadastrarLead') {
            contentHtml = cadastrarLead();
        } else if (query.nomeLead) { 
            contentHtml = criarLead(query);
        } else if (query.funcao === 'consultarLead') {
            contentHtml = consultarLead(query.consultaLead);
        } else if (query.funcao === 'removerLead') {
            contentHtml = removerLead(query.removeLead, query.deseja);
        } else if (query.funcao === 'atualizarLead') {
            contentHtml = atualizarLead(query.atualizaLead);
        } else if (query.mudaLead) { 
            contentHtml = mudarLead(query);
            // se a atualização foi sucedida redireciona para a pagina de consulta
            if (contentHtml.includes('sucesso')) {
                 res.writeHead(302, { 'Location': `/?funcao=consultarLead&consultaLead=${query.mudaLead}` });
                 return res.end();
            }
        } else if (query.funcao === 'registrarAtividade') {
            contentHtml = registrarAtividade(query.registraLead);
        } else if (query.nomeVendedor) { 
            contentHtml = criarAtividade(query);
        } else if (query.funcao === 'relatorioFunil') {
            contentHtml = relatorioFunil(query.relatorioLead);
        }

        
        // no HTML base, injeta o conteudo dinamico no lugar correto
        const finalHtml = baseHtml.toString().replace('</main>', `${contentHtml}</main>`);
        
        res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
        res.end(finalHtml);
    });
});

function exibirPipeline() {
    return `
        <div class="card"><div class="card-body">
            <h2 class="card-title">Etapas do Funil de Vendas</h2>
            <ul class="list-group list-group-flush">
                <li class="list-group-item">1. Contato Inicial</li>
                <li class="list-group-item">2. Proposta Apresentada</li>
                <li class="list-group-item">3. Negociação</li>
                <li class="list-group-item">4. Fechamento</li>
            </ul>
        </div></div>`;
}
function criarLead(query) {
    const { nomeLead, cpfLead, telefoneLead, cepLead, ruaLead, bairroLead } = query;

    if (verificaLead(nomeLead)) 
        return cadastrarLead(`<strong>Erro:</strong> Um lead com o nome "${nomeLead}" já existe.`);
    
    if (!checkTel(telefoneLead)) 
        return cadastrarLead(`<strong>Erro:</strong> O formato do telefone é inválido.`);
    if (!checkCpf(cpfLead))
        return cadastrarLead(`<strong>Erro:</strong> O formato do cpf é inválido.`);
    if (!checkRua(ruaLead))
        return cadastrarLead(`<strong>Erro:</strong> O formato do rua é inválido.`);
    const newId = retornaID();
    const leadData = { 
        ID: newId, 
        nomeLead: nomeLead, 
        cpfLead: cpfLead,
        telefoneLead: telefoneLead, 
        cepLead: cepLead, 
        ruaLead: ruaLead, 
        bairroLead: bairroLead, 
        funilStatus: "Contato Inicial", 
        historico: `Lead criado em ${new Date().toLocaleString('pt-BR')}`
    };
    const fileName = `leads/${nomeLead}${newId}.json`;

    try {
        fs.writeFileSync(fileName, JSON.stringify(leadData, null, 2));
        return `<div class="alert alert-success"><h1>Lead "${nomeLead}" cadastrado com sucesso!</h1></div>`;
    } catch (error) {
        console.error(`ERRO ao salvar lead ${fileName}:`, error);
        return `<div class="alert alert-danger"><h1>Erro interno ao salvar o lead.</h1></div>`;
    }
}
function retornaID(){
    try {
        let id = 0
        const files = fs.readdirSync("./leads");
        for (let i of files){
            let file = fs.readFileSync("./leads/"+i)
            const json = JSON.parse(file)
            if (json.ID > id)
                id = json.ID
        }
        return id+1
    } catch (err) {
    console.error('Error reading directory:', err);
    }
    
}
function cadastrarLead(errorMessage = '') {
    const errorHtml = errorMessage ? `<div class="alert alert-danger">${errorMessage}</div>` : '';
    return errorHtml + `
        <div class="card"><div class="card-body">
            <h2 class="card-title">Cadastrar Novo Lead</h2>
            <form action="/" method="GET">
                <div class="mb-3"><label class="form-label">Nome</label><input type="text" name="nomeLead" class="form-control" required></div>
                <div class="mb-3"><label class="form-label">CPF</label><input type="text" name="cpfLead" class="form-control" required placeholder="xxx.xxx.xxx-xx"></div>
                <div class="mb-3"><label class="form-label">Telefone</label><input type="tel" name="telefoneLead" class="form-control" required placeholder="(xx) xxxxx-xxxx"></div>
                <div class="mb-3"><label class="form-label">CEP</label><input type="text" name="cepLead" class="form-control"></div>
                <div class="mb-3"><label class="form-label">Rua</label><input type="text" name="ruaLead" class="form-control" required placeholder="ex: rua itagua 220"></div>
                <div class="mb-3"><label class="form-label">Bairro</label><input type="text" name="bairroLead" class="form-control"></div>
                <button type="submit" class="btn btn-primary">Cadastrar</button>
            </form>
        </div></div>`;
}

function consultarLead(nomeLead) {
    if (!nomeLead) {
        return `
            <div class="card"><div class="card-body">
                <h2 class="card-title">Consultar Lead</h2>
                <form action="/" method="GET">
                    <input type="hidden" name="funcao" value="consultarLead">
                    <div class="mb-3"><label class="form-label">Nome do Lead</label><input type="text" name="consultaLead" class="form-control" required></div>
                    <button type="submit" class="btn btn-info">Consultar</button>
                </form>
            </div></div>`;
    }

    if (!verificaLead(nomeLead)) {
        return `<div class="alert alert-danger">Lead "${nomeLead}" não encontrado.</div>` + consultarLead();
    }
    
    const leadData = getLead(nomeLead);
    if (!leadData) {
        return `<div class="alert alert-danger">Erro ao ler dados do lead "${nomeLead}". O arquivo pode estar corrompido.</div>` + consultarLead();
    }

    const atividades = getAtividadesDoLead(nomeLead);
    let atividadesHtml = '<div class="card-body"><p class="text-muted">Nenhuma atividade registrada para este lead.</p></div>';

    if (atividades.length > 0) {
        atividadesHtml = `<div class="accordion" id="accAtividades">`;
        atividades.forEach((at, i) => {
            atividadesHtml += `
                <div class="accordion-item">
                    <h2 class="accordion-header"><button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#collapse${i}">Atividade de ${at.nomeVendedor} - Status: ${at.statusFunil}</button></h2>
                    <div id="collapse${i}" class="accordion-collapse collapse" data-bs-parent="#accAtividades"><div class="accordion-body">${at.historico}</div></div>
                </div>`;
        });
        atividadesHtml += `</div>`;
    }

    return `
        <div class="card mb-3">
            <div class="card-header fs-5">Detalhes de: <strong>${nomeLead}</strong></div>
            <ul class="list-group list-group-flush">
                <li class="list-group-item"><strong>ID:</strong> ${leadData.ID}</li>
                <li class="list-group-item"><strong>CPF:</strong> ${leadData.cpfLead}</li>
                <li class="list-group-item"><strong>Telefone:</strong> ${leadData.telefoneLead}</li>
                <li class="list-group-item"><strong>Endereço:</strong> ${leadData.ruaLead || 'N/A'}, ${leadData.bairroLead || 'N/A'} - CEP: ${leadData.cepLead || 'N/A'}</li>
                <li class="list-group-item"><strong>Status:</strong> <span class="badge bg-primary">${leadData.funilStatus}</span></li>
                <li class="list-group-item"><strong>Histórico:</strong> <pre class="mb-0">${leadData.historico}</pre></li>
            </ul>
        </div>
        <div class="card">
            <div class="card-header">Atividades</div>
            ${atividadesHtml}
        </div>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>`;
}

function atualizarLead(nomeLead) {
    if (!nomeLead) {
        return `<div class="card"><div class="card-body">
        <h2 class="card-title">Atualizar Lead</h2>
        <form action="/" method="GET"><input type="hidden" name="funcao" value="atualizarLead">
        <div class="mb-3"><label class="form-label">Nome do Lead</label>
        <input type="text" name="atualizaLead" class="form-control" required></div>
        <button type="submit" class="btn btn-warning">Buscar Lead</button></form></div></div>`;
    }
    if (!verificaLead(nomeLead)) {
        return `<div class="alert alert-danger">Lead "${nomeLead}" não encontrado.</div>` + atualizarLead();
    }
    const leadData = getLead(nomeLead);
    if (!leadData) {
        return `<div class="alert alert-danger">Erro ao ler dados do lead "${nomeLead}".</div>` + atualizarLead();
    }
    return `
        <div class="card"><div class="card-body"><h2 class="card-title">Editando: ${nomeLead}</h2><form action="/" method="GET">
            <div class="mb-3"><label class="form-label">CPF</label><input type="text" name="cpfLead" value="${leadData.cpfLead || ''}" class="form-control"></div>
            <div class="mb-3"><label class="form-label">Telefone</label><input type="text" name="telefoneLead" value="${leadData.telefoneLead || ''}" class="form-control"></div>
            <div class="mb-3"><label class="form-label">CEP</label><input type="text" name="cepLead" value="${leadData.cepLead || ''}" class="form-control"></div>
            <div class="mb-3"><label class="form-label">Rua</label><input type="text" name="ruaLead" value="${leadData.ruaLead || ''}" class="form-control"></div>
            <div class="mb-3"><label class="form-label">Bairro</label><input type="text" name="bairroLead" value="${leadData.bairroLead || ''}" class="form-control"></div>
            <input type="hidden" name="idLead" value="${leadData.ID}">
            <input type="hidden" name="mudaLead" value="${nomeLead}">
            <input type="hidden" name="statusFunil" value="${leadData.funilStatus}">
            <input type="hidden" name="historico" value="${leadData.historico}">
            <button type="submit" class="btn btn-primary">Salvar Alterações</button>
        </form></div></div>`;
}

function registrarAtividade(nomeLead) {
    if (!nomeLead) {
        return `<div class="card"><div class="card-body">
        <h2 class="card-title">Registrar Atividade</h2>
        <form action="/" method="GET"><input type="hidden" name="funcao" value="registrarAtividade">
        <div class="mb-3"><label class="form-label">Nome do Lead</label><input type="text" name="registraLead" class="form-control" required>
        </div><button type="submit" class="btn btn-info">Buscar Lead</button></form></div></div>`;
    }
    if (!verificaLead(nomeLead)) {
        return `<div class="alert alert-danger">Lead "${nomeLead}" não encontrado.</div>` + registrarAtividade();
    }
    return `
        <div class="card"><div class="card-body"><h2 class="card-title">Nova Atividade para: ${nomeLead}</h2><form action="/" method="GET">
            <div class="mb-3"><label class="form-label">Nome do Vendedor</label><input type="text" name="nomeVendedor" class="form-control" required></div>
            <div class="mb-3"><label class="form-label">Descrição (Histórico)</label><textarea name="historico" class="form-control" rows="3" required></textarea></div>
            <input type="hidden" name="registraLead" value="${nomeLead}"><div class="mb-3"><label class="form-label">Novo Status</label><div class="btn-group d-block" role="group">
                <button type="submit" name="status" value="Contato Inicial" class="btn btn-outline-primary">Contato Inicial</button>
                <button type="submit" name="status" value="Proposta" class="btn btn-outline-info">Proposta</button>
                <button type="submit" name="status" value="Negociação" class="btn btn-outline-warning">Negociação</button>
                <button type="submit" name="status" value="Fechamento" class="btn btn-outline-success">Fechamento</button>
            </div></div></form></div></div>`;
}

function relatorioFunil(leadName) {
    if (!leadName) {
        return `<div class="card"><div class="card-body"><h2 class="card-title">Relatório de Funil por Lead</h2><form action="/" method="GET">
        <input type="hidden" name="funcao" value="relatorioFunil">
        <div class="mb-3"><label class="form-label">Nome do Lead</label><input type="text" name="relatorioLead" class="form-control" required>
        </div><button type="submit" class="btn btn-success">Gerar</button></form></div></div>`;
    }
    if (!verificaLead(leadName)) {
        return `<div class="alert alert-danger">Lead "${leadName}" não encontrado.</div>` + relatorioFunil();
    }
    const leadData = getLead(leadName);
    if (!leadData) {
        return `<div class="alert alert-danger">Erro ao ler dados do lead "${leadName}".</div>` + relatorioFunil();
    }
    return `<div class="card"><div class="card-header">Relatório para: <strong>${leadName}</strong></div>
    <div class="card-body"><p>O status atual do lead no funil é:</p>
    <h3 class="text-center"><span class="badge bg-success fs-4">${leadData.funilStatus}</span></h3></div></div>`;
}

function removerLead(nomeLead, confirmacao) {
    if (!nomeLead) {
        return `<div class="card"><div class="card-body"><h2 class="card-title">Remover Lead</h2><form action="/" method="GET">
        <input type="hidden" name="funcao" value="removerLead">
        <div class="mb-3"><label class="form-label">Nome do Lead</label><input type="text" name="removeLead" class="form-control" required>
        </div><button type="submit" class="btn btn-danger">Remover</button></form></div></div>`;
    }
    if (!verificaLead(nomeLead)) {
        return `<div class="alert alert-danger">Lead "${nomeLead}" não encontrado.</div>` + removerLead();
    }
    if (!confirmacao) {
        return `<div class="alert alert-warning"><h4 class="alert-heading">Atenção! Ação Irreversível!</h4>
        <p>Deseja remover o lead "<strong>${nomeLead}</strong>" e suas atividades?</p>
        <hr><a href="/?funcao=removerLead&removeLead=${nomeLead}&deseja=Sim" class="btn btn-danger">Sim, remover</a>
         <a href="/" class="btn btn-secondary">Não, cancelar</a></div>`;
    }
    if (confirmacao === "Sim") {
        try {
            const atividadesRemovidas = removerAtividadesDoLead(nomeLead);
            const leadFile = findLeadFile(nomeLead);
            if(leadFile) fs.unlinkSync(`leads/${leadFile}`);
            return `<div class="alert alert-success">Lead "${nomeLead}" e ${atividadesRemovidas} atividade(s) foram removidos com sucesso.</div>`;
        } catch (error) {
            console.error("Erro ao remover lead:", error);
            return `<div class="alert alert-danger">Erro no servidor ao remover o lead.</div>`;
        }
    } else {
        return `<div class="alert alert-info">A remoção foi cancelada.</div>`;
    }
}

function criarAtividade(query) {
    const { registraLead, nomeVendedor, historico, status } = query;
    const logFileName = `log_${Date.now()}.json`;
    const atividadeData = { nomeVendedor, nomeLead: registraLead, statusFunil: status, historico, data: new Date().toLocaleString() };
    try {
        fs.writeFileSync(`atividades/${logFileName}`, JSON.stringify(atividadeData, null, 2));
        atualizarHistorico(registraLead, historico, status);
        return `<div class="alert alert-success"><h1>Atividade para "${registraLead}" registrada com sucesso!</h1></div>`;
    } catch (error) {
        console.error(`ERRO ao salvar atividade para "${registraLead}":`, error);
        return `<div class="alert alert-danger"><h1>Erro ao salvar a atividade.</h1></div>`;
    }
}

function mudarLead(query) {
    const { mudaLead, idLead, cpfLead, telefoneLead, cepLead, ruaLead, bairroLead, statusFunil, historico } = query;
    if (!checkTel(telefoneLead)) {
        return `<div class="alert alert-danger">Erro: Formato de telefone inválido.</div>` + atualizarLead(mudaLead);
    }
    if (!checkCpf(cpfLead)) {
        return `<div class="alert alert-danger">Erro: Formato de cpf inválido.</div>` + atualizarLead(mudaLead);
    }
    if (!checkRua(ruaLead)) {
        return `<div class="alert alert-danger">Erro: Formato de rua invalido.</div>` + atualizarLead(mudaLead);
    }
    const leadData = { ID: parseInt(idLead), cpfLead, telefoneLead, cepLead, ruaLead, bairroLead, funilStatus: statusFunil, historico: historico +
     `\n[${new Date().toLocaleString()}] Dados cadastrais atualizados.`};

    const fileName = `${mudaLead}${idLead}.json`;
    try {
        fs.writeFileSync(`leads/${fileName}`, JSON.stringify(leadData, null, 2));
        return `<h1>Lead atualizado com sucesso</h1>`; 
    } catch (err) {
        console.error(`ERRO ao salvar o arquivo ${fileName}:`, err);
        return `<div class="alert alert-danger"><h1>Ocorreu um erro interno ao salvar as alterações.</h1></div>`;
    }
}

function verificaLead(nomeLead) {
    if (!nomeLead) return false;
    const files = fs.readdirSync("./leads");
    for (let i of files) {
        if (i.includes(nomeLead)) 
            return true;
    }
    return false;
}

function getLead(nomeLead) {
    const files = fs.readdirSync("./leads");
    for (let i of files) {
        if (i.includes(nomeLead)) {
            var file = fs.readFileSync("./leads/" + i);
            break;
        }
    }
    if (file) {
        try {
            return JSON.parse(file);
        } catch (e) {
            console.error(`Arquivo ${i} não é um JSON válido.`);
            return null;
        }
    } else
        return null;
}

function findLeadFile(nomeLead) {
    const files = fs.readdirSync("./leads");
    return files.find(file => file.includes(nomeLead));
}

function checkTel(tel) {
    if (!tel || typeof tel !== 'string') return false;
    let telSemEspacos = '';
    for (const char of tel) 
        if (char !== ' ') 
            telSemEspacos += char;

    let contParentesesAbre = 0, posParentesesAbre = -1, contParentesesFecha = 0, posParentesesFecha = -1, contHifen = 0, posHifen = -1, contDigitos = 0;
    for (let i = 0; i < telSemEspacos.length; i++) {
        const char = telSemEspacos[i];
        if (char >= '0' && char <= '9') 
            contDigitos++;
        else if (char === '(') { 
            contParentesesAbre++; 
            posParentesesAbre = i; 
        }
        else if (char === ')') { 
            contParentesesFecha++; 
            posParentesesFecha = i; 
        }
        else if (char === '-') { 
            contHifen++; 
            posHifen = i; 
        }
        else return false;
    }
    if (contDigitos !== 11) 
        return false;
    const semParenteses = contParentesesAbre === 0 && contParentesesFecha === 0;
    const comParentesesCorretos = contParentesesAbre === 1 && contParentesesFecha === 1 && posParentesesAbre === 0 && posParentesesFecha === 3;
    if (!semParenteses && !comParentesesCorretos) 
        return false;
    if (contHifen > 1) 
        return false;
    if (semParenteses && contHifen === 1 && posHifen !== 7) 
        return false;
    if (comParentesesCorretos && contHifen === 1 && posHifen !== 9) 
        return false;
    return true; //telefone valido
}
function checkCpf(cpf) {
    if (!cpf || typeof cpf !== 'string') return false;
    let cpfSemEspacos = '';
    for (const char of cpf)
        if (char !== ' ')
            cpfSemEspacos += char;
    let posPonto = new Array();
    let vetNumero = new Array();
    let contDigitos = 0, contPonto = 0, posHifen = 0, contHifen = 0;
    for (let i = 0, j = 0, k = 0; i < cpfSemEspacos.length; i++) {
        const char = cpfSemEspacos[i];
        if (char >= '0' && char <= '9') {
            vetNumero[k++] = char - '0';
            contDigitos++;
        }
        else if (char === '.') {
            contPonto++;
            posPonto[j++] = i;
        }
        else if (char === '-') {
            contHifen++;
            posHifen = i;
        }
    }
    let digito1,digito2,temp = 0;
    for (let i = 0; i < 9; i++)
        temp += (vetNumero[i] * (10 - i));
    temp %= 11;
    if(temp < 2)digito1 = 0;
    else digito1 = 11 - temp;
    temp = 0;
    for(let i = 0; i < 10; i++)
        temp += (vetNumero[i] * (11 - i));
    temp %= 11;
    if(temp < 2)digito2 = 0;
    else digito2 = 11 - temp;
    const isTrue = contPonto == 2 && posPonto[0] == 3 && posPonto[1] == 7 && contHifen == 1 && posHifen == 11;
    if(digito1 == vetNumero[9] && digito2 == vetNumero[10] && isTrue)
        return true;
    else
        return false;
}
function checkRua(rua) {
    if (!rua || typeof rua !== 'string') return false;
    const partes = rua.trim().split(" ");
    const ultima = partes[partes.length - 1];
    return !isNaN(ultima);
}
function getAtividadesDoLead(nomeLead) {
    const atividadesEncontradas = [];
    const pastaAtividades = "./atividades";
    if (!fs.existsSync(pastaAtividades)) 
        return atividadesEncontradas;
    try {
        const files = fs.readdirSync(pastaAtividades);
        for (const fileName of files) {
            try {
                const fileContent = fs.readFileSync(`${pastaAtividades}/${fileName}`, 'utf-8');
                const atividadeData = JSON.parse(fileContent);
                if (atividadeData.nomeLead === nomeLead) 
                    atividadesEncontradas.push(atividadeData);

            } catch (parseError) {
                console.warn(`Aviso: Arquivo de atividade "${fileName}" inválido.`);
            }
        }
    } catch (dirError) {
        console.error("Erro ao ler o diretório de atividades:", dirError);
    }
    return atividadesEncontradas;
}

function removerAtividadesDoLead(nomeLead) {
    let atividadesRemovidas = 0;
    const pastaAtividades = "./atividades";
    if (!fs.existsSync(pastaAtividades)) 
        return 0;
    try {
        const files = fs.readdirSync(pastaAtividades);
        for (const fileName of files) {
            try {
                const fileContent = fs.readFileSync(`${pastaAtividades}/${fileName}`, 'utf-8');
                const atividadeData = JSON.parse(fileContent);
                if (atividadeData.nomeLead === nomeLead) {
                    fs.unlinkSync(`${pastaAtividades}/${fileName}`);
                    atividadesRemovidas++;
                }
            } catch (parseError) {
                console.warn(`Aviso: Ignorando atividade inválida durante remoção: ${fileName}`);
            }
        }
    } catch (dirError) {
        console.error("Erro ao remover atividades:", dirError);
    }
    return atividadesRemovidas;
}

function atualizarHistorico(nomeLead, novoHistorico, novoStatus) {
    if (!nomeLead || !novoHistorico || !novoStatus) {
        console.error("ERRO: Parâmetros faltando em atualizar Historico.");
        return;
    }
    const leadData = getLead(nomeLead);
    if (!leadData) {
        console.error(`ERRO: Tentativa de atualizar lead não existente: "${nomeLead}"`);
        return;
    }
    leadData.funilStatus = novoStatus;
    const dataRegistro = new Date().toLocaleString('pt-BR');
    const entradaHistorico = `\n[${dataRegistro}] ${novoHistorico}`;
    leadData.historico = (leadData.historico || '') + entradaHistorico;
    const fileName = `leads/${nomeLead}${leadData.ID}.json`;
    try {
        const jsonContent = JSON.stringify(leadData, null, 2);
        fs.writeFileSync(fileName, jsonContent);
        console.log(`Histórico de "${nomeLead}" atualizado.`);
    } catch (error) {
        console.error(`ERRO ao salvar lead "${fileName}":`, error);
    }
}

servidor.listen(port, () => {
    console.log(`Servidor rodando em http://localhost:${port}`);
});