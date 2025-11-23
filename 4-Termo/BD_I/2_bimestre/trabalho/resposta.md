3)
a)
select CodProf, NomeProf from professor join titulacao on professor.Titulacao_CodTit = 
titulacao.CodTit where titulacao.nomeTit = lower('MESTRE');

b)
select disciplina.NomeDisc 
from disciplina 
where disciplina.NumDisc in (
	select profTurma.Turma_Disciplina_NumDisc from profTurma where Turma_AnoSem = '25/2'
    and Professor_CodProf in (
		select professor.CodProf from professor where Titulacao_CodTit in (
			select titulacao.CodTit from titulacao where NomeTit = 'doutor'
		)
	)
) 

c)
SELECT predio.NomePred, sala.NumSala
FROM sala
JOIN predio ON sala.Predio_CodPred = predio.CodPred
WHERE sala.Capacidade > 40;

d)
select d.NomeDisc, dd.NomeDisc from disciplina d
left join prereq r on d.NumDisc = r.Disciplina_NumDisc
left join disciplina dd on r.Disciplina_NumDisReq = dd.NumDisc

e)
select p.NomeProf from profTurma pt
join professor p on pt.Professor_CodProf = p.CodProf
join disciplina d on pt.Turma_Disciplina_NumDisc = d.NumDisc
where p.Departamento_CodDepto != d.Departamento_CodDepto

f)
select h.Sala_NumSala, p.NomePred from horario h
left join sala s on h.Sala_NumSala = s.NumSala
left join predio p on s.Predio_CodPred = p.CodPred
where h.HoraInicio != '8:20';

g)
select count(*) from professor where Departamento_CodDepto in (
	select CodDepto from departamento where NomeDepto = 'FIPP'
)

h)
select d.CodDepto, d.NomeDepto from professor p
join departamento d on p.Departamento_CodDepto = d.CodDepto
group by d.CodDepto having count(p.CodProf) > 10;

i)
select * from turma where NmaxAlunos = (select max(NmaxAlunos) from turma);

j)
select p.CodProf, p.NomeProf, count(pt.Turma_Disciplina_NumDisc) as totalDisciplinas 
from professor p 
left join profTurma pt on p.CodProf = pt.Professor_CodProf
group by p.CodProf, p.NomeProf;

k)
select p.NomeProf from profTurma pt
join professor p on pt.Professor_CodProf = p.CodProf
where pt.Turma_AnoSem = '25/2' and p.Titulacao_CodTit in (
	select CodTit from titulacao where titulacao.NomeTit = 'mestre'
)
group by p.NomeProf having count(*) > 3;

6)
update turma set NmaxAlunos  = NmaxAlunos * 1.2 where Disciplina_NumDisc in (
	select NumDisc from disciplina where NomeDisc = 'BD1'
)
