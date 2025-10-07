package unoeste.fipp.sisdentalfx.db.util;

import java.io.RandomAccessFile;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class SingletonDB {
    private static Conexao conexao=null;
    private SingletonDB(){
        //impede a instancia da classe
    }
    public static boolean conectar(){
        conexao=new Conexao();
        return conexao.conectar("jdbc:postgresql://localhost/","sisdentaldb","postgres","postgres123");
    }
    public static Conexao getConexao() {
        return conexao;
    }

    public static boolean criarBD(String BD){
        try{
            String url = "jdbc:postgresql://localhost/";
            Connection con = DriverManager.getConnection(url,"postgres","postgres123");

            Statement statement = con.createStatement();
            statement.execute("CREATE DATABASE "+BD);
            statement.close();
            con.close();
        }
        catch(Exception e) {
            System.out.println(e.getMessage()); return false;}
        return true;
    }
    public static boolean criarTabelas(String script,String BD){
        try{
            String url = "jdbc:postgresql://localhost/"+BD;
            Connection connection = DriverManager.getConnection(url, "postgres","postgres123");

            Statement statement = connection.createStatement();
            RandomAccessFile arq=new RandomAccessFile(script, "r");
            while(arq.getFilePointer() < arq.length())
                statement.addBatch(arq.readLine());
            statement.executeBatch();

            statement.close();
            connection.close();
            arq.close();
        }
        catch(Exception e){
            System.out.println(e.getMessage()); return false;}
        return true;
    }


}
