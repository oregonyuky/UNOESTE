package unoeste.fipp.sisdentalfx;

import javafx.application.Application;
import javafx.stage.Stage;
import unoeste.fipp.sisdentalfx.db.entities.Procedimento;
import unoeste.fipp.sisdentalfx.db.repositories.ProcedimentoDAL;
import unoeste.fipp.sisdentalfx.db.util.SingletonDB;

import java.util.List;

public class MainTeste{

    public static void main(String[] args) {

        //SingletonDB.conectar();
        //ProcedimentoDAL dal = new ProcedimentoDAL();
        //List<Procedimento> procedimentoList;
        //procedimentoList = dal.get(1);
        //procedimentoList.forEach(p->System.out.println(p.getDescr()));
//        Procedimento procedimento = new Procedimento("clareamento", 40, 120.5);
//        if(!dal.gravar(procedimento))
//            System.out.println("Erro " + SingletonDB.getConexao().getMensagemErro());
//        procedimento.setDescr(procedimento.getDescr().toUpperCase());
//        dal.alterar(procedimento);

        //dal.apagar(new Procedimento(2, "", 0, 0));
        var con = SingletonDB.getConexao();
        if (con.getEstadoConexao()) {
            System.out.println("✅ Conexão bem-sucedida!");
        } else {
            System.out.println("❌ Falha na conexão: " + con.getMensagemErro());
        }
    }
}
