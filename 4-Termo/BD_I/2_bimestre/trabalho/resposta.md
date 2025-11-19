3)
a)
select CodProf, NomeProf from professor join titulacao on professor.Titulacao_CodTit = 
titulacao.CodTit where titulacao.nomeTit = lower('MESTRE');(3, 'departamento de ciencia de dados')

b)
select disciplina.NomeDisc from disciplina 
join turma on disciplina.NumDisc = turma.Disciplina_NumDisc
join professor on disciplina.Departamento_CodDepto = professor.Departamento_CodDepto 
join titulacao on professor.Titulacao_CodTit = titulacao.CodTit
where titulacao.CodTit = 'DOUTOR' and turma.AnoSem = '25/2';

c)

