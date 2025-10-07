package unoeste.fipp.sisdentalfx.db.repositories;

import unoeste.fipp.sisdentalfx.db.entities.Procedimento;
import unoeste.fipp.sisdentalfx.db.util.IDAL;
import unoeste.fipp.sisdentalfx.db.util.SingletonDB;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class ProcedimentoDAL implements IDAL<Procedimento> {
    @Override
    public boolean gravar(Procedimento entidade) {
        String sql = """
                INSERT INTO procedimento (pro_desc, pro_tempo, pro_valor)
                VALUES ('#1', #2, #3);
                """;
        sql = sql.replace("#1", entidade.getDescr());
        sql = sql.replace("#2", ""+entidade.getTempo());
        sql = sql.replace("#3", String.format("%.2f", entidade.getValor()));
        return SingletonDB.getConexao().manipular(sql);

    }

    @Override
    public boolean alterar(Procedimento entidade) {
        String sql = """
                UPDATE procedimento SET pro_desc='#1', pro_tempo=#2, pro_valor=#3
                WHERE pro_id=#4
                """;
        sql = sql.replace("#1", entidade.getDescr());
        sql = sql.replace("#2", ""+entidade.getTempo());
        sql = sql.replace("#3", String.format(Locale.US, "%.2f", entidade.getValor()));
        sql = sql.replace("#4", ""+entidade.getId());
        return SingletonDB.getConexao().manipular(sql);
    }

    @Override
    public boolean apagar(Procedimento entidade) {
        return SingletonDB.getConexao().manipular("DELETE FROM procedimento WHERE pro_id=" + entidade.getId());
    }

    @Override
    public Procedimento get(int id) {
        Procedimento procedimento = null;
        String sql = "SELECT * FROM procedimento WHERE pro_id="+id;
        ResultSet resultSet = SingletonDB.getConexao().consultar(sql);
        try {
            if (resultSet.next()) {
                procedimento = new Procedimento(resultSet.getInt("pro_id"),
                        resultSet.getString("pro_desc"),
                        resultSet.getDouble("pro_tempo"),
                        resultSet.getDouble("pro_valor"));
            }
        }catch(Exception e){
            throw new RuntimeException(e);
        }
        return procedimento;
    }

    @Override
    public List<Procedimento> get(String filtro) {
        List <Procedimento> procedimentoList = new ArrayList<>();
        String sql = "SELECT * FROM procedimento";
        if(!filtro.isEmpty())
            sql += " WHERE " + filtro;
        ResultSet resultSet = SingletonDB.getConexao().consultar(sql);
        try {
            while (resultSet.next()) {
                Procedimento procedimento = new Procedimento(resultSet.getInt("pro_id"),
                        resultSet.getString("pro_desc"),
                        resultSet.getDouble("pro_tempo"),
                        resultSet.getDouble("pro_valor"));
                procedimentoList.add(procedimento);
            }
        }catch(Exception e){
            throw new RuntimeException(e);
        }
        return procedimentoList;
    }
}
